#include <stdio.h>
#include <stdbool.h>
#include <iso646.h>

// A biblioteca iso646, nos ajuda em operadores lógicos e bitwises que ao vez de declaramos
// com seus respectivos símbolos, podemos simplesmente utilizar a nomeação definida.
// Seu uso é OPCIONAL

/**
 * @brief Demonstra o uso do operador lógico NOT (!).
 *
 * Esta função demonstra o uso do operador `not` para negação lógica.
 *
 * @param n1 Primeiro número para comparação.
 * @param n2 Segundo número para comparação.
 */
void operadorLogicoNot(int n1, int n2)
{
    printf("\n=================================\n");
    printf("\n\tnot(!)\n");

    bool condNot1 = not(n2 >= n1);      // !(n2 >= n1)
    bool condNot2 = not(n1 >= n2);      // !(n1 >= n2)
    bool condNot3 = not(not(n1 >= n2)); // !(!(n1 >= n2))

    printf("CondNot1 é : %d\n", condNot1);
    printf("CondNot2 é : %d\n", condNot2);
    printf("CondNot3 é : %d\n", condNot3);
}

/**
 * @brief Demonstra o uso do operador lógico OR (||).
 *
 * Esta função demonstra o uso do operador `or` para disjunção lógica.
 *
 * @param n1 Primeiro número para comparação.
 * @param n2 Segundo número para comparação.
 */
void operadorLogicoOr(int n1, int n2)
{
    printf("\n=================================\n");

    printf("\n\tor(||): ");

    bool condOr = (n2 >= n2) or (n2 < n2); // (n2 >= n2) || (n2 < n2)
    printf("CondOr é : %d\n", condOr);
}

/**
 * @brief Demonstra o uso dos operadores lógicos AND (&&) e != (not_eq).
 *
 * Esta função demonstra o uso dos operadores `and` para conjunção lógica e `not_eq`
 * para desigualdade.
 *
 * @param n1 Primeiro número para comparação.
 * @param n2 Segundo número para comparação.
 */
void operadorLogicoAnd(int n1, int n2)
{
    printf("\n=================================\n");
    printf("\n\tand(&&)\n");

    // (n1 > n2) && (n2 < n1)
    bool condAnd = (n1 > n2) and (n2 < n1);
    printf("CondAnd é : %d\n", condAnd);

    // (n1 != n2) && (n2 < n1)
    bool condAnd2 = (n1 not_eq n2) and (n2 < n1);
    printf("CondAnd é : %d\n", condAnd2);
    printf("\n=================================\n");
}

/**
 * @brief Demonstra o uso dos operadores bitwise AND (&) e &=.
 *
 * Esta função demonstra o uso do operador `bitand` para AND bitwise e `and_eq` para AND
 * bitwise com atribuição.
 *
 * @param bit1 Primeiro valor bitwise.
 * @param bit2 Segundo valor bitwise.
 */
void operadorBitAnd(int bit1, int bit2)
{
    printf("\n=================================\n");
    printf("\nand(&) : ");

    int BitAnd = bit1 bitand bit2; // bit1 & bit2
    printf("BitAnd é : %d\n", BitAnd);

    printf("\nand_eq(&=): ");

    int BitAndEq = bit1 and_eq bit2; // bit1 &= bit2
    printf("BitAndEq é : %d\n", BitAndEq);
    printf("\n=================================\n");
}

/**
 * @brief Demonstra o uso dos operadores bitwise OR (|) e |=.
 *
 * Esta função demonstra o uso do operador `bitor` para OR bitwise e `or_eq` para OR
 * bitwise com atribuição.
 *
 * @param bit1 Primeiro valor bitwise.
 * @param bit2 Segundo valor bitwise.
 */
void operadorBitOr(int bit1, int bit2)
{
    printf("\n=================================\n");

    printf("\n or(|): ");

    int BitOr = bit1 or bit2; // bit1 | bit2
    printf("BitOr é : %d\n", BitOr);

    printf("\n=================================\n");

    printf("\nor_eq(|=): ");

    int BitOrEq = bit1 or_eq bit2; // bit1 |= bit2
    printf("BitOrEq é : %d\n", BitOrEq);
    printf("\n=================================\n");
}

/**
 * @brief Demonstra o uso dos operadores bitwise XOR (^) e ^=.
 *
 * Esta função demonstra o uso do operador `xor` para XOR bitwise e `xor_eq` para XOR
 * bitwise com atribuição.
 *
 * @param bit1 Primeiro valor bitwise.
 * @param bit2 Segundo valor bitwise.
 */
void operadorBitXor(int bit1, int bit2)
{
    printf("\n xor(^): ");

    int BitXor = bit1 xor bit2; // bit1 ^ bit2
    printf("BitXor é : %d\n", BitXor);

    printf("\n=================================\n");

    printf("\nxor_eq(^=): ");

    int BitXorEq = bit1 xor_eq bit2; // bit1 ^= bit2
    printf("BitXorEq é : %d\n", BitXorEq);
    printf("\n=================================\n");
}

/**
 * @brief Demonstra o uso do operador bitwise NOT (~).
 *
 * Esta função demonstra o uso do operador `compl` para negação bitwise.
 *
 * @param bit1 Valor bitwise para negação.
 */
void operadorBitNot(int bit1)
{
    printf("\nnot(~):");
    int bitNot = compl(bit1); // ~bit1
    printf("\nbitNot é : %d\n", bitNot);

    int bitNot2 = compl(compl(bit1)); // ~(~bit1)
    printf("bitNot2 é : %d\n", bitNot2);
    printf("\n=================================\n");
}

int main(int argc, char **argv)
{
    printf("\n---------------------------------\n");
    printf("\n\t=====>OPERADORES LÓGICOS<=====\n");

    // Definindo valores
    int number1 = 45;
    int number2 = 82;

    // Chamando as funções para realizar as operações
    operadorLogicoNot(number1, number2);
    operadorLogicoOr(number1, number2);
    operadorLogicoAnd(number1, number2);

    printf("\n---------------------------------\n");

    printf("\n=====>OPERADORES BITWISES<=====\n");

    // Definindo valores
    int bit1 = 4;
    int bit2 = 7;

    // Chamando as funções para realizar as operações
    operadorBitAnd(bit1, bit2);
    operadorBitOr(bit1, bit2);
    operadorBitXor(bit1, bit2);
    operadorBitNot(bit1);
    return 0;
}
