#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#include <string.h>



int primo ( int x )
{
    int i , j , z ;

    for ( i = 0 ; i < 10000 ; i ++)
    {
        for ( j = 0 ; j < 10000 ; j ++)
        {
            z = 1;
        }
    }
    if (( x == 0 ) || ( x == 1 ))

        return 0 ;

    int div ;

    for ( div = 2 ; div < x ; div ++)
    {
        if ( x % div == 0 )
        {
            return 0 ;
        }
    }
    return 1 ;
}



int main()
{
    double tempo1, tempo2;
    int n;
    printf("Digite o numero N: ");
    scanf("%d",&n);

    int * vetor = malloc(sizeof(int)*n);

    tempo1= omp_get_wtime();

    #pragma omp parallel for
    for(int i = 0; i < n; i++)
    {
        vetor[i] = i + 1;
    }

    int qtd = 0;
    #pragma omp parallel for 
    for(int i = 0; i < n; i++)
    {
        if(primo(vetor[i]))
        {
            qtd++;
        }
    }

    tempo2 = omp_get_wtime();

    printf("Quantidade: %d\n", qtd);
    printf("Tempo %f segundos", tempo2 - tempo1);

    printf("\n");
}