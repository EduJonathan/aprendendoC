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

int main(int argc, char **argv)
{
    struct_renomeada LOCAL;           // Identificador local da struct_renomeada
    struct_renomeada *PONTEIRO_LOCAL; // Ponteiro para a local da struct_renomeada

    // Acesso de GLOBAL ao membro
    GLOBAL.dado = 4;

    // Acesso de LOCAL ao membro dado
    LOCAL.dado = 6;

    // Imprimindo os valores do campo dado
    printf("GLOBAL.dado : %d\n", GLOBAL.dado);
    printf("LOCAL.dado  : %d\n", LOCAL.dado);

    // Acesso do ponteiro local ao membro dado
    (*PONTEIRO_LOCAL).dado = 78;

    // Acesso do ponteiro global ao membro dado
    (*PONTEIRO_GLOBAL).dado = 45;

    // Imprimindo os valores do campo dado
    printf("(*PONTEIRO_GLOBAL)->dado = %d\n", PONTEIRO_GLOBAL->dado);
    printf("(*PONTEIRO_LOCAL)->dado  = %d\n", PONTEIRO_LOCAL->dado);
    return 0;
}
