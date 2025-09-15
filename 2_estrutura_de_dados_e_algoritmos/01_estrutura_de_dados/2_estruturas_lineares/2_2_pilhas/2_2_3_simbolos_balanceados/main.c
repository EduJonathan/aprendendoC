#include <stdio.h>
#include "stack.h"

int main(int argc, char **argv)
{
    Stack *stack = createStack(100);
    if (stack == NULL)
    {
        return 1;
    }

    unsigned char expression[100] = {0};
    printf("Entre com uma expressão (ex.: \"(([]{}))\"): ");
    scanf("%99[^\n]", expression);

    if (parenthesesMatching(expression, stack))
    {
        printf("Parênteses estão balanceados\n");
    }
    else
    {
        printf("Parênteses não estão balanceados\n");
    }

    freeStack(stack);

    /**
     * gcc -std=c11 main.c implementacao.c -o parentheses_checker
     * .\parentheses_checker.exe
     */
    return 0;
}
