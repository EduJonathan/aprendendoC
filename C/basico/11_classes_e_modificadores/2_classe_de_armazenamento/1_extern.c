#include <stdio.h>

/**
 * EXTERN: Estende a visibilidade de acesso ao uso onde é declarada sua existencia,
 * seu escopo de varíavel sempre global.
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
    printf("Valor de global_extern no arquivo extern.c: %d\n", global_extern);
    printf("Endereço de global_extern no arquivo extern.c: %p\n", &global_extern);

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
        printf("VALOR ASCII: %d\tCHAR-%c\tEND. DE MEMÓRIA-%p\n", meuArray[i], meuArray[i], &meuArray[i]);
    }
}
