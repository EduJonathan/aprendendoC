#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Declarando uma struct renomeada pelo typedef
 */
typedef struct typedef_para_struct
{
    int dado;       /**< Campo para dado de um inteiro */
} struct_renomeada; /* Nome da struct via typedef */

struct_renomeada GLOBAL = {0};            // Identificador global inicializado
struct_renomeada *PONTEIRO_GLOBAL = NULL; // Ponteiro global inicializado

typedef struct
{
    const char *nome; /**< Campo para o nome */
    int idade;        /**< Campo para a idade */
} dados_pessoa;       // Struct anônima para dados de uma pessoa

// Função para exibir dados de uma pessoa
void print_pessoa(dados_pessoa *p)
{
    printf("Nome: %s, Idade: %d\n", p->nome, p->idade);
}

int main(int argc, char **argv)
{
    struct_renomeada LOCAL = {0};            // Instância local inicializada
    struct_renomeada *PONTEIRO_LOCAL = NULL; // Ponteiro local inicializado

    PONTEIRO_GLOBAL = &GLOBAL; // Inicializando ponteiro global
    PONTEIRO_LOCAL = &LOCAL;   // Inicializando ponteiro local

    GLOBAL.dado = 4;
    LOCAL.dado = 6;

    printf("GLOBAL.dado : %d\n", GLOBAL.dado);
    printf("LOCAL.dado : %d\n", LOCAL.dado);

    PONTEIRO_LOCAL->dado = 78;
    PONTEIRO_GLOBAL->dado = 45;

    printf("PONTEIRO_GLOBAL->dado : %d\n", PONTEIRO_GLOBAL->dado);
    printf("PONTEIRO_LOCAL->dado  : %d\n", PONTEIRO_LOCAL->dado);

    dados_pessoa pessoa;
    pessoa.nome = "João"; // Usamos const char* para evitar modificações em literais
    pessoa.idade = 30;

    print_pessoa(&pessoa);

    // Exemplo com alocação dinâmica
    dados_pessoa *pessoa_dinamica = malloc(sizeof(dados_pessoa));
    if (pessoa_dinamica)
    {
        pessoa_dinamica->nome = "Maria";
        pessoa_dinamica->idade = 25;
        
        printf("Pessoa Dinâmica - ");
        print_pessoa(pessoa_dinamica);
        free(pessoa_dinamica);
    }
    else
    {
        printf("Erro: Falha na alocação de memória\n");
    }

    /**
     * A diferença entre:
     * - `typedef struct typedef_para_struct{...}nomeDaStruct` e `typedef struct { ... }nomeDaStruct`
     *
     * O primeiro define um tipo de struct com um nome específico (`typedef_para_struct`).
     * O segundo define uma struct anônima, acessível apenas pelo nome do typedef (`dados_pessoa`).
     * Ambos permitem criar instâncias e acessar membros, mas o primeiro é reutilizável em outros contextos.
     *
     * @note O conceito é mesmo para (UNIONS e ENUMS)
     */
    return 0;
}
