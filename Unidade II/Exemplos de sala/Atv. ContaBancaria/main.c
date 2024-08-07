#include<stdio.h>
#include"contabancaria.h"

int main(void){
    ContaBancaria * conta = cria_conta("Maria", 1000.00, 23455);
    Deposita(conta, 2500.00);
    Sacar(conta, 3000.00);
    return 0;
}