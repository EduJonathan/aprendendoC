#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Estrutura de um nó na lista de solicitações do elevador.
 *
 * Cada nó representa uma solicitação de andar com o número do andar e um ponteiro
 * para o próximo nó na lista de prioridades.
 *
 * A fila de prioridade é um tipo de estrutura de dados em que cada elemento tem uma
 * prioridade associada. Em uma fila de prioridade, os elementos são processados de acordo
 * com a sua prioridade, ou seja, os elementos com maior prioridade são atendidos primeiro,
 * independentemente da ordem em que foram inseridos. Se dois elementos possuem a mesma prioridade,
 * eles são atendidos conforme a ordem de chegada (First-In-First-Out - FIFO).
 *
 * Este tipo de fila é comumente utilizado em algoritmos de agendamento, simulação de processos
 * e outras aplicações onde a ordem de execução deve ser determinada pela importância de cada tarefa,
 * ao invés de uma ordem estrita de inserção.
 */
typedef struct Node
{
    int andar;         /**< Número do andar solicitado */
    struct Node *next; /**< Ponteiro para o próximo nó na lista */
} Node;

/**
 * @brief Estrutura que representa o elevador.
 *
 * Contém informações sobre o andar atual, direção, andares chamados e a fila de solicitações.
 */
typedef struct elevator
{
    int andarAtual;           /**< Andar atual do elevador */
    int direcao;              /**< Direção do elevador: 1 para subir, -1 para descer, 0 para parado */
    bool andaresChamados[11]; /**< Array de booleanos indicando quais andares foram chamados (0 a 10) */
    Node *filaSolicitacoes;   /**< Ponteiro para a lista de solicitações (fila de prioridade) */
} Elevador;

/**
 * @brief Função para inicializar o elevador.
 *
 * Inicializa o elevador com o andar atual igual a 0, direção 0 (parado),
 * e a lista de solicitações vazia.
 *
 * @param elevador Ponteiro para a estrutura do elevador a ser inicializado.
 */
void inicializarElevador(Elevador *elevador)
{
    elevador->andarAtual = 0;
    elevador->direcao = 0;
    elevador->filaSolicitacoes = NULL;

    // Inicializa todos os andares como não chamados
    for (int i = 0; i <= 10; i++)
    {
        elevador->andaresChamados[i] = false;
    }
}

/**
 * @brief Função para adicionar uma solicitação de andar na fila de prioridade.
 *
 * Adiciona um andar solicitado na lista de solicitações, ordenando pela proximidade
 * com o andar atual do elevador (prioridade para o andar mais próximo).
 * Se o andar já foi solicitado, a solicitação é ignorada.
 *
 * @param elevador Ponteiro para a estrutura do elevador.
 * @param andar Número do andar solicitado (entre 0 e 10).
 */
void adicionarSolicitacao(Elevador *elevador, int andar)
{
    Node *novoNo = (Node *)malloc(sizeof(Node));

    if (andar < 0 || andar > 10)
    {
        printf("Andar inválido!\n");
        return;
    }
    if (elevador->andaresChamados[andar])
    {
        return; // Evita duplicação
    }
    if (!novoNo)
    {
        printf("Erro de alocação de memória.\n");
        return;
    }

    novoNo->andar = andar;
    novoNo->next = NULL;

    // Insere ordenado na lista de acordo com a proximidade do andar atual
    Node **ptr = &(elevador->filaSolicitacoes);

    while (*ptr != NULL && abs((*ptr)->andar - elevador->andarAtual) < abs(andar - elevador->andarAtual))
    {
        ptr = &((*ptr)->next);
    }
    novoNo->next = *ptr;
    *ptr = novoNo;

    elevador->andaresChamados[andar] = true;
    printf("Solicitação para o andar %d adicionada.\n", andar);
}

/**
 * @brief Função para remover e retornar o próximo andar a ser atendido.
 *
 * Remove e retorna o andar mais próximo da lista de solicitações. A prioridade é dada
 * ao andar que está mais próximo do andar atual do elevador.
 *
 * @param elevador Ponteiro para a estrutura do elevador.
 * @return O andar mais próximo a ser atendido, ou -1 se a fila estiver vazia.
 */
int removerSolicitacao(Elevador *elevador)
{
    if (elevador->filaSolicitacoes == NULL)
    {
        return -1; // Fila vazia
    }

    Node *temp = elevador->filaSolicitacoes;
    int andar = temp->andar;
    elevador->filaSolicitacoes = temp->next;
    free(temp);
    elevador->andaresChamados[andar] = false;
    return andar;
}

/**
 * @brief Função para processar as solicitações e mover o elevador.
 *
 * Atende todas as solicitações de andares, movendo o elevador para o andar mais próximo
 * e parando para atender a solicitação no andar.
 *
 * @param elevador Ponteiro para a estrutura do elevador.
 */
void processarSolicitacoes(Elevador *elevador)
{
    while (elevador->filaSolicitacoes != NULL)
    {
        int proximoAndar = removerSolicitacao(elevador);

        // Movendo o elevador para o andar mais próximo
        while (elevador->andarAtual != proximoAndar)
        {
            if (elevador->andarAtual < proximoAndar)
            {
                elevador->andarAtual++;
                elevador->direcao = 1; // Subindo
            }
            else
            {
                elevador->andarAtual--;
                elevador->direcao = -1; // Descendo
            }
            printf("Elevador no andar %d.\n", elevador->andarAtual);
        }
        printf("Parando no andar %d para atender solicitação.\n", elevador->andarAtual);
    }
    elevador->direcao = 0; // Elevador parado
}

int main(int argc, char **argv)
{
    Elevador elevador;
    inicializarElevador(&elevador);

    // Adicionando solicitações
    adicionarSolicitacao(&elevador, 8);  // Andar 8
    adicionarSolicitacao(&elevador, 2);  // Andar 2
    adicionarSolicitacao(&elevador, 5);  // Andar 5
    adicionarSolicitacao(&elevador, 10); // Andar 10

    // Processando solicitações
    processarSolicitacoes(&elevador);

    /**
     * Se chamarmos os andares 8, 2, 5, 10, a ordem de atendimento será 2 → 5 → 8 → 10,
     * e não na ordem em que foram adicionados! Agora, o elevador funciona como uma
     * fila de prioridade, garantindo um atendimento mais eficiente.
     */
    return 0;
}
