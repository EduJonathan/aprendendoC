#include <stdio.h>
#include "armstrongfunc.h"

int main(int argc, char **argv)
{
    int num = 153; // Número canditato para o armstrong, mude o conteúdo para saber outros resultados
    printf("O numero: %d é armstrong %d\n", num, is_armstrong_number(num));

    /**
     * gcc -o armstrong .\main_armstrong.c .\is_armstrong.c
     * .\armstrong.exe
     */
    return 0;
}
