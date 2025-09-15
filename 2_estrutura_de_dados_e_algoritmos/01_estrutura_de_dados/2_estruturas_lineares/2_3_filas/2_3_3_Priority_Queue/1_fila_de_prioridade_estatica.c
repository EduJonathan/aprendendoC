#include <stdio.h>

#define TAM_MAX_FILA 10

/**
 * @brief Estrutura que representa uma fila de prioridade.
 */
typedef struct
{
    int filaPrioridade[TAM_MAX_FILA]; /**< Vetor que armazena os elementos da fila */
    int inicio;                       /**< Índice do primeiro elemento */
    int fim;                          /**< Índice do último elemento */
} FilaPrioridade;

/**
 * @brief Inicializa a fila de prioridade.
 *
 * @param fila Ponteiro para a estrutura FilaPrioridade
 */
void inicializarFila(FilaPrioridade *fila)
{
    fila->inicio = -1;
    fila->fim = -1;
}

/**
 * @brief Verifica se a fila está vazia.
 *
 * @param fila Ponteiro para a estrutura FilaPrioridade
 * @return 1 se estiver vazia, 0 caso contrário
 */
int estaVazia(FilaPrioridade *fila)
{
    return fila->inicio == -1 && fila->fim == -1;
}

/**
 * @brief Verifica se a fila está cheia.
 *
 * @param fila Ponteiro para a estrutura FilaPrioridade
 * @return 1 se estiver cheia, 0 caso contrário
 */
int estaCheia(FilaPrioridade *fila)
{
    return fila->fim >= TAM_MAX_FILA - 1;
}

/**
 * @brief Insere um elemento na fila de prioridade (maior valor = maior prioridade).
 *
 * @param fila Ponteiro para a estrutura FilaPrioridade
 * @param valor Valor a ser inserido
 */
void inserir(FilaPrioridade *fila, int valor)
{
    if (estaCheia(fila))
    {
        printf("Erro: Fila cheia, não é possível inserir %d\n", valor);
        return;
    }

    if (estaVazia(fila))
    {
        fila->inicio = 0;
        fila->fim = 0;
        fila->filaPrioridade[0] = valor;
        return;
    }

    // Encontrar posição de inserção com base na prioridade
    int i = 0;
    for (i = fila->fim; i >= 0; i--)
    {
        if (valor > fila->filaPrioridade[i])
        {
            fila->filaPrioridade[i + 1] = fila->filaPrioridade[i];
        }
        else
        {
            break;
        }
    }

    fila->filaPrioridade[i + 1] = valor;
    fila->fim++;
}

/**
 * @brief Remove um valor específico da fila de prioridade.
 *
 * @param fila Ponteiro para a estrutura FilaPrioridade
 * @param valor Valor a ser removido
 */
void remover(FilaPrioridade *fila, int valor)
{
    if (estaVazia(fila))
    {
        printf("Erro: Fila vazia\n");
        return;
    }

    for (int i = 0; i <= fila->fim; i++)
    {
        if (fila->filaPrioridade[i] == valor)
        {
            // Deslocar elementos para a esquerda
            for (int j = i; j < fila->fim; j++)
            {
                fila->filaPrioridade[j] = fila->filaPrioridade[j + 1];
            }
            fila->fim--;

            if (fila->fim < 0)
            {
                fila->inicio = -1;
            }
            return;
        }
    }
    printf("Erro: Valor %d não encontrado na fila\n", valor);
}

/**
 * @brief Exibe todos os elementos da fila de prioridade.
 *
 * @param fila Ponteiro para a estrutura FilaPrioridade
 */
void exibir(FilaPrioridade *fila)
{
    if (estaVazia(fila))
    {
        printf("Fila vazia\n");
        return;
    }

    printf("Fila de Prioridade: ");
    for (int i = fila->inicio; i <= fila->fim; i++)
    {
        printf("%d ", fila->filaPrioridade[i]);
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    FilaPrioridade fila;
    inicializarFila(&fila);

    inserir(&fila, 5);
    inserir(&fila, 10); // Maior prioridade
    inserir(&fila, 2);

    printf("Após inserções: ");
    exibir(&fila);

    remover(&fila, 10);

    printf("Após remoção: ");
    exibir(&fila);

    inserir(&fila, 20); // Maior prioridade
    inserir(&fila, 6);

    printf("Após novas inserções: ");
    exibir(&fila);

    return 0;
}
