
#include <stdio.h>
#include <stdlib.h>
#include "Point.h"

typedef struct stack Stack;

//stack_create
//Cria e retorna uma pilha
Stack *stack_create();

//stack_free
//Destr�i a pilha passada como par�metro e libera da mem�ria
void stack_free(Stack *st);

//stack_push
//Adiciona um elemento a pilha
int stack_push(Stack *st, Ponto p);

//stack_pop
//Deleta elemento do topo da pilha
int stack_pop(Stack *st);

//stack_top
//Retorna o elemento do topo da pilha
int stack_top(Stack *st, Ponto *p);

//stack_size
//Retorna a quantidade de elementos da pilha
int stack_size(Stack *st);

//stack_print
//imprime elementos da pilha
int stack_print(Stack *st);
