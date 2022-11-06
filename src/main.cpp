//  Created by Linzaer on 2019/11/15.
//  Copyright © 2019 Linzaer. All rights reserved.


#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <fstream>
#include <pwd.h>
#include <thread>
#include "FaceRec.hpp"


int main(int argc, char **argv) {


//    auto cap = cv::VideoCapture("rtmp://192.168.5.55:1935/bcs/channel0_main.bcs?channel=0&stream=0&user=admin&password=123456");

    struct passwd *pw = getpwuid(getuid());
    const char *homedir = pw->pw_dir;
    std::string path(homedir);
    path.append("/configuration.conf");
    std::cout << path << std::endl;
    std::ifstream ConfReader(path);
    std::vector<std::string> config = {};
    std::string line;
    while (std::getline(ConfReader, line)) {
        config.push_back(line);
    }
    ConfReader.close();

    auto separated1 = split(config[1], ";");
    FaceRec faceRec1 = FaceRec(config[0], 5555, separated1[0], separated1[1]);
    std::thread th1(&FaceRec::run, faceRec1, separated1[0]);
    std::cout << "1st thread" << std::endl;

    if (config.size() > 3) {
        auto separated2 = split(config[2], ";");
        FaceRec faceRec2 = FaceRec(config[0], 5555, separated2[0], separated2[1]);
        std::thread th2(&FaceRec::run, faceRec2, separated2[0]);
        std::cout << "2nd thread" << std::endl;
        th2.join();
    }
    th1.join();

//    std::vector<std::thread> pool;
//    auto func = [](FaceRec faceRec){
//        faceRec.run("1");
//    };
//
//    for (int i = 1; i < config.size() - 1; i++) {
//        auto separated = split(config[i], ";");
//        std::cout << separated[0] << " " << separated[1] << std::endl;
//        pool.push_back(std::thread(func, FaceRec(config[0], 5555, separated[0], separated[1])));
//    }
//
//    for (auto & thread : pool)
//        thread.join();

    return 0;
}

