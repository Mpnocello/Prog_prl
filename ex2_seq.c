// Gere um relatório de performance de uma solução sequencial
// e paralela para o seguinte problema:

// Mostre quais, quantos e o somatório de todos números primos entre 
// 100 e 1000000000


#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#include <string.h>


int primo(int n){

    if(n==1){
        return 0;
    }
    long long int x = 0;

    for(long long int i = 1; i < n; i++){
        if(n % i == 0){
            x++;
        }
    }
    return x == 1;
}

int main()
{
    double tempo_1, tempo_2;

    long long int sum = 0, cont = 0, i;
    long long int INICIO = 100; 
    //long long int LIMITE = 1000000;
    long long int LIMITE = 100000;

    tempo_1 = omp_get_wtime();

    for(i = INICIO; i <= LIMITE; i++){
        if(primo(i)){
            printf("%lld ", i);
            cont++;
            sum+=i;
        }
    }

    tempo_2 = omp_get_wtime();

    printf("\nNumero de primos: %lld", cont);

    printf("\nSoma: %lld", sum);

    printf("\nTempo: %f", tempo_2 - tempo_1);

    printf("\n");
    return 0;
}