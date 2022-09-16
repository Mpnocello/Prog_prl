#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#include <string.h>

int main()
{
    int n;

    printf("\nN: ");
    scanf("%d", &n);

    omp_set_num_threads(n);

    #pragma omp parallel
    {
        int id = omp_get_thread_num();

        #pragma omp single
        {
            printf("Iniciando Mundo Paralelo: thread %d", id);
        }

        printf("\nEu sou a thread %d",id);


        #pragma omp barrier
        #pragma omp master
        {
            printf("\nFIM");
        }

    }

    printf("\n");
    return 0;
}