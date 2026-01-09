#include <stdio.h>
#include <string.h>

/**
 * @brief Definindo uma estrutura que representa até o momento com os campos
 */
struct Pessoa
{
    const char nome[50]; /**< Campo para armazenar o nome */
    unsigned int idade;  /**< Campo para armazenar o idade */
};

int main(int argc, char **argv)
{
    printf("\n\t>>ACESSO COM O '.'\n");
    struct Pessoa Eduardo = {0}; // Inicializando com zero

    /*
     * O operador ponto (.): É utilizado quando você está acessando membros de uma
     * struct usando uma variável do tipo struct diretamente.
     */
    Eduardo.idade = 25U;
    printf(" pessoa.idade : %d\n", Eduardo.idade);

    strcpy(Eduardo.nome, "Eduardo");
    printf(" pessoa.nome : %s\n", Eduardo.nome);

    printf("\n\t>>ACESSO COM A '->'\n");

    /*
     * O operador seta (->): É utilizado quando você está acessando membros de uma struct
     * através de um ponteiro para essa struct.
     */
    struct Pessoa ponteiro_pessoa = {0}; // Inicializando com zero
    struct Pessoa *ponteiroParaPessoa = &ponteiro_pessoa;
    // strcpy((*ponteiroParaPessoa).nome, "Eduardo")
    // (*ponteiroParaPessoa).idade = 75;

    ponteiroParaPessoa->idade = 23U;
    strcpy(ponteiroParaPessoa->nome, "Jonathan");

    printf(" ponteiroParaPessoa->idade: %d\n", ponteiroParaPessoa->idade);
    printf(" ponteiroParaPessoa->nome: %s\n", ponteiroParaPessoa->nome);
    /**
     * As notações '.' (ponto) e "->" (seta) são usadas para acessar tanto membros de
     * structs e unions, mas há uma diferença importante entre elas, relacionada ao tipo
     * de variável usada. A diferença entre ('.') e ("->") está relacionada ao tipo da
     * variável usada para acessar os membros.
     *
     * OBS:
     * Se você estiver usando uma variável do tipo struct, use o operador ponto ('.').
     * Se estiver usando um ponteiro para a struct, use o operador seta ('->').
     */
    return 0;
}
