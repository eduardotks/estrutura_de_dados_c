#ifndef TFILE_H_INCLUDED
#define TFILE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TMatriz.h"
#include "TStack.h"
#include "Point.h"

#define SUCCESS 1
#define COMMAND_INVALID -1
#define INVALID_FILE_FORMAT -2
#define FAIL_OPEN_FILEIN -3
#define FAIL_OPEN_FILEOUT -4
#define ERRO_TAD_MAT -5
#define ERRO_TAD_FILLMAT -6
#define FAIL_MAZE_NOTFINAL -7
#define ERRO_MAZEFUNC -8

//Abre uma imagem txt e printa na tela
int print_file(char *fileIn);

//Converte file.txt para file.imm
int convert(char *fileIn, char *fileOut);// -open

//Faz o thresholding (limiarização da imagem) com um valor thres(limiar) da imagem file.imm
//e escreve o resultado em segfile.imm
int segment(int limiar, char *fileIn, char *fileOut);

//Detecta os componentes de uma imagem e rotula no arquivo de saída
int componente(char *fileIn, char *fileOut);

//Mostra o caminho do labirinto em no arquivo de saída
int maze(char *fileIn, char *fileOut);

//OTHERS FUNCT
//Escreve no arquivo de saída(.txt ou .imm)
int write_in_file(char *fileOut, Matriz *m);

//Calcula dimensão da matriz de um arquivo(.txt ou .imm)
int dimen_file_mat(char *fileIn, int *linha, int *coluna);

//Abre um arquivo e poe na Matriz m (.txt ou .imm)
int open_file(char *fileIn, Matriz **m);

//Identifica o tipo do arquivo. Retornando 1, 2 ou 0 dependendo do arquivo
int identify_type_file(char *fileIn);

#endif
