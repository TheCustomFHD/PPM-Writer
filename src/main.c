#include <stdio.h>
#include <stdint.h>
#include "writer.c"

int iterateMandel(float cx, float cy, int iterations)
{
    float zx = 0;
    float zy = 0;
    float i = 0;
    for(i = 0; i < iterations; i = i + 1)
    {
        float zx2 = zx * zx - zy * zy + cx;
        float zy2 = 2 * zx * zy + cy;
        zx = zx2;
        zy = zy2;
        if (zx * zx + zy * zy > (float)2 * (float)2)
        {
            return i;
        }
    }
    return 0;
}

int main(void)
{
    //Reusable Variables
    int functionOutput = 0;

    //Example SamplePic
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

    //Mandelbrot
    width = 1024;
    height = 768;
    colordepth = 255;

    uint8_t mandelset[2359296] = {0};
    int X = 0;
    int Y = 0;

    int currentInt = 0;
    int rgbhop = 0;

    for(Y = 0; Y < height; Y = Y + 1)
    {
        for(X = 0; X < width; X = X + 1)
        {
            float cx = (float)X / (float)width * (float)2 - (float)1.5;
            float cy = (float)Y / (float)height * (float)2 - (float)1;
            int grey = iterateMandel(cx, cy, colordepth);
            for(rgbhop = 0; rgbhop < 3; rgbhop = rgbhop + 1)
            {
                mandelset[currentInt] = grey;
                currentInt = currentInt + 1;
            }
            
        }
    }

    functionOutput = writeToPPM("mandel.ppm", width, height, colordepth, mandelset);

    return 0;
}

/*
ToDo:   Add Mandelbrot Set Renderer, and make it output into singular uint8_t array thats 3 times larger
        then total amopunt of pixels (R then G then B)
*/