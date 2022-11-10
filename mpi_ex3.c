/*
3)
Este teste é uma maneira fácil de usar uma operação coletiva. 
Esta aplicação é composta por 4 processos MPI e consiste no 
processo MPI 1 enviando o valor 12345 para todos os outros processos MPI. 
Para conseguir isso, você não tem permissão para usar envios individuais, 
em vez disso, você deve usar uma operação coletiva.
Saída:
I am process 1 and I broadcast value 12345
(as proximas linhas poderão aparecer em qualquer ordem)
I am process 0 and I received value 12345 via broadcast
I am process 2 and I received value 12345 via broadcast
I am process 3 and I received value 12345 via broadcast
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

    MPI_Status status;

    MPI_Comm_size(MPI_COMM_WORLD, &qtd_process);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);

    if(id == 1)
    {
        valor = 12345;
        
        printf("I am process %d and I broadcast value %d\n", id, valor);
    }

    MPI_Bcast(&valor, 1, MPI_INT, 1, MPI_COMM_WORLD);

    if(id!=1)
    {
        printf("I am process %d and I received value %d via broadcast\n", id, valor);
    }

    MPI_Finalize();

    return 0;
}