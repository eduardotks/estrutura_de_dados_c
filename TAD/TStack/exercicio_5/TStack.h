#ifndef TSTACK_H_INCLUDED
#define TSTACK_H_INCLUDED

#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4
#define ERRO -5

typedef struct stack Stack;

//CREATE AREA
Stack *stack_create();

//INSERT AREA
int stack_push(Stack *st, char caract);

//REMOVE AREA
char stack_pop(Stack *st);

//OTHER AREA
int stack_top(Stack *st, char *caract);

//FREE AREA
void stack_free(Stack *st);

#endif // TSTACK_H_INCLUDED
