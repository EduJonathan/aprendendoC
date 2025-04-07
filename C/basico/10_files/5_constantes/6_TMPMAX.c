#include <stdio.h>

/**
 * TMPMAX: Define quantos nomes únicos  pode gerar antes de repetir algum nome.
 * Podemos usá-lo para gerar múltiplos nomes de arquivos temporários, Ele representa
 * a quantidade de nomes distintos que podem ser criados antes de ocorrer repetição.
 */

int main(int argc, char **argv)
{
    printf("TMP_MAX: %d\n", TMP_MAX);
    char nomeTemp[L_tmpnam];

    for (int i = 0; i < TMP_MAX; i++)
    {
        tmpnam(nomeTemp);
        printf("Arquivo temporário %d: %s\n", i + 1, nomeTemp);
    }

    return 0;
}
