#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arraygenerator.h"
#include "algorithms.h"

#define TRUE 1
#define FALSE 0

#define INSERTION 'I'
#define BUBBLE 'B'
#define SELECTION 'S'
#define MERGE 'M'
#define QUICK 'Q'
#define HEAP 'H'

#define AVERAGE 'a'
#define BEST 'b'
#define WORST 'w'

long int getValue(char *[],int);
char getEntranceMode(char *[],int);
char getAlgorithm(char *[]);
void getOptionalParameters(char*, int*, char*[],int);
int isNumber(char*);
/** Apenas para Debug**/
void DEBUGEntryParameters(long int,char,char,int);
void DEBUGArrayCreation(long int, long int*,char);
void DEBUGPrintArray(long int, long int*);

/*** programa algoritmo n [mode,runs] ***/
/** Exemplo: ./main insertion 20 w **/
int main(int argc, char *argv[]) 
{
    long int n, *v;
    int runs;       /** Opcional, para suporte de várias experimentos individuais (não implementado) **/
    char algorithm; 
    char mode;      /** Opcional, especifica se é melhor, pior, ou caso médio. Nada especificado -> caso médio **/

    if(argc < 3) 
    {
        printf("Falta de parâmetros. Digite --help para mais informações."); /** TO DO: implementar help **/
        exit(EXIT_FAILURE);
    }

    algorithm = getAlgorithm(argv);
    if(algorithm == ' ') 
    {
        printf("Algoritmo desconhecido. Abortando");
        exit(EXIT_FAILURE);
    }

    n = getValue(argv,2);
    getOptionalParameters(&mode,&runs,argv,argc);

    /** DEBUG **/
    /* Verificação de parametros de entrada e alocação dinâmica. */
    DEBUGEntryParameters(n,algorithm,mode,runs); 

    /* Configuração e chamada de algoritmos */
    switch (algorithm)
    {
        case INSERTION:
            v = setupInsertionSort(n,mode);
            DEBUGPrintArray(n,v);
            // START TIME
            InsertionSort(n,v);
            // END TIME
            DEBUGPrintArray(n,v);
            break;
        case BUBBLE:
            // v = setupBubbleSort(n,mode);
            // START TIME
            // BubbleSort(n,v);
            // END TIME
            break;
        case SELECTION:
            // v = setupSelectionSort(n,mode);
            // START TIME
            // SelectionSort(n,v);
            // END TIME
            break;
        case MERGE:
            // v = setupMergeSort(n,mode);
            // START TIME
            // MergeSort(n,v);
            // END TIME
            break;
        case QUICK:
            // v = setupQuickSort(n,mode);
            // START TIME
            // QuickSort(n,v);
            // END TIME
            break;
        case HEAP:
            // v = setupHeapSort(n,mode);
            // START TIME
            // HeapSort(n,v);
            // END TIME
            break;
    }
    return 0;
}

long int getValue(char *argv[],int v) 
{
    char *p;
    long int value = strtol(argv[v], &p, 10);
    if (value < 1) return 1;
    return value;
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

void getOptionalParameters(char *mode, int *runs, char*argv[], int argc)
{   
    if(argc == 3) 
    {
        *mode = AVERAGE;
        *runs = 1;
    }
    else 
    {
        /* Modo entrada primeiro, depois numero de testes */
        if(!isNumber(argv[3])) 
        {
            *mode = getEntranceMode(argv,3);
            if(argc == 5) 
            {
                if(isNumber(argv[4])) 
                {
                    *runs = getValue(argv,4);
                }
            }
            else 
            {
                *runs = 1;
            }
        }
        /*numero de interações, depois modo*/
        else 
        {
            if(isNumber(argv[3]))
            {
                *runs = getValue(argv,3);
            }
            else 
            {
                *runs = 1;
            }
            if(argc == 5) 
            {
                *mode = getEntranceMode(argv,4);
            }
            else
            {
                *mode = AVERAGE;
            }           
        }
    }
    
}

char getEntranceMode(char *argv[], int v)
{
    char c = argv[v][0];

    switch (c)
    {
        case 'b':
            return BEST;
            break;
        case 'B':
            return BEST;
            break;
        case 'w':
            return WORST;
            break;
        case 'W':
            return WORST;
            break;
        case 'a':
            return AVERAGE;
            break;
        case 'A':
            return AVERAGE;
            break;
        default:
            return AVERAGE;
            break;
    }
}

int isNumber(char* string)
{

    for(int i = 0; i < strlen(string); i++) 
    {
        if(!isdigit(string[i]))
        {
            return FALSE;
        }
    }
    return TRUE;
}

/** Funções somente para verificação e testes. **/

void DEBUGEntryParameters(long int n, char algorithm, char mode, int runs)
{
    printf("Parametros: \n");
    printf("n: %d \n", n);
    printf("algorithm: %c \n", algorithm);
    printf("mode: %c \n", mode);
    printf("runs: %d \n", runs);
    printf(" ----- END OF DEBUG ENTRYPAR  -----\n");
}

void DEBUGPrintArray(long int n, long int *v)
{
    printf("\n Estado de v \n");
    for(int i = 0; i < n; i++)
    {
        printf("[%d] ",v[i]);
    }
    printf("\n ----- END OF DEBUG OF ARRAY CHECK -----\n");
}