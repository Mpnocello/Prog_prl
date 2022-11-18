/*
    Implemente o calculo de PI utilizando MPI
*/


#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

static long num_steps = 1000000;

int main()
{

    MPI_Init(NULL,NULL);

    int qtd_processos;
    int id_processo;
    int i;
    double x;
    double sum = 0;
    double soma = 0;
    double step;

    MPI_Comm_size(MPI_COMM_WORLD, &qtd_processos);
    MPI_Comm_rank(MPI_COMM_WORLD, &id_processo); 

    step  = 1.0/(double)num_steps;

    for(i = id_processo, sum = 0.0; i < num_steps; i+=qtd_processos){

        x = (i+0.5) * step;
        sum= sum + 4.0/(1.0 + x * x);
    }

    MPI_Reduce(&sum, &soma, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if(id_processo == 0){
        printf("pi = %lf\n", soma *step);
    }

    MPI_Finalize();

    return 0;
}