#include <stdio.h>

// Criando uma variável static e inicializando com o valor 3
static int staticGlobal = 3;

/**
 * @brief Criando uma função que retorna um static int e cada chamada deverá incrementar
 * seu valor +3.
 *
 * @return static int retorno da variável estatica com o valor atualizado
 */
static int static_global(void)
{
    // Incrementando o valor da variável static global
    staticGlobal += 3;

    // Verificando a atualização a cada chamada realizada
    printf("Variavel estatica global : %d\n", staticGlobal);

    // Retornando o valor
    return staticGlobal;
}

int main(int argc, char **argv)
{
    // Valor retornado é 6
    static_global();

    // Valor retornado é 9
    static_global();

    // Valor retornado é 12
    static_global();
    return 0;
}
