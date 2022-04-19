


#include "TDLinkedList.h"


typedef struct dlnode DLNode;

struct dlnode
{
    struct aluno data;
    DLNode *next;
    DLNode *prev;
};

//struct list
struct DlinkedList
{
    DLNode *begin;
    DLNode *end;
    int size;
};


//CREATE AREA
List* list_create()
{
    List *li;
    li = malloc(sizeof(List));
    if (li != NULL)
    {
        li->begin = NULL;
        li->end = NULL;
        li->size = 0;
    }
    return li;
};

//INSERT AREA
int list_push_front(List *li, struct aluno al)
{
    //verificação de lista
    if (li == NULL)
    {
        return INVALID_NULL_POINTER;
    }

    //alocação de nó
    DLNode *new_node;
    new_node = malloc(sizeof(DLNode));

    //verificação de nó se é válido
    if (new_node == NULL)
    {
        return INVALID_NULL_POINTER;
    }

    new_node->data = al; // node recebe informação
    new_node->prev = NULL; // salva endereço
    new_node->next = li->begin; // salva endereço de begin

    //se lista vazia
    if (li->begin == NULL)
    {
        li->begin = new_node; // begin recebe endereço do  novo nó
        li->end = new_node; //
        li->size = li->size + 1; // incremento
    }
    //
    else
    {
        li->begin->prev = new_node; //insere no começo
        li->begin = new_node; //aponta begin para o novo nó inserido no início
        li->size = li->size + 1; //incremento
    }
    return 0;

}

int list_push_back(List *li, struct aluno al)
{
    //verificação de lista
    if (li == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    //alocação de nó
    DLNode *new_node;
    new_node = malloc(sizeof(DLNode));
    //verificação de alocação
    if (new_node == NULL)
    {
        return INVALID_NULL_POINTER;
    }

    new_node->data = al; //recebe a informação
    new_node->next = NULL; // salva endereço
    new_node->prev = li->end; // salva endereço

    //se vazio
    if (li->begin == NULL)
    {
        li->begin = new_node;  // begin recebe endereço do  novo nó
        li->end = new_node; //
    }
    else
    {
        li->end->next = new_node; //insere no final
        li->end = new_node; //end aponta para novo nó
    }
    li->size = li->size + 1; //incrementa

    return SUCCESS;
}

int list_insert(List *li, int pos, struct aluno al)
{
    //verificação de lista se válida
    if (li == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    //se informação de posição menor que zero ou = 0 ou a posição maior do que o tamanho configurado da lista
    else if ((pos <= 0) || (pos > li->size + 1))
    {
        return OUT_OF_RANGE;
    }
    //se tudo certo, prossegue
    else
    {
        //alocação
        DLNode *new_node;
        new_node = malloc(sizeof(DLNode));
        //verifica alocação
        if (new_node == NULL)
        {
            return OUT_OF_MEMORY;
        }
        //se ok
        else
        {

            new_node->data = al; //recebe informação do nó
            //se tamanho 0
            if (li->size == 0)
            {
                new_node->prev = NULL;
                new_node->next = NULL;

                li->begin = new_node; //begin aponta para o novo nó
                li->end = new_node; //end aponta para novo nó
                li->size = 1; // tamanho agora é 1
            }
            else
            {
                if (pos == 1)
                {
                    // insere na cabeça da lista
                    new_node->prev = NULL; //anterior do no aponta null
                    new_node->next = li->begin; //o next do novo nó recebe endereço de begin
                    li->begin->prev = new_node; //li->begin->prev agora aponta para o novo nó
                    li->begin = new_node;
                    li->size++;
                }
                else
                {
                    if (pos == li->size + 1)
                    {
                        // inserção no final
                        new_node->next = NULL;
                        new_node->prev = li->end;
                        li->end->next = new_node;
                        li->end = new_node;
                        li->size++;
                    }
                    else
                    {
                        // inserção no meio da lista
                        int i = 1;
                        DLNode *aux;
                        aux = li->begin; //armazena ender begin
                        while (i < pos - 1)
                        {
                            aux = aux->next;
                            i++;
                        }
                        new_node->prev = aux;
                        new_node->next = aux->next;
                        new_node->next->prev = new_node;
                        aux->next = new_node;
                        li->size++;
                    }
                }
            }
            return SUCCESS;
        }
    }
}

//REMOVE/ERASE AREA
int list_pop_front(List *li)
{
    //verificação de lista se válida
    if (li == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    //se a lista estiver vazia
    if (li->size == 0)
    {
        return ELEM_NOT_FOUND;
    }
    //se existir 1 elemento
    if (li->size == 1)
    {
        free(li->begin);
        //begin recebe null
        li->begin = NULL;
        //end = null
        li->end = NULL;
        //decrementa tamanho
        li->size = li->size -1;
    }
    else
    {
        DLNode *a;
        a = li->begin; //armazena endereço
        li->begin = a->next;
        free(a);//libera
        li->begin->prev = NULL; //o prev vai apontar null
        li->size = li->size -1; //decrementa
    }

    return SUCCESS;
}

int list_pop_back(List *li)
{
    //verificação
    if(li == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    DLNode *a = NULL;

    //lista vazia? ou tamanho zero?
    if(li->begin == NULL && li->size == 0)
    {
        return INVALID_NULL_POINTER;
    }
    //1 elemento na lista?
    if(li->begin->next == NULL)
    {
        free(li->begin); //libera
        li->begin = NULL; //seta null
        li->end = NULL; //seta null
        li->size--; //decrementa

        return SUCCESS;
    }


    //tendo mais de 1 na lista
    a = li->end;
    li->end = li->end->prev;
    li->end->next = NULL;
    free(a); //libera
    return SUCCESS;
}

int list_erase(List *li, int pos)
{
    //verifica
    if (li == NULL)
    {
        return INVALID_NULL_POINTER;
    }

    //pos menor que zero ou igual? e pos maior que o tamanho da lista
    if ((pos <= 0 ) || (pos > li->size))
    {
        return OUT_OF_RANGE;
    }

    DLNode *a;
    a = li->begin; //armazena

    int i = 1; //começa em 1
    while (i < pos)
    {
        i++;
        a = a->next;
    }

    //para primeiro elemento
    if (a->prev == NULL)
    {
        li->begin = a->next;//begin aponta para o próximo
    }

    //para o último elemento
    if (a->next == NULL)
    {
        li->end = a->prev; //prev aponta para  o anterior
    }
    //
    if (a->next)
    {
        a->next->prev = a->prev;
    }
    if (a->prev)
    {
        a->prev->next = a->next;
    }
    free(a);
    li->size--; //decremento

    return SUCCESS;
}


//GET AREA
int list_find_pos(List *li, int pos, struct aluno *al)
{
    int i = 1; ///inicia em 1
    //verificação
    if(li == NULL)
        return INVALID_NULL_POINTER;
    //verificação
    if(li->size == 0)
        return INVALID_NULL_POINTER;
    //verificação
    if(pos <= 0 || pos > li->size)
        return INVALID_NULL_POINTER;

    DLNode *p = NULL;
    p = li->begin; //armazena

    while (i != pos && p != NULL)
    {
        p = p->next;
        i++;
    }
    //verifica
    if(p == NULL)
        return INVALID_NULL_POINTER;

    *al = p->data;

    printf("A informação do aluno é: ");
    printf("\n********************************************");
    printf("\nMATRÍCULA: %d",p->data.matricula);
    printf("\nNOME: %s",p->data.nome);
    printf("\nNOTAS: (%f | %f | %f)",p->data.n1,p->data.n2,p->data.n3);
    printf("\n********************************************\n");

    return SUCCESS;

}

int list_find_mat(List *li, int nmat, struct aluno *al)
{

    //verificação
    if (li == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    //verificação
    if (li->size == 0)
    {
        return ELEM_NOT_FOUND;
    }

    DLNode *a;
    a = li->begin; //armazena

    while (a!= NULL && a->data.matricula != nmat)
    {
        a = a->next;
    }
    if (a == NULL)
    {
        return ELEM_NOT_FOUND;
    }
    else
    {
        *al = a->data;

        printf("A informação do aluno é: ");
        printf("\n********************************************");
        printf("\nMATRÍCULA: %d",a->data.matricula);
        printf("\nNOME: %s",a->data.nome);
        printf("\nNOTAS: (%f | %f | %f)",a->data.n1,a->data.n2,a->data.n3);
        printf("\n********************************************\n");

    }
    return SUCCESS;
}

int list_front(List *li, struct aluno *al)
{

    //verificação
    if(li == NULL)
        return INVALID_NULL_POINTER;
    //verificação
    if(li->size <= 0)
        return INVALID_NULL_POINTER;

    *al = li->begin->data;
    return SUCCESS;
}

int list_back(List *li, struct aluno *al)
{
    //verificação
    if(li == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    //verificação
    if(li->size <= 0)
    {
        return INVALID_NULL_POINTER;
    }
    *al = li->end ->data;
    return SUCCESS;
}

int list_get_pos(List *li, int nmat, int *pos)
{
    DLNode *a = NULL;
    //verificação
    if(li == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    //verificação
    if(li->size <= 0)
    {
        return INVALID_NULL_POINTER;
    }

    a = li->begin;
    //verificação
    if(a == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    int i = 1;
    while(a->data.matricula != nmat && a != NULL)
    {
        a = a->next;
        i++;
    }

    return i;
}

//PRINT AREA
int list_print_forward(List *li) //begin e next
{
    //verificação de lista
    if(li == NULL)
    {
        return INVALID_NULL_POINTER;
    }

    DLNode *a = li->begin; //salvando o endereço
    while(a != NULL)
    {
        printf("\n********************************************");
        printf("\nMATRÍCULA: %d",a->data.matricula);
        printf("\nNOME: %s",a->data.nome);
        printf("\nNOTAS: (%f | %f | %f)",a->data.n1,a->data.n2,a->data.n3);
        printf("\n********************************************\n");
        a = a->next;
    }
    return SUCCESS;
}

int list_print_reverse(List *li) //end e prev
{
    //verificação de lista
    if(li == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    DLNode *a = li->end;
    while(a != NULL)
    {
        printf("\n********************************************");
        printf("\nMATRÍCULA: %d",a->data.matricula);
        printf("\nNOME: %s",a->data.nome);
        printf("\nNOTAS: (%f | %f | %f)",a->data.n1,a->data.n2,a->data.n3);
        printf("\n********************************************\n");
        a = a->prev;
    }

    return SUCCESS;
}


//FREE AREA
int list_free(List *li)
{
    //verificação
    if (li == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        DLNode *a;
        a = li->begin;//armazena endereço de begin
        while (a != NULL)
        {
            li->begin = a->next;
            free(a); //libera
            a = li->begin;
        }
        free(li);//libera
        return SUCCESS;
    }
}

//SIZE AREA
int list_size(List *li)
{
    //verificação
    if (li == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        return li->size;
    }
}



