/*
Analise o código abaixo. 
Explique o que são as structs. 
Em seguida escreva uma código na função principal 
que inicialize uma variável do tipo struct ficha aluno, 
preencha todos os campos desse aluno e em seguida imprima todos os dados. 

struct data {
   int dia;
   int mes;
   int ano;   };
struct ficha_aluno {
   char nome[30];
   char endereco[100];
   struct data nascimento;					}
*/

#include <stdio.h>
#include <string.h>//funcao strcpy()

//definindo a struct para a data
struct data {
int dia;
int mes;
int ano;
};

//definindo a struct pincipal ficha_aluno
struct ficha_aluno {
char nome[30];
char endereco[100];
struct data nascimento; 
};

//função principal
int main() {
    //declaracao da Variavel:
    //declaramos uma variavel 'aluno1' que usa o molde 'struct ficha_aluno'
    struct ficha_aluno aluno1;

    //preenchimento dos Campos:

    //nome e endereço
    strcpy(aluno1.nome, "Maria Silva");
    strcpy(aluno1.endereco, "Rua das Flores, 123 - Centro");

    //nascimento
    //para acessar o 'dia', primeiro acessamos o campo 'nascimento' da struct principal,
    // e depois o campo 'dia' da struct 'data'
    aluno1.nascimento.dia = 15;
    aluno1.nascimento.mes = 6;
    aluno1.nascimento.ano = 2005;

    //impressão dos dados

    printf("--- Ficha do Aluno ---\n");
    printf("Nome: %s\n", aluno1.nome);
    printf("Endereco: %s\n", aluno1.endereco);
    
    //imprime a data completa
    printf("Data de Nascimento: %d/%d/%d\n", 
           aluno1.nascimento.dia, 
           aluno1.nascimento.mes, 
           aluno1.nascimento.ano);

    return 0;
}