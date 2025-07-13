#include <stdio.h>

/**
 * @brief Declarando uma struct renomeada pelo typedef
 */
typedef struct typedef_para_struct
{
    int dado;       /**< Campo para dado de um inteiro*/
} struct_renomeada; /* Aqui declaramos o nome da nova struct de acordo com o typedef */

struct_renomeada GLOBAL;           // Identificador global da struct_renomeada
struct_renomeada *PONTEIRO_GLOBAL; // Ponteiro para a global de struct_renomeada

typedef struct
{
    const char *nome; /**< Campo para o nome */
    int idade;        /**< Campo para a idade */
} dados_pessoa;       // Definindo uma struct para dados de uma pessoa

int main(int argc, char **argv)
{
    struct_renomeada LOCAL;           // Instância local
    struct_renomeada *PONTEIRO_LOCAL; // Ponteiro local

    PONTEIRO_GLOBAL = &GLOBAL; // Inicializando ponteiro global
    PONTEIRO_LOCAL = &LOCAL;   // Inicializando ponteiro local

    GLOBAL.dado = 4;
    LOCAL.dado = 6;

    printf("GLOBAL.dado : %d\n", GLOBAL.dado);
    printf("LOCAL.dado  : %d\n", LOCAL.dado);

    PONTEIRO_LOCAL->dado = 78;
    PONTEIRO_GLOBAL->dado = 45;

    printf("(*PONTEIRO_GLOBAL)->dado = %d\n", PONTEIRO_GLOBAL->dado);
    printf("(*PONTEIRO_LOCAL)->dado  = %d\n", PONTEIRO_LOCAL->dado);

    dados_pessoa pessoa;
    pessoa.nome = "João";
    pessoa.idade = 30;

    printf("Nome: %s, Idade: %d\n", pessoa.nome, pessoa.idade);

    /**
     * A diferença entre:
     * - `typedef struct typedef_para_struct{...}nomeDaStruct` e `typedef struct { ... }nomeDaStruct`
     *
     * É que o primeiro define um tipo de struct com um nome específico
     * (`typedef_para_struct é o nome da struct`).
     * Enquanto o segundo define uma struct anônima sem nome, mas ainda pode ser usada
     * com o tipo `dados_pessoa`. Ambos os casos permitem criar instâncias da struct
     * e acessar seus membros, mas o primeiro caso permite reutilizar o nome da struct
     * em outras partes do código. Vale o mesmo para unions e enums.
     */
    return 0;
}
