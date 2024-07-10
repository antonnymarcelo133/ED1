#include <stdio.h>
#include <stdlib.h>

int main(void){
int tamanho;
printf("Informe o tamanho do vetor: \t");
scanf("%d",&tamanho);
int * vetor = (int*) malloc(tamanho*sizeof(int));
if(vetor==NULL){
    printf("No Memory");
    exit(1);
}
else{
    printf("Vetor alocado com sucesso! \n");
}

printf("Digitar os elementos do vetor: \n ");
for(int count=0; count<tamanho; count++){
    scanf("%d", &vetor[count]);
}
printf("Vetor inverso: \n");
for(int count=tamanho-1; count>=0; count++){
    printf("%d \t", vetor[count]);
}
free(vetor);

    return(0);
}