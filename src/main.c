#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
    char header[4] = "P6";
    int width = 1920;
    int height = 1080;
    int colorRange = 255;

    printf("PPM Writer v0\n");

    //Open FilePointer and Specify its overwrite and binary
    FILE *fptr;
    fptr = fopen("output.ppm", "wb");
    if (fptr == NULL)
    {
        perror("[ERROR] Status of fopen() in overwrite-text mode failed:");
        exit(1);
    }

    /*Create Header for Binary Mode PPM File, example:
    P6 (P3 for ASCII Encoding)
    Width Height
    ColorRange (0-255)
    */
    fprintf(fptr, "%s\n%d %d\n%d\n", header, width, height, colorRange);

    u_int64_t x;
    u_int64_t y;
    int colorB = 0;

    for (y = 0; y < height; y = y + 1)
    {
        for (x = 0; x < width; x = x +1)
        {
            int colorR = round((double)x / (double)width * (double)colorRange);
            int colorG = round((double)y / (double)height * (double)colorRange);
          
            //printf("X:%d,Y:%d | R:%d,G:%d,B:%d\n", x, y, colorR, colorG, colorB);
            fwrite(&colorR, sizeof(u_int8_t), 1, fptr);
            fwrite(&colorG, sizeof(u_int8_t), 1, fptr);
            fwrite(&colorB, sizeof(u_int8_t), 1, fptr);
        } 
    }
        

    fclose(fptr);
    return 0;
}
//ToDo: Make it accept some sort of Input Array or something like that.