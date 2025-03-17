#include <stdio.h>
#include <string.h>

/**
 * strcmp(string compare): Função que compara duas strings recebendo-os como parâmetros e logo
 * em seguida as comparando-as, onde se foram iguais o valor o retorna um valor inteiro, onde
 * indica a relação entre elas, sendo:
 *
 * - Menor que(<) 0 se a primeira string é menor que a segunda
 * - Igual(==) a 0 se as strings são iguais
 * - Maior(>) que 0 se a primeira string é maior que a segunda.
 *
 * SINTAXE: int strcmp(const char *_Str1, const char *_Str2);
 * @param _Str1 O primeiro ponteiro para char
 * @param _Str2 O segundo ponteiro para char
 * @return retorna um inteiro com as comparações sendo realizadas com os valores de seu parâmetros
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
 * A função compara as strings e imprime se são iguais ou não.
 *
 * @param string1 O primeiro ponteiro para char
 * @param string2 O segundo ponteiro para char
 */
void comparaCaseSenstivedasStrings(const char *string1, const char *string2)
{
    if (strcmp(string1, string2) == 0)
    {
        printf("\nAs strings são iguais\n");
    }
    else
    {
        printf("\nAs strings não são iguais\n");
    }
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
    const char *texto1 = "LINGUAGEM c";
    const char *texto2 = "LINGUAGEM C";

    // Chamando a função para comparar estas strings
    comparaCaseSenstivedasStrings(texto1, texto2);
    return 0;
}
