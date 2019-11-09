#!/bin/bash

gcc -o sort main.c algorithms.c arraygenerator.c -lm
./sort insertion reverse 4096 4 > insertionsort.dat
./sort bubble reverse 4096 4 > bubblesort.dat
./sort selection reverse 4096 4 > selectionsort.dat

gcc gnuplot_graph.c -o gnuplot_graph
./gnuplot_graph