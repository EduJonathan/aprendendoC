#include <stdio.h>
#include "agenda.h"

int main(int argc, char **argv)
{
    // Inicializa a agenda
    struct agenda *agenda = inicializar_agenda();
    if (agenda == NULL)
    {
        return 1;
    }

    printf("=== Sistema de Agenda Telefônica ===\n\n");

    // Insere alguns contatos
    printf("Inserindo contatos...\n");
    inserir_contato(agenda, "Ana", "1234-5678");
    inserir_contato(agenda, "Carlos", "8765-4321");
    inserir_contato(agenda, "Bianca", "5555-5555");
    inserir_contato(agenda, "Daniel", "9999-8888");

    // Lista todos os contatos (deverá aparecer em ordem alfabética)
    printf("\n");
    listar_contatos(agenda);

    // Busca por um contato específico
    printf("\n");
    struct contato *contato = buscar_contato(agenda, "Carlos");
    if (contato)
    {
        printf("Contato encontrado: %s, %s\n", contato->nome, contato->telefone);
    }
    else
    {
        printf("Contato não encontrado.\n");
    }

    // Remove um contato
    printf("\n");
    if (remover_contato(agenda, "Ana"))
    {
        printf("Contato Ana removido.\n");
    }
    else
    {
        printf("Contato Ana não encontrado.\n");
    }

    // Lista após remoção
    printf("\nLista após remoção:\n");
    listar_contatos(agenda);

    // Teste de atualização de contato
    printf("\nAtualizando telefone do Carlos...\n");
    inserir_contato(agenda, "Carlos", "1111-2222");

    contato = buscar_contato(agenda, "Carlos");
    if (contato)
    {
        printf("Telefone atualizado: %s, %s\n", contato->nome, contato->telefone);
    }

    // Lista final
    printf("\nLista final:\n");
    listar_contatos(agenda);

    // Libera memória
    liberar_agenda(agenda);
    printf("\nAgenda liberada. Programa encerrado.\n");

    /**
     * Compile e execute com:
     *
     * gcc -O3 -std=c17 -Wall -Wshadow -Wpedantic .\agenda.c .\main.c
     * .\a.exe
     */
    return 0;
}
