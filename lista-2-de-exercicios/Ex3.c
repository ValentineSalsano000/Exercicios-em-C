/*
Escreva uma função que receba dois números inteiros positivos a e b como parâmetro 
e determine se eles são amigos ou não, 
devolvendo True caso sejam amigos e False caso contrário.
Dois números são amigos se cada número é igual à soma dos divisores próprios do outro 
(Os divisores próprios de um número m são os divisores estritamente menores que m).
Por exemplo, os divisores próprios de 220 são 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 e 110, cuja soma é 284; 
e os divisores próprios de 284 são 1, 2, 4, 71 e 142, cuja soma é 220.
 Logo, 220 e 284 são números amigos.
*/

#include <stdio.h>

//retorna 1(verdadeiro) se forem amigos e 0(falso)
int sao_amigos(int a, int b){

    //verificando se os numeros sao positivos e diferentes
if (a <= 0 || b <= 0 || a == b) {
        return 0; // Se a for 0 ou igual A e B, retorna falso
    }

//calculando a soma dos divisores de A
long int soma_divisores_a = 0;

// O laço vai de 1 até a metade de A (A/2)
// O i representa o divisor que estamos testando

for (int i = 1; i <= a / 2; i++) {
        // Se o resto da divisão de A por i for 0, significa que i divide A
        if (a % i == 0) {
            soma_divisores_a = soma_divisores_a + i; // Adiciona o divisor a soma
        }
    }

    // calculando a soma dos divisores de B
    long int soma_divisores_b = 0;
    
    // O laço vai de 1 até a metade de B (B/2)
    for (int i = 1; i <= b / 2; i++) {
        // Se o resto da divisão de B por i for 0, significa que i divide B
        if (b % i == 0) {
            soma_divisores_b = soma_divisores_b + i; // Adiciona o divisor à soma.
        }
    }

    //A soma dos divisores de A deve ser igual a B
    //A soma dos divisores de B deve ser igual a A
    if (soma_divisores_a == b && soma_divisores_b == a) {
        return 1; //Retorna 1 se a condição for verdadeira
    } else {
        return 0; //retorna 0 caso falso
    }
}


//função principal
int main() {
    int num1 = 220;
    int num2 = 284;

    printf("Verificando se %d e %d sao amigos...\n", num1, num2);

    // chamamos a funcao sao_amigos
    if (sao_amigos(num1, num2) == 1) { // se o resultado for 1 verdadeiro
        printf("Resultado: SIM! Eles SAO numeros amigos.\n");
    } else { // se o resultado for 0 falso
        printf("Resultado: NAO! Eles NAO sao numeros amigos.\n");
    }

    return 0;
}