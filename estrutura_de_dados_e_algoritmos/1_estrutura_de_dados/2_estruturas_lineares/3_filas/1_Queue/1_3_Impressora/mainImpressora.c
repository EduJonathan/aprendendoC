#include "funcoesImpressoras.h"

int main(int argc, char **argv)
{
    Fila fila;
    inicializarFila(&fila);

    adicionarTrabalho(&fila, "Livro", 24, 12, 14);
    adicionarTrabalho(&fila, "PDF", 10, 1, 10);
    adicionarTrabalho(&fila, "Foto", 1, 1, 1);

    imprimir_intervalo(&fila);
    imprimir_tudo(&fila);

    return 0;
}
