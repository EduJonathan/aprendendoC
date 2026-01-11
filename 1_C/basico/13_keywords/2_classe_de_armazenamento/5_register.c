#include <stdio.h>

/**
 * REGISTER:
 * A palavra-chave `register` em C sugere ao compilador que a variável deve ser
 * armazenada em um registrador da CPU, onde o acesso é mais rápido do que na memória RAM.
 *
 * Características:
 * - Escopo sempre local: só pode ser usada dentro de funções ou blocos.
 * - Não pode ser usada com ponteiros, porque registradores não têm endereço de memória acessível.
 * - Declarar `register` **não garante** que a variável será realmente alocada no registrador;
 *   o compilador pode ignorar a sugestão.
 * - Variáveis globais **não podem** ser `register`.
 *
 * Uso típico:
 * - Variáveis contadoras em loops (int, char, etc.).
 *
 * Exemplo:
 *   register int count = 0;
 *
 * Observações:
 * - Não é possível obter o endereço de uma variável `register` usando &.
 * - Em C moderno, o uso de `register` é praticamente obsoleto; compiladores modernos otimizam automaticamente.
 */

/// ERRO: a global-scope declaration may not have this storage class
/// register int s;

int main(int argc, char **argv)
{
    /// printf("%p", &r); ERRO: address of register variable 'r' requested
    /// register char *p = &r; ERRO: address of register variable 'r

    // Declarando uma variável register local
    register int r = 0;

    // Vetor de três elementos
    int v[3] = {45, 6, 7};

    // Somando todos os elementos do vetor usando a variável register
    for (int i = 0; i < 3; i++)
    {
        r += v[i];
    }

    // Imprimindo o resultado
    printf("r = %d\n", r); // OUTPUT: 58

    return 0;
}
