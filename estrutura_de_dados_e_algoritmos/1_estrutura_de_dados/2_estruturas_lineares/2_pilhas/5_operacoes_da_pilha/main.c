#include "implementarFuncoes.h"

int main(int argc, char **argv)
{
    Pilha p = {0};   // Declaração e inicialização da pilha
    inicializar(&p); // Inicializa a pilha

    // Empilhando elementos
    empilhar(&p, 10);
    empilhar(&p, 20);
    empilhar(&p, 30);

    // Exibindo o tamanho da pilha
    printf("Tamanho da pilha: %d\n", tamanho(&p));

    printf("\n----------------------\n");

    // Desempilhando um elemento
    printf("Elemento desempilhado: %d\n", desempilhar(&p));

    printf("\n----------------------\n");

    // Exibindo o tamanho da pilha após o desempilhamento
    printf("Tamanho da pilha após desempilhar: %d\n", tamanho(&p));

    printf("\n----------------------\n");

    // Exibindo o topo da pilha
    printf("Elemento no topo da pilha: %d\n", topo(&p));

    printf("\n----------------------\n");

    int valorBuscado = 10;
    bool resultado = buscar(&p, valorBuscado);

    if (resultado != -1)
    {
        printf("Elemento %d encontrado na posição %d (do topo)\n", valorBuscado, resultado);
    }
    else
    {
        printf("Elemento %d não encontrado.\n", valorBuscado);
    }

    printf("\n----------------------\n");

    printf("Pilha antes da ordenação: ");
    imprimirPilha(&p);

    ordenarPilha(&p);

    printf("Pilha após a ordenação: ");
    imprimirPilha(&p);
    return 0;
}
