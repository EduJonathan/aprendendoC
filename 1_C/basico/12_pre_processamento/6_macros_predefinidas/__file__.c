#include <stdio.h>

/* __FILE__: Exibe o nome do arquivo de origem no qual a macro __FILE__ é exibido. */

/* Macro que irá exibir tanto o arquivo que estamos, quanto a linha que a macro irá começar */
#define PRINT_FILE_INFO() \
    printf("ARQUIVO: %s\nEstou na linha: %d\n", __FILE__, __LINE__)

int main(int argc, char **argv)
{
    // Criando uma variável do tipo int com o valor 42 inicializando
    int c = 42;

    // Chamada da macro
    PRINT_FILE_INFO();

    // Imprimindo o valor
    printf("Valor de c = %d\n", c);
    return 0;
}
