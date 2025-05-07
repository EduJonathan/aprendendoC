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
 * e também reduzir a profundidade da para economizar pilha, otimizando com
 * ("tail call optimization").
 */

/**
 * @brief Função que irá ser repassada a outras funções
 */
void funcaoC()
{
    printf("Função C Chamada\n");
}

/**
 * @brief Função que irá ser invocar a funcaoC()
 */
void funcaoB()
{
    // FuncaoB chama FuncaoC
    funcaoC();
}

/**
 * @brief Função que irá ser invocar a funcaoB() para invocar a funcaoC()
 */
void funcaoA()
{
    // FuncaoA chama FuncaoB
    funcaoB();
}

/**
 * @brief Irá inserir o ano que o usuário nasceu e retorna-lo
 */
int lerAno()
{
    int ano = 0;
    printf("Digite o ano que você nasceu: ");
    scanf("%d", &ano);
    return ano;
}

/**
 * @brief Irá calcular o ano que o usuário nasceu e com o ano atual(2025) retornando a idade
 *
 * @param ano Pega o ano que o usuário nasceu
 */
int calcularIdade(int ano)
{
    int idade = 2025 - ano;
    return idade;
}

/**
 * @brief Irá apresentar a idade do usuário
 *
 * @param idade Parâmetro para informar e apresentar a idade do usuário
 */
void suaIdadeE(int idade)
{
    printf("Você tem: %d", idade);
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

    int ano = lerAno(); // A função só irá sair após o valor de entrada
    int idade = calcularIdade(ano);
    suaIdadeE(idade);
    return 0;
}
