SHELL := /bin/bash

compile:
	gcc Image.c main.c -o gray -lm -lpthread
runAll:
	@echo "Running 720p test with 1, 2, 4, 8, 16 threads:"
	@echo "To 1 thread, 720p:"
	time ./gray ./Images/720p.png ./Output/720p_1.png 1
	@echo "To 2 thread, 720p:"
	time ./gray ./Images/720p.png ./Output/720p_2.png 2
	@echo "To 4 thread, 720p:"
	time ./gray ./Images/720p.png ./Output/720p_4.png 4
	@echo "To 8 thread, 720p:"
	time ./gray ./Images/720p.png ./Output/720p_8.png 8
	@echo "To 16 thread, 720p:"
	time ./gray ./Images/720p.png ./Output/720p_16.png 16

	@echo "-----------------------------------------------"
	@echo "Running 1080p test with 1, 2, 4, 8, 16 threads:"
	@echo "To 1 thread, 1080p:"
	time ./gray ./Images/1080p.png ./Output/1080p_1.png 1
	@echo "To 2 thread, 1080p:"
	time ./gray ./Images/1080p.png ./Output/1080p_2.png 2
	@echo "To 4 thread, 1080p:"
	time ./gray ./Images/1080p.png ./Output/1080p_4.png 4
	@echo "To 8 thread, 1080p:"
	time ./gray ./Images/1080p.png ./Output/1080p_8.png 8
	@echo "To 16 thread, 1080p:"
	time ./gray ./Images/1080p.png ./Output/1080p_16.png 16

	@echo "-----------------------------------------------"
	@echo "Running 4k test with 1, 2, 4, 8, 16 threads:"
	@echo "To 1 thread:"
	time ./gray ./Images/4k.png ./Output/4k_1.png 1
	@echo "To 2 thread, 4k:"
	time ./gray ./Images/4k.png ./Output/4k_2.png 2
	@echo "To 4 thread, 4k:"
	time ./gray ./Images/4k.png ./Output/4k_4.png 4
	@echo "To 8 thread, 4k:"
	time ./gray ./Images/4k.png ./Output/4k_8.png 8
	@echo "To 16 thread, 4k:"
	time ./gray ./Images/4k.png ./Output/4k_16.png 16

