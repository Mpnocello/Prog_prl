#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#include <string.h>

int main()
{
    omp_set_num_threads(3);

    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        printf("Meu ID: %d \n", id);

        #pragma omp sections
        {
           #pragma omp section
           {
                printf("Primeiro ID: %d\n", id);
                for(int i = 2; i<=10;i+=2){
                    printf("Par: %d\n", i);
                }
           }

          #pragma omp section
           {
                printf("Segundo ID: %d\n", id);
                for(int i = 1; i<=10;i+=2){
                    printf("Impar: %d\n", i);
                }  
           }

           #pragma omp section
           {
                printf("Terceiro ID: %d\n", id);

                printf("Primo: 2\n");

                printf("Primo: 3\n");

                printf("Primo: 5\n");

                printf("Primo: 7\n");
           } 
        }
    }

    printf("\n");
    return 0;
}