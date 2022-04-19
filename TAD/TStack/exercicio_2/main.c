#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

#include "TLinkedList.h"
#include "aluno.h"
#include "TStack.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    //------------------------------------------------------------------
    int i = 0, tamanho = 0, res = 0, caseUse = 0, pos = 0;
    struct aluno al;
    //------------------------------------------------------------------
    printf("Digite o tamanho que será alocado: ");
    scanf("%d",&tamanho);

    Stack *st = stack_create(tamanho);

    if(st == NULL)
    {
        printf("Erro!");
        return INVALID_NULL_POINTER;
    }

    do
    {
        printf("\n****************************************************\n");
        printf("<< Cadastro de Aluno - Pilha - Encadeada Dinâmica >> \n");
        printf("Digite uma opção");
        printf("\n 1 - stack_push"); //insere
        printf("\n 2 - stack_pop"); //remove
        printf("\n 3 - stack_top"); //busca por posição
        printf("\n 4 - stack_print"); //imprime
        printf("\n 5 - stack_size"); //tamanho
        printf("\n 6 - stack_empty"); //
        printf("\n 7 - stack_free"); //

        printf("\n 8 - Sair");

        printf("\n****************************************************\n");
        scanf(" %d", &caseUse);

        switch (caseUse)
        {

        case 1:
            //------------------------------------------------
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
                res = stack_push(st, al);
            }
            break;
        //------------------------------------------------


        case 2:
            //------------------------------------------------
            stack_pop(st);
            break;
        //------------------------------------------------


        case 3:
            //--------------------------------------------
            pos = 0;
            printf("\nDigite a posição que deseja pesquisar: \n");
            scanf(" %d",&pos);
            getchar();
            stack_top(st,pos, &al);
            break;
        //--------------------------------------------


        case 4:
            //--------------------------------------------
            stack_print(st);
            break;

        //--------------------------------------------

        case 5:
            //------------------------
            res = 0;
            res = stack_size(st);
            printf("\nO tamanho é: %d", res);
            break;
        //------------------------

        case 6:
            //-------------------------
            res = 0;

            res = stack_empty(st);
            if(res == 0)
            {
                printf("\nA lista está vazia!");
            }
            else
            {
                printf("\nA lista NÃO está vazia!");
            }

            break;
        //------------------------


        case 7:
            //-------------------------
            stack_free(st);
            return 8; //para sair depois de desalocar
            break;
        //------------------------

        case 8:
            //----------------------------
            printf("\nFim do programa!");
            break;
            //----------------------------

        }
    }
    while(caseUse != 8);

    return 0;
}
