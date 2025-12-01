/*
Ainda em relação ao código do exercício 14: 
crie um vetor de 10 alunos, inicialmente zerados.
 Preencha apenas o ano de nascimento de todos eles. 
 Em seguida calcule a média de idade de todos 
 e imprima esse resultado (sabendo que 


*/

#include <stdio.h>

#define NUM_ALUNOS 10
#define ANO_ATUAL 2025 //ano de referencia fixo

//definicao da struct 'data'
typedef struct data {
int dia;
int mes;
int ano;
} Data; 

//dfinicao da struct principal
typedef struct ficha_aluno {
char nome[30];
char endereco[100];
Data nascimento;
} FichaAluno; 

//função principal
int main() {
    
    //criando e inicializando o vetor de structs com os dados
    //inicializamos o vetor com 10 entradas, preenchendo APENAS o ano (o resto e zerado)
    //o nome e endereco serao strings vazias e dia/mes serao 0
    FichaAluno vetor_alunos[NUM_ALUNOS] = {
        {.nascimento.ano = 2000}, // Aluno 1
        {.nascimento.ano = 2001}, // Aluno 2
        {.nascimento.ano = 2002}, // Aluno 3
        {.nascimento.ano = 2003}, // Aluno 4
        {.nascimento.ano = 2004}, // Aluno 5
        {.nascimento.ano = 2005}, // Aluno 6
        {.nascimento.ano = 2006}, // Aluno 7
        {.nascimento.ano = 2007}, // Aluno 8
        {.nascimento.ano = 2008}, // Aluno 9
        {.nascimento.ano = 2009}  // Aluno 10
    };
    
    int soma_idades = 0;
    
    printf("--- Calculo da Media de Idade ---\n");
    printf("Anos de Referencia: %d\n", ANO_ATUAL);

    //calculo da media de idade
    for (int i = 0; i < NUM_ALUNOS; i++) {
        
        int ano_nasc = vetor_alunos[i].nascimento.ano;
        
        //idade = ano atual - ano de Nascimento
        int idade = ANO_ATUAL - ano_nasc;
        
        soma_idades += idade; 
    }
    
    //calculo final e impressao
    //converte a soma para float antes de dividir para ter casas decimais
    float media_idades = (float)soma_idades / NUM_ALUNOS;

    printf("\nSoma total das idades: %d\n", soma_idades);
    printf("A media de idade dos %d alunos e: %.2f anos.\n", NUM_ALUNOS, media_idades);

    return 0;
}