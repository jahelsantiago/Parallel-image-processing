#!/bin/bash
> resultsPth.txt
touch resultsPth.txt
for img in 720p 1080p 4k
do
echo "----------------------------------------" >> resultsPth.txt
echo "Running $img test with 1, 2, 4, 8, 16 threads"
for threads	in 1 2 4 8 16
do
echo "Running $img test with $threads threads"
echo -e "\n>> $img test with $threads threads:" >> resultsPth.txt
./gray ./Images/${img}.png ./Output/${img}_"${threads}".png "${threads}" posix >> resultsPth.txt
done
done
