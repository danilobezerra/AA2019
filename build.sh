#!/bin/bash
gcc -o main main.c algorithms.c arraygenerator.c -lm
./main > selectionsort.dat
gcc gnuplot_graph.c -o gnuplot_graph
./gnuplot_graph