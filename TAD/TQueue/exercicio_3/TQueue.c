
#include "TQueue.h"

struct queue
{
    int front, rear, size, firstS, secS;
    Aluno *data;
};

Queue *queue_create(int tamanhoInicial)
{
    //malloc
    Queue *que = NULL;
    que = malloc(sizeof(Queue));

    if(que != NULL)
    {
        //inicializando atrib.
        que->front = 0;
        que->rear = 0;
        que->size = 0;
        que->firstS = tamanhoInicial;
        que->secS = tamanhoInicial;
        que->data = malloc(tamanhoInicial * sizeof(Aluno));
        if(que->data == NULL)
        {
            free(que);//libera se erro
            que = NULL;
        }
    }
    return que;
}

int queue_front(Queue *que, Aluno *al)
{
    //verificação
    if(que == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    //ver. tamanho 0?
    if(que->size == 0)
    {
        return OUT_OF_RANGE;
    }

    *al = que->data[que->front];
    //mostra informações
    printf("\n**************INFORMAÇÕES*******************");
    printf("\nMATRÍCULA: %d",al->matricula);
    printf("\nNOME: %s",al->nome);
    printf("\nNOTAS: (%f | %f | %f)",al->n1,al->n2,al->n3);
    printf("\n********************************************\n");

    return SUCCESS;
}

int queue_push(Queue *que, Aluno al)
{
    //verificação de pont
    if(que == NULL)
    {
        return INVALID_NULL_POINTER;
    }

    if(que->rear == que->front && que->size>0)//se lista cheia.
    {
        que->data = realloc(que->data, sizeof(Aluno) *(que->size + que->firstS));//realocação do tamanho
        que->rear = que->size; //tam
        que->secS = que->secS + que->firstS;

        for(int i = 0; i < que->front; i++)
        {
            que->data[que->rear] = que->data[i]; //aponta sempre para posição vaga
            que->rear = (que->rear+1) % que->secS; //rear +1 posição , o resto volta para o inicio
        }
    }


    que->data[que->rear] = al; //recebe al
    que->rear = (que->rear+1) % que->secS; //rear +1 posição , o resto volta para o inicio
    que->size++; //incrementa tamanho
    return SUCCESS;
}


int queue_pop(Queue *que)
{
    //verificação
    if(que == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    //verificação
    if(que->size < 1)
    {
        return OUT_OF_RANGE;
    }

    que->front = (que->front+1) % que->secS; //desloca uma posição para frente, se a pos for final
    //e for a última, o resto da divisão da ult pos == zero, então, volta para o início.
    que->size--;//decrementa
    return SUCCESS;
}

int queue_size(Queue *que)
{
    ////verificação
    if(que == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    //retorna tamanho
    return que->size;
}

int queue_empty(Queue *que)
{
    //verificação
    if(que == NULL)
    {
        return INVALID_NULL_POINTER;
    }

    if(que->size == 0) //se tamanho 0 então vazia
    {
        return SUCCESS;
    }
    else
    {
        return OUT_OF_RANGE;
    }
}

int queue_full(Queue *que)
{
    //verificação
    if(que == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    if(que->size != 0) //se diferente de zero significa que está cheia
    {
        return SUCCESS;
    }
    else
    {
        return OUT_OF_RANGE;
    }
}

int compactar_lista(Queue *que)
{
    //verificação
    if(que == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    //tamanho "size" menor que tamanho atual menos tamanho inicial
    if(que->size < que->secS - que->firstS)
    {
        que = realloc(que, que->secS - que->firstS); //call realloc
        que->secS = que->secS - que->firstS; //tamanho atual é o atual menos o inicial
        {
            return SUCCESS;
        }
    }
    else
    {
        return OUT_OF_RANGE;
    }
}

//FREE AREA
int queue_free(Queue *que)
{
    //verificação
    if(que == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    while(que->size > 0)
    {
        queue_pop(que); //call pop
    }

    free(que); //Limpa
    return SUCCESS;
}
