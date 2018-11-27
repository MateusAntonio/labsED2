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

static int size(BST *n) {
    if (n == NULL) {
        return 0;
    }
    else {
        return n->size;
    }
}

static BST* create_node(Key key, Value val, int size) {
    BST *n = malloc(sizeof *n);
    n->key = key;
    n->val = val;
    n->l = n->r = NULL;
    n->size = size;
    return n;
}

static void fix_size(BST *n) {
    if (n == NULL) {
        return;
    }
    n->size = 1 + size(n->l) + size(n->r);
}

static BST* rotate_right(BST *n) {
    BST *t = n->l;
    n->l = t->r;
    t->r = n;
    fix_size(n->r);
    fix_size(n);
    return t;
}

static BST* rotate_left(BST *n) {
    BST *t = n->r;
    n->r = t->l;
    t->l = n;
    fix_size(n->l);
    fix_size(n);
    return t;
}

static BST* root_insert(BST *n, Key key, Value val) {
    int cmp = compare(key, n->key);
    if (cmp < 0) {
        n->l = BST_insert(n->l, key, val);
        n = rotate_right(n);
    } else if (cmp > 0) {
        n->r = BST_insert(n->r, key, val);
        n = rotate_left(n);
    } else /*cmp == 0*/ {
        n->val = val;
    }
    fix_size(n);
    return n;
}

BST* BST_insert(BST *n, Key key, Value val) {
    if (n == NULL) {
        return create_node(key, val, 1);
    }

    if (rand() < (RAND_MAX / (n->size + 1)) ) {
        return root_insert(n, key, val);
    }
    int cmp = compare(key, n->key);
    if (cmp < 0) {
        n->l = BST_insert(n->l, key, val);
    } else if (cmp > 0) {
        n->r = BST_insert(n->r, key, val);
    }
    fix_size(n);
    return n;
}
