#include <stdio.h>

/**
 * GOTO: É uma instrução em linguagens de programação como C, C++, e outras, que permite
 * transferir o controle do programa para um outro ponto específico no código.
 * Essencialmente, ele faz com que o fluxo de execução "salte" para uma linha de
 * código especificada, que é identificada por um rótulo (label).
 */

int main(int argc, char **argv)
{
    // declarando uma variavel
    int i = 0;

// Este é a LABEL que vai ser usada para o goto
CAMPO:
    // imprimindo a variavel
    printf("%d ", i);

    // incrementando a variavel
    i++;

    // verificando se a variavel eh menor ou igual que 10
    if (i <= 10)
    {
        // se sim, vai para o LABEL CAMPO
        goto CAMPO;
    }
    return 0;
}
