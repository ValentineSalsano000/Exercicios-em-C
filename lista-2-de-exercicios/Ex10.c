/* Escreva um programa que peça 5 números diferentes e salve-os em um vetor. 
Não repita nenhum número. 
Em seguida pergunte pro usuário qual valor ele quer buscar. 
Use uma função para implementar a busca: se o número buscado estiver presente retorne a posição que ele está, 
caso contrário retorne -1. 
Em seguida imprima "O número ____ encontra-se presente no indice ___ do vetor" ou "O numero ___ não está presente no vetor". 
	Exemplo: Se digitar 2 5 3 6 4  
		   ao pedir para buscar o número 5 irá imprimir "O numero 5 encontra-se no indice 1 do vetor"*/

#include <stdio.h>

#define TAMANHO 5

//função de busca
int buscar_valor(int lista[], int n, int valor_buscado) {
    for (int i = 0; i < n; i++) {
        if (lista[i] == valor_buscado) {
            return i;
        }
    }
    return -1; 
}


//função principal
int main() {
    int vetor[TAMANHO];
    int numero_digitado;
    int valor_buscado;
    int indice_encontrado;
    int repetido; 

    printf("--- Programa de Busca em Vetor ---\n");
    printf("Por favor, digite %d numeros diferentes.\n", TAMANHO);

    //leitura e validação dos numeros
    for (int i = 0; i < TAMANHO; i++) {
        do {
            //falso = 0, assumindo que o numero não esta se repetindo
            repetido = 0; 
            
            printf("Digite o %do numero: ", i + 1);
            scanf("%d", &numero_digitado);
            
            //verifica se o numero digitado ja existe nas posicoes anteriores (j < i)
            for (int j = 0; j < i; j++) {
                if (vetor[j] == numero_digitado) {
                    //verdadeiro = 1, o numero se repete
                    repetido = 1; 
                    printf("ERRO! O numero %d ja foi digitado. Tente outro.\n", numero_digitado);
                    break;
                }
            }
            
        //o while(repetido) e o mesmo que while(repetido != 0)
        } while (repetido); 

        //salva o numero, pois nao houve repeticao
        vetor[i] = numero_digitado;
    }

    printf("\n--- BUSCA ---\n");
    printf("Digite o valor que deseja buscar no vetor: ");
    scanf("%d", &valor_buscado);

    //chama a função e o resultado é salvo em indice_encontrado
    indice_encontrado = buscar_valor(vetor, TAMANHO, valor_buscado);

    if (indice_encontrado != -1) {
        printf("\nO numero %d encontra-se presente no indice %d do vetor.\n", 
               valor_buscado, indice_encontrado);
    } else {
        printf("\nO numero %d nao esta presente no vetor.\n", valor_buscado);
    }

    return 0;
}