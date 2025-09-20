#include <stdio.h>
#include "functions_aritmeticas.h"

/**
 * @brief Compilação em projetos com múltiplos arquivos
 *
 * Em projetos organizados em vários arquivos (módulos separados),
 * é indispensável compilar cada módulo individualmente, pois,
 * durante a fase de *linking*, o linker precisa resolver todos os
 * símbolos utilizados em diferentes partes do programa.
 *
 * Existem dois tipos principais de arquivos:
 * - **.h**: contém declarações de funções, diretivas de pré-processador, macros e definições de tipos.
 * - **.c**: contém as implementações (definições) das funções e variáveis.
 *
 * O compilador traduz cada arquivo `.c` em um objeto intermediário (`.o`).
 * Somente na etapa de linkagem o linker reúne todos esses objetos,
 * resolvendo referências entre funções e variáveis globais declaradas em módulos distintos.
 *
 * Se algum módulo não for compilado ou incluído no processo de linkagem,
 * ocorrerão erros como *undefined reference*.
 *
 * Vantagens dessa abordagem:
 * - Organização e modularização do código.
 * - Reutilização de componentes.
 * - Compilação incremental (compila apenas o que mudou).
 * - Maior manutenibilidade e escalabilidade do projeto.
 *
 * Mesmo em programas pequenos, quando há modularização,
 * é essencial um processo de compilação adequado — seja manual via `gcc`,
 * com um `Makefile`, ou usando ferramentas de build como **CMake**.
 *
 * @note **Apenas os arquivos `.c` devem ser passados ao compilador**.
 *       Arquivos de cabeçalho (`.h`) não são compilados diretamente,
 *       pois são incluídos (com `#include`) pelos arquivos-fonte `.c`.
 */

int main(int argc, char **argv)
{
    // Definindo valores
    float n1 = 30.0F;
    float n2 = 20.0F;

    // Criando variáveis para guardar o valor do retorno de cada operação.
    float res_soma = add(n1, n2);
    printf("Resultado de %.2f + %.2f = %.2f\n", n1, n2, res_soma);

    float res_sub = subtract(n1, n2);
    printf("Resultado de %.2f - %.2f = %.2f\n", n1, n2, res_sub);

    float res_mult = multiply(n1, n2);
    printf("Resultado de %.2f * %.2f = %.2f\n", n1, n2, res_mult);

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
