#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/**
 * strcmp: Compara duas strings lexicograficamente com base nos valores ASCII dos caracteres.
 * Retorna um inteiro que indica a relação entre as strings:
 *   - < 0: se a primeira string é menor que a segunda.
 *   - == 0: se as strings são iguais.
 *   - > 0: se a primeira string é maior que a segunda.
 *
 * @param _Str1 Ponteiro para a primeira string.
 * @param _Str2 Ponteiro para a segunda string.
 * @return Inteiro representando a relação lexicográfica entre as strings.
 */

/**
 * @brief Procedimento que irá somente imprimir os valores comparados através da função strcmp
 * de duas strings passadas como parâmetros
 *
 * @param string1 Passando a primeira string
 * @param string2 Passando a segunda string
 */
void comparandoStringsComStrcmp(const char *string1, const char *string2)
{
    printf("strcmp(string1, string2) > 0? %d\n", strcmp(string1, string2) > 0);
    printf("strcmp(string1, string2) >= 0? %d\n", strcmp(string1, string2) >= 0);
    printf("strcmp(string1, string2) < 0? %d\n", strcmp(string1, string2) < 0);
    printf("strcmp(string1, string2) <= 0? %d\n", strcmp(string1, string2) <= 0);
    printf("strcmp(string1, string2) == 0? %d\n", strcmp(string1, string2) == 0);
    printf("strcmp(string1, string2) != 0? %d\n", strcmp(string1, string2) != 0);
}

/**
 * @brief Compara duas strings considerando a sensibilidade a maiúsculas e minúsculas.
 * Imprime se as strings são iguais ou diferentes e retorna o resultado como booleano.
 *
 * @param string1 Ponteiro para a primeira string.
 * @param string2 Ponteiro para a segunda string.
 * @return bool Verdadeiro se as strings forem iguais, falso caso contrário.
 */
bool comparaCaseSensitive(const char *string1, const char *string2)
{
    bool saoIguais = strcmp(string1, string2) == 0 ? true : false;
    printf("\nComparando '%s' e '%s': %s\n", string1, string2, saoIguais ? "Iguais" : "Diferentes");
    return saoIguais;
}

int main(int argc, char **argv)
{
    /* Declarando dois vetores de caracteres para inserir nos parâmetros*/
    const char str1[] = "Brasil";
    const char str2[] = "EUA";

    // Chamando a função para comparar estes dois vetores de caracteres
    comparandoStringsComStrcmp(str1, str2);

    /*
     * C é case-sensitive, ou seja, a linguagem diferencia casos (maiúsculas/minúsculas)
     * de funções, palavras-chave, variáveis e até mesmo strings.
     */

    /*
     * Declarando dois ponteiros para char que tem como única diferença a letra `c`.
     * Mas é o bastante para que elas não sejam iguais.
     */
    // Declaração de duas strings com diferença em maiúsculas/minúsculas
    const char *string3 = "LINGUAGEM c";
    const char *string4 = "LINGUAGEM C";

    // Compara as strings considerando sensibilidade a maiúsculas/minúsculas
    bool stringsIguais = comparaCaseSensitive(string3, string4);
    return 0;
}
