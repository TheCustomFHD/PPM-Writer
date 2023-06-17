#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

int writeToPPM(char *path, int width, int height, int colorRange, int pixelsRGB[], int totalPixelCount)
{
    //Open FilePointer and Specify its overwrite and binary
    FILE *fptr;
    fptr = fopen(path, "wb");
    if (fptr == NULL)
    {
        perror("[ERROR] Status of fopen() in overwrite-text mode failed:");
        exit(1);
    }

    /*
    Create Header for Binary Mode PPM File, example:
    P6 (P3 for ASCII Encoding)
    Width Height
    ColorRange (0-255)
    */
    char header[4] = "P6";
    fprintf(fptr, "%s\n%d %d\n%d\n", header, width, height, colorRange);

    uint8_t colorB = 0;

    for (uint64_t y = 0; y < height; y = y + 1)
    {
        for (uint64_t x = 0; x < width; x = x +1)
        {
            uint8_t colorR = round((double)x / (double)width * (double)colorRange);
            uint8_t colorG = round((double)y / (double)height * (double)colorRange);
          
            //printf("X:%d,Y:%d | R:%d,G:%d,B:%d\n", x, y, colorR, colorG, colorB);
            fwrite(&colorR, sizeof(uint8_t), 1, fptr);
            fwrite(&colorG, sizeof(uint8_t), 1, fptr);
            fwrite(&colorB, sizeof(uint8_t), 1, fptr);
        } 
    }
        

    fclose(fptr);
    return 0;
}
//ToDo: Make it accept some sort of Input Array or something like that.