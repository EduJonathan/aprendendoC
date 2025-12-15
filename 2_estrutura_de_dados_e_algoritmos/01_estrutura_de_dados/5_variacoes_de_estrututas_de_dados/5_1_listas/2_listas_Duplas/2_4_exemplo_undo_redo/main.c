#include <stdio.h>
#include <locale.h>
#include "editor.h"

int main(int argc, char **argv)
{
    // Configurar locale para caracteres em português
    setlocale(LC_ALL, "pt_BR.UTF-8");

    Editor *editor = criarEditor();
    if (editor == NULL)
    {
        fprintf(stderr, "Erro: Não foi possível criar o editor\n");
        return 1;
    }

    // Adicionando alguns estados
    printf("Adicionando estados:\n");
    adicionarEstado(editor, "Primeira versão do texto");
    exibirEstado(editor);

    adicionarEstado(editor, "Texto com alterações");
    exibirEstado(editor);

    adicionarEstado(editor, "Texto final");
    exibirEstado(editor);

    // Testando Undo
    printf("\nDesfazendo alterações:\n");
    undo(editor);
    exibirEstado(editor);
    undo(editor);
    exibirEstado(editor);
    undo(editor); // Tentativa de undo além do início

    // Testando Redo
    printf("\nRefazendo alterações:\n");
    redo(editor);
    exibirEstado(editor);
    redo(editor);
    exibirEstado(editor);
    redo(editor); // Tentativa de redo além do fim

    // Liberando a memória
    liberarEditor(editor);

    /**
     * COMPILE E EXECUTE COM:
     *
     * > gcc -std=c17 -Wall -Wpedantic .\copy.c .\no.c .\main.c
     * > .\a.exe
     */
    return 0;
}
