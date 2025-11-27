#include <stdio.h>

// Função que recebe as REFERÊNCIAS para alterar as variáveis originais
//int n e o tamanho do vetor
//int *min_ptr e o ENDEREÇO da variável 'minimo' da função main
//int *max_ptr e o ENDEREÇO da variável 'maximo' da função main

void CalculaMinimoEMaximo(int lista[], int n, int *min_ptr, int *max_ptr) {
    //o vetor deve ter pelo menos um elemento
    if (n <= 0) {
        return; 
    }

    //minimo e maximo
    int primeiro_elemento = lista[0];

    //com o desreferenciamento (*) mudamos as variaveis da função main
    //e damos a elas o valor inicial do vetor
    *min_ptr = primeiro_elemento; 
    *max_ptr = primeiro_elemento;
    
    // Laço de repetição
    for (int i = 1; i < n; i++) {
        int elemento_atual = lista[i];

        //verificando o MINIMO
        //se o elemento atual for menor que o valor guardado atualmente em *min_ptr,
        //atualizamos o valor de *min_ptr
        if (elemento_atual < *min_ptr) {
            *min_ptr = elemento_atual;
        }

        //verificação o MAXIMO
        //se o elemento atual for maior que o valor guardado atualmente em *max_ptr,
        //atualizamos o valor de *max_ptr
        if (elemento_atual > *max_ptr) {
            *max_ptr = elemento_atual;
        }
    }
}


//função principal
int main() {
    //criando o vetor
    int meu_vetor[] = { 45, 12, 88, 5, 60, 23 }; 

    //criando as variáveis locais 'minimo' e 'maximo', começam zeradas
    int minimo = 0; 
    int maximo = 0; 
    
    //calculo do tamanho do vetor (n)
    int n_elementos = sizeof(meu_vetor) / sizeof(meu_vetor[0]);
    
    printf("Vetor: {45, 12, 88, 5, 60, 23}\n");
    printf("Antes da funcao: Minimo = %d, Maximo = %d\n", minimo, maximo); // 0, 0

    //chamando a função e passando as REFERÊNCIAS
    // o & e para o endereço das variaveis que queremos alterar
    CalculaMinimoEMaximo(meu_vetor, n_elementos, &minimo, &maximo);

    //exibindo os resultados com as variaveis ja alteradas
    printf("Apos a funcao: Minimo = %d, Maximo = %d\n", minimo, maximo);
     // variaveis atuais apos a mudança 5, 88

    return 0;
}