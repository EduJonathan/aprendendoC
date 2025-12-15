#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Enum para representar os tipos de dados suportados.
 */
typedef enum
{
    TYPE_INT,    /**< Inteiro */
    TYPE_CHAR,   /**< Caractere */
    TYPE_STRING, /**< Cadeia de caracteres (string) */
    TYPE_DOUBLE  /**< Número de ponto flutuante (double) */
} DataType;

/**
 * @brief Estrutura que representa um nó da pilha encadeada.
 *
 * Contém um ponteiro genérico para o valor, um identificador do tipo
 * e um ponteiro para o próximo nó.
 */
typedef struct Stack
{
    void *value;        /**< Ponteiro para o valor armazenado. */
    DataType type;      /**< Tipo do valor armazenado. */
    struct Stack *next; /**< Ponteiro para o próximo nó da pilha. */
} Stack;

/**
 * @brief Gera uma pilha encadeada com valores fornecidos pelo usuário.
 *
 * Lê o tamanho da pilha, o tipo de dado e os valores a serem inseridos,
 * alocando dinamicamente cada nó.
 * Exibe a posição de cada valor inserido (0 é o topo).
 *
 * @param stack Ponteiro duplo para o topo da pilha.
 */
void generateStack(Stack **stack);

/**
 * @brief Imprime os elementos da pilha.
 *
 * Mostra os valores da pilha do topo até a base.
 * Se a pilha estiver vazia, exibe uma mensagem.
 *
 * @param stack Ponteiro para o topo da pilha.
 */
void printStack(Stack *stack);

/**
 * @brief Inverte a ordem dos elementos da pilha.
 *
 * Modifica a pilha “in-place”, invertendo a ordem dos nós.
 *
 * @param stack Ponteiro duplo para o topo da pilha.
 */
void reverseStack(Stack **stack);

/**
 * @brief Libera a memória alocada para a pilha.
 *
 * Desaloca todos os nós da pilha e define o topo como NULL.
 *
 * @param stack Ponteiro duplo para o topo da pilha.
 */
void freeStack(Stack **stack);

/**
 * @brief Calcula o tamanho atual da pilha.
 *
 * @param stack Ponteiro para o topo da pilha.
 * @return Número de elementos na pilha.
 */
size_t stackSize(Stack *stack);

/**
 * @brief Ordena os elementos da pilha em ordem crescente.
 *
 * Reorganiza os nós da pilha, mantendo o maior valor no topo.
 *
 * @param stack Ponteiro duplo para o topo da pilha.
 */
void sortStack(Stack **stack);

/**
 * @brief Busca um elemento na pilha.
 *
 * Verifica se o valor especificado existe na pilha, respeitando o tipo de dado.
 *
 * @param stack Ponteiro para o topo da pilha.
 * @param value Valor a ser buscado (deve corresponder ao tipo da pilha).
 * @param type Tipo do valor a ser buscado.
 * @return 1 se o valor for encontrado, 0 caso contrário ou se a pilha for vazia/NULL.
 */
int searchStack(Stack *stack, void *value, DataType type);

#endif
