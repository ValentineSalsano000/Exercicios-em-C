/*
4. Escreva uma função que receba uma vetor de números reais 
e devolva a média aritmética dos números da lista. 
Escreva também código da main que testa sua função.
*/


#include <stdio.h>

float calcular_media(float lista[], int tamanho) {
    float soma = 0.0; // a soma fica uardada aqui e inicia em 0

    // Laço de Repetição, começa em 0 e vai ate o numero que o vetor tem
    for (int i = 0; i < tamanho; i++) {
        soma = soma + lista[i]; 
        // pega o numero do vetor, que seria lista[i] e soma com o total
    }

    // o calculo da média é a soma dividida pela quantidade de elementos
    return soma / tamanho;
}


//função principal
int main() {
    // vetor de números reais com 5 notas
    float notas[] = { 7.5, 8.0, 6.5, 9.0, 7.0 }; 

    // Calcula o tamanho do vetor.
    // A divisão dá o número total de elementos.
    int num_elementos = sizeof(notas) / sizeof(notas[0]);
    
    // Declara uma variável para guardar o resultado.
    float media_final;

    // chama se a função e passa se o nome do vetor (notas) e o número de elementos
    // O nome do vetor 'notas' é o que se chama de passagem por referência
    media_final = calcular_media(notas, num_elementos);

    // Imprime o resultado formatado com 2 casas decimais.
    printf("O vetor tem %d notas.\n", num_elementos);
    printf("A media aritmetica das notas e: %.2f\n", media_final);

    return 0;
}