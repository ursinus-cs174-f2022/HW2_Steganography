#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include "ellipse.h"
#include "simplecanvas/SimpleCanvas.h"


int main(int argc, char** argv) {
    int width = 800;
    int height = 800;
    uint8_t** data = allocateImage(width, height);

    drawEllipse(data, width, height, width/2, height/2, width/4, height/3, 150);
    drawEllipse(data, width, height, width/2-width/8, height/2-height/8, width/16, height/16, 50);
    drawEllipse(data, width, height, width/2+width/8, height/2-height/8, width/16, height/16, 50);
    drawEllipse(data, width, height, width/2, height/2+height/8, width/6, height/16, 50);
    
    writeImage("art.png", data, width, height);
    freeImage(data, height);

    return 0;
}

