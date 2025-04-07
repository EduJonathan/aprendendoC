#include <stdio.h>

/**
 * O #pragma optimize é uma diretiva usada no compilador MSVC (Microsoft Visual C++)
 * para habilitar ou desabilitar otimizações específicas durante a compilação do código.
 * Ele pode ser útil para ajustar o desempenho de certas partes do programa, garantindo
 * que algumas otimizações sejam aplicadas ou evitadas.
 * Parâmetros comuns do #pragma optimize:
 * "g" -> Otimizações gerais
 * "s" -> Minimiza tamanho do código
 * "t" -> Favorece desempenho
 * "y" -> Habilita análise de código inalterado
 * Para compiladores não MSVC, você precisaria usar outras formas de controle de
 * otimização específicas para esses compiladores (por exemplo, flags de compilação
 * como -O0, -O1, -O2, etc. em GCC e Clang).
 */

#pragma optimize("g", off) // Desativa otimizações
void funcaoSemOtmizacao()
{
    printf("Esta função está sem otimizações.\n");
}

#pragma optimize("g", on) // Ativa otimizações
void funcaoComOtmizacao()
{
    printf("Esta função está com otimizações.\n");
}

int main(int argc, char **argv)
{
    funcaoSemOtmizacao();
    funcaoComOtmizacao();
    return 0;
}
