#include <stdio.h>

/**
 * O que é um Ponteiro para Função?
 * Um ponteiro para função é uma variável que armazena o endereço de uma função.
 * Esse ponteiro pode ser usado para invocar a função à qual ele aponta, assim como uma
 * função normal, mas de forma mais flexível. Isso é útil, por exemplo, quando se deseja passar
 * funções como parâmetros para outras funções, ou quando se precisa escolher dinamicamente
 * qual função chamar.
 *
 * SINTAXE: tipo_retorno (*ponteiro)(tipo_parametro1, tipo_parametro2, ...);
 *
 * São uma maneira poderosa de tornar o código mais flexível e dinâmico, permitindo selecionar
 * e chamar funções de forma indireta. Eles são úteis, por exemplo, em implementações de tabelas
 * de dispersão (hash), algoritmos que dependem de callbacks ou para realizar operações com várias
 * funções em tempo de execução.
 */

/**
 * @brief Função que imprime uma mensagem no console.
 *
 * Esta função demonstra o uso de um ponteiro para função ao imprimir
 * uma mensagem indicando que um ponteiro para função está sendo usado.
 */
void function1(void)
{
    printf("\nIsso é um ponteiro para função!!\n");
}

void welcome(void)
{
    printf("Bem Vindos a linguagem de Programação em C");
}

int main(int argc, char **argv)
{
    void (*mensagemDeBemVindos)();
    mensagemDeBemVindos = welcome;
    (*mensagemDeBemVindos)();

    // Declaração de um ponteiro para uma função que não recebe argumentos e não retorna valor
    void (*ponteiroParaFuncao)();

    // Atribui o endereço da função function1 ao ponteiro ponteiroParaFuncao
    ponteiroParaFuncao = function1;

    // Chama a função através do ponteiro
    (*ponteiroParaFuncao)();
    return 0;
}
