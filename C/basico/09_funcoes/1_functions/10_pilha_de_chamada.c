#include <stdio.h>

/**
 * PILHA DE CHAMADA: É uma estrutura de memória onde o sistema armazena informações
 * todas as vezes que uma função é chamada, conhecida como novo quadro de ativação
 * (stack frame) é empilhadado, quadro este que guarda(Endereço de retorno, que é onde
 * voltar depois que a função terminar), (Parâmetros de funções) e (Variáveis Locais)
 * Quando terminado o quadro é removido(desempilhado) e o controle retorna para quem o chamou.
 *
 * Entender a pilha de chamada faz com que seu código tenha performance para com o custo
 * de menos memória, pois funções que possam tratar de cálculos muitos complexo, ainda
 * mais em funções recursiva infinitas que podem gerar "stack overflow"(estouro de pilha)
 * e também reduzir a profundidade da para economizar pilha, otimizanod com
 * ("tail call optimization").
 */

void funcaoC()
{
    printf("Função C Chamada\n");
}

void funcaoB()
{
    // FuncaoB chama FuncaoC
    funcaoC();
}

void funcaoA()
{
    // FuncaoA chama FuncaoB
    funcaoB();
}

int main(int argc, char **argv)
{
    funcaoA();

    /**
     * Ordem das chamadas de função
     * main()
     * |--------funcaoA()
     *          |--------funcaoB()
     *                  |--------funcaoC()
     */
    return 0;
}
