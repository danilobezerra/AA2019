#include "arraygenerator.h"

long int* allocateArray(long int n)
{
    long int *v;

    v = malloc(sizeof(long int) * n);
    if(v == NULL) 
    {
        printf("Falha na alocação de memória. Abortando...");
        exit(EXIT_FAILURE);
    }
    return v;
}

long int* increascingOrder(long int n)
{
    long int *v = allocateArray(n);
    for(int i = 0; i < n; i++) v[i] = i;
    return v;
}

long int* randomOrder(long int n)
{
    srand(time(NULL));
    long int *v = allocateArray(n);
    for(int i = 0; i < n; i++) v[i] = rand();
    return v;
}

long int* decreascingOrder(long int n)
{
    long int *v = allocateArray(n);
    for(int i = 0; i < n; i++) v[i] = (n-1) - i;
    return v;
}
