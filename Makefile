SHELL := /bin/bash

compilepthread:
	gcc Image.c main.c -o gray -lm -lpthread

compileomp:
	gcc Image.c main.c -o gray -lm -fopenmp