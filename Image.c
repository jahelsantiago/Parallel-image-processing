//This is a program to parallelize the image processing using convolution and posix threads.

#include <stdint.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main() {
    int width, height, bpp;

    //The image is stored in the rgb_image array in the following format:
    //rgb_image[0] = red component of the first pixel
    //rgb_image[1] = green component of the first pixel
    //rgb_image[2] = blue component of the first pixel
    uint8_t* rgb_image = stbi_load("image.png", &width, &height, &bpp, 3);

    stbi_image_free(rgb_image); //Free the image data

    // print the width and height of the image
    printf("width: %d, height: %d\n", width, height);

    return 0;
}





