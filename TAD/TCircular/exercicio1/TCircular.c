#include "TCircular.h"

//STRUCT AREA
struct listcircular
{
    ListNode *end;
    int size;
};

struct listnode
{
    Aluno data;
    ListNode* next;
};

//CREATE AREA
ListCircular *list_create()
{
    ListCircular *LiCi = NULL;
    LiCi = malloc(sizeof(ListCircular)); //alocacao
    if(LiCi == NULL) //vericacao
    {
        exit(INVALID_NULL_POINTER);
    }
    else
    {
        LiCi->end = NULL; //set
        LiCi->size = 0; //set
    }

    return LiCi;
}

//INSERT AREA
int list_push_begin(ListCircular *LiCi, Aluno al)
{
    ListNode *ln = NULL;

    if(LiCi == NULL) //verifica se valido
    {
        return INVALID_NULL_POINTER;
    }

    if(LiCi->end == NULL) //se primeiro
    {
        ln = malloc(sizeof(ListNode)); //alocacao
        if(ln == NULL) //verifica
        {
            return INVALID_NULL_POINTER;
        }
        //recebe info
        ln->data = al;
        ln->next = ln;
        LiCi->end = ln;
        //incrementa
        LiCi->size++;
        return SUCCESS;
    }
    else //mais de 1 elemento
    {
        //alocacao
        ln = malloc(sizeof(ListNode));
        //verifica
        if(ln == NULL)
        {
            return INVALID_NULL_POINTER;
        }
        //recebe info
        ln->data = al;
        ln->next = LiCi->end->next;
        LiCi->end->next = ln;
        //incrementa
        LiCi->size++;
        return SUCCESS;
    }
}

int list_push_end(ListCircular *LiCi, Aluno al)
{

    ListNode *ln = NULL;

    if(LiCi == NULL) //se valido
    {
        return INVALID_NULL_POINTER;
    }
    //lista vazia
    if(LiCi->end == NULL)
    {
        //alocacao
        ln = malloc(sizeof(ListNode));
        //verifica alocacao
        if(ln == NULL)
        {
            return INVALID_NULL_POINTER;
        }

        ln->data = al;  // passa valores
        ln->next = ln;  //
        LiCi->end = ln; //
        LiCi->size++;   // incrementa
        return SUCCESS;
    }
    else  //Caso um ou mais elementos
    {
        //alocacao
        ln = malloc(sizeof(ListNode));
        //verifica
        if(ln == NULL)
        {
            return INVALID_NULL_POINTER;
        }

        ln->data = al;
        ln->next = LiCi->end->next;
        LiCi->end->next = ln; //prox de end recebe ln
        LiCi->end = ln; //
        LiCi->size++; //incrementa
        return SUCCESS;
    }


}

int list_push_pos(ListCircular *LiCi, int pos, Aluno al)
{
    ListNode *ln;
    //verifica
    if(LiCi == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    //
    if(pos > LiCi->size+1)
    {
        return INVALID_NULL_POINTER;
    }
    //se tamanho zero e pos diferente de 1
    if(LiCi->size == 0 && pos != 1)
    {
        return INVALID_NULL_POINTER;
    }
    //alocacao
    ln = malloc(sizeof(ListNode));
    if(ln == NULL) //verifica
    {
        return INVALID_NULL_POINTER;
    }
    //recebe valor
    ln->data = al;

    if(LiCi->size == 0)//Caso de lista vazia
    {

        ln->next = ln;
        LiCi->end = ln;
        //incrementa
        LiCi->size++;
        return SUCCESS;
    }
    //se lista com 1 elemento ou mais
    else
    {
        //Inserir na primeira posicao
        if(pos == 1)
        {
            ln->next = LiCi->end->next; //
            LiCi->end->next = ln;
            //incrementa
            LiCi->size++; //increm
            return SUCCESS;
        }
        //se inserir no final
        if(pos == LiCi->size+1)
        {
            ln -> next = LiCi->end->next;
            LiCi->end->next = ln;
            LiCi->end = ln;
            //incrementa
            LiCi->size++;
            return SUCCESS;
        }
        //Caso de inserir em uma pos no meio da lista
        ListNode *aux;// aux node
        ListNode *ant;// ant node
        aux = LiCi->end;

        for(int i = 0; i < pos; i++)
        {
            ant = aux;
            aux = aux->next;
        }
        ln->next = aux;
        ant->next = ln;
        //incrementa
        LiCi->size++;
        return SUCCESS;
    }

}

//REMOVE AREA
int list_remove_begin(ListCircular *LiCi)
{
    ListNode *ln = NULL;
    //incrementa
    if(LiCi == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    //incrementa
    if(LiCi->end == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    //
    if(LiCi->end == LiCi->end->next)
    {
        free(LiCi->end);
        LiCi -> end = NULL;
        LiCi->size--; //decrementa
        return SUCCESS;
    }
    else //se vários elementos
    {
        ln = LiCi->end->next;
        LiCi->end = LiCi->end->next->next;
        free(ln);
        LiCi->size--; //decrementa
        return SUCCESS;
    }
}

int list_remove_end(ListCircular *LiCi)
{
    ListNode *ln = NULL;
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
    //se houver 1 elemento
    if(LiCi->end->next == LiCi->end)
    {
        free(LiCi->end);
        LiCi->end = NULL;
        LiCi->size--; //decrementa
        return SUCCESS;
    }
    //caso contrário se houver muitos elementos
    else
    {
        ln = LiCi->end->next;
        while(ln->next != LiCi->end)
        {
            ln = ln->next;
        }
        aux = LiCi->end;
        ln-> next = aux->next;
        LiCi->end = ln;
        free(aux); //libera aux
        LiCi->size--; //decremento
        return SUCCESS;
    }
}

int list_remove_mat(ListCircular *LiCi, int mat)
{
    ListNode *ln = NULL;
    ListNode *aux = NULL;

    if(LiCi == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    if(LiCi->size < 1)
    {
        return INVALID_NULL_POINTER;
    }
    //se 1 elemento
    if(LiCi->size == 1)
    {
        if(LiCi->end->data.matricula == mat)
        {
            free(LiCi->end); //libera
            LiCi->end = NULL;
            LiCi->size--; //decremento
            return SUCCESS;
        }
        else
        {
            return INVALID_NULL_POINTER;
        }
    }
    //caso muitos na lista
    else
    {

        ln = LiCi->end;

        for(int i = 0; i < LiCi->size+1; i++)
        {
            aux = ln;
            ln = ln->next;

            //elemento na última posição?
            if(ln == LiCi->end && ln->data.matricula == mat)
            {
                aux->next = LiCi->end->next;
                free(LiCi->end);
                LiCi->end = aux;
                LiCi->size--; //decrementa
                return SUCCESS;
            }

            //no meio da lista?

            if(ln->data.matricula == mat)
            {
                aux->next = ln->next;
                free(ln);
                LiCi->size--;
                return SUCCESS;
            }
        }

    }
    return SUCCESS;
}

int list_remove_pos(ListCircular *LiCi, int pos)
{
    ListNode *ln = NULL;
    ListNode *aux = NULL;
    //valida
    if(LiCi == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    //valida
    if(LiCi->size < 1)
    {
        return INVALID_NULL_POINTER;
    }
    //valida
    if(pos > LiCi->size)
    {
        return INVALID_NULL_POINTER;
    }
    //se 1 elemento
    if(LiCi->size == 1 && pos == 1)
    {
        free(LiCi->end);
        LiCi->end = NULL;
        LiCi->size--;
        return SUCCESS;
    }
    //remover da última pos com muitos elementos
    if(pos == LiCi->size)
    {
        ln = LiCi->end;
        for(int i = 0; i < LiCi->size; i++)
        {
            aux = ln;
            ln = ln->next;
        }

        aux->next = LiCi->end->next;
        free(LiCi->end); //libera
        LiCi->end = aux; //armazena
        LiCi->size--; //decrementa
        return SUCCESS;
    }

    //remover primeiro de muitos elementos
    if(pos == 1)
    {
        ln = LiCi->end->next;
        LiCi->end->next = LiCi->end->next->next;
        free(ln); //libera
        LiCi->size--; //decrementa
        return SUCCESS;
    }

    ln = LiCi->end;
    for(int i = 0; i < LiCi->size; i++)
    {
        aux = ln;
        ln = ln->next;
    }

    aux->next = ln->next;
    free(ln); //libera
    LiCi->size--; //decrementa
    return SUCCESS;
}

//PRINT AREA
int list_print(ListCircular *LiCi)
{
    if(LiCi != NULL && LiCi->size > 0)
    {
        ListNode *ln;
        ln = LiCi->end->next;
        for(int i = 1; i <= LiCi->size; i++)
        {
            //mostra informações
            printf("\n**************INFORMAÇÕES*******************");
            printf("\nMATRÍCULA: %d",ln->data.matricula);
            printf("\nNOME: %s",ln->data.nome);
            printf("\nNOTAS: (%f | %f | %f)",ln->data.n1,ln->data.n2,ln->data.n3);
            printf("\n********************************************\n");
            ln = ln->next;
        }
        return SUCCESS;
    }
    else
    {
        return ERRO;
    }
}

//OTHERS
int list_select_begin(ListCircular *LiCi, Aluno *al)
{
    //valida
    if(LiCi == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    //valida
    if(LiCi->size < 1)
    {
        return INVALID_NULL_POINTER;
    }

    *al = LiCi->end->next->data; //get info
    return SUCCESS;
}

int list_select_end(ListCircular *LiCi, Aluno *al)
{
    //valida
    if(LiCi == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    //valida
    if(LiCi->size < 1)
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

int list_select_mat(ListCircular *LiCi, int mat, Aluno *al)
{
    ListNode *ln = NULL;
    //valida
    if(LiCi == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    //valida
    if(LiCi->size < 1)
    {
        return INVALID_NULL_POINTER;
    }
    //ln = end
    ln = LiCi->end;
    for(int i = 0; i < LiCi->size; i++)
    {
        ln = ln->next;
        if(ln->data.matricula == mat)
        {
            *al = ln->data;
            //mostra informações
            printf("\n**************INFORMAÇÕES*******************");
            printf("\nMATRÍCULA: %d",al->matricula);
            printf("\nNOME: %s",al->nome);
            printf("\nNOTAS: (%f | %f | %f)",al->n1,al->n2,al->n3);
            printf("\n********************************************\n");
            return SUCCESS;
        }
    }

    return SUCCESS;
}

int list_select_pos(ListCircular *LiCi, int pos, Aluno *al)
{
    ListNode *ln = NULL;
    //valida
    if(LiCi == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    //valida
    if(LiCi->size < 1)
    {
        return INVALID_NULL_POINTER;
    }
    //valida
    if(pos > LiCi->size)
    {
        return INVALID_NULL_POINTER;
    }

    ln = LiCi->end;
    for(int i = 0; i < pos; i++)
    {
        ln = ln->next;
    }

    *al = ln->data;
    //mostra informações
    printf("\n**************INFORMAÇÕES*******************");
    printf("\nMATRÍCULA: %d",al->matricula);
    printf("\nNOME: %s",al->nome);
    printf("\nNOTAS: (%f | %f | %f)",al->n1,al->n2,al->n3);
    printf("\n********************************************\n");
    return SUCCESS;
}
