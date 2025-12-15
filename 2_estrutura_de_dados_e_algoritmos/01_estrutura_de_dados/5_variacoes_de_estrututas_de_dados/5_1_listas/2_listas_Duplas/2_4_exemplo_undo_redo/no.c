#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "no.h"

No *criarNo(const char *texto)
{
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo == NULL)
    {
        fprintf(stderr, "Erro: Falha ao alocar memória para o nó\n");
        return NULL;
    }
    strncpy(novoNo->estado.texto, texto, sizeof(novoNo->estado.texto) - 1);
    novoNo->estado.texto[sizeof(novoNo->estado.texto) - 1] = '\0'; // Garantir terminação nula
    novoNo->anterior = NULL;
    novoNo->proximo = NULL;
    return novoNo;
}
