#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"

#define RUNS 10
#define N    1000000 // 10^6

int main(int argc, char *argv[]) {
    srand(time(NULL));

    printf("ITER\tUNBALANCED HEIGHT\tBALANCED HEIGHT\n");
    for (int run = 0; run < RUNS; run++) {
        printf("%d\t", run);
        BST *t = BST_create();
        for (int i = 0; i < N; i++) {
            int r = rand();
            t = BST_insert(t, r, 0);
        }
        printf("%d\t\t\t", BST_height(t));
        t = BST_balance(t);
        printf("%d\n", BST_height(t));
        BST_destroy(t);
    }

    printf("-----------------\n");
    printf("BALANCED HEIGHT SHOULD BE: 19\n");
}
