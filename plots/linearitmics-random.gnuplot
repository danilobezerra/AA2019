set title "Complexidade de Tempo para os Algoritmos Linearítmicos"
set autoscale

set style data lines

set xlabel "Tamanho da Entrada (N)"
set ylabel "Tempo (em segundos)"

set key left top

set grid

plot \
        ".data/merge-rnd.dat" title "Merge Sort", \
        ".data/quick-rnd.dat" title "Quick Sort", \
        ".data/heap-rnd.dat" title "Heap Sort"

pause -1 "Tecle enter para sair..."