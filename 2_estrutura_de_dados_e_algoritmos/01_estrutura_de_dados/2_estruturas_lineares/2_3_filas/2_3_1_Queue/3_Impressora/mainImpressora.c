#include <stdio.h>
#include "impressora.h"

int main(int argc, char **argv)
{
    Queue queue;
    initializeQueue(&queue);

    addTarefa(&queue, "Livro", 24, 12, 14);
    addTarefa(&queue, "PDF", 10, 1, 10);
    addTarefa(&queue, "Foto", 1, 1, 1);

    printInterval(&queue);
    printFull(&queue);

    freeQueue(&queue);
    return 0;
}
