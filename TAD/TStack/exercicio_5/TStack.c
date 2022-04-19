#include <stdlib.h>
#include <stdio.h>

#include "TStack.h"

typedef struct node Node;


struct stack
{
    Node *head;
    int size;
};

struct node
{
    Node *next;
    char character;
};

//CREATE AREA
Stack *stack_create()
{
    Stack *st = NULL;
    st = malloc(sizeof(Stack)); //alocação

    if(st != NULL)//se null seta null e 0
    {
        st->head = NULL;
        st->size = 0;
    }
    return st;
}

//INSERT AREA
int stack_push(Stack *st, char c)
{
    Node *node = NULL;
    //verificação
    if(st == NULL)
    {
        return INVALID_NULL_POINTER;
    }

    node = malloc(sizeof(Node)); //alocação
    //verifica alocação
    if(node == NULL)
    {
        return INVALID_NULL_POINTER;
    }

    node->character = c;
    node->next = NULL;
    //se vazio
    if(st->size == 0)
    {
        st->head = node;
        st->size++;
        return SUCCESS;
    }
    else
    {
        node->next = st->head;
        st->head = node;
        st->size++; //incrementa
        return SUCCESS;
    }
}

//REMOVE AREA
char stack_pop(Stack *st)
{
    Node *aux = NULL;
    char x;

    //verificação
    if(st == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    //se negativo ou 0
    if(st->size <= 0)
    {
        return OUT_OF_RANGE;
    }
    //se 1 elemento
    if(st->size == 1)
    {
        x = st->head->character;
        free(st->head); //libera
        st->head = NULL; //head recebe null
        st->size--; //decrementa
        return x;
    }
    else
    {
        x = st->head->character;
        aux = st->head->next;

        free(st->head); //libera
        st->head = aux;
        st->size--; //decrementa
        return x;
    }
}

//OTHER AREA
int stack_top(Stack *st, char *c)
{
    //verifica se válido
    if(st == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    //se o tamanho for igual a zero
    if(st->size == 0)
    {
        return OUT_OF_RANGE;
    }

    *c = st->head->character;
    return SUCCESS;
}

//FREE AREA
void stack_free(Stack *st)
{
    Node *aux = NULL;
    Node *p = NULL;
    //se não for null
    if(st != NULL)
    {
        //se 1 elemento
        if(st->size == 1)
        {
            free(st->head);
        }
        else//se mais elementos
        {
            aux = st->head;
            while(aux->next != NULL)//percorre
            {
                p = aux;
                aux = aux->next;
                free(p);//libera
            }
        }
    }

    free(st);
}
