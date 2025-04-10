#include <iostream>
#include <opencv2/opencv.hpp>
#include <image.h>
#include <video.h>


int main(const int argc, char** argv) {
    if (argc < 3 || argc > 4) {
        std::cerr << "Usage:\n"
                  << "  " << argv[0] << " --img <filename>\n"
                  << "  " << argv[0] << " --vid <filename> [--color]\n";
        return 1;
    }

    const std::string mode = argv[1];
    const std::string filePath = argv[2];

    if (mode == "--img") {
        printImage(filePath);
    } else if (mode == "--vid") {
        // Check optional 4th argument
        const bool useColor = (argc == 4 && std::string(argv[3]) == "--color");
        playVideoAsAscii(filePath, useColor);
    } else {
        std::cerr << "Invalid flag. Use --img for images or --vid for videos." << std::endl;
        return 1;
    }

    return 0;
}