#include "TFile.h"
#include "TMatriz.h"

//mostra erro
void mensagem_erro(int n);

int main(int argc, char *argv[])
{
    int temp;

    //se argumento 1 for igual a -open então executa.
    //retorna 0 se strings iguais.
    if(strcmp(argv[1], "-open") == 0 && argc == 3)
    {
        //Abre uma imagem
        temp = print_file(argv[2]); //chama função print
        if(!temp)
        {
            mensagem_erro(temp); //se erro
        }
    }
    //se arg 1 for -convert
    else if(strcmp(argv[1], "-convert") == 0 && argc == 4)
    {
        //Converte formato da imagem
        temp = convert(argv[2], argv[3]);
        if(!temp)
        {
            mensagem_erro(temp); //se erro
        }

    }
    //se arg 1 for -segment
    else if(strcmp(argv[1], "-segment") == 0 && argc == 5)
    {
        int thr = atoi(argv[2]);
        //Faz o thresholding
        temp = segment(thr, argv[3], argv[4]);
        if(!temp)
        {
            mensagem_erro(temp); //se erro
        }

    }
    //se arg 1 for -cc
    else if(strcmp(argv[1], "-cc") == 0 && argc == 4)
    {
        //Detecta os componentes conexos de uma imagem
        temp = componente(argv[2], argv[3]);
        if(!temp)
        {
            mensagem_erro(temp); //se erro
        }
    }
    //se argv 1 for -lab
    else if(strcmp(argv[1], "-lab") == 0  && argc == 4)
    {
        //Labirinto
        temp = maze(argv[2], argv[3]);
        if(!temp)
        {
            mensagem_erro(temp); //se erro
        }
    }
    else //se erro
    {
        mensagem_erro(COMMAND_INVALID);
    }

    return 0;
}
