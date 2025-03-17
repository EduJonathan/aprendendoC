#include <stdio.h>

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
