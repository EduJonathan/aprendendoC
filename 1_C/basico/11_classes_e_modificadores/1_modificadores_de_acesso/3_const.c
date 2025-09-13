#include <stdio.h>

/**
 * CONST: É um modificador de acesso utilizada para armazenar valores que não podem ser
 * alterados durante a execução, se tornando assim uma varíavel a qual o compilador irá
 * somente ler seu conteúdo.
 */

int main(int argc, char **argv)
{
    // Declarando variável constante
    const int num = 78;
    /**
     * caso tentarmos:
     * num = 5 ou scanf("%d", &num);
     * irá dar ERROR: "assignment of read-only variable" (atribuição de varíavel de leitura apenas)
     */
    printf("Valor de num : %d\n", num);

    // Pode ser declarado assim também, em qualquer tipo de dado,
    // porém o mais aconselável é <CONST DATATYPE>
    char const str[5] = "Olá";
    /// str[0] = 'h'; ERRO: Expression must be a modifiable lvalue

    printf("Valor de str : %s\n", str);
    return 0;
}
