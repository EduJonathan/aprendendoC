#include <stdio.h>

int main(int argc, char **argv)
{
    /**
     * ERRO NO USO DO VETOR DE PONTEIROS
     *
     * int v1[3] = {1, 2, 3};
     * int v2[3] = {4, 5, 6};
     * int v3[3] = {7, 8, 9};
     * int v4[3] = {10, 11, 12};
     *
     * int *pt[3]; // vetor de ponteiros do tipo inteiro
     *
     * pt[0] = v1;
     * pt[1] = v2;
     * pt[2] = v3;
     * pt[3] = v4;   // <-- ERRO
     *
     * PROBLEMA:
     * A declaração `int *pt[3]` cria um vetor com APENAS TRÊS elementos (pt[0], pt[1], pt[2]).
     * Entretanto, o código tenta escrever em pt[3], que NÃO EXISTE. Isso causa comportamento
     * indefinido. Se a intenção é armazenar quatro vetores, o correto seria:
     *
     *     int *pt[4];
     *
     * ou remover a atribuição a pt[3].
     *
     * ---
     * ERRO NO LOOP:
     *
     * for (int i = 0; i < 3; i++)
     * {
     *     printf("v3[%d] = %d\n", i, (*pt)++);
     * }
     *
     * Nesse caso, `(*pt)` equivale a `pt[0]`, pois `pt` aponta para o primeiro elemento
     * do vetor de ponteiros. Assim, `(*pt)++` incrementa o ponteiro pt[0], fazendo com
     * que ele percorra os elementos de v1 — e não os vetores v1, v2, v3 individualmente.
     *
     * Para acessar cada vetor corretamente, você deve usar pt[i]:
     *
     * for (int i = 0; i < 3; i++)
     * {
     *    printf("v%d[%d] = %d\n", i + 1, i, pt[i][i]);
     * }
     *
     * Ou, se quiser percorrer cada vetor separadamente com ponteiro:
     *
     *     for (int i = 0; i < 3; i++)
     *     {
     *         int *p = pt[i];
     *         for (int j = 0; j < 3; j++)
     *         {
     *             printf("%d ", *(p + j));
     *         }
     *         printf("\n");
     *     }
     *
     * RESUMO:
     * - O tamanho do vetor de ponteiros deve ser suficiente para as atribuições.
     * - `(*pt)` sempre acessa o primeiro ponteiro (pt[0]).
     * - Para acessar os vetores corretamente, use pt[i].
     */

    int v0[3] = {0, 1, 2};   // Vetor 1 com três elementos
    int v1[3] = {3, 4, 5};   // Vetor 2 com três elementos
    int v2[3] = {6, 7, 8};   // Vetor 3 com três elementos
    int v3[3] = {9, 10, 11}; // Vetor 4 com três elementos
    int *pt[4];              // Vetor de ponteiros do tipo inteiro

    pt[0] = v0; // Atribui o endereço do vetor1 para o ponteiro pt[0]
    pt[1] = v1; // Atribui o endereço do vetor2 para o ponteiro pt[1]
    pt[2] = v2; // Atribui o endereço do vetor3 para o ponteiro pt[2]
    pt[3] = v3; // Atribui o endereço do vetor4 para o ponteiro pt[3]

    printf("\n\tIMPRIMINDO VETOR DE PONTEIROS POSIÇÃO POR POSIÇÃO:\n");

    printf(" posição pt[0][0]: %d\t", *(*(pt + 0) + 0));
    printf(" posição pt[0][1]: %d\t", *(*(pt + 0) + 1));
    printf(" posição pt[0][2]: %d\n", *(*(pt + 0) + 2));

    printf(" posição pt[1][0]: %d\t", *(*(pt + 1) + 0));
    printf(" posição pt[1][1]: %d\t", *(*(pt + 1) + 1));
    printf(" posição pt[1][2]: %d\n", *(*(pt + 1) + 2));

    printf(" posição pt[2][0]: %d\t", *(*(pt + 2) + 0));
    printf(" posição pt[2][1]: %d\t", *(*(pt + 2) + 1));
    printf(" posição pt[2][2]: %d\n", *(*(pt + 2) + 2));

    printf(" posição pt[3][0]: %d\t", *(*(pt + 3) + 0));
    printf(" posição pt[3][1]: %d\t", *(*(pt + 3) + 1));
    printf(" posição pt[3][2]: %d\n", *(*(pt + 3) + 2));

    putchar('\n');

    printf("\n=============================================================================\n");

    printf("\n\t\t>>IMPRIMINDO VETOR DE PONTEIROS<<\n");

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("\t pt[%d][%d] = %d ", i, j, pt[i][j]);
        }
        printf("\n");
    }

    printf("\n=============================================================================\n");

    printf("\n\t\t>>IMPRIMINDO VETOR DE PONTEIROS COM A ARITMETICA DE PONTEIROS<<\n");

    // Número de elementos em pt
    size_t num_arrays = sizeof(pt) / sizeof(pt[0]);

    // Tamanho de cada vetor individual
    size_t array_size = sizeof(v0) / sizeof(v0[0]);

    for (size_t i = 0ull; i < num_arrays; i++)
    {
        printf("Elementos do vetor %zu usando aritmética de ponteiros: ", i);
        // Usando aritmética de ponteiros para acessar os elementos do vetor
        for (size_t j = 0ull; j < array_size; j++)
        {
            printf("%d ", *(pt[i] + j)); // *(pt[i] + j) equivalente a pt[i][j]
        }
        printf("\n");
    }
    return 0;
}
