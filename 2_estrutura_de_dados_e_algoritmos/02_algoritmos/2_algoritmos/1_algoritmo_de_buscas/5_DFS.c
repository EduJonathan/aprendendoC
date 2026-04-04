#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @struct stack
 * @brief Estrutura para representar uma pilha (LIFO) com alocação dinâmica.
 */
typedef struct stack
{
    int *itens;   /**< Ponteiro para o array que armazena os elementos da pilha */
    int top;      /**< Índice do elemento que está no topo da pilha */
    int capacity; /**< Capacidade máxima de armazenamento da pilha */
} pilha;

/**
 * @brief Inicializa a pilha com a capacidade especificada.
 * 
 * @param capacity O número máximo de elementos que a pilha pode conter.
 * @return Ponteiro para a nova estrutura de pilha ou NULL em caso de erro.
 */
pilha *initStack(int capacity)
{
    pilha *stack = (pilha *)malloc(sizeof(pilha));
    if (stack == NULL)
    {
        printf("Erro: Falha na alocação de memória para a pilha.\n");
        return NULL;
    }

    stack->itens = (int *)malloc(capacity * sizeof(int));
    if (stack->itens == NULL)
    {
        printf("Erro: Falha na alocação de memória para os itens da pilha.\n");
        free(stack);
        return NULL;
    }
    stack->top      = -1;
    stack->capacity = capacity;
    return stack;
}

/**
 * @brief Libera a memória alocada para a estrutura da pilha e seus itens.
 * 
 * @param stack Ponteiro para a pilha a ser desalocada.
 */
void freeStack(pilha *stack)
{
    if (stack != NULL)
    {
        free(stack->itens);
        free(stack);
    }
}

/**
 * @brief Verifica se a pilha não contém elementos.
 * 
 * @param stack Ponteiro para a pilha consultada.
 * @return true se a pilha estiver vazia, false caso contrário.
 */
bool isEmpty(pilha *stack)
{
    return stack->top == -1;
}

/**
 * @brief Remove e retorna o elemento no topo da pilha.
 * 
 * @param stack Ponteiro para a pilha.
 * @return O valor do item removido ou -1 caso a pilha esteja vazia (underflow).
 */
int remover(pilha *stack)
{
    if (isEmpty(stack))
    {
        printf("Erro: Pilha vazia.\n");
        return -1;
    }
    return stack->itens[stack->top--];
}

/**
 * @brief Insere um novo valor no topo da pilha.
 * 
 * @param stack Ponteiro para a pilha.
 * @param valor O elemento inteiro a ser inserido.
 * @note Caso a pilha atinja sua capacidade máxima, uma mensagem de erro é exibida.
 */
void insert(pilha *stack, int valor)
{
    if (stack->top == stack->capacity - 1)
    {
        printf("Estouro: a pilha está cheia.\n");
        return;
    }
    stack->itens[++(stack->top)] = valor;
}

/**
 * @brief Realiza a Busca em Profundidade (DFS) usando uma pilha explícita.
 *
 * Diferente da versão recursiva, esta função utiliza uma estrutura de pilha
 * manual para simular a exploração de ramos até a maior profundidade possível.
 *
 * @param start O vértice de origem para iniciar a exploração.
 * @param adj Matriz de adjacência que representa as conexões do grafo.
 * @param v Número total de vértices no grafo.
 * @param visitados Vetor de controle para evitar ciclos e visitas duplicadas.
 */
void DFS(int start, int **adj, int v, int *visitados)
{
    pilha *stack = initStack(v);
    if (stack == NULL)
    {
        return;
    }

    insert(stack, start);
    visitados[start] = 1;

    while (!isEmpty(stack))
    {
        int current = remover(stack);
        printf("%d ", current);

        for (int i = 0; i < v; i++)
        {
            if (adj[current][i] == 1 && visitados[i] == 0)
            {
                insert(stack, i);
                visitados[i] = 1;
            }
        }
    }
    freeStack(stack);
}

/**
 * @brief Aloca dinamicamente uma matriz de adjacência preenchida com zeros.
 * 
 * @param v Número de vértices (linhas e colunas).
 * @return Ponteiro para a matriz alocada ou NULL em caso de falha.
 */
int **allocateGraph(int v)
{
    int **adj = (int **)malloc(v * sizeof(int *));
    if (adj == NULL)
    {
        printf("Erro: Falha na alocação de memória.\n");
        return NULL;
    }

    for (int i = 0; i < v; i++)
    {
        adj[i] = (int *)calloc(v, sizeof(int));
        if (adj[i] == NULL)
        {
            printf("Erro: Falha na alocação de memória.\n");
            for (int j = 0; j < i; j++)
            {
                free(adj[j]);
            }
            free(adj);
            return NULL;
        }
    }
    return adj;
}

/**
 * @brief Executa o algoritmo DFS em todos os componentes conexos do grafo.
 * 
 * @param adj Matriz de adjacência do grafo.
 * @param v Quantidade total de vértices.
 */
void DFSAll(int **adj, int v)
{
    int *visitados = (int *)calloc(v, sizeof(int));
    if (visitados == NULL)
    {
        printf("Erro: Falha na alocação de memória para visitados.\n");
        return;
    }

    printf("Resultado da DFS por componentes:\n");
    for (int i = 0; i < v; i++)
    {
        if (visitados[i] == 0)
        {
            printf("Componente começando em %d: ", i);
            DFS(i, adj, v, visitados);
            printf("\n");
        }
    }
    free(visitados);
}

/**
 * @brief Desaloca a memória da matriz de adjacência.
 * 
 * @param adj Matriz de adjacência.
 * @param v Número de vértices (linhas).
 */
void freeGraph(int **adj, int v)
{
    for (int i = 0; i < v; i++)
    {
        free(adj[i]);
    }
    free(adj);
}

int main(int argc, char **argv)
{
    int v = 0, e = 0, start_vertex = 0;

    // Solicita o número de vértices
    printf("Digite o número de vértices: ");
    if (scanf("%d", &v) != 1 || v <= 0)
    {
        printf("Erro: Número de vértices deve ser positivo.\n");
        return 1;
    }

    // Solicita o número de arestas
    printf("Digite o número de arestas: ");
    if (scanf("%d", &e) != 1 || e < 0)
    {
        printf("Erro: Número de arestas deve ser não-negativo.\n");
        return 1;
    }

    // Aloca a matriz de adjacência
    int **adj = allocateGraph(v);
    if (adj == NULL)
    {
        return 1;
    }

    // Solicita as arestas
    printf("Digite as arestas (formato: vértice_origem vértice_destino):\n");
    for (int i = 0; i < e; i++)
    {
        int src = 0, dest = 0;
        printf("Aresta %d: ", i + 1);
        if (scanf("%d %d", &src, &dest) != 2 || src < 0 || src >= v || dest < 0 || dest >= v)
        {
            printf("Erro: Vértices inválidos.\n");
            freeGraph(adj, v);
            return 1;
        }
        adj[src][dest] = 1; // Grafo não direcionado
        adj[dest][src] = 1;
    }

    // Solicita o vértice inicial
    printf("Digite o vértice inicial para DFS (0 a %d): ", v - 1);
    if (scanf("%d", &start_vertex) != 1 || start_vertex < 0 || start_vertex >= v)
    {
        printf("Erro: Vértice inicial inválido.\n");
        freeGraph(adj, v);
        return 1;
    }

    // Executa DFS para o vértice inicial
    int *visitados = (int *)calloc(v, sizeof(int));
    if (visitados == NULL)
    {
        printf("Erro: Falha na alocação de memória para visitados.\n");
        freeGraph(adj, v);
        return 1;
    }
    printf("Resultado da DFS a partir do vértice %d: ", start_vertex);
    DFS(start_vertex, adj, v, visitados);
    printf("\n");

    // Executa DFS para todos os vértices (para grafos desconexos)
    DFSAll(adj, v);

    // Libera memória
    free(visitados);
    freeGraph(adj, v);
    return 0;
}
