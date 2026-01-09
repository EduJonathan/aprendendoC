#include <stdio.h>

// Habilite o modo de depuração definindo a macro DEBUG (comente para desativar)
#define DEBUG

// Macro para simplificar mensagens de depuração
#ifdef DEBUG
#define DEBUG_PRINT(fmt, ...) printf("DEBUG: " fmt, ##__VA_ARGS__)
#else
#define DEBUG_PRINT(fmt, ...) // Expande para nada se DEBUG não está definido
#endif

int main(int argc, char **argv)
{
    int x = 5;
    int y = 10;

    // Bloco de depuração condicional
#ifdef DEBUG
    // Redefine o número da linha para facilitar rastreamento em logs de depuração
#line 100 "debug_example.c"
    DEBUG_PRINT("Iniciando a depuração...\n");
    DEBUG_PRINT("Valor de x: %d\n", x);
    DEBUG_PRINT("Valor de y: %d\n", y);
#endif

    // Redefine a linha para o código principal (evita confusão em mensagens de erro)
#line 200 "main_program.c"
    // Código principal: calcula e imprime a soma de x e y
    printf("O resultado da soma é: %d\n", x + y);

    // Exemplo opcional: provoca um erro para testar mensagens do compilador
    // #error Este é um erro intencional para demonstrar #line

    // Flags Recomendadas
    // gcc -O2 -Wall -s -UDEBUG debug.c -o debug_example
    // gcc -O2 -Wall -s debug.c -o debug_example
    // gcc -g -Wall -Wextra -O0 -fsanitize=address debug.c -o debug_example

    return 0;
}
