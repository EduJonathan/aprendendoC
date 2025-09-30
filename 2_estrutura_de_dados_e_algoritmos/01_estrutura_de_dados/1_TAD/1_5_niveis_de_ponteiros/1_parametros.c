#include <stdio.h>
#include <stdlib.h>

/**
 * Um dos pontos que mais gera dúvida em C é: quando usar ponteiros de diferentes níveis
 * (*, **, ***) em funções e parâmetros, especialmente em estruturas de dados.
 *
 * A escolha do nível de indireção (quantidade de asteriscos) depende do que se deseja modificar:
 *
 * - * (ponteiro simples): permite acessar e alterar os dados armazenados no objeto
 * apontado, mas não trocar o ponteiro original.
 *
 * - ** (ponteiro duplo): permite, além de acessar dados, alterar o próprio ponteiro
 * original (por exemplo, mudar a cabeça de uma lista encadeada).
 *
 * - *** (ponteiro triplo): usado em casos mais complexos, como manipular um ponteiro
 * para ponteiro, permitindo substituir estruturas inteiras (ex.: lista de listas ou
 * matrizes dinâmicas).
 *
 * RESUMINDO: cada nível extra de indireção dá controle sobre um nível a mais de endereço.
 * A regra prática é perguntar:
 * "Quero modificar apenas os dados, o ponteiro, ou um ponteiro que guarda outro ponteiro?"
 */

struct Estrutura
{
    int dados;
    struct Estrutura *proximo;
};

// Nível 1 (*): Modifica dados, mas não a cabeça
void func(struct Estrutura *cabeca)
{
    if (cabeca != NULL)
    {
        cabeca->dados = 10;
        cabeca = NULL; // só muda a cópia local
    }
}

// Nível 2 (**): Pode mudar o ponteiro original
void inserir_inicio(struct Estrutura **cabeca, int dado)
{
    struct Estrutura *novo = (struct Estrutura *)malloc(sizeof(struct Estrutura));
    if (!novo)
    {
        fprintf(stderr, "Erro de alocacao");
        exit(EXIT_FAILURE);
    }
    novo->dados = dado;
    novo->proximo = *cabeca;
    *cabeca = novo;
}

// Nível 3 (***): Raro, mas permite mudar o ponteiro de ponteiro
void funcao_tripla(struct Estrutura ***cabeca)
{
    struct Estrutura *novo = (struct Estrutura *)malloc(sizeof(struct Estrutura));
    if (!novo)
    {
        fprintf(stderr, "Erro de alocacao");
        exit(EXIT_FAILURE);
    }
    novo->dados = 99;
    novo->proximo = NULL;
    **cabeca = novo;
}

// Libera memória da lista encadeada
void liberar_lista(struct Estrutura *cabeca)
{
    struct Estrutura *atual = cabeca;
    while (atual != NULL)
    {
        struct Estrutura *prox = atual->proximo;
        free(atual);
        atual = prox;
    }
}

int main(int argc, char **argv)
{
    struct Estrutura *lista = NULL;

    // Insere nós
    inserir_inicio(&lista, 1);
    inserir_inicio(&lista, 2);

    printf("Lista: cabeca=%p, dados=%d\n", (void *)lista, lista->dados);

    // Testando ponteiro simples
    func(lista);
    printf("Depois de func: cabeca=%p, dados=%d\n", (void *)lista, lista->dados);

    // Testando ponteiro triplo
    struct Estrutura **ptr = &lista;
    funcao_tripla(&ptr);
    printf("Depois de funcao_tripla: cabeca=%p, dados=%d\n", (void *)lista, lista->dados);

    // Libera memória
    liberar_lista(lista);

    return 0;
}
