#include <stdio.h>

/**
 * @brief Definição de uma estrutura chamada 'ponto' que representa um ponto em 2D.
 * A estrutura 'ponto' armazena as coordenadas `x` e `y`.
 */
struct ponto
{
    int x; /**< Coordenada x do ponto */
    int y; /**< Coordenada y do ponto */
};

/**
 * @brief Função para imprimir os valores das coordenadas x e y de um ponto.
 * Esta função recebe as coordenadas x e y como parâmetros e imprime seus valores.
 *
 * @param x Coordenada x do ponto a ser impressa.
 * @param y Coordenada y do ponto a ser impressa.
 */
void print(int x, int y)
{
    printf(" Valor do campo do ponto x é: %d\n E Valor do campo do ponto y é: %d", x, y);
}

int main(int argc, char **argv)
{
    // Criação de uma variável `acessa_campo` do tipo `struct ponto` e inicialização
    // com valores 5 e 15.
    struct ponto acessa_campo = {5, 15};

    /*
     * Chamada da função `print` para imprimir os valores das coordenadas x e y
     * da variável `acessa_campo`. print o valor acessando o campo x e y com as structs
     */
    print(acessa_campo.x, acessa_campo.y);
    return 0;
}
