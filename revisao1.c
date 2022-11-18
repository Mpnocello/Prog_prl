/*
1)
    a)Leia um valoor x do usuário no rank 0;
    b)Dissemine seu conteúdo para todos os processos;
    c)Em cada processo calcule y = id_processos * x recebido do rank 0;
        c.1) sincronize os processos;
    d)Sumarize os valores calculados em todos os processos,no processo 0;
*/

#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{

    MPI_Init(NULL, NULL);

    int qtd_processos;
    int id_processo;
    int x, y;
    int * recvbuf;
    
    MPI_Comm_size(MPI_COMM_WORLD, &qtd_processos);
    MPI_Comm_rank(MPI_COMM_WORLD, &id_processo);

    if(id_processo == 0){
        scanf("%d", &x);
    }

    recvbuf = malloc(sizeof(int) * qtd_processos);

    MPI_Bcast(&x, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if(id_processo != 0){
        y = x * id_processo;
    }

    MPI_Barrier(MPI_COMM_WORLD);

    MPI_Gather(&y, 1, MPI_INT, recvbuf, 1, MPI_INT, 0, MPI_COMM_WORLD);
    
    if(id_processo == 0){
        for(int i = 1; i < qtd_processos; i++){
            printf("ID: %d -> %d\n",i , recvbuf[i]);
        }
    }

    MPI_Finalize();
    
    return 0;
}
