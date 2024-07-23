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
typedef enum mes{
    JANEIRO=1,
    FEVEREIRO,
    MARCO,
    ABRIL,
    MAIO,
    JUNHO,
    JULHO,
    AGOSTO,
    SETEMBRO,
    OUTUBRO,
    NOVEMBRO,
    DEZEMBRO,
};

int main(void){
enum dias_semana dia;
enum mes mes;
dia=SEGUNDA;
mes=JANEIRO;

printf("Informe o dia da semana de 2 a 8:\t");
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
printf("Informe o mes do ano de 1 a 12:\t");
scanf("%d", &mes);
switch(mes){
    case JANEIRO:
    printf(" Janeiro\n");
    break;

    case FEVEREIRO:
    printf(" Fevereiro\n");
    break;

    case MARCO:
    printf(" Marco\n");
    break;

    case ABRIL:
    printf(" Abril\n");
    break;

    case MAIO:
    printf(" Maio\n");
    break;

    case JUNHO:
    printf(" Junho\n");
    break;

    case JULHO:
    printf(" Julho\n");
    break;

    case AGOSTO:
    printf(" Agosto\n");
    break;

    case SETEMBRO:
    printf(" Setembro\n");
    break;

    case OUTUBRO:
    printf(" Outubro\n");
    break;

    case NOVEMBRO:
    printf(" Novembro\n");
    break;

    case DEZEMBRO:
    printf(" Dezembro\n");
    break;
    default:

    printf("Mes nao cadastrado!\n");
    break;

}
return 0;
}