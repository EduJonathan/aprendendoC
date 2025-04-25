#include <stdio.h>
#include <string.h>

#define MAX_CONVIDADOS 10 // Máximo de convidados na lista
#define MAX_NOME 50       // Tamanho máximo de cada nome

int main(int argc, char **argv)
{
    // Array de convidados, onde cada linha armazena um nome
    char convidados[MAX_CONVIDADOS][MAX_NOME] = {0}; // Inicializa com 0 (vazio)
    int num_convidados = 0;                          // Contador de convidados atuais

    // Ponteiro para os convidados
    char (*ptrConvidados)[MAX_NOME] = convidados;

    // Adicionando convidados manualmente
    if (num_convidados < MAX_CONVIDADOS)
    {
        strcpy(ptrConvidados[num_convidados], "Carlos");
        num_convidados++;
    }

    if (num_convidados < MAX_CONVIDADOS)
    {
        strcpy(ptrConvidados[num_convidados], "Ana");
        num_convidados++;
    }

    if (num_convidados < MAX_CONVIDADOS)
    {
        strcpy(ptrConvidados[num_convidados], "João");
        num_convidados++;
    }

    if (num_convidados < MAX_CONVIDADOS)
    {
        strcpy(ptrConvidados[num_convidados], "Maria");
        num_convidados++;
    }

    // Imprimindo a lista de convidados
    printf("Lista de Convidados:\n");
    for (int i = 0; i < num_convidados; i++)
    {
        printf("%d. %s\n", i + 1, ptrConvidados[i]);
    }

    // Exclusão de um convidado manualmente (excluindo "Ana")
    int excluir_index = -1;
    for (int i = 0; i < num_convidados; i++)
    {
        if (strcmp(ptrConvidados[i], "Ana") == 0)
        {
            excluir_index = i;
            break;
        }
    }

    if (excluir_index != -1)
    {
        // "Excluindo" o convidado (movendo os elementos para a esquerda)
        for (int i = excluir_index; i < num_convidados - 1; i++)
        {
            strcpy(ptrConvidados[i], ptrConvidados[i + 1]);
        }
        memset(ptrConvidados[num_convidados - 1], 0, MAX_NOME); // Limpa o último nome
        num_convidados--;                                       // Atualiza o contador
        printf("\nConvidado 'Ana' excluído da lista.\n");
    }
    else
    {
        printf("\nConvidado 'Ana' não encontrado.\n");
    }

    // Imprimindo a lista de convidados após exclusão
    printf("\nLista de Convidados após exclusão:\n");
    for (int i = 0; i < num_convidados; i++)
    {
        printf("%d. %s\n", i + 1, ptrConvidados[i]);
    }

    // Adicionando um novo convidado "Pedro"
    if (num_convidados < MAX_CONVIDADOS)
    {
        strcpy(ptrConvidados[num_convidados], "Pedro");
        num_convidados++;
    }

    // Imprimindo a lista de convidados final
    printf("\nLista de Convidados Final:\n");
    for (int i = 0; i < num_convidados; i++)
    {
        printf("%d. %s\n", i + 1, ptrConvidados[i]);
    }
    return 0;
}
