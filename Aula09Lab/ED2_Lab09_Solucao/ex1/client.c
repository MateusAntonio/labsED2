#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"

#define RUNS 10
#define N    1000000 // 10^6

int main(int argc, char *argv[]) {
    srand(time(NULL));

    int sum = 0;
    printf("ITER\tHEIGHT\n");
    for (int run = 0; run < RUNS; run++) {
        printf("%d\t", run);
        BST *t = BST_create();
        for (int i = 0; i < N; i++) {
            int r = rand();
            t = BST_insert(t, r, 0);
        }
        int h = BST_height(t);
        sum += h;
        printf("%d\n", h);
        BST_destroy(t);
    }

    printf("-----------------\n");
    printf("MEAN: %.2f\n", (double) sum / RUNS);
}
