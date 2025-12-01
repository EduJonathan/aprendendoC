#include <stdio.h>

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
 */

/**
 * @brief Procedimento que recebe três parâmetros (inteiro, caractere e ponto flutuante)
 * e os imprime
 *
 * @param inteiro O inteiro a ser impresso.
 * @param letra O caractere a ser impresso.
 * @param real O ponto flutuante a ser impresso.
 */
void parametros(int inteiro, char letra, float real)
{
    printf("int: %d\tchar: %c\tfloat: %f\n", inteiro, letra, real);
}

/**
 * @brief Contabiliza e imprime a quantidade de vogais, consoantes, espaços,
 *        caracteres especiais e dígitos em uma string.
 *
 * @param string A string a ser contabilizada.
 */
void checaString(char *string)
{
    int qntdVogal = 0,
        qntdConsoante = 0,
        qntdEspaco = 0,
        qntdCaracteresEspeciais = 0,
        qntdDigito = 0;

    for (int i = 0; string[i] != '\0'; i++)
    {
        char c = string[i];

        // Verificar se é um dígito
        if (c >= '0' && c <= '9')
        {
            qntdDigito++;
        }
        // Verificar se é um espaço
        else if (c == ' ')
        {
            qntdEspaco++;
        }
        // Verificar se é uma vogal (maiúscula ou minúscula)
        else if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                 c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        {
            qntdVogal++;
        }
        // Verificar se é uma consoante
        else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            qntdConsoante++;
        }
        // Caso contrário, é um caractere especial
        else
        {
            qntdCaracteresEspeciais++;
        }
    }

    // Imprimir os resultados
    printf("Vogais: %d\n", qntdVogal);
    printf("Consoantes: %d\n", qntdConsoante);
    printf("Espaços: %d\n", qntdEspaco);
    printf("Caracteres especiais: %d\n", qntdCaracteresEspeciais);
    printf("Dígitos: %d\n", qntdDigito);
}

/**
 * @brief Calcula e retorna um valor inteiro baseado na operação entre dois números de ponto
 * flutuante.
 *
 * Esta função converte dois números de ponto flutuante para inteiros, calcula a soma
 * desses inteiros, e então aplica o operador módulo com o valor do parâmetro `resultado`.
 * O valor final é retornado pela função, será por um parâmetro.
 *
 * @param numero1 Valor do primeiro número a ser convertido e somado (do tipo float).
 * @param numero2 Valor do segundo número a ser convertido e somado (do tipo float).
 * @param resultado Valor utilizado como divisor na operação módulo.
 * @return retorna O resultado da operação ((int)numero1 + (int)numero2) % resultado.
 */
int retornandoUmParametro(float numero1, float numero2, int resultado)
{
    // Converte os números de ponto flutuante para inteiros e calcula a soma
    // Em seguida, aplica o operador módulo com o valor de `resultado`
    resultado = ((int)numero1 + (int)numero2) % resultado;

    // Imprime o resultado da operação
    printf("O resultado da expressão é: %d\n", resultado);

    // Retorna o resultado da operação
    return resultado;
}

int main(int argc, char **argv)
{
    // Declaração e inicialização de variáveis
    int number = 1;
    char letra = 'a';
    float pi = 3.14;

    // Chamada da função 'parametros' com valores das variáveis
    parametros(number, letra, pi);
    printf("\n--------------------------------------\n");

    // Chamada da função 'parametros' com operações nos parâmetros
    parametros(number - 1, letra - 7, pi + 0.3);
    printf("\n--------------------------------------\n");

    // Chamada da função 'parametros' com operações mais complexas nos parâmetros
    parametros(sizeof(number) - 1, letra + 1, pi + 0.06);
    parametros(sizeof(number) - sizeof(int) + 4, letra - 32, pi + 10.06);

    // Tentativa de chamar a função com um número incorreto de argumentos (causará erro)
    // parametros(number - 1, letra - 7, pi + 0.3, number);
    // erro: too many arguments in function call

    printf("\n---------------------------------------\n");

    // Inicialização dos valores
    float n1 = 7.0F;
    float n2 = 7.0F;
    int result = 4;

    // Chama a função e armazena o valor retornado
    int resultado = retornandoUmParametro(n1, n2, result);

    // Imprime o resultado retornado pela função
    printf("O resultado é : %d\n", resultado);

    printf("\n---------------------------------------\n");

    /** string que a função irá receber e checar */
    char *frase = "Ola, tudo bem? programador 1";
    checaString(frase);
    return 0;
}
