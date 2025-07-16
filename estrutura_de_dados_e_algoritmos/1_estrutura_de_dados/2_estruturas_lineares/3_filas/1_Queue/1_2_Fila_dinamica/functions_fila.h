#ifndef FUNCOES_FILA_H
#define FUNCOES_FILA_H

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

/**
 * @struct No
 *
 * @brief Estrutura de nó para a lista encadeada
 */
typedef struct no
{
	float valor;		/**< Valor armazenado no nó */
	struct no *proximo; /**< Ponteiro para o próximo nó */
} No;

/**
 * @struct Fila
 *
 * @brief Estrutura de fila utilizando lista encadeada
 */
typedef struct fila
{
	No *inicio; /**< Ponteiro para o início da fila */
	No *fim;	/**< Ponteiro para o fim da fila */
} Fila;

/**
 * @brief Cria uma nova fila vazia.
 *
 * @return Ponteiro para a nova fila criada
 */
Fila *criar_fila(void)
{
	// Aloca memória para a estrutura da fila
	Fila *nova_fila = (Fila *)malloc(sizeof(Fila));

	// Inicializa os ponteiros de início e fim como NULL, indicando uma fila vazia
	nova_fila->inicio = nova_fila->fim = NULL;

	// Retorna o ponteiro para a fila criada
	return nova_fila;
}

/**
 * @brief Verifica se a fila está vazia.
 *
 * @param f Ponteiro para a fila a ser verificada
 * @return 1 se a fila estiver vazia, 0 caso contrário
 */
int vazia(Fila *f)
{
	// Retorna 1 se o ponteiro de início da fila for NULL (fila vazia).
	return (f->inicio == NULL);
}

/**
 * @brief Insere um elemento na fila.
 *
 * @param f Ponteiro para a fila onde o elemento será inserido
 * @param valor Valor a ser inserido na fila
 */
void inserir(Fila *f, float valor)
{
	// Cria um novo nó para armazenar o valor
	No *novo_no = (No *)malloc(sizeof(No));

	novo_no->valor = valor;	 // Define o valor a ser armazenado no nó
	novo_no->proximo = NULL; // Inicializa o ponteiro para o próximo nó como NULL, pois este será o último nó da fila

	if (f->fim != NULL)
	{
		// Se a fila não estiver vazia, atualiza o próximo do último nó
		// para apontar para o novo nó
		f->fim->proximo = novo_no;
	}
	else
	{
		// Se a fila estiver vazia, o novo nó é tanto o início quanto o fim da fila
		f->inicio = novo_no;
	}

	// Atualiza o ponteiro de fim para apontar para o novo último nó
	f->fim = novo_no;
}

/**
 * @brief Remove e retorna o elemento do início da fila.
 *
 * @param f Ponteiro para a fila onde o elemento será removido
 * @return Elemento removido do início da fila
 */
float remover(Fila *f)
{
	// Se a fila estiver vazia, exibe uma mensagem de erro e encerra o programa
	if (vazia(f))
	{
		printf("Fila vazia\n");
		exit(1); // Se a fila estiver vazia, exibe uma mensagem de erro e encerra o programa
	}

	// Armazena o ponteiro para o primeiro nó da fila em 'primeiro_no'
	No *primeiro_no = f->inicio;

	// Armazena o valor do primeiro nó em 'valor_removido'
	float valor_removido = primeiro_no->valor;

	// Atualiza o ponteiro de início para apontar para o próximo nó da fila
	f->inicio = primeiro_no->proximo;

	if (f->inicio == NULL)
	{
		// Se o próximo do início for NULL, a fila está agora vazia,
		// então o ponteiro de fim também é atualizado para NULL
		f->fim = NULL;
	}

	free(primeiro_no);	   // Libera a memória do nó removido
	return valor_removido; // Retorna o valor do nó removido
}

/**
 * @brief Libera toda a memória alocada para a fila.
 *
 * @param f Ponteiro para a fila a ser liberada
 */
void liberar(Fila *f)
{
	// Inicializa um ponteiro 'atual' para percorrer a fila a partir do início
	No *atual = f->inicio;

	while (atual != NULL)
	{
		No *proximo_no = atual->proximo; // Armazena o próximo nó em 'proximo_no' antes de liberar 'atual'
		free(atual);					 // Libera a memória do nó atual 'atual'
		atual = proximo_no;				 // Atualiza 'atual' para apontar para o próximo nó da fila
	}
	free(f); // Por fim, libera a memória da estrutura da fila 'f' em si
}

/**
 * @brief Imprime os elementos da fila.
 *
 * @param f Ponteiro para a fila a ser impressa
 */
void imprimir(Fila *f)
{
	// Inicializa um ponteiro 'atual' para percorrer a fila a partir do início
	No *atual = f->inicio;

	// Percorre a fila imprimindo os elementos
	while (atual != NULL)
	{
		printf("%.2f -> ", atual->valor); // Imprime o valor do nó atual 'atual'
		atual = atual->proximo;			  // Atualiza 'atual' para apontar para o próximo nó da fila
	}
	printf("NULL\n");
}

#endif
