#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_ANDARES 11
#define ANDAR_MAXIMO 10
#define ANDAR_MINIMO 0

/**
 * @brief Enum que representa a direção do elevador.
 */
typedef enum
{
    PARADO = 0,   /**< Elevador parado */
    SUBINDO = 1,  /**< Elevador subindo */
    DESCENDO = -1 /**< Elevador descendo */
} Direcao;

/**
 * @brief Estrutura que representa um nó da fila de solicitações.
 */
typedef struct No
{
    int andar;          /**< Número do andar solicitado */
    struct No *proximo; /**< Ponteiro para o próximo nó da lista */
} No;

/**
 * @brief Estrutura que representa o elevador.
 */
typedef struct elevador
{
    int andarAtual;                    /**< Andar atual do elevador */
    Direcao direcao;                   /**< Direção atual do elevador */
    bool andaresChamados[NUM_ANDARES]; /**< Vetor que indica quais andares foram chamados */
    No *filaSolicitacoes;              /**< Ponteiro para a fila de solicitações (lista ligada) */
} Elevador;

/**
 * @brief Inicializa os parâmetros do elevador.
 *
 * Define o andar atual como 0, a direção como PARADO e limpa a fila de solicitações.
 *
 * @param elevador Ponteiro para a estrutura do elevador.
 */
void inicializarElevador(Elevador *elevador)
{
    elevador->andarAtual = 0;
    elevador->direcao = PARADO;
    elevador->filaSolicitacoes = NULL;
    for (int i = 0; i < NUM_ANDARES; i++)
    {
        elevador->andaresChamados[i] = false;
    }
}

/**
 * @brief Cria um novo nó para a fila de solicitações.
 *
 * @param andar Número do andar a ser armazenado no nó.
 * @return Ponteiro para o novo nó criado ou NULL em caso de erro de alocação.
 */
No *criarNo(int andar)
{
    No *novoNo = (No *)malloc(sizeof(No));
    if (!novoNo)
    {
        printf("Erro de alocação de memória.\n");
        return NULL;
    }
    novoNo->andar = andar;
    novoNo->proximo = NULL;
    return novoNo;
}

/**
 * @brief Adiciona uma nova solicitação de andar à fila do elevador.
 *
 * Ignora chamadas duplicadas ou inválidas. Insere a nova solicitação considerando a direção
 * atual do elevador para otimizar o trajeto.
 *
 * @param elevador Ponteiro para a estrutura do elevador.
 * @param andar Número do andar solicitado (de 0 a 10).
 */
void adicionarSolicitacao(Elevador *elevador, int andar)
{
    if (andar < ANDAR_MINIMO || andar > ANDAR_MAXIMO)
    {
        printf("Andar inválido! Deve estar entre %d e %d.\n", ANDAR_MINIMO, ANDAR_MAXIMO);
        return;
    }

    if (elevador->andaresChamados[andar])
    {
        return; // Solicitação já feita anteriormente
    }

    No *novoNo = criarNo(andar);
    if (!novoNo)
        return;

    // Inserção na fila com base na direção e distância
    No **ptr = &(elevador->filaSolicitacoes);
    while (*ptr != NULL)
    {
        int distanciaAtual = abs((*ptr)->andar - elevador->andarAtual);
        int distanciaNova = abs(andar - elevador->andarAtual);
        bool mesmaDirecao = (elevador->direcao == SUBINDO && (*ptr)->andar >= elevador->andarAtual) ||
                            (elevador->direcao == DESCENDO && (*ptr)->andar <= elevador->andarAtual);

        if ((elevador->direcao != PARADO && mesmaDirecao && distanciaAtual < distanciaNova) ||
            (elevador->direcao == PARADO && distanciaAtual < distanciaNova))
        {
            ptr = &((*ptr)->proximo);
        }
        else
        {
            break;
        }
    }

    novoNo->proximo = *ptr;
    *ptr = novoNo;
    elevador->andaresChamados[andar] = true;

    printf("Solicitação para o andar %d adicionada.\n", andar);
}

/**
 * @brief Remove e retorna o próximo andar a ser atendido.
 *
 * Remove o primeiro nó da fila de solicitações e atualiza o vetor de andares chamados.
 *
 * @param elevador Ponteiro para a estrutura do elevador.
 * @return O número do próximo andar ou -1 se não houver solicitações.
 */
int removerSolicitacao(Elevador *elevador)
{
    if (elevador->filaSolicitacoes == NULL)
    {
        return -1; // Fila vazia
    }

    No *temp = elevador->filaSolicitacoes;
    int andar = temp->andar;
    elevador->filaSolicitacoes = temp->proximo;
    elevador->andaresChamados[andar] = false;
    free(temp);
    return andar;
}

/**
 * @brief Verifica se o estado do elevador é válido.
 *
 * Confirma se o andar atual e a direção estão dentro dos limites válidos.
 *
 * @param elevador Ponteiro para a estrutura do elevador.
 * @return true se o estado for válido, false caso contrário.
 */
bool validarElevador(Elevador *elevador)
{
    if (elevador->andarAtual < ANDAR_MINIMO || elevador->andarAtual > ANDAR_MAXIMO)
    {
        printf("Erro: Andar atual %d inválido.\n", elevador->andarAtual);
        return false;
    }
    if (elevador->direcao != SUBINDO && elevador->direcao != DESCENDO && elevador->direcao != PARADO)
    {
        printf("Erro: Direção %d inválida.\n", elevador->direcao);
        return false;
    }
    return true;
}

/**
 * @brief Exibe o estado atual do elevador.
 *
 * Mostra o andar atual, direção e lista de andares com solicitações pendentes.
 *
 * @param elevador Ponteiro para a estrutura do elevador.
 */
void exibirEstado(Elevador *elevador)
{
    printf("\nEstado do Elevador:\n");
    printf("  Andar Atual: %d\n", elevador->andarAtual);
    printf("  Direção: %s\n", elevador->direcao == SUBINDO ? "Subindo" : elevador->direcao == DESCENDO ? "Descendo"
                                                                                                       : "Parado");
    printf("  Solicitações Pendentes: ");
    if (elevador->filaSolicitacoes == NULL)
    {
        printf("Nenhuma\n");
    }
    else
    {
        No *atual = elevador->filaSolicitacoes;
        while (atual != NULL)
        {
            printf("%d ", atual->andar);
            atual = atual->proximo;
        }
        printf("\n");
    }
}

/**
 * @brief Processa as solicitações da fila e move o elevador.
 *
 * O elevador se move para cada andar solicitado, imprimindo seu movimento e estado atualizado.
 *
 * @param elevador Ponteiro para a estrutura do elevador.
 */
void processarSolicitacoes(Elevador *elevador)
{
    if (!validarElevador(elevador))
    {
        printf("Não é possível processar solicitações devido a estado inválido.\n");
        return;
    }

    while (elevador->filaSolicitacoes != NULL)
    {
        int proximoAndar = removerSolicitacao(elevador);
        if (proximoAndar == -1)
            break;

        // Movimento até o próximo andar
        while (elevador->andarAtual != proximoAndar)
        {
            if (elevador->andarAtual < proximoAndar)
            {
                elevador->andarAtual++;
                elevador->direcao = SUBINDO;
            }
            else
            {
                elevador->andarAtual--;
                elevador->direcao = DESCENDO;
            }
            printf("Elevador no andar %d.\n", elevador->andarAtual);
            exibirEstado(elevador);
        }
        printf("Parando no andar %d para atender solicitação.\n", elevador->andarAtual);
    }

    elevador->direcao = PARADO;
    exibirEstado(elevador);
}

/**
 * @brief Libera a memória da fila de solicitações e limpa os andares chamados.
 *
 * @param elevador Ponteiro para a estrutura do elevador.
 */
void liberarFila(Elevador *elevador)
{
    No *atual = elevador->filaSolicitacoes;
    while (atual != NULL)
    {
        No *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    elevador->filaSolicitacoes = NULL;

    for (int i = 0; i < NUM_ANDARES; i++)
    {
        elevador->andaresChamados[i] = false;
    }
}

int main(int argc, char **argv)
{
    Elevador elevador = {0};
    inicializarElevador(&elevador);

    printf("Solicitações\n");
    adicionarSolicitacao(&elevador, 8);
    adicionarSolicitacao(&elevador, 2);
    adicionarSolicitacao(&elevador, 5);
    adicionarSolicitacao(&elevador, 10);

    exibirEstado(&elevador);
    processarSolicitacoes(&elevador);

    liberarFila(&elevador);
    /**
     * Se chamarmos os andares 8, 2, 5, 10, a ordem de atendimento será 2 → 5 → 8 → 10,
     * e não na ordem em que foram adicionados! Agora, o elevador funciona como uma
     * fila de prioridade, garantindo um atendimento mais eficiente.
     */
    return 0;
}
