#include <iostream>
#include <opencv2/opencv.hpp>
#include <image.h>
#include <video.h>


int main(const int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " --img <filename> OR " << argv[0] << " --vid <filename>" << std::endl;
        return 1;
    }
    const std::string mode = argv[1];
    const std::string filePath = argv[2];
    if (mode == "--img") {
        printImage(filePath);
    } else if (mode == "--vid") {
        playVideoAsAscii(filePath);
    } else {
        std::cerr << "Invalid flag. Use --img for images or --vid for videos." << std::endl;
        return 1;
    }
    return 0;
}