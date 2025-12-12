#include <stdio.h>
#include <stdbool.h>

/*
 * Operadores lógicos: São operadores que geram dois resultados possíveis:
 * verdadeiro (1) ou falso (0). Esses operadores são utilizados para combinar ou
 * inverter condições. Os operadores lógicos são:
 *
 * +------------+---------------+
 * | OPERADORES | OPERAÇÃO      |
 * +------------+---------------+
 * |    &&      | AND (E)       |
 * +------------+---------------+
 * |    ||      | OR (OU)       |
 * +------------+---------------+
 * |    !       | NOT (NEGAÇÃO) |
 * +------------+---------------+
 */

int main(int argc, char **argv)
{
    printf("\n\tOPERADOR AND (&&):\n");

    /*
     * O operador AND (&&): retorna verdadeiro (1) apenas se ambos os operandos
     * forem verdadeiros. Caso contrário, o resultado será falso (0).
     * Sua tabela verdade é a seguinte:
     *
     * +---------+---------+--------+
     * | valor x | valor y | x && y |
     * +---------+---------+--------+
     * |    0    |    0    |   0    |
     * +---------+---------+--------+
     * |    0    |    1    |   0    |
     * +---------+---------+--------+
     * |    1    |    0    |   0    |
     * +---------+---------+--------+
     * |    1    |    1    |   1    |
     * +---------+---------+--------+
     */

    int resultado_and = 0;

    resultado_and = (2 < 1) && (4 < 3);                   // (FALSE) && (FALSE)
    printf(" (2 < 1) && (4 < 3) >> %d\n", resultado_and); // Saída: 0

    resultado_and = (2 < 1) && (4 > 3);                   // (FALSE) && (TRUE)
    printf(" (2 < 1) && (4 > 3) >> %d\n", resultado_and); // Saída: 0

    resultado_and = (2 > 1) && (4 < 3);                   // (TRUE) && (FALSE)
    printf(" (2 > 1) && (4 < 3) >> %d\n", resultado_and); // Saída: 0

    resultado_and = (2 > 1) && (4 > 3);                   // (TRUE) && (TRUE)
    printf(" (2 > 1) && (4 > 3) >> %d\n", resultado_and); // Saída: 1

    printf("\n=====================================================================\n");
    printf("\n\tOPERADOR OR (||):\n");

    /*
     * O operador OR (||): retorna verdadeiro (1) se pelo menos um dos operandos
     * for verdadeiro. Só retorna falso (0) se ambos os operandos forem falsos.
     * Sua tabela verdade é a seguinte:
     *
     * +---------+---------+--------+
     * | valor x | valor y | x || y |
     * +---------+---------+--------+
     * |    0    |    0    |   0    |
     * +---------+---------+--------+
     * |    0    |    1    |   1    |
     * +---------+---------+--------+
     * |    1    |    0    |   1    |
     * +---------+---------+--------+
     * |    1    |    1    |   1    |
     * +---------+---------+--------+
     */

    int resultado_or = 0;

    resultado_or = (2 < 1) || (4 < 3);                   // (FALSE) || (FALSE)
    printf(" (2 < 1) || (4 < 3) >> %d\n", resultado_or); // Saída: 0

    resultado_or = (2 < 1) || (4 > 3);                   // (FALSE) || (TRUE)
    printf(" (2 < 1) || (4 > 3) >> %d\n", resultado_or); // Saída: 1

    resultado_or = (2 > 1) || (4 < 3);                   // (TRUE) || (FALSE)
    printf(" (2 > 1) || (4 < 3) >> %d\n", resultado_or); // Saída: 1

    resultado_or = (2 > 1) || (4 > 3);                   // (TRUE) || (TRUE)
    printf(" (2 > 1) || (4 > 3) >> %d\n", resultado_or); // Saída: 1

    printf("\n=======================================================================\n");
    printf("\n\tOPERADOR NOT (!):\n");

    /*
     * O operador NOT (!): nega a condição, ou seja, transforma verdadeiro (1) em falso (0)
     * e falso (0) em verdadeiro (1). Sua tabela verdade é a seguinte:
     *
     * +---------+----+
     * | valor x | !x |
     * +---------+----+
     * |    0    |  1 |
     * +---------+----+
     * |    1    |  0 |
     * +---------+----+
     */

    int resultado_not = 0;

    resultado_not = !(2 < 1);                   // !(FALSE)
    printf(" !(2 < 1) >> %d\n", resultado_not); // Saída: 1

    resultado_not = !(2 > 1);                   // !(TRUE)
    printf(" !(2 > 1) >> %d\n", resultado_not); // Saída: 0

    printf("\n======================================================================\n");
    printf("\n\tEXPRESSÃO UTILIZANDO OPERADORES LÓGICOS\n");

    // Expressão lógica utilizando operadores lógicos
    int a = 7;
    int b = 65;
    int c = 2;
    int d = 90;

    bool expressao_logica = ((a > b) && (c != 0)) || (d <= 5);
    // (false) && (true) || (false)
    // (false) || (false)
    // Resultado: falso (0)
    printf(" A 'expressao_logica' é VERDADEIRA OU FALSA? %d\n", expressao_logica); // Saída: 0

    bool expressao_logica1 = !((a > b) && (c != 0)) || !!(d >= 5);
    // !(false) && (true) || !!(true)
    // (true) || (true)
    // Resultado: verdadeiro (1)
    printf(" A 'expressao_logica1' é VERDADEIRA OU FALSA? %d\n", expressao_logica1); // Saída: 1
    return 0;
}
