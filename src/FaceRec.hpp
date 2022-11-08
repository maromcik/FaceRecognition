#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>
#include <arpa/inet.h>
#include <cstdio>
#include <sys/socket.h>
#include <unistd.h>
#include <chrono>
#include <string>


#include "UltraFace.hpp"
#include "DlibRecognition.hpp"

class FaceRec {
public:
    FaceRec(const std::string& server_ip, int port, const std::string& camera, const std::string& stream);
    void run(const std::string& winname);
    cv::Mat process(cv::Mat frame);
    int send_data(const cv::Mat& img);
    std::vector<uchar> encode_img(const cv::Mat& frame);
    #ifdef RECOGNITION
        double compare(matrix<float, 0, 1> known, matrix<float, 0, 1> unknown);
    #endif

private:
    const char* server_ip;
    int port;
    const char* camera;
    std::string stream;

    std::string mnn_path = "../model/version-RFB/RFB-320.mnn";
    UltraFace ultraface = UltraFace(mnn_path, 320, 240, 4, 0.65);
    DlibRecognition dlibRecognition = DlibRecognition("../model/");
    cv::Mat convert_color(matrix<rgb_pixel> img);
};