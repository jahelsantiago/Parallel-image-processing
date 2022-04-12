//This is a program to parallelize the image processing using convolution and posix threads.

//add headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>

//add opencv headers
#include <opencv2/core/types_c.h>


//read a .jpg image using opencv
IplImage* read_image(char* filename)
{
    IplImage* img = cvLoadImage(filename, CV_LOAD_IMAGE_COLOR);
    if (!img)
    {
        printf("Could not open file %s\n", filename);
        return 0;
    }
    return img;
}


//convert IplImage to a matrix of doubles 
double** convert_IplImage_to_matrix(IplImage* img)
{
    double** matrix = (double**)malloc(img->height * sizeof(double*));
    for (int i = 0; i < img->height; i++)
    {
        matrix[i] = (double*)malloc(img->width * sizeof(double));
    }
    for (int i = 0; i < img->height; i++)
    {
        for (int j = 0; j < img->width; j++)
        {
            matrix[i][j] = (double)img->imageData[i * img->widthStep + j * img->nChannels];
        }
    }
    return matrix;
}

//convert a matrix of doubles to an IplImage
IplImage* convert_matrix_to_IplImage(double** matrix, int height, int width)
{
    IplImage* img = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 1);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            img->imageData[i * img->widthStep + j * img->nChannels] = (unsigned char)matrix[i][j];
        }
    }
    return img;
}

//write an IplImage to a .jpg file
void write_image(IplImage* img, char* filename)
{
    cvSaveImage(filename, img);
}

//function to apply convolutions to a matrix of doubles
double** convolve(double** matrix, int height, int width, double** kernel, int kernel_height, int kernel_width)
{
    double** result = (double**)malloc(height * sizeof(double*));
    for (int i = 0; i < height; i++)
    {
        result[i] = (double*)malloc(width * sizeof(double));
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double sum = 0;
            for (int k = 0; k < kernel_height; k++)
            {
                for (int l = 0; l < kernel_width; l++)
                {
                    int x = i + k - kernel_height / 2;
                    int y = j + l - kernel_width / 2;
                    if (x >= 0 && x < height && y >= 0 && y < width)
                    {
                        sum += matrix[x][y] * kernel[k][l];
                    }
                }
            }
            result[i][j] = sum;
        }
    }
    return result;
}


//creat a main function to test the program
int main(int argc, char** argv)
{
    //read the image
    IplImage* img = read_image("lena.jpg");
    //convert the image to a matrix of doubles
    double** matrix = convert_IplImage_to_matrix(img);
    //create a kernel
    double** kernel = (double**)malloc(3 * sizeof(double*));
    for (int i = 0; i < 3; i++)
    {
        kernel[i] = (double*)malloc(3 * sizeof(double));
    }
    kernel[0][0] = 1;
    kernel[0][1] = 1;
    kernel[0][2] = 1;
    kernel[1][0] = 1;
    kernel[1][1] = 1;
    kernel[1][2] = 1;
    kernel[2][0] = 1;
    kernel[2][1] = 1;
    kernel[2][2] = 1;
    //apply the convolution
    double** result = convolve(matrix, img->height, img->width, kernel, 3, 3);
    //convert the result to an IplImage
    IplImage* result_img = convert_matrix_to_IplImage(result, img->height, img->width);
    //write the result to a .jpg file
    write_image(result_img, "result.jpg");
    //free the memory
    cvReleaseImage(&img);
    cvReleaseImage(&result_img);
    for (int i = 0; i < 3; i++)
    {
        free(kernel[i]);
    }
    free(kernel);
    for (int i = 0; i < img->height; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    for (int i = 0; i < img->height; i++)
    {
        free(result[i]);
    }
    free(result);
    return 0;
}

