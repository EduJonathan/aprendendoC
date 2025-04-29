#include <stdio.h>

/**
 * PROFUNDIDADE DA PILHA: Diferente da pilha de chamada, profundidade da pilha é quantas
 * funções estão empilhadas no momento exato. Não medindo o uso real memória e sim o número
 * de chamadas ativas no programa. Chamadas recursivas, este valor pode crescer muito se
 * não tiver controle.
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
