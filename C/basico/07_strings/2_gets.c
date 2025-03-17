#include <stdio.h>

int main(int argc, char **argv)
{
    char string[10]; /* Vetor de 10 posicoes para armazenar o nome do usuario*/

    // Solicitando o nome do usuário
    printf("Digite seu nome: ");
    gets(string);

    // Imprimindo o nome do usuário
    printf("%s\n", string);

    /**
     * gets(get string): Pode ser sim uma boa escolha por considerar espaçamentos até
     * você digitar o enter, o porém é que a função não é segura, o próprio compilador
     * diz a respeito sobre ser unsafe (inseguro). Então ele nos recomenda usarmos o fgets.
     * Mas porque gets é inseguro? ele ultrapassa os limites do vetor, se eu digito meu nome
     * "eduardo jonathan", em um vetor de 10 elementos ele imprime o nome todo, sendo que
     * deveria imprimir considerando o espaço até o caractere 'o'.
     *
     * ['e']['d']['u']['a']['r']['d']['o'][' ']['j']['o']['\0']
     *   0    1    2    3    4    5    6    7    8    9   10
     *
     * OBS: Strings SEMPRE termina no caractere '\0', por mais que não o vemos ele está lá.
     * E enquanto aos outros caracteres?
     *
     * ['n']['a']['t']['h']['a']['n']
     *  11   12   13   14   15   16
     * eles vão ocupando posições que não pertencem ao vetor e vão para outros endereços aleátorios.
     */

    printf("\n-----------------------------------------------------\n");

    /* Trecho de código verifica cada atributo do vetor(índice, conteúdo e endereço de memória). */
    for (int i = 0; string[i] != '\0'; i++)
    {
        printf("Índice: %d\tConteúdo: %c\tEndereço: %p\n", i, string[i], &string[i]);
    }
    return 0;
}
