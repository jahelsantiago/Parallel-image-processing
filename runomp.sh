#!/bin/bash
> resultsOmp.txt
touch resultsOmp.txt
for img in 720p 1080p 4k
do
echo "----------------------------------------" >> resultsOmp.txt
echo "Running $img test with 1, 2, 4, 8, 16 threads"
for threads	in 1 2 4 8 16
do
echo "Running $img test with $threads threads"
echo -e "\n>> $img test with $threads threads:" >> resultsOmp.txt
./gray ./Images/${img}.png ./Output/${img}_"${threads}".png "${threads}" omp >> resultsOmp.txt
done
done
