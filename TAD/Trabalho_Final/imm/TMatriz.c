#include "TMatriz.h"

//definicao estrutura
struct matriz
{
    int *dados;
    int nlinhas;
    int ncolunas;
};

//cria matriz // alocacao
Matriz *matriz_create(int nlinha, int ncoluna)
{
    Matriz *n;
    //alocacao
    n = malloc(sizeof(Matriz) );
    //verificacao de alocacao
    if(n == NULL)
    {
        return NULL;
    }
    //se der certo faz alocacao do tamanho da matriz linha x coluna
    else
    {
        n->dados = malloc (nlinha * ncoluna * sizeof(int));
    }
    //verificacao de malloc
    if(n->dados == NULL)
    {
        return NULL;
    }
    else
    {
        n->nlinhas = nlinha; //qtd de linhas
        n->ncolunas = ncoluna; //qtd de colunas
        return n; //matriz
    }
}


int matriz_insert(Matriz *n, int i, int j, int val)
{
    //tendo i como numero de linhas, j como número de colunas
    //verificacao, se não nulo
    if(n != NULL)
    {
        //verifica caso linha e negativo
        if(i > n->nlinhas || i < 0)
        {
            return -1;
        }
        //verifica caso coluna e negativ
        if(j > n->ncolunas || j < 0)
        {
            return -1;
        }

        //insere em uma determinada posição da matriz utilizando o método abaixo.
        n->dados[j * n->nlinhas + i] = val;
        return 1;
    }
    else
    {
        return -1;
    }
}

//
int matriz_select(Matriz *n, int i, int j, int* val)
{
    //verificação
    if(n != NULL)
    {
        int a;
        //verifica caso linha e negativo
        if(i > n->nlinhas || i < 0)
        {
            return -1;
        }
        //verifica caso coluna e negativo
        if(j > n->ncolunas || j < 0)
        {
            return -1;
        }

        a = n->dados[j * n->nlinhas + i];
        *val = a;
    }
    else
    {
        return -1;
    }

    return 1;
}



//linha e colunas
int matriz_fill(Matriz *n, int val)
{
    //verifica
    if(n != NULL)
    {
        //linhas
        for(int i = 0; i < n->nlinhas; i++)
        {
            //colunas
            for(int j = 0; j < n->ncolunas; j++)
            {
                //pega linhas e colunas e faz o cálculo de conversão
                n->dados[j * n->nlinhas + i] = val;
            }
        }

        return 1;
    }
    else
    {
        return -1;
    }
}

//get linha coluna
int matriz_get_lin_col(Matriz *m, int *nLin, int *nCol)
{
    *nLin = m->nlinhas;
    *nCol = m->ncolunas;

    return 1;
}

//imprime matriz
int matriz_print(Matriz *m)
{
    int val;
    //linha
    for(int i = 0; i < m->nlinhas; i++)
    {
        printf("\n");
        //coluna
        for(int j = 0; j < m->ncolunas; j++)
        {
            matriz_select(m, i, j, &val);
            printf("%d ", val);
        }
    }
    return 1;
}

//FREE
int matriz_free(Matriz *n)
{
    //verificacao, se não nulo
    if(n != NULL)
    {
        free(n->dados); //libera dados
        free(n); //libera n

        return 1;
    }
    else
    {
        return -1;
    }
}

