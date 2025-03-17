#include <stdio.h>

/**
 * FUNÇÕES MACRO: Uma macro em C é uma maneira de definir uma sequência de código que pode
 * ser reutilizada em diferentes partes do programa. Em vez de escrever a mesma expressão
 * repetidamente, você define uma macro uma vez e a utiliza sempre que necessário.
 * No caso de funções macro, elas podem receber parâmetros e são substituídas diretamente
 * no código-fonte pelo pré-processador.
 *
 * IMPORTANTE: Por padrão, macros devem ser escritas em uma única linha. No entanto,
 * se for necessário escrever macros em várias linhas, podemos usar a barra invertida (\)
 * no final de cada linha para indicar que a linha continua na próxima. Isso ajuda a organizar
 * o código sem quebrar a funcionalidade da macro.
 */

// Macro para trocar os valores de duas variáveis de qualquer tipo.
// A macro recebe três parâmetros: os dois valores a serem trocados e o tipo de dado.
#define TROCA(a, b, dataType) \
    {                         \
        dataType temp = a;    \
        a = b;                \
        b = temp;             \
    }

/*
 * Por que usamos `dataType`? A necessidade de um tipo genérico para os parâmetros `a` e `b`
 * se deve ao fato de que a macro pode ser usada para variáveis de tipos diferentes
 * (por exemplo, `int`, `float`, `char`, etc.). O parâmetro `dataType` permite que a macro
 * seja flexível, funcionando com qualquer tipo de dado. O valor de `a` é armazenado
 * temporariamente em `temp`, permitindo a troca dos valores de `a` e `b`.
 */

// Macro para encontrar o valor mínimo e máximo entre dois números.
// A macro recebe quatro parâmetros: os dois números a comparar e as variáveis
// para armazenar o valor mínimo e o valor máximo.
#define MIN_MAX(numero1, numero2, min, max) \
    do                                      \
    {                                       \
        if ((numero1) < (numero2))          \
        {                                   \
            min = (numero1);                \
            max = (numero2);                \
        }                                   \
        else                                \
        {                                   \
            min = (numero2);                \
            max = (numero1);                \
        }                                   \
    } while (0) // O do-while(0) garante que a macro seja tratada como uma única expressão

/*
 * Por que usar `do...while(0)`? O uso do `do-while(0)` evita que a macro gere erros quando
 * usada em diferentes contextos, como dentro de uma estrutura condicional ou de um loop.
 * Sem esse padrão, o código gerado pela macro poderia ser interpretado incorretamente.
 * O `do-while(0)` garante que a macro seja tratada como uma instrução única e evita a
 * necessidade de um ponto e vírgula extra ao utilizá-la.
 */

int main(int argc, char **argv)
{
    // Exemplificando a macro de troca de valores com inteiros
    int x = 10;
    int y = 20;

    // Exibe os valores antes da troca
    printf("Antes da troca - x: %d\ty: %d\n", x, y);

    // Realiza a troca usando a macro TROCA
    TROCA(x, y, int);

    // Exibe os valores após a troca
    printf("Depois da troca - x: %d\ty: %d\n", x, y);

    printf("\n--------------------\n");

    // Exemplificando a troca de valores com caracteres
    char c = '0';
    char l = '1';

    // Exibe os valores antes da troca
    printf("Antes da troca - c: %c\tl: %c\n", c, l);

    // Realiza a troca usando a macro TROCA
    TROCA(c, l, char);

    // Exibe os valores após a troca
    printf("Depois da troca - c: %c\tl: %c\n", c, l);

    printf("\n-------------------------\n");

    // Exemplificando a macro MIN_MAX para encontrar o maior e o menor valor
    int num1 = 10;
    int num2 = 5;
    int min_val = 0;
    int max_val = 0;

    // Chama a macro MIN_MAX para determinar o valor mínimo e máximo
    MIN_MAX(num1, num2, min_val, max_val);

    // Exibe os resultados
    printf("Valor mínimo: %d\n", min_val);
    printf("Valor máximo: %d\n", max_val);

    return 0;
}
