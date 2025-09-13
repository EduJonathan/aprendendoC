#include <stdio.h>

// A diretiva #pragma region é específica do compilador Microsoft Visual Studio utilizada
// para agrupar blocos de código em regiões. Isso pode ser útil para organizar e estruturar
// o código-fonte de uma maneira mais legível e modular.

/* Iniciando uma região de 2 funções matemáticas*/
#pragma region SecaodeFuncoesMatematicas

int soma(int a, int b) { return a + b; }
int subtracao(int a, int b) { return a - b; }

/* Declara o fim da região */
#pragma endregion

#pragma region Secao_Principal

int main(int argc, char **argv)
{
    int resultado = soma(5, 3);
    printf("Resultado da soma: %d\n", resultado);

    resultado = subtracao(10, 4);
    printf("Resultado da subtração: %d\n", resultado);
    return 0;
}

#pragma endregion

// o código foi dividido em duas regiões usando #pragma region. A primeira região agrupa funções
// matemáticas (soma e subtracao), e a segunda região agrupa a função main. não é uma prática
// universalmente aceita e pode não ser suportado por todos os compiladores. Portanto, é uma
// funcionalidade específica do Microsoft Visual Studio e pode não funcionar corretamente em
// outros ambientes de desenvolvimento.
