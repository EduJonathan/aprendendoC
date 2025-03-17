#include <stdio.h>

/**
 * REGISTERS: Ou registradores são onde as variáveis estão alocadas em registradores,
 * uma região de memória presente no processador da máquina (CPU) que seu acesso é mais
 * rápido que uma memória alocada na memória RAM. Seu escopo sempre será local, utilizada
 * mais nos tipo int e char, não pode ser um ponteiro, pois registers não possuem endereços
 * de memória que possam ser extraído com '&'.
 */

/// ERRO: a global-scope declaration may not have this storage class
/// register int s;

int main(int argc, char **argv)
{
    // Declarando a variável register
    register int r = 0;

    /// printf("%p", &r); ERRO: address of register variable 'r' requested
    /// register char *p = &r; ERRO: address of register variable 'r

    // Criando vetor de três elementos
    int v[3] = {45, 6, 7};

    // Pecorrendo o vetor
    for (int i = 0; i < 3; i++)
    {
        // e armazenando em register todos os valores do vetor somados
        r += v[i];
    }

    // Imprimindo o resultado
    printf("r = %d\n", r);
    return 0;
}
