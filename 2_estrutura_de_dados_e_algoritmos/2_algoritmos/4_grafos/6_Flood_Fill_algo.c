#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Algoritmo de Flood Fill (Preenchimento de Área)
 *
 * O algoritmo de Flood Fill é usado para preencher uma região conectada de uma matriz ou imagem,
 * começando de uma célula inicial e expandindo para células vizinhas com a mesma cor ou valor.
 *
 * É amplamente utilizado em:
 * - Editores de imagem (como a ferramenta "balde de tinta")
 * - Resolução de labirintos e mapas
 * - Identificação de componentes conexos em matrizes
 *
 * O algoritmo pode ser implementado de três formas:
 * - **Recursivo (DFS)**: Simples e intuitivo, mas pode causar estouro de pilha em regiões grandes.
 * - **Iterativo com pilha (DFS simulada)**: Evita recursão profunda.
 * - **Iterativo com fila (BFS)**: Garante preenchimento em "ondas" e é estável para grandes áreas.
 *
 * Este exemplo usa a **versão recursiva (DFS)** para fins de simplicidade.
 *
 * Regras comuns de vizinhança:
 * - **4-direções (N, S, L, O)**: Vizinhos ortogonais.
 * - **8-direções**: Vizinhos ortogonais + diagonais.
 *
 * @note A matriz deve estar dentro dos limites e não deve ser modificada enquanto
 * estiver sendo percorrida.
 *
 * COMPLEXIDADE:
 * - TEMPO: O(N), onde N é o número de células a serem preenchidas (área da região conectada).
 * - ESPAÇO: O(N) no pior caso (para pilha de chamadas ou fila).
 */

// Estrutura para representar um ponto (coordenada x, y)
typedef struct
{
    int x;
    int y;
} Ponto;

// Estrutura da pilha
typedef struct
{
    Ponto *dados;   // Array para armazenar os pontos
    int topo;       // Índice do topo
    int capacidade; // Tamanho máximo da pilha
} Pilha;

// Cria uma pilha com capacidade inicial
Pilha *criarPilha(int capacidade)
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->dados = (Ponto *)malloc(capacidade * sizeof(Ponto));
    p->topo = -1; // Pilha vazia
    p->capacidade = capacidade;
    return p;
}

// Verifica se a pilha está vazia
bool pilhaVazia(Pilha *p)
{
    return p->topo == -1;
}

// Empilha um novo ponto
void empilhar(Pilha *p, Ponto ponto)
{
    // Redimensiona se necessário (dinamicamente)
    if (p->topo == p->capacidade - 1)
    {
        p->capacidade *= 2;
        p->dados = (Ponto *)realloc(p->dados, p->capacidade * sizeof(Ponto));
    }
    p->dados[++p->topo] = ponto;
}

// Desempilha um ponto
Ponto desempilhar(Pilha *p)
{
    if (pilhaVazia(p))
    {
        fprintf(stderr, "Erro: Pilha vazia!\n");
        exit(EXIT_FAILURE);
    }
    return p->dados[p->topo--];
}

// Libera a memória da pilha
void liberarPilha(Pilha *p)
{
    free(p->dados);
    free(p);
}

/**
 * @brief Algoritmo Flood Fill usando uma pilha (DFS iterativo).
 *
 * Este algoritmo preenche uma área conectada de pontos na matriz com um novo valor.
 * A busca é feita de forma iterativa (DFS) usando uma pilha.
 * O algoritmo pode ser implementado por Fila utilizando BFS.
 *
 * @param matriz Matriz 2D representando o espaço a ser preenchido.
 * @param linhas Número de linhas da matriz.
 * @param colunas Número de colunas da matriz.
 * @param x Coordenada x (linha) do ponto inicial.
 * @param y Coordenada y (coluna) do ponto inicial.
 * @param novoValor O valor que será atribuído aos pontos preenchidos.
 *
 * @note O algoritmo evita sobreescrever os pontos que já foram preenchidos com o valor desejado.
 */
void floodFillPilha(int **matriz, int linhas, int colunas, int x, int y, int novoValor)
{
    int valorOriginal = matriz[x][y];
    if (valorOriginal == novoValor)
        return; // Nada a fazer

    Pilha *pilha = criarPilha(linhas * colunas); // Pilha dinâmica
    empilhar(pilha, (Ponto){x, y});

    // Direções: cima, baixo, esquerda, direita (4-vizinhança)
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!pilhaVazia(pilha))
    {
        Ponto atual = desempilhar(pilha);
        int i = atual.x, j = atual.y;

        // Verifica limites e se o pixel deve ser preenchido
        if (i < 0 || i >= linhas || j < 0 || j >= colunas || matriz[i][j] != valorOriginal)
        {
            continue;
        }

        // Preenche o pixel
        matriz[i][j] = novoValor;

        // Empilha os vizinhos
        for (int k = 0; k < 4; k++)
        {
            int novoX = i + dx[k];
            int novoY = j + dy[k];
            empilhar(pilha, (Ponto){novoX, novoY});
        }
    }

    liberarPilha(pilha);
}

// Função para imprimir a matriz
void imprimirMatriz(int **matriz, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv)
{
    // Exemplo de matriz 5x5 (0 = fundo, 1 = área a preencher)
    int linhas = 5, colunas = 5;
    int **matriz = (int **)malloc(linhas * sizeof(int *));
    for (int i = 0; i < linhas; i++)
    {
        matriz[i] = (int *)malloc(colunas * sizeof(int));
    }

    // Preenche a matriz com um exemplo
    int exemplo[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}};

    // Copia para a matriz dinâmica
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            matriz[i][j] = exemplo[i][j];
        }
    }

    printf("=== Matriz Original ===\n");
    imprimirMatriz(matriz, linhas, colunas);

    // Aplica Flood Fill a partir do ponto (2, 2) com o valor 2
    floodFillPilha(matriz, linhas, colunas, 2, 2, 2);

    printf("\n=== Matriz Após Flood Fill ===\n");
    imprimirMatriz(matriz, linhas, colunas);

    // Libera memória
    for (int i = 0; i < linhas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
