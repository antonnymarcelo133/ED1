#include <stdio.h>
#include <stdlib.h>
#include "aluno.c"

int main(void){
    Aluno*aluno = (Aluno*) malloc(sizeof(Aluno));
    if (aluno==NULL){ exit(1);}
    preenche_aluno(aluno);
    imprime(aluno);
    return 0;
}