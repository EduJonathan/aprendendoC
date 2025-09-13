#include <stdio.h>

/**
 * EXTERN: A palavra-chave `extern` é usada para estender a visibilidade de uma variável
 * ou função além do seu escopo original, permitindo que seja acessada em diferentes arquivos 
 * de código-fonte. A variável ou função declarada com `extern` não é definida neste arquivo, 
 * mas sim em outro arquivo de código, sendo assim acessível globalmente. Isso é útil em 
 * programas que envolvem múltiplos arquivos e ajudam a organizar a memória de forma eficiente.
 *
 * @note O uso de `extern` implica que a variável ou função é global, ou seja, pode ser acessada em
 * qualquer parte do programa onde for declarada, desde que a declaração seja feita corretamente.
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
