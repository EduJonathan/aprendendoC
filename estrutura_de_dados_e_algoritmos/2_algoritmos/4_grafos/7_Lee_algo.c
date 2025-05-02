#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/**
 * Algoritmo de Lee - Caminho Mínimo em Grade (Grid)
 *
 * O algoritmo de Lee é uma variação da **Busca em Largura (BFS)** aplicada em matrizes
 * bidimensionais para encontrar o caminho mais curto entre dois pontos. É comumente utilizado
 * em problemas de:
 *
 * - Labirintos
 * - Roteamento de circuitos em PCB (placas eletrônicas)
 * - Robótica e mapeamento de ambientes
 * - Mapas de calor e propagação em grids
 *
 * O algoritmo parte de um ponto inicial e propaga em todas as direções válidas (geralmente 4 ou 8),
 * marcando a distância mínima em cada célula visitada até encontrar o destino.
 *
 * Características:
 * - Garante o menor número de passos (em número de células) até o destino.
 * - Suporta obstáculos (paredes, células bloqueadas).
 *
 * DIREÇÕES COMUNS:
 * - **4-direções**: cima, baixo, esquerda, direita.
 * - **8-direções**: inclui diagonais.
 *
 * @note As células bloqueadas devem ser identificadas por um valor específico (ex: -1 ou 0).
 *
 * COMPLEXIDADE:
 * - TEMPO: O(N * M), onde N e M são as dimensões da matriz (cada célula é visitada no máximo uma vez).
 * - ESPAÇO: O(N * M), devido à fila usada na BFS e à matriz de distâncias.
 */

// Estrutura para representar uma célula no grid
typedef struct
{
    int row;
    int col;
} Cell;

// Estrutura para a fila usada na BFS
typedef struct
{
    Cell *items;
    int front;
    int rear;
    int capacity;
} Queue;

// Cria uma fila
Queue *createQueue(int capacity)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->items = (Cell *)malloc(capacity * sizeof(Cell));
    q->front = q->rear = -1;
    q->capacity = capacity;
    return q;
}

// Verifica se a fila está vazia
bool isEmpty(Queue *q)
{
    return q->front == -1;
}

// Adiciona um elemento
void enqueue(Queue *q, Cell item)
{
    if (q->rear == q->capacity - 1)
    {
        printf("Fila cheia\n");
        return;
    }
    if (q->front == -1)
    {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = item;
}

// Remove e retorna o item do início da fila.
Cell dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Fila vazia\n");
        return (Cell){-1, -1};
    }
    Cell item = q->items[q->front];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front++;
    }
    return item;
}

// Liberar a fila
void freeQueue(Queue *q)
{
    free(q->items);
    free(q);
}

/**
 * @brief Verifica se uma posição está dentro dos limites da matriz.
 *
 * @param row Linha a verificar.
 * @param col Coluna a verificar.
 * @param rows Número total de linhas da matriz.
 * @param cols Número total de colunas da matriz.
 * @return true se estiver dentro dos limites, false caso contrário.
 */
bool isValid(int row, int col, int rows, int cols)
{
    return (row >= 0) && (row < rows) && (col >= 0) && (col < cols);
}

/**
 * @brief Algoritmo de Lee para encontrar o caminho mínimo entre dois pontos em uma matriz.
 *
 * Utiliza busca em largura (BFS) para explorar caminhos e calcula a menor
 * distância (em número de passos) entre a célula inicial e a final, evitando obstáculos
 * (valores 0).
 *
 * @param grid Matriz 2D de inteiros representando o mapa (1 = livre, 0 = obstáculo).
 * @param rows Número de linhas da matriz.
 * @param cols Número de colunas da matriz.
 * @param start Célula inicial.
 * @param end Célula final (destino).
 * @return Número mínimo de passos até o destino, ou -1 se não houver caminho possível.
 */
int leeAlgorithm(int **grid, int rows, int cols, Cell start, Cell end)
{
    // Verifica se start e end são válidos e não são obstáculos
    if (!isValid(start.row, start.col, rows, cols) || !isValid(end.row, end.col, rows, cols) ||
        grid[start.row][start.col] == 0 || grid[end.row][end.col] == 0)
    {
        return -1;
    }

    // Matriz de distâncias
    int **dist = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        dist[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++)
        {
            dist[i][j] = -1; // Inicializa com -1 (não visitado)
        }
    }

    // Possíveis movimentos (4 direções)
    int rowNum[] = {-1, 0, 0, 1};
    int colNum[] = {0, -1, 1, 0};

    // Cria fila para BFS
    Queue *q = createQueue(rows * cols);

    // Marca a célula inicial como visitada e define distância 0
    dist[start.row][start.col] = 0;
    enqueue(q, start);

    while (!isEmpty(q))
    {
        Cell curr = dequeue(q);

        // Verifica se chegamos ao destino
        if (curr.row == end.row && curr.col == end.col)
        {
            int result = dist[curr.row][curr.col];

            // Libera memória
            for (int i = 0; i < rows; i++)
            {
                free(dist[i]);
            }
            free(dist);
            freeQueue(q);

            return result;
        }

        // Explora todas as 4 direções
        for (int i = 0; i < 4; i++)
        {
            int newRow = curr.row + rowNum[i];
            int newCol = curr.col + colNum[i];

            // Se a célula é válida, não é obstáculo e não foi visitada
            if (isValid(newRow, newCol, rows, cols) &&
                grid[newRow][newCol] != 0 &&
                dist[newRow][newCol] == -1)
            {

                dist[newRow][newCol] = dist[curr.row][curr.col] + 1;
                enqueue(q, (Cell){newRow, newCol});
            }
        }
    }

    // Libera memória
    for (int i = 0; i < rows; i++)
    {
        free(dist[i]);
    }
    free(dist);
    freeQueue(q);

    // Se chegou aqui, não encontrou caminho
    return -1;
}

/**
 * @brief Imprime a matriz (grid) no console.
 *
 * @param grid Matriz 2D a ser impressa.
 * @param rows Número de linhas.
 * @param cols Número de colunas.
 */
void printGrid(int **grid, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv)
{
    // Exemplo de grid (0 representa obstáculos, 1 representa caminhos livres)
    int rows = 5, cols = 5;
    int gridTemplate[5][5] = {
        {1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1}};

    // Aloca grid dinamicamente
    int **grid = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        grid[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++)
        {
            grid[i][j] = gridTemplate[i][j];
        }
    }

    printf("Grid:\n");
    printGrid(grid, rows, cols);

    Cell start = {0, 0}; // Ponto inicial (canto superior esquerdo)
    Cell end = {4, 4};   // Ponto final (canto inferior direito)

    int distance = leeAlgorithm(grid, rows, cols, start, end);

    if (distance != -1)
    {
        printf("\nDistância mínima de (%d,%d) a (%d,%d): %d\n", start.row, start.col, end.row, end.col, distance);
    }
    else
    {
        printf("\nNão existe caminho de (%d,%d) a (%d,%d)\n", start.row, start.col, end.row, end.col);
    }

    // Libera memória
    for (int i = 0; i < rows; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}
