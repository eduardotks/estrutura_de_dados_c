#include "TFile.h"

//imprime
int print_file(char *fileIn)
{
    Matriz *m;
    int aux;

    //abre arquivo
    aux = open_file(fileIn, &m);
    //verifica se valido
    if(!aux)
    {
        return FAIL_OPEN_FILEIN;
    }
    matriz_print(m); //imprime linhaXcoluna
    matriz_free(m); //libera matriz
    return SUCCESS;
}

//converte
int convert(char *fileIn, char *fileOut)
{
    Matriz *m;
    //abre arquivo
    open_file(fileIn, &m);
    //escreve no arquivo
    write_in_file(fileOut, m);

    return SUCCESS;
}

//thresholding(limiarização)
int segment(int limiar, char *fileIn, char *fileOut)
{
    Matriz *m;
    int nLin, nCol;
    int val;

    open_file(fileIn, &m);
    matriz_get_lin_col(m, &nLin, &nCol);

    //faz thresholding
    //linha
    for(int i = 0; i < nLin; i++)
    {
        //coluna
        for(int j = 0; j < nCol; j++)
        {
            //chama funcao matriz
            matriz_select(m, i, j, &val);
            if(val >= limiar)
            {
                //insere 1
                matriz_insert(m, i, j, 1);
            }
            else
            {
                //insere 0
                matriz_insert(m, i, j, 0);
            }
        }
    }
    //escreve matriz no arquivo
    write_in_file(fileOut, m);
    //libera matriz m
    matriz_free(m);
    return SUCCESS;
}

int componente(char *fileIn, char *fileOut)
{
    Stack *st;
    Matriz *img;
    Matriz *imagem_rotulada;
    Ponto vetor_ponto[4];
    Ponto base;
    int nLin, nCol;
    int valA, valB;
    int rotulo = 0;

    open_file(fileIn, &img);

    //capturar linha e coluna
    matriz_get_lin_col(img, &nLin, &nCol);

    //cria matriz
    imagem_rotulada = matriz_create(nLin, nCol);

    //preencher matriz com zero
    matriz_fill(imagem_rotulada, 0);

    //pilha create
    st = stack_create();

    //Rotulamento Matriz imagem_rotulada
    //linha
    for(int i = 0; i < nLin; i++)
    {
        //coluna
        for(int j = 0; j < nCol; j++)
        {
            //consulta val
            matriz_select(img, i, j, &valA);
            matriz_select(imagem_rotulada, i, j, &valB);

            //tendo 1 e 0 executa
            if(valA == 1 && valB == 0)
            {
                rotulo++;
                printf("\n Informação capturada teste::: %d\n", rotulo);
                matriz_insert(imagem_rotulada, i, j, rotulo);//insere rotulo em uma img de saída

                //coloca no ponto onde começou
                base.x = i; //lin
                base.y = j; //col

                //insere
                stack_push(st, base);

                while(stack_size(st) > 0)
                {

                    stack_top(st, &base);
                    stack_pop(st);
                    // cima baixo esquerda direita
                    vetor_ponto[0].x= base.x;
                    vetor_ponto[0].y= base.y-1;
                    vetor_ponto[1].x= base.x-1;
                    vetor_ponto[1].y= base.y;
                    vetor_ponto[2].x= base.x;
                    vetor_ponto[2].y= base.y+1;
                    vetor_ponto[3].x= base.x+1;
                    vetor_ponto[3].y= base.y;


                    for(int k = 0; k < 4; k++)
                    {
                        if(vetor_ponto[k].x < 0 || vetor_ponto[k].x > nLin ||
                                vetor_ponto[k].y < 0 || vetor_ponto[k].y > nCol)
                        {
                            continue;
                        }
                        //printf("nlin ncol: %d %d\n", nLin, nCol);
                        matriz_select(img, vetor_ponto[k].x, vetor_ponto[k].y, &valA);
                        matriz_select(imagem_rotulada, vetor_ponto[k].x, vetor_ponto[k].y, &valB);

                        if(valA == 1 && valB == 0)
                        {

                            matriz_insert(imagem_rotulada, vetor_ponto[k].x, vetor_ponto[k].y, rotulo);
                            stack_push(st, vetor_ponto[k]);
                            base = vetor_ponto[k];
                            break;
                        }
                    }

                }
            }
        }
    }
    //escreve no arquivo
    write_in_file(fileOut, imagem_rotulada);

    matriz_free(img); //libera
    matriz_free(imagem_rotulada); //libera
    stack_free(st); //libera pilha

    return SUCCESS;
}

//LABIRINTO
int maze(char *fileIn, char *fileOut)
{
    Stack *st;
    Matriz *img;
    Matriz *imagem_rotulada;
    Ponto inicio;
    Ponto atual;
    Ponto vetor_ponto[4];
    int nLin, nCol;
    int val, valA, valB;
    int x, y;

    //abre o arquivo
    open_file(fileIn, &img);

    //pega linha coluna
    matriz_get_lin_col(img, &nLin, &nCol);

    //create/alocacao
    imagem_rotulada = matriz_create(nLin, nCol);

    //insere 0
    matriz_fill(imagem_rotulada, 0);

    //aloca pilha
    st = stack_create();

    //variável de teste
    int achei = 0;
    //verifica linha
    for(int i = 0; i < nLin; i++)
    {
        //pega val
        matriz_select(img, i, 0, &val);

        if(val == 1)
        {
            inicio.x = i;
            inicio.y = 0;
            achei = 1;
            break;
        }
        //pega val
        matriz_select(img, i, nCol-1, &val);
        if(val == 1)
        {
            inicio.x = i;
            inicio.y = nCol-1;
            achei = 1;
            break;
        }
    }

    if(achei == 0 )
    {
        //verifica coluna
        for(int i = 0; i < nCol; i++)
        {
            //pega val
            matriz_select(img, 0, i, &val);
            if(val == 1)
            {
                inicio.x = 0;
                inicio.y = i;
                achei = 1;
                break;
            }
            //pega val
            matriz_select(img, nLin-1, i, &val);
            if(val == 1)
            {
                inicio.x = nLin-1;
                inicio.y = i;
                achei = 1;
                break;
            }
        }
    }
    //insere 2 na pos inicial
    matriz_insert(imagem_rotulada, inicio.x, inicio.y, 2);

    atual.x = inicio.x; //armazena em atual x
    atual.y = inicio.y; //armazena em atual y
    int sem_saida = 0;
    while( 1 )
    {

        matriz_select(img, atual.x, atual.y, &valA);
        //testando
        printf("Teste para sair: ax :%d ay :%d valA :%d inx :%d iny :%d numLin :%d numCol :%d\n", atual.x, atual.y, valA, inicio.x, inicio.y, nLin, nCol);
        if
        (
            (atual.y == 0 || atual.x == 0 || atual.y == nCol-1 || atual.x == nLin-1) &&
            (valA == 1) &&
            (atual.x != inicio.x || atual.y != inicio.y)
        )
        {
            matriz_insert(imagem_rotulada, atual.x, atual.y, 2);
            break;
        }

        //posições para vizinhos
        vetor_ponto[0].x= atual.x ;
        vetor_ponto[0].y= atual.y-1;
        vetor_ponto[1].x= atual.x-1;
        vetor_ponto[1].y= atual.y;
        vetor_ponto[2].x= atual.x;
        vetor_ponto[2].y= atual.y+1;
        vetor_ponto[3].x= atual.x+1;
        vetor_ponto[3].y= atual.y;

        //Percorre e rotula a partir da terceira posição do caminho
        for(int i = 0; i < 4; i++)
        {
            x = vetor_ponto[i].x;
            y = vetor_ponto[i].y;

            //teste de ponto
            printf("Estou no ponto (%d, %d):\n", x, y);

            if( x >= nLin || x < 0 ||
                    y >= nCol || y < 0)
            {
                printf("Estou no ponto (%d, %d) entrei para continue: ", x, y);
                continue;
            }

            matriz_select(img, x, y, &valA);
            matriz_select(imagem_rotulada, x, y, &valB);

            if(valA == 1 && valB == 0)////valido? Então rotula 2 e vai para o proximo que encontrar
            {
                printf("Achei um válido %d %d\n",  x, y);
                stack_push(st, vetor_ponto[i]);
                //insere 2
                matriz_insert(imagem_rotulada, x, y, 2);
                atual = vetor_ponto[i];
                break;
            }
            else
            {
                //Se nao ha mais para onde ir, volta.
                if(i == 3)
                {

                    matriz_insert(imagem_rotulada, atual.x, atual.y, 1);
                    stack_pop(st); //remove

                    //retorna info
                    int retorno = stack_top(st, &atual);

                    if( retorno == 0 )
                    {
                        sem_saida = 1;
                        break;
                    }
                }
            }
        }

        if(sem_saida)
            break;
    }
    //escreve
    write_in_file(fileOut, imagem_rotulada);
    //print
    stack_print(st);
    printf("\n\n\n");
    printf("************************\n");
    if(sem_saida)
    {
        printf("\t\t Labirinto sem saida\n");
    }
    matriz_print(imagem_rotulada);
    printf("\n\n************************\n");
    printf("\n\n\n");

    matriz_free(img); //libera
    matriz_free(imagem_rotulada); //libera
    stack_free(st); //libera pilha
    return SUCCESS;
}


//OTHERS FUNC
int dimen_file_mat(char *fileIn, int *linha, int *coluna)
{
    //*****************************************************
    FILE *f;
    int nLin = 0, nCol = 0,val = 0, elem = 0, fileType = 0;
    char cCurrent, cAnt;
    //*****************************************************
    fileType = identify_type_file(fileIn);

    switch(fileType)
    {
    //Verifica se é 1
    case 1:
        f = fopen (fileIn, "r");
        //verifica se o arquivo foi aberto
        if(f == NULL)
        {
            return FAIL_OPEN_FILEIN;
        }
        //Percorrendo matriz do arquivo para calcular sua dimensao
        fscanf(f, "%d%c", &val, &cCurrent);
        elem++;

        while(1)
        {
            //anterior recebe o atual
            cAnt = cCurrent;
            elem++;

            fscanf(f, "%d", &val);
            if(feof(f))
            {
                break;
            }
            fscanf(f, "%c", &cCurrent);
            if(feof(f))
            {
                break;
            }
            if(cCurrent == '\n')
            {
                nLin++;
            }
        }

        elem++;//Pra compensar o lado onde o feof para antes de ler o ultimo elemento da matriz;

        if(feof(f))//Verifica se há "\n" se nao houver conta mais uma linha.
        {
            if(cAnt != '\n')
                nLin++;
        }

        nCol = elem / nLin;

        *linha = nLin;
        *coluna = nCol;
        fclose(f);
        return SUCCESS;
    //verifica se é 2
    case 2:
        f = fopen(fileIn, "rb");
        if(f == NULL)
        {
            return FAIL_OPEN_FILEIN;
        }
        fread(&linha, sizeof(int), 1, f);
        fread(&coluna, sizeof(int), 1, f);

        fclose(f);
        return SUCCESS;

    default:
        return INVALID_FILE_FORMAT;
    }

}

//verifica se é para escrever normal ou em binário
int write_in_file(char *fileOut, Matriz *m)
{
    FILE *f;
    int nLin, nCol;
    int val;
    int fileType = 0;

    //captura linha//coluna
    matriz_get_lin_col(m, &nLin, &nCol);

    fileType = identify_type_file(fileOut);

    switch(fileType)
    {
    case 1: //no caso de arquivo
        f = fopen(fileOut, "w");
        if(f == NULL)
        {
            return FAIL_OPEN_FILEOUT;
        }
        //Escreve matriz da TAD no arquivo
        for(int i = 0; i < nLin; i++)
        {
            for(int j = 0; j < nCol; j++)
            {
                matriz_select(m, i, j, &val);
                fprintf(f, "%d", val);
                if(j == nCol-1)
                {
                    fprintf(f, "\n");
                }
                else
                {
                    fprintf(f, " ");
                }
            }
        }
        fclose(f);
        return SUCCESS;

    case 2: //no caso de binário
        f = fopen(fileOut, "wb");
        if(f == NULL)
        {
            return FAIL_OPEN_FILEOUT;
        }
        // linha e coluna para conseguir ler
        fwrite(&nLin, sizeof(int), 1, f);
        fwrite(&nCol, sizeof(int), 1, f);

        for(int i = 0; i < nLin; i++)
        {
            for(int j = 0; j < nCol; j++)
            {
                matriz_select(m, i, j, &val); //matriz-linha-coluna
                fwrite(&val, sizeof(int), 1, f);
            }
        }
        fclose(f);
        return SUCCESS;

    default:
        return INVALID_FILE_FORMAT;
    }
}

int open_file(char *fileIn, Matriz **m)
{
    FILE *f;
    int nLin = 0, nCol = 0;
    int val = 0;
    int fileType = 0;

    fileType = identify_type_file(fileIn);

    switch(fileType)
    {
    case 1://Caso de arquivo ser .txt
        //captura dimensão da matriz
        if(dimen_file_mat(fileIn, &nLin, &nCol) != 1)
        {
            return FAIL_OPEN_FILEIN;
        }

        *m = matriz_create(nLin, nCol);

        f = fopen (fileIn, "r");
        //verifica arquivo
        if(f == NULL)
        {
            return FAIL_OPEN_FILEIN;
        }
        for(int i = 0; i < nLin; i++)
        {
            for(int j = 0; j < nCol; j++)
            {
                fscanf(f, "%d", &val);
                matriz_insert(*m, i, j, val);
            }
        }

        fclose(f);
        return SUCCESS;

    case 2://Se o arquivo for .imm
        f = fopen(fileIn, "rb");
        if(f == NULL)
        {
            return FAIL_OPEN_FILEIN;
        }

        fread(&nLin, sizeof(int), 1, f);//numero de linhas
        fread(&nCol, sizeof(int), 1, f);//numero de colunas

        *m = matriz_create(nLin, nCol);

        //Pega matriz do arquivo e coloca na TAD
        for(int i = 0; i < nLin; i++)
        {
            for(int j = 0; j < nCol; j++)
            {
                fread(&val, sizeof(int), 1, f);
                matriz_insert(*m, i, j, val); //inserção
            }
        }

        fclose(f);
        return SUCCESS;

    default://Caso de formato desconhecido
        return INVALID_FILE_FORMAT;

    }
}

//verifica qual o tipo do arquivo
int identify_type_file(char *fileIn)
{
    int i = strlen(fileIn);

    //se for arquivo txt retorna 1
    if(fileIn[i-4] == '.' && fileIn[i-3] == 't' && fileIn[i-2] == 'x' && fileIn[i-1] == 't')
    {
        return 1;
    }
    else
    {
        //se for arquivo imm retorna 2
        if(fileIn[i-4] == '.' && fileIn[i-3] == 'i' && fileIn[i-2] == 'm' && fileIn[i-1] == 'm')
        {
            return 2;
        }

        return 0;
    }
}


//mostra o erro
//formato de mensagem
void mensagem_erro(int n)
{
    switch(n)
    {
    case COMMAND_INVALID:
        printf("\nErro: Comando inválido.\n");
        break;

    case INVALID_FILE_FORMAT:
        printf("\nErro: Formato inválido, tente o formato correto.\n");
        break;

    case FAIL_OPEN_FILEIN:
        printf("\nErro: Não foi possível abrir arquivo de entrada.\n");
        break;

    case FAIL_OPEN_FILEOUT:
        printf("\nErro: Não foi possível abrir arquivo de saída.\n");
        break;

    case ERRO_TAD_MAT:
        printf("\nErro: Erro na alocação da matriz.\n");
        break;

    case ERRO_TAD_FILLMAT:
        printf("\nErro: Fill em Matriz com 0 falhou.\n");

    case FAIL_MAZE_NOTFINAL:
        printf("\nErro: Fim do labirinto/não encontrado.\n");
        break;

    case ERRO_MAZEFUNC:
        printf("\nErro: Falha na alocação de pilha.\n");
        break;

    default:
        printf("\nErro: Natureza desconhecida.\n");
    }

}
