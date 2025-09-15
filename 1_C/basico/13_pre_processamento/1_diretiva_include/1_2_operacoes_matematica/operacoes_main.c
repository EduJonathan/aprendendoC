#include <stdio.h>
#include "functions_aritmeticas.h"

/**
 * @brief Compilação em projetos com múltiplos arquivos.
 *
 * Quando se trata de projetos organizados em múltiplos arquivos (módulos separados),
 * a etapa de compilação individual de cada módulo torna-se indispensável, principalmente devido
 * à necessidade de resolução de símbolos durante o linking.
 *
 * O compilador traduz cada arquivo `.c` em um objeto (`.o`), mas somente durante a etapa
 * de linkagem o linker reúne todos esses objetos, resolvendo referências entre funções
 * e variáveis globais declaradas em diferentes módulos.
 *
 * Se algum módulo não for compilado ou incluído no processo de linkagem,
 * erros como "undefined reference" podem ocorrer.
 *
 * Cada arquivo-fonte (.c) é compilado separadamente em um objeto intermediário (.o),
 * que posteriormente será vinculado (linkado) com os demais objetos para formar
 * o executável final.
 *
 * Essa abordagem permite:
 * - Melhor organização e modularização do código.
 * - Reutilização de componentes.
 * - Compilação incremental (compila-se apenas o que mudou).
 * - Maior manutenibilidade e escalabilidade do projeto.
 *
 * Por isso, mesmo que o programa pareça pequeno, quando modularizado,
 * exige um processo de compilação adequado — seja manual via `gcc`, com `Makefile`,
 * ou por meio de ferramentas de build automatizadas como `CMake`.
 */

int main(int argc, char **argv)
{
    // Definindo valores
    float n1 = 30.0F;
    float n2 = 20.0F;

    // Criando variáveis para guardar o valor do retorno de cada operação.
    float res_soma = add(n1, n2);
    printf("Resultado de %.2f + %.2f = %.2f\n", n1, n2, res_soma);

    // Criando variáveis para guardar o valor do retorno de cada operação.
    float res_sub = subtract(n1, n2);
    printf("Resultado de %.2f - %.2f = %.2f\n", n1, n2, res_sub);

    // Criando variáveis para guardar o valor do retorno de cada operação.
    float res_mult = multiply(n1, n2);
    printf("Resultado de %.2f * %.2f = %.2f\n", n1, n2, res_mult);

    // Criando variáveis para guardar o valor do retorno de cada operação.
    float res_div = divide(n1, n2);
    printf("Resultado de %.2f / %.2f = %.2f\n", n1, n2, res_div);

    /**
     * Nesse caso teremos que compilar e executar
     *
     * gcc -o programa .\operacoes_main.c .\operacoes_aritmeticas.c
     * .\programa.exe
     */
    return 0;
}
