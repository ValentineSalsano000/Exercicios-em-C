/*
 Escreva um programa que peça pro usuário digitar uma sequência de 5 números 
 e salve-a em um vetor. 
 Em seguida multiplique cada elemento do vetor pela posição de seu índice. 
 Imprima o vetor ao final desse processo.
	Ex:  Se digitar 2 3 4 5 6
		deverá gerar um vetor [2 3 4 5 6] 
		que irá virar [0x2 1x3 2x4 3x5 4x6] =  [0 3 8 15 24] e então imprimir esse vetor.


*/

#include <stdio.h>

//definindo  tamanho do vetor
#define TAMANHO 5 

int main() {

    // O vetor numeros guarda 5 numeros inteiros
    int numeros[TAMANHO]; 

    printf("--- Multiplicacao por Posicao ---\n");
    printf("Por favor, digite uma sequencia de %d numeros inteiros:\n", TAMANHO);

    //o laço for é para pedir e guardar cada número
    for (int i = 0; i < TAMANHO; i++) {

        printf("Digite o numero na Posicao %d: ", i + 1); 
        
        // & é o endereco, assim como na passagem por referencia, mas aqui e usado
        // para o scanf saber onde salvar o dado
        scanf("%d", &numeros[i]); 
    }
    
    //imprime o vetor original lido
    printf("\nVetor Original lido: [");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d%s", numeros[i], (i == TAMANHO - 1) ? "" : " ");
    }
    printf("]\n");

    for (int i = 0; i < TAMANHO; i++) {
        //o valor atual (numeros[i]) é substituido pelo
        //seu valor multiplicado pelo indice (i)
        // um ex: na 3a passagem, i=2, numeros[2] = numeros[2] * 2
        numeros[i] = numeros[i] * i;
    }


    //imprimindo o vetor final
    printf("Vetor Final (Elemento * Indice): [");
    for (int i = 0; i < TAMANHO; i++) {
        //imprimindo o elemento alterado
        printf("%d%s", numeros[i], (i == TAMANHO - 1) ? "" : " ");
    }
    printf("]\n");

    return 0;
}