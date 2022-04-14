#include "Image.h"
#include "utils.h"
#include "time.h"

char **global_argv;

int main(int argc, char** argv ) {
    // Put the input arguments in a global variable to be used by the threads
    global_argv = argv;

    // Check if the user has entered the correct number of arguments
    if ( argc != 4 ){
        printf("Input error!\nUse: ./gray <original_image_route> <gray_image_route> <num_threads>\n");
        return -1;
    }



    Image img_original;

    // Load the original_image_route
    Image_load(&img_original, argv[1]);
    ON_ERROR_EXIT(img_original.data == NULL, "Error in loading the image");

    // take time to measure the execution time
    clock_t begin = clock();

    // Convert the images to gray
    Image img_gray_result;
    paralel_image_to_gray(&img_original, &img_gray_result);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;


    // Save images
    Image_save(&img_gray_result, argv[2]);
    printf("Images saved successfully\n");

    // Release memory
    Image_free(&img_original);
    Image_free(&img_gray_result);

    printf("Execution time: %f\n", time_spent);
}
