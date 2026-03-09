#include <stdio.h>

/**
 * Enum com tipo subjacente fixo (fixed underlying type) é um recurso introduzido no padrão C23.
 * Permite especificar explicitamente o tipo inteiro usado para representar os valores do enum,
 * garantindo consistência (ABI, tamanho, interoperabilidade com outras linguagens, etc.).
 * Antes do C23 (C11/C17/etc.), o tipo era escolhido pelo compilador (implementation-defined).
 */

// Definindo um enum fixo para representar os dias da semana
enum dias_da_semana : int
{
    DOMINGO = 0,
    SEGUNDA = 1,
    TERCA = 2,
    QUARTA = 3,
    QUINTA = 4,
    SEXTA = 5,
    SABADO = 6
};

// Definindo um enum fixo com verificação de suporte ao recurso (C23 ou superior), pois nem todos os compiladores
// podem suportar enums com tipo subjacente fixo em C17.
#if __STDC_VERSION__ >= 202311L // C23 ou superior
enum cores : short
{
    RED,
    GREEN,
    BLUE
};
#else
enum cores
{
    RED,
    GREEN,
    BLUE
};
#endif

int main(int argc, char **argv)
{
    printf("Domingo:    %d\n", DOMINGO);
    printf("Segunda:    %d\n", SEGUNDA);
    printf("Terça:      %d\n", TERCA);
    printf("Quarta:     %d\n", QUARTA);
    printf("Quinta:     %d\n", QUINTA);
    printf("Sexta:      %d\n", SEXTA);
    printf("Sábado:     %d\n", SABADO);

    // Exemplos de uso como tipo
    enum dias_da_semana hoje = QUARTA;
    printf("\nHoje é %d\n", hoje);

    printf("==================================\n");

    printf("Cores:\n");
    printf("Red:   %d\n", RED);
    printf("Green: %d\n", GREEN);
    printf("Blue:  %d\n", BLUE);

    return 0;
}
