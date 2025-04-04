//
// Created by khushalagrawal on 4/4/25.
//
#pragma once

#include <vector>
#include <unistd.h>
#include <iostream>

const std::string GRAYSCALE = "@%#*+=-:. "; // For grayscale

// This is because ASCII width is much lower than ASCII height
constexpr int SCALING_FACTOR = 2;

static int WIDTH = 80;
static int HEIGHT = 40;

struct Dimensions {
    int width;
    int height;
};

// Get terminal dimensions
Dimensions getTerminalDimensions();

// Get print dimensions based on limiting factor
Dimensions getPrintDimensions(const Dimensions& dims);

char getAscii(const int brightness);