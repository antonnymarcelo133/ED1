#include <stdio.h>
#include <stdlib.h>

int main(void){
    int linhas, colunas;
    printf("Informe a quantidade de linhas e colunas: \n");
    scanf("%d %d", &linhas, &colunas);
    
    int ** matriz = (int**) malloc(colunas*sizeof(int*));
    if(matriz == NULL){
        exit(1);
    }
    for(int count=0; count<linhas; count++ ){
        matriz[count] = (int*) malloc(colunas*sizeof(int));
        if(matriz[count] == NULL){
            exit(1);
        }

    }
    printf("Informe os elementos: \n");
    int linha, coluna;
    for(linha=0; linha<linhas; linha++ ){
        for(coluna=0; coluna<colunas; coluna++){
            scanf("%d", &matriz[linha] [coluna]);
        }
    }
        for(linha=0; linha<linhas; linha++ ){
            printf("\n");
        for(coluna=0; coluna<colunas; coluna++){
            printf("%d\t", matriz[linha] [coluna]);
        }
    }
    printf("Matriz transposta:\n");
            for(linha=0; linha<linhas; linha++ ){
            printf("\n");
        for(coluna=0; coluna<colunas; coluna++){
            printf("%d\t", matriz[coluna] [linha]);
        }
    }
    for(linha=0; linha<linhas; linha++){
        free(matriz[linha]);

    }
    return(0);
}