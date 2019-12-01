set title "Complexidade de Tempo para Todos os Algoritmos (Entrada Ordenada)"
set autoscale

set style data lines

set xlabel "Tamanho da Entrada (N)"
set ylabel "Tempo (em segundos)"

set key left top

set grid

plot \
        ".data/insertion-srt.dat" title "Insertion Sort",\
        ".data/bubble-srt.dat" title "Bubble Sort", \
        ".data/selection-srt.dat" title "Selection Sort", \
        ".data/merge-srt.dat" title "Merge Sort", \
        ".data/quick-srt.dat" title "Quick Sort", \
        ".data/heap-srt.dat" title "Heap Sort"

pause -1 "Tecle enter para sair..."