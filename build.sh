#!/bin/bash

gcc -o sort main.c algorithms/insertion_sort.c algorithms/bubble_sort.c algorithms/selection_sort.c algorithms/merge_sort.c algorithms/quick_sort.c algorithms/heap_sort.c algorithms/utils.c -lm
gcc gnuplot_graph.c -o gnuplot_graph

mkdir -p .data

./sort insertion reverse 100000 1000 > .data/insertion_sort.dat
./sort bubble reverse 100000 1000 > .data/bubble_sort.dat
./sort selection reverse 100000 1000 > .data/selection_sort.dat
./sort merge reverse 100000 1000 > .data/merge_sort.dat

./gnuplot_graph