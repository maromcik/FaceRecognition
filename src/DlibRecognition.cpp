#include "DlibRecognition.hpp"

using namespace dlib;
using namespace std;

DlibRecognition::DlibRecognition(const std::string& model_folder) {
    deserialize(model_folder + "shape_predictor_68_face_landmarks.dat") >> sp;
    std::cout << "Shape predictor successfully loaded" << std::endl;
#ifdef RECOGNITION
    deserialize(model_folder + "dlib_face_recognition_resnet_model_v1.dat") >> net;
#endif

}


matrix<rgb_pixel> DlibRecognition::get_shape(const cv::Mat& frame, dlib::rectangle face) {
    cv_image<bgr_pixel> cimg(frame);
    auto shape = sp(cimg, face);
    matrix<rgb_pixel> face_chip;
    extract_image_chip(cimg, get_face_chip_details(shape, 150, 0.25), face_chip);
    return face_chip;
}

#ifdef RECOGNITION
matrix<float,0,1> DlibRecognition::get_descriptor(const dlib::matrix<rgb_pixel>& face_chip) {
    matrix<float,0,1> descriptors = net(std::move(face_chip));
    return descriptors;
}

std::vector<matrix<float, 0, 1>> DlibRecognition::process(cv::Mat image) {
    std::vector<matrix<float, 0, 1>> out = {};
    for (auto face : get_detection(image)) {
        auto face_chip = get_shape(image, face);
        out.push_back(get_descriptor(face_chip));
    }
    return out;
}

std::vector<dlib::rectangle> DlibRecognition::get_detection(const cv::Mat& frame) {
//    cv::resize(frame, frame, cv::Size(), 0.25, 0.25);
    cv_image<bgr_pixel> cimg(frame);
    std::vector<rectangle> detected_faces = detector(cimg);
    return detected_faces;
}
#endif


