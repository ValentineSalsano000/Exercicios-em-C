#include<stdio.h>
#include<math.h>


// o Float lista[] é o vetor de numeros reais
// o int n é o tamanho do vetor
float calcular_desvio_padrao(float lista[], int n){

    if (n <= 1){
        return 0.0; // ou seja, não funciona se houver 0 ou 1 elemento
    }

    float soma_dos_elementos = 0.0;//soma dos Xi
    float soma_dos_quadrados = 0.0;//soma dos Xi^2

    //laço de repetição
    for (int i = 0; i< n; i++){

        float xi = lista[i];

    //esta e a primeira parte da formula, primeira soma dos elementos
    soma_dos_elementos = soma_dos_elementos + xi;

    //esta e a segunda parte da formula, soma dos quadrados dos elementos
    soma_dos_quadrados = soma_dos_quadrados + (xi * xi);
    }

    //aplicando nossa formula
    //termo A, soma dos quadrados, (SUM(xi^2))
    float termo_a = soma_dos_quadrados;

    //termo B, soma dos elementos ao quadrado, dividido por n, (1/n * (SUM(xi))²)
    float termo_b = (soma_dos_elementos * soma_dos_elementos) / n;
//diferença de A e B
    float diferenca = termo_a - termo_b;

    //a Variância é a diferença entre os dois termos dividida por (n - 1)
    //diferença interna da variancia
    float variancia = (1.0 / (n - 1)) * diferenca;
    
    //desvio padrão é a raiz quadrada da variancia
    //usamos a função sqrt() da biblioteca math.h
    float desvio_padrao = sqrt(variancia);

    return desvio_padrao;
}

//função principal
int main() {
    //dados do nosso exemplo
    float dados[] = { 2.0, 4.0, 4.0, 5.0 }; 

    //calcula o tamanho do vetor (n)
    int n_elementos = sizeof(dados) / sizeof(dados[0]);
    
    float resultado_dp;

    //chama a função
    resultado_dp = calcular_desvio_padrao(dados, n_elementos);

    //imprime o resultado formatado com 4 casas decimais para maior precisão
    printf("Dados: {2.0, 4.0, 4.0, 5.0}\n");
    printf("Numero de elementos (n): %d\n", n_elementos);
    printf("O Desvio Padrao e: %.4f\n", resultado_dp); 
    // o valor correto para estes dados, usando a formula amostral (dividindo por n-1), e 1.2583

    return 0;
}