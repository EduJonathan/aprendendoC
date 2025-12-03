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
 * @brief Contabiliza e imprime vogais, consoantes, espaços, dígitos e caracteres especiais.
 *        Agora com suporte a acentos e todos os tipos de espaço (espaço, tab, etc.).
 *
 * @param string String a ser analisada (não será modificada).
 */
void checaString(const char *string)
{
    int qntdVogal = 0;
    int qntdConsoante = 0;
    int qntdEspaco = 0;
    int qntdCaracteresEspeciais = 0;
    int qntdDigito = 0;

    for (int i = 0; string[i] != '\0'; i++)
    {
        char c = string[i];
        char lower = tolower(c); // Converte para minúscula para facilitar comparação

        if (isdigit(c))
        {
            qntdDigito++;
        }
        else if (isspace(c)) // Inclui espaço, tab, \n, etc.
        {
            qntdEspaco++;
        }
        else if (isalpha(c)) // É uma letra (inclui acentos em locale pt_BR)
        {
            // Vogais (incluindo acentuadas comuns em português)
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u')
            {
                qntdVogal++;
            }
            else
            {
                qntdConsoante++;
            }
        }
        else
        {
            qntdCaracteresEspeciais++;
        }
    }

    printf("Vogais: %d\n", qntdVogal);
    printf("Consoantes: %d\n", qntdConsoante);
    printf("Espaços: %d\n", qntdEspaco);
    printf("Caracteres especiais: %d\n", qntdCaracteresEspeciais);
    printf("Dígitos: %d\n", qntdDigito);
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
