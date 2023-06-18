#include <stdio.h>
#include <stdint.h>
#include "writer.c"

int main(void)
{
    int width = 2;
    int height = 2;
    int colordepth = 1;

    //Array must be (Width * Height * 3). 3 for RGB, and must be a uint8_t, to stay under 8Bit (255 MAX color value for PPM)
    uint8_t samplePic[12] = {0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1};

    printf("Starting Writing PPM\n");
    writeToPPM("out.ppm", width, height, colordepth, samplePic);

    return 0;
}

/*
ToDo:   Add Mandelbrot Set Renderer, and make it output into singular uint8_t array thats 3 times larger
        then total amopunt of pixels (R then G then B)
*/