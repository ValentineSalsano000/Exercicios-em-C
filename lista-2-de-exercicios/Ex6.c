/*
6. O código abaixo não funciona porque usa passagem por valor (veja a lista "só de estudo" para mais detalhes).
void duplica(float x) {
   x = 2 *x;
}
int main(){
	int x = 10;
	duplica(x);
		printf("%d",x);
}

Corrija-o usando passagem por referência, para que ele faça a duplicação de x. Não use return.
*/

#include <stdio.h>

//a função duplica recebe um endereço de um número real
//o nome da variável x na função main é um INT, mas o ponteiro precisa ser FLOAT
//porque a função faz a multiplicação com números de ponto flutuante
void duplica(float *x) {
    //o asterisco AQUI significa: 
    //"pegue o VALOR que está guardado no endereço que recebemos, multiplique por 2 e guarde o resultado de volta NESTE MESMO ENDEREÇO"

    *x = 2.0 * (*x);
}

int main() {

  //declaração do valor da nossa variavel
    float numero = 10.0; 

    printf("Valor original: %.1f\n", numero); //imprimi 10.0

    //chamamos a funcao duplica, mas passamos o ENDEREÇO da variavel 'numero'
    // O '&' significa o endereço de memória de 'numero'
    duplica(&numero);

    printf("Valor duplicado: %.1f\n", numero); // Agora deve imprimir 20.0

    return 0;
}