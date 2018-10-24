#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void sort(Item *a, int lo, int hi);

Item* init_array(int N){
    Item* array = malloc(N * sizeof(Item));
    return array;
}

int main(int argc, char *argv[]){
    int N = atoi(argv[1]);
    Item* array = init_array(N); //passos 1 e 2
    for(int i = 0; i < N; i++) 
        scanf("%d", &array[i]); //passo 3
    
    clock_t begin = clock(); //passo 5.1
    sort(array,0,N); //passo 4
    clock_t final = clock(); //passo 5.2
    double time_spent = (double)(final - begin) / CLOCKS_PER_SEC; //passo 5 final

    for(int j = 0; j < atoi(argv[1]); j++)
        printf("%d\n", array[j]); //passo 6
    
    printf("%f\n", time_spent);

    free(array); //passo 7

    
    return 0;
}