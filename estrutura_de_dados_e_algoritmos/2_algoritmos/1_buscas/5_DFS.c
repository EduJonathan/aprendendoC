#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 10
#define MAX_VERTICES 10 // Definir o número máximo de vértices no grafo

typedef struct stack
{
    int top;
    int itens[STACK_SIZE];
} pilha;

/**
 * Verifica se a pilha está vazia.
 *
 * @param stack Ponteiro para a pilha.
 * @return Retorna true se a pilha estiver vazia, caso contrário, retorna false.
 */
bool isEmpty(pilha *stack)
{
    return (stack->top == -1);
}

/**
 * Remove um item da pilha.
 *
 * @param stack Ponteiro para a pilha.
 * @return O item removido da pilha.
 */
int remover(pilha *stack)
{
    return stack->itens[stack->top--];
}

/**
 * Insere um valor na pilha.
 *
 * @param stack Ponteiro para a pilha.
 * @param valor O valor a ser inserido.
 */
void insert(pilha *stack, int valor)
{
    if (stack->top == STACK_SIZE - 1)
    {
        printf("Estouro: a pilha está cheia.\n");
        return;
    }
    stack->itens[++(stack->top)] = valor;
}

/**
 * Realiza a Busca em Profundidade (DFS) em um grafo usando uma pilha explícita.
 *
 * @param start O vértice de início da busca.
 * @param adj Matriz de adjacência do grafo.
 * @param v Número de vértices no grafo.
 * @param visitados Vetor que mantém o controle dos vértices visitados.
 *
 * @note A Busca em Profundidade (DFS) é um algoritmo de travessia de grafos que explora os
 * vértices de um grafo indo o mais fundo possível ao longo de cada ramo antes de retroceder
 * (backtrack) e explorar outros ramos. A complexidade de tempo de execução da DFS é:
 * 𝑂(𝑉+𝐸) Onde: 𝑉 é o número de vértices no grafo. 𝐸 é o número de arestas no grafo.
 * A pilha é a estrutura de dados mais indicada porque ela segue o princípio
 * LIFO (Last In, First Out), ou seja, o último elemento inserido é o primeiro a ser removido,
 * o que é ideal para o comportamento de retrocesso do DFS.
 */
void DFS(int start, int adj[MAX_VERTICES][MAX_VERTICES], int v, int visitados[MAX_VERTICES])
{
    pilha stack;    // Pilha para armazenar os vértices a serem visitados
    stack.top = -1; // Inicializa a pilha vazia

    // Insere o vértice inicial na pilha
    insert(&stack, start);
    visitados[start] = 1; // Marca o vértice inicial como visitado

    // Enquanto houver vértices na pilha, continue a busca
    while (!isEmpty(&stack))
    {
        int current = remover(&stack); // Remove o topo da pilha (vértice a ser visitado)
        printf("%d ", current);        // Exibe o vértice atual

        // Verifica os vizinhos do vértice atual
        for (int i = 0; i < v; i++)
        {
            // Se houver uma aresta entre o vértice atual e o vizinho
            // e o vizinho ainda não foi visitado
            if (adj[current][i] == 1 && visitados[i] == 0)
            {
                insert(&stack, i); // Insere o vizinho na pilha
                visitados[i] = 1;  // Marca o vizinho como visitado
            }
        }
    }
}

int main(int argc, char **argv)
{
    // Grafo de exemplo representado por uma matriz de adjacência
    int adj[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {0, 0, 0, 1, 0},
    };

    int v = 5;            // Número de vértices no grafo
    int start_vertex = 0; // Vértice de início para a DFS

    // Inicializa todos os vértices como não visitados
    int visitados[MAX_VERTICES] = {0};

    // Chama a função DFS a partir do vértice `start_vertex`
    printf("Resultado da DFS a partir do vértice %d:\n", start_vertex);
    DFS(start_vertex, adj, v, visitados);

    return 0;
}
