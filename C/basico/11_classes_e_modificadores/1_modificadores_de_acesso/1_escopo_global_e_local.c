#include <stdio.h>
#include <stdbool.h>

/*
 * VARIÁVEIS GLOBAIS:
 * São declaradas fora de qualquer função e têm escopo global, ou seja, podem ser acessadas
 * por todo o código. Embora sejam convenientes, o uso excessivo pode aumentar o consumo de
 * memória e tornar o código mais difícil de entender e manter. Além disso, pode haver
 * conflitos de nomes com variáveis locais, o que torna o código mais propenso a erros.
 * Por isso, sempre que possível, prefira variáveis locais.
 */

/**
 * VARIÁVEIS LOCAIS: 
 * São declaradas dentro de funções ou blocos de código (como loops ou condicionais) 
 * e só podem ser acessadas dentro desse escopo. Elas são destruídas após o término da
 * função ou bloco e consomem menos memória. O uso de variáveis locais facilita o entendimento,
 * modulariza o código e ajuda a evitar conflitos de nomes e problemas de memória.
 */

int X = 104;             // Variável global
int variavel_global = 5; // Variável global

int main(int argc, char **argv)
{
    // Não declare nomes iguais de uma varíavel global e local
    int X = 635;
    int variavel_local = 301;

    printf(" X = %d\n", X);
    printf(" variavel_local  = %d\n", variavel_local);
    printf(" variavel_global = %d\n", variavel_global);

    printf("\n--------------------------\n");

    // Variáveis local que podem ser usadas em funções e blocos
    char n[10] = "2,46,789";

    // A variável 'i' está unicamente visivel dentro do for
    for (int i = 0; n[i] != '\0'; i++)
    {
        // Se o caractere for diferente da virgula
        if (n[i] != ',')
        {
            // Imprime o caractere sem a virgula
            printf("%c", n[i]);
        }
    }

    printf("\n--------------------------\n");

    if (variavel_global != variavel_local)
    {
        // Estas variáveis são visiveis apenas dentro do if
        int numero = 10;

        if ((numero % 5 == 0) && (numero % 2 == 0))
        {
            printf("O número '%d' é divisível por 5 e por 2\n", numero);
        }
        else
        {
            printf("O número '%d' não é divisível por 5 e por 2\n", numero);
        }
    }

    // Se você tentar utilizar 'numero' fora do if, causaria um erro,
    // pois ele é visível apenas dentro do bloco do if.

    printf("\n--------------------------\n");

    while (variavel_global != variavel_local)
    {
        // Estas variáveis são visiveis apenas dentro do while
        char str1[15] = "Hello";
        char str2[15] = "World";
        char *copyString1 = str1;
        char *copyString2 = str2;
        int compareString = 0;

        // Comparando as duas strings caractere por caractere
        while (*copyString1 != '\0' && *copyString2 != '\0')
        {
            if (*copyString1 != *copyString2)
            {
                compareString++;
            }
            copyString1++;
            copyString2++;
        }

        // Verificar se uma string é maior que a outra
        if (*copyString1 != '\0' || *copyString2 != '\0')
        {
            compareString++;
        }

        // Verificar se as strings é iguais
        bool isStringEqual = (compareString == 0) ? true : false;
        printf("As strings '%s' e '%s' %s iguais\n", str1, str2, isStringEqual ? "Sim" : "Não");

        /*
         * Sair do while, se não o printf iria entrar em loop devido a condição
         * while (variavel_global != variavel_local).
         */
        break;
    }
    return 0;
}
