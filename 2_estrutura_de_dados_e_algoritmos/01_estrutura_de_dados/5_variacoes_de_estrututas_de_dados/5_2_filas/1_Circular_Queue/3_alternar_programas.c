#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/// Número máximo de programas que podem estar abertos simultaneamente
#define MAXIMO_PROGRAMAS 10

/// Tamanho máximo do nome de um programa (incluindo '\0')
#define MAX_NOME_PROGRAMA 20

/// Mensagem exibida quando o limite da fila é atingido
#define MSG_LIMITE "Limite atingido! Remova um ou mais programas para adicionar outro."

/// Mensagem exibida quando não há programas na fila
#define MSG_VAZIA "Não há programas abertos."

/// Mensagem exibida quando o nome do programa excede o limite
#define MSG_NOME_LONGO "Nome do programa muito longo! Máximo de %d caracteres."

/**
 * @brief Estrutura que representa uma fila circular de nomes de programas.
 */
typedef struct
{
    char programas[MAXIMO_PROGRAMAS][MAX_NOME_PROGRAMA]; /**< Lista de nomes dos programas */
    size_t front;                                        /**< Índice do início da fila */
    size_t rear;                                         /**< Índice do fim da fila */
    size_t tamanho;                                      /**< Quantidade atual de programas na fila */
} CircularQueue;

/**
 * @brief Inicializa a fila circular.
 *
 * @param fila Ponteiro para a fila a ser inicializada.
 */
void inicializarFila(CircularQueue *fila)
{
    fila->front = 0;
    fila->rear = -1;
    fila->tamanho = 0;
    for (size_t i = 0; i < MAXIMO_PROGRAMAS; i++)
    {
        fila->programas[i][0] = '\0';
    }
}

/**
 * @brief Verifica se a fila está vazia.
 *
 * @param fila Ponteiro para a fila.
 * @return true se a fila estiver vazia, false caso contrário.
 */
bool filaVazia(CircularQueue *fila) { return fila->tamanho == 0; }

/**
 * @brief Verifica se a fila está cheia.
 *
 * @param fila Ponteiro para a fila.
 * @return true se a fila estiver cheia, false caso contrário.
 */
bool filaCheia(CircularQueue *fila) { return fila->tamanho == MAXIMO_PROGRAMAS; }

/**
 * @brief Adiciona um programa à fila.
 *
 * @param fila Ponteiro para a fila.
 * @param nome Nome do programa a ser adicionado.
 * @return true se o programa foi adicionado com sucesso, false caso contrário.
 */
bool abrirPrograma(CircularQueue *fila, const char *nome)
{
    if (nome == NULL || nome[0] == '\0')
        return false;

    if (strlen(nome) >= MAX_NOME_PROGRAMA)
        return false;

    if (filaCheia(fila))
        return false;

    fila->rear = (fila->rear + 1) % MAXIMO_PROGRAMAS;
    strncpy(fila->programas[fila->rear], nome, MAX_NOME_PROGRAMA - 1);
    fila->programas[fila->rear][MAX_NOME_PROGRAMA - 1] = '\0';
    fila->tamanho++;
    return true;
}

/**
 * @brief Alterna para o próximo programa na fila.
 *
 * @param fila Ponteiro para a fila.
 * @return true se a alternância foi possível, false caso contrário.
 */
bool alternarPrograma(CircularQueue *fila)
{
    if (filaVazia(fila) || fila->tamanho == 1)
        return false;

    fila->front = (fila->front + 1) % MAXIMO_PROGRAMAS;
    return true;
}

/**
 * @brief Exibe o programa que está atualmente em execução.
 *
 * @param fila Ponteiro para a fila.
 */
void programaAtual(CircularQueue *fila)
{
    if (filaVazia(fila))
    {
        printf("%s\n", MSG_VAZIA);
        return;
    }

    printf("Programa em execução: %s (Posição: %zu)\n", fila->programas[fila->front], fila->front);
}

/**
 * @brief Lista todos os programas atualmente na fila.
 *
 * @param fila Ponteiro para a fila.
 */
void listarProgramas(CircularQueue *fila)
{
    if (filaVazia(fila))
    {
        printf("%s\n", MSG_VAZIA);
        return;
    }

    printf("Ordem da fila circular dos programas:\n");
    size_t pos = fila->front;
    for (size_t i = 0; i < fila->tamanho; i++)
    {
        printf("[%zu] %s\n", pos, fila->programas[pos]);
        pos = (pos + 1) % MAXIMO_PROGRAMAS;
    }
}

/**
 * @brief Encerra (remove) o programa atualmente em execução.
 *
 * @param fila Ponteiro para a fila.
 * @return true se o programa foi encerrado com sucesso, false se a fila estiver vazia.
 */
bool encerrarPrograma(CircularQueue *fila)
{
    if (filaVazia(fila))
        return false;

    fila->front = (fila->front + 1) % MAXIMO_PROGRAMAS;
    fila->tamanho--;

    if (fila->tamanho == 0)
        fila->rear = -1;

    return true;
}

/**
 * @brief Exibe o estado atual da fila (modo debug).
 *
 * @param fila Ponteiro para a fila.
 */
void mostrarEstadoFila(CircularQueue *fila)
{
    printf("\nEstado da Fila (Debug):\n");
    printf("Frente: %zu | Trás: %zu | Tamanho: %zu\n", fila->front, fila->rear, fila->tamanho);
    printf("Índices ocupados: ");
    if (filaVazia(fila))
    {
        printf("Nenhum\n");
        return;
    }

    size_t pos = fila->front;
    for (size_t i = 0; i < fila->tamanho; i++)
    {
        printf("%zu ", pos);
        pos = (pos + 1) % MAXIMO_PROGRAMAS;
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    CircularQueue alt_tab = {0};
    inicializarFila(&alt_tab);
    printf("=== Simulador ALT+TAB (Fila Circular FIFO) ===\n");

    const char *programas[] = {
        "Google Chrome",
        "Vs Code",
        "Excel",
        "Word",
        "Este nome é muito longo para caber no buffer"};

    for (size_t i = 0; i < 5; i++)
    {
        if (!abrirPrograma(&alt_tab, programas[i]))
        {
            printf("Erro ao abrir '%s': %s\n", programas[i],
                   strlen(programas[i]) >= MAX_NOME_PROGRAMA ? MSG_NOME_LONGO : MSG_LIMITE);
        }
        else
        {
            printf("Programa '%s' aberto. (Posição: %zu)\n", programas[i], alt_tab.rear);
        }
    }

    mostrarEstadoFila(&alt_tab);
    listarProgramas(&alt_tab);
    programaAtual(&alt_tab);

    for (int i = 0; i < 6; i++)
    {
        if (alternarPrograma(&alt_tab))
        {
            printf("Alternando para '%s'\n", alt_tab.programas[alt_tab.front]);
        }
        else
        {
            printf(filaVazia(&alt_tab) ? MSG_VAZIA : "Apenas um programa aberto: %s\n", alt_tab.programas[alt_tab.front]);
        }
    }

    while (!filaVazia(&alt_tab))
    {
        printf("Programa '%s' encerrado.\n", alt_tab.programas[alt_tab.front]);
        encerrarPrograma(&alt_tab);
        mostrarEstadoFila(&alt_tab);
    }

    programaAtual(&alt_tab);
    alternarPrograma(&alt_tab);
    encerrarPrograma(&alt_tab);

    return 0;
}
