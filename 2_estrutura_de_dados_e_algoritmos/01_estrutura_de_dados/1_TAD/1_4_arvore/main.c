#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

void testar_busca(struct no *raiz, int valor)
{
    struct no *resultado = buscar(raiz, valor);
    if (resultado != NULL)
    {
        printf("Valor %d encontrado na árvore.\n", valor);
    }
    else
    {
        printf("Valor %d não encontrado na árvore.\n", valor);
    }
}

int main(int argc, char **argv)
{
    printf("=== Teste da Árvore Binária de Busca ===\n\n");

    // Teste 1: Usando struct no * diretamente
    printf("1. Teste com struct no *:\n");

    struct no *arvore_simples = NULL;
    inserir(&arvore_simples, 10);
    inserir(&arvore_simples, 5);
    inserir(&arvore_simples, 15);
    inserir(&arvore_simples, 3);
    inserir(&arvore_simples, 7);

    printf("Árvore em ordem: ");
    imprimir_em_ordem(arvore_simples);
    printf("\n");

    printf("Raiz: %d\n", arvore_simples->valor);

    // Teste de remoção
    remover(&arvore_simples, 10);
    printf("Após remover 10, nova raiz: %d\n", arvore_simples ? arvore_simples->valor : -1);

    printf("Árvore em ordem após remoção: ");
    imprimir_em_ordem(arvore_simples);
    printf("\n\n");

    // Teste 2: Usando struct arvore
    printf("2. Teste com struct arvore:\n");

    struct arvore minha_arvore;
    if (inicializar_arvore(&minha_arvore) != 0)
    {
        printf("Erro ao inicializar árvore!\n");
        return 1;
    }

    inserir(minha_arvore.raiz, 20);
    inserir(minha_arvore.raiz, 10);
    inserir(minha_arvore.raiz, 30);
    inserir(minha_arvore.raiz, 25);
    inserir(minha_arvore.raiz, 35);

    printf("Árvore em pré-ordem: ");
    imprimir_pre_ordem(*(minha_arvore.raiz));
    printf("\n");

    printf("Raiz da estrutura: %d\n", (*(minha_arvore.raiz))->valor);

    // Teste de busca
    testar_busca(*(minha_arvore.raiz), 25);
    testar_busca(*(minha_arvore.raiz), 40);

    // Teste de remoção
    remover(minha_arvore.raiz, 20);
    printf("Após remover 20, nova raiz: %d\n", *(minha_arvore.raiz) ? (*(minha_arvore.raiz))->valor : -1);

    printf("Árvore em pós-ordem: ");
    imprimir_pos_ordem(*(minha_arvore.raiz));
    printf("\n\n");

    // Liberar memória
    printf("3. Liberando memória:\n");
    liberar_arvore(arvore_simples);
    liberar_arvore(*(minha_arvore.raiz));
    free(minha_arvore.raiz);

    printf("Memória liberada com sucesso!\n");

    /**
     * Para compilar
     *
     * gcc -O3 -Wall -Wextra -std=c17 -o arvore main.c arvore.c
     * .\a.exe
     */
    return 0;
}
