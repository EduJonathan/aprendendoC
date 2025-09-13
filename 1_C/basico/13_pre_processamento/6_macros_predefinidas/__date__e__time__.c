#include <stdio.h>

// __DATE__: Exibe a data de compilação, no formato "Mmm dd yyyy". Exemplo: "18 de dezembro de 2002".
// __TIME__: Exibe a hora de compilação.

/* Macro criada para exibir a hora e a data do dia. */
#define EXIBE_DATA_E_HORA() \
    printf("Arquivo compilado no dia: %s\t na hora: %s\n", __DATE__, __TIME__);

int main(int argc, char **argv)
{
    // Chamada da macro para exibir data e hora
    EXIBE_DATA_E_HORA();
    return 0;
}
