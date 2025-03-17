#ifndef AGENDA_H
#define AGENDA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo o tamanho máximo dos buffers
#define TAMANHO_NOME 100
#define TAMANHO_TELEFONE 15

/**
 * @brief Estrutura que representa um contato na agenda.
 *
 * Contém o nome e o telefone do contato, bem como um ponteiro para o próximo contato na agenda.
 */
struct Contato
{
    char nome[TAMANHO_NOME];         /**< Nome do contato. */
    char telefone[TAMANHO_TELEFONE]; /**< Telefone do contato. */
    struct Contato *prox;            /*** Ponteiro para próximo contato na agenda */
};

/**
 * @brief Cria um novo contato e o retorna.
 *
 * Aloca memória para um novo contato e o inicializa com os valores de nome e telefone
 * passados como parâmetros. Caso a alocação falhe, uma mensagem de erro será impressa
 * e NULL será retornado.
 *
 * @param nome Nome do contato a ser criado.
 * @param telefone Telefone do contato a ser criado.
 * @return Ponteiro para o novo contato criado, ou NULL se a alocação falhar.
 */
struct Contato *criarContato(const char *nome, const char *telefone)
{
    struct Contato *novoContato = (struct Contato *)malloc(sizeof(struct Contato));

    if (novoContato == NULL)
    {
        printf("Erro de alocação de memória!\n");
        return NULL;
    }

    // Usando strncpy para evitar buffer overflow
    strncpy(novoContato->nome, nome, TAMANHO_NOME - 1);
    novoContato->nome[TAMANHO_NOME - 1] = '\0'; // Garantir que a string termine com '\0'

    strncpy(novoContato->telefone, telefone, TAMANHO_TELEFONE - 1);
    novoContato->telefone[TAMANHO_TELEFONE - 1] = '\0'; // Garantir que a string termine com '\0'

    novoContato->prox = NULL;
    return novoContato;
}

/**
 * @brief Insere um contato na lista em ordem alfabética.
 *
 * Aloca memória para um novo contato e o insere na lista em ordem alfabética.
 * Caso a lista esteja vazia, o novo contato será o primeiro.
 *
 * @param lista Ponteiro para o ponteiro que aponta para o primeiro contato na lista.
 * @param nome Nome do contato a ser inserido.
 * @param telefone Telefone do contato a ser inserido.
 */
void inserirContato(struct Contato **lista, const char *nome, const char *telefone)
{
    struct Contato *novoContato = criarContato(nome, telefone);
    struct Contato *temp = *lista;

    if (novoContato == NULL)
    {
        // Caso a alocação falhe
        return;
    }

    // Se a lista estiver vazia ou o nome do novo contato for lexicograficamente menor
    // que o nome do primeiro contato da lista, o novo contato será inserido no início.
    // Caso contrário, o código percorre a lista até encontrar a posição correta,
    // inserindo o contato em ordem alfabética.
    if (*lista == NULL || strncmp(nome, (*lista)->nome, TAMANHO_NOME) < 0)
    {
        novoContato->prox = *lista;
        *lista = novoContato;
        return;
    }

    while (temp->prox != NULL && strncmp(temp->prox->nome, nome, TAMANHO_NOME) < 0)
    {
        temp = temp->prox;
    }

    novoContato->prox = temp->prox; // Insere o novo contato
    temp->prox = novoContato;       // Insere o novo contato
}

/**
 * @brief Função para buscar um contato na lista encadeada.
 *
 * Percorre a lista e retorna o ponteiro para o contato encontrado, ou NULL se o contato
 * não for encontrado.
 *
 * @param lista Ponteiro para o primeiro elemento da lista encadeada.
 * @param nome Nome do contato a ser buscado.
 * @return Ponteiro para o contato encontrado, ou NULL se o contato não for encontrado.
 */
struct Contato *buscarContato(struct Contato *lista, const char *nome)
{
    struct Contato *temp = lista;

    // Percorrer a lista até encontrar o contato
    while (temp != NULL)
    {
        // Usando strncasecmp para comparação segura e sem case-sensitive
        if (strncasecmp(temp->nome, nome, TAMANHO_NOME) == 0)
        {
            // Encontrou o contato
            return temp;
        }

        temp = temp->prox;
    }

    return NULL; // Contato não encontrado
}

/**
 * @brief Exclui um contato da lista encadeada.
 *
 * Percorre a lista e remove o contato com o nome especificado. Se o contato
 * não for encontrado, imprime uma mensagem de erro.
 *
 * @param lista Ponteiro para o ponteiro que aponta para o primeiro contato na lista.
 * @param nome Nome do contato a ser excluído.
 */
void excluirContato(struct Contato **lista, const char *nome)
{
    struct Contato *temp = *lista;
    struct Contato *anterior = NULL;

    if (*lista == NULL)
    {
        printf("A lista está vazia.\n");
        return;
    }

    // Percorrer a lista até encontrar o contato ou o final
    while (temp != NULL && strncmp(temp->nome, nome, TAMANHO_NOME) != 0)
    {
        anterior = temp;
        temp = temp->prox;
    }

    // Se o contato foi encontrado
    if (temp != NULL)
    {
        // Se o contato a ser removido é o primeiro
        if (anterior == NULL)
        {
            // Atualiza a cabeça da lista
            *lista = temp->prox;
        }
        else
        {
            // Remove o contato da lista
            anterior->prox = temp->prox;
        }

        free(temp); // Libera a memória do contato
        printf("Contato '%s' excluído com sucesso.\n", nome);
    }
    else
    {
        printf("Contato '%s' não encontrado para exclusão.\n", nome);
    }
}

/**
 * @brief Imprime todos os contatos da lista encadeada.
 *
 * Percorre a lista e imprime o nome e telefone de cada contato.
 *
 * @param lista Ponteiro para o primeiro elemento da lista encadeada.
 */
void imprimirLista(struct Contato *lista)
{
    struct Contato *temp = lista;

    while (temp != NULL)
    {
        printf("Nome: %s | Telefone: %s\n", temp->nome, temp->telefone);
        temp = temp->prox;
    }
}

/**
 * @brief Libera a memória alocada para a lista encadeada de contatos.
 *
 * Esta função percorre a lista de contatos e libera a memória de cada contato.
 * Após a liberação, o ponteiro para a lista é atualizado para NULL, garantindo
 * que a lista esteja vazia após a operação.
 *
 * @param lista Ponteiro para o ponteiro que aponta para o primeiro contato na lista.
 */
void liberarMemoria(struct Contato **lista)
{
    struct Contato *temp = *lista;

    while (temp != NULL)
    {
        struct Contato *proximo = temp->prox;
        free(temp);
        temp = proximo;
    }

    // Garantir que o ponteiro principal seja NULL após a liberação
    *lista = NULL;
}

#endif
