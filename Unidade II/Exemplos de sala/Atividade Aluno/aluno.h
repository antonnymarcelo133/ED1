
/* Arquivo cabeçalho para tipo abstrato de dados(TADs) Aluno*/
typedef struct aluno Aluno;

/*Função que aloca dinamicamente uma struct aluno na memoria*/
Aluno*aloca_aluno(void);

/*Função para preencher struct Aluno. A função recebe um endereço para aluno.*/
void preenche_aluno(Aluno*aluno);

/*Função para imprimir strcut Aluno. A função recebe um endereço para aluno e imprime os dados*/
void imprime(Aluno*aluno);