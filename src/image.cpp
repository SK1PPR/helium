//
// Created by khushalagrawal on 4/4/25.
//
#define STB_IMAGE_IMPLEMENTATION
#include <image.h>

void printImage(const std::string& imagePath) {

    int width, height, channels;
    unsigned char* image = stbi_load(imagePath.c_str(), &width, &height, &channels, 1);

    if (!image) {
        std::cerr << "Failed to load image: " << imagePath << std::endl;
        return;
    }

    const Dimensions printDims = getPrintDimensions(Dimensions(width, height));

    std::cout << "\033[H\033[J"; // ANSI code to clear terminal

    for (int y = 0; y < printDims.height; y++) {
        for (int x = 0; x < printDims.width; x++) {
            const int origX = x * width / printDims.width;
            const int origY = y * height / printDims.height;
            const int brightness = image[origY * width + origX];
            std::cout << getAscii(brightness);
        }
        std::cout << std::endl;
    }

    stbi_image_free(image);
}