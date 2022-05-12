SHELL := /bin/bash

compile:
	gcc Image.c main.c -o gray -lm -lpthread -fopenmp

testpth:
	sh runpth.sh

testomp:
	sh runomp.sh
