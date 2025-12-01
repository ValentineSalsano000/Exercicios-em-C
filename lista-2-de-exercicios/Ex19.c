/*
O código abaixo adiciona elemento ao início ou ao final da lista? 
Escreve a função que faça a inserção no outro extremo, 
e então crie uma lista nesta sequência:

1 no início (ou fim - já que a lista começa vazia, tanto faz)
 2 no início 3 no fim

A lista final deverá ser 2 -> 1 -> 3

p_no adicionar_elemento(p_no lista, int x) {
    p_no novo; // 1. Declara um ponteiro para o novo nó
    novo = malloc(sizeof(No)); // 2. Reserva espaço na memória para o novo nó
    novo->dado = x; // 3. Coloca o valor 'x' dentro do novo nó
    novo->prox = lista; // 4. FAZ O NOVO NÓ APONTAR PARA O INÍCIO ATUAL DA LISTA
    return novo; // 5. RETORNA O NOVO NÓ COMO O NOVO INÍCIO DA LISTA
}

// Código no cliente:
// lista = adicionar_elemento(lista, num);
*/

//1.Onde o Elemento é Adicionado? No Início
//O código original adiciona o novo elemento no início (cabeça) da lista
//Imagine a lista como um trem. O código pega um novo vagão (novo) e o conecta na frente da locomotiva que já estava lá (lista).

//A linha chave é: novo->prox = lista;. Isso significa: "O próximo elemento, depois deste novo elemento, é o que antes era o primeiro da lista."

//O return novo; faz o ponteiro principal da lista apontar para este novo elemento, completando a inserção no início.

//2. A Função para o Outro Extremo: Inserir no Fim ➡️
//O "outro extremo" é o final da lista. Para isso, precisamos de uma função diferente que caminhe até o fim.

//Ideia: Começamos no início e vamos pulando de nó em nó usando o ponteiro prox, até encontrar um nó cujo prox seja NULL (ou seja, ele é o último).

/*
p_no adicionar_fim(p_no lista, int x) {
    p_no novo;
    // 1. Cria o novo nó (o vagão). O 'prox' dele é NULL, pois ele será o ÚLTIMO.
    novo = malloc(sizeof(No));
    novo->dado = x;
    novo->prox = NULL; 

    // Se a lista estiver vazia, o novo nó é o início.
    if (lista == NULL) {
        return novo;
    }

    // 2. Cria um ponteiro 'atual' e caminha até o último elemento do trem.
    p_no atual = lista;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    // 3. O último vagão (atual) agora aponta para o novo vagão.
    atual->prox = novo;

    // Retorna o início da lista (que não mudou)
    return lista; 
}
*/




/*
p_no lista = NULL; // Começa vazia

// Passo 1: Insere 1 no Início (Lista: 1)
lista = adicionar_elemento(lista, 1); 

// Passo 2: Insere 2 no Início (Lista: 2 -> 1)
lista = adicionar_elemento(lista, 2); 

// Passo 3: Insere 3 no Fim (Lista: 2 -> 1 -> 3)
lista = adicionar_fim(lista, 3);
*/

//codigo completo e funcional:

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó e do ponteiro para o nó
typedef struct No {
    int dado;
    struct No *prox;
} No, *p_no;


// === FUNÇÃO ORIGINAL (INSERÇÃO NO INÍCIO) ===
/*
 * O novo nó se torna a cabeça da lista.
 */
p_no adicionar_elemento(p_no lista, int x) {
    p_no novo;
    
    // Aloca memória
    novo = (p_no) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return lista;
    }
    
    // 1. Preenche o dado
    novo->dado = x;
    
    // 2. O 'prox' do novo nó aponta para a cabeça antiga (lista)
    novo->prox = lista;
    
    // 3. O novo nó é a nova cabeça da lista
    return novo;
}


// === FUNÇÃO SOLICITADA (INSERÇÃO NO FIM) ===
/*
 * Percorre a lista até o último nó e anexa o novo elemento.
 */
p_no adicionar_fim(p_no lista, int x) {
    p_no novo;
    
    // 1. Aloca e inicializa o novo nó. O 'prox' dele é NULL.
    novo = (p_no) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return lista;
    }
    novo->dado = x;
    novo->prox = NULL; 

    // 2. Se a lista estiver vazia, o novo nó é o início.
    if (lista == NULL) {
        return novo;
    }

    // 3. Percorre a lista até o último nó
    p_no atual = lista;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    // 4. Conecta o último nó ('atual') ao novo nó
    atual->prox = novo;

    // 5. Retorna o início da lista
    return lista;
}


// === FUNÇÃO AUXILIAR PARA IMPRIMIR A LISTA ===
void imprimir_lista(p_no lista) {
    p_no atual = lista;
    while (atual != NULL) {
        printf("%d", atual->dado);
        if (atual->prox != NULL) {
            printf(" -> ");
        }
        atual = atual->prox;
    }
    printf("\n");
}


//função principal
int main() {
    p_no lista = NULL; // Lista começa vazia

    printf("=== Construcao da Lista: 2 -> 1 -> 3 ===\n");
    printf("Lista Inicial: Vazia\n");
    
    //insere 1 no Início (ou Fim, pois está vazia)
    //chamada: lista = adicionar_elemento
    lista = adicionar_elemento(lista, 1);
    printf("1. Inserido 1 no INÍCIO. Lista: ");
    imprimir_lista(lista);

    //insere 2 no Início
    //chamada: lista = adicionar_elemento
    lista = adicionar_elemento(lista, 2);
    printf("2. Inserido 2 no INÍCIO. Lista: ");
    imprimir_lista(lista);

    //insere 3 no fim
    //chamada: lista = adicionar_fim(lista, 3)
    lista = adicionar_fim(lista, 3);
    printf("3. Inserido 3 no FIM. Lista: ");
    imprimir_lista(lista);
    
    printf("-----------------------------------------\n");
    printf("Resultado Final: ");
    imprimir_lista(lista);

    //libera a memória alocada
    p_no temp;
    while (lista != NULL) {
        temp = lista;
        lista = lista->prox;
        free(temp);
    }

    return 0;
}