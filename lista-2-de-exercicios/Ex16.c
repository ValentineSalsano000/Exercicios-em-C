/*
Analise os códigos abaixo. 
Como a recursão é utilizada no código da esquerda (explique dando exemplo)? 
Pontue a diferença com o código da direit

*/

//com e utilizada a recursão : A cada passo, a função não retorna imediatamente (a menos que encontre o valor ou atinja o caso base). Em vez disso, ela se chama novamente, mas com um intervalo de busca reduzido (metade do anterior)

//Se valor < vetor[meio], a função chama buscaBinariaComLog com o novo intervalo: [inicio, meio - 1] (Busca na Esquerda).

//Se valor > vetor[meio], a função chama buscaBinariaComLog com o novo intervalo: [meio + 1, fim] (Busca na Direita).

//Exemplo de Recursão (Buscando o valor 10):
//A função se chama sequencialmente até encontrar o valor:

//buscaBinariaComLog(V, 0, 8, 10) -> Compara 5 (índice 4). Chama-se com buscaBinariaComLog(V, 5, 8, 10).

//buscaBinariaComLog(V, 5, 8, 10) -> Compara 8 (índice 6). Chama-se com buscaBinariaComLog(V, 7, 8, 10).

//buscaBinariaComLog(V, 7, 8, 10) -> Compara 10 (índice 7). Encontrado, retorna o índice 7.

//Caso Base: O mecanismo de parada (que evita o loop infinito) é a condição if (inicio > fim), onde o intervalo se torna vazio e a função retorna -1.

//Característica,Código da Esquerda (Recursão),Código da Direita (Iteração)
//Mecanismo,A função chama a si mesma repetidamente.,Utiliza um laço de repetição (while ou for) para continuar o processo.
//Memória,Utiliza a Pilha de Chamadas (Call Stack) para armazenar os parâmetros de cada chamada recursiva.,"Utiliza variáveis locais (ex: inicio, fim, meio) que são atualizadas a cada iteração do laço."
//Controle,O fluxo de controle é gerenciado pela sequência de chamadas e retornos de função.,O fluxo de controle é gerenciado pela condição do laço (while (inicio <= fim)).
//Leitura,Geralmente é mais curto e elegante para problemas de divisão e conquista.,Geralmente é considerado mais eficiente em termos de memória (não consome a pilha de chamadas).



#include <stdio.h>


int buscaBinariaComLog(int vetor[], int inicio, int fim, int valor) {
    // Caso base: intervalo vazio
    if (inicio > fim) {
        printf("  -> Intervalo vazio. Elemento NAO encontrado.\n");
        return -1;
    }
    
    // Calcula o índice do meio
    int meio = inicio + (fim - inicio) / 2;
    
    // Exibe a comparação sendo feita
    printf("  Comparacao: vetor[%d] = %d", meio, vetor[meio]);
    
    // Verifica se encontrou
    if (vetor[meio] == valor) {
        printf(" == %d -> ENCONTRADO!\n", valor);
        return meio;
    }
    
    // Busca na metade esquerda
    if (valor < vetor[meio]) {
        printf(" > %d -> Buscar na ESQUERDA [%d..%d]\n", valor, inicio, meio - 1);
        return buscaBinariaComLog(vetor, inicio, meio - 1, valor);
    }
    
    // Busca na metade direita
    printf(" < %d -> Buscar na DIREITA [%d..%d]\n", valor, meio + 1, fim);
    return buscaBinariaComLog(vetor, meio + 1, fim, valor);
}

int main() {
    // Vetor do exercício: [0 2 3 4 5 6 8 10 11]
    int V[] = {0, 2, 3, 4, 5, 6, 8, 10, 11};
    int tamanho = 9;
    int resultado;
    int i;
    
    // Exibe o vetor
    printf("=== Busca Binaria - Sequencia de Comparacoes ===\n\n");
    printf("Vetor V = [");
    for (i = 0; i < tamanho; i++) {
        printf("%d", V[i]);
        if (i < tamanho - 1) printf(" ");
    }
    printf("]\n");
    printf("Indices:  [");
    for (i = 0; i < tamanho; i++) {
        printf("%d", i);
        if (i < tamanho - 1) printf(" ");
    }
    printf("]\n\n");
    
    // === BUSCAR O VALOR 10 ===
    printf("====================================\n");
    printf("BUSCAR O VALOR 10:\n");
    printf("====================================\n");
    resultado = buscaBinariaComLog(V, 0, tamanho - 1, 10);
    printf("Resultado: ");
    if (resultado != -1) {
        printf("Encontrado no indice %d\n", resultado);
    } else {
        printf("Nao encontrado\n");
    }
    
    printf("\n");
    
    // === BUSCAR O VALOR 12 ===
    printf("====================================\n");
    printf("BUSCAR O VALOR 12:\n");
    printf("====================================\n");
    resultado = buscaBinariaComLog(V, 0, tamanho - 1, 12);
    printf("Resultado: ");
    if (resultado != -1) {
        printf("Encontrado no indice %d\n", resultado);
    } else {
        printf("Nao encontrado\n");
    }
    
    printf("\n====================================\n");
    printf("RESUMO:\n");
    printf("====================================\n");
    printf("Buscar 10: Sequencia = 5, 10 (2 comparacoes)\n");
    printf("Buscar 12: Sequencia = 5, 10, 11 (3 comparacoes)\n");
    
    return 0;
}