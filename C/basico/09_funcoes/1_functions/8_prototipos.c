#include <stdio.h>
#include <stdlib.h>

/**
 * PROTOTIPOS: São assinatura da função que indica ao compilador quando ele ler o código,
 * dizendo que há funções logo após a main, ou que possa está em outro arquivo.
 *
 * @note do jeito que o protótipo da função foi declarado no arquivo, tanto ele como seus
 * parâmetros precisa serem declarados da mesma forma, seja na main ou em outro arquivo.
 */

// Maneiras de se declarar protótipos de funções
int soma(int, int);
float subtracao(float n1, float n2);
void printLinhas(int);
char *concatenar(const char *, const char *);

int main(int argc, char **argv)
{
    printLinhas(20); // -------------------------
    printf("\n Resultado do retorno da soma é : %d\n", soma(1, 2));

    printLinhas(20); // -------------------------

    printf("\n Resultado do retorno da subtracao é : %f\n", subtracao(4.0F, 2.0F));
    printLinhas(20); // -------------------------

    const char *string1 = "Linguagem";
    const char *string2 = "Java";
    char *concaternarString = concatenar(string1, string2);

    printf("\n Concatenando as strings: %s\n", concaternarString);

    free(concaternarString);
    return 0;
}

/**
 * @brief Função que irá realizar a soma de numeros inteiros onde seus valores estarão
 * sendo passados por parâmetro.
 *
 * @param n1 passe o primeiro valor inteiro
 * @param n2 passe o segundo valor inteiro
 *
 * @return A soma dos 2 parâmetros
 */
int soma(int n1, int n2)
{
    return n1 + n2;
}

/**
 * @brief Função que irá realizar a subtração de numeros inteiros onde seus valores
 * estarão sendo passados por parâmetro.
 *
 * @param n1 passe o primeiro valor inteiro
 * @param n2 passe o segundo valor inteiro
 *
 * @return A subtração dos 2 parâmetros
 */
float subtracao(float n1, float n2)
{
    return n1 - n2;
}

/**
 * @brief Procedimento que irá realizar a impressão de traçados para o
 * número de linhas informado
 *
 * @param n Numero de linhas
 */
void printLinhas(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("-");
    }
}

char *concatenar(const char *str1, const char *str2)
{
    int i = 0,
        j = 0;

    /* Calcula o comprimento das strings. */
    while (str1[i] != '\0')
    {
        i++;
    }

    while (str2[j] != '\0')
    {
        j++;
    }

    /*
     * Aloca memória para a concatenação o tamanho das duas strings(str1 + str2 e +1 para o '\0')
     * E +1 para o ' '(espaço em branco).
     */
    char *concatenaString = (char *)malloc((i + j + 2) * sizeof(char));

    /* Copia a primeira string para a concatenação. */
    int copy = 0;
    for (; copy < i; copy++)
    {
        concatenaString[copy] = str1[copy];
    }

    /* Adiciona um espaço em branco no final da primeira string. */
    concatenaString[copy++] = ' ';

    /* Copia a segunda string para a concatenação. */
    for (int len = 0; len < j; len++, copy++)
    {
        concatenaString[copy] = str2[len];
    }

    /* Adiciona o '\0' no final da concatenação. */
    concatenaString[copy] = '\0';

    /* Retorna a concatenação. */
    return concatenaString;
}
