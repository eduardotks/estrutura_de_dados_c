#ifndef ALUNO_H_INCLUDED
#define ALUNO_H_INCLUDED


struct aluno
{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct aluno Aluno;

#endif // ALUNO_H_INCLUDED
