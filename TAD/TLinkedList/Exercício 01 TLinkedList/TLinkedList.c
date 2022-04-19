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
int list_push_front(List *li, struct aluno al) //Insere no in�cio.
{
    //verifica se a lista � v�lida
    if(li == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    //alocar um n�
    List_node *new_node;
    new_node = (List_node*) malloc(sizeof(struct list_node));

    /*//verifica��o
    if(li->head == NULL)
    {
        return INVALID_NULL_POINTER;
    }*/
    if(new_node == NULL)
    {
        return OUT_OF_MEMORY;
    }

    new_node->data = al;

    new_node->next = li->head;
    li->head = new_node;
    return SUCCESS;
}

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

    return SUCCESS;
}

int list_insert_sorted(List *li, struct aluno al)
{
    if (li == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        List_node *new_node;
        new_node = malloc(sizeof(List_node));
        if (new_node == NULL)
        {
            return OUT_OF_MEMORY;
        }
        else
        {
            new_node->data = al;
            // teste se a lista est� vazia
            if (li->head == NULL)
            {
                //o novo n� aponta para null
                new_node->next = NULL;
                //cabe�a aponta para o novo n�
                li->head = new_node;
            }
            else
            {
                //lista com pelo menos 1 elemento
                List_node *aux, *previous;
                aux = li->head;
                while (aux != NULL &&  aux->data.matricula < al.matricula )
                {
                    previous = aux;
                    aux = aux->next;
                }
                // verifica se a inser��o � no in�cio da lista
                if (aux == li->head)
                {
                    new_node->next = li->head;
                    li->head = new_node;
                }
                else
                {
                    // inser��o em uma posi��o diferente do in�cio da lista
                    previous->next = new_node;
                    new_node->next = aux;
                }
            }
            return SUCCESS;
        }
    }
}

int list_insert(List *li, int pos, struct aluno al) //insere pela posi��o informada
{
    int i = 1;

    if(li == NULL)
    {
        return INVALID_NULL_POINTER;
    }

    List_node *a;
    a = malloc(sizeof(List_node));

    if(a == NULL)
    {
        return OUT_OF_MEMORY;
    }

    a->data = al ;
    a->next = NULL;

    //se lista vazia
    if(li->head == NULL)
    {
        if(pos == 1)
        {
            li->head = a;
            return SUCCESS;
        }
        else
        {
            return ELEM_NOT_FOUND;
        }
    }

    //se primeiro elemento
    if(pos == 1)
    {
        a->next = li->head;
        li->head = a;
        return SUCCESS;
    }

    List_node *aux = NULL;
    List_node *ant = NULL;

    aux = li->head;
    while(aux != NULL && i < pos)
    {
        ant = aux;
        aux = aux->next;
        i++;
    }

    //
    if(aux == NULL && pos == i)
    {
        ant->next = a;
        return SUCCESS;
    }

    //
    if(aux == NULL && pos > i)
        return OUT_OF_RANGE;

    //se estiver entre
    ant->next = a;
    a->next = aux;
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
        return INVALID_NULL_POINTER;

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
int list_print(List *li)
{
    if(li == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    List_node *aux = li->head;
    printf("\n\nLista: ");
    //int a = 0;
    while(aux != NULL)
    {
        printf("\n********************************************");
        printf("\nMATR�CULA: %d",aux->data.matricula);
        printf("\nNOME: %s",aux->data.nome);
        printf("\nNOTAS: (%f | %f | %f)",aux->data.n1,aux->data.n2,aux->data.n3);
        printf("\n********************************************\n");
        aux = aux->next;
    }
    return SUCCESS;
}

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
    return SUCCESS;
}

int list_find_mat(List *li, int mat, struct aluno *al) //listar por matr�cula
{
    List_node *p = NULL;
    p = li ->head;

    if(p == NULL)
        return INVALID_NULL_POINTER;

    while(p ->data.matricula != mat && p != NULL)
    {
        p = p ->next;
    }

    if(p == NULL)
        return INVALID_NULL_POINTER;

    *al = p->data;
    return SUCCESS;
}

//-----------------------------------------------------------------------------
//REMOVE AREA
int list_pop_front(List *li) //remove do in�cio
{
    //verifica lista
    if(li == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    //N�o faz sentido remover se est� vazia, portanto:
    if(li->head == NULL)
    {
        return ELEM_NOT_FOUND;
    }
    //aux recebe head, pois � necess�rio guardar o endere�o da mem�ria;
    List_node *aux = li->head;
    //ap�s ter salvo o endere�o de head em aux, devemos apontar para o pr�ximo n�, portanto:
    li->head = aux->next;
    //libero aux;
    free(aux);

    return SUCCESS;

}

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

int list_erase(List *li, int pos)
{
    //Verifica��es
    if(li == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    //negativos
    if(pos < 0)
    {
        return OUT_OF_RANGE;
    }
    //sem elemento na lista
    if(li->head == NULL)
    {
        return ELEM_NOT_FOUND;
    }
    List_node *aux;

    //-----------------
    //Remove na head
    if(pos == 0)
    {   //armazeno no auxiliar
        aux = li->head;
        //passa para o pr�ximo elemento
        li->head = li->head->next;
        //libero aux
        free(aux);
        return 0;
    }
    //-----------------
    //Remo��o em qualquer lugar

    //usando vari�veis para armazenar os endere�os.
    List_node *ant = NULL;
    //n� atual recebe head
    aux = li->head;
    int i = 0;
    //enquanto n�o chegar em nulo e na posi��o digitada, faz:
    while(aux != NULL && i != pos)
    {
        ant = aux; //ant = NULL
        aux = aux->next; // li->head aponta para pr�ximo node
        i++;
    }

    //Se n�o encontrar a posi��o(digitando um valor maior por exemplo)
    if(aux == NULL)
    {
        return OUT_OF_RANGE;
    }
    else
    {
        //O anterior aponta pra null e remove o �ltimo elemento.
        ant->next = aux->next;
        free(aux);
        return SUCCESS;
    }
    return SUCCESS;
}

int list_get_pos(List *li, int nmat, int *pos)  // lista_pegar_pos
{
    if(li == NULL)
    {
        return INVALID_NULL_POINTER;
    }

    List_node *aux = li->head;
    int i = 0;
    printf("\n");

    while(aux != NULL)
    {

        if(aux->data.matricula == nmat)
        {
            printf("Encontrado!!!\n");
            printf("Posi��o: %d, Matr�cula: %d\n", i, aux->data.matricula);
            *pos = i;
            break;
            return SUCCESS;
        }
        i++;
        aux = aux->next;
    }
    printf("N�o encontrei!!!");

    if(aux == NULL)
    {
        *pos = INVALID_NULL_POINTER;
        return ELEM_NOT_FOUND;
    }
    return 0;
}
