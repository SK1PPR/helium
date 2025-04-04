//
// Created by khushalagrawal on 4/4/25.
//
#include <cstdio>
#include <stdio.h>
#include <utils.h>

Dimensions getTerminalDimensions() {
    Dimensions dims = {WIDTH, HEIGHT};

    FILE* pipe = popen("stty size", "r");
    if (!pipe) return dims;

    if (fscanf(pipe, "%d %d", &dims.height, &dims.width) != 2) {
        std::cerr << "Error getting terminal dimensions, defaulting to standard " << std::endl;
        dims.height = HEIGHT;
        dims.width = WIDTH;  // If parsing fails, use default width
    }
    pclose(pipe);  // Close the pipe

    return dims;
}

Dimensions getPrintDimensions(const Dimensions& dims) {
    Dimensions terminalDims = getTerminalDimensions();

    // To account for UI
    terminalDims.height--;

    // Check if width is the limiting factor
    if (const int newHeight = (dims.height * terminalDims.width) / (dims.width * SCALING_FACTOR); newHeight <= terminalDims.height) {
        terminalDims.height = newHeight;
        return terminalDims;
    }

    terminalDims.width = (dims.width * SCALING_FACTOR * terminalDims.height) / dims.height;
    return terminalDims;
}

char getAscii(const int brightness) {
    return GRAYSCALE[(brightness * (GRAYSCALE.length() - 1)) / 255];
}

