#include <stdio.h>

/**
 * VARIÁVEIS DE BLOCO: São declaradas dentro de um conjunto de chaves, seja fora ou dentro
 * de uma função, seu tratamento ocorrer somente dentro de onde foram estão declaradas {},
 * não devem possuir as mesmas nomeações tanto de varíaveis globais, quanto de varíaveis
 * locais, ou então elas perderá o acesso.
 */

int main(int argc, char **argv)
{
    // Variáveis locais
    int a = 8;
    int p = 5;

    // Variáveis de bloco
    {
        int b = 12;
        int r = a + b;
        int p = 3;
        printf("a + b: %d\n", r);
    }

    // r = b + a;
    // printf("b + a: %d\n", r);
    // Erro pois a varíavel r está dentro do escopo de bloco

    // Variável 'p' local, sobrescreve a que está no bloco
    printf(" p: %d\n", p);
    return 0;
}
