#include <stdio.h>
#include "armstrongfunc.h"

int main(int argc, char **argv)
{
    int num = 153; // Número canditato para o armstrong
    printf("O numero: %d é armstrong %d\n", num, is_armstrong_number(num));
    return 0;
}
