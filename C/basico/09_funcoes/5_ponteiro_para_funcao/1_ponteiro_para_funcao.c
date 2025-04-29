#include <stdio.h>

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
