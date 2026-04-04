#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/**
 * @brief Estrutura para representar o estado do documento
 */
typedef struct
{
    char texto[1000]; ///< Texto do documento (string para simplificar)
} Estado;

/**
 * @brief Estrutura do nó da lista duplamente encadeada
 */
typedef struct no
{
    Estado estado;       ///< Estado do documento armazenado no nó
    struct no *anterior; ///< Ponteiro para o nó anterior
    struct no *proximo;  ///< Ponteiro para o nó seguinte
} No;

/**
 * @brief Estrutura do editor de texto com histórico
 */
typedef struct
{
    No *atual; ///< Nó atual (estado corrente do documento)
} Editor;

/**
 * @brief Cria um novo nó com o texto especificado
 *
 * @param texto Texto a ser armazenado no nó
 * @return Ponteiro para o novo nó alocado
 */
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
    novoNo->proximo  = NULL;
    return novoNo;
}

/**
 * @brief Cria um novo editor vazio
 *
 * @return Ponteiro para o novo editor alocado
 */
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

/**
 * @brief Adiciona um novo estado ao histórico do editor
 *
 * @param editor Ponteiro para o editor
 * @param texto Texto do novo estado a ser adicionado
 */
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
        novoNo->anterior       = editor->atual;
        editor->atual->proximo = novoNo;
    }
    editor->atual = novoNo; // Atualizar o estado atual
}

/**
 * @brief Desfaz a última alteração (undo)
 *
 * @param editor Ponteiro para o editor
 * @return 1 se o undo foi bem-sucedido, 0 caso contrário
 */
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

/**
 * @brief Refaz a última alteração desfeita (redo)
 *
 * @param editor Ponteiro para o editor
 * @return 1 se o redo foi bem-sucedido, 0 caso contrário
 */
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

/**
 * @brief Exibe o estado atual do documento
 *
 * @param editor Ponteiro para o editor
 */
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

/**
 * @brief Libera toda a memória alocada para o editor
 *
 * @param editor Ponteiro para o editor a ser liberado
 */
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
        atual    = atual->proximo;
        free(temp);
    }
    free(editor);
}

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

    return 0;
}
