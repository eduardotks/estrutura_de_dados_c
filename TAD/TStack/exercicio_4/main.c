#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

#include "TStack.h"


int main()
{
//**********************************
    setlocale(LC_ALL, "Portuguese");
//**********************************

    int n = 0;
    printf("\nDigite a quantidade de caracteres(Digite 1 caracter por vez): ");
    scanf("%d", &n);

    char *vetorChar;
    vetorChar = (char *) malloc(n * sizeof(char));

    for(int i = 0; i < n ; i++)
    {
        printf("\nDigite: ");
        scanf(" %c", &vetorChar[i]);
    }

    char c;

    Stack *st = NULL;
    st = stack_create();


    stack_push(st, vetorChar[0]);
    stack_top(st, &c);
    if(c != '(' && c != '[')
    {
        printf("\nInválido");
        return ERRO;
    }

    for(int i = 1; i < strlen(vetorChar); i++)
    {
        switch(vetorChar[i])
        {
        case 40:// "(" parenteses aberto decimal code
            stack_push(st, vetorChar[i]);
            break;

        case 41:// ")" parenteses fechado decimal code
            stack_top(st, &c);
            if(c == 40)
            {
                stack_pop(st);
                break;
            }
            else
            {
                printf("\nInválido");
                return ERRO;
            }


        case 91:// "["  colchete aberto decimal code
            stack_push(st, vetorChar[i]);
            break;

        case 93:// "]" colchete fechado decimal code
            stack_top(st, &c);
            if(c == 91)
            {
                stack_pop(st);
                break;
            }
            else
            {
                printf("\nInválido");
                return ERRO;
            }

        default:
            printf("\nERRO!!!");
            break;
        }
    }


    if(stack_size(st) == SUCCESS)
    {
        printf("\n>>> STRING ESTÁ BEM FORMADA\n");
    }
    else
    {
        printf("\n>>> STRING ESTÁ MAL FORMADA\n");
    }


    return SUCCESS;
}

