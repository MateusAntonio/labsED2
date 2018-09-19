#include <stdlib.h>
#include "Stack.h"

struct stack{
    int values[50];
    int top;
};

Stack* init_stack(){
    Stack* stack = malloc(sizeof(stack));
    stack->top = 0;
    return stack;
}

Stack* push(Stack* stack, int value){
    stack->values[stack->top++] = value;
    return stack;
}

int pop(Stack* stack){
    return stack->values[--stack->top];
}
