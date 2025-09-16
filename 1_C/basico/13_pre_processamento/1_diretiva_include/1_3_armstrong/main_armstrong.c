#include <stdio.h>
#include "is_armstrong.h"

int main(int argc, char **argv)
{
    int num = 153; // Número canditato para o armstrong, mude o conteúdo para saber outros resultados
    printf("O numero: %d é armstrong %d\n", num, is_armstrong_number(num));

    /**
     * gcc .\armstrong_func.c .\main_armstrong.c
     * .\a.exe
     */
    return 0;
}
