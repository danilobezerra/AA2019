set title "Complexidade de Tempo para Todos os Algoritmos (Entrada Inversa)"
set autoscale

set style data lines

set xlabel "Tamanho da Entrada (N)"
set ylabel "Tempo (em segundos)"

set key left top

set grid

plot \
        ".data/insertion-rev.dat" title "Insertion Sort",\
        ".data/bubble-rev.dat" title "Bubble Sort", \
        ".data/selection-rev.dat" title "Selection Sort", \
        ".data/merge-rev.dat" title "Merge Sort", \
        ".data/quick-rev.dat" title "Quick Sort", \
        ".data/heap-rev.dat" title "Heap Sort"

pause -1 "Tecle enter para sair..."