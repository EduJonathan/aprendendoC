#include <stdio.h>

/**
 * Este código demonstra que um vetor pode ser tratado como um ponteiro **somente no
 * sentido de que seu nome representa o endereço do primeiro elemento**. A partir desse
 * endereço inicial, é possível utilizar aritmética de ponteiros para navegar pelos
 * elementos do vetor.
 *
 * Contudo, isso **não transforma o vetor em um ponteiro real**. A diferença fundamental
 * aparece quando tentamos alterar o endereço armazenado:
 *
 * - O nome de um vetor é um endereço FIXO, determinado na compilação. Ele não pode ser
 *   modificado ou receber outro endereço.
 *
 * - Já um ponteiro comum é uma variável que armazena um endereço de memória e pode ser
 *   alterado livremente (reatribuído, incrementado, etc.).
 *
 * Portanto, embora vetores e ponteiros compartilhem comportamentos semelhantes em
 * expressões, eles não são equivalentes e possuem características distintas.
 */

int main(int argc, char **argv)
{
    printf("\n\tINFORMAÇÕES SOBRE VETORES EM C\n\n");

    // Declaração e inicialização do vetor
    int vet[5] = {5, 3, 4, 0, 7};                        // Vetor de 5 inteiros
    const size_t tamanho = sizeof(vet) / sizeof(vet[0]); // Calculando o número de elementos no vetor

    // Cabeçalho com informações básicas sobre o vetor
    printf("Vetor declarado: int vet[5] = {5, 3, 4, 0, 7};\n");
    printf("Tamanho do vetor: %zu elementos\n", tamanho);
    printf("Tamanho total em bytes: %zu\n\n", sizeof(vet));

    // Seção 1: Endereços base do vetor
    printf("1. ENDEREÇOS BASE DO VETOR:\n");
    printf("vet      (endereço base): %p\n", (void *)vet);
    printf("&vet     (endereço do array): %p\n", (void *)&vet);
    printf("&vet[0]  (endereço do 1º elemento): %p\n", (void *)&vet[0]);
    printf("-> Todos representam o mesmo endereço de memória\n");

    printf("\n=======================================\n");

    // Imprimindo valores e endereços dos elementos do vetor usando o índice
    for (int i = 0; i < tamanho; i++)
    {
        // Imprime o índice, o valor do elemento e o endereço do elemento
        printf(" Elemento [%d]:\tVALOR: %d\tEndereço: %p\n", i, vet[i], (void *)&vet[i]);
    }

    printf("\n=======================================\n");

    // Seção 2: Acesso por índice (forma tradicional)
    printf("2. ACESSO POR ÍNDICE (vet[i]):\n");
    printf("Índice\tValor\tEndereço\n");
    printf("------\t-----\t--------\n");

    for (size_t i = 0ull; i < tamanho; i++)
    {
        printf("[%zu]\t%d\t%p\n", i, vet[i], (void *)&vet[i]);
    }

    printf("\n=======================================\n");

    // Seção 3: Acesso por aritmética de ponteiros (*(vet + i))
    printf("3. ACESSO POR ARITMÉTICA DE PONTEIROS (*(vet + i)):\n");
    printf("Expressão\tValor\tEndereço\n");
    printf("----------\t-----\t--------\n");

    for (size_t i = 0ull; i < tamanho; i++)
    {
        printf("*(vet + %zu)\t%d\t%p\n", i, *(vet + i), (void *)(vet + i)); // Aritmética de ponteiros
    }

    printf("\n=======================================\n");

    // Seção 4: Demonstração da equivalência entre as formas de acesso
    printf("4. EQUIVALÊNCIA ENTRE AS FORMAS DE ACESSO:\n");

    printf("vet[i] é equivalente a *(vet + i)\n");
    printf("&vet[i] é equivalente a (vet + i)\n\n");
    printf("Diferença entre *vet + i e *(vet + i):\n");
    printf("*vet + i = %d (valor do 1º elemento + i)\n", *vet + 0);
    printf("*(vet + i) = %d (valor do i-ésimo elemento)\n", *(vet + 0));

    printf("\n=======================================\n");

    // Seção 5: Imprimindo valores usando *vet + i
    printf("\n *vet + i:\n");

    // A expressão *vet + i não imprime os valores dos elementos do vetor corretamente.
    // Ela imprime o valor do primeiro elemento somado com o índice i.
    for (int i = 0; i < tamanho; i++)
    {
        // *vet + i é a soma do valor do primeiro elemento do vetor com i
        // Isso não imprime o valor correto do vetor, mas demonstra a operação.
        printf(" %d - %p\n", *vet + i, (void *)&vet[i]); // Essa linha não imprime o valor correto.
    }
    return 0;
}
