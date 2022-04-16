SHELL := /bin/bash

compile:
	gcc Image.c main.c -o gray -lm -lpthread