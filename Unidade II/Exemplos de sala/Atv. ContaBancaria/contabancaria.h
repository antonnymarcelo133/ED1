typedef struct ContaBancaria ContaBancaria;

/*função que aloca memoria para struct conta e retorna su endereço
para:
char*titular: nome do titular da conta
float saldo: saldo disponivel na conta
int numero: número da conta
*/
ContaBancaria * cria_conta(char*titular, float saldo, int numero);
/*função que simula a opreção de deposito
para:
ContaBancaria*conta: representa conta bancaria
float dinheiro: saldo para ser adicionado a conta
*/
void Deposita(ContaBancaria*conta, float dinheiro);
/*fonção que simula a operação de sacar um valor de uma conta
Paras:
  ContaBancaria*conta: representa  conta bancaria 
  */

void Sacar(ContaBancaria*conta, float valor);


float saldo(ContaBancaria*conta);
