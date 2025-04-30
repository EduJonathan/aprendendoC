#include <stdio.h>

/**
 * MATRIZES: São estruturas de dados bidimensionais (vetor de vetores), com dados organizados
 * em linhas e colunas. Muito usadas para representar tabelas, calendários, jogos (xadrez,
 * batalha naval, etc.), além de aplicações em programação como bancos de dados, planilhas,
 * imagens e jogos.
 *
 * SINTAXE: <tipo de dado><nome da matriz>[Nº linhas][Nº colunas];
 *
 * int matriz[2][3]; Com a declaração temos uma matriz onde temos 2 linhas e 3 colunas
 * que são nossas dimensões
 *
 * EXE:
 *         -------------------------------
 * --------| coluna0 | coluna1 | coluna2 |
 * |linha0 |    []   |   []    |    []   |
 * |linha1 |    []   |   []    |    []   |
 * ---------------------------------------
 *
 * O que delimita uma matriz nos seus valores é o quanto determinarmos para as linhas
 * e as colunas fazendo a multiplicação deles, no meu exemplo eu entreguei 6,
 * pois, 2(linhas) * 3(colunas) = 6.
 * E seu tamanho em bytes é: 2(linhas) * 3(coluna) * 4(nº de byte do tipo de dado) = 24 bytes
 * pegando o exemplo anterior e inicializando os valores
 *
 *          -----------------------------
 * -------- | coluna0| coluna1| coluna2 |
 * | linha0 |   [5]  |   [10] |   [32]  |
 * | linha1 |   [4]  |   [22] |   [96]  |
 * --------------------------------------
 *
 * Cada valor assume uma posição:
 *           -----------------------------
 * ---------| coluna0 | coluna1 | coluna2|
 * | linha0 | [0, 0]  | [0, 1]  | [0, 2] |
 * | linha1 | [1, 0]  | [1, 1]  | [1, 2] |
 * ---------------------------------------
 */

int main(int argc, char **argv)
{
    // Declarando uma matriz
    float mat[2][2];

    // Inicializando os valores um a um
    mat[0][0] = 6.5F;
    mat[0][1] = 7.8F;
    mat[1][0] = 3.6F;
    mat[1][1] = 2.7F;

    printf("\n\t>>IMPRIMINDO MATRIZ POR MATRIZ<<\n");

    printf(" mat [0x0] : %.2f", mat[0][0]);
    printf(" mat [0x1] : %.2f\n", mat[0][1]);
    printf(" mat [1x0] : %.2f", mat[1][0]);
    printf(" mat [1x1] : %.2f\n", mat[1][1]);

    printf("\n\t>>ALTERANDO CONTEÚDO POSIÇÃO POR POSIÇÃO<<\n");

    // Lendo valores de matriz por matriz
    printf(" Digite um valor para [0]x[0]: ");
    scanf("%f", &mat[0][0]);

    printf(" Digite um valor para [0]x[1]: ");
    scanf("%f", &mat[0][1]);

    printf(" Digite um valor para [1]x[0]: ");
    scanf("%f", &mat[1][0]);

    printf(" Digite um valor para [1]x[1]: ");
    scanf("%f", &mat[1][1]);

    printf("\n\t>>EXIBINDO CONTEÚDO ALTERADO<<\n");
    printf(" mat [0x0]: %.2f", mat[0][0]);
    printf(" mat [0x1]: %.2f\n", mat[0][1]);
    printf(" mat [1x0]: %.2f", mat[1][0]);
    printf(" mat [1x1]: %.2f\n", mat[1][1]);

    printf("\n===================================================================\n");
    printf("\n\t>>IMPRIMINDO INFORMAÇÕES SOBRE A MATRIZ 'MAT'<<\n");

    // Obtém o número de linhas na mat
    size_t num_Linhas = sizeof(mat) / sizeof(mat[0]);

    // Obtém o número de colunas na mat
    size_t num_Colunas = sizeof(mat[0]) / sizeof(mat[0][0]);

    // Calcula tamanho total da matriz mat em bytes
    size_t tamanho_Total = num_Linhas * num_Colunas * sizeof(mat[0][0]);

    printf(" Tamanho total da matriz     'mat' : %zu bytes\n", tamanho_Total);
    printf(" Número de linhas da matriz  'mat' : %zu\n", num_Linhas);
    printf(" Número de colunas da matriz 'mat' : %zu\n", num_Colunas);

    printf("\n==================================================================\n");
    printf("\n\t>>IMPRIMINDO INFORMAÇÕES SOBRE MATRIZ<<\n");

    int matriz[2][3] = {{5, 10, 32},  // linha 0
                        {32, 4, 96}}; // linha 1

    /**
     * CURIOSIDADE: É possível preencher uma matriz diretamente como um array
     * EXE: int matriz[2][3] = {5, 10, 32, 32, 4, 96};
     * Mas como se trata de uma matriz o programa irá tratar esta declaração pela
     * quantidade de linhas e colunas onde ele irá separar começando pela linha que em
     * análise ele pega o array por inteiro, porém pela quantidade de colunas ele irá pegar
     * através somente os primeiros valores a qual a quantidade de colunas foi declarada,
     * no nosso caso 3 valores, fazendo assim:
     *
     * int matriz[0][3] = {[0x0] 5,  [0x1] 10, [0x2] 32};
     * int matriz[1][3] = {[1x0] 32, [1x1] 4,  [1x2] 96};
     */

    // Obtendo o número de linhas da matriz
    size_t numLinhas = sizeof(matriz) / sizeof(matriz[0]);

    // Obtendo o número de colunas da matriz
    size_t numColunas = sizeof(matriz[0]) / sizeof(matriz[0][0]);

    // Calcula tamanho total da matriz em bytes
    size_t tamanhoTotal = numLinhas * numColunas * sizeof(matriz[0][0]);

    printf(" Tamanho total da     'matriz' : %zu bytes\n", tamanhoTotal);
    printf(" Número de linhas na  'matriz' : %zu\n", numLinhas);
    printf(" Número de colunas na 'matriz' : %zu\n", numColunas);

    printf("\n=================================================================\n");
    printf("\n\t>>IMPRIMINDO A 'MATRIZ' ATRAVÉS DO FOR ANINHADO<<\n");

    for (int i = 0; i < numLinhas; i++)
    {
        for (int j = 0; j < numColunas; j++)
        {
            printf(" O valor de matriz[%d]x[%d] = %d\t", i, j, matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n====================================================================\n");
    printf("\n\t>>ALTERANDO O VALOR DA 'MATRIZ'<<\n");

    for (int i = 0; i < numLinhas; i++)
    {
        for (int j = 0; j < numColunas; j++)
        {
            printf(" Insira atual de matriz[%d]x[%d] = ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\n=====================================================================\n");
    printf("\n\t>>IMPRIMINDO A 'MATRIZ' COM VALORES ATUALIZADOS PELO SCANF<<\n");

    for (int i = 0; i < numLinhas; i++)
    {
        for (int j = 0; j < numColunas; j++)
        {
            printf(" Valor atual de matriz[%d]x[%d] = %d ", i, j, matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}
