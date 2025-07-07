#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100
#define ARQUIVO_PRODUTOS "produtos.txt"
#define ARQUIVO_USUARIOS "usuarios.txt"

typedef struct {
    char nome[50];
    float preco;
    int estoque;
    int promocao; // 0 ou 1
} Produto;

typedef struct {
    char nome[50];
    char senha[20];
    char email[80];
} Usuario;

void salvarProduto(Produto p) {
    FILE *fp = fopen(ARQUIVO_PRODUTOS, "a");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo de produtos.\n");
        return;
    }
    fprintf(fp, "%s|%.2f|%d|%d\n", p.nome, p.preco, p.estoque, p.promocao);
    fclose(fp);
}

void salvarUsuario(Usuario u) {
    FILE *fp = fopen(ARQUIVO_USUARIOS, "a");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo de usuários.\n");
        return;
    }
    fprintf(fp, "%s|%s|%s\n", u.nome, u.senha, u.email);
    fclose(fp);
}

int emailValido(char email[]) {
    if (strlen(email) >= 80) return 0;
    if (strchr(email, '@') == NULL) return 0;

    FILE *fp = fopen(ARQUIVO_USUARIOS, "r");
    char linha[150];
    while (fgets(linha, sizeof(linha), fp)) {
        char *token = strtok(linha, "|");
        token = strtok(NULL, "|"); // senha
        token = strtok(NULL, "\n"); // email
        if (strcmp(token, email) == 0) {
            fclose(fp);
            return 0; // já existe
        }
    }
    fclose(fp);
    return 1;
}

void cadastrarUsuario() {
    Usuario u;
    printf("Digite seu e-mail: ");
    scanf(" %[^\n]", u.email);
    if (!emailValido(u.email)) {
        printf("E-mail inválido ou já cadastrado.\n");
        return;
    }
    printf("Digite um nome de usuário: ");
    scanf(" %[^\n]", u.nome);
    printf("Digite uma senha: ");
    scanf(" %[^\n]", u.senha);
    salvarUsuario(u);
    printf("Usuário cadastrado com sucesso!\n\n");
}

int login() {
    char nome[50], senha[20], linha[150];
    printf("Usuário: ");
    scanf(" %[^\n]", nome);
    printf("Senha: ");
    scanf(" %[^\n]", senha);

    FILE *fp = fopen(ARQUIVO_USUARIOS, "r");
    if (fp == NULL) {
        printf("Arquivo de usuários não encontrado.\n");
        return 0;
    }

    while (fgets(linha, sizeof(linha), fp)) {
        char *usuario = strtok(linha, "|");
        char *sen = strtok(NULL, "|");
        if (strcmp(nome, usuario) == 0 && strcmp(senha, sen) == 0) {
            fclose(fp);
            printf("\n🎉 Bem-vindo ao sistema de Loja Virtual, %s!\n\n", nome);
            return 1;
        }
    }
    fclose(fp);
    printf("Login incorreto.\n\n");
    return 0;
}

void cadastrarProduto() {
    Produto p;
    printf("Nome do produto: ");
    scanf(" %[^\n]", p.nome);
    printf("Preço: ");
    scanf("%f", &p.preco);
    printf("Estoque: ");
    scanf("%d", &p.estoque);
    printf("Está em promoção? (1=Sim, 0=Não): ");
    scanf("%d", &p.promocao);
    salvarProduto(p);
    printf("Produto cadastrado!\n\n");
}

void listarProdutos() {
    FILE *fp = fopen(ARQUIVO_PRODUTOS, "r");
    Produto p;
    char linha[150];
    int i = 1;

    if (fp == NULL) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    while (fgets(linha, sizeof(linha), fp)) {
        sscanf(linha, " %[^|]|%f|%d|%d", p.nome, &p.preco, &p.estoque, &p.promocao);
        printf("%d. %s - R$ %.2f - Estoque: %d - Promoção: %s\n",
               i++, p.nome, p.preco, p.estoque, p.promocao ? "Sim" : "Não");
    }
    fclose(fp);
}

void listarPromocoes() {
    FILE *fp = fopen(ARQUIVO_PRODUTOS, "r");
    Produto p;
    char linha[150];

    printf("\nProdutos em promoção:\n");

    while (fgets(linha, sizeof(linha), fp)) {
        sscanf(linha, " %[^|]|%f|%d|%d", p.nome, &p.preco, &p.estoque, &p.promocao);
        if (p.promocao)
            printf("%s - R$ %.2f\n", p.nome, p.preco);
    }
    fclose(fp);
}

void buscarProduto() {
    char termo[50];
    printf("Digite o nome para buscar: ");
    scanf(" %[^\n]", termo);

    FILE *fp = fopen(ARQUIVO_PRODUTOS, "r");
    Produto p;
    char linha[150];

    while (fgets(linha, sizeof(linha), fp)) {
        sscanf(linha, " %[^|]|%f|%d|%d", p.nome, &p.preco, &p.estoque, &p.promocao);
        if (strstr(p.nome, termo)) {
            printf("%s - R$ %.2f - Estoque: %d\n", p.nome, p.preco, p.estoque);
        }
    }
    fclose(fp);
}

void contarProdutos() {
    FILE *fp = fopen(ARQUIVO_PRODUTOS, "r");
    int total = 0;
    char linha[150];
    while (fgets(linha, sizeof(linha), fp)) total++;
    fclose(fp);
    printf("Total de produtos: %d\n", total);
}

void estoqueBaixo() {
    FILE *fp = fopen(ARQUIVO_PRODUTOS, "r");
    Produto p;
    char linha[150];

    printf("Produtos com estoque baixo:\n");
    while (fgets(linha, sizeof(linha), fp)) {
        sscanf(linha, " %[^|]|%f|%d|%d", p.nome, &p.preco, &p.estoque, &p.promocao);
        if (p.estoque < 5)
            printf("%s - Estoque: %d\n", p.nome, p.estoque);
    }
    fclose(fp);
}

// Menu principal
void menu() {
    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Produtos em Promoção\n");
        printf("4. Buscar Produto\n");
        printf("5. Total de Produtos\n");
        printf("6. Produtos com Estoque Baixo\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: cadastrarProduto(); break;
            case 2: listarProdutos(); break;
            case 3: listarPromocoes(); break;
            case 4: buscarProduto(); break;
            case 5: contarProdutos(); break;
            case 6: estoqueBaixo(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida!\n");
        }

    } while (opcao != 0);
}

int main() {
    printf("=== Sistema de Loja Virtual ===\n");

    FILE *fp = fopen(ARQUIVO_USUARIOS, "r");
    if (fp == NULL) {
        printf("Nenhum usuário encontrado. Faça o cadastro inicial:\n");
        cadastrarUsuario();
    } else {
        fclose(fp);
    }

    while (!login()) {
        printf("Tente novamente...\n");
    }

    menu();
    return 0;
}
