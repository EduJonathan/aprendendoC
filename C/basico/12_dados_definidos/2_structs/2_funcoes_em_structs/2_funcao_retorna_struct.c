#include <stdio.h>

/**
 * @brief Definição de uma estrutura chamada `funcao_struct` com dois campos inteiros: x e y.
 * A estrutura `funcao_struct` é usada para armazenar dois valores inteiros, representando as
 * coordenadas.
 */
struct funcao_struct
{
    int x; /**< Coordenada x do ponto */
    int y; /**< Coordenada y do ponto */
};

/**
 * @brief Função que recebe uma estrutura `funcao_struct` como argumento, modifica seus
 * campos e retorna a estrutura modificada. Esta função adiciona 10 ao valor do campo `x`
 * e 20 ao valor do campo `y` da estrutura fornecida. Em seguida, retorna a estrutura
 * modificada.
 *
 * @param modificador Estrutura `funcao_struct` cujos campos serão modificados.
 * @return Estrutura `funcao_struct` com os campos `x` e `y` modificados.
 */
struct funcao_struct modificar(struct funcao_struct modificador)
{
    // Modifica o valor do campo x, adicionando 10 ao valor original
    modificador.x = modificador.x + 10;

    // Modifica o valor do campo y, adicionando 20 ao valor original
    modificador.y += 20; // modificador.y = modificador.y + 20;

    // Retorna a estrutura modificada
    return modificador;
}

/**
 * @brief Função que recebe uma estrutura `funcao_struct` como argumento e imprime
 * os valores de seus campos `x` e `y`. Esta função imprime os valores dos campos `x` e `y`
 * da estrutura fornecida.
 *
 * @param values Estrutura `funcao_struct` cujos campos serão impressos.
 */
void print(struct funcao_struct values)
{
    // Imprime os valores dos campos x e y da estrutura
    printf("Valor de x: %d\tValor de y = %d\n", values.x, values.y);
}

int main(int argc, char **argv)
{
    // Declaração `struct funcao_struct`: acessa_campo e valor_modificado que irá acessar `x` e `y`
    struct funcao_struct acessa_campo;

    // Solicita ao usuário que digite um valor para o campo x da estrutura acessa_campo
    printf("Digite o valor para x: ");
    scanf("%d", &acessa_campo.x);

    // Solicita ao usuário que digite um valor para o campo y da estrutura acessa_campo
    printf("Digite o valor para y: ");
    scanf("%d", &acessa_campo.y);

    // Declaração do tipo `struct funcao_struct`: valor_modificado que irá
    // receber a função `modificar`
    struct funcao_struct valor_modificado;

    // Chama a função modificar, passando a estrutura acessa_campo como argumento,
    // e armazena o resultado em valor_modificado
    valor_modificado = modificar(acessa_campo);

    // Chama a função print, passando a estrutura valor_modificado como argumento,
    // para imprimir os valores dos campos x e y
    print(valor_modificado);
    return 0;
}
