#include <stdio.h>

/**
 * #pragma GCC diagnostic ignored "-Wdeprecated-declarations": Diretiva do compilador GCC
 * usada para suprimir avisos relacionados ao uso de funções ou declarações obsoletas.
 * Quando o compilador encontra código que chama funções ou usa elementos marcados como
 * obsoletos, ele normalmente gera um aviso para alertar o desenvolvedor de que esses
 * elementos podem ser removidos em versões futuras.
 *
 * Ao incluir essa diretiva no código, você instrui o compilador a ignorar esses
 * avisos e prosseguir com a compilação sem exibi-los.
 */

// Função obsoleta
__attribute__((deprecated("Use novaFuncao() em vez disso."))) void funcaoAntiga()
{
    printf("Esta é uma função obsoleta.\n");
}

int main(int argc, char **argv)
{
// Suprimindo aviso de função obsoleta
#pragma GCC diagnostic push

// Desativa os avisos sobre funções obsoletas no GCC.
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

    funcaoAntiga(); // Chamando a função obsoleta sem aviso

// Restaura o estado anterior dos diagnósticos, permitindo que os avisos voltem ao
// comportamento padrão após a chamada para funcaoAntiga().
#pragma GCC diagnostic pop

    /**
     * #pragma GCC diagnostic push e #pragma GCC diagnostic pop: São usados para garantir
     * que os avisos sejam temporariamente desativados apenas onde necessário.
     *
     * Possíveis flags:
     * > gcc -std=c17 -Wall -Wextra -Wpedantic -Werror -g -Og -o meu_programa meu_codigo.c
     * > gcc -std=c17 -O3 -march=native -flto -fomit-frame-pointer -DNDEBUG -o meu_programa meu_codigo.c
     * > gcc -std=c17 -Wall -Wextra -Wno-deprecated-declarations -o meu_programa meu_codigo.c
     * > gcc -std=c17 -Wall -Wextra -Wconversion -Wshadow -Wstrict-overflow=5 -fstack-protector-strong -o meu_programa meu_codigo.c
     * > gcc -std=c17 -O3 -fopenmp -march=native -o meu_programa meu_codigo.c
     * > gcc -std=c17 -Wall -Wextra -g -o exemplo exemplo.c
     */

    return 0;
}
