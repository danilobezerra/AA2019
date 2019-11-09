#!/bin/bash

gcc -o sort main.c algorithms.c arraygenerator.c -lm
./sort insertion 5000 reverse > insertionsort.dat
./sort bubble 5000 reverse > bubblesort.dat
./sort selection 5000 reverse > selectionsort.dat

gcc gnuplot_graph.c -o gnuplot_graph
./gnuplot_graph