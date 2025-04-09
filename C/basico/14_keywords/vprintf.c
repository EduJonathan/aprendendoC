#include <stdio.h>
#include <stdarg.h>

/**
 * @brief Função que imprime uma string formatada e adiciona uma nova linha no final.
 *
 * Esta função é uma versão personalizada de `printf`, que aceita uma string formatada com
 * argumentos variáveis e adiciona automaticamente um caractere de nova linha (`\n`) no final
 * da impressão.
 *
 * @param Format A string de formato que pode conter especificadores como `%d`, `%f`, etc.
 * @param ... Argumentos variáveis correspondentes aos especificadores na string de formato.
 *
 * @return O número de caracteres escritos, incluindo o caractere de nova linha.
 */
int println(const char *__restrict__ Format, ...)
{
    va_list arguments;
    va_start(arguments, Format);

    int result = vprintf(Format, arguments);
    /**
     * A função vprintf(): É utilizada para imprimir a string formatada com os argumentos passados
     * para a função. Isso é equivalente ao uso de printf, mas vprintf é uma versão que aceita um
     * va_list de argumentos.
     */
    putchar('\n'); // Adiciona uma nova linha

    va_end(arguments);
    return result + 1; // Retorna o número de bytes escritos (incluindo '\n')
}

int main(int argc, char **argv)
{
    println("Hello world %d", 4);             // Exemplo com um número
    println("O valor de pi é %.2f", 3.14159); // Exemplo com ponto flutuante

    println("-------------------------------------");

    int valorInteiro = 0;
    printf("Insira um valor para valorInteiro: ");
    scanf("%d", &valorInteiro);
    println("O valor da variável \"valorInteiro\" é: %d", valorInteiro);
    return 0;
}
