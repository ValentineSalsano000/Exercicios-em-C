/*
 É comum no uso de registros utilizar a chamada typdef. 
 Para que ela serve? 
 Como faríamos para inicializar uma variável do tipo ponto na função principal,
  aproveitando-se da implementação do typedef? 
  Crie um código em C que altere o código do exercício anterior, 
  mas desta vez usando o typedef.
*/

#include <stdio.h>

//definindo a struct para a data com typedef
typedef struct data {
    int dia;
    int mes;
    int ano; 
} Data; 

//definição da Struct 'ficha_aluno' com o apelido 'FichaAluno'
typedef struct ficha_aluno {
    char nome[30];
    char endereco[100];
    Data nascimento; //isa o apelido data
} FichaAluno; 

//função principal
int main() {
    
    // 1. Declaração da Variável (Usando o Typedef):
    // Agora podemos usar 'FichaAluno' diretamente como tipo
    FichaAluno aluno_simples = {
        "Carlos Silva",                        
        "Rua da Paz, 500 - Belo Horizonte",    
        { 5, 10, 2003 }                        
    };
    
    //impressão dos dados
    
    printf("--- Ficha do Aluno Simplificada ---\n");
    printf("Nome: %s\n", aluno_simples.nome);
    printf("Endereco: %s\n", aluno_simples.endereco);
    
    //acessando os campos da struct data aninhada
    printf("Data de Nascimento: %d/%d/%d\n", 
           aluno_simples.nascimento.dia, 
           aluno_simples.nascimento.mes, 
           aluno_simples.nascimento.ano);

    return 0;
}