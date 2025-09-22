#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**
 * A função `snprintf()` formata uma string de acordo com o formato especificado e a armazena
 * no buffer fornecido. Ela garante que o número de caracteres não ultrapasse o tamanho máximo
 * do buffer, prevenindo o problema de buffer overflow. Se o buffer for pequeno, a string será
 * truncada, mas a função sempre inclui um terminador nulo (`'\0'`).
 *
 * @param __stream Ponteiro para o buffer onde a string formatada será armazenada.
 * @param __n Tamanho máximo do buffer (incluindo o caractere nulo `'\0'`).
 * @param __format String de formato contendo especificadores de dados (ex: `%d`, `%s`).
 * @param ... Argumentos a serem formatados conforme o formato especificado.
 *
 * @return Retorna o número de caracteres que seriam escritos no buffer (sem contar o terminador nulo).
 *         Se o número de caracteres exceder o tamanho do buffer, a string será truncada.
 *         Caso o buffer tenha tamanho suficiente, retorna o número de caracteres realmente escritos.
 *
 * @note Se o número de caracteres a ser escrito no buffer exceder o tamanho do buffer (`n`), a string
 *       será truncada, mas sempre será terminada com `'\0'`. O valor retornado indica o número total de
 *       caracteres que seriam escritos, sem contar o caractere nulo.
 */

/**
 * @brief Exemplo de uso da função `snprintf` para formatar e imprimir um valor calculado.
 *
 * Esta função demonstra como usar `snprintf` para calcular o tamanho necessário para armazenar
 * um valor formatado em uma string. Ela calcula o valor de `sqrt(2)` e o formata usando um
 * especificador de formato (`%f`) para armazená-lo em um buffer. Em seguida, a função imprime
 * o valor formatado na tela.
 *
 * @note A função utiliza `snprintf` duas vezes: a primeira para determinar o tamanho necessário
 *       do buffer (sem realmente escrever no buffer), e a segunda para realizar a formatação real.
 */
void imprimindoComSnprintf(void)
{
    const char fmt[] = "sqrt(2) = %f";
    int sz = snprintf(NULL, 0, fmt, sqrt(2)); // Calcula o tamanho necessário

    // Aloca dinamicamente o buffer para armazenar o resultado formatado
    char *buf = (char *)malloc(sz + 1);
    if (buf == NULL)
    {
        printf("Erro ao alocar memória.\n");
        return; // Se a alocação falhar, retorna
    }

    snprintf(buf, sz + 1, fmt, sqrt(2)); // Formata e armazena no buffer
    printf("Resultado formatado: %s\n", buf);

    free(buf); // Libera a memória alocada
}

int main(int argc, char **argv)
{
    imprimindoComSnprintf();

    printf("\n------------------------------------\n");

    char buffer[1024];
    int i = 35;
    int j = 0;
    double fp = 1.7320;
    char *string = "Eduardo";
    char caractere = 'l';

    /* Formatando com snprintf() uma variedade de dados */
    j = snprintf(buffer, sizeof(buffer), "%s\n", string);
    j += snprintf(buffer + j, sizeof(buffer) - j, "%c\n", caractere);
    j += snprintf(buffer + j, sizeof(buffer) - j, "%d\n", i);
    j += snprintf(buffer + j, sizeof(buffer) - j, "%f\n", fp);

    // Exibe a string formatada
    printf("String formatada:\n\"%s\"\nCaractere contador = %d\n", buffer, j);

    return 0;
}
