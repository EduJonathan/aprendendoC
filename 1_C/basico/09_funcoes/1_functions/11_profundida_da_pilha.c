#include <stdio.h>

/**
 * PROFUNDIDADE DA PILHA: Refere-se ao número de funções ativas (ou empilhadas) no
 * momento atual da execução do programa. Ao contrário do uso de memória real, que
 * mede o espaço ocupado na memória, a profundidade da pilha mede o número de chamadas
 * de função que estão em execução. Esse valor pode aumentar significativamente em casos
 * de chamadas recursivas, especialmente se não houver controle, o que pode levar a problemas
 * como estouro de pilha.
 */

int profundidade = 0; // Variável que vai contabilizar as profundidades das funções

/**
 * @brief Procedimento para informar a quantidade da profundidade atual das funções
 */
void imprimirProfundidade(void)
{
    printf("Profundidade atual: %d\n", profundidade);
}

void funcaoC()
{
    profundidade++;
    imprimirProfundidade();

    // Aqui termina funcaoC
    profundidade--;
}

void funcaoB()
{
    profundidade++;
    imprimirProfundidade();
    funcaoC();
    profundidade--;
}

void funcaoA()
{
    profundidade++;
    imprimirProfundidade();
    funcaoB();
    profundidade--;
}

int main(int argc, char **argv)
{
    profundidade++;
    imprimirProfundidade();
    funcaoA();
    profundidade--;
    return 0;
}
