#include<stdio.h>
#include<stdlib.h>
#include "contabancaria.h"
#include<string.h>

struct ContaBancaria{
    char titular[20]; //nome do usuario
    int numero; //numero da conta
    float saldo; //saldo da conta
};
ContaBancaria * cria_conta(char*titular, float saldo, int numero){
    ContaBancaria * conta=(ContaBancaria*) malloc(sizeof(ContaBancaria));
    if(conta==NULL){
        printf("No memory!\n");
        exit(1);
    }
else{
    printf("Conta Alocada:\n");
}
conta->numero=numero;
conta->saldo=saldo;
strcpy(conta->titular, titular);
return conta;
}

void Deposita(ContaBancaria*conta, float dinheiro){
    conta->saldo=conta->saldo+ dinheiro;
    printf("Valor depositado com sucesso.\n Novo saldo:%f", conta->saldo);
}

void Sacar(ContaBancaria*conta, float valor){
    if(conta->saldo>=valor){
        conta->saldo= conta->saldo - valor;
        printf("Valor sacado com sucesso!");
    }
    else{
        printf("O saldo e insuficiente.\n");
    }
}