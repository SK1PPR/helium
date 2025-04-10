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

void displayFrameAsAsciiColor(cv::Mat& frame) {
    const Dimensions printDims = getPrintDimensions(Dimensions(frame.cols, frame.rows));
    cv::resize(frame, frame, cv::Size(printDims.width, printDims.height));

    std::cout << "\033[H\033[J"; // Clear screen

    for (int y = 0; y < printDims.height; y++) {
        for (int x = 0; x < printDims.width; x++) {
            auto color = frame.at<cv::Vec3b>(y, x);  // BGR
            const int b = color[0];
            const int g = color[1];
            const int r = color[2];

            // Convert to 216-color cube (0-5 per channel)
            const int r6 = r * 6 / 256;
            const int g6 = g * 6 / 256;
            const int b6 = b * 6 / 256;
            const int ansiColor = 16 + 36 * r6 + 6 * g6 + b6;

            // Grayscale brightness for picking character
            const int brightness = (r + g + b) / 3;
            const char c = getAscii(brightness);

            std::cout << "\033[38;5;" << ansiColor << "m" << c;
        }
        std::cout << "\033[0m\n";  // Reset color
    }
}

void playVideoAsAscii(const std::string& videoPath, const bool color) {
    cv::VideoCapture cap(videoPath);
    if (!cap.isOpened()) {
        std::cerr << "Failed to open video: " << videoPath << std::endl;
        return;
    }

    const int fps = static_cast<int>(cap.get(cv::CAP_PROP_FPS));
    const int frameDelay = (fps > 0) ? 1000000 / fps : 40000;

    cv::Mat frame, grayFrame;
    while (cap.read(frame)) {
        if (color) {
            displayFrameAsAsciiColor(frame);
        } else {
            cv::cvtColor(frame, grayFrame, cv::COLOR_BGR2GRAY); // Convert to grayscale
            displayFrameAsAscii(grayFrame);
        }
        usleep(frameDelay); // Control frame rate
    }
    cap.release();
}