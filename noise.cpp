/**
 * @file grayscale.cpp
 * @author Chris Tralie
 * 
 * Purpose: To add a certain amount of noise to an image
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include "simplecanvas/SimpleCanvas.h"
#include "randutils.h"

using namespace std;

/**
 * @brief Add noise to every channel of every pixel
 * 
 * @param image Image to which to add noise
 * @param snr Signal to noise ratio
 */
void noise(SimpleCanvas& image, float snr) {
    RandFloat r;
    float amt = 255/snr;
    for (int i = 0; i < image.height; i++) {
        for (int j = 0; j < image.width; j++) {
            for (int k = 0; k < 3; k++) {
                float x = (float)image.data[i][j][k];
                x += amt*(r.nextFloat()-0.5);
                if (x > 255) {
                    x = 255;
                }
                if (x < 0) {
                    x = 0;
                }
                image.data[i][j][k] = (uint8_t)x;
            }
        }
    }
}

int main(int argc, char** argv) {
    if (argc < 4) {
        printf("Usage: ./noise <image in> <snr> <image out>\n");
        return 1;
    }
    SimpleCanvas image(argv[1]);
    float snr = atof(argv[2]);
    noise(image, snr);
    image.write(argv[3]);
    return 0;
}
