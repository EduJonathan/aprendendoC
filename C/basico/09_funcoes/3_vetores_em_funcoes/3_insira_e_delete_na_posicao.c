#include <stdio.h>

#define TAMANHO_VETOR 10 // Definindo o tamanho do vetor

/**
 * @brief Exibe o conteúdo de um vetor de inteiros.
 *
 * @param vet Ponteiro para o vetor de inteiros.
 * @param tamanho Número de elementos no vetor
 */
void exibirVetor(int vet[], size_t tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

/**
 * @brief Insere um elemento na posição especificada em um vetor de inteiros.
 *
 * @param vet Ponteiro para o vetor de inteiros.
 * @param tamanho Número de elementos no vetor
 */
void inserindoElementoNaPosicao(int vet[], size_t *tamanho)
{
    int posicao = 0, elemento = 0;

    // Verificando se o vetor tem espaço
    if (*tamanho >= TAMANHO_VETOR)
    {
        printf("Vetor cheio. Não é possível inserir um novo elemento.\n");
        return;
    }

    // Pedir a posição e o elemento
    printf("Insira a posição do elemento (0 a %d): ", *tamanho);
    scanf("%d", &posicao);

    // Verificar se a posição é válida
    if (posicao < 0 || posicao > *tamanho)
    {
        printf("Posição inválida!\n");
        return;
    }

    printf("Insira o elemento: ");
    scanf("%d", &elemento);

    // Deslocar os elementos para a direita para abrir espaço
    for (int i = *tamanho; i > posicao; i--)
    {
        vet[i] = vet[i - 1];
    }

    // Inserir o elemento na posição especificada
    vet[posicao] = elemento;

    // Atualizar o tamanho do vetor
    (*tamanho)++;

    // Exibir o vetor após a inserção
    exibirVetor(vet, *tamanho);
}

/**
 * @brief Deleta o elemento na posição especificada de um vetor de inteiros.
 *
 * @param vet Ponteiro para o vetor de inteiros.
 * @param tamanho Número de elementos no vetor
 */
void deletandoElementoNaPosicao(int vet[], size_t *tamanho)
{
    int posicao = 0;

    // Verificar se o vetor está vazio
    if (*tamanho == 0)
    {
        printf("Vetor vazio. Não é possível excluir elementos.\n");
        return;
    }

    // Pedir a posição do elemento a ser excluído
    printf("Insira a posição do elemento a ser excluído (0 a %d): ", *tamanho - 1);
    scanf("%d", &posicao);

    // Verificar se a posição é válida
    if (posicao < 0 || posicao >= *tamanho)
    {
        printf("Posição inválida!\n");
        return;
    }

    // Deslocar os elementos para a esquerda para preencher o espaço
    for (int i = posicao; i < *tamanho - 1; i++)
    {
        vet[i] = vet[i + 1];
    }

    // Atualizar o tamanho do vetor
    (*tamanho)--;

    // Exibir o vetor após a exclusão
    exibirVetor(vet, *tamanho);
}

int main(int argc, char **argv)
{
    int vet[TAMANHO_VETOR] = {1, 2, 3, 4, 5, 6, 7, 8, 10}; // Exemplo de vetor inicial
    size_t tamanho = 9;                                    // Número atual de elementos no vetor (já considerando a quantidade real)

    // Exibir o vetor antes da inserção
    printf("Vetor antes da inserção: ");
    exibirVetor(vet, tamanho);

    // Inserir um elemento no vetor
    inserindoElementoNaPosicao(vet, &tamanho);

    // Deletar um elemento do vetor
    deletandoElementoNaPosicao(vet, &tamanho);

    return 0;
}
