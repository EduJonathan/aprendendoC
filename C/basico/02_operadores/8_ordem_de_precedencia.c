#include <stdio.h>
#include <stdbool.h>

// Este código exibe a ordem de precedência, ordem de precedência são regras que as instruções
// recebem para serem resolvidas primeiro(tendo mais preferências) do que outras.

int main(int argc, char **argv)
{
    printf("\n\t\tPRECEDÊNCIA DE OPERADORES ARITMÉTICOS:\n");

    // Operadores Aritméticos
    int a = 5, b = 2, c = 10;
    int result = 0;

    result = a + b * c;
    // Multiplicação tem maior precedência, assim como divisão e resto teria também
    // 5 + 2 * 10
    // 5 + 20
    // 25
    printf(" a + b * c = %d\n", result);

    result = (a + c) * c;
    // Tudo que tiver entre parênteses terá maior precedência
    // (5 + 10) * 10
    // 15 * 10
    // 150
    printf("(a + c) * c = %d\n", result);

    result = (a + b) * -c;
    // -c (Deixa o seu conteúdo negativo), tem mais precedência, sendo realizado primeiro
    // (5 + 2) * -10
    // 7 * -10
    // -700
    printf("(a + b) * -c = %d\n", result);

    result = (a + (b * -c));
    // -c (Deixa o seu conteúdo negativo), tem mais precedência a ser realizado primeiro
    // (5 + (2 * -10))
    // (5 + (-20))
    // -15
    printf("(a + (b * -c)) = %d\n", result);

    result = (a++ + b) * -(-c) - --b;
    // (5++ + 2) * -(-10) - --2;
    // (5++ + 2) * 10 - 1;
    // (7) * 10 - 1;
    // 7 * 10 - 1
    // 70 - 1
    // 69
    printf("(a++ + b) * -(-c) - --b = %d\n", result);

    // ... Se desejar pode inserir mais expressões que despertam suas curiosidade
    printf("\n===================================================================\n");
    printf("\n\t\tPRECEDÊNCIA DE OPERADORES LÓGICOS:\n");

    // Operadores Lógicos
    bool x = true, y = false;

    // Expressões booleanas
    bool logicalResult = (x && y) || (x || !y);
    // (true && false) || (true || !false)
    // (false) || (true || true)
    // (false) || (true)
    // true

    bool logicalResult1 = x && y || !!(x || y);
    // (true && false) || !!(true || false)
    // (true && false) || !!(true)
    // (true && false) || !(false)
    // (true && false) || (true)
    // false || true
    // true

    bool logicalResult2 = (x || y) || x || !(y);
    // (true || false) || true || !(false)
    // (true || false) || true || true
    // true || true
    // true

    bool logicalResult3 = (x || y) && !(x || y);
    // (true || false) && !(true || false)
    // (true || false) && !(true)
    // (true || false) && false
    // true && false
    // false

    // ... Se desejar pode inserir mais expressões que despertam suas curiosidade
    printf("(x && y) || (x || !y)  = %d\n", logicalResult);  // Imprime 1 (true)
    printf("(x && y) || !!(x || y) = %d\n", logicalResult1); // Imprime 1 (true)
    printf("(x || y) || x || !(y)  = %d\n", logicalResult2); // Imprime 1 (true)
    printf("(x || y) && !(x || y)  = %d\n", logicalResult3); // Imprime 0 (false)

    printf("\n=================================================================\n");
    printf("\n\t\tPRECEDÊNCIA DE OPERADORES BITWISE:\n");

    int bit1 = 10, bit2 = 35, bit3 = 9;

    int bitwiseResult1 = (bit1 & bit2) | bit3;  // (10 & 35) | 9 => 8
    int bitwiseResult2 = bit1 ^ (bit2 & bit3);  // 10 ^ (35 & 9) => 41
    int bitwiseResult3 = ~bit1 | (bit2 & bit3); // ~(10) | (35 & 9) => -11

    // ... Se desejar pode inserir mais expressões que despertam suas curiosidade
    printf("(bit1 & bit2) | bit3  = %d\n", bitwiseResult1);
    printf("bit1 ^ (bit2 & bit3)  = %d\n", bitwiseResult2);
    printf("~bit1 | (bit2 & bit3) = %d\n", bitwiseResult3);
    return 0;
}
