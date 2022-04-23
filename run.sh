#!/bin/bash
> results.txt
touch results.txt
for img in 720p 1080p 4k
do
echo "----------------------------------------" >> results.txt
echo "Running $img test with 1, 2, 4, 8, 16 threads"
for threads	in 1 2 4 8 16
do
echo "Running $img test with $threads threads"
echo -e "\n>> $img test with $threads threads:" >> results.txt
./gray ./Images/${img}.png ./Output/${img}_"${threads}".png "${threads}" >> results.txt
done
done
