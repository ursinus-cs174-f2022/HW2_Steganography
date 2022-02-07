/**
 * @file grayscale.cpp
 * @author Chris Tralie
 * 
 * Purpose: To convert an image to grayscale
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include "simplecanvas/SimpleCanvas.h"

using namespace std;

/**
 * @brief Replace the pixels in an image with their grayscale representation
 * 
 * @param image Image to process
 */
void grayscale(SimpleCanvas& image) {
    for (int i = 0; i < image.height; i++) {
        for (int j = 0; j < image.width; j++) {
            float R = (float)image.data[i][j][0];
            float G = (float)image.data[i][j][1];
            float B = (float)image.data[i][j][2];
            // https://scikit-image.org/docs/dev/auto_examples/color_exposure/plot_rgb_to_gray.html
            float gray = R*0.2125 + G*0.7154 + B*0.0721;
            for (int k = 0; k < 3; k++) {
                image.data[i][j][k] = (uint8_t)gray;
            }
        }
    }
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: ./grayscale <image in> <image out>\n");
        return 1;
    }
    SimpleCanvas image(argv[1]);
    grayscale(image);
    image.write(argv[2]);
    return 0;
}
