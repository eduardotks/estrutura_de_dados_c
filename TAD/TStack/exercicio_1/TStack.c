#include <stdlib.h>
#include <stdio.h>

#include "TStack.h"
#include "TList.h"



//************************************************************

//CREATE AREA
Stack *stack_create(int tamanho)
{
    List *li = NULL;
    li = create_list(tamanho);
    return li;
}

//INSERT AREA
int stack_push(Stack *st, Aluno al)
{
    if(st == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    if(insert_List_final(st, al))
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
    if(remove_List_final(st))
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
    if(consult_List_pos(st, pos, al))
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
    print_List(st);
    return SUCCESS;
}


//OTHER AREA
int stack_empty(Stack *st)
{
    if(empty_List(st))
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
    int i = size_List(st);

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
    if(free_list(st))
    {
        free(st);
        return SUCCESS;
    }
    else
    {
        return ERRO;
    }

}


