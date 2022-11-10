/*
4)
Um coletivo clássico: a redução. Este exercício consiste em escrever 
uma aplicação onde cada processo declara uma variável contendo um 
valor igual ao seu MPI rank vezes 100. Em seguida, todos os processos 
participam de uma operação coletiva calculando a soma de todas essas 
variáveis ​​e armazenando a soma em uma variável mantida no MPI processo 0, 
que o imprime.
Saída:
Value held by MPI process 0: 0.
Value held by MPI process 1: 100.
Value held by MPI process 3: 300.
Value held by MPI process 4: 400.
Value held by MPI process 2: 200.
Total sum reduced at MPI process 0: 1000.
*/

#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    MPI_Init(NULL,NULL);

    int qtd_process;
    int id;
    int valor = 0;
    int soma = 0;

    MPI_Comm_size(MPI_COMM_WORLD, &qtd_process);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);

    valor = id * 100;
    

    printf("Value held by MPI process %d: %d.\n", id, valor);

    if(id==0)
    {
        MPI_Reduce(&valor, &soma, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
        printf("Total sum reduced at MPI process %d: %d.\n", id, soma);

    }else{
        MPI_Reduce(&valor, &soma, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    }


    MPI_Finalize();

    return 0;
}