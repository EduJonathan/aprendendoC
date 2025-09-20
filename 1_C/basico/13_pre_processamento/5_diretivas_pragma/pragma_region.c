#include <stdio.h>

/**
 * #pragma region e #pragma endregion: Diretivas específicas do Microsoft Visual C++ (MSVC)
 * usadas para agrupar blocos de código em regiões nomeadas, melhorando a legibilidade e a
 * organização do código-fonte. São úteis para:
 * - Estruturar projetos grandes com seções lógicas (ex.: funções relacionadas, inicialização).
 * - Facilitar a navegação em IDEs como o Visual Studio, onde as regiões podem ser colapsadas/expandidas.
 *
 * Sintaxe:
 * - #pragma region NomeDaRegião: Inicia um bloco nomeado.
 * - #pragma endregion: Finaliza o bloco.
 *
 * Exemplo:
 * - #pragma region SecaoDeFuncoesMatematicas agrupa funções como soma e subtracao.
 * - #pragma region SecaoPrincipal agrupa a função main.
 *
 * Suporte:
 * - Exclusivo do MSVC. GCC, Clang e outros compiladores ignoram essas diretivas, mas o código
 *   compila normalmente, pois elas não afetam a lógica do programa.
 * - Não é padrão C (C11/C17/C23), afetando portabilidade.
 *
 * Boas práticas:
 * - Use nomes claros e descritivos para as regiões (ex.: SecaoDeFuncoesMatematicas).
 * - Evite depender de #pragma region para organização em projetos multiplataforma; use comentários
 *   (ex.: // --- Seção X ---) como alternativa portátil.
 * - Mantenha regiões curtas e focadas para não sobrecarregar a visualização.
 *
 * #pragma region "não possui flags", pois é uma diretiva organizacional que não interage
 * com opções de compilação. Para depuração:
 * gcc -E pragma_region.c > output.c
 *
 * Compilação:
 * - MSVC: cl pragma_region.c
 * - GCC: gcc -std=c17 -Wall -o programa pragma_region.c (ignora #pragma region)
 * - Depuração: gcc -E pragma_region.c (verifica pré-processamento)
 */

// --- Seção de Funções Matemáticas --- (alternativa portátil para GCC/Clang)
#ifdef _MSC_VER
#pragma region SecaoDeFuncoesMatematicas
#endif

int soma(int a, int b) { return a + b; }
int subtracao(int a, int b) { return a - b; }
int multiplicacao(int a, int b) { return a * b; }

#ifdef _MSC_VER
#pragma endregion
#endif
// --- Fim da Seção de Funções Matemáticas ---

// --- Seção Principal ---
#ifdef _MSC_VER
#pragma region SecaoPrincipal
#endif

int main(int argc, char **argv)
{
    int resultado = soma(5, 3);
    printf("Resultado da soma: %d\n", resultado);

    resultado = subtracao(10, 4);
    printf("Resultado da subtração: %d\n", resultado);

    resultado = multiplicacao(6, 7);
    printf("Resultado da multiplicação: %d\n", resultado);

    return 0;
}

#ifdef _MSC_VER
#pragma endregion
#endif
