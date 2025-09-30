#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"

unsigned int hash(const char *nome)
{
    unsigned int valor = 0;
    for (int i = 0; nome[i] != '\0'; i++)
    {
        valor = valor * 31 + nome[i];
    }
    return valor % TAMANHO_TABELA;
}

struct contato *criar_contato(const char *nome, const char *telefone)
{
    struct contato *novo = malloc(sizeof(struct contato));
    if (novo == NULL)
    {
        printf("Erro: falha ao alocar memória!\n");
        return NULL;
    }
    strncpy(novo->nome, nome, sizeof(novo->nome) - 1);
    novo->nome[sizeof(novo->nome) - 1] = '\0';
    strncpy(novo->telefone, telefone, sizeof(novo->telefone) - 1);
    novo->telefone[sizeof(novo->telefone) - 1] = '\0';
    novo->proximo = NULL;
    return novo;
}

struct agenda *inicializar_agenda()
{
    struct agenda *agenda = malloc(sizeof(struct agenda));
    if (agenda == NULL)
    {
        printf("Erro: falha ao alocar memória para a agenda!\n");
        return NULL;
    }

    for (int i = 0; i < TAMANHO_TABELA; i++)
    {
        agenda->tabela[i] = NULL;
    }
    return agenda;
}

struct contato *inserir_contato(struct agenda *agenda, const char *nome, const char *telefone)
{
    if (agenda == NULL || nome == NULL || telefone == NULL)
    {
        return NULL;
    }

    unsigned int indice = hash(nome);
    struct contato **atual = &(agenda->tabela[indice]);

    // Procura a posição correta mantendo a lista ordenada
    while (*atual != NULL)
    {
        int cmp = strcmp(nome, (*atual)->nome);
        if (cmp == 0)
        {
            // Contato já existe, atualiza telefone
            strncpy((*atual)->telefone, telefone, sizeof((*atual)->telefone) - 1);
            (*atual)->telefone[sizeof((*atual)->telefone) - 1] = '\0';
            return *atual;
        }
        if (cmp < 0)
        {
            // Encontrou a posição de inserção
            break;
        }
        atual = &((*atual)->proximo);
    }

    // Cria e insere o novo contato
    struct contato *novo = criar_contato(nome, telefone);
    if (novo == NULL)
        return NULL;

    novo->proximo = *atual;
    *atual = novo;
    return novo;
}

struct contato *buscar_contato(struct agenda *agenda, const char *nome)
{
    if (agenda == NULL || nome == NULL)
    {
        return NULL;
    }

    unsigned int indice = hash(nome);
    struct contato *atual = agenda->tabela[indice];

    while (atual != NULL)
    {
        if (strcmp(atual->nome, nome) == 0)
        {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

struct contato **remover_contato(struct agenda *agenda, const char *nome)
{
    if (agenda == NULL || nome == NULL)
    {
        return NULL;
    }

    unsigned int indice = hash(nome);
    struct contato **atual = &(agenda->tabela[indice]);
    struct contato *temp = NULL;

    while (*atual != NULL)
    {
        if (strcmp((*atual)->nome, nome) == 0)
        {
            temp = *atual;
            *atual = (*atual)->proximo;
            free(temp);
            return atual;
        }
        atual = &((*atual)->proximo);
    }
    return NULL;
}

struct contato **coletar_contatos(struct agenda *agenda, int *num_contatos)
{
    if (agenda == NULL || num_contatos == NULL)
    {
        return NULL;
    }

    // Conta o número total de contatos
    *num_contatos = 0;
    for (int i = 0; i < TAMANHO_TABELA; i++)
    {
        struct contato *atual = agenda->tabela[i];
        while (atual != NULL)
        {
            (*num_contatos)++;
            atual = atual->proximo;
        }
    }

    // Aloca array para os contatos
    struct contato **contatos = malloc(*num_contatos * sizeof(struct contato *));
    if (contatos == NULL)
    {
        return NULL;
    }

    // Coleta todos os contatos
    int k = 0;
    for (int i = 0; i < TAMANHO_TABELA; i++)
    {
        struct contato *atual = agenda->tabela[i];
        while (atual != NULL)
        {
            contatos[k++] = atual;
            atual = atual->proximo;
        }
    }

    // Ordena os contatos por nome usando bubble sort
    for (int i = 0; i < *num_contatos - 1; i++)
    {
        for (int j = 0; j < *num_contatos - i - 1; j++)
        {
            if (strcmp(contatos[j]->nome, contatos[j + 1]->nome) > 0)
            {
                struct contato *temp = contatos[j];
                contatos[j] = contatos[j + 1];
                contatos[j + 1] = temp;
            }
        }
    }
    return contatos;
}

void listar_contatos(struct agenda *agenda)
{
    if (agenda == NULL)
    {
        printf("Agenda inválida!\n");
        return;
    }

    int num_contatos = 0;
    struct contato **contatos = coletar_contatos(agenda, &num_contatos);
    if (contatos == NULL)
    {
        printf("Erro: falha ao alocar memória para listagem.\n");
        return;
    }

    if (num_contatos == 0)
    {
        printf("Nenhum contato na agenda.\n");
    }
    else
    {
        printf("Lista de contatos (%d contatos):\n", num_contatos);
        for (int i = 0; i < num_contatos; i++)
        {
            printf("Nome: %s, Telefone: %s\n", contatos[i]->nome, contatos[i]->telefone);
        }
    }
    free(contatos);
}

void liberar_agenda(struct agenda *agenda)
{
    if (agenda == NULL)
    {
        return;
    }

    for (int i = 0; i < TAMANHO_TABELA; i++)
    {
        struct contato *atual = agenda->tabela[i];
        while (atual != NULL)
        {
            struct contato *temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }
    free(agenda);
}
