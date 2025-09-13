#include <stdio.h>

/**
 * REGISTERS: `register` é usado para indicar que uma variável deve ser alocada em
 * um registrador de CPU, onde o acesso é mais rápido do que na memória RAM. É mais comumente
 * usado para variáveis do tipo `int` e `char`. O uso de `register` sugere ao compilador otimizar
 * o acesso à variável.
 *
 * Importante:
 * - O escopo de uma variável registrada é sempre local.
 * - Não pode ser usado com ponteiros, pois os registradores não possuem endereços de memória.
 *
 * Exemplo:
 * register int count = 0;
 *
 * @note O compilador pode ignorar o modificador `register` e armazenar a variável na RAM.
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
