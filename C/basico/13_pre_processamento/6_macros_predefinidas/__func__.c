#include <stdio.h>

/* __func__: Exibe o nome da função na qual macro __func__ é exibido. */

/**
 * @brief Função de exemplo que utiliza a macro __func__ para exibir o nome da função atual.
 */
void myFunction(void)
{
    printf("Nome da função: %s\n", __func__);
}

#define MAX_STACK 100 /**< Tamanho máximo da pilha de chamadas */

// Variáveis para rastrear a pilha
static int callCount = 0;  // Conta chamadas totais
static int stackDepth = 0; // Rastreia profundidade atual
static int maxDepth = 0;   // Armazena a profundidade máxima

/**
 * @brief Macro para rastrear a entrada nas funções e armazenar o nome da função na pilha.
 *
 * Essa macro armazena o nome da função atual em callStack e imprime a entrada na função,
 * além de atualizar a profundidade da pilha.
 */
#define ENTRAR_NA_FUNCAO()                                                                      \
    {                                                                                           \
        callCount++;                                                                            \
        stackDepth++;                                                                           \
        if (stackDepth > maxDepth)                                                              \
            maxDepth = stackDepth;                                                              \
        printf("→ Chamada %d | Pilha: %d (Entrando em %s)\n", callCount, stackDepth, __func__); \
    }

/**
 * @brief Macro para rastrear a saída de funções e exibir o nome da função.
 *
 * A macro decrementa o nível da pilha e imprime o nome da função que está saindo.
 */
#define SAINDO_DA_FUNCAO()                                            \
    {                                                                 \
        stackDepth--;                                                 \
        printf("← Saindo de %s | Pilha: %d\n", __func__, stackDepth); \
    }

// ---- Funções Para Exemplificar ---- //
void funcao3()
{
    ENTRAR_NA_FUNCAO();
    printf("\nExecutando operação em funcao3...\n");
    SAINDO_DA_FUNCAO();
}

void funcao2()
{
    ENTRAR_NA_FUNCAO();
    printf("\nChamando funcao3...\n");
    funcao3(); // Chamada aninhada
    SAINDO_DA_FUNCAO();
}

void funcao1()
{
    ENTRAR_NA_FUNCAO();
    printf("\nChamando funcao2...\n");
    funcao2(); // Chamada aninhada
    SAINDO_DA_FUNCAO();
}

int main(int argc, char **argv)
{
    /* Utilizando a macro __func__ para exibir o nome da função principal ("main"). */
    printf("Nome da função: %s\n", __func__);

    /* Chamando a função. */
    myFunction();

    printf("\n--------------------------------\n");

    ENTRAR_NA_FUNCAO();

    printf("Chamando funcao1...\n");
    funcao1();

    printf("Chamando funcao3 diretamente...\n");
    funcao3(); // Chamada direta

    SAINDO_DA_FUNCAO();

    // Resumo final
    printf("\nEstatísticas:\n");
    printf("Total de chamadas: %d\n", callCount);
    printf("Profundidade máxima da pilha: %d\n", maxDepth);
    return 0;
}
