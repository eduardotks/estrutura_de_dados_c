#ifndef TSTACK_H_INCLUDED
#define TSTACK_H_INCLUDED

#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4
#define ERRO -5

#include "aluno.h"
#include "TList.h"


typedef List Stack;

//CREATE AREA
Stack *stack_create();

//INSERT AREA
int stack_push(Stack *st, struct aluno al);

//REMOVE AREA
int stack_pop(Stack *st);

//CONSULT AREA
int stack_top(Stack *st, int pos, struct aluno *al);

//OTHER AREA
int stack_empty(Stack *st);
int stack_size(Stack *st);

//PRINTF AREA
int stack_print(Stack *st);

//FREE AREA
int stack_free(Stack *st);


#endif // TSTACK_H_INCLUDED
