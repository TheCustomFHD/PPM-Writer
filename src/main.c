#include <stdio.h>
#include <stdint.h>
#include "writer.c"

int main(void)
{
    //Reusable Variables
    int functionOutput = 0;

    int width = 2;
    int height = 3;
    int colordepth = 1;

    //Array must be (Width * Height * 3). 3 for RGB, and must be a uint8_t, to stay under 8Bit (255 MAX color value for PPM)
    uint8_t samplePic[18] = {0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1};

    printf("[Info] Starting to write to PPM File (P6)\n");
    functionOutput = writeToPPM("out.ppm", width, height, colordepth, samplePic);
    switch(functionOutput)
    {
        case 1:
            printf("[ERROR] File Error\n");
            break;
        
        case 2:
            printf("[ERROR] fwrite() Error\n");
            break;

        default:
            printf("[Info] Writing Successful\n");
            break;
    }

    return 0;
}

/*
ToDo:   Add Mandelbrot Set Renderer, and make it output into singular uint8_t array thats 3 times larger
        then total amopunt of pixels (R then G then B)
*/