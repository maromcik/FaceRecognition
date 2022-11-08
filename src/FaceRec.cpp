/**
 * @brief FaceRecognition class that completes the application
 *
 * @author Roman Alexander Mariancik
 * Contact: 492965@muni.cz
 */

#include "FaceRec.hpp"

/**
 *
 * @param server_ip - the ip of the server
 * @param port - the open port on the server
 * @param camera - camera id
 * @param stream - camera stream
 */
FaceRec::FaceRec(const std::string &server_ip, int port, const std::string &camera, const std::string &stream) {
    this->server_ip = server_ip.c_str();
    this->port = port;
    this->camera = camera.c_str();
    this->stream = stream;
}

/**
 * The run function runs until the application ends
 * It reads the stream, calls the @process() function to analyse each frame and optionally desplays the results
 *
 * @param winname the name of the window to be opened, must be different in each thread
 */
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

/**
 * Processes each frame - detects faces and performs alignment
 * Aligned faces are sent over the network with the @send_data() function
 * Various parts of this function are enabled or disabled with macros
 * If no output to screen is necessary, there is no need to waste processing time on drawing rectangles to frames
 * If debug is disabled, no output is printed to the console
 *
 * @param frame
 * @return frame
 */
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

/**
 * Creates a socket, sends an image, and closes the socket
 * Constant reopening of sockets turns out to be simpler to implement and more reliable than keeping the socket
 * open. Furthermore, overhead of opening and closing sockets is relatively negligible in comparison with
 * performing face detection.
 *
 * @param img - the input image to be sent
 * @return 0 if successful, -1 if not
 */
int FaceRec::send_data(const cv::Mat &img) {
    int sock = 0, client_fd;
    struct sockaddr_in serv_addr;
    auto jpg_img = encode_img(img);

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
    send(sock, jpg_img.data(), jpg_img.size(), 0);
    printf("Image sent successfully \n");
    // closing the connected socket
    close(client_fd);
    close(sock);
    return 0;
}

/**
 * Encodes the image with opencv
 *
 * @param frame
 * @return jpg data
 */
std::vector<uchar> FaceRec::encode_img(const cv::Mat &frame) {
    std::vector<uchar> buf;
    if (!cv::imencode(".jpg", frame, buf)) {
        std::cerr << "Failed to encode frame." << std::endl;
    }
    return buf;
}

/**
 * converts dlib image to opencv image
 *
 * @param img
 * @return
 */
cv::Mat FaceRec::convert_color(matrix<rgb_pixel> img) {
    cv::Mat out_img;
    cv::cvtColor(dlib::toMat(img), out_img, cv::COLOR_BGR2RGB);
    return out_img;
}


/**
 * Compares face descriptors, used on face recognition testing.
 * Calculates the Euclidean distance. In Python on the server it is implemented with the np.linalg.norm() function.
 *
 */
#ifdef RECOGNITION
double FaceRec::compare(matrix<float, 0, 1> known, matrix<float, 0, 1> unknown) {
    double temp = 0;
    for (int i = 0; i < 128; i++) {
        temp = temp + pow(known(i) - unknown(i), 2.0);
    }
    return sqrt(temp);
}
#endif
