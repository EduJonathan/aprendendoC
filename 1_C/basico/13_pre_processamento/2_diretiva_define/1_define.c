#include <stdio.h>

/**
 * DEFINE: Diretiva de compilação que informa ao compilador que ele deve procurar todas as
 * ocorrências da palavra definida por nome_da_constante e substituir por valor_da_constante
 * quando o programa for compilado.
 *
 * SINTAXE: #define nome_da_constante valor_da_constante
 */

// IMPRIMINDO UMA MENSAGEM
#define MSG "OI! VAMOS APRENDER O #DEFINE"

#define SIZEARR 10U // Podemos entregar um define com prefixos para determinar tamanhos
#define LINHAS 4U   // Como para matriz também, aqui criamos para representar 4 linhas
#define COLUNAS 4U  // E aqui criamos para representar 4 colunas
#define PI 3.14159  // Definindo uma constante simbólica

// Definindo uma macro (macro se define quando estiver entre parênteses), aqui temos uma
// macro que calcula o quadrado de um número
#define SQUARE(x) ((x) * (x))
// 'x' é um parâmetro que quando aplicado um valor para ele na chamada do define todos os
// param 'x' será substituido por esse valor, para evitar conflitos e erros nos parâmetros
// separem por "()"

#define MIN(a, b) (((a) < (b)) ? a : b)                    // Macro com argumentos
#define PRINT_MENSAGEM(msg) printf("Mensagem: %s\n", msg); // Exibindo mensagem

// Verificando com a macro utilizando uma operação ternária o valor ABS de um número
#define ABS(a) ((a) < 0 ? -(a) : (a))

int main(int argc, char **argv)
{
    // Imprimindo a mensagem contida no define MSG
    printf("%s\n", MSG);

    putchar('\n');

    // Inicializando o array com a constante de define e depois o imprimindo
    int arr[SIZEARR] = {0}; // Inicializando o array com zeros

    for (int i = 0; i < 10; i++)
    {
        arr[i] = i;
        printf("Valores de arr: %d\n", arr[i]);
    }

    putchar('\n');

    // Inicializando a matriz com o define e logo após a imprimindo
    int matriz[LINHAS][COLUNAS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
    };

    for (int l = 0; l < LINHAS; l++)
    {
        for (int c = 0; c < COLUNAS; c++)
        {
            printf("Valor atual de matriz[%d][%d] = %d ", l, c, matriz[l][c]);
        }
        printf("\n");
    }

    putchar('\n');

    // Definindo um valor para o raio
    double raio = 5.0;

    // Utilizando a constante simbólica
    double area = PI * SQUARE(raio);
    // 3.14159 * (5.0)
    // 3.14159 * ((5.0) * (5.0))
    // 3.14159 * 25.0
    // 78.539750

    // Imprimindo o resultado
    printf("Área do círculo : %lf\n", area);

    // Menor número
    printf("O menor número é : %d\n", MIN(10, 20));

    printf("O VALOR ABS é : %d\n", ABS(2));     // (2) < 0 ? -(2) : (2)
    printf("O VALOR ABS é : %d\n", ABS(2 - 1)); // (2 - 1) < 0 ? -(2 - 1) : (2 - 2)

    PRINT_MENSAGEM("Olá!! Eu sou o #DEFINE, E FIM!");
    return 0;
}
