#include <stdio.h>

#define DEBUG // Defina isso para ativar o modo de depuração

int main(int argc, char **argv)
{
    int x = 5;
    int y = 10;

#if defined(DEBUG)
    printf("Iniciando a depuração...\n");
    printf("Valor de x: %d\n", x);
    printf("Valor de y: %d\n", y);
#endif

    // Código principal
    printf("O resultado da soma é: %d\n", x + y);

    return 0;
}
