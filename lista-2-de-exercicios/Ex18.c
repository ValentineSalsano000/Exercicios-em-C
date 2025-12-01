/*
O código ao lado é responsável pela alocação dinâmica de uma matriz. 
Explique por que matriz é declarada com int **matriz. 
Por que temos duas linhas com malloc? 
Por que na 4ª linha o parâmetro do sizeof é (int *), 
enquanto na linha 6 o parâmetro do sizeof é (int). 
E por que o malloc da linha 6 está dentro de um laço for, 
enquanto o da linha 4 não está dentro do laço for?


int i, n, m, **matriz;
scanf("%d %d", &n, &m);
matriz = malloc(n * sizeof(int *));
for (i = 0; i < n; i++)
    matriz[i] = malloc(m * sizeof(int));
*/

//1. Declaração: int **matrizA variável matriz é declarada como um ponteiro para um ponteiro de inteiro (int **). Isso é necessário porque a matriz dinâmica em C não é um único bloco contíguo; ela é uma estrutura onde matriz aponta para um array de endereços (int *), e cada endereço nesse array, por sua vez, aponta para o início de uma linha da matriz (os dados int)
//2. Duas Chamadas mallocExistem duas chamadas malloc porque a alocação é feita em duas etapas essenciais:Primeiro malloc: Aloca o array principal de ponteiros (int *). Este array armazena os endereços das futuras linhas.Segundo malloc : Aloca o espaço para os dados reais (int) de cada uma das N linhas
//3. Diferença no sizeofA diferença nos parâmetros de sizeof reflete o que está sendo alocado em cada etapa:O sizeof é usado com (int *) porque estamos alocando memória para um ponteiro de inteiro (o tamanho de um endereço de memória), que é o tipo de dado armazenado no array principal.Linha 6: O sizeof é usado com (int) porque estamos alocando memória para o inteiro em si (o dado da matriz), que é o tipo de dado armazenado em cada linha
//4. Uso do Laço forO for é usado para diferenciar o modo como os blocos de memória são alocados:malloc da (Fora do for): É executado apenas uma vez porque aloca um único bloco de memória grande o suficiente para conter todos os ponteiros.malloc da (Dentro do for): É executado N vezes (uma vez para cada linha) porque cada linha da matriz é um bloco de memória separado que precisa ser alocado individualmente.