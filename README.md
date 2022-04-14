gcc Image.c main.c -o gray -lpthread

time ./gray ./Input_images/sky.jpg ./Output_images/sky_gray.jpg 4

gcc -std=c17 -Wall Image.c main.c -o t2 -lm -lpthread
