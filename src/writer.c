#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int writeToPPM(char *path, int width, int height, int colorRange, uint8_t pixelsRGB[])
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
    
    //Calculate Total Array Length // ToDo: Figure out why -1 is needed, assumption because of a terminator or 0 as array start
    int arrayLength = (width * height * 3);

    //Write Pixel Data
    fwrite(pixelsRGB, sizeof(uint8_t), arrayLength, fptr); 

    //Close Filepointer(Cleanup) and return
    fclose(fptr);
    return 0;
}
//ToDo: Make it accept some sort of Input Array or something like that.