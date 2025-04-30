#include <stdio.h>
#include <string.h>

/**
 * @brief Função para concatenar duas strings.
 *
 * Esta função recebe duas strings e as concatena, armazenando o resultado em uma terceira string.
 *
 * @param a String de entrada que será concatenada.
 * @param b String de entrada que será concatenada.
 * @param resultado String que receberá o resultado da concatenação.
 */
void concatenar(char *a, char *b, char *resultado)
{
    strcpy(resultado, a); /**< Copia a string 'a' para 'resultado' */
    strcat(resultado, b); /**< Concatena a string 'b' ao 'resultado' */
}

/**
 * @brief Função para comparar duas strings.
 *
 * Esta função compara duas strings e retorna um valor indicando se são iguais, 
 * ou qual vem primeiro lexicograficamente.
 *
 * @param a Primeira string a ser comparada.
 * @param b Segunda string a ser comparada.
 * @return Retorna 0 se as strings são iguais, um valor negativo se 'a' for menor que 'b',
 * ou um valor positivo se 'a' for maior que 'b'.
 */
int comparar(char *a, char *b)
{
    return strcmp(a, b); /**< Retorna o resultado da comparação das duas strings */
}

/**
 * @brief Função para inverter uma string.
 *
 * Esta função inverte uma string e armazena o resultado em uma string de saída.
 *
 * @param a String de entrada a ser invertida.
 * @param resultado String onde o resultado da inversão será armazenado.
 */
void inverter(char *a, char *resultado)
{
    int i, len = strlen(a);
    for (i = 0; i < len; i++)
    {
        resultado[i] = a[len - i - 1]; /**< Inverte a string */
    }
    resultado[len] = '\0'; /**< Adiciona o terminador nulo ao final da string invertida */
}

/**
 * @brief Função para contar o número de caracteres em uma string.
 *
 * Esta função conta o número de caracteres (não contando o terminador nulo) de uma string.
 *
 * @param a String cuja quantidade de caracteres será contada.
 * @return Retorna o número de caracteres presentes na string.
 */
int contarCaracteres(char *a)
{
    return strlen(a); /**< Retorna o número de caracteres na string */
}

/**
 * @brief Função que recebe um ponteiro para função (callback) e aplica a operação.
 *
 * Esta função executa uma operação em duas strings, dependendo do ponteiro para função fornecido.
 *
 * @param operacao Ponteiro para a função de operação a ser aplicada nas strings.
 * @param a Primeira string de entrada.
 * @param b Segunda string de entrada.
 * @param resultado String onde o resultado da operação será armazenado.
 */
void aplicarOperacao(void (*operacao)(char *, char *, char *), char *a, char *b, char *resultado)
{
    operacao(a, b, resultado); /**< Chama a função recebida como ponteiro */
}

/**
 * @brief Função que seleciona a operação a ser realizada com base na escolha do usuário.
 *
 * Esta função retorna um ponteiro para a função correspondente à operação escolhida pelo usuário.
 *
 * @param escolha Número que indica a operação desejada.
 * @return Retorna o ponteiro para a função de operação correspondente ou NULL se a opção for inválida.
 */
void (*selecionarOperacao(int escolha))(char *, char *, char *)
{
    switch (escolha)
    {
    case 1:
        return (void (*)(char *, char *, char *))concatenar;

    case 2:
        return (void (*)(char *, char *, char *))comparar;

    case 3:
        return (void (*)(char *, char *, char *))inverter;

    case 4:
        return (void (*)(char *, char *, char *))contarCaracteres;

    default:
        printf("Opção inválida!\n");
        return NULL; /**< Retorna NULL caso a opção seja inválida */
    }
}

int main(int argc, char **argv)
{
    int escolha = 0;
    char a[100] = "Hello";
    char b[100] = " Mundo!";
    char resultado[200]; /**< String para armazenar os resultados */

    printf("Escolha uma operação:\n");
    printf("1. Concatenar\n2. Comparar\n3. Inverter\n4. Contar Caracteres: ");
    scanf("%d", &escolha);

    // Usando ponteiro para função para aplicar operação
    void (*operacaoSelecionada)(char *, char *, char *) = selecionarOperacao(escolha);

    if (operacaoSelecionada != NULL)
    {
        if (escolha == 2)
        {
            // Para comparação, o resultado é um valor inteiro, não uma string
            int resultadoComparacao = comparar(a, b);
            if (resultadoComparacao == 0)
            {
                printf("As strings são iguais.\n");
            }
            else if (resultadoComparacao < 0)
            {
                printf("A string '%s' vem antes de '%s'.\n", a, b);
            }
            else
            {
                printf("A string '%s' vem depois de '%s'.\n", a, b);
            }
        }
        else if (escolha == 4)
        {
            // Para contar caracteres, o resultado é um número inteiro
            printf("Número de caracteres: %d\n", contarCaracteres(a));
        }
        else
        {
            // Para as outras operações, o resultado é uma string
            operacaoSelecionada(a, b, resultado);
            printf("Resultado da operação selecionada: %s\n", resultado);
        }
    }
    return 0;
}
