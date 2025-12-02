#include <stdio.h>

/**
 * FUNÇÕES MACRO: Macros em C permitem definir trechos de código reutilizáveis que são
 * substituídos diretamente pelo pré-processador antes da compilação. Quando recebem
 * parâmetros, funcionam como “funções inline textuais”, evitando repetições no código.
 *
 * IMPORTANTE: Por padrão, macros são escritas em uma única linha. Para criar macros
 * multilinha, utiliza-se a barra invertida (\) ao final de cada linha, indicando que a
 * instrução continua na próxima. Isso facilita a organização sem alterar o comportamento
 * da macro.
 */

/**
 * Macro para trocar os valores de duas variáveis de qualquer tipo.
 *
 * @note O parâmetro `dataType` permite que a macro funcione com qualquer tipo
 *       (int, float, char, etc.). Um valor temporário é usado para armazenar `a`
 *       enquanto os valores são trocados.
 */
#define TROCA(a, b, dataType) \
    {                         \
        dataType temp = a;    \
        a = b;                \
        b = temp;             \
    }

/**
 * Macro para determinar o valor mínimo e máximo entre dois números.
 *
 * @note O padrão `do { ... } while (0)` garante que a macro seja tratada como
 *       uma única instrução, evitando problemas quando usada em `if`, loops
 *       ou outros blocos de controle.
 */
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

// Definindo a macro "let" para criar uma variável de tipo e nome especificados
#define let(type, name)                                  \
    /* Cria uma variável do tipo "type" e nome "name" */ \
    type name

/**
 * Macro "match": simula uma estrutura switch-case baseada em um valor.
 *
 * @note A macro `match` permite criar uma lógica semelhante ao switch-case,
 *       executando ações específicas conforme o valor fornecido. É uma forma
 *       de gerar despachos condicionais usando apenas o pré-processador.
 */
#define match(value, ...)                                                       \
    ({                                                                          \
        /* Armazena o valor em uma variável do mesmo tipo do valor fornecido */ \
        typeof(value) __val = (value);                                          \
                                                                                \
        /* Inicia o switch com o valor armazenado */                            \
        switch (__val)                                                          \
        {                                                                       \
            /* As instruções fornecidas como argumento para a macro "match" */  \
            __VA_ARGS__                                                         \
        }                                                                       \
    })

/**
 * Macro para criar um caso dentro de um switch.
 *
 * @note A macro recebe um valor (`val`) e uma ação (`action`) e os expande como um
 *       caso do switch. É apenas uma substituição textual, mas não é recomendável
 *       redefinir palavras-chave da linguagem (como `case`), pois pode causar
 *       confusão e dificultar a leitura do código.
 */
#define case(val, action)                                          \
    case val:                                                      \
                                                                   \
        action; /* Para o valor "val", executa a ação fornecida */ \
                                                                   \
        break; /* Interrompe o switch após a execução */

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

    printf("\n-------------------------\n");

    // Exemplificando o uso da macro let para declarar variáveis
    let(int, a) = 5;

    // Usando a macro match para comparar o valor de 'a'
    match(a,
          case (1, printf("O valor é 1\n"));
          case (2, printf("O valor é 2\n"));
          case (3, printf("O valor é 3\n"));
          default : printf("O valor desconhecido\n"); // Caso padrão
    );
    return 0;
}
