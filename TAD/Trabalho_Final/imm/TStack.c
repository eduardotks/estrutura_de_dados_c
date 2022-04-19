#include "TStack.h"

typedef struct snode Snode;


struct stack
{
    Snode *head;
    int size;
};

struct snode
{
    Snode *next;
    Ponto data;
};

//cria pilha
Stack *stack_create()
{
    Stack *st = NULL;
    st = malloc(sizeof(Stack));
    //verificação
    if(st != NULL)
    {
        st->head = NULL; //set
        st->size = 0;   //set
    }
    return st;
}


int stack_push(Stack *st, Ponto p)
{
    Snode *node = NULL;
    //verificação
    if(st == NULL)
    {
        return 0;
    }
    node = malloc(sizeof(Snode)); //aloca
    //verificação
    if(node == NULL)
    {
        return 0;
    }
    node->data = p;
    node->next = NULL;
    //se inicio
    if(st->size == 0)
    {
        st->head = node;
        st->size++;
        return 1;
    }
    else //outros
    {
        node->next = st->head;
        st->head = node;
        st->size++;
        return 1;
    }
}

//remove
int stack_pop(Stack *st)
{
    Snode *aux = NULL;
    //verificação
    if(st == NULL)
    {
        return 0;
    }
    //verifica tamanho negativo
    if(st->size <= 0)
    {
        return 0;
    }
    //verifica se só 1 elemento
    if(st->size == 1)
    {
        free(st->head);
        st->head = NULL;
        st->size--;
        return 1;
    }
    else //outros
    {
        aux = st->head->next;
        free(st->head);
        st->head = aux;
        st->size--;
        return 1;
    }
}

//consulta
int stack_top(Stack *st, Ponto *p)
{
    //verificação
    if(st == NULL)
    {
        return 0;
    }
    //se 0
    if(st->size == 0)
    {
        return 0;
    }
    *p = st->head->data;
    return 1;
}

//tamanho
int stack_size(Stack *st)
{
    //verificação
    if(st == NULL)
    {
        return -1;
    }
    return st->size;
}

//imprime
int stack_print(Stack *st)
{
    Snode *aux = NULL;
    //verificação
    if(st == NULL)
    {
        return 0;
    }
    //tamanho 0
    if(st->size == 0)
    {
        return 0;
    }
    aux = st->head;
    while(aux != NULL)
    {
        printf("\n************************");
        printf("\nX: %d", aux->data.x);
        printf("\nY: %d", aux->data.y);
        printf("\n************************");
        aux = aux->next;
    }

    return 0;
}

//libera pilha
void stack_free(Stack *st)
{
    Snode *aux = NULL;
    Snode *p = NULL;
    //verifica
    if(st != NULL)
    {
        if(st->size > 0)
        {
            aux = st->head;
            while(aux != NULL)
            {
                p = aux;
                aux = aux->next;
                free(p);
            }
        }
    }

    free(st);
}
