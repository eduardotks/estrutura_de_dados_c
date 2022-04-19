
#include "TCircular.h"

struct listcircular
{
    ListNode *end;
    ListNode *cur;
    int size;
};

struct listnode
{
    Carro data;
    ListNode* next;
};

//CREATE AREA
ListCircular *list_create()
{
    ListCircular *LiCi;
    LiCi = malloc(sizeof(ListCircular)); //alocação
    if(LiCi == NULL)//se falhou
    {
        exit(INVALID_NULL_POINTER);
    }
    //se criado
    if(LiCi != NULL)
    {
        LiCi->end = NULL; //set
        LiCi->size = 0; //set
    }
    return LiCi;
}

int list_push_begin(ListCircular *LiCi, Carro c)
{
    ListNode *clnode;
    //verificação
    if(LiCi == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    //se end for null lista vazia
    if(LiCi->end == NULL)
    {
        //alocação
        clnode = malloc(sizeof(ListNode));
        //verifica se válido
        if(clnode == NULL)
        {
            return INVALID_NULL_POINTER;
        }

        clnode->data = c; //recebe informação
        clnode->next = clnode; //salva endereço de clnode no próximo elemento
        LiCi->end = clnode; //end recebe o endereço de clnode
        LiCi->size++; //incrementa
        LiCi->cur = LiCi->end;
        return SUCCESS;
    }
    else
    {
        //alocação
        clnode = malloc(sizeof(ListNode));
        //verificacao
        if(clnode == NULL)
        {
            return INVALID_NULL_POINTER;
        }

        clnode->data = c; //recebe informação
        clnode->next = LiCi->end->next; //o próx elemento de END, será o próximo elemento de NODE
        LiCi->end->next = clnode; // O próx elemento de END recebe o nó.
        LiCi->size++; //incrementa
        return SUCCESS;
    }
}


int list_push_end(ListCircular *LiCi, Carro c)
{
    ListNode *clnode;
    //verifica
    if(LiCi == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    //se lista vazia
    if(LiCi->end == NULL)
    {
        clnode = malloc(sizeof(ListNode)); //alocação
        //verificação
        if(clnode == NULL)
        {
            return INVALID_NULL_POINTER;
        }
        clnode->data = c; //recebe info
        clnode->next = clnode;

        LiCi->end = clnode;
        LiCi->size++;
        LiCi->cur = LiCi->end;
        return SUCCESS;
    }
    //se um ou mais elementos
    else
    {
        clnode = malloc(sizeof(ListNode));
        if(clnode == NULL)
        {
            return INVALID_NULL_POINTER;
        }
        clnode->data = c;
        clnode->next = LiCi->end->next;
        LiCi->end->next = clnode;
        LiCi->end = clnode;
        LiCi->size++;
    }
    return SUCCESS;
}


int list_remove_begin(ListCircular *LiCi)
{
    ListNode *clnode = NULL;
    //verifica
    if(LiCi == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    //verifica
    if(LiCi->end == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    //se um elemento
    if(LiCi->end == LiCi->end->next)
    {
        free(LiCi->end); //libera
        LiCi -> end = NULL; //end recebe null
        LiCi->size--; //decremento
        LiCi->cur = NULL; //nó corrente null
        return SUCCESS;
    }
    //se vários
    else
    {

        clnode = LiCi->end->next;
        if(clnode == LiCi->cur) //node == corrent?
        {
            LiCi->cur = clnode->next;
        }

        LiCi->end = LiCi->end->next->next;
        free(clnode); //libera
        LiCi->size--; //decrementa
        return SUCCESS;
    }
}

int list_remove_end(ListCircular *LiCi)
{
    ListNode *clnode = NULL;
    ListNode *aux = NULL;
    //verifica
    if(LiCi == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    //verifica
    if(LiCi->end == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    //Caso um elemento
    if(LiCi->end->next == LiCi->end)
    {
        free(LiCi->end); //libera
        LiCi-> end = NULL; //end null
        LiCi->size--; //decrementa
        LiCi->cur = NULL; //cur null
        return SUCCESS;
    }
    //se vários
    else
    {
        clnode = LiCi->end->next;
        while(clnode->next != LiCi->end) //próximo elemento diferente do end de final
        {
            clnode = clnode->next;
        }
        aux = LiCi->end; //salva end
        clnode-> next = aux->next; //node next recebe próx elm do aux
        LiCi->end = clnode;

        free(aux);
        LiCi->size--; //decremente
        return SUCCESS;
    }
}

int list_data(ListCircular *cL, Carro *c)
{
    //verificação
    if(cL == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    //verificação
    if(cL->size < 1)
    {
        return OUT_OF_RANGE;
    }

    *c = cL->cur->data; //c recebe a informação corrente
    return SUCCESS;
}


void list_print(ListCircular *LiCi)
{
    if(LiCi != NULL && LiCi->size > 0)
    {
        ListNode *clnode = NULL;
        clnode = LiCi->end->next;
        for(int i = 1; i <= LiCi->size; i++)
        {
            //mostra informações
            printf("\n**************INFORMAÇÕES*******************");
            printf("\nMarca: %s", clnode->data.marca);
            printf("\nModelo: %s", clnode->data.modelo);
            printf("\n********************************************\n");

            clnode = clnode->next;
        }
    }
}
