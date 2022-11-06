#include "FaceRec.hpp"

FaceRec::FaceRec(const std::string &server_ip, int port, const std::string &camera, const std::string &stream) {
    this->server_ip = server_ip.c_str();
    this->port = port;
    this->camera = camera.c_str();
    this->stream = stream;
}

void FaceRec::run(const std::string &winname) {
    std::cout << "Face Recognition is starting" << std::endl;
    cv::VideoCapture cap;
    if (stream.length() == 1) {
        std::cout << "stream: " << std::stoi(stream) << std::endl;
        cap = cv::VideoCapture(std::stoi(stream));
    } else {
        std::cout << "stream: " << stream << std::endl;
        cap = cv::VideoCapture(stream);
    }
    if (!cap.isOpened()) {
        std::cerr << "Camera could not be connected" << std::endl;
        return;
    }
    std::cout << "Camera: " << camera << " connected" << std::endl;
    cv::Mat frame;
    std::cout << "Face recognition is running" << std::endl;
    while (true) {
        cap.read(frame);
        frame = process(frame);
#ifdef RUNWITHGUI
        cv::imshow(winname, frame);
        char c = (char) cv::waitKey(1);
        if (c == 27 || c == 'q' || c == 'Q') {
            break;
        }
#endif
    }
    cap.release();
#ifdef RUNWITHGUI
    cv::destroyAllWindows();
#endif
}

cv::Mat FaceRec::process(cv::Mat frame) {
    std::vector<FaceInfo> face_info;
    std::vector<rectangle> faces;

    cv::resize(frame, frame, cv::Size(), 0.5, 0.5);

    auto start = std::chrono::steady_clock::now();
    ultraface.detect(frame, face_info);
    for (auto face: face_info) {
        dlib::rectangle rect = dlib::rectangle();
        rect.left() = face.x1;
        rect.right() = face.x2;
        rect.top() = face.y1;
        rect.bottom() = face.y2;
#ifdef DEBUG
        auto s2 = std::chrono::steady_clock::now();
#endif
        auto sp = dlibRecognition.get_shape(frame, rect);
#ifdef DEBUG
        auto e2 = std::chrono::steady_clock::now();
        std::cout << "Shape predictor time: "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(e2 - s2).count()
                  << " ms" << std::endl;
#endif
#ifdef RECOGNITION
        auto s1 = std::chrono::steady_clock::now();
        auto dsc = dlibRecognition.get_descriptor(sp);
        auto e1 = std::chrono::steady_clock::now();
#endif
#if defined (DEBUG) && defined (RECOGNITION)
        std::cout << "Face descriptor time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(e1 - s1).count()
              << " ms" << std::endl;
#endif
        send_data(convert_color(sp));
#ifdef RUNWITHGUI
        cv::Point pt1(face.x1, face.y1);
        cv::Point pt2(face.x2, face.y2);
        cv::rectangle(frame, pt1, pt2, cv::Scalar(0, 255, 0), 2);
#endif
    }
    auto end = std::chrono::steady_clock::now();
#ifdef DEBUG
    std::cout << "Process time per frame: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms" << std::endl;
#endif
    return frame;
}


int FaceRec::send_data(const cv::Mat &img) {
    int sock = 0, client_fd;
    struct sockaddr_in serv_addr;
    auto compressed_img = compress_img(img);

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, server_ip, &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if ((client_fd = connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr))) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    std::cout << camera << std::endl;
    send(sock, camera, 7, 0);
    send(sock, compressed_img.data(), compressed_img.size(), 0);
    printf("Image sent successfully \n");
    // closing the connected socket
    close(client_fd);
    close(sock);
    return 0;
}


std::vector<uchar> FaceRec::compress_img(const cv::Mat &frame) {
    std::vector<uchar> buf;
    if (!cv::imencode(".jpg", frame, buf)) {
        std::cerr << "Failed to compress frame." << std::endl;
    }
    return buf;
}

cv::Mat FaceRec::convert_color(matrix<rgb_pixel> img) {
    cv::Mat out_img;
    cv::cvtColor(dlib::toMat(img), out_img, cv::COLOR_BGR2RGB);
    return out_img;
}


#ifdef RECOGNITION
double FaceRec::compare(matrix<float, 0, 1> known, matrix<float, 0, 1> unknown) {
    double temp = 0;
    for (int i = 0; i < 128; i++) {
        temp = temp + pow(known(i) - unknown(i), 2.0);
    }
    return sqrt(temp);
}
#endif
