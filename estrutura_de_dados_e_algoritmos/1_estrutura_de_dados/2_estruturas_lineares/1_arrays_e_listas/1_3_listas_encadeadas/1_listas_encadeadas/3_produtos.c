#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Estrutura que representa um produto.
 */
typedef struct tipo_produto
{
    int codigo;                   /**< Código do produto */
    char nome[50];                /**< Nome do produto */
    double preco;                 /**< Preço do produto */
    struct tipo_produto *proximo; /**< Ponteiro para o próximo produto na lista */
} TProduto;

/**
 * @brief Insere um novo produto no final da lista.
 *
 * @param cabeca Ponteiro para o ponteiro do início da lista.
 */
void inserir(TProduto **cabeca)
{
    TProduto *novo = (TProduto *)malloc(sizeof(TProduto));
    if (novo == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        return;
    }

    printf("Codigo do produto: ");
    scanf("%d", &novo->codigo);
    getchar(); // Limpa o '\n' do buffer

    printf("Nome do produto: ");
    fgets(novo->nome, sizeof(novo->nome), stdin);
    novo->nome[strcspn(novo->nome, "\n")] = '\0'; // Remove o '\n'

    printf("Preco do produto: R$");
    scanf("%lf", &novo->preco);
    getchar();

    novo->proximo = NULL;

    if (*cabeca == NULL)
    {
        *cabeca = novo;
    }
    else
    {
        TProduto *atual = *cabeca;
        while (atual->proximo != NULL)
        {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
    printf("Produto adicionado com sucesso!\n");
}

/**
 * @brief Lista todos os produtos cadastrados.
 *
 * @param cabeca Ponteiro para o início da lista de produtos.
 */
void listar(TProduto *cabeca)
{
    if (cabeca == NULL)
    {
        printf("Nenhum produto cadastrado!\n");
        return;
    }

    TProduto *atual = cabeca;
    int i = 1;
    while (atual != NULL)
    {
        printf("\nProduto %d:\n", i++);
        printf("Codigo: %d\n", atual->codigo);
        printf("Nome: %s\n", atual->nome);
        printf("Preco: R$%.2lf\n", atual->preco);
        atual = atual->proximo;
    }
}

/**
 * @brief Busca e exibe um produto pelo seu código.
 *
 * @param cabeca Ponteiro para o início da lista.
 * @param codigo Código do produto a ser buscado.
 */
void buscar(TProduto *cabeca, int codigo)
{
    TProduto *atual = cabeca;
    while (atual != NULL)
    {
        if (atual->codigo == codigo)
        {
            printf("\nProduto encontrado:\n");
            printf("Codigo: %d\n", atual->codigo);
            printf("Nome: %s\n", atual->nome);
            printf("Preco: R$%.2lf\n", atual->preco);
            return;
        }
        atual = atual->proximo;
    }
    printf("Produto com codigo %d nao encontrado!\n", codigo);
}

int main(int argc, char **argv)
{
    TProduto *cabeca = NULL;
    char opcao;
    int codigo_busca;

    do
    {
        printf("\nOpcoes:\n");
        printf("I -> Inserir produto\n");
        printf("L -> Listar produtos\n");
        printf("B -> Buscar produto por codigo\n");
        printf("S -> Sair\n");
        printf("Escolha: ");
        scanf(" %c", &opcao);
        getchar(); // limpa o '\n' deixado no buffer

        switch (opcao)
        {
        case 'I':
        case 'i':
            inserir(&cabeca);
            break;

        case 'L':
        case 'l':
            listar(cabeca);
            break;

        case 'B':
        case 'b':
            printf("Digite o codigo do produto: ");
            scanf("%d", &codigo_busca);
            getchar();
            buscar(cabeca, codigo_busca);
            break;

        case 'S':
        case 's':
            break;

        default:
            printf("Opcao invalida!\n");
        }

    } while (opcao != 'S' && opcao != 's');

    // Libera memória
    TProduto *atual = cabeca;
    while (atual != NULL)
    {
        TProduto *temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    return 0;
}
