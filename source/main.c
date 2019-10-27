#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define INSERTION 'I'
#define BUBBLE 'B'
#define SELECTION 'S'
#define MERGE 'M'
#define QUICK 'Q'
#define HEAP 'H'

int getSize(char *argv[]);
char getEntranceMode(char *argv[]);
char getAlgorithm(char *argv[]);

/*** programa n modo [-opcao] [-i] ***/
int main(int argc, char *argv[]) 
{
    long int n, *v, runs;
    char algorithm;
    char mode;

    if(argc < 2) 
    {
        printf("Falta de parâmetros. Digite --help para mais informações.");
        exit(EXIT_FAILURE);
    }

    n = getSize(argv);
    algorithm = getAlgorithm(argv);
    if(algorithm == ' ') 
    {
        printf("Algoritm odesconhecido. Abortando");
        exit(EXIT_FAILURE);
    }

    if(argc > 2) 
    {
        mode = getEntranceMode(argv);
        if(argc == 4) 
        {
            runs = getEntranceMode(argv);
        }
        else 
        {
            runs = 1;
        }
    }

    printf("Parametros: [%d,%c,%c,%d]", n, algorithm, mode, runs);
    return 0;
}

int getSize(char *argv[]) 
{
    char *p;
    return strtol(argv[1], &p, 20);
}

char getAlgorithm(char *argv[])
{
    if(!strcmp("insertion",argv[1]) || !strcmp("Insertion",argv[1]) || !strcmp("InsertionSort",argv[1])) 
    {
        return INSERTION;
    }
    else if(!strcmp("bubble",argv[1]) || !strcmp("Bubble",argv[1]) || !strcmp("BubbleSort",argv[1]))
    {
        return BUBBLE;
    }
    else if(!strcmp("selection",argv[1]) || !strcmp("Selection",argv[1]) || !strcmp("SelectionSort",argv[1]))
    {
        return SELECTION;
    }
    else if(!strcmp("merge",argv[1]) || !strcmp("Merge",argv[1]) || !strcmp("MergeSort",argv[1]))
    {
        return MERGE;
    }
    else if(!strcmp("quick",argv[1]) || !strcmp("Quick",argv[1]) || !strcmp("QuickSort",argv[1]))
    {
        return QUICK;
    }
    else if(!strcmp("heap",argv[1]) || !strcmp("Heap",argv[1]) || !strcmp("HeapSort",argv[1]))
    {
        return HEAP;
    }
    else 
    {
        return ' ';
    }
}

char getEntranceMode(char *argv[])
{
    char c = argv[2][0];

    switch (c)
    {
        case 'b':
            return 'b';
            break;
        case 'B':
            return 'b';
            break;
        case 'w':
            return 'w';
            break;
        case 'W':
            return 'w';
            break;
        default:
            return 'm';
            break;
    }
}