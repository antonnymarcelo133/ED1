#include <stdio.h>
#include <stdlib.h>

typedef enum dias_semana {
    SEGUNDA=2,
    TERCA,
    QUARTA,
    QUINTA,
    SEXTA,
    SABADO,
    DOMINGO,
};

int main(void){
enum dias_semana dia;
dia=SEGUNDA;
printf("Informe o dia da semana: 2 a 8\t");
scanf("%d", &dia);
switch(dia){
    case SEGUNDA:
    printf(" Segunda-Feira\n");
    break;

    case TERCA:
    printf(" Terca-Feira\n");
    break;

    case QUARTA:
    printf(" Quarta-Feira\n");
    break;

    case QUINTA:
    printf(" Quinta-Feira\n");
    break;

    case SEXTA:
    printf(" Sexta-Feira\n");
    break;

    case SABADO:
    printf(" Sabado\n");
    break;

    case DOMINGO:
    printf(" Domingo\n");
    break;
    default:

    printf("Dia nao cadastrado!\n");
    break;
}
return 0;
}