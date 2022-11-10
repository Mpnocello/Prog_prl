/*
1)
Faça um programa em MPI que gere a seguinte saída:
"Hello World!" from MPI process 0. We are 4 MPI processes.
"Hello World!" from MPI process 1. We are 4 MPI processes.
"Hello World!" from MPI process 2. We are 4 MPI processes.
"Hello World!" from MPI process 3. We are 4 MPI processes.
*/

#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{

    MPI_Init(NULL, NULL);

    int qtd_processos;
    int id_processo;
    
    MPI_Comm_size(MPI_COMM_WORLD, &qtd_processos);
    MPI_Comm_rank(MPI_COMM_WORLD, &id_processo);

    printf("Hello world! from MPI process %d. We are %d MPI processes\n", id_processo, qtd_processos);

    MPI_Finalize();
    
    return 0;
}