#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#include "fila.h"
#define SUCCESS 1
#define ERRO 0
#define INVALID_NULL_POINTER -1

//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
struct grafo
{
    int NumVert; //qtd vértices
    int NumAresta; //qtd arestas
    struct noVert *vertices;
};
struct noVert
{
    int vert; //vértice principal
    struct noVert *prox; //endereço do próx node vértice
    struct noAdj *ladj; //endereço do adjacente
};
struct noAdj
{
    int vert; //vértice adjacente
    struct noAdj *prox; //enreço do próx adj
    struct noTempo *tempo;
};
struct noTempo
{
    int entrada; //entrada tempo em horas
    int saida; //saída tempo em horas
    struct noTempo *prox; //prox node tempo
};
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//DEF
typedef struct grafo *Grafo;
typedef struct noVert *noVert;
typedef struct noAdj *noAdj;
typedef struct noTempo *noTempo;
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
Grafo criarGrafo(int nVert); //CRIA GRAFO - OK
void inserirNovoVertice(Grafo G, int v); //INSERIR NOVO VERTICE - OK
void inserirArestas(Grafo G, int v1, int v2); //INSERIR ARESTAS - OK
void insertTempoComVerificacao(Grafo G, int v1, int v2, int saida, int chegada); //INSERIR TEMPO COM VERIFICAÇÃO - OK
void imprimirListaAdj(Grafo G); // IMPRIMIR LISTA - OK
void verificaCaminho (Grafo grafo, int v1, int v2); // VERIFICA CAMINHO - OK
int primeiraChegada(Grafo G, int v1, int v2); // PRIMEIRA CHEGADA - OK
int ultimaSaida(Grafo G, int v1, int v2);      //ÚLTIMA SAÍDA - OK
int existeAresta(Grafo G, int v1,int v2); //EXISTE ARESTA - OK
int viagemMenorDuracao(Grafo G, int v1, int v2, int *entrada, int *saida); //VIAGEM COM MENOR DURAÇÃO - OK
int caminhoValidoEntreVertices(noVert v, TipoFila *saida); // CAMINHO VÁLIDO ENTRE OS VÉRTICES - OK
int verificaValidadeTempo(Grafo grafo, int origem, int destino, TipoFila *tFilaTempo); // VERIFICA VALIDADE TEMPO - OK
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

#endif // GRAFO_H_INCLUDED



