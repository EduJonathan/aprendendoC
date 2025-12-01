#include <stdio.h>

/**
 * EXTERN:
 * A palavra-chave `extern` indica que uma variável ou função está definida em outro arquivo
 * ou em outro escopo, permitindo que seja usada em diferentes arquivos de código-fonte.
 *
 * Características:
 * - Permite acessar variáveis e funções globais de outros arquivos.
 * - Não aloca memória para a variável; apenas informa ao compilador que a variável existe
 *   em outro lugar.
 * - É útil para programas que usam múltiplos arquivos fonte (.c) e ajuda a organizar o código.
 *
 * Exemplo:
 *   extern int contador;  // variável definida em outro arquivo
 *
 * Observações:
 * - A variável referenciada por `extern` **deve ser definida em algum lugar do programa**.
 * - `extern` também pode ser usado com funções, mas não é necessário em funções já
 *   declaradas globalmente.
 */

// Declaração da variável global com a palavra-chave 'extern'
extern int global_extern;

// Declaração da variável do tipo array com a palavra-chave 'extern'
extern const char meuArray[5];

// Declarando função com a palavra-chave 'extern' que retorna um tipo float
// e aceita 2 parâmetros float
extern float extern_function(float, float);

/// @brief Procedimento para realizar algumas operações com as variáveis extern
extern void teste(void)
{
    // Imprimir o valor e endereço da variável global_extern
    printf("Valor de global_extern no extern_vars.c: %d\n", global_extern);
    printf("Endereço de global_extern no extern_vars.c: %p\n", (void *)&global_extern);

    // Incrementa o valor da variável global_extern
    global_extern += 4;

    // Imprimir o novo valor incrementado da variável global_extern
    printf("Valor incrementado de global_extern += 4 no arquivo extern.c: %d\n", global_extern);

    printf("\n-------------------------------------\n");

    // Calcula a quantidade de elementos no array
    size_t qntdElemento = sizeof(meuArray) / sizeof(meuArray[0]);

    // Imprimindo o conteúdo do array
    printf("Conteúdo do array no arquivo extern.c\n");
    for (int i = 0; i < qntdElemento; ++i)
    {
        printf("VALOR ASCII: %d\tCHAR: %c\tEND. DE MEMÓRIA: %p\n",
               meuArray[i], meuArray[i], (void *)&meuArray[i]);
    }
}
