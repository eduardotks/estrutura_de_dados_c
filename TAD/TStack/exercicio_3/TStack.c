#include <stdlib.h>
#include <stdio.h>
//------------------
#include "TStack.h"
//------------------
struct stack
{
    Node *head;
    int size;
};

struct node
{
    char charact;
    Node *next;
};

//CREATE AREA
Stack *stack_create()
{
    Stack *st = NULL;           //pnt stack
    st = malloc(sizeof(Stack)); //alocação
    if (st == NULL)             //verificação
    {
        exit(INVALID_NULL_POINTER);
    }

    st->head = NULL;
    st->size = 0;

    return st;
}

//INSERT AREA
int stack_push(Stack *st, char a)
{
    //verificação
    if (st == NULL)
    {
        return ERRO;
    }
    //filtragem de character
    if (a != '[' && a != ']' && a != '(' && a != ')')
    {
        return ERRO;
    }

    Node *new_node = NULL;
    new_node = malloc(sizeof(Node)); //alocação
    if (new_node == NULL)            //verifica alocação
    {
        return INVALID_NULL_POINTER;
    }

    new_node->charact = a;
    new_node->next = NULL;

    //para inserir primeiro elemento
    if (st->head == NULL)
    {
        st->head = new_node;
        st->size++; //incrementa
        return SUCCESS;
    }

    Node *aux;
    aux = st->head; //armazena
    while (aux->next != NULL) //percorre
    {
        aux = aux->next;
    }
    aux->next = new_node;
    st->size++; //incrementa
    return SUCCESS;
}

//REMOVE AREA
int stack_pop(Stack *st)
{
    //verificação
    if (st == NULL)
    {
        return ERRO;
    }
    //se tamanho negativo ou 0
    if (st->size <= 0)
    {
        return ERRO;
    }
    //1 elemento
    if (st->size == 1)
    {
        //remove e aponta head null
        free(st->head);
        st->head = NULL;
        st->size--; //decrementa
        return SUCCESS;
    }
    else //mais de 1 elemento
    {
        Node *aux = NULL;
        aux = st->head; //armazena endereço de head
        while (aux->next->next != NULL) //percorre
        {
            aux = aux->next;
        }
        free(aux->next); //libera
        aux->next = NULL;
        st->size--; //decrementa
        return SUCCESS;
    }
}

//GET AREA
int stack_top(Stack *st, char *a)
{
    //validação
    if (st == NULL)
    {
        return ERRO;
    }
    //se 0 ou menor que zero
    if (st->size <= 0)
        return ERRO;

    Node *aux = NULL;
    aux = st->head; //armazena

    while (aux->next != NULL)
    {
        aux = aux->next;
    }

    *a = aux->charact;
    return SUCCESS;
}

int stack_size(Stack *st)
{
    //validação
    if (st == NULL)
    {
        return ERRO;
    }
    //tamanho 0 ou menor
    if (st->size < 0)
        return ERRO;

    return st->size; //tamanho
}

//FREE AREA
void stack_free(Stack *st)
{
    //se válido/existente
    if (st != NULL && st->size > 0)
    {
        while (st->size > 0)
        {
            stack_pop(st); //chama função encadeada.
        }

        free(st);
    }
}

/*//PRINTF AREA
int stack_print(Stack *st)
{
    if(st == NULL) // List nula?
        return;
    if(st->size == 0) // quantidade zero?
        printf("\nNada para mostrar!\n");

    int i;
    for(i=0; i<st->size; i++)
    {
        printf("\n********************************************");
        
        printf("\n********************************************\n");
    }
    return SUCCESS;
}*/

