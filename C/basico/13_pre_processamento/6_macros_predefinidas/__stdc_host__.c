#include <stdio.h>

/**
 * Definição: A macro __STDC_HOSTED__ é definida se o compilador estiver operando em um
 * ambiente "hospedado" (hosted environment). Se o valor de __STDC_HOSTED__ for 1, isso
 * indica que o ambiente é hospedado. Caso contrário, o ambiente é considerado
 * "free-standing" (não hospedado).
 *
 * AMBIENTE HOSPEDADO: Em um ambiente hospedado, a implementação do sistema fornece uma
 * biblioteca padrão completa, incluindo funções de entrada/saída (como printf e scanf),
 * gerenciamento de memória dinâmico (como malloc e free), e outros serviços típicos de um
 * sistema operacional completo.
 *
 * AMBIENTE FREE-STANDING: Em um ambiente free-standing, a biblioteca padrão pode estar
 * ausente ou incompleta, e o programa pode precisar de um suporte adicional para funções básicas.
 */

int main(int argc, char **argv)
{
#ifdef __STDC_HOSTED__

#if __STDC_HOSTED__ == 1
    printf("O programa está sendo compilado para um ambiente hospedado\n");
#else
    printf("O programa está sendo compilado para um ambiente livre-standing\n");
#endif

#else
    printf("Informação sobre o ambiente hospedado não disponivel\n");
#endif
    return 0;
}
