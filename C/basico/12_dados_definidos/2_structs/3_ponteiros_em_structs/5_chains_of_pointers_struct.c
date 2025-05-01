#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// Estrutura que representa um contato
struct Contato
{
    char nome[30];
    char rua[40];
    char cidade[20];
    char estado[3];
    char cep[11];
    struct Contato *proximo;
    struct Contato *anterior;
};

/**
 * @brief Exibe o menu principal e retorna a opção escolhida.
 *
 * @return int A opção selecionada (1 a 5).
 */
int selecionarMenu(void)
{
    char entrada[10];
    int opcao = 0;

    printf("\n1. Adicionar contato\n");
    printf("2. Remover contato\n");
    printf("3. Listar contatos\n");
    printf("4. Buscar contato\n");
    printf("5. Sair\n");

    do
    {
        printf("\nDigite a opção: ");
        fgets(entrada, sizeof(entrada), stdin);
        opcao = atoi(entrada);
    } while (opcao < 1 || opcao > 5);

    return opcao;
}

/**
 * @brief Lê uma string do usuário com segurança.
 *
 * @param mensagem Texto a ser exibido como prompt.
 * @param destino Vetor onde a entrada será armazenada.
 * @param limite Tamanho máximo da string.
 */
void lerEntrada(const char *mensagem, char *destino, int limite)
{
    char buffer[255];

    do
    {
        printf("%s", mensagem);
        fgets(buffer, sizeof(buffer), stdin);
        if (strlen(buffer) > 1 && buffer[strlen(buffer) - 1] == '\n')
        {
            buffer[strlen(buffer) - 1] = '\0';
        }
        if ((int)strlen(buffer) > limite)
            printf("Muito longo. Máximo de %d caracteres.\n", limite);
    } while ((int)strlen(buffer) > limite);

    strcpy(destino, buffer);
}

/**
 * @brief Exibe as informações de um único contato.
 *
 * @param contato Ponteiro para o contato.
 */
void exibirContato(const struct Contato *contato)
{
    printf("\nNome: %s\n", contato->nome);
    printf("Rua: %s\n", contato->rua);
    printf("Cidade: %s\n", contato->cidade);
    printf("Estado: %s\n", contato->estado);
    printf("CEP: %s\n", contato->cep);
    printf("------------\n");
}

/**
 * @brief Busca um contato pelo nome.
 *
 * @param nome Nome do contato a ser buscado.
 * @param inicio Ponteiro para o início da lista.
 * @return struct Contato* Ponteiro para o contato encontrado ou NULL.
 */
struct Contato *buscarContato(const char *nome, struct Contato *inicio)
{
    while (inicio)
    {
        if (!strcmp(nome, inicio->nome))
            return inicio;
        inicio = inicio->proximo;
    }
    return NULL;
}

/**
 * @brief Insere um contato na lista em ordem alfabética.
 *
 * @param novo Ponteiro para o novo contato.
 * @param inicio Ponteiro para o ponteiro do primeiro contato.
 * @param fim Ponteiro para o ponteiro do último contato.
 */
void inserirOrdenado(struct Contato *novo, struct Contato **inicio, struct Contato **fim)
{
    struct Contato *atual = *inicio;
    struct Contato *anterior = NULL;

    if (*fim == NULL)
    {
        novo->proximo = novo->anterior = NULL;
        *inicio = *fim = novo;
        return;
    }

    while (atual && strcmp(atual->nome, novo->nome) < 0)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    if (!anterior)
    {
        novo->proximo = *inicio;
        novo->anterior = NULL;
        (*inicio)->anterior = novo;
        *inicio = novo;
    }
    else
    {
        novo->proximo = atual;
        novo->anterior = anterior;
        anterior->proximo = novo;
        if (atual)
            atual->anterior = novo;
        else
            *fim = novo;
    }
}

/**
 * @brief Adiciona um novo contato.
 *
 * @param inicio Ponteiro para o ponteiro do primeiro contato.
 * @param fim Ponteiro para o ponteiro do último contato.
 */
void adicionarContato(struct Contato **inicio, struct Contato **fim)
{
    struct Contato *novoContato;
    char continuar[5];

    do
    {
        novoContato = (struct Contato *)malloc(sizeof(struct Contato));
        if (!novoContato)
        {
            printf("Sem memória disponível.\n");
            return;
        }

        lerEntrada("Nome: ", novoContato->nome, 29);
        if (!novoContato->nome[0])
        {
            free(novoContato);
            break;
        }

        lerEntrada("Rua: ", novoContato->rua, 39);
        lerEntrada("Cidade: ", novoContato->cidade, 19);
        lerEntrada("Estado (ex: PI): ", novoContato->estado, 2);
        lerEntrada("CEP: ", novoContato->cep, 10);

        inserirOrdenado(novoContato, inicio, fim);

        printf("Deseja adicionar outro contato? (s/n): ");
        fgets(continuar, sizeof(continuar), stdin);
    } while (continuar[0] == 's' || continuar[0] == 'S');
}

/**
 * @brief Remove um contato pelo nome.
 *
 * @param inicio Ponteiro para o ponteiro do primeiro contato.
 * @param fim Ponteiro para o ponteiro do último contato.
 */
void removerContato(struct Contato **inicio, struct Contato **fim)
{
    char nome[30];
    lerEntrada("Nome a remover: ", nome, 29);

    struct Contato *contato = buscarContato(nome, *inicio);
    if (!contato)
    {
        printf("Contato não encontrado.\n");
        return;
    }

    if (contato == *inicio)
        *inicio = contato->proximo;
    if (contato == *fim)
        *fim = contato->anterior;
    if (contato->anterior)
        contato->anterior->proximo = contato->proximo;
    if (contato->proximo)
        contato->proximo->anterior = contato->anterior;

    free(contato);
}

/**
 * @brief Lista todos os contatos da agenda.
 *
 * @param inicio Ponteiro para o início da lista.
 */
void listarContatos(struct Contato *inicio)
{
    while (inicio)
    {
        exibirContato(inicio);
        inicio = inicio->proximo;
    }
}

/**
 * @brief Solicita um nome ao usuário, busca e exibe o contato.
 *
 * @param inicio Ponteiro para o início da lista.
 */
void procurarContato(struct Contato *inicio)
{
    char nome[30];
    lerEntrada("Digite o nome a buscar: ", nome, 29);
    struct Contato *contato = buscarContato(nome, inicio);

    if (contato)
        exibirContato(contato);
    else
        printf("Contato não encontrado.\n");
}

/**
 * @brief Libera toda a memória alocada da lista.
 *
 * @param inicio Ponteiro para o início da lista.
 */
void liberarContatos(struct Contato *inicio)
{
    struct Contato *temp;
    while (inicio)
    {
        temp = inicio;
        inicio = inicio->proximo;
        free(temp);
    }
}

int main(int argc, char **argv)
{
    struct Contato *inicio = NULL;
    struct Contato *fim = NULL;

    for (;;)
    {
        switch (selecionarMenu())
        {
        case 1:
            adicionarContato(&inicio, &fim);
            break;

        case 2:
            removerContato(&inicio, &fim);
            break;

        case 3:
            listarContatos(inicio);
            break;

        case 4:
            procurarContato(inicio);
            break;

        case 5:
            exit(0);
            printf("Saindo...\n");
            return 0;
        }
    }
    
    liberarContatos(inicio);
    return 0;
}
