#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"

#define N    10000 // 10^4
#define M    10

int main(int argc, char *argv[]) {
    printf("I\tBEFORE\tAFTER\n");
    BST *t = BST_create();
    for (int i = 0; i < N; i++) {
        t = BST_insert(t, i, 0);
    }
    for (int i = 0; i < M; i++) {
        printf("%d\t%d", i, BST_height(t));
        BST_search(&t, i);
        printf("\t%d\n", BST_height(t));
    }
    BST_destroy(t);
}
