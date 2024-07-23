#include <stdio.h>
#include <stdlib.h>

/*intrudução do comando union.*/
union tipos{
    int inteiro;
    float real;
    char letra;
};
/*renomeando union tipos para Tipos em maiúsculo*/
typedef union tipos Tipos;

int main(void){
    Tipos variavel;
    variavel.inteiro=2;
    printf("%d, %f, %c \n", variavel.inteiro, variavel.real, variavel.letra);
    variavel.real= 2.5;
    variavel.letra = 's';
    printf(" %d, %f, %c", variavel.inteiro, variavel.real, variavel.letra );

    return 0;
}