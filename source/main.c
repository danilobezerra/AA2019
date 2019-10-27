#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

int getValue(char *[],int);
char getEntranceMode(char *[],int);
char getAlgorithm(char *[]);
void getOptionalParameters(char*, int*, char*[],int);
int isNumber(char*);
/** Apenas para Debug**/
void DEBUGEntryParameters(long int,char,char,int);

/*** programa modo n [-opcao] [-i] ***/
int main(int argc, char *argv[]) 
{
    long int n, *v;
    int runs;
    char algorithm;
    char mode;

    if(argc < 3) 
    {
        printf("Falta de parâmetros. Digite --help para mais informações.");
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
    DEBUGEntryParameters(n,algorithm,mode,runs);

    return 0;
}

int getValue(char *argv[],int v) 
{
    char *p;
    int value = strtol(argv[v], &p, 10);
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
        case 'm':
            return AVERAGE;
            break;
        case 'M':
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

void DEBUGEntryParameters(long int n, char algorithm, char mode, int runs)
{
    printf("Parametros: \n");
    printf("n: %d \n", n);
    printf("algorithm: %c \n", algorithm);
    printf("mode: %c \n", mode);
    printf("runs: %d \n", runs);
    printf(" ----- DEBUG END -----\n");
}