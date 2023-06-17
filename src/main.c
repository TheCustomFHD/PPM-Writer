#include <stdio.h>
#include <stdint.h>
#include "writer.c"

int main(void)
{
    int replaceMe[3];

    printf("Writing PPM\n");
    writeToPPM("out.ppm", 160, 90, 15, replaceMe, (160 * 90));

    return 0;
}

/*
ToDo:   Add Mandelbrot Set Renderer, and make it output into singular uint8_t array thats 3 times larger
        then total amopunt of pixels (R then G then B)
*/