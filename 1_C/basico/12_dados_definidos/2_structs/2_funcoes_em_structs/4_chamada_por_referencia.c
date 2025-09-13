#include <stdio.h>

/**
 * @brief Definição de uma estrutura chamada `ponto` com dois campos inteiros: x e y.
 * Estrutura usada para representar um ponto em um sistema de coordenadas 2D, armazenando
 * as coordenadas
 */
struct ponto
{
    int x; /**< Coordenada x do ponto */
    int y; /**< Coordenada y do ponto */
};

/**
 * @brief Modifica os valores das coordenadas de um ponto usando chamada por referência.
 * Esta função recebe dois ponteiros para inteiros e modifica os valores que eles apontam.
 * Geralmente, os ponteiros apontam para as coordenadas x e y de um ponto. aplicando uma
 * modificação aos valores de coordenadas passados como argumentos.
 *
 * @param ptrx Ponteiro para a coordenada x do ponto a ser modificada.
 * @param ptry Ponteiro para a coordenada y do ponto a ser modificada.
 */
void modifyPoint(int *ptrx, int *ptry)
{
    // Incrementa o valor apontado por ptrx em 5
    *ptrx = *ptrx + 5;

    // Decrementa o valor apontado por ptry em 5
    *ptry = *ptry - 5;
}

/**
 * @brief Imprime as coordenadas de um ponto.
 * Esta função recebe as coordenadas x e y de um ponto e imprime seus valores.
 *
 * @param x Coordenada x do ponto a ser impressa.
 * @param y Coordenada y do ponto a ser impressa.
 */
void print(int x, int y)
{
    // Imprime as coordenadas x e y do ponto
    printf("As coordenadas do ponto x são: %d, e ponto y é: %d\n", x, y);
}

int main(int argc, char **argv)
{
    // Declaração e inicialização de uma variável do tipo ponto chamada acesse
    struct ponto acesse = {5, 15};

    // Chama a função modifyPoint, passando os endereços dos membros x e y de acesse
    modifyPoint(&acesse.x, &acesse.y);

    // Chama a função print, passando os valores dos membros x e y de acesse
    // para imprimir as coordenadas do ponto
    print(acesse.x, acesse.y);
    return 0;
}
