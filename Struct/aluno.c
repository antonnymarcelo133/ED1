#include<stdio.h>
#include<stdlib.h>

typedef struct aluno{
    char nome[20];
    int idade;
    long int matricula;

}Aluno;

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