/*
Repita o exercício anterior, porém permita que o usuário digite mais de uma vez o mesmo número. 
Busque todas as posições que contenha o número.
Exemplo: Se digitar 2 5 2 6 2 deverá imprimir
	"O número 2 encontra-se no(s) índice(s) 0, 2, 4 do vetor"

*/

#include <stdio.h>

#define TAMANHO 5
#define MAX_POSICOES TAMANHO //o vetor e posições tem no maximmo 5 vetores

//funçao de busca para todas as posicoes

//retorna o total de vezes que o valor foi encontrado
int buscar_todas_posicoes(int lista[], int n, int valor_buscado, int *posicoes_encontradas) {
    int contador = 0; //conta quantas vezes o valor aparece
    
    //o laço DEVE percorrer o vetor INTEIRO, do início ao fim
    for (int i = 0; i < n; i++) {
        //se o elemento atual for igual ao valor que buscamos...
        if (lista[i] == valor_buscado) {
            //...salvamos o índice (i) no nosso vetor de posições (usando o contador como índice)
            posicoes_encontradas[contador] = i; 
            
            //e incrementamos o contador, pois encontramos mais uma ocorrência
            contador++; 
        }
    }
    
    //retornamos a quantidade total de vezes que o valor foi encontrado
    return contador;
}


//função principal
int main() {
    int vetor[TAMANHO];
    int valor_buscado;
    //criamos um novo vetor para guardar os índices que a função encontrar
    int indices_salvos[MAX_POSICOES]; 
    int total_de_vezes;

    printf("--- Programa de Busca de Multiplas Ocorrencias ---\n");
    
    //leitura simples dos numeros
    printf("Por favor, digite uma sequencia de %d numeros:\n", TAMANHO);
    for (int i = 0; i < TAMANHO; i++) {
        printf("Digite o %do numero: ", i + 1);
        scanf("%d", &vetor[i]); 
    }

    printf("\n--- BUSCA ---\n");
    printf("Digite o valor que deseja buscar no vetor: ");
    scanf("%d", &valor_buscado);

    //chamada da funçao e salvamento do resultado
    
    //chamamos a função, passando o vetor de índices como 'referência' (ponteiro)
    //o nome do vetor 'indices_salvos' ja é um ponteiro, por isso não usamos o '&'
    total_de_vezes = buscar_todas_posicoes(vetor, TAMANHO, valor_buscado, indices_salvos);

    //impressao do resultado
    
    if (total_de_vezes > 0) {
        //se o número foi encontrado pelo menos uma vez...
        
        printf("\nO numero %d encontra-se presente no(s) indice(s) ", valor_buscado);
        
        //laço para imprimir todos os índices salvos no vetor 'indices_salvos'
        for (int i = 0; i < total_de_vezes; i++) {
            printf("%d", indices_salvos[i]);
            
            //logica para imprimir a vírgula e o espaço, exceto no último número
            if (i < total_de_vezes - 1) {
                printf(", ");
            }
        }
        printf(" do vetor.\n");

    } else {
        //se a função retornou 0 ocorrências
        printf("\nO numero %d nao esta presente no vetor.\n", valor_buscado);
    }

    return 0;
}