/*
7) O código abaixo não funciona porque usa passagem por valor.  
Corrija-o usando passagem por referência, para que ele faça a duplicação de x. 

Não use return.
void duplica(float x) {
   x = 2 *x;
}
int main(){
	int x = 10;
	duplica(x);
		printf("%d",x);
}

*/

#include <stdio.h>

//a função agora recebe um ENDEREÇO de memória
//o asterisco aqui indica que ptr é um PONTEIRO
void duplica(float *ptr) {
    
    // *ptr significa que "o valor que está naquele endereço"
    *ptr = 2.0 * (*ptr);
}

int main() {

    float x = 10.0; 

    printf("Valor original de x: %.1f\n", x); // Imprime 10.0

    //chamando a função, mas passamos o ENDEREÇO de x
    //o & significa que "o endereço de memória de x"
    //isso é a Passagem por Referência
    duplica(&x);

    //a variável 'x' na main foi ALTERADA pela função
    printf("Valor de x apos a duplicacao: %.1f\n", x); // Imprime 20.0

    return 0;
}