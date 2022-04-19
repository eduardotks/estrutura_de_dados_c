#include <stdlib.h>
#include <stdio.h>
#include "TQueue.h"
#include "TLinkedList.h"

typedef struct queue
{
    List *data;
} Queue;

//CREATE AREA
Queue* queue_create()
{
    Queue *tmp;
    tmp = malloc(sizeof(Queue)); //alocação
    if(tmp == NULL)//verificação
    {
        exit(INVALID_NULL_POINTER);
    }
    else
    {
        tmp->data = list_create();//  usando create tlinkedlist
        if(tmp->data == NULL)
        {
            free(tmp); //limpa
            exit(INVALID_NULL_POINTER);
        }
    }

    return tmp;
}

//INSERT AREA
int queue_push(Queue *tmp, Aluno al)
{
    int i = list_push_back(tmp->data, al); //usando tlinked push
    return i;
}

//REMOVE AREA
int queue_pop(Queue *tmp)
{
    int i = list_pop_back(tmp->data); //usando tlinked pop
    return i;
}

//FIND elemento 1º POSITION
int queue_front(Queue *tmp, Aluno *al)
{
    int a;

    a = list_find_pos(tmp->data, 1, al); //usando find pos tlinked

    return a;
}

//SIZE AREA
int queue_size(Queue *tmp)
{
    int i = list_size(tmp->data); //usando size tlinked
    return i;
}

//OTHERS AREA
int queue_empty(Queue *tmp)
{
    if(tmp == NULL || (tmp->data) == NULL)
    {
        return SUCCESS;
    }
    else
    {
        return ERRO;
    }
}

int queue_full(Queue *tmp)
{
    return SUCCESS;
}

//FREE AREA
int queue_free(Queue *tmp)
{
    if(tmp->data  != NULL)
    {
        list_free(tmp->data); //usando free
        return SUCCESS;
    }
    else
    {
        return ERRO;
    }
}
