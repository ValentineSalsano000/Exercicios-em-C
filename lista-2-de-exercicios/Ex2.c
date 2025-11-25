/*
Escreva uma função que calcule e retorne a distância entre dois pontos ( x1, y1) e (x2, y2).
Todos os números e valores de retorno devem ser do tipo float. 
Escreva também código da main que testa sua função.
*/

#include <stdio.h>
#include <math.h> // Biblioteca necessária para a função sqrt() e pow()

//definindo nossa função de distancia
float calcularDistancia(float x1, float y1, float x2, float y2){

//calcula a diferença das coordenadas (x2 - x1) e (y2 - y1)
    float deltaX = x1 - x2; //variavel 1(guarda a diferença em x)
    float deltaY = y1 - y2; //variavel 2 (guarda a diferença em y)

    //guarda a soma dos quadrados (deltaX^2 + deltaY^2)
    //variavel 3
float somaDosQuadrados = pow(deltaX, 2) + pow(deltaY, 2);

// Retorna a raiz quadrada do resultado, que é a distância
float distancia = sqrt(somaDosQuadrados); //variavel 4, guarda a raiz quadrada

return distancia;
}

//função pincipal
int main () {

//definindo a coordenada dos dois pontos
    float p1_x = 1.0;
    float p1_y = 2.0;

    float p2_x = 4.0;
    float p2_y = 6.0;

// Chamando a função e armazenando o resultado
    float resultado = calcularDistancia(p1_x, p1_y, p2_x, p2_y);

// Exibe os pontos e o resultado
    printf("---Teste da Funcao de Distancia---\n");
    printf("Ponto 1(x1, y1): (%.1f, %.1f)\n", p1_x, p1_y);
    printf("Ponto 2 (x2, y2): (%.1f, %.1f)\n", p2_x, p2_y);
    printf("A distancia entre os dois pontos e: %.2f\n", resultado);
    // Para este exemplo, a distancia esperada é 5.0 (3^2 + 4^2 = 9 + 16 = 25, sqrt(25) = 5)

    return 0;
}
   