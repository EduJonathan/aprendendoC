#include <stdio.h>
#include <string.h>

/* __func__: Exibe o nome da função na qual a macro __func__ é exibida. */

#define MAX_STACK 100 /**< Tamanho máximo da pilha de chamadas */

/* Array to store call stack history */
static const char *callStack[MAX_STACK];
static int callCount = 0;  /* Conta chamadas totais */
static int stackDepth = 0; /* Rastreia profundidade atual */
static int maxDepth = 0;   /* Armazena profundidade máxima */

/**
 * @brief Função de exemplo que utiliza __func__ para exibir o nome da função atual.
 */
void myFunction(void)
{
    printf("Nome da função: %s\n", __func__);
}

/**
 * @brief Macro para rastrear a entrada nas funções e armazenar o nome na pilha.
 * Verifica overflow da pilha e armazena o nome da função.
 */
#define ENTRAR_NA_FUNCAO()                                                                           \
    {                                                                                                \
        if (stackDepth >= MAX_STACK)                                                                 \
        {                                                                                            \
            fprintf(stderr, "Erro: Pilha de chamadas cheia (limite: %d)!\n", MAX_STACK);             \
        }                                                                                            \
        callCount++;                                                                                 \
        stackDepth++;                                                                                \
        callStack[stackDepth - 1] = __func__; /* Store function name */                              \
        if (stackDepth > maxDepth)                                                                   \
            maxDepth = stackDepth;                                                                   \
        printf("\n-> Chamada %2d | Pilha: %2d | Entrando em %s\n", callCount, stackDepth, __func__); \
    }

/**
 * @brief Macro para rastrear a saída de funções.
 * Decrementa a profundidade da pilha e imprime a saída.
 */
#define SAINDO_DA_FUNCAO()                                                                         \
    {                                                                                              \
        printf("<- Chamada %2d | Pilha: %2d | Saindo de %s\n", callCount, stackDepth, __func__); \
        stackDepth--;                                                                              \
    }

// ---- Funções Para Exemplificar ---- //
void funcao3()
{
    ENTRAR_NA_FUNCAO();
    printf("   Executando operação em funcao3...\n");
    SAINDO_DA_FUNCAO();
}

void funcao2()
{
    ENTRAR_NA_FUNCAO();
    printf("   Chamando funcao3...\n");
    funcao3(); // Chamada aninhada
    SAINDO_DA_FUNCAO();
}

void funcao1()
{
    ENTRAR_NA_FUNCAO();
    printf("   Chamando funcao2...\n");
    funcao2(); // Chamada aninhada
    SAINDO_DA_FUNCAO();
}

int main(int argc, char **argv)
{
    printf("Nome da função: %s\n", __func__);
    myFunction();
    printf("\n--------------------------------\n");

    ENTRAR_NA_FUNCAO();
    printf("   Chamando funcao1...\n");
    funcao1();

    printf("   Chamando funcao3 diretamente...\n");
    funcao3();
    SAINDO_DA_FUNCAO();

    // Resumo final
    printf("\nEstatísticas:\n");
    printf("Total de chamadas: %d\n", callCount);
    printf("Profundidade máxima da pilha: %d\n", maxDepth);
    printf("Histórico da pilha de chamadas:\n");

    for (int i = 0; i < maxDepth; i++)
    {
        if (callStack[i])
        {
            printf("  [%d] %s\n", i + 1, callStack[i]);
        }
    }
    return 0;
}
