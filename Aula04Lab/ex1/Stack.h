#ifndef stack_EX1
#define stack_EX1

typedef struct stack Stack;
Stack* init_stack();
Stack* push(Stack* stack, int value);
int pop(Stack* stack);

#endif //stack_EX1

