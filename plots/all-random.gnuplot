set title "Complexidade de Tempo para Todos os Algoritmos (Entrada Aleatória)"
set autoscale

set style data lines

set xlabel "Tamanho da Entrada (N)"
set ylabel "Tempo (em segundos)"

set key left top

set grid

plot \
        ".data/insertion-rnd.dat" title "Insertion Sort",\
        ".data/bubble-rnd.dat" title "Bubble Sort", \
        ".data/selection-rnd.dat" title "Selection Sort", \
        ".data/merge-rnd.dat" title "Merge Sort", \
        ".data/quick-rnd.dat" title "Quick Sort", \
        ".data/heap-rnd.dat" title "Heap Sort"

pause -1 "Tecle enter para sair..."