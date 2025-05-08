#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAXIMO_PROGRAMAS 10
#define MAX_NOME_PROGRAMA 20

// Constantes para mensagens
#define MSG_LIMITE "Limite Atingido! Remova um ou mais programas para adicionar outro\n"
#define MSG_VAZIA "Não há programas abertos\n"
#define MSG_NOME_LONGO "Nome do programa muito longo! Máximo de %d caracteres.\n"

/**
 * @brief Estrutura de dados que representa a fila circular.
 */
typedef struct fila
{
    char programas[MAXIMO_PROGRAMAS][MAX_NOME_PROGRAMA]; /**< Array de programas */
    int frente;                                          /**< Índice do programa que está na frente da fila */
    int tras;                                            /**< Índice do programa que está no final da fila */
    size_t tamanho;                                      /**< Número de programas atualmente na fila */
} filaCircular;

/**
 * @brief Inicializa a fila circular, configurando os índices da frente e trás.
 *
 * @param fila Ponteiro para a estrutura fila a ser inicializada
 */
void inicializarFila(filaCircular *fila)
{
    fila->frente = 0;
    fila->tras = -1;
    fila->tamanho = 0;
}

/**
 * @brief Verifica se a fila está vazia.
 *
 * @param fila Ponteiro para a estrutura fila
 * @return true se a fila estiver vazia, false caso contrário
 */
bool filaVazia(filaCircular *fila) { return fila->tamanho == 0; }

/**
 * @brief Verifica se a fila está cheia.
 *
 * @param fila Ponteiro para a estrutura fila
 * @return true se a fila estiver cheia, false caso contrário
 */
bool filaCheia(filaCircular *fila) { return fila->tamanho == MAXIMO_PROGRAMAS; }

/**
 * @brief Abre um programa e adiciona na fila. Se a fila estiver cheia, exibe uma mensagem de erro.
 *
 * @param fila Ponteiro para a estrutura fila
 * @param nome Nome do programa a ser aberto
 */
void abrirPrograma(filaCircular *fila, const char *nome)
{
    if (strlen(nome) >= MAX_NOME_PROGRAMA)
    {
        printf(MSG_NOME_LONGO, MAX_NOME_PROGRAMA - 1);
        return;
    }

    if (filaCheia(fila))
    {
        printf(MSG_LIMITE);
        return;
    }

    fila->tras = (fila->tras + 1) % MAXIMO_PROGRAMAS;
    strncpy(fila->programas[fila->tras], nome, MAX_NOME_PROGRAMA - 1);
    fila->programas[fila->tras][MAX_NOME_PROGRAMA - 1] = '\0'; // Garantir que o nome seja terminado com '\0'
    fila->tamanho++;
    printf("Programa '%s' aberto. (Posição: %d)\n", nome, fila->tras);
}

/**
 * @brief Alterna o programa atual para o próximo na fila.
 *
 * @param fila Ponteiro para a estrutura fila
 */
void alternarPrograma(filaCircular *fila)
{
    if (filaVazia(fila))
    {
        printf(MSG_VAZIA);
        return;
    }

    if (fila->tamanho == 1)
    {
        printf("Apenas um programa aberto: %s\n", fila->programas[fila->frente]);
        return;
    }

    printf("Alternando de '%s' para ", fila->programas[fila->frente]);

    // Movimento eficiente sem cópia de string
    fila->tras = (fila->tras + 1) % MAXIMO_PROGRAMAS;
    strcpy(fila->programas[fila->tras], fila->programas[fila->frente]);
    fila->frente = (fila->frente + 1) % MAXIMO_PROGRAMAS;

    printf("'%s'\n", fila->programas[fila->frente]);
}

/**
 * @brief Exibe o programa atual em execução (programa na frente da fila).
 *
 * @param fila Ponteiro para a estrutura fila
 */
void programaAtual(filaCircular *fila)
{
    if (filaVazia(fila))
    {
        printf(MSG_VAZIA);
        return;
    }

    printf("\nPrograma em execução: %s (Posição: %d)\n", fila->programas[fila->frente], fila->frente);
}

/**
 * @brief Exibe a lista de programas atualmente na fila.
 *
 * @param fila Ponteiro para a estrutura fila
 */
void listarProgramas(filaCircular *fila)
{
    if (filaVazia(fila))
    {
        printf(MSG_VAZIA);
        return;
    }

    printf("\nOrdem da fila circular dos programas:\n");
    int pos = fila->frente;

    for (int i = 0; i < fila->tamanho; i++)
    {
        printf("[%d] %s\n", pos, fila->programas[pos]);
        pos = (pos + 1) % MAXIMO_PROGRAMAS;
    }
}

/**
 * @brief Encerrar o programa atual, removendo-o da fila.
 *
 * @param fila Ponteiro para a estrutura fila
 */
void encerrarPrograma(filaCircular *fila)
{
    if (filaVazia(fila))
    {
        printf(MSG_VAZIA);
        return;
    }

    printf("Programa '%s' encerrado.\n", fila->programas[fila->frente]);

    fila->frente = (fila->frente + 1) % MAXIMO_PROGRAMAS;
    fila->tamanho--;

    if (fila->tamanho == 0)
    {
        fila->tras = -1; // Resetar a fila quando esvaziar
    }
}

/**
 * @brief Função de depuração que exibe o estado atual da fila.
 *
 * @param fila Ponteiro para a estrutura fila
 */
void mostrarEstadoFila(filaCircular *fila)
{
    printf("\nEstado da Fila (Debug):\n");
    printf("Frente: %d | Tras: %d | Tamanho: %zu\n", fila->frente, fila->tras, fila->tamanho);
    printf("Índices ocupados: ");

    if (filaVazia(fila))
    {
        printf("Nenhum\n");
        return;
    }

    int pos = fila->frente;
    for (int i = 0; i < fila->tamanho; i++)
    {
        printf("%d ", pos);
        pos = (pos + 1) % MAXIMO_PROGRAMAS;
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    filaCircular alt_tab;
    inicializarFila(&alt_tab);

    // Demonstração das funcionalidades
    printf("=== Simulador ALT+TAB (Fila Circular FIFO) ===\n");

    // Abrindo programas
    abrirPrograma(&alt_tab, "Google Chrome");
    abrirPrograma(&alt_tab, "Vs Code");
    abrirPrograma(&alt_tab, "Excel");
    abrirPrograma(&alt_tab, "Word");
    abrirPrograma(&alt_tab, "Este nome é muito longo para caber no buffer"); // Será rejeitado

    mostrarEstadoFila(&alt_tab);
    listarProgramas(&alt_tab);
    programaAtual(&alt_tab);

    // Alternando programas
    for (int i = 0; i < 6; i++)
    {
        alternarPrograma(&alt_tab);
    }

    // Encerrando programas
    while (!filaVazia(&alt_tab))
    {
        encerrarPrograma(&alt_tab);
        mostrarEstadoFila(&alt_tab);
    }

    // Testando com fila vazia
    programaAtual(&alt_tab);
    alternarPrograma(&alt_tab);
    encerrarPrograma(&alt_tab);

    return 0;
}
