#include "grafo.h"
#include "fila.h"
#include "no.h"
#include <stdlib.h>
#include <stdio.h>
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
noVert inserirVertice(noVert vp, int num)
{
    noVert novoVertice;
    novoVertice = (noVert) malloc (sizeof(struct noVert));//aloca
    novoVertice->vert = num;//insere vert
    novoVertice->prox = vp;//guarda endere�o
    novoVertice->ladj = NULL;//seta NULL
    return novoVertice; //
}
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
noAdj inserirAdjacencia(int vdest, noAdj m)
{
    noAdj novo = (noAdj) malloc(sizeof (struct noAdj)); //aloca
    novo->vert = vdest;//seta v�rtice com valor correspondente
    novo->prox = m; //liga n�
    novo->tempo = NULL;//seta strc tempo em NULL
    return novo;
}
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
Grafo criarGrafo(int nVert)
{
    Grafo G;
    G = (Grafo) malloc(sizeof (Grafo)); //aloca
    G->NumAresta = 0; //seta 0
    G->NumVert = 0; //seta 0
    G->vertices = NULL; //seta NULL
    for (int v = nVert-1; v >= 0; v--)
    {
        G->vertices = inserirVertice(G->vertices,v); //insert
        G->NumVert++; //incrementa
    }
    return G;
}
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
void inserirNovoVertice(Grafo G, int v)
{
    G->vertices = inserirVertice(G->vertices,v);  //chama func
    G->NumVert++; //incrementa qtd
}
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
void inserirArestas(Grafo G, int v1, int v2)
{
    noVert v;
    noAdj z;
    if (G == NULL) //verifica se v�lido
    {
        return;
    }
    for (v = G->vertices; v != NULL; v = v->prox) //percorre para inser��o
    {
        if (v->vert == v1) //se encontrou o v�rtice ent�o insere
        {
            for(z = v->ladj; z != NULL; z = z->prox) // percorre
            {
                if (z->vert == v2) //se existe sai
                {
                    return;
                }
            }
            v->ladj = inserirAdjacencia(v2,v->ladj); //insere
            G->NumAresta++; //incrementa
        }
    }
}
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//para a primeira chegada do transporte
int primeiraChegada(Grafo G, int v1, int v2)
{
    noVert v;//def
    noAdj z;//def
    if (G == NULL)//verifica se G v�lido
    {
        return INVALID_NULL_POINTER;
    }

    for (v = G->vertices; v != NULL; v = v->prox) //percorre
    {
        if (v->vert == v1) //se encontrou
        {
            for(z = v->ladj; z != NULL; z = z->prox) //percorre
            {
                if (z->vert == v2) //se encontrou, devolve valor
                {
                    return z->tempo->saida;
                }
            }
        }
    }
    return ERRO;
}
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
int ultimaSaida(Grafo G, int v1, int v2)
{
    noVert v; //def
    noAdj z; //def
    noTempo x; //def
    //var
    int res = 0;

    if (G == NULL) //verifica G v�lido
    {
        return INVALID_NULL_POINTER;
    }
    //for vertice
    for (v = G->vertices; v != NULL; v = v->prox) //percorre at� n�o encontrar
    {
        if (v->vert == v1) //se encontrou
        {
            //for Adjacente
            for(z = v->ladj; z != NULL; z = z->prox) //percorre at� n�o encontrar
            {
                if (z->vert == v2) //se encontrou
                {
                    //for tempo
                    for(x = z->tempo; x != NULL; x = x->prox) //percorre tempo at� n�o achar mais
                    {
                        if(x->entrada > res)
                        {
                            res = x->entrada; //armazena tempo
                        }
                    }
                }
            }
        }
    }
    return res;
}
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
int viagemMenorDuracao(Grafo G, int v1, int v2, int *entrada, int *saida)
{
    noVert v; //def
    noAdj z; //def
    noTempo x; //def
    int res = 0; //var

    if (G == NULL) //verifica G v�lido
    {
        return INVALID_NULL_POINTER;
    }
    //for vertice
    for (v = G->vertices; v != NULL; v = v->prox) //percorre
    {
        if (v->vert == v1)//se encontrou
        {
            //for Adjacente
            for(z = v->ladj; z != NULL; z = z->prox) //percorre
            {
                if (z->vert == v2) //se encontrou
                {
                    //for Tempo
                    for(x = z->tempo; x != NULL; x = x->prox)
                    {
                        *entrada = x->entrada; //armazena
                        *saida = x->saida; //armazena
                        res = x->saida - x->entrada; //tempo final ou dura��o
                    }
                }
            }
        }
    }

    return res; //retorna dura��o
}
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
int existeAresta(Grafo G, int v1,int v2) //verifica exist�ncia de aresta
{
    noVert v; //def
    noAdj z; //def

    if(G == NULL) //verifica se G v�lido
    {
        return INVALID_NULL_POINTER;
    }

    //for vertice
    for(v = G->vertices; v != NULL; v = v->prox) //percorre
    {
        if(v->vert == v1) //se encontrou
        {
            //for adjacencia
            for(z = v->ladj; z != NULL; z = z->prox) //percorre
            {
                if(z->vert == v2) //se encontrou
                {
                    return SUCCESS; //retorna sucesso
                }
            }
        }
    }
    return ERRO;
}
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

void imprimirListaAdj(Grafo G)
{
    noVert v; //Def
    noAdj z; //Def
    noTempo x; //Def

    if (G == NULL) //verifica se G v�lido
    {
        return;
    }

    //for vertice
    for (v = G->vertices; v != NULL; v = v->prox) //percorre se n�o nulo
    {
        printf("\nV�rtice %d: ",v->vert);
        //for adjacencia
        for (z = v->ladj; z != NULL; z = z->prox) //percorre se n�o nulo
        {
            printf("| %d", z->vert); //print para multi usos
            //for Tempo
            for(x = z->tempo; x != NULL; x = x->prox) //percorre se n�o nulo
            {

                printf(" : [Sa�da Bus: %d horas, Chegada Bus: %d horas]", x->entrada, x->saida); //mostra tempos
            }
            printf(" |;");
        }
    }
}
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
void verificaCaminho (Grafo G, int v1, int v2)
{
    noVert v; //def
    noAdj z; //def
    noTempo x; //def
    //Var
    int *X = 0; //temp
    int *X1 = 0; //temp
    int *RES = 0; //para o caminho
    int auxT = 0; //tempo aux
    int aux = 0; //tempor�rio aux
    int ant = 0; //
    int i = 0; //
    int a = 0; //

    if(G == NULL) //verifica
    {
        return;
    }

    //------------------ALOCA��O E VERIFICA��O-------------------
    X = (int *)malloc(G->NumVert*sizeof(int));
    X1 = (int *)malloc(G->NumVert*sizeof(int));
    RES = (int *)malloc(G->NumVert*sizeof(int));

    if(X == NULL) //verifica aloc
    {
        return;
    }
    if(X1 == NULL) //verifica aloc
    {
        return;
    }
    if(RES == NULL) //verifica aloc
    {
        return;
    }
    //------------------------------------------------------------
    // pr� set field
    aux = v1; // armazena
    ant = v1; //armazena
    X[aux] = 1; //v�rtice percorrido = 1
    //

    for(i = 0; i < G->NumVert; i++) //percorre pelo n�mero de v�rtices existentes
    {
        //para cada pos do vet preenche valores pre setados;
        X[i] = 0; //set 0
        X1[i] = -9999; //set -9999
    }
    //------------------------------------------------------------
    //Utilizando codifica��o em FILA temos:
    //Def
    TipoFila tFila[G->NumVert];
    TipoFila tFilaTempo;
    //---
    for(int i = 0; i < G->NumVert; i++) //percorre qtd v�rtice
    {
        IniciaFila(&tFila[i]); //inicia baseado no tamanho
    }
    IniciaFila(&tFilaTempo); //inicia
    //---

    while(ant != v2 && ant != -1) //enquanto houver valor e encontrar resultado e o ant n�o for != -1
    {
        //For v�rtices
        for(v = G->vertices; v != NULL; v = v->prox) // percorre v�rtices enquanto n�o for NULL
        {
            if(v->vert == aux) //se encontrou elemento
            {
                //For Adjacencias
                for(z = v->ladj; z != NULL; z = z->prox)// percorre enquanto n�o for NULL
                {
                    if(X1[z->vert] == -9999) //se n�o tiver armazenado, seta o anterior
                    {
                        X1[z->vert] = ant; //set anterior no vetor
                    }
                    //for Tempo
                    for(x = z->tempo; x != NULL; x = x->prox) // percorre enquanto n�o for NULL
                    {
                        Enfileira(x->saida, &tFila[z->vert]); //enfileira nodes com tempos de chegada
                    }
                }
            }
        }


        //------------------------------------------------------------
        //pr� set field
        ant = aux;
        aux = -1;
        //--
        //Verifica se chegou no final e finaliza o loop
        if(ant == v2)
        {
            break;
        }
        //for V�rtices
        for(v = G->vertices; v != NULL; v = v->prox) //percorre at� ser diferente de Null
        {
            if(X[v->vert] == 0 && existeAresta(G, ant, v->vert)) //verifica se elemento = 0 e se existe aresta
            {
                if(v->vert == v2)//Se encontrou igual a v2
                {
                    if(verificaValidadeTempo(G, ant, v->vert, &tFilaTempo))
                    {
                        aux = v->vert; //seta v
                        ant = aux; //seta aux no anterior
                        break; //finaliza loop
                    }
                }
                else //se v�rtice diferente de v2
                {
                    auxT = caminhoValidoEntreVertices(v, &tFila[v->vert]); //retorna valor, se v�lido ou n�o.
                    if(auxT != -1) //se v�lido
                    {
                        aux = v->vert; //aux recebe o v�rtice
                        ant = aux; //armazena o vert
                        Esvazia(&tFila[v->vert]); //esvazia a fila
                        Desenfileira(&tFilaTempo); //Remove da fila
                        Enfileira(auxT, &tFilaTempo); //insere valor v�lido
                        break; //sai do loop
                    }
                }
            }
        }
        for(int i = 0; i < G->NumVert; i++) //percorre pela quantidade
        {
            Esvazia(&tFila[i]); //esvazia a fila.
        }

        X[aux] = 1;
    }

    //------------------------------------------------------------
    //PRINT AREA
    if(ant == v2) //
    {
        RES[0] = v2;

        a = 1;
        while(ant != v1) //loop para preenchimento
        {
            RES[a] = X1[ant]; //Altera no Vector RES
            ant = X1[ant];
            a++; //incrementa
        }

        RES[a] = v1;
        //como o vetor foi preenchido ao contr�rio, ser� necess�rio fazer a corre��o
        printf("\n SIM : ");
        for( ; a > 0 ; a--)
        {
            printf("%d ", RES[a-1]);
        }
        printf("\n");

    }
    else
        printf("\n N�O : Caminho inv�lido!!!\n");

    //------------------------------------------------------------
    //chama fun��es para liberar FILAS
    for(int i = 0; i < G->NumVert; i++) //percorre a quantidade de v�rtice
    {
        Libera(&tFila[i]); //Libera fila v
    }
    Libera(&tFilaTempo); //Libera a fila de Tempos
}


//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
int caminhoValidoEntreVertices(noVert v, TipoFila *saida) //
{
    TipoNo *no; //DEF
    noAdj z; //DEF
    noTempo x; //DEF

    //var
    int tInicial = 0; //declara

    //verifica��o
    if(Vazia(saida)) //verifica se Fila � v�lida
    {
        return -1;
    }

    //For N�
    for(no = saida->inicio; no != NULL; no = no->prox) //percorre at� o n� ser diferente de NULL
    {
        tInicial = no->valor;
        //for Adjacencia
        for(z = v->ladj; z != NULL; z = z->prox)//percorre
        {
            //for Tempo
            for(x = z->tempo; x != NULL; x = x->prox)//percorre
            {
                if(x->entrada > tInicial) //compara tempos
                {
                    return tInicial; //se menor retorna.
                }
            }
        }
    }

    return ERRO;
}


//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
int verificaValidadeTempo(Grafo G, int v1, int v2, TipoFila *tFilaTempo)
{
    noVert v; //DEF
    noAdj z; //DEF
    noTempo x; //DEF
    //-------------------

    if (G == NULL) //verifica��o
    {
        return INVALID_NULL_POINTER; // retorna inv�lido
    }

    int auxT = Desenfileira(tFilaTempo); //chama fun��o de fila

    //for V�rtices
    for (v = G->vertices; v != NULL; v = v->prox) //percorre at� o n� ser diferente de NULL
    {
        if (v->vert == v1) //se encontrou
        {
            //for Adjacencias
            for (z = v->ladj; z != NULL; z = z->prox) //percorre at� o n� ser diferente de NULL
            {
                if (z->vert == v2) //se encontrou
                {
                    //for Tempo
                    for(x = z->tempo; x != NULL; x = x->prox) //percorre at� o n� ser diferente de NULL
                    {
                        if(x->entrada > auxT) //compara tempos
                        {
                            return SUCCESS; //retorna v�lido
                        }
                    }
                }
            }
        }
    }
    return ERRO; //retorna inv�lido
}


//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
noTempo insertComVerificacaoTempo(int entrada, int saida, noTempo noT)
{
    noTempo NOTEMPO = (noTempo)malloc(sizeof(struct noTempo)); //aloca

    if(NOTEMPO == NULL) //verifica/valida
    {
        return INVALID_NULL_POINTER;
    }

    NOTEMPO->entrada = entrada; //seta valor da entrada
    NOTEMPO->saida = saida; //seta valor da saida

    if(noT == NULL || saida <= noT->saida) //compara os tempos e e "noT" for igual a nulo
    {
        NOTEMPO->prox = noT; //seta noT no prox
        noT = NOTEMPO; //atribui

        return noT; //
    }
    //armazena em um aux tipo noTempo
    noTempo aux = noT;

    while(aux->prox != NULL && aux->prox->saida < saida)
        //se existir um prox,  e o prox aux da sa�da menor que o tempo de sa�da var
    {
        aux = aux->prox; //aux aponta pra prox
    }

    NOTEMPO->prox = aux->prox;
    aux->prox = NOTEMPO;

    return noT;
}

//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
void insertTempoComVerificacao(Grafo G, int v1, int v2, int entrada, int saida)
{
    noVert v; //DEF
    noAdj z; //DEF

    if (G == NULL)
    {
        return;
    }

    //for v�rtices
    for (v = G->vertices; v != NULL; v = v->prox) //percorre v�rtices
    {
        if (v->vert == v1)  //se encontrou
        {
            //for Adjacencias
            for(z = v->ladj; z != NULL; z = z->prox)

                if (z->vert == v2) //se encontrou
                {
                    z->tempo = insertComVerificacaoTempo(entrada, saida, z->tempo);// insere
                    break; //sai do loop
                }
        }
    }
}
