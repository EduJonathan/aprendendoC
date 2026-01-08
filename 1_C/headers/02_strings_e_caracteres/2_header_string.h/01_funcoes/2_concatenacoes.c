#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/**
 * Enum para identificar as funções de concatenação
 */
typedef enum
{
    CNT_STRCAT,
    CNT_STRNCAT
} CONCATENE_STRINGS;

/**
 * Estrutura para armazenar informações sobre uma operação de concatenação
 */
typedef struct
{
    const char *s1;            // String destino original (antes da cópia)
    const char *s2;            // String a ser anexada
    size_t n;                  // Quantidade máxima de caracteres (usado apenas em strncat)
    CONCATENE_STRINGS type; // Tipo de função utilizada
    char resultado[256];       // Buffer para armazenar a string concatenada
} Resultado_Concatenacao;

/**
 * Retorna o nome da função de concatenação
 *
 * @param type Tipo da função de concatenação
 * @return Nome da função como string
 */
const char *get_concat_name(CONCATENE_STRINGS type)
{
    switch (type)
    {
    case CNT_STRCAT:
        return "strcat";

    case CNT_STRNCAT:
        return "strncat";

    default:
        return "Função Desconhecida";
    }
}

/**
 * Realiza a concatenação usando a função especificada e armazena o resultado na estrutura
 *
 * @param res Ponteiro para a estrutura Resultado_Concatenacao contendo os dados da operação
 */
void concatenar_strings(Resultado_Concatenacao *res)
{
    // Copia s1 para o buffer de resultado (necessário porque strcat/strncat modificam o destino)
    strcpy(res->resultado, res->s1);

    printf("[%s] ", get_concat_name(res->type));

    if (res->type == CNT_STRCAT)
    {
        strcat(res->resultado, res->s2);
        printf("\"%s\" + \"%s\" → \"%s\"\n", res->s1, res->s2, res->resultado);
    }
    else
    {
        strncat(res->resultado, res->s2, res->n);
        printf("\"%s\" + \"%s\" (máx %zu chars) → \"%s\"\n", res->s1, res->s2, res->n, res->resultado);
    }
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");

    printf("=== DEMONSTRAÇÃO DE strcat E strncat ===\n\n");

    Resultado_Concatenacao testes[] = {
        {"Olá, ", "mundo!", 0, CNT_STRCAT},                // strcat completo
        {"Bom ", "dia!", 0, CNT_STRCAT},                   // strcat completo
        {"ABC", "DEFGHI", 3, CNT_STRNCAT},                 // só anexa "DEF"
        {"Teste", "123456789", 5, CNT_STRNCAT},            // anexa "12345"
        {"Seguro", " com limite longo", 100, CNT_STRNCAT}, // limite maior que s2 → comportamento igual a strcat
        {"", "vazio + algo", 0, CNT_STRCAT},               // string vazia como destino
    };

    // Calcular o número de testes
    size_t num_testes = sizeof(testes) / sizeof(testes[0]);

    for (size_t i = 0; i < num_testes; i++)
    {
        concatenar_strings(&testes[i]);
    }

    printf("\nObservações importantes:\n");
    printf("- strcat() anexa TODA a string s2 (cuidado com buffer overflow!)\n");
    printf("- strncat() anexa no MÁXIMO 'n' caracteres de s2 + adiciona '\\0' automaticamente\n");
    printf("- Sempre garanta que o buffer destino tenha espaço suficiente!\n");

    return 0;
}
