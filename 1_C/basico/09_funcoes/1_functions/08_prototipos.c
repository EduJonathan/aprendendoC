#include <stdio.h>
#include <stdlib.h>

/**
 * PROTÓTIPOS DE FUNÇÃO:
 * Um protótipo de função é uma declaração que informa ao compilador sobre a
 * existência de uma função, incluindo seu nome, tipo de retorno e parâmetros,
 * antes que a função seja realmente definida no código.
 *
 * Isso permite que você utilize a função em trechos de código que aparecem
 * antes da definição completa, ou mesmo que a função esteja em outro arquivo.
 *
 * Exemplo:
 * O printf() é uma função cuja declaração (protótipo) já está presente na biblioteca
 * <stdio.h>. Graças a esse protótipo, você pode chamar printf() em qualquer parte
 * do seu código sem que o compilador reclame, mesmo antes de ver a definição da função.
 *
 * @note
 * O protótipo deve corresponder exatamente à definição da função, incluindo:
 *  - tipo de retorno
 *  - tipo e ordem dos parâmetros
 * Qualquer diferença pode gerar erros de compilação ou comportamento inesperado.
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

/**
 * @brief Concatena duas strings, com um espaço em branco entre elas.
 *
 * Esta função recebe duas strings como parâmetros, calcula seus comprimentos, aloca
 * memória suficiente para armazenar a concatenação delas com um espaço em branco
 * entre elas, e retorna o resultado como uma nova string.
 *
 * @param str1 A primeira string a ser concatenada.
 * @param str2 A segunda string a ser concatenada.
 *
 * @return Um ponteiro para a nova string concatenada, com um espaço em branco
 * entre as duas strings originais. A string retornada deve ser liberada com `free`
 * após o uso.
 */
char *concatenar(const char *str1, const char *str2)
{
    int i = 0, j = 0;

    /* Calcula o comprimento da primeira string. */
    while (str1[i] != '\0')
    {
        i++;
    }

    /* Calcula o comprimento da segunda string. */
    while (str2[j] != '\0')
    {
        j++;
    }

    /*
     * Aloca memória suficiente para armazenar a concatenação das duas strings,
     * mais 1 para o espaço em branco e +1 para o caractere de finalização '\0'.
     */
    char *concatenaString = (char *)malloc((i + j + 2) * sizeof(char));

    /* Copia a primeira string para a nova string. */
    int copy = 0;
    for (; copy < i; copy++)
    {
        concatenaString[copy] = str1[copy];
    }

    /* Adiciona um espaço em branco no final da primeira string. */
    concatenaString[copy++] = ' ';

    /* Copia a segunda string para a nova string. */
    for (int len = 0; len < j; len++, copy++)
    {
        concatenaString[copy] = str2[len];
    }

    /* Adiciona o '\0' no final da nova string. */
    concatenaString[copy] = '\0';

    /* Retorna a string concatenada. */
    return concatenaString;
}
