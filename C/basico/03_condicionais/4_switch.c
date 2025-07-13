#include <stdio.h>
#include <stdbool.h>

/**
 * SWITCH-CASE: O comando `switch-case` permite testar o valor de uma variável contra
 * múltiplos casos possíveis (valores constantes). Ele é útil quando há várias condições
 * a serem verificadas para um único valor. Cada `case` representa um valor específico
 * e, caso a variável corresponda a esse valor, o código correspondente a esse `case`
 * será executado.
 *
 * A diferença entre o `switch-case` e o `if-else` é que o `switch` é mais eficiente
 * quando comparado com múltiplos `if` em que a condição precisa ser calculada repetidamente.
 * O `switch` funciona apenas com valores constantes e não aceita condições mais complexas.
 */

int main(int argc, char **argv)
{
    printf("\n\t>>SWITCH-CASE<<\n");

    char pontuacao;
    printf("\n Digite um sinal de pontuação: ");
    scanf("%c", &pontuacao);

    switch (pontuacao)
    {
    case '?':
        printf("\n VOCÊ DIGITOU O SINAL DE PONTUAÇÃO :: '%c' >> PONTO DE INTERROGAÇÃO\n", pontuacao);
        break;

    case '!':
        printf("\n VOCÊ DIGITOU O SINAL DE PONTUAÇÃO :: '%c' >> EXCLAMAÇÃO\n", pontuacao);
        break;

    case ';':
        printf("\n VOCÊ DIGITOU O SINAL DE PONTUAÇÃO :: '%c' >> PONTO E VIRGULA\n", pontuacao);
        break;

    case ',':
        printf("\n VOCÊ DIGITOU O SINAL DE PONTUAÇÃO :: '%c' >> VIRGULA\n", pontuacao);
        break;

    case '.':
        printf("\n VOCÊ DIGITOU O SINAL DE PONTUAÇÃO :: '%c' >> PONTO\n", pontuacao);
        break;

    case '/':
        printf("\n VOCÊ DIGITOU O SINAL DE PONTUAÇÃO :: '%c' >> BARRA\n", pontuacao);
        break;

    default:
        printf("\nESTE SINAL NÃO FOI INCLUSO NO PROGRAMA\n");
        break;
    }

    /**
     * DEFAULT: Não é necessariamente obrigatório dentro do switch é opcional e funciona
     * como se fosse um else, onde o teste de leitura da variável nao entrar em nenhum nos
     * casos do switch, exibe a mensagem do default.
     */

    /** BREAK: interrompe a continuação do programa evitando a execução dos case seguinte. */

    printf("\n=============================================================\n");
    printf("\n\t>>SWICTH CASE EM MULTIPLOS CASOS<<\n");

    char letra = 'a';

    switch (letra)
    {
    case 'A':
    case 'a':
    case 'E':
    case 'e':
    case 'I':
    case 'i':
    case 'O':
    case 'o':
    case 'U':
    case 'u':
        printf("A letra digitada '%c' é uma vogal\n", letra);
        break;
    default:
        printf("A letra digitada '%c' é uma consoante\n", letra);
        break;
    }

    printf("\n==================================================================\n");
    printf("\n\t>>BLOCO NO SWITCH-CASE<<\n");

    int escolha = 0;

    printf(" Qual operação matematica você deseja realizar! DIGITE\n");
    printf(" [1] -> SOMA\n");
    printf(" [2] -> SUBTRAÇÃO\n");
    printf(" [3] -> MULTIPLICAÇÃO\n");
    printf(" [4] -> DIVISÃO: ");
    scanf("%d", &escolha);

    // Podemos também programar dentro de cada case, transformando-os em blocos de casos,
    // tendo toda uma instrução a ser realizad onde o que acontece lá, apenas acontecerá lá.
    switch (escolha)
    {
    case 1:
    {
        float primeira_parcela = 0.0F, segunda_parcela = 0.0F;

        printf("\nInsira o primeiro numero :: ");
        scanf("%f", &primeira_parcela);

        printf("Insira o segundo numero :: ");
        scanf("%f", &segunda_parcela);

        float soma = primeira_parcela + segunda_parcela;
        printf("\nA soma de %.2f + %.2f é >> %.2f", primeira_parcela, segunda_parcela, soma);
        break;
    }
    case 2:
    {
        float minuendo = 0.0F, subtraendo = 0.0F;

        printf("\nInsira o primeiro numero :: ");
        scanf("%f", &minuendo);

        printf("Insira o segundo numero :: ");
        scanf("%f", &subtraendo);

        float diferenca = minuendo - subtraendo;
        printf("\nA subtração de %.2f - %.2f é >> %.2f", minuendo, subtraendo, diferenca);
        break;
    }
    case 3:
    {
        float primeiro_fator = 0.0F, segundo_fator = 0.0F;

        printf("\nInsira o primeiro numero :: ");
        scanf("%f", &primeiro_fator);

        printf("Insira o segundo numero :: ");
        scanf("%f", &segundo_fator);

        float produto = primeiro_fator * segundo_fator;
        printf("\nA multiplicação de %.2f x %.2f é: %.2f\n", primeiro_fator, segundo_fator, produto);
        break;
    }
    case 4:
    {
        float dividendo = 0.0F, divisor = 0.0F;

        printf("\nInsira o primeiro numero :: ");
        scanf("%f", &dividendo);

        printf("Insira o segundo numero :: ");
        scanf("%f", &divisor);

        // Verifica se o divisor é zero
        if (divisor != 0)
        {
            float quociente = dividendo / divisor;
            printf("\nA divisão de %.2f / %.2f é >> %.2f", dividendo, divisor, quociente);
        }
        else
        {
            printf("\nDivisão por zero não permitida!");
        }
        break;
    }
    default:
        printf("\nOperação não encontrada por favor! insira uma operação valida\n");
        break;
    }

    printf("\n==================================================================\n");
    printf("\n\t>>SWITCH-CASE ANINHADO<<\n");

    bool True = true;
    bool False = false;

    switch (True)
    {
    case 1:
        printf("O valor de True é: %d\n", True);

        switch (False)
        {
        case 0:
            printf("O valor de False é: %d\n", False);
            break;
            
        case 1:
            printf("O valor de False é: %d\n", False);
            break;
        }
        break;
    }
    return 0;
}
