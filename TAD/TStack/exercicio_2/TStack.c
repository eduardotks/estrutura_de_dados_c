#include <stdlib.h>
#include <stdio.h>

#include "TStack.h"
#include "TLinkedList.h"



//************************************************************

//CREATE AREA
Stack *stack_create(int tamanho)
{
    List *li = NULL;
    li = list_create(tamanho);
    return li;
}

//INSERT AREA
int stack_push(Stack *st, Aluno al)
{
    if(st == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    if(list_push_back(st, al))
    {
        return SUCCESS;
    }
    else
    {
        return ERRO;
    }
}

//REMOVE AREA
int stack_pop(Stack *st)
{
    if(list_pop_back(st))
    {
        return SUCCESS;
    }
    else
    {
        return ERRO;
    }
}

//CONSULT AREA
int stack_top(Stack *st, int pos, Aluno *al)
{
    if(list_find_pos(st, pos, al))
    {
        return SUCCESS;
    }
    else
    {
        return ERRO;
    }
}

//PRINTF AREA
int stack_print(Stack *st)
{
    list_print(st);
    return SUCCESS;
}


//OTHER AREA
int stack_empty(Stack *st)
{
    if(list_empty(st))
    {
        return SUCCESS;
    }
    else
    {
        return ERRO;
    }
}

int stack_size(Stack *st)
{
    int i = list_size(st);

    if(i != -1)
    {
        return i;
    }
    else
    {
        return ERRO;
    }
}

int stack_free(Stack *st)
{
    if(list_free(st))
    {
        return SUCCESS;
    }
    else
    {
        return ERRO;
    }
}


