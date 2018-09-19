#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include <string.h>
#include <ctype.h>

// int calc(void) {
//     // Implemente essa funcao para resolver a questao 1.
// }

int my_atoi(char c);

int main() {    
    // Le a entrada e calcula e retorna o resultado.
    Stack* stack = init_stack();
    char c;
    while((c = getc(stdin)) != EOF){
        if(isdigit(c)){
            push(stack, my_atoi(c));
        }
        else
            if(c == '*'){
                int value = pop(stack) * pop(stack);
                push(stack, value);
            }
            if(c == '+'){
                int value = pop(stack) + pop(stack);
                push(stack, value);
            }
    }
    
    // int res = calc();
    // Exibe a saida.
    printf("%d\n", pop(stack));
}

int my_atoi(char c){
	if(c >=48 && c <= 57)
    return c-48;
  return 0;
}