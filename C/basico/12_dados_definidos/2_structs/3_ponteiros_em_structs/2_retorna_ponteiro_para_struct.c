#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Definição de uma estrutura chamada 'ponto' que representa um ponto em 2D.
 *
 * A estrutura 'ponto' armazena as coordenadas `x` e `y`.
 */
struct funcao_pointer_struct
{
    int x; /**< Coordenada x do ponto */
    int y; /**< Coordenada y do ponto */
};

/**
 * @brief Procedimento que recebe dois valores inteiros, aloca dinamicamente a estrutura
 * funcao_pointer_struct.
 *
 * @param valor_x atribui os valores fornecidos aos seus campos e retorna um ponteiro para a
 * estrutura alocada. 
 * @param valor_y atribui os valores fornecidos aos seus campos e retorna um ponteiro para a
 * estrutura alocada.
 * 
 * @return Retorna um ponteiro para struct com alocação dinâmica
 */
struct funcao_pointer_struct *modificacao(int valor_x, int valor_y)
{
    // Declaração de um ponteiro para funcao_pointer_struct
    struct funcao_pointer_struct *ptr = NULL;

    // Alocação dinâmica de memória para a estrutura funcao_pointer_struct
    ptr = (struct funcao_pointer_struct *)malloc(sizeof(struct funcao_pointer_struct));

    // Atribuição dos valores fornecidos aos campos x e y da estrutura
    ptr->x = valor_x;
    ptr->y = valor_y;

    // Retorna o ponteiro para a estrutura alocada
    return ptr;
}

/**
 * @brief Imprime os valores dos campos x e y de uma estrutura `funcao_pointer_struct`.
 * Esta função recebe um ponteiro para uma estrutura `funcao_pointer_struct` e imprime
 * os valores dos campos `x` e `y` dessa estrutura.
 *
 * @param values Ponteiro para uma estrutura `funcao_pointer_struct` cujos campos serão impressos.
 */
void print(struct funcao_pointer_struct *values)
{
    // Imprime os valores dos campos x e y da estrutura referenciada pelo ponteiro
    printf(" Valor de x: %d\t Valor de y = %d\n", values->x, values->y);
}

int main(int argc, char **argv)
{
    // Declaração de um ponteiro para funcao_pointer_struct
    struct funcao_pointer_struct *ponteiro_modificador = NULL;

    // Variáveis para inserção de valores
    int x;
    int y;

    // Solicita ao usuário que digite um valor para a variável x
    printf("Digite o valor para x: ");
    scanf("%d", &x);

    // Solicita ao usuário que digite um valor para a variável y
    printf("Digite o valor para y: ");
    scanf("%d", &y);

    // Chama a função modificacao, passando os valores de x e y como argumentos,
    // e armazena o ponteiro retornado em ponteiro_modificador
    ponteiro_modificador = modificacao(x, y);

    // Chama a função print, passando o ponteiro ponteiro_modificador como argumento,
    // para imprimir os valores dos campos x e y da estrutura alocada dinamicamente
    print(ponteiro_modificador);

    // Libera a memória alocada dinamicamente pela função modificacao
    free(ponteiro_modificador);
    return 0;
}
