# AA2019

Repositório do trabalho da disciplina de Análise de Algoritmos da UFABC

## Tarefas

- [x] Estrutura básica do relatório: capa, índice e seções. (_Melhorar um pouco no visual ainda, talvez?_)
- [x] Estrutura básica do programa, leitura dos parâmetros, seguido do controle de fluxo esperado. (_Revisado, e mais flexível_)
- [x] Algoritmos elementares (_Insertion, Selection e Bubble_) funcionando para todas entradas (_melhor, pior, random_)
- [x] Implementar os algoritmos em algoritmos.c:
  - MergeSort
  - QuickSort
  - HeapSort
- [x] Fazer a geração do melhor, pior e randômico para cada algoritmo restante
- [x] Descrever o funcionamento dos algoritmos (_com pseudo código?_)
- [x] Definir ambiente de execução
- [x] Resultados e Análise
- [x] Listar do documentos e referências (_Opcional_)

## Pré-requisitos

- Algum compilador C/C++ como o [GCC](https://gcc.gnu.org/) (Linux/macOS) ou [MinGW](http://www.mingw.org/) (Windows).
- O [Gnuplot](http://www.gnuplot.info/) para plotar os gráficos.

## Uso

O programa principal executa os algoritmos a partir dos seguintes parâmetros:

```shell
./sort {0} {1} {2} {3}
```

- `{0}`: Nome (Obrigatório)
  - `insertion`
  - `bubble`
  - `selection`
  - `merge`
  - `quick`
  - `heap`

- `{1}`: Ordenação (Obrigatório)
  - `random`
  - `sorted`
  - `reverse`

- `{2}`: Tamanho (Opcional, padrão = 1000)

- `{3}`: Passo (Opcional, padrão = 1)

## Exemplo

Compilar o arquivo principal e os algoritmos:

```shell
gcc -o sort main.c algorithms/insertion_sort.c algorithms/bubble_sort.c algorithms/selection_sort.c algorithms/merge_sort.c algorithms/quick_sort.c algorithms/heap_sort.c algorithms/utils.c -lm
```

Criar um diretório para armazenar os dados:

```shell
mkdir -p .data
```

Executar os algoritmos com entrada aleatória:

```shell
./sort insertion random 160000 10000 > .data/insertion-rnd.dat
./sort bubble random 160000 10000 > .data/bubble-rnd.dat
./sort selection random 160000 10000 > .data/selection-rnd.dat
./sort merge random 160000 10000 > .data/merge-rnd.dat
./sort quick random 160000 10000 > .data/quick-rnd.dat
./sort heap random 160000 10000 > .data/heap-rnd.dat
```

Executar os algoritmos com entrada ordenada:

```shell
./sort insertion sorted 160000 10000 > .data/insertion-srt.dat
./sort bubble sorted 160000 10000 > .data/bubble-srt.dat
./sort selection sorted 160000 10000 > .data/selection-srt.dat
./sort merge sorted 160000 10000 > .data/merge-srt.dat
./sort quick sorted 160000 10000 > .data/quick-srt.dat
./sort heap sorted 160000 10000 > .data/heap-srt.dat
```

Executar os algoritmos com entrada inversa:

```shell
./sort insertion reverse 160000 10000 > .data/insertion-rev.dat
./sort bubble reverse 160000 10000 > .data/bubble-rev.dat
./sort selection reverse 160000 10000 > .data/selection-rev.dat
./sort merge reverse 160000 10000 > .data/merge-rev.dat
./sort quick reverse 160000 10000 > .data/quick-rev.dat
./sort heap reverse 160000 10000 > .data/heap-rev.dat
```

Plotar os gráficos:

```shell
gnuplot plots/all-random.gnuplot
gnuplot plots/all-sorted.gnuplot
gnuplot plots/all-reverse.gnuplot
gnuplot plots/linearitmics-random.gnuplot
```

## Contribuição

- [Danilo Bezerra](https://github.com/danilobezerra)
- [Diego Martos](https://github.com/dmb42odyssey)

## Licença

MIT License
