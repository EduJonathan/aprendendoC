#include <stdio.h>

/**
 * @brief Enumeração dos dias da semana. Esta enumeração define os dias da semana
 * com valores inteiros associados.
 */
typedef enum DiasDaSemana
{
    DOMINGO, /**< Domingo. VALOR CONSTANTE = 0 */
    SEGUNDA, /**< Segunda-feira. VALOR CONSTANTE = 1 */
    TERCA,   /**< Terça-feira. VALOR CONSTANTE = 2 */
    QUARTA,  /**< Quarta-feira. VALOR CONSTANTE = 3 */
    QUINTA,  /**< Quinta-feira. VALOR CONSTANTE = 4 */
    SEXTA,   /**< Sexta-feira. VALOR CONSTANTE = 5 */
    SABADO,  /**< Sábado. VALOR CONSTANTE = 6 */
} DiasSemanais;

int main(int argc, char **argv)
{
    /**
     * Percorre os valores do enum e imprime o nome do dia da semana. Este loop
     * percorre todos os valores possíveis da enumeração DiasSemanais e utiliza
     * uma estrutura switch para imprimir o nome do dia correspondente.
     */
    for (int i = DOMINGO; i <= SABADO; i++)
    {
        switch (i)
        {
        case DOMINGO:
            printf("DOMINGO\n");
            break;

        case SEGUNDA:
            printf("SEGUNDA\n");
            break;

        case TERCA:
            printf("TERCA\n");
            break;

        case QUARTA:
            printf("QUARTA\n");
            break;

        case QUINTA:
            printf("QUINTA\n");
            break;

        case SEXTA:
            printf("SEXTA\n");
            break;

        case SABADO:
            printf("SABADO\n");
            break;

        default:
            printf("Valor inesperado\n");
            break;
        }
    }

    // Crinado uma variável apartir da `enum` DiasSemanais e Atribuindo a variável e
    // num um valor numerado da enum DiasSemanais
    DiasSemanais dia1 = SABADO;
    printf("\nPosição numerada de SABADO É: %d\n", dia1);

    printf("\n-----------------------------------------\n");

    // Array de strings com os nomes dos dias da semana
    const char *nomesDosDias[] = {
        "DOMINGO",
        "SEGUNDA",
        "TERCA",
        "QUARTA",
        "QUINTA",
        "SEXTA",
        "SABADO"};

    // Percorrendo o enum e exibindo os nomes dos dias da semana
    for (int i = DOMINGO; i <= SABADO; i++)
    {
        printf("%s\n", nomesDosDias[i]);
    }
    return 0;
}
