#include<stdio.h>
#include<stdlib.h>
#include"aluno.h"

struct aluno{
    char nome[20];
    int idade;
    long int matricula;

};

Aluno*aloca_aluno(void){
    Aluno*aluno = (Aluno*) malloc(sizeof(Aluno));
    if (aluno==NULL){
        printf("No memory!");
        exit(1);
    }
    else{
        printf("Aluno alocado!\n");
    }
    return aluno;

}

void preenche_aluno(Aluno*aluno){
    printf("Informe o nome:\n");
    scanf("%[^\n]", aluno->nome);
    printf("Informe a idade e matricula:\n");
    scanf("%d %ld", &aluno->idade, &aluno->matricula);
}

void imprime(Aluno*aluno){
    printf("Nome:%s \n Idade:%d \n Matricula:%ld", aluno->nome, aluno->idade, aluno->matricula);
}

int main(void){
    Aluno*aluno = (Aluno*) malloc(sizeof(Aluno));
    if (aluno==NULL){ exit(1);}
    preenche_aluno(aluno);
    imprime(aluno);
    return 0;
}