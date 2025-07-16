#include <stdio.h>

/**
 * No código prova que o vetor é passado para a função como um ponteiro, e a função pode
 * manipular diretamente os elementos do vetor. Isso ocorre porque em C, o nome de um vetor
 * é um ponteiro para o primeiro elemento.
 */

/**
 * @brief Função que modifica o valor da primeira posição de um vetor
 *
 * Esta função recebe um ponteiro para um vetor de inteiros e modifica o valor da
 * primeira posição do vetor para 20 e a última posição para 30.
 *
 * @param v Ponteiro para o vetor de inteiros.
 * @param tam Tamanho do vetor.
 */
void modificaVetor(int *v, size_t tam)
{
    v[0] = 20;       // Modifica o valor na primeira posição
    v[tam - 1] = 30; // Modifica o valor da última posição
}

/**
 * @brief Função que altera os valores de um vetor passado por parâmetro.
 *
 * @param v Ponteiro para o vetor de inteiros.
 * @param tam Tamanho do vetor.
 */
void alterarVetor(int *v, int tamanho)
{
    // Altera os valores do vetor passando um valor multiplicado por 2
    for (int i = 0; i < tamanho; i++)
    {
        v[i] *= 2; // Multiplica cada elemento por 2
    }
}

/**
 * @brief Função para imprimir os valores de um vetor
 *
 * Esta função percorre o vetor e imprime seus valores.
 *
 * @param v Ponteiro para o vetor de inteiros.
 */
void imprimirVetor(int *arr)
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main(int argc, char **argv)
{
    // Criando um vetor
    int vetor[10] = {0}; // Inicializa o vetor com zeros

    // Obtendo o tamanho do vetor
    size_t tamanho = sizeof(vetor) / sizeof(vetor[0]);

    // Preenche o vetor com valores de 0 a 9
    for (int i = 0; i < tamanho; i++)
    {
        // Atribui o valor de i ao elemento do vetor
        vetor[i] = i;
    }

    // Imprime os valores do vetor
    printf("VALORES DO VETOR ANTES DA CHAMADA DA FUNÇÃO:\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }

    // Chama a função modificaVetor passando o endereço inicial do vetor
    modificaVetor(vetor, tamanho);
    // Como Interpretar: passamos o endereço inicial, pois os elementos não forma copiados.
    // e sim apenas passamos o primeiro endereço do elemento

    printf("\nValor da primeira posição do vetor após a chamada da função: %d\n", vetor[0]);

    printf("VETOR DEPOIS DE CHAMAR A FUNÇÃO:\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    printf("\n-------------------------------------------\n");

    int vet[5] = {1, 2, 3, 4, 5};
    int size = sizeof(vet) / sizeof(vet[0]);

    printf("Vetor original: ");
    imprimirVetor(vet); // Aqui ainda é chamado sem passar o tamanho!

    // Passa o vetor para a função e altera seus valores
    alterarVetor(vet, size);

    printf("\nVetor alterado (após passagem para a função): ");
    imprimirVetor(vet); // Imprime o vetor alterado
    return 0;
}
