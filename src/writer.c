#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//ToDo: Rename Function and "Libary", include that this function does P6 Binary
int writeToPPM(char *path, int width, int height, int colorRange, uint8_t pixelsRGB[])
{
    //Reusable Variables
    int functionOutput = 0;

    //Open FilePointer and Specify its overwrite and binary
    FILE *fptr;
    fptr = fopen(path, "wb");
    if (fptr == NULL)
    {
        perror("[ERROR] Status of fopen() in overwrite-text mode:");
        return 1;
    }

    /*
    Create and write Header for Binary Mode PPM File, example:
    P6
    Width Height
    ColorRange (0-255)
    */
    char header[4] = "P6";
    fprintf(fptr, "%s\n%d %d\n%d\n", header, width, height, colorRange);
    
    //Calculate Total Array Length
    int arrayLength = (width * height * 3);

    //Write Pixel Data
    functionOutput = fwrite(pixelsRGB, sizeof(uint8_t), arrayLength, fptr); 
    if (functionOutput != arrayLength)
    {
        //Error Checking, unsure of its effectivness, ImproveMe:
        int functionOutput = ferror(fptr);
        printf("[ERROR] fwrite() had an error, quitting: %d\n", functionOutput);
        clearerr(fptr);
        return 2;
    }

    //printf("[DEBUG] FWRITE OUTPUT: %d\n", functionOutput);

    //Close Filepointer(Cleanup) and return
    fclose(fptr);
    return 0;
}