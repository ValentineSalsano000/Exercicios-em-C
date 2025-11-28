/*
Escreva um programa que leia dois vetores de n e m valores inteiros, 
onde n<=m, e imprima quantas vezes a primeira sequência ocorre na segunda.
 Escreva também código da main que testa sua função.
*/

#include <stdio.h>

//a fncao verifica quantas vezes a sequencia MENOR aparece na MAIOR
int contar_ocorrencias(int vetor_menor[], int tamanho_n, int vetor_maior[], int tamanho_m) {
    
    //se a sequencia buscada for maior que o vetor principal, é impossivel achar
    if (tamanho_n > tamanho_m) {
        return 0;
    }

    int total_encontrado = 0; //conta quantas vezes achamos a sequencia

    //o laco Externo (i) controla onde a busca começa no vetor MAIOR
    for (int i = 0; i <= tamanho_m - tamanho_n; i++) {
        
        //a sequencia comeca assumindo que bate(1=verdadeiro)
        int sequencia_bate = 1; 
        
        //verifica elemento por elemento
        // Ele so roda o tamanho da sequencia que estamos buscando
        for (int j = 0; j < tamanho_n; j++) {
            
            // Compara os elementos
            if (vetor_maior[i + j] != vetor_menor[j]) {
                sequencia_bate = 0; //se um elemento nao for igual, marca como falso
                break;              //para a verificacao interna, pois ja sabemos que nao bate
            }
        }

        //se a sequencia_bate ainda for 1 (Verdadeiro) apos o laco interno, achamos uma ocorrencia
        if (sequencia_bate == 1) {
            total_encontrado++;
        }
    }

    return total_encontrado;
}

//funçao principal
int main() {
    //vetor N (buscado) a sequencia que queremos contar
    int vetor_n[] = { 1, 2 }; 
    int n = 2; //tamanho de N

    // Vetor M (principal): o vetor onde buscaremos
    int vetor_m[] = { 1, 2, 3, 1, 2, 4, 5, 1, 2 }; 
    int m = 9; //tamanho de M
    
    int resultado;

    printf("--- Contagem de Sequencias Simplificada ---\n");
    printf("Sequencia Buscada: {1, 2} \n");
    printf("Vetor Principal: {1, 2, 3, 1, 2, 4, 5, 1, 2} \n");
    
    //chamada da Funcao
    resultado = contar_ocorrencias(vetor_n, n, vetor_m, m);

    //impressao do Resultado
    printf("\nA sequencia {1, 2} ocorre %d vez(es) no vetor maior.\n", resultado);
    //resultado esperado: 3

    return 0;
}