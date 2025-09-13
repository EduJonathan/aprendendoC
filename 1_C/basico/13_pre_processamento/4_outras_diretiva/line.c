#include <stdio.h>

/**
 * #line: Instrui o pré-processador a definir os valores relatados do compilador para o
 * número da linha e o nome do arquivo para um determinado número de linha e nome do arquivo.
 * é uma ferramenta poderosa para manipular informações de depuração durante a compilação,
 * proporcionando flexibilidade em certos cenários de desenvolvimento de software.
 */

// Macro to print o atual número da linha
#define PrintLineNum \
    printf("O número da linha é %d, no arquivo %s\n", __LINE__, __FILE__)

int main(int argc, char **argv)
{
    // Imprime a linha atual (__LINE__) e o nome do arquivo (__FILE__) onde está este printf
    printf("Essa linha de código está em %d, no arquivo %s\n", __LINE__, __FILE__);

    // Define a linha atual como 10 usando a diretiva #line
#line 10

    // Imprime a linha atual (__LINE__) e o nome do arquivo (__FILE__) após a diretiva #line 10
    printf("Essa linha de código está em %d, no arquivo %s\n", __LINE__, __FILE__);

    // Define a linha atual como 20 e o nome do arquivo como "hello.cpp" usando #line
#line 20 "hello.cpp"

    // Imprime a linha atual (__LINE__) e o nome do arquivo (__FILE__) após a diretiva #line 20 "hello.cpp"
    printf("Essa linha de código está em %d, no arquivo %s\n", __LINE__, __FILE__);

    // Imprime a linha atual (__LINE__) e o nome do arquivo (__FILE__) após as diretivas #line anteriores
    printf("Essa linha de código está em %d, no arquivo %s\n", __LINE__, __FILE__);

    // Imprime a linha original
    PrintLineNum;

    // Define a linha atual como 20 e o nome do arquivo como "main.c" usando #line
#line 20 "main.c"
    PrintLineNum;

    // Define a linha atual como 30 e o nome do arquivo como "index.c" usando #line
#line 30 "index.c"
    PrintLineNum;
    return 0;
}
