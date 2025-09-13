#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Enumeração dos possíveis resultados do jogo.
 */
enum results
{
    ACERTOU,  /**< Número acertado */
    ERROU,    /**< Número errado */
    PROXIMO,  /**< Número foi próximo */
    DISTANTE, /**< Número foi muito distante */
};

/**
 * @brief Função que gera um número aleatório entre 1 e 100.
 *
 * @return Um número aleatório entre 1 e 100.
 */
int gerarAletoriedade(void)
{
    return rand() % 100 + 1;
}

/**
 * @brief Função que tenta adivinhar o número correto gerado aleatoriamente.
 *
 * A função gera um número aleatório e verifica se é igual, próximo
 * ou distante do número correto. Dependendo da proximidade, retorna
 * um dos valores possíveis: ACERTOU, ERROU, PROXIMO ou DISTANTE.
 *
 * @param numeroCerto O número correto que o jogador escolheu.
 * @return O resultado da tentativa (ACERTOU, ERROU, PROXIMO ou DISTANTE).
 */
enum results adivinheONumero(int numeroCerto)
{
    /**< Gera a tentativa aleatória */
    int tentativa = rand() % 100 + 1;

    printf("Tentativa: %d\n", tentativa);

    if (tentativa == numeroCerto)
    {
        /**< Se acertou, retorna ACERTOU */
        return ACERTOU;
    }
    else if (abs(tentativa - numeroCerto) <= 10)
    {
        /**< Se a diferença é menor ou igual a 10, retorna PROXIMO */
        return PROXIMO;
    }
    else if (abs(tentativa - numeroCerto) <= 30)
    {
        /**< Se a diferença é menor ou igual a 30, retorna DISTANTE */
        return DISTANTE;
    }
    return ERROU; /**< Se a diferença for maior que 30, retorna ERROU */
}

int main(int argc, char **argv)
{
    srand(time(NULL)); /**< Inicializa o gerador de números aleatórios com o tempo atual */

    int numeroCerto = 0;

    printf("Digite um numero de 1 a 100: ");
    scanf("%d", &numeroCerto);

    if (numeroCerto < 1 || numeroCerto > 100)
    {
        printf("Numero fora do intervalo permitido\n");
        return 1; /**< Se o número estiver fora do intervalo, o programa termina com erro */
    }

    /**< Chama a função para adivinhar o número correto */
    enum results r = adivinheONumero(numeroCerto);

    switch (r)
    {
    case ACERTOU:
        printf("Acertou\n");
        break;

    case ERROU:
        printf("Errou\n");
        break;

    case PROXIMO:
        printf("Proximo\n");
        break;

    case DISTANTE:
        printf("Distante\n");
        break;
    }

    printf("FIM DO JOGO\n");
    return 0; /**< Finaliza o programa com sucesso */
}
