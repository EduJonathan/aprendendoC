#include <stdio.h>

// Este programa demonstra o uso dos operadores de deslocamento de bits em C:
// - Deslocamento à esquerda (<<): multiplica por potências de 2.
// - Deslocamento à direita (>>): divide por potências de 2.
// Inclui exemplos com números positivos, negativos e operadores compostos (<<=, >>=),
// além de verificações para evitar comportamentos indefinidos.

int main(int argc, char **argv)
{
    // Operador de deslocamento à esquerda (<<):
    // Move os bits de um número para a esquerda, preenchendo com zeros à direita.
    // Equivale-se a multiplicar o número por 2 elevado ao número de posições deslocadas.
    // Exemplo: 4 (binário: 0100) << 1 = 1000 (8 em decimal).
    printf("Deslocamento à Esquerda (<<):\n");
    printf(" 4 << 1: %10d  // 4 * 2^1 = 8\n", 4 << 1);
    printf(" 4 << 2: %10d  // 4 * 2^2 = 16\n", 4 << 2);
    printf(" 4 << 3: %10d  // 4 * 2^3 = 32\n", 4 << 3);
    printf(" 4 << 4: %10d  // 4 * 2^4 = 64\n", 4 << 4);
    printf(" 4 << 5: %10d  // 4 * 2^5 = 128\n", 4 << 5);
    printf(" 4 << 20: %10d // 4 * 2^20 = 4194304\n", 4 << 20);

    printf("\n-----------------------------\n");

    // Operador de deslocamento à direita (>>):
    // Move os bits de um número para a direita.
    // Para inteiros sem sinal: preenche com zeros à esquerda, equivale-se a dividir por 2^n.
    // Para inteiros com sinal: preenche com o bit de sinal (deslocamento aritmético).
    // Exemplo: 16 (binário: 10000) >> 1 = 01000 (8 em decimal).
    printf("Deslocamento à Direita (>>):\n");
    printf("16 >> 1: %10d  // 16 / 2^1 = 8\n", 16 >> 1);
    printf("16 >> 2: %10d  // 16 / 2^2 = 4\n", 16 >> 2);
    printf("16 >> 3: %10d  // 16 / 2^3 = 2\n", 16 >> 3);
    printf("16 >> 4: %10d  // 16 / 2^4 = 1\n", 16 >> 4);
    printf("16 >> 20: %10d // 16 / 2^20 aproximadamente 0\n", 16 >> 20);

    printf("-----------------------------\n");
    printf("Deslocamento com Números Negativos:\n");

    // Deslocamento à direita com números negativos usa deslocamento aritmético:
    // O bit de sinal (1 para negativos) é preservado, mantendo o sinal do número.
    // Exemplo: -16 (binário: ...11110000) >> 1 = ...11111000 (-8 em decimal).
    int valor_neg = -16;
    printf("-16 >> 1: %4d // -16 / 2^1 = -8\n", valor_neg >> 1);

    printf("\n-----------------------------\n");
    printf("Operadores Compostos (<<=, >>=):\n");

    // Operadores compostos combinam deslocamento e atribuição, modificando a variável.
    unsigned int valor1 = 8u;
    valor1 <<= 2; // 8 * 2^2 = 32
    printf(" 8 <<= 2: %4u // 8 * 2^2 = 32\n", valor1);

    unsigned int valor2 = 8u;
    valor2 >>= 2; // 8 / 2^2 = 2
    printf(" 8 >>= 2: %4u // 8 / 2^2 = 2\n", valor2);

    printf("\n-----------------------------\n");
    printf("Cuidados com Deslocamentos:\n");

    // Verificação segura para evitar deslocamentos inválidos:
    // - Deslocamento negativo ou maior/igual ao tamanho do tipo (em bits) é indefinido.
    // - Para int de 32 bits, deslocamentos devem estar entre 0 e 31.
    unsigned long long valor = 4ull; // Usa tipo maior para deslocamentos grandes
    int deslocamento = 20;
    size_t tamanho_bits = sizeof(valor) * 8; // Tamanho do tipo em bits (64 para long long)

    if (deslocamento >= 0 && deslocamento < tamanho_bits)
    {
        unsigned long long resultado = valor << deslocamento;
        printf("Valor %llu << %d = %llu\n", valor, deslocamento, resultado);
    }
    else
    {
        printf("Erro: Deslocamento %d é inválido (deve ser >= 0 e < %zu bits)\n", deslocamento, tamanho_bits);
    }

    // Nota: Deslocamentos são úteis para otimizações (ex.: substituir multiplicação/divisão),
    // manipulação de bits (ex.: flags em sistemas embarcados) ou algoritmos como codificação.
    // Cuidados importantes:
    // 1. Evite deslocamentos com números negativos em << (pode causar overflow).
    // 2. Sempre valide o valor do deslocamento para evitar comportamento indefinido.
    // 3. Use tipos sem sinal (unsigned) para deslocamentos previsíveis.
    // 4. Para valores grandes, prefira unsigned long long.

    return 0;
}
