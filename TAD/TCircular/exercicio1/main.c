#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

#include "aluno.h"
#include "TCircular.h"
int main()
{
    //pt-br
    setlocale(LC_ALL, "Portuguese");
    //------------------------------------------------------
    int i = 0, tamanho = 0, res = 0, caseUse = 0, pos = 0, mat = 0;
    struct aluno al;
    ListCircular *cl = NULL;
    //------------------------------------------------------

    printf("Quantos deseja inserir? ");
    scanf("%d",&tamanho);

    cl = list_create();
    //verifica create
    if(cl == NULL)
    {
        printf("Erro!");
        return INVALID_NULL_POINTER;
    }

    do
    {
        printf("\n****************************************************\n");
        printf("<< Cadastro de Aluno - LISTA CIRCULAR >> \n");
        printf("Digite uma opção");
        //insert area
        printf("\n 1 - list_push_begin");       //insere
        printf("\n 2 - list_push_end");         //insere
        printf("\n 3 - list_push_pos");         //insere
        //remove area
        printf("\n 4 - list_remove_begin");     //remove
        printf("\n 5 - list_remove_end");       //remove
        printf("\n 6 - list_remove_mat");       //remove
        printf("\n 7 - list_remove_pos");       //remove
        //print area
        printf("\n 8 - list_print");
        //Print
        printf("\n 9 - list_select_begin");     //mostra inicio
        printf("\n 10 - list_select_end");      //mostra fim
        printf("\n 11 - list_select_mat");      //mostra aluno por mat
        printf("\n 12 - list_select_pos");      //mostra aluno por pos
        //EXIT
        printf("\n 13 - Sair"); //sair

        printf("\n****************************************************\n");
        scanf(" %d", &caseUse);

        switch (caseUse)
        {

        case 1:
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
                res = list_push_begin(cl, al);
                if(res == INVALID_NULL_POINTER)
                {
                    return ERRO;
                }
            }
            break;


        case 2:

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
                res = list_push_end(cl, al);
                if(res == INVALID_NULL_POINTER)
                {
                    return ERRO;
                }
            }
            break;

        case 3:
            res = 0;
            printf("Digite a posição que deseja inserir o aluno: ");
            scanf(" %d", &pos);
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
                res = list_push_pos(cl, pos, al);
                if(res == INVALID_NULL_POINTER)
                {
                    return ERRO;
                }
            }
            break;

        case 4:
            list_remove_begin(cl);
            printf("\nRemovido do Início!\n");
            break;

        case 5:
            list_remove_end(cl);
            printf("\nRemovido do Final!\n");
            break;

        case 6:
            mat = 0;
            printf("Digite a matrícula para remover o aluno: ");
            scanf(" %d", &mat);
            list_remove_mat(cl, mat);
            break;

        case 7:
            pos = 0;
            printf("Digite a posição para remover o aluno: ");
            scanf(" %d", &pos);
            list_remove_pos(cl, pos);
            break;

        case 8:
            res = 0;
            res = list_print(cl);
            if(res < 0)
            {
                printf("\nNão existe nada para mostrar!!!! \n");
            }
            break;

        case 9:
            list_select_begin(cl, &al);
            break;

        case 10:
            list_select_end(cl, &al);
            break;

        case 11:
            mat = 0;
            printf("Digite a matrícula do aluno: ");
            scanf(" %d", &mat);
            list_select_mat(cl, mat, &al);
            break;

        case 12:
            pos = 0;
            printf("Digite a posição do aluno: ");
            scanf(" %d", &pos);
            list_select_pos(cl, pos, &al);
            break;

        case 13:

            printf("\nFim do programa!");
            break;

        }
    }
    while(caseUse != 13);

    return 0;
}
