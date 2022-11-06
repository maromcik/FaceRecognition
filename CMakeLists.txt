cmake_minimum_required(VERSION 3.10)
project(FaceRecognition)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)
find_package(dlib REQUIRED)

include_directories(
        mnn/include
        src
)

link_directories(mnn/lib)

if (RECOGNITION)
    add_definitions(-DRECOGNITION=1)
endif (RECOGNITION)

if (RUNWITHGUI)
    add_definitions(-DRUNWITHGUI=1)
endif (RUNWITHGUI)

if (DEBUG)
    add_definitions(-DDEBUG=1)
endif (DEBUG)


add_executable(Recognition src/main.cpp src/UltraFace.cpp src/DlibRecognition.cpp src/FaceRec.cpp src/FaceRec.hpp)
target_link_libraries(Recognition MNN ${OpenCV_LIBS})
target_link_libraries(Recognition dlib::dlib)
