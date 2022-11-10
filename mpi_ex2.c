/*
2)
Este teste é para você praticar o recurso fundamental do MPI: 
enviar uma mensagem. A aplicação que você deve desenvolver é composta por 
2 processos MPI, o primeiro envia uma mensagem e o segundo a recebe. 
A mensagem a enviar é apenas um inteiro com o valor 12345. 
O destinatário deve imprimir o valor recebido. Você é livre para escolher 
o valor da tag que deseja.Saída:
I am process 0, I send value 12345
I am process 1, I received value 12345
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

    if(id == 0)
    {
        valor = 12345;
        MPI_Send(&valor, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        printf("I am process %d, I send value %d\n", id, valor);
    }else{
        MPI_Recv(&valor, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        printf("I am process %d, I received value %d\n", id, valor);
    }

    MPI_Finalize();

    return 0;
}