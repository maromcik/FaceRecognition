#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <fstream>
#include <pwd.h>
#include <thread>
#include "FaceRec.hpp"


int main() {

    // gets home directory
    struct passwd *pw = getpwuid(getuid());
    const char *homedir = pw->pw_dir;
    std::string path(homedir);
    path.append("/configuration.conf");
    std::cout << path << std::endl;

    // reads a configuration file
    std::ifstream ConfReader(path);
    std::vector<std::string> config = {};
    std::string line;
    while (std::getline(ConfReader, line)) {
        config.push_back(line);
    }
    ConfReader.close();

//    auto separated = split(config[1], ";");
//    FaceRec faceRec1 = FaceRec(config[0], 5555, separated[0], separated[1]);
//
//    std::thread th1(&FaceRec::run, faceRec1, separated[0]);
//    th1.join();

    std::vector<std::thread> pool;

    // config[0] - server IP
    // separated[0] - camera ID
    // separated[1] - camera stream

    for (int i = 1; i < config.size() - 1; i++) {
        std::cout << "Thread: " << i << std::endl;
        // A Dlib function, separates csv values in the configuration file
        auto separated = split(config[i], ";");
        pool.emplace_back(&FaceRec::run, FaceRec(config[0], 5555, separated[0], separated[1]), separated[0]);
    }

    for (auto & thread : pool)
        thread.join();

    return 0;
}

