#include "TCircular.h"
//STRUCT 1
struct listcircular
{
    ListNode *end;
    ListNode *cur;
};
//STRUCT 2
struct listnode
{
    Aluno data;
    ListNode* next;
};

//CREATE AREA
ListCircular *list_create()
{
    ListCircular *LiCi;
    //alocacao
    LiCi = malloc(sizeof(ListCircular));
    //verifica
    if(LiCi == NULL)
    {
        exit(INVALID_NULL_POINTER);
    }
    if(LiCi != NULL)
    {
        LiCi->end = NULL; //set
        LiCi->cur = NULL; //set
    }
    return LiCi;
}

//INSERT AREA
int list_push_begin(ListCircular *LiCi, Aluno al)
{
    ListNode *clnode;
    //verifica
    if(LiCi == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    //lista vazia?
    if(LiCi->end == NULL)
    {
        //aloca
        clnode = malloc(sizeof(ListNode));
        //verifica
        if(clnode == NULL)
        {
            return INVALID_NULL_POINTER;
        }
        //passa informacao
        clnode->data = al;
        clnode->next = clnode; //prox elem é o novo node
        LiCi->end = clnode; //end vai estar no novo node
        LiCi->cur = LiCi->end->next; //
        return SUCCESS;
    }
    else
    {
        //alocacao
        clnode = malloc(sizeof(ListNode));
        //Verifica
        if(clnode == NULL)
        {
            return INVALID_NULL_POINTER;
        }

        clnode->data = al; //recebe informação
        clnode->next = LiCi->end->next;
        LiCi->end->next = clnode;
        LiCi->cur = LiCi->end->next;
        return SUCCESS;

    }
}

int list_push_end(ListCircular *LiCi, Aluno al)
{
    ListNode *clnode = NULL;
    //verifica
    if(LiCi == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    //lista vazia?
    if(LiCi->end == NULL)
    {
        //aloca
        clnode = malloc(sizeof(ListNode));
        //verifica
        if(clnode == NULL)
        {
            return INVALID_NULL_POINTER;
        }

        clnode->data = al; //recebe info
        clnode->next = clnode;

        LiCi->end = clnode;
        LiCi->cur = LiCi->end->next;
        return SUCCESS;
    }
    //se mais elementos
    else
    {
        //aloca
        clnode = malloc(sizeof(ListNode));
        if(clnode == NULL)
        {
            return INVALID_NULL_POINTER;
        }
        clnode->data = al; //recebe info
        clnode->next = LiCi->end->next;
        LiCi->end->next = clnode;
        LiCi->end = clnode;
        LiCi->cur = LiCi->end->next;
    }
    return SUCCESS;
}

//REMOVE AREA
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
    //se 1 elemento
    if(LiCi->end == LiCi->end->next)
    {
        free(LiCi->end); //libera end
        LiCi -> end = NULL; //end recebe null
        LiCi->cur = LiCi->end->next;
        return SUCCESS;
    }
    //varios elementos
    else
    {
        clnode = LiCi->end->next;
        LiCi->end = LiCi->end->next->next;
        free(clnode); //libera
        LiCi->cur = LiCi->end->next;
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
    //verifca
    if(LiCi->end == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    //se for 1 elemento
    if(LiCi->end->next == LiCi->end)
    {
        free(LiCi->end);
        LiCi-> end = NULL; //set
        LiCi->cur = LiCi->end->next;
        return SUCCESS;
    }
    //vários elementos
    else
    {
        clnode = LiCi->end->next;
        while(clnode->next != LiCi->end)
        {
            clnode = clnode->next;
        }
        aux = LiCi->end;
        clnode-> next = aux->next;
        LiCi->end = clnode;
        free(aux);
        LiCi->cur = LiCi->end->next;
        return SUCCESS;
    }

}

//PRINT AREA

int list_select_begin(ListCircular *LiCi, Aluno *al)
{
    //valida
    if(LiCi == NULL)
    {
        return INVALID_NULL_POINTER;
    }

    *al = LiCi->end->next->data;
    //mostra informações
    printf("\n**************INFORMAÇÕES*******************");
    printf("\nMATRÍCULA: %d",al->matricula);
    printf("\nNOME: %s",al->nome);
    printf("\nNOTAS: (%f | %f | %f)",al->n1,al->n2,al->n3);
    printf("\n********************************************\n");
    return SUCCESS;

}

int list_select_end(ListCircular *LiCi, Aluno *al)
{
    //valida
    if(LiCi == NULL)
    {
        return INVALID_NULL_POINTER;
    }

    *al = LiCi->end->data; //get info
    //mostra informações
    printf("\n**************INFORMAÇÕES*******************");
    printf("\nMATRÍCULA: %d",al->matricula);
    printf("\nNOME: %s",al->nome);
    printf("\nNOTAS: (%f | %f | %f)",al->n1,al->n2,al->n3);
    printf("\n********************************************\n");
    return SUCCESS;
}

ListNode *list_select_next(ListCircular *LiCi, Aluno *al)
{
    //verifica
    if(LiCi == NULL)
    {
        exit(INVALID_NULL_POINTER);
    }
    //verifica
    if(LiCi->end == NULL)
    {
        exit(INVALID_NULL_POINTER);
    }
    //verifica
    if(LiCi->cur == NULL)
    {
        exit(INVALID_NULL_POINTER);
    }

    *al = LiCi->cur->data; // info
    LiCi->cur = LiCi->cur->next;

    printf("\n**************INFORMAÇÕES*******************");
    printf("\nMATRÍCULA: %d",al->matricula);
    printf("\nNOME: %s",al->nome);
    printf("\nNOTAS: (%f | %f | %f)",al->n1,al->n2,al->n3);
    printf("\n********************************************\n");
    return SUCCESS;
}

int list_free(ListCircular *cl)
{
    if(cl!= NULL && cl->cur!= NULL) //conteúdo válido?
    {
        ListNode *aux;
        ListNode *node;
        while((cl->cur) != node->next)
        {
            aux = node;
            node = node->next; //avanca
            free(aux); //libera aux

        }
        free(node); //libera nó
        free(cl); //libera lista
    }
    return SUCCESS;
}

