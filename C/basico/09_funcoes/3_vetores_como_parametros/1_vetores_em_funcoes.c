#include <stdio.h>

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

int main(int argc, char **argv)
{
    // Criando um vetor
    int vetor[10];

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
    return 0;
}
