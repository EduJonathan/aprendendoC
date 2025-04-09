#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * qsort(quick sort): Função que realiza a ordenação (organização) em ordem alfabetica.
 *
 * SINTAXE:
 * void qsort(void *_Base, size_t _Nmemb, size_t _Size, int (*_Compare)(const void *, const void *));
 *
 * @param _Base Ponteiro para o array de ponteiros.
 * @param _Nmemb Número de elementos no array de ponteiros .
 * @param _Size Tamanho dos elementos no array de ponteiros .
 * @param _Compare Função de comparação que define a ordem dos elementos no array de ponteiros.
 * @return Nenhum valor é retornado.
 *
 * =========================================================================================
 *
 * bsearch(binary search): Função que realiza a busca binária em um array de ponteiros.
 *
 * SINTAXE:
 * void *bsearch(const void *_Key, const void *_Base, size_t _Nmemb, size_t _Size, int (*_Compare)(const void *, const void *));
 *
 * @param _Key Ponteiro para a chave de busca.
 * @param _Base Ponteiro para o array de ponteiros.
 * @param _Nmemb Número de elementos no array de ponteiros .
 * @param _Size Tamanho dos elementos no array de ponteiros .
 * @param _Compare Função de comparação que define a ordem dos elementos no array de ponteiros.
 * @return Um ponteiro para o elemento encontrado ou NULL se o elemento não for encontrado.
 *
 * @details É de extrema importância que para realizar uma busca com o bsearch,
 * deve-se primeiramente ordenar o array de ponteiros utilizando a função qsort ou qualquer
 * outro algoritmo de ordenação, bsearch qsort podem trabalhar simultanemente.
 */

/**
 * Compara strings recebidas como parâmetros e retorna um valor que indica a ordenação,
 * usando a função strcmp.
 *
 * @param a Primeiro ponteiro para string
 * @param b Segundo ponteiro para string
 *
 * @return Retorna um valor que indica a ordenação:
 *         - Menos que 0 se a primeira string for menor que a segunda
 *         - Igual a 0 se as strings forem iguais
 *         - Maior que 0 se a primeira string for maior que a segunda
 */
int compara_strings(const void *a, const void *b)
{
    const char *str1 = *(const char **)a; // Converte void* para char*
    const char *str2 = *(const char **)b; // Converte void* para char*
    return strcmp(str1, str2);            // Compara as strings usando strcmp
}

int main(int argc, char **argv)
{
    // Definição da frutas de strings
    char frutas[5][20] = {
        "abacaxi",
        "banana",
        "laranja",
        "maçã",
        "uva"};

    // Criando um array de ponteiros para as strings na frutas
    const char *ponteiros[5];

    // Preenchendo o array de ponteiros
    for (int i = 0; i < 5; ++i)
    {
        ponteiros[i] = frutas[i]; // Cada ponteiro aponta para uma string na frutas
    }

    // Ordenando o array de ponteiros para strings
    qsort(ponteiros, 5, sizeof(char *), compara_strings);

    // Exibindo as strings ordenadas
    printf("frutas ordenada:\n");

    // Imprimindo as strings ordenadas
    for (int i = 0; i < 5; ++i)
    {
        printf("%s\n", ponteiros[i]); // Imprime cada string ordenada
    }

    // String que queremos buscar na frutas
    const char *chave = "laranja";

    // Usando bsearch para encontrar a string na frutas
    const char **resultado = (const char **)bsearch(&chave, ponteiros, 5, sizeof(char *), compara_strings);

    // Verificando se encontrou a string e exibindo o resultado
    if (resultado != NULL)
    {
        printf("\n'%s' encontrado na posição %ld.\n", chave, resultado - ponteiros);
    }
    else
    {
        printf("\n'%s' não encontrado.\n", chave);
    }
    return 0;
}
