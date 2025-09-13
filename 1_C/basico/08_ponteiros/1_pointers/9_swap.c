#include <stdio.h>

int main(int argc, char **argv)
{
    // Declaração e inicialização de variáveis
    int n1 = 6;
    int n2 = 2;

    // Declaração de ponteiros e atribuição dos endereços de n1 e n2
    int *ptrN1 = NULL;
    int *ptrN2 = NULL;

    // Entregando o endereço de n1 e n2 para os ponteiros ptrN1, ptrN2
    ptrN1 = &n1;
    ptrN2 = &n2;

    // Exibição dos valores iniciais
    printf("ANTES DO SWAP\n");
    printf(" n1 = %d\t n2 = %d\n", *ptrN1, *ptrN2);

    printf("DEPOIS DO SWAP\n");

    int temp = *ptrN2; // Armazena o conteúdo de n2 em uma variável temporária
    *ptrN2 = *ptrN1;   // Atribui o conteúdo de n1 a n2
    *ptrN1 = temp;     // Atribui o conteúdo temporário (n2 anterior) a n1

    printf(" ptrN1 = %d\t ptrN2 = %d\n", *ptrN1, *ptrN2);
    return 0;
}
