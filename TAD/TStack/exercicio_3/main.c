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
    printf("\nDigite a quantidade de caracteres: ");
    scanf("%d", &n);

    char *vetorChar;
    vetorChar = (char *) malloc(n * sizeof(char));

    Stack *st = NULL;
    st = stack_create();

    for(int i = 0; i < n ; i++)
    {
        printf("\nDigite: ");
        scanf(" %c", &vetorChar[i]);
        stack_push(st, vetorChar[i]);
    }






    return SUCCESS;
}

