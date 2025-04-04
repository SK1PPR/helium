//
// Created by khushalagrawal on 4/4/25.
//
#include <video.h>

void displayFrameAsAscii(cv::Mat& frame) {
    const Dimensions printDims = getPrintDimensions(Dimensions(frame.cols, frame.rows));
    cv::resize(frame, frame, cv::Size(printDims.width, printDims.height));

    // Clear terminal before printing new frame
    std::cout << "\033[H\033[J";

    for (int y = 0; y < printDims.height; y++) {
        for (int x = 0; x < printDims.width; x++) {
            const int brightness = frame.at<uchar>(y, x);  // Get pixel intensity
            std::cout << getAscii(brightness);
        }
        std::cout << std::endl;
    }
}

void playVideoAsAscii(const std::string& videoPath) {
    cv::VideoCapture cap(videoPath);
    if (!cap.isOpened()) {
        std::cerr << "Failed to open video: " << videoPath << std::endl;
        return;
    }

    const int fps = static_cast<int>(cap.get(cv::CAP_PROP_FPS));
    const int frameDelay = (fps > 0) ? 1000000 / fps : 40000;

    cv::Mat frame, grayFrame;
    while (cap.read(frame)) {
        cv::cvtColor(frame, grayFrame, cv::COLOR_BGR2GRAY); // Convert to grayscale
        displayFrameAsAscii(grayFrame); // Display frame as ASCII
        usleep(frameDelay); // Control frame rate
    }
    cap.release();
}