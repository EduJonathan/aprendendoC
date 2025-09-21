#include <stdio.h>

/**
 * #line: Instrui o pré-processador a definir os valores relatados do compilador para o
 * número da linha e o nome do arquivo para um determinado número de linha e nome do arquivo.
 * É uma ferramenta poderosa para manipular informações de depuração durante a compilação,
 * proporcionando flexibilidade em certos cenários de desenvolvimento de software.
 *
 * Melhores flags para compilar
 * gcc -g -Wall -Wextra -O0 -fsanitize=address line.c -o programa
 * gcc -O2 -Wall -s line.c -o programa
 */

// Macro para imprimir o número da linha atual e o nome do arquivo
#define PrintLineNum() \
    printf("O número da linha é %d, no arquivo %s\n", __LINE__, __FILE__)

int main(int argc, char **argv)
{
    // Imprime a linha atual (__LINE__) e o nome do arquivo (__FILE__) sem alterações
    printf("Essa linha de código está em %d, no arquivo %s\n", __LINE__, __FILE__);

    // Define a linha atual como 100 (número distinto para evitar confusão com linhas reais)
#line 100

    // Imprime após redefinir apenas o número da linha para 100
    printf("Essa linha de código está em %d, no arquivo %s\n", __LINE__, __FILE__);

    // Define a linha como 200 e o nome do arquivo como "hello.cpp" (números distintos para clareza)
#line 200 "hello.cpp"

    // Imprime após redefinir linha para 200 e arquivo para "hello.cpp"
    printf("Essa linha de código está em %d, no arquivo %s\n", __LINE__, __FILE__);

    // Imprime a linha seguinte (deve ser 201, pois incrementa automaticamente)
    printf("Essa linha de código está em %d, no arquivo %s\n", __LINE__, __FILE__);

    // Usa a macro para imprimir (deve ser 202, ainda em "hello.cpp")
    PrintLineNum();

    // Redefine a linha para 300 e o arquivo para "main.c"
#line 300 "main.c"

    // Usa a macro após redefinição (deve ser 300, em "main.c")
    PrintLineNum();

    // Redefine a linha para 400 e o arquivo para "index.c"
#line 400 "index.c"

    // Usa a macro após redefinição (deve ser 400, em "index.c")
    PrintLineNum();

    // Exemplo opcional: Provoca um erro de compilação para demonstrar o efeito em mensagens de erro
    // Descomente a linha abaixo para testar (o compilador reportará erro na linha 401 de "index.c")
    // #error Este é um erro intencional para demonstrar #line

    return 0;
}
