#include <stdio.h>
#include <stdbool.h>
#include <math.h> /* Arquivo cabeçalho que fornece funções matemáticas */

/* Este programa exibe diversos tipos de retornos para cada função */

/**
 * @brief Função que retorna void
 *
 * Procedimento que realiza apenas uma instrução de printf para exibir uma mensagem
 *
 * @return void
 */
void return_void(void)
{
    printf("\n\t===> RETORNOS DE FUNÇÃO <===\n");
    return; // Retorno sem valor (void)
}

/**
 * @brief Função que retorna um valor inteiro (int)
 *
 * Função que retorna um valor inteiro do resultado de uma soma
 *
 * @return da soma de dois inteiros
 */
int return_int(void)
{
    int n1 = 45, n2 = 23;
    int result = n1 + n2;
    printf(" RESULTADO: %d\n", result);
    return result; // Retorna um valor inteiro do resultado de uma soma
}

/**
 * @brief Função que retorna um valor em ponto flutuante (float)
 *
 * Função que retorna um valor aproximado de um ponto flutuante
 *
 * @return retorno de um valor aproximado
 */
float return_float(void)
{
    float valorAprox = ceilf(0.78F);
    // ceilf(): Fornecido por math.h, retorna o menor valor aproximado

    printf(" VALOR APROXIMADO: %f\n", valorAprox);
    return valorAprox; // Retorna um valor em ponto flutuante
}

/**
 * @brief Função que retorna um valor em ponto flutuante (double)
 *
 * Função que retorna a potência de um ponto flutuante
 *
 * @return retorno da potência de um ponto flutuante
 */
double return_double(void)
{
    double power = pow(5.0, 2.0);
    // pow(): Fornecido por math.h, retorna o valor de potenciação

    printf(" POTENCIAÇÃO: %lf\n", power);
    return power; // Retorna um valor em ponto flutuante double
}

/**
 * @brief Função que retorna um valor booleano (bool)
 *
 * Função que retorna um valor booleano
 *
 * @return uma variável booleana
 */
bool return_bool(void)
{
    bool condicao = (4 != 56) && (6 == 7);
    printf(" VERDADEIRO OU FALSO? %d\n", condicao);
    return condicao; // Retorna um valor booleano
}

/**
 * @brief Função que retorna um ponteiro para (char)
 *
 * Função que retorna um ponteiro para char
 *
 * @return Um ponteiro para char
 */
char *return_pointer(void)
{
    char n = 95;
    char *retorno = &n;
    printf(" RETORNO: ASCII: '%c' DECIMAL: %d\n", *retorno, *retorno);
    return retorno; // Retorna um ponteiro para char.
}

/**
 * @brief Função que retorna uma string
 *
 * @return Uma cadeia de caractere
 */
const char *return_str(void)
{
    const char *str = "RETORNO da função return_str";
    printf(" %s\n", str);
    return str; // Retorna uma cadeia de caractere
}

/**
 * @brief Função que retorna um ponteiro genérico (void *)
 *
 * @return Um ponteiro genérico
 */
void *return_v(void)
{
    int valor = 45;
    void *returnVoid = &valor;
    printf(" RETORNO DE *returnVoid: %d\n", *(int *)returnVoid);
    return returnVoid; // Retorna um ponteiro genérico (void *)
}

/**
 * @brief Função que retorna um valor do tipo size_t
 *
 * @return Um valor do tipo size_t
 */
size_t return_sizet(void)
{
    size_t tamanho = sizeof(int);
    printf(" TAMANHO EM BYTES DE UM INT: %zu\n", tamanho);
    return tamanho; // Retorna um valor do tipo size_t
}

/**
 * @brief Função que retorna um ponteiro estático para char
 *
 * @return Um ponteiro estático para char
 */
static char *return_static_pointer(void)
{
    static char n = 90; // Variável estática para persistência após o retorno
    printf(" RETORNO: ASCII: '%c' DECIMAL: %d\n", n, n);
    return &n; // Retornando a referência de uma variável estática
}

/**
 * @brief Função que retorna um valor do tipo signed long
 *
 * @return Um valor do tipo signed long
 */
signed long return_signed_long(void)
{
    signed long result = -123456789L;
    printf(" SIGNED LONG: %ld\n", result);
    return result; // Retorna um valor do tipo signed long
}

/**
 * @brief Função que retorna um valor do tipo unsigned long
 *
 * @return Um valor do tipo unsigned long
 */
unsigned long return_unsigned_long(void)
{
    unsigned long result = 987654321UL;
    printf(" UNSIGNED LONG: %lu\n", result);
    return result; // Retorna um valor do tipo unsigned long
}

/// @brief Chamando cada função na principal (main)
int main(int argc, char **argv)
{
    return_void();           /// OUTPUT: ===> RETORNOS DE FUNÇÃO <===
    return_int();            /// OUTPUT: RESULTADO: 68
    return_float();          /// OUTPUT: VALOR APROXIMADO: 1.000000
    return_double();         /// OUTPUT: POTENCIAÇÃO: 25.000000
    return_bool();           /// OUTPUT: VERDADEIRO OU FALSO? 0
    return_pointer();        /// OUTPUT: RETORNO: ASCII: '_' DECIMAL: 95
    return_static_pointer(); /// OUTPUT: RETORNO: ASCII: 'Z' DECIMAL: 90
    return_str();            /// OUTPUT: RETORNO da função return_str
    return_v();              /// OUTPUT: RETORNO de *returnVoid: 45
    return_sizet();          /// OUTPUT: TAMANHO EM BYTES DE UM INT: 4
    return_signed_long();    /// OUTPUT: SIGNED LONG: -123456789
    return_unsigned_long();  /// OUTPUT: UNSIGNED LONG: 987654321
    return 0;
}
