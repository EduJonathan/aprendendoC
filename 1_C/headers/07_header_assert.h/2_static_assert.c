#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
 * _Static_assert é um recurso introduzido no padrão C11 que permite realizar
 * verificações em tempo de compilação.
 *
 * Diferentemente do assert tradicional (assert()),
 * que é avaliado em tempo de execução e pode ser desativado em builds de produção,
 * o _Static_assert é sempre verificado pelo compilador.
 *
 * Caso a condição passada ao _Static_assert seja falsa,
 * o código não compila e o compilador emite uma mensagem de erro.
 *
 * Esse mecanismo é especialmente útil para garantir:
 *  - tamanhos mínimos ou exatos de tipos de dados;
 *  - propriedades de layout de estruturas;
 *  - suposições sobre alinhamento e compatibilidade entre plataformas;
 *  - invariantes que devem ser verdadeiras antes da execução do programa.
 *
 * O uso de _Static_assert ajuda a detectar erros de projeto cedo,
 * tornando o código mais seguro, portável e robusto.
 *
 * Use _Static_assert quando:
 * - A condição precisa ser verdadeira para o código existir
 * - Envolve tipos, tamanhos, layout, alinhamento
 * - Erro não pode ser recuperado em runtime
 */

/* Garantindo propriedades básicas do sistema */
_Static_assert(sizeof(int) >= 4, "int deve ter pelo menos 4 bytes");
_Static_assert(sizeof(size_t) >= sizeof(int), "size_t deve ser >= int");

/**
 * Estrutura de uma pilha simples
 */
typedef struct pilha_simples
{
    int topo;
    int capacidade;
    size_t *itens;
} stack_t;

/* Garantindo layout da estrutura */
_Static_assert(sizeof(stack_t) >= sizeof(int) * 2, "stack_t deve conter ao menos topo e capacidade");

/**
 * Inicializa a pilha
 *
 * @param p Informar pilha
 * @param capacidade Capacidade da pilha
 */
void pilha_init(stack_t *p, size_t capacidade)
{
    assert(p != NULL);
    assert(capacidade > 0);

    p->topo = -1;
    p->capacidade = (int)capacidade;
    p->itens = malloc(sizeof(size_t) * capacidade);

    assert(p->itens != NULL);
}

/**
 * Libera a pilha
 *
 * @param p Informar pilha
 */
void pilha_destroy(stack_t *p)
{
    assert(p != NULL);

    free(p->itens);
    p->itens = NULL;
}

/**
 * Empilha um valor
 *
 * @param p Informar pilha
 * @param valor Valor a ser empilhado
 */
void pilha_push(stack_t *p, size_t valor)
{
    assert(p != NULL);
    assert(p->topo < p->capacidade - 1);

    p->itens[++p->topo] = valor;
}

/**
 * Desempilha um valor
 *
 * @param p Informar pilha
 * @return valor desempilhado
 */
size_t pilha_pop(stack_t *p)
{
    assert(p != NULL);
    assert(p->topo >= 0);

    return p->itens[p->topo--];
}

int main(int argc, char **argv)
{
    stack_t pilha; // Declarando a pilha

    pilha_init(&pilha, 10); // Capacidade para iniciar a pilha com 10 elementos

    pilha_push(&pilha, 42); // Empilhando valor 42
    pilha_push(&pilha, 99); // Empilhando valor 99

    printf("Pop: %zu\n", pilha_pop(&pilha)); // Deve imprimir 99
    printf("Pop: %zu\n", pilha_pop(&pilha)); // Deve imprimir 42

    pilha_destroy(&pilha); // Liberando recursos da pilha

    return 0;
}
