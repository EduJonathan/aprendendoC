#include <stdio.h>

/* Um ponteiro que está apontando para uma estrutura é conhecido como ponteiro para estrutura. */

/**
 * @brief Estrutura para representar os dados de um livro.
 *
 * Esta estrutura armazena informações sobre um livro, incluindo o autor, o título
 * e um identificador único.
 */
struct dados_do_livro
{
    const char autor_do_livro[50]; /**< Campo para definir o autor do livro. */
    const char *livro;             /**< Campo para definir o nome do livro. */
    unsigned int id;               /**< Campo para o id do livro. */
};

/**
 * @brief procedimento para imprimir as informações do livro usando um ponteiro para estrutura
 *
 * @param detalhes Parâmetro para passar as referências do livro para imprimir as informações
 */
void imprime_informacao(struct dados_do_livro *detalhes)
{
    printf("\nNome do livro: %s\nAutor do livro: %s\nID: %d\n", detalhes->livro, detalhes->autor_do_livro, detalhes->id);
    printf("ENDEREÇO DA STRUCT detalhes: %p | CONTEÚDO DA STRUCT detalhes: %p\n", &detalhes, detalhes);
}

/**
 * @brief Função para imprimir os endereços das estruturas e seus ponteiros.
 *
 * @param informacao Estrutura de dados do livro
 * @param livro Ponteiro para a estrutura do livro
 */
void imprime_enderecos(struct dados_do_livro *informacao, struct dados_do_livro *livro)
{
    printf("\nENDEREÇO DA STRUCT informacao_livro: %p | ENDEREÇO DA STRUCT livro: %p\n", informacao, livro);
    printf("CONTEÚDO DA STRUCT livro: %p\n", livro);
}

int main(int argc, char **argv)
{
    // Inicializa uma estrutura dados_do_livro com informações específicas
    struct dados_do_livro informacao_livro = {"Python para Iniciantes", "Nilo Ney", 0};
    struct dados_do_livro informacao_livro2 = {"Algoritmos", "Autor Desc.", 1};

    // Cria um ponteiro para estrutura e o faz apontar para a estrutura informacao_livro
    struct dados_do_livro *livro = &informacao_livro;
    struct dados_do_livro *livro2 = &informacao_livro2;

    // Chama a função para imprimir as informações do livro usando o ponteiro para estrutura
    imprime_informacao(livro);
    imprime_informacao(livro2);

    // Chama a função que imprime os endereços das estruturas e ponteiros
    imprime_enderecos(&informacao_livro, livro);
    imprime_enderecos(&informacao_livro2, livro2);
    return 0;
}
