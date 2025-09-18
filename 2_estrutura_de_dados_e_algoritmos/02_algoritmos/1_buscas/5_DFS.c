#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Estrutura para representar uma pilha dinâmica.
 */
typedef struct stack
{
    int *itens;   // Array dinâmico para armazenar os itens
    int top;      // Índice do topo da pilha
    int capacity; // Capacidade total da pilha
} pilha;

/**
 * @brief Inicializa a pilha com a capacidade especificada.
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
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

/**
 * @brief Libera a memória alocada para a pilha.
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
 * @brief Verifica se a pilha está vazia.
 */
bool isEmpty(pilha *stack)
{
    return stack->top == -1;
}

/**
 * @brief Remove um item da pilha.
 */
int remover(pilha *stack)
{
    if (isEmpty(stack))
    {
        printf("Erro: Pilha vazia.\n");
        return -1; // Valor sentinela para erro
    }
    return stack->itens[stack->top--];
}

/**
 * @brief Insere um valor na pilha.
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
 * @brief Realiza a Busca em Profundidade (DFS) em um grafo usando uma pilha explícita.
 *
 * A Busca em Profundidade (DFS) é um algoritmo de travessia de grafos que explora os
 * vértices indo o mais fundo possível ao longo de cada ramo antes de retroceder
 * (backtrack) para explorar outros caminhos. Utiliza uma pilha (LIFO) para controlar
 * a ordem de visitação dos vértices.
 *
 * Complexidade:
 *
 * - Tempo:  O(V + E), onde V é o número de vértices e E o número de arestas.
 *
 * - Espaço: O(V), para armazenar a pilha e o vetor de visitados.
 *
 * @param start O vértice de início da busca.
 * @param adj Matriz de adjacência do grafo.
 * @param v Número de vértices no grafo.
 * @param visitados Vetor que mantém o controle dos vértices visitados.
 */
void DFS(int start, int **adj, int v, int *visitados)
{
    pilha *stack = initStack(v); // Capacidade da pilha igual ao número de vértices
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
 * @brief Aloca uma matriz de adjacência dinamicamente.
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
        adj[i] = (int *)calloc(v, sizeof(int)); // Inicializa com 0
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
 * @brief Realiza a Busca em Profundidade (DFS) em um grafo usando uma pilha.
 */
void DFSAll(int **adj, int v)
{
    int *visitados = (int *)calloc(v, sizeof(int));
    if (visitados == NULL)
    {
        printf("Erro: Falha na alocação de memória para visitados.\n");
        return;
    }

    printf("Resultado da DFS:\n");
    for (int i = 0; i < v; i++)
    {
        if (visitados[i] == 0)
        {
            printf("Componente conexa começando em %d: ", i);
            DFS(i, adj, v, visitados);
            printf("\n");
        }
    }
    free(visitados);
}

/**
 * @brief Libera a memória alocada para a matriz de adjacência.
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
