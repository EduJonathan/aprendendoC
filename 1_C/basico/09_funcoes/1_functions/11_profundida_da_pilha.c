#include <stdio.h>

/**
 * @brief Conceito de Profundidade da Pilha (Call Stack Depth).
 *
 * **Definição**
 * - A profundidade da pilha representa o número de quadros de ativação (*stack frames*)
 *   atualmente presentes na pilha de chamadas.
 * - Cada vez que uma função é invocada, um novo quadro é empilhado; quando a função termina,
 *   esse quadro é removido.
 *
 * **Diferença em relação ao uso de memória**
 * - Enquanto o uso de memória indica a quantidade de bytes ocupados, a profundidade da pilha
 *   indica quantas funções estão ativas no momento da execução.
 * - A profundidade é, portanto, uma métrica de contagem de chamadas, não de tamanho em bytes.
 *
 * **Impacto prático**
 * - Em chamadas recursivas, a profundidade pode crescer rapidamente, aumentando o risco de
 *   *stack overflow* (estouro da pilha) caso não haja uma condição de parada adequada.
 * - Monitorar ou limitar a profundidade é útil para projetar funções recursivas seguras e
 *   otimizar o consumo de recursos.
 *
 * **Boas práticas**
 * - Garantir que funções recursivas tenham um caso base claro para encerrar a recursão.
 * - Sempre que possível, considerar algoritmos iterativos ou técnicas como
 *   *tail call optimization* para manter a profundidade controlada.
 */

/**
 * @brief Exibe a profundidade atual da pilha com o nome da função.
 *
 * @param profundidade Nível atual da pilha.
 * @param nome_funcao Nome da função para contexto.
 */
void imprimirProfundidade(int profundidade, const char *nome_funcao)
{
    printf("%*sProfundidade em %s: %d\n", profundidade * 2, "", nome_funcao, profundidade);
}

/**
 * @brief Função de nível 3 (folha da chamada).
 *
 * @param profundidade Nível atual da pilha.
 * @return Novo valor da profundidade após a execução.
 */
int nivel3(int profundidade)
{
    profundidade++;
    imprimirProfundidade(profundidade, "nivel3");
    return profundidade - 1;
}

/**
 * @brief Função de nível 2, chama nivel3.
 *
 * @param profundidade Nível atual da pilha.
 * @return Novo valor da profundidade após a execução.
 */
int nivel2(int profundidade)
{
    profundidade++;
    imprimirProfundidade(profundidade, "nivel2");
    profundidade = nivel3(profundidade);
    return profundidade - 1;
}

/**
 * @brief Função de nível 1, chama nivel2.
 *
 * @param profundidade Nível atual da pilha.
 * @return Novo valor da profundidade após a execução.
 */
int nivel1(int profundidade)
{
    profundidade++;
    imprimirProfundidade(profundidade, "nivel1");
    profundidade = nivel2(profundidade);
    return profundidade - 1;
}

/**
 * @brief Calcula a soma dos n primeiros números naturais usando recursão e exibe a profundidade da pilha.
 *
 * @param n Número de termos a somar.
 * @param profundidade Nível atual da pilha.
 * @return Soma dos números de 1 a n.
 */
int n_natural(int n, int profundidade)
{
    imprimirProfundidade(profundidade, "n_natural");
    if (n == 0)
    {
        return 0; // Caso base: se n for 0, retorna 0
    }
    return n_natural(n - 1, profundidade + 1) + n; // Chamada recursiva para somar n com n-1
}

int main(int argc, char **argv)
{
    printf("\n=== Demonstração de Profundidade da Pilha ===\n");
    int profundidade = 0;

    profundidade++;
    imprimirProfundidade(profundidade, "main");
    profundidade = nivel1(profundidade);
    profundidade--;

    printf("Fim da execução, profundidade final: %d\n", profundidade);

    printf("-----------------------------------------\n");

    printf("\n=== Demonstração de Profundidade da Pilha (Recursiva - Soma dos 5 primeiros números naturais) ===\n");

    profundidade = 1;
    imprimirProfundidade(profundidade, "main");

    int resultado_natural = n_natural(5, profundidade + 1);
    profundidade--;
    printf("Soma dos 5 primeiros números naturais = %d\n", resultado_natural);
    printf("Fim da execução (recursiva - n_natural), profundidade final: %d\n", profundidade);

    /**
     * Ordem das chamadas de função (recursiva - n_natural)
     * main()
     * |--------n_natural(5)
     *          |--------n_natural(4)
     *                  |--------n_natural(3)
     *                          |--------n_natural(2)
     *                                  |--------n_natural(1)
     *                                          |--------n_natural(0)
     */
    return 0;
}
