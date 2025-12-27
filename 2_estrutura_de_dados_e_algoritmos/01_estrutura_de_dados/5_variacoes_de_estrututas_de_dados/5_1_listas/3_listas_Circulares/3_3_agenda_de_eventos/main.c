#define _GNU_SOURCE // <- diretiva de compilação (se estiver em um sistema POSIX como Linux ou macOS) para garantir que strdup ou outras funções esteja disponível.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "eventos.h"

int main(int argc, char **argv)
{
    // Configurar locale para caracteres em português
    setlocale(LC_ALL, "pt_BR.UTF-8");

    No *agenda = NULL;

    // Criar eventos (alocando memória para strings)
    Reuniao *r1 = (Reuniao *)malloc(sizeof(Reuniao));
    r1->titulo = strdup("Reunião Equipe");
    r1->horario = strdup("09:00");

    LembretePagamento *lp1 = (LembretePagamento *)malloc(sizeof(LembretePagamento));
    lp1->valor = 100.50;
    lp1->descricao = strdup("Conta de luz");

    Aniversario *a1 = (Aniversario *)malloc(sizeof(Aniversario));
    a1->nome = strdup("João");
    a1->data = strdup("21/09");

    // Inserir eventos na lista circular
    inserirCircular(&agenda, criarNo(TIPO_REUNIAO, r1, 0));             // Segunda
    inserirCircular(&agenda, criarNo(TIPO_LEMBRETE_PAGAMENTO, lp1, 2)); // Quarta
    inserirCircular(&agenda, criarNo(TIPO_ANIVERSARIO, a1, 6));         // Domingo

    // Imprimir a agenda
    imprimirAgenda(agenda);

    // Liberar memória
    liberarAgenda(agenda);
    free(r1->titulo);
    free(r1->horario);
    free(r1);
    free(lp1->descricao);
    free(lp1);
    free(a1->nome);
    free(a1->data);
    free(a1);

    /**
     * COMPILE E EXECUTE COM:
     *
     * > gcc -std=c17 -Wall -Wpedantic main.c eventos.c
     * > .\a.exe
     */
    return 0;
}
