#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

#include "TCircular.h"

int main()
{
    //pt-br
    setlocale(LC_ALL, "Portuguese");
    //Informações que serão inseridas;
    Carro a = {"Toyota", "Etios"};
    Carro b = {"Honda", "Civic"};
    Carro c = {"Fiat", "Uno"};
    Carro d;

    ListCircular *listaCar = NULL;
    listaCar = list_create();
    //inserção
    list_push_begin(listaCar, a);
    list_push_begin(listaCar, b);
    list_push_begin(listaCar, c);
    //captura info
    list_data(listaCar, &d);
    //mostra informações capturadas
    printf("\nInformações:\n");
    printf("\n%s - %s\n", d.marca, d.modelo);

    return 0;
}

