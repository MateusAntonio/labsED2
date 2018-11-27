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

static BST* rotate_right(BST *n) {
    BST *t = n->l;
    n->l = t->r;
    t->r = n;
    return t;
}

static BST* rotate_left(BST *n) {
    BST *t = n->r;
    n->r = t->l;
    t->l = n;
    return t;
}

// Splay tree function. Splay key in the tree rooted at n. If a node with
// that key exists, it is splayed to the root of the tree. If it does not,
// the last node along the search path for the key is splayed to the root.
static BST* splay(BST* n, Key key) {
    if (n == NULL) {
        return NULL;
    }

    int cmp1 = compare(key, n->key);

    if (cmp1 < 0) {
        // Key not in tree, so we are done.
        if (n->l == NULL) {
            return n;
        }
        int cmp2 = compare(key, n->l->key);
        if (cmp2 < 0) {
            n->l->l = splay(n->l->l, key);
            n = rotate_right(n);
        } else if (cmp2 > 0) {
            n->l->r = splay(n->l->r, key);
            if (n->l->r != NULL) {
                n->l = rotate_left(n->l);
            }
        }

        if (n->l == NULL) {
            return n;
        } else {
            return rotate_right(n);
        }

    } else if (cmp1 > 0) {
        // Key not in tree, so we are done.
        if (n->r == NULL) {
            return n;
        }

        int cmp2 = compare(key, n->r->key);
        if (cmp2 < 0) {
            n->r->l = splay(n->r->l, key);
            if (n->r->l != NULL) {
                n->r = rotate_right(n->r);
            }
        } else if (cmp2 > 0) {
            n->r->r = splay(n->r->r, key);
            n = rotate_left(n);
        }

        if (n->r == NULL) {
            return n;
        } else {
            return rotate_left(n);
        }
    }

    else /*cmp == 0*/ {
        return n;
    }
}

// Node n should always be root.
BST* BST_insert(BST* n, Key key, Value val) {
    // Splay key to root.
    if (n == NULL) {
        return create_node(key, val);
    }

    n = splay(n, key);

    // Insert new node at root.
    int cmp = compare(key, n->key);
    if (cmp < 0) {
        BST *t = create_node(key, val);
        t->l = n->l;
        t->r = n;
        n->l = NULL;
        return t;
    } else if (cmp > 0) {
        BST *t = create_node(key, val);
        t->r = n->r;
        t->l = n;
        n->r = NULL;
        return t;
    } else {
        // Duplicate key.
        n->val = val;
        return n;
    }
}

// Modifies the root and returns the search result.
Value BST_search(BST** root, Key key) {
    *root = splay(*root, key);
    BST *n = *root;
    if (compare(key, n->key) == 0) {
        return n->val;
    } else {
        return NULL_Value;
    }
}
