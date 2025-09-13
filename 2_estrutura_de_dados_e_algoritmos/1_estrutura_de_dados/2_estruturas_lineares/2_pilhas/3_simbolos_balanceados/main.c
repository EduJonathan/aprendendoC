#include <stdio.h>
#include <stdlib.h>
#include "implementacao.h"

int main(int argc, char **argv)
{
    // Aloca memória para a estrutura da pilha
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));

    // Verifica se a alocação de memória para a estrutura da pilha foi bem-sucedida
    if (s == NULL)
    {
        printf("Memória não alocada para a pilha\n");
        return 1;
    }

    // Inicializa os atributos da pilha
    s->size = 100;                                   // Define o tamanho da pilha
    s->top = -1;                                     // Define o topo da pilha como -1
    s->arr = (char *)malloc(s->size * sizeof(char)); // Aloca memória para o array da pilha

    // Verifica se a alocação de memória para o array da pilha foi bem-sucedida
    if (s->arr == NULL)
    {
        printf("Memória não alocada para o array da pilha\n");
        free(s); // Libera a memória alocada para a estrutura da pilha
        return 1;
    }

    unsigned char expressao[100] = {0}; // Array para armazenar a expressão

    printf("Entre com uma expressão (por exemplo, \"(([]{})))\")\n");
    scanf("%99[^\n]", expressao); // Lê até 99 caracteres ou até encontrar uma nova linha

    // Verifica o balanceamento de parênteses na expressão
    int resultado = paranthesesMaching(expressao, s);

    // Verifica se a pilha está vazia após a verificação da expressão
    if (resultado)
    {
        printf("Parênteses estão balanceados\n");
    }
    else
    {
        printf("Parênteses não estão balanceados\n");
    }

    // Libera a memória alocada para o array da pilha e para a estrutura da pilha
    free(s->arr);
    free(s);

    return 0;
}
