SHELL := /bin/bash

compile:
	gcc Image.c main.c -o gray -lm -lpthread

test:
	sh run.sh