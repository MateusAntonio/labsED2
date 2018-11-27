#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

BST* BST_create() {
    return NULL;
}

void BST_destroy(BST *n) {
    if (n != NULL) {
        BST_destroy(n->l);
        BST_destroy(n->r);
        free(n);
    }
}

int BST_height(BST *n) {
    if (n == NULL) {
        return -1;
    }
    int lh = BST_height(n->l);
    int rh = BST_height(n->r);
    if (lh > rh) {
        return lh + 1;
    } else {
        return rh + 1;
    }
}

static BST* create_node(Key key, Value val) {
    BST *n = malloc(sizeof *n);
    n->key = key;
    n->val = val;
    n->l = n->r = NULL;
    return n;
}

BST* BST_insert(BST *n, Key key, Value val) {
    if (n == NULL) {
        return create_node(key, val);
    }
    int cmp = compare(key, n->key);
    if (cmp < 0) {
        n->l = BST_insert(n->l, key, val);
    } else if (cmp > 0) {
        n->r = BST_insert(n->r, key, val);
    } else /*cmp == 0*/ {
        n->val = val;
    }
    return n;
}
