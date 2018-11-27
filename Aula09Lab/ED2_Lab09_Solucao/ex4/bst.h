#ifndef BST_H
#define BST_H

#include "../key.h"

typedef struct node BST;

struct node {
    Key key;
    Value val;
    BST *l, *r;
};

BST* BST_create();
void BST_destroy(BST*);

int BST_height(BST*);

BST* BST_insert(BST*, Key, Value);

Value BST_search(BST**, Key);

#endif
