#include<stdlib.h>
#include<stdio.h>

FILE*open_file(char * nome, char * modo){
    FILE*arquivo = fopen(nome, modo);
    if(arquivo==NULL){
        printf("ARQUIVO NAO PODE SER ABERTO!\n");
        exit(1);
    }
    else{
        printf("ARQUIVO ABERTO.\n");
    }
    return arquivo;
}

int main(void){
    FILE*arquivo_de_entrada, *arquivo_de_saida;
    arquivo_de_entrada = open_file("entrada_q3.txt", "r"); //ler o arquivo de entrada
    arquivo_de_saida = open_file("saida_q3.txt", "w"); //cria o arquivo de saida
    char * nome_aluno[20];
    float nota1, nota2, nota3, media;
    //ler os dados dentro de arquivo fgets, fgetc, fscanf, sscanf.

    while(!feof(arquivo_de_entrada)){
        fscanf(arquivo_de_entrada, "%s/t %f/t %f/t %f/t", nome_aluno, &nota1, &nota2, &nota3); //ler os dados do arquivo

        //calcular media
        media = (nota1+nota2+nota3)/3.0;
        //escreve o arquivo de saida
        if(media>=7){
            fprintf(arquivo_de_saida, "%s\t%.1f\tAPROVADO\n", nome_aluno, media);
        }
        else{
            fprintf(arquivo_de_saida, "%s\t%.1f\tREPROVADO\n", nome_aluno, media);
        }
        fclose(arquivo_de_entrada);
        fclose(arquivo_de_saida);
    }
}