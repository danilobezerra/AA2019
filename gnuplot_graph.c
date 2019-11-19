#include <stdio.h>
#include <stdlib.h>

#define GNUPLOT "gnuplot -persist"

int main(int argc, char **argv) {
    FILE *gnuplot;

    gnuplot = popen(GNUPLOT, "w");
    if (gnuplot == NULL) {
        printf("Erro ao abrir pipe para o GNU plot.\n"
            "Instale com 'sudo apt-get install gnuplot'\n");
        exit(0);
    }

    fprintf(gnuplot, "set title 'Todos os algoritmos'\n");
    fprintf(gnuplot, "set autoscale\n");
    fprintf(gnuplot, "set style data lines\n\n");
    fprintf(gnuplot, "set xlabel 'Tamanho da entrada (N)'\n");
    fprintf(gnuplot, "set ylabel 'Tempo de execução (segundos)'\n");

    fprintf(gnuplot, "plot '.data/insertion_sort.dat'\n");
    fprintf(gnuplot, "rep '.data/bubble_sort.dat'\n");
    fprintf(gnuplot, "rep '.data/selection_sort.dat'\n");
    fprintf(gnuplot, "rep '.data/merge_sort.dat'\n");
    fprintf(gnuplot, "rep '.data/quick_sort.dat'\n");
    fprintf(gnuplot, "rep '.data/heap_sort.dat'\n");

    fflush(gnuplot);
}