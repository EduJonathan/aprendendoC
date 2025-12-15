#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "editor.h"

Editor *criarEditor()
{
    Editor *editor = (Editor *)malloc(sizeof(Editor));
    if (editor == NULL)
    {
        fprintf(stderr, "Erro: Falha ao alocar memória para o editor\n");
        return NULL;
    }
    editor->atual = NULL;
    return editor;
}

void adicionarEstado(Editor *editor, const char *texto)
{
    if (editor == NULL)
    {
        fprintf(stderr, "Erro: Editor não inicializado\n");
        return;
    }

    No *novoNo = criarNo(texto);
    if (novoNo == NULL)
    {
        return;
    }

    // Se já existe um estado atual
    if (editor->atual != NULL)
    {
        // Limpar todos os nós à frente (descartar redo após nova edição)
        No *temp = editor->atual->proximo;
        while (temp != NULL)
        {
            No *proximo = temp->proximo;
            free(temp);
            temp = proximo;
        }
        
        // Conectar o novo nó
        novoNo->anterior = editor->atual;
        editor->atual->proximo = novoNo;
    }
    editor->atual = novoNo; // Atualizar o estado atual
}

int undo(Editor *editor)
{
    if (editor == NULL)
    {
        fprintf(stderr, "Erro: Editor não inicializado\n");
        return 0;
    }

    if (editor->atual == NULL || editor->atual->anterior == NULL)
    {
        printf("Nada para desfazer.\n");
        return 0;
    }
    editor->atual = editor->atual->anterior;
    return 1;
}

int redo(Editor *editor)
{
    if (editor == NULL)
    {
        fprintf(stderr, "Erro: Editor não inicializado\n");
        return 0;
    }

    if (editor->atual == NULL || editor->atual->proximo == NULL)
    {
        printf("Nada para refazer.\n");
        return 0;
    }
    editor->atual = editor->atual->proximo;
    return 1;
}

void exibirEstado(const Editor *editor)
{
    if (editor == NULL)
    {
        fprintf(stderr, "Erro: Editor não inicializado\n");
        return;
    }

    if (editor->atual == NULL)
    {
        printf("Documento vazio.\n");
    }
    else
    {
        printf("Estado atual: %s\n", editor->atual->estado.texto);
    }
}

void liberarEditor(Editor *editor)
{
    if (editor == NULL)
    {
        return;
    }

    No *atual = editor->atual;

    // Mover para o início da lista
    while (atual != NULL && atual->anterior != NULL)
    {
        atual = atual->anterior;
    }

    // Liberar todos os nós
    while (atual != NULL)
    {
        No *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    free(editor);
}
