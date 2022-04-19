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
    novoVertice->prox = vp;//guarda endereço
    novoVertice->ladj = NULL;//seta NULL
    return novoVertice; //
}
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
noAdj inserirAdjacencia(int vdest, noAdj m)
{
    noAdj novo = (noAdj) malloc(sizeof (struct noAdj)); //aloca
    novo->vert = vdest;//seta vértice com valor correspondente
    novo->prox = m; //liga nó
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
    if (G == NULL) //verifica se válido
    {
        return;
    }
    for (v = G->vertices; v != NULL; v = v->prox) //percorre para inserção
    {
        if (v->vert == v1) //se encontrou o vértice então insere
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
    if (G == NULL)//verifica se G válido
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

    if (G == NULL) //verifica G válido
    {
        return INVALID_NULL_POINTER;
    }
    //for vertice
    for (v = G->vertices; v != NULL; v = v->prox) //percorre até não encontrar
    {
        if (v->vert == v1) //se encontrou
        {
            //for Adjacente
            for(z = v->ladj; z != NULL; z = z->prox) //percorre até não encontrar
            {
                if (z->vert == v2) //se encontrou
                {
                    //for tempo
                    for(x = z->tempo; x != NULL; x = x->prox) //percorre tempo até não achar mais
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

    if (G == NULL) //verifica G válido
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
                        res = x->saida - x->entrada; //tempo final ou duração
                    }
                }
            }
        }
    }

    return res; //retorna duração
}
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
int existeAresta(Grafo G, int v1,int v2) //verifica existência de aresta
{
    noVert v; //def
    noAdj z; //def

    if(G == NULL) //verifica se G válido
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

    if (G == NULL) //verifica se G válido
    {
        return;
    }

    //for vertice
    for (v = G->vertices; v != NULL; v = v->prox) //percorre se não nulo
    {
        printf("\nVértice %d: ",v->vert);
        //for adjacencia
        for (z = v->ladj; z != NULL; z = z->prox) //percorre se não nulo
        {
            printf("| %d", z->vert); //print para multi usos
            //for Tempo
            for(x = z->tempo; x != NULL; x = x->prox) //percorre se não nulo
            {

                printf(" : [Saída Bus: %d horas, Chegada Bus: %d horas]", x->entrada, x->saida); //mostra tempos
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
    int aux = 0; //temporário aux
    int ant = 0; //
    int i = 0; //
    int a = 0; //

    if(G == NULL) //verifica
    {
        return;
    }

    //------------------ALOCAÇÃO E VERIFICAÇÃO-------------------
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
    // pré set field
    aux = v1; // armazena
    ant = v1; //armazena
    X[aux] = 1; //vértice percorrido = 1
    //

    for(i = 0; i < G->NumVert; i++) //percorre pelo número de vértices existentes
    {
        //para cada pos do vet preenche valores pre setados;
        X[i] = 0; //set 0
        X1[i] = -9999; //set -9999
    }
    //------------------------------------------------------------
    //Utilizando codificação em FILA temos:
    //Def
    TipoFila tFila[G->NumVert];
    TipoFila tFilaTempo;
    //---
    for(int i = 0; i < G->NumVert; i++) //percorre qtd vértice
    {
        IniciaFila(&tFila[i]); //inicia baseado no tamanho
    }
    IniciaFila(&tFilaTempo); //inicia
    //---

    while(ant != v2 && ant != -1) //enquanto houver valor e encontrar resultado e o ant não for != -1
    {
        //For vértices
        for(v = G->vertices; v != NULL; v = v->prox) // percorre vértices enquanto não for NULL
        {
            if(v->vert == aux) //se encontrou elemento
            {
                //For Adjacencias
                for(z = v->ladj; z != NULL; z = z->prox)// percorre enquanto não for NULL
                {
                    if(X1[z->vert] == -9999) //se não tiver armazenado, seta o anterior
                    {
                        X1[z->vert] = ant; //set anterior no vetor
                    }
                    //for Tempo
                    for(x = z->tempo; x != NULL; x = x->prox) // percorre enquanto não for NULL
                    {
                        Enfileira(x->saida, &tFila[z->vert]); //enfileira nodes com tempos de chegada
                    }
                }
            }
        }


        //------------------------------------------------------------
        //pré set field
        ant = aux;
        aux = -1;
        //--
        //Verifica se chegou no final e finaliza o loop
        if(ant == v2)
        {
            break;
        }
        //for Vértices
        for(v = G->vertices; v != NULL; v = v->prox) //percorre até ser diferente de Null
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
                else //se vértice diferente de v2
                {
                    auxT = caminhoValidoEntreVertices(v, &tFila[v->vert]); //retorna valor, se válido ou não.
                    if(auxT != -1) //se válido
                    {
                        aux = v->vert; //aux recebe o vértice
                        ant = aux; //armazena o vert
                        Esvazia(&tFila[v->vert]); //esvazia a fila
                        Desenfileira(&tFilaTempo); //Remove da fila
                        Enfileira(auxT, &tFilaTempo); //insere valor válido
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
        //como o vetor foi preenchido ao contrário, será necessário fazer a correção
        printf("\n SIM : ");
        for( ; a > 0 ; a--)
        {
            printf("%d ", RES[a-1]);
        }
        printf("\n");

    }
    else
        printf("\n NÃO : Caminho inválido!!!\n");

    //------------------------------------------------------------
    //chama funções para liberar FILAS
    for(int i = 0; i < G->NumVert; i++) //percorre a quantidade de vértice
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

    //verificação
    if(Vazia(saida)) //verifica se Fila é válida
    {
        return -1;
    }

    //For Nó
    for(no = saida->inicio; no != NULL; no = no->prox) //percorre até o nó ser diferente de NULL
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

    if (G == NULL) //verificação
    {
        return INVALID_NULL_POINTER; // retorna inválido
    }

    int auxT = Desenfileira(tFilaTempo); //chama função de fila

    //for Vértices
    for (v = G->vertices; v != NULL; v = v->prox) //percorre até o nó ser diferente de NULL
    {
        if (v->vert == v1) //se encontrou
        {
            //for Adjacencias
            for (z = v->ladj; z != NULL; z = z->prox) //percorre até o nó ser diferente de NULL
            {
                if (z->vert == v2) //se encontrou
                {
                    //for Tempo
                    for(x = z->tempo; x != NULL; x = x->prox) //percorre até o nó ser diferente de NULL
                    {
                        if(x->entrada > auxT) //compara tempos
                        {
                            return SUCCESS; //retorna válido
                        }
                    }
                }
            }
        }
    }
    return ERRO; //retorna inválido
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
        //se existir um prox,  e o prox aux da saída menor que o tempo de saída var
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

    //for vértices
    for (v = G->vertices; v != NULL; v = v->prox) //percorre vértices
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
