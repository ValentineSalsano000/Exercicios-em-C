/*
Explique como funciona a busca binária. 
Explique também como o código abaixo implementa a busca binária. 
Para finalizar, pontue a diferença da busca binária e da busca linear, 
deixando claro qual é a O(N) 
ou ordem do tempo de execução de cada caso.


Ainda em relação ao código da busca binária. 
Considere o vetor V=[0 2 3 4 5 6 8 10 11].
Qual será a sequência de comparações para verficiar se o dado 10 está presente? 
 Repita para o dado 12.

*/


// a busca binaria e um algoritmo de busca ultra-rapido usado para encontrar um valor em um vetor, mas ela só funciona se o vetor estiver OBRIGATORIAMENTE ORDENADO(ou seja, em ordem numerica)



#include <stdio.h>

int buscar(int v[], int n, int dado) {
    int inicio = 0; //ponto de partida
    int fim = n - 1; //ponto final
    int meio; //posicao central

    while (inicio <= fim) { //o laço continua enquanto a busca for válida
        meio = (inicio + fim) / 2; //calcula a posicao central
        
        if (dado < v[meio]) { //se o dado for MENOR que o valor do meio
            fim = meio - 1;   //move-se o ponto final para a ESQUERDA do meio
        } else if (dado > v[meio]) { //se o dado for MAIOR que o valor do meio
            inicio = meio + 1;       //move-se o ponto de inicio para a DIREITA do meio
        } else {
            return meio; //achou! Retorna a posicao
        }
    }
    return -1; //se o laço terminar, o valor nao foi encontrado
}

//diferença de busca binaria e busca linear

//A diferença principal é que a Busca Binária é muito mais inteligente e rápida, mas a Busca Linear é mais simples e pode ser usada em qualquer situação
//busca Linear
//metodo: É a busca mais simples, você começa no primeiro item do vetor e verifica um por um (sequencialmente) até encontrar o valor ou chegar ao fim.

//requisito: NÃO precisa que o vetor esteja em ordem

//velocidade: É lenta. O tempo que ela leva é diretamente ligado ao tamanho do vetor. se o vetor dobra de tamanho, o tempo de busca também dobra.

//busca binária
//metodo: É um "corte-corte" inteligente. Você vai para o meio do vetor e descarta imediatamente metade dos dados. Repete esse processo na metade restante.

//requisito: DEVE que o vetor esteja ordenado (em ordem numérica).

//velocidade : É muito rápida. O tempo que ela leva cresce muito devagar, mesmo que o vetor seja gigantesco. Por isso, é considerada a busca mais eficiente.

