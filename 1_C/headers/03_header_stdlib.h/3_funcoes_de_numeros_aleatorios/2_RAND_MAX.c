#include <stdio.h>
#include <stdint.h>   // para uint64_t
#include <inttypes.h> // para PRIu64
#include <unistd.h>   // para getpid()
#include <stdlib.h>
#include <time.h>

/**
 * @brief Gera uma semente pseudo-aleatória com um número específico de dígitos.
 *
 * @param digitos Número de dígitos desejados para a semente (máximo 10).
 * @return uint64_t A semente gerada.
 */
uint64_t gerar_semente(int digitos)
{
    if (digitos < 1 || digitos > 10)
    {
        printf("Erro: o número de dígitos deve estar entre 1 e 10.\n");
        exit(1);
    }

    uint64_t valor_maximo = 1;
    for (int i = 0; i < digitos; i++)
    {
        valor_maximo *= 10;
    }

    // Gera número entre 0 e (10^digitos - 1)
    return (uint64_t)((double)rand() / RAND_MAX * (valor_maximo - 1));
}

/**
 * @brief Calcula o próximo número pseudo-aleatório usando o método do quadrado do meio.
 *
 * @param numero O número atual.
 * @param digitos A quantidade de dígitos que o número deve ter.
 * @return O próximo número pseudo-aleatório.
 */
uint64_t quadrado_do_meio(uint64_t numero, int digitos)
{
    uint64_t quadrado = numero * numero;

    int remover_de_cada_lado = (digitos + 1) / 2;

    uint64_t divisor = 1;
    for (int i = 0; i < digitos - remover_de_cada_lado; i++)
    {
        divisor *= 10;
    }

    uint64_t resultado = (quadrado / divisor) % (divisor * 10ULL);
    return resultado;
}

int main(int argc, char **argv)
{
    int quantidade_digitos = 0;
    int quantidade_gerar = 0;

    printf("=== Gerador de números pseudo-aleatórios (método do quadrado do meio) ===\n\n");

    printf("Quantos dígitos cada número deve ter? (máximo 10): ");
    if (scanf("%d", &quantidade_digitos) != 1 || quantidade_digitos < 1 || quantidade_digitos > 10)
    {
        printf("Valor inválido!\n");
        return 1;
    }

    printf("Quantos números aleatórios deseja gerar? ");
    if (scanf("%d", &quantidade_gerar) != 1 || quantidade_gerar < 1)
    {
        printf("Quantidade inválida!\n");
        return 1;
    }

    /* Inicializa o gerador uma única vez */
    srand(time(NULL) ^ getpid());

    uint64_t semente = gerar_semente(quantidade_digitos);

    printf("\nSemente inicial: %0*" PRIu64 "\n\n", quantidade_digitos, semente);

    printf("Gerando %d número(s)...\n\n", quantidade_gerar);

    uint64_t atual = semente;

    for (int i = 1; i <= quantidade_gerar; i++)
    {
        atual = quadrado_do_meio(atual, quantidade_digitos);
        printf("%3dº número: %0*" PRIu64 "\n", i, quantidade_digitos, atual);
    }

    /**
     * @note
     * RAND_MAX é uma constante definida na biblioteca stdlib.h que representa o valor máximo
     * que a função rand() pode retornar. O valor de RAND_MAX pode variar entre diferentes
     * implementações da linguagem C, mas geralmente é definido como 32767 (2^15 - 1) em muitas plataformas.
     * Isso significa que a função rand() retornará um número inteiro aleatório no intervalo de 0 a RAND_MAX.
     */
    return 0;
}
