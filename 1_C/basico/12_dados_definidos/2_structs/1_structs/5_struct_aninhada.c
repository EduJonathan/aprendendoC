#include <stdio.h>

/*
 * STRUCTS ANINHADAS: Referem-se à prática de incluir uma estrutura (struct) como membro
 * de outra estrutura em linguagens de programação que suportam esse recurso. Isso cria
 * uma relação de composição, onde uma estrutura é parte integrante de outra.
 */

/**
 * @brief Estrutura que representa um endereço. e irá servir para uma apresentar
 * uma struct externa(aninhada). Esta estrutura contém informações sobre um endereço,
 * incluindo a rua, a cidade, o estado e o CEP.
 */
struct Endereco
{
    const char *rua;    /**< Cadeia de caracteres que armazena o nome da rua. */
    const char *cidade; /**< Cadeia de caracteres que armazena o nome da cidade. */
    const char *estado; /**< Cadeia de caracteres que armazena o nome da estado. */
    const char *cep;    /**< Cadeia de caracteres que armazena o nome da cep. */
    unsigned numero;    /**< Tipo unsigned que armazena o o número do imóvel na rua. */
};

/**
 * @brief Estrutura que representa uma pessoa. E é nossa Struct interna(principal) Esta
 * estrutura contém informações pessoais, como o nome, a idade e um endereço.
 */
struct Pessoa
{
    const char *nome;         /**< Campo de uma cadeia de caracteres que armazena o nome da pessoa. */
    unsigned idade;           /**< Campo Armazena a idade da pessoa. */
    struct Endereco endereco; /**< Struct Endereco aninhada com a struct pessoa. */
};

int main(int argc, char **argv)
{
    // Criando uma instância da struct `Pessoa`
    struct Pessoa pessoa = {0}; // Inicializando com zero

    // Preenchendo os dados da pessoa
    pessoa.nome = "João";
    pessoa.idade = 25;

    printf("==>Pessoa\n");
    // Exibindo os dados da pessoa
    printf("Nome  : %s\n", pessoa.nome);
    printf("Idade : %d\n", pessoa.idade);

    // Preenchendo os dados do endereço
    pessoa.endereco.rua = "Rua A";
    pessoa.endereco.numero = 123;
    pessoa.endereco.cidade = "Cidade X";
    pessoa.endereco.estado = "Estado Y";
    pessoa.endereco.cep = "12345-678";

    // Exibindo os dados da endereço da pessoa
    printf("\n==>Endereço\n");
    printf("RUA    : %s\n", pessoa.endereco.rua);
    printf("Número : %d\n", pessoa.endereco.numero);
    printf("Cidade : %s\n", pessoa.endereco.cidade);
    printf("Estado : %s\n", pessoa.endereco.estado);
    printf("CEP    : %s\n", pessoa.endereco.cep);
    return 0;
}
