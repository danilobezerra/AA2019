#!/bin/bash

gcc -o sort main.c algorithms/insertion_sort.c algorithms/bubble_sort.c algorithms/selection_sort.c algorithms/merge_sort.c algorithms/quick_sort.c algorithms/heap_sort.c algorithms/utils.c -lm
gcc gnuplot_graph.c -o gnuplot_graph

mkdir -p .data

./sort insertion random 10000 100 > .data/insertion_sort.dat
./sort bubble random 10000 100 > .data/bubble_sort.dat
./sort selection random 10000 100 > .data/selection_sort.dat
./sort merge random 10000 100 > .data/merge_sort.dat
./sort quick random 10000 100 > .data/quick_sort.dat
./sort heap random 10000 100 > .data/heap_sort.dat

./gnuplot_graph