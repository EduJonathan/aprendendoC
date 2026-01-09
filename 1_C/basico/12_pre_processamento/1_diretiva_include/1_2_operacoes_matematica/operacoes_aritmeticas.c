#include <stdio.h>
#include <math.h>
#include "functions_aritmeticas.h"

float add(float a, float b)
{
    return a + b;
}

float subtract(float a, float b)
{
    return a - b;
}

float multiply(float a, float b)
{
    return a * b;
}

float divide(float a, float b)
{
    if (b == 0.0F)
    {
        printf("Não é possível realizar a divisão por zero!\n");
        return NAN; // ou INFINITY, dependendo do caso
    }
    return a / b;
}
