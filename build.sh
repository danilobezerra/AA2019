#!/bin/bash

gcc -o sort main.c algorithms.c arraygenerator.c -lm
./sort insertion reverse 1024 1 > insertionsort.dat
./sort bubble reverse 1024 1 > bubblesort.dat
./sort selection reverse 1024 1 > selectionsort.dat
./sort merge reverse 1024 1 > mergesort.dat

gcc gnuplot_graph.c -o gnuplot_graph
./gnuplot_graph