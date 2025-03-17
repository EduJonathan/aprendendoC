#include <stdio.h>

/* __func__: Exibe o nome da função na qual macro __func__ é exibido. */

/**
 * @brief Procedimento que está utilizando a macro __func__ para exibir o seu
 * nome definido ("myFunction").
 */
void myFunction(void)
{
    printf("Nome da função: %s\n", __func__);
}

int main(int argc, char **argv)
{
    /* Utilizando a macro __func__ para exibir o nome da função principal ("main"). */
    printf("Nome da função: %s\n", __func__);

    /* Chamando a função. */
    myFunction();
    return 0;
}
