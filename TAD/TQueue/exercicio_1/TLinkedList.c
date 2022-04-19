#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "TLinkedList.h"
//c�digo das fun��es
typedef struct list_node List_node;

struct list_node
{
    struct aluno data;
    List_node *next;
    //int data;
};

typedef struct list
{
    List_node *head;
    int size; //para tamanho
} List;

//CREATE AREA
List* list_create()
{
    List *li;
    li = (List*) malloc(sizeof(List));

    if(li != NULL)
    {
        li->head = NULL;//cabe�a recebe null
    }
    return li;
}
//-----------------------------------------------------------------------------
//INSERT AREA

int list_push_back(List *li, struct aluno al) //Insere no final.
{
    if(li == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    //alocar um n�
    List_node *new_node;
    new_node = (List_node*) malloc(sizeof(struct list_node));

    //verifica se alocado.
    if(new_node == NULL)
    {
        return OUT_OF_MEMORY;
    }

    //novo n� recebe valores
    new_node->data = al;
    //novo n� vai apontar pra null
    new_node->next = NULL;
    //Se lista vazia
    if(li->head == NULL)
    {
        //se inicio nulo, o �nicio � o novo n�
        li->head = new_node;
        li->size = 1;
        return SUCCESS;
    }
    //aux recebe head, pois � necess�rio guardar o endere�o da mem�ria;
    List_node* aux = li->head;
    //enquanto pr�ximo n�o �  null
    while(aux->next != NULL)
    {
        aux = aux->next;
    }
    //pr�x elemento � o novo n�.
    aux->next = new_node;
    li->size++;
    return SUCCESS;
}

//-----------------------------------------------------------------------------
//FREE AREA
int list_free(List * li)
{
    //verifica list
    if(li == NULL)
    {
        return INVALID_NULL_POINTER;
    }

    List_node *aux = li->head;
    List_node *aux2 = NULL;

    while(aux != NULL)
    {
        aux2 = aux;
        aux = aux->next;
        free(aux2);
    }
    free(li);

    return SUCCESS;
}

//-----------------------------------------------------------------------------
//SIZE AREA
int list_size(List *li)
{
    List_node * a = NULL;
    int i = 1;

    if(li == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    a = li->head;

    while(a->next != NULL)
    {
        a = a->next;
        i++;
    }
    return i;
}

//-----------------------------------------------------------------------------
//GET AREA

int list_find_pos(List* li, int pos, struct aluno *al) //listar por posi��o
{
    List_node *a = NULL;
    a = li->head;

    if(a == NULL)
        return INVALID_NULL_POINTER;

    for(int i = 0; i < pos-1; i++)
    {
        a = a->next;
    }

    if(a == NULL)
        return INVALID_NULL_POINTER;

    *al = a->data;

    printf("A informa��o do aluno �: ");
    printf("\n********************************************");
    printf("\nMATR�CULA: %d",a->data.matricula);
    printf("\nNOME: %s",a->data.nome);
    printf("\nNOTAS: (%f | %f | %f)",a->data.n1,a->data.n2,a->data.n3);
    printf("\n********************************************\n");
    return SUCCESS;
}


//-----------------------------------------------------------------------------
//REMOVE AREA
int list_pop_back(List *li) //remove do final
{
    //verifica lista alocada
    if(li==NULL)
    {
        return INVALID_NULL_POINTER;
    }
    //verifica se est� vazia
    if(li->head==NULL)
    {
        return ELEM_NOT_FOUND;
    }
    //para 1 elemento apenas, ent�o o end de head e o pr�ximo elemento dele � nulo, ent�o:
    if(li->head->next==NULL)
    {
        //libera head
        free(li->head);
        //head recebe null
        li->head= NULL;
        return SUCCESS;
    }
    //anterior aponta para null
    List_node *ant = NULL;
    //aux aponta para cabe�a
    List_node *aux = li->head;
    //enquanto diferente de nulo, anda na lista.

    while(aux->next != NULL)
    {
        //para garantir que o anterior sempre ficar� 1 posi��o atr�s do n� auxiliar;
        ant = aux;
        aux = aux->next;
    }
    //como foi deletado o next do ant apontar� null
    ant->next = NULL;
    //libera aux;
    free(aux);

    //para 1 n� apenas
    /*
    List_node *aux = li->head;

    while(aux->next->next != NULL)
    {
        aux = aux->next;
    }

    free(aux->next);
    aux->next = NULL;
    */


    return SUCCESS;
}

//OTHERS AREA
int list_empty(List *li)
{
    List_node * a = NULL;
    int i = 1;

    if(li == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    a = li->head;

    while(a->next != NULL)
    {
        a = a->next;
        i++;
    }
    return i;
}

int list_full(List *li)
{
    return SUCCESS;
}


