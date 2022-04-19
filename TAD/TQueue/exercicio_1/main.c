#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

#include "aluno.h"
#include "TQueue.h"
#include "TLinkedList.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    //------------------------------------------------------
    int i = 0, tamanho = 0, res = 0, caseUse = 0;
    struct aluno al;
    //------------------------------------------------------

    printf("Digite quantos alunos deseja inserir: ");
    scanf("%d",&tamanho);

    Queue *qu = queue_create();

    if(qu == NULL)
    {
        printf("Erro!");
        return INVALID_NULL_POINTER;
    }

    do
    {
        printf("\n****************************************************\n");
        printf("<< Cadastro de Aluno - FILA - TDLinkedList >> \n");
        printf("Digite uma opção");
        printf("\n 1 - queue_push"); //insere
        printf("\n 2 - queue_pop"); //remove
        printf("\n 3 - queue_front"); //busca por posição
        printf("\n 4 - queue_size"); //tamanho
        printf("\n 5 - queue_empty"); //vazio?
        printf("\n 6 - queue_full"); //cheio?
        printf("\n 7 - queue_free"); //limpar

        printf("\n 8 - Sair");

        printf("\n****************************************************\n");
        scanf(" %d", &caseUse);

        switch (caseUse)
        {

        case 1://insere final
            for(i = 0; i < tamanho; i++)
            {
                printf("\nDigite o número da matrícula: \n");
                scanf(" %d",&al.matricula);
                getchar();
                printf("\nDigite o nome do aluno: \n");
                fgets(al.nome,30,stdin);
                printf("Digite a 1º nota: \n");
                scanf(" %f",&al.n1);
                getchar();
                printf("Digite a 2º nota: \n");
                scanf(" %f",&al.n2);
                getchar();
                printf("Digite a 3º nota: \n");
                scanf(" %f",&al.n3);
                getchar();
                res = queue_push(qu, al);
            }
            break;


        case 2://Remove início

            queue_pop(qu);
            break;

        case 3://posição
            queue_front(qu, &al);
            break;

        case 4:
            res = 0;
            res = queue_size(qu);
            printf("\nO tamanho é: %d", res);
            break;

        case 5:
            queue_empty(qu);
            break;

        case 6:
            res = 0;
            res = queue_full(qu);
            if(res == 0)
            {
                printf("\nNão está cheia!");
            }
            else
            {
                printf("\nEstá cheia!");
            }
            break;

        case 7:
            res = 0;
            res = queue_free(qu);
            if(res == 0)
            {
                printf("\nFree executado!");
            }
            return 8;
            break;

        case 8:

            printf("\nFim do programa!");
            break;

        }
    }
    while(caseUse != 8);

    return 0;
}

