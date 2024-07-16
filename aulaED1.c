#include<stdio.h>
#include<stdlib.h>

struct aluno{
    int mat, idade;
    char nome[20];
};

void coluna (struct aluno*a){
    printf("Digite a idade e matricula do aluno: \n");
    scanf("%d %d", &a->mat, &a->idade);
    printf("Digite o nome do aluno: \n");
    scanf("[^/n]", &a->nome);
}
void imprime(struct aluno*a){
    printf(" IDADE: %d", a->idade);
    printf("MATRICULA: %d", a->mat);
    printf("NOME: %s", a->nome);
}
int main(void){
    struct aluno*a;
    coluna(&a);
    imprime(&a);
    return 0;
}