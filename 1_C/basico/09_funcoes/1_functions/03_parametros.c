#include <stdio.h>
#include <ctype.h>
#include <string.h>

/**
 * PARÂMETROS: São valores que uma função recebe no momento em que é chamada.
 * Eles funcionam como “entradas” da função e permitem que ela execute operações
 * com base nos dados fornecidos.
 *
 * Os parâmetros são declarados na definição da função e recebem seus valores
 * através dos argumentos passados na chamada. Dentro da função, comportam-se
 * como variáveis locais.
 *
 * @note A ordem dos parâmetros é importante. Por convenção, recomenda-se:
 *       1. Primeiro os dados essenciais (inputs principais),
 *       2. Depois configurações, opções ou modificadores,
 *       3. E por último parâmetros de saída (ponteiros usados para retornar valores).
 *       Essa organização torna a função mais clara, evita erros e facilita sua utilização.
 *       4. Sempre verifique os parâmetros com if
 */

/**
 * @brief Imprime três valores de tipos diferentes.
 *
 * @param inteiro O inteiro a ser impresso.
 * @param letra O caractere a ser impresso.
 * @param real O ponto flutuante a ser impresso.
 */
void parametros(int inteiro, char letra, float real)
{
    printf("int: %d\tchar: %c\tfloat: %.2f\n", inteiro, letra, real);
}

/**
 * @brief Analisa uma string e conta vogais, consoantes, espaços, caracteres especiais e dígitos.
 *
 * @param str A string a ser analisada.
 */
void checaString(const char *str)
{
    if (str == NULL)
    {
        printf("Erro: string nula fornecida para análise.\n");
        return;
    }

    int v = 0, c = 0, esp = 0, esp_espec = 0, dig = 0;

    // Vogais em português (incluindo acentuadas mais comuns)
    const char *vogais = "aeiou";

    for (int i = 0; str[i]; i++)
    {
        char ch = str[i];

        if (isdigit(ch))
            dig++;
        else if (isspace(ch))
            esp++;
        else if (isalpha(ch))
        {
            // strrchr retorna != NULL se encontrar
            if (strrchr(vogais, ch))
                v++;
            else
                c++;
        }
        else
            esp_espec++;
    }

    printf("Vogais.............: %d\n", v);
    printf("Consoantes.........: %d\n", c);
    printf("Espaços............: %d\n", esp);
    printf("Caracteres especiais: %d\n", esp_espec);
    printf("Dígitos............: %d\n", dig);
}

/**
 * @brief Calcula (int)numero1 + (int)numero2 e aplica módulo por 'modulo'.
 *        Agora com nome correto, tratamento de erro e lógica clara.
 *
 * @param numero1 Primeiro número float.
 * @param numero2 Segundo número float.
 * @param modulo Valor usado no operador módulo (não pode ser zero).
 * @return int Resultado da operação ou -1 se módulo por zero.
 */
int calculaSomaTruncadaModulo(float numero1, float numero2, int modulo)
{
    if (modulo == 0)
    {
        printf("Erro: não é possível fazer módulo por zero!\n");
        return -1;
    }

    int soma = (int)numero1 + (int)numero2;
    int resultado = soma % modulo;

    printf("O resultado da expressão é: %d\n", resultado);
    return resultado;
}

int main(int argc, char **argv)
{
    // Chamada da função 'parametros' com valores das variáveis
    parametros(42, 'X', 3.14159f);
    printf("\n--------------------------------------\n");

    // Chamada da função 'parametros' com operações nos parâmetros
    parametros(42 - 1, 'G' - 7, 3.14159f + 0.3);
    printf("\n--------------------------------------\n");

    // Chamada da função 'parametros' com operações mais complexas nos parâmetros
    parametros(sizeof(int) - 1, 68 + 1, 3.14159f + 0.06);
    parametros(sizeof(char) - sizeof(int) + 4, 'l' - 32, 3.14159f + 10.06);

    // Tentativa de chamar a função com um número incorreto de argumentos (causará erro)
    // parametros(number - 1, 'm' - 7,  3.14159f + 0.3, number);
    // erro: too many arguments in function call

    printf("\n---------------------------------------\n");

    printf("\n=== Teste da função calculaSomaTruncadaModulo ===\n");
    calculaSomaTruncadaModulo(5.9, 3.2, 4);  // (5 + 3) % 4 = 8 % 4 = 0
    calculaSomaTruncadaModulo(10.7, 8.1, 5); // (10 + 8) % 5 = 18 % 5 = 3
    calculaSomaTruncadaModulo(1.1, 2.2, 0);  // Erro esperado

    printf("\n---------------------------------------\n");

    printf("\n=== Teste da função checaString ===\n");

    /** string que a função irá receber e checar */
    char frase[] = "Ola, mundo! 123 @#";
    checaString(frase);
    return 0;
}
