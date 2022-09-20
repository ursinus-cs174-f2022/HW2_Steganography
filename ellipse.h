#ifndef ELLIPSE_H
#define ELLIPSE_H

typedef unsigned char uint8_t;

/**
 * @brief Allocate an image that's height x width
 * 
 * @param width Width of image
 * @param height Height of image
 * @return uint8_t** Pointer to image
 */
uint8_t** allocateImage(int width, int height);

/**
 * @brief Free the dynamic memory allocated to the image
 * 
 * @param image Pointer to image
 * @param height Height of image
 */
void freeImage(uint8_t** image, int height);

/**
 * @brief Draw an ellipse on the image
 * 
 * @param image Pointer to image
 * @param width Width of image
 * @param height Height of image
 * @param cx Center of ellipse in x
 * @param cy Center of ellipse in y
 * @param sx Scale of ellipse in x
 * @param sy Scale of ellipse in y
 * @param shade Shade of the ellipse, between 0 (black) and 255 (white)
 */
void drawEllipse(uint8_t** image, int width, int height, float cx, float cy, float sx, float sy, uint8_t shade);


#endif