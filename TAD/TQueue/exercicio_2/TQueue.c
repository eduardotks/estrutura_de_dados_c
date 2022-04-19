#include "TQueue.h"

struct queue
{
    Node *begin;
    Node *end;
    int size;
};

struct node
{
    Aluno data;
    Node *next;
};

//CREATE AREA
Queue *queue_create()
{
    Queue *qu = NULL;
    //aloca��o
    qu = malloc(sizeof(Queue));
    if(qu != NULL)//se aloca��o v�lida
    {
        qu->begin = NULL;//set null
        qu->end = NULL;//set null
        qu->size = 0;//set 0
    }
    return qu;
}

//INSERT AREA
int queue_push(Queue *qu, Aluno al)
{

    if(qu == NULL)//verifica��o
    {
        return INVALID_NULL_POINTER;
    }
    Node *a;
    if(qu->size == 0 && qu->begin == NULL)//se nula ou size 0
    {
        a = malloc(sizeof(Node));//aloca��o
        if(a == NULL)//verifica��o
        {
            return INVALID_NULL_POINTER;
        }
        a->data = al;
        a->next = NULL;

        qu->begin = a;
        qu->end = a;
        qu->size++;
        return SUCCESS;
    }
    else//caso contr�rio
    {
        a = malloc(sizeof(Node));//aloca��o
        if(a == NULL)//verifica��o
        {
            return INVALID_NULL_POINTER;
        }
        a->data = al;
        a->next = NULL;

        qu->end->next = a;
        qu->end = a;
        qu->size++;
        return SUCCESS;
    }
}

//REMOVE AREA
int queue_pop(Queue *qu)
{
    Node *a;

    if(qu == NULL)//verifica��o
    {
        return INVALID_NULL_POINTER;
    }
    if(qu->size <=0 || qu->begin == NULL)// se zero ou menor ou begin nulo.
    {
        return ELEM_NOT_FOUND;
    }
    if(qu->size == 1) //se o tamanho 1
    {
        a = qu->begin;
        qu->begin = NULL;
        qu->end = NULL;
        qu->size--; //decrementa tamanho
        free(a);
        return SUCCESS;
    }
    else
    {
        a = qu->begin;
        qu->begin = qu->begin->next;
        free(a);
        qu->size--;//decrementa tamanho
        return SUCCESS;
    }
}

//FIND AREA
int queue_front(Queue *qu, Aluno *al)
{
    if(qu == NULL) // se v�lido
    {
        return INVALID_NULL_POINTER;
    }
    if(qu->size == 0 || qu->begin == NULL) //tamanho zero ou begin null
    {
        return ELEM_NOT_FOUND;
    }

    *al = qu->begin->data;
    //�qrea para mostrar resultado que est� em primeiro lugar
    printf("\n**************INFORMA��ES*******************");
    printf("\nMATR�CULA: %d",al->matricula);
    printf("\nNOME: %s",al->nome);
    printf("\nNOTAS: (%f | %f | %f)",al->n1,al->n2,al->n3);
    printf("\n********************************************\n");

    return SUCCESS;
}

//SIZE AREA
int queue_size(Queue *qu)
{
    if(qu != NULL) //se diferente mostra tamanho.
    {
        return qu->size;
    }
    else
    {
        return ERRO;
    }
}

//OTHERS AREA
int queue_empty(Queue *qu)
{   //verifica
    if(qu == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    //se zero ent�o vazio
    if(qu->size == 0)
    {
        return SUCCESS;
    }
    else
    {
        return ERRO;
    }
}

int queue_full(Queue *qu)
{   //verifica
    if(qu == NULL)
    {
        return INVALID_NULL_POINTER;
    }

    return SUCCESS;
}

//FREE AREA
int queue_free(Queue *qu)
{
    //verifica��o
    if(qu == NULL)
    {
        return INVALID_NULL_POINTER;
    }

    while(qu->size > 0)
    {
        queue_pop(qu);
    }

    free(qu);//libera
    return SUCCESS;
}
