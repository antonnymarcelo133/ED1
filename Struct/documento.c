#include <stdio.h>
#include <stdlib.h>

/* Exemplo: como usar union e structs.*/

typedef union documentos{
    char cpf[11]; //Formato 00.000.000.00
    long int rg; //Apenas números inteiros

}Documentos;

typedef struct pessoa{
    char nome[20]; //para guardar o nome completo da pessoa
    Documentos documentos; //para guardar o CPF ou RG

}Pessoa;

void preenche_pessoa(Pessoa*pessoa){
    /* Função que preenche a struct pessoa*/
    int opcao_documento;
    printf("Informe o nome: \n");
    scanf(" %[^\n]", pessoa->nome);
    printf("Informe o 1-CPF ou o 2-RG:\n ");
    scanf("%d", &opcao_documento);
    /*switch para dar opção de escolha entre cpf ou rg*/
    switch (opcao_documento){
    case 1 :
        scanf(" %[^\n]", pessoa->documentos.cpf);
    break;

    case 2 :
        scanf("%ld", &pessoa->documentos.rg);
        default:
        printf("Valor valido!\n");
    break;

    }

}
void imprime_pessoa(Pessoa*pessoa){
    printf("Nome: %s\nDocumentos:%s\n",
    pessoa->nome, pessoa->documentos.cpf);

}
 int main(void){
    Pessoa pessoa;
    preenche_pessoa(&pessoa);
    imprime_pessoa(&pessoa);
    return 0;
 }