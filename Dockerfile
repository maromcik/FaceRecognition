# syntax=docker/dockerfile:1
FROM ubuntu
RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y apt-utils build-essential cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev libopenblas-dev liblapack-dev
RUN cd /root && git clone https://github.com/maromcik/FaceRecognition.git
WORKDIR /root/FaceRecognition
RUN cd MNN && ./schema/generate.sh && mkdir build && cd build && cmake .. && make -j $(nproc) && cp libMNN.so ../../mnn/lib
RUN cd opencv/ && rm -rfd build && mkdir -p build && cd build && cmake -DBUILD_LIST=core,highgui,improc,videoio ../opencv-4.x && cmake --build . -j $(nproc)
RUN cd dlib-19.24/dlib && rm -rfd build && mkdir build && cd build && cmake -DCMAKE_BUILD_TYPE=Release .. && cmake --build . --config Release -- -j $(nproc) && make install
RUN ldconfig
RUN rm -rdf build && mkdir build && cd build && cmake -DCMAKE_PREFIX_PATH="opencv/build" -DDEBUG=1 -DCMAKE_BUILD_TYPE=Release .. && cmake --build . --config Release -- -j $(nproc)
CMD cd build && ./Recognition
RUN echo "All operations completed successfully"
