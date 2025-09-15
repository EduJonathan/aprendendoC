#include <stdio.h>
#include <stdlib.h>

#ifndef NODE_H
#define NODE_H

/**
 * @brief Estrutura que representa um nó na árvore.
 *
 * Uma árvore genérica ou simples pode ser vista como uma estrutura de dados que armazena
 * um conjunto de dados (números de filhos) sem restrição que um nó possa ter. Cada nó contém
 * um dado do tipo `char`, um ponteiro para o nó pai, um ponteiro para o primeiro filho e um
 * ponteiro para o próximo irmão.
 */
typedef struct no
{
    char dado;        /**< Valor armazenado no nó */
    struct no *pai;   /**< Ponteiro para o nó pai */
    struct no *filho; /**< Ponteiro para o primeiro filho */
    struct no *irmao; /**< Ponteiro para o próximo irmão */
} Node;

#endif

/**
 * @brief Cria um novo nó com o valor especificado.
 *
 * Esta função aloca memória para um novo nó e inicializa seus campos.
 *
 * @param valor O valor a ser armazenado no nó.
 * @return Ponteiro para o nó criado.
 */
Node *criarNo(char valor)
{
    Node *no = (Node *)malloc(sizeof(Node)); /**< Aloca memória para um nó */
    no->dado = valor;                        /**< Atribui o valor ao nó */
    no->pai = NULL;                          /**< Inicializa o ponteiro para o pai como NULL */
    no->filho = NULL;                        /**< Inicializa o ponteiro para o filho como NULL */
    no->irmao = NULL;                        /**< Inicializa o ponteiro para o irmão como NULL */
    return no;
}

/**
 * @brief Insere um novo nó como filho de um nó pai, na posição especificada.
 *
 * A função percorre a lista de filhos do nó pai e insere o novo nó na posição
 * indicada (onde 0 é a primeira posição). Se o nó pai não tiver filhos,
 * o novo nó será o primeiro filho.
 *
 * @param pai Ponteiro para o nó pai.
 * @param novoNo Ponteiro para o novo nó a ser inserido.
 * @param posicao A posição onde o novo nó deve ser inserido.
 */
void inserirFilho(Node *pai, Node *novoNo, int posicao)
{
    if (pai == NULL || novoNo == NULL)
    {
        return; /**< Verifica se os ponteiros são válidos */
    }

    // Se o nó pai não tem filhos, insere o novo nó como primeiro filho
    if (pai->filho == NULL)
    {
        // Insere o novo nó como primeiro filho
        pai->filho = novoNo;
    }
    else
    {
        // Percorre a lista de filhos para encontrar a posição desejada
        Node *current = pai->filho;
        int index = 0;

        // Percorre a lista de irmãos até a posição desejada
        while (current->irmao != NULL && index < posicao - 1)
        {
            current = current->irmao;
            index++;
        }

        // Insere o novo nó na posição desejada
        novoNo->irmao = current->irmao;
        current->irmao = novoNo;
    }
    novoNo->pai = pai; // Define o nó pai do novo nó
}

/**
 * @brief Função recursiva para imprimir a árvore.
 *
 * Esta função imprime todos os nós da árvore de forma recursiva. Cada nível
 * da árvore é indentado com espaços para mostrar sua profundidade na estrutura.
 *
 * @param no Ponteiro para o nó atual.
 * @param nivel O nível de profundidade do nó na árvore.
 */
void imprimirArvore(Node *no, int nivel)
{
    if (no == NULL)
    {
        return; /**< Caso base para a recursão, se o nó for NULL, termina a função */
    }

    // Imprime o nó com indentação conforme o nível na árvore
    for (int i = 0; i < nivel; i++)
    {
        printf("  ");
    }

    printf("%c\n", no->dado);

    // Chama recursivamente para imprimir os filhos
    imprimirArvore(no->filho, nivel + 1);

    // Chama recursivamente para imprimir os irmãos
    imprimirArvore(no->irmao, nivel);
}

int main(int argc, char **argv)
{
    // Criação dos nós
    Node *A = criarNo('A');
    Node *B = criarNo('B');
    Node *C = criarNo('C');
    Node *D = criarNo('D');
    Node *E = criarNo('E');
    Node *F = criarNo('F');
    Node *G = criarNo('G');

    // Estabelece relações de pai-filho e irmão
    A->filho = B;
    B->irmao = C;
    C->irmao = D;
    B->filho = E;
    E->irmao = F;
    F->irmao = G;

    // Imprime a árvore antes de inserir
    printf("Arvore antes de inserir:\n");
    imprimirArvore(A, 0);

    // Exemplo de inserção de um novo nó 'H' sob o nó 'B' (na posição 1)
    Node *H = criarNo('H');
    inserirFilho(B, H, 1); /**< Insere 'H' como segundo filho de 'B' */

    // Imprime a árvore após a inserção
    printf("\nArvore depois de inserir 'H' sob 'B':\n");
    imprimirArvore(A, 0);

    return 0;
}
