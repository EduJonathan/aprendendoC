#include <stdio.h>
#include <locale.h>
#include <string.h>

// Tipos para funções de cópia de strings definidas em <string.h>
typedef enum
{
    COPY_STRCPY,
    COPY_STRNCPY
} COPIE_STRINGS;

// Estrutura para armazenar o resultado de uma operação de cópia de strings
typedef struct
{
    const char *src;      // string fonte (original)
    char *dest;           // buffer destino (modificado)
    size_t dest_size;     // tamanho total do buffer destino (para segurança)
    size_t n;             // número máximo de caracteres a copiar (strncpy)
    COPIE_STRINGS type;   // tipo de cópia realizada
    char dest_before[64]; // conteúdo do destino ANTES da cópia (para exibição)
} Resultado_Copia_String;

/**
 * @brief Retorna o nome da função de cópia correspondente ao tipo
 *
 * @param type Tipo da função de cópia
 * @return const char* Nome da função como string
 */
const char *get_copy_name(COPIE_STRINGS type)
{
    switch (type)
    {
    case COPY_STRCPY:
        return "strcpy";

    case COPY_STRNCPY:
        return "strncpy";

    default:
        return "Função Desconhecida";
    }
}

/**
 * @brief Realiza a cópia de strings e imprime o resultado de forma clara
 *
 * @param src String fonte (original)
 * @param dest Buffer destino (onde a string será copiada)
 * @param dest_size Tamanho total do buffer destino (para segurança)
 * @param n Número máximo de caracteres a copiar (usado apenas em strncpy)
 * @param type Tipo de função de cópia a ser utilizada
 */
void copy_strings(const char *src, char *dest, size_t dest_size, size_t n, COPIE_STRINGS type)
{
    Resultado_Copia_String resultado =
    {
        .src = src,
        .dest = dest,
        .dest_size = dest_size,
        .n = n,
        .type = type,
        .dest_before = {0}
    };

    if (src == NULL || dest == NULL || dest_size == 0)
    {
        printf("Parâmetros inválidos.\n");
        return;
    }

    // Salva estado anterior (máx 63 chars para exibição segura)
    strncpy(resultado.dest_before, dest, 63);
    resultado.dest_before[63] = '\0';

    printf("[%s] Copiando \"%s\" → buffer (tamanho %zu bytes)\n", get_copy_name(type), src, dest_size);
    printf("Antes : \"%s\"\n", resultado.dest_before);

    // Verificação básica de espaço (apenas aviso)
    size_t src_len = strlen(src);
    if (type == COPY_STRCPY && src_len + 1 > dest_size)
    {
        printf("AVISO: strcpy pode causar buffer overflow! (precisa de %zu bytes)\n", src_len + 1);
    }
    else if (type == COPY_STRNCPY && n + 1 > dest_size)
    {
        printf("AVISO: strncpy com n=%zu pode causar problemas (buffer tem %zu bytes)\n", n, dest_size);
    }

    if (type == COPY_STRCPY)
    {
        strcpy(dest, src); // CUIDADO: sem verificação de tamanho!
    }
    else
    {
        // COPY_STRNCPY
        strncpy(dest, src, n);

        // Garantir terminador nulo (regra importante do strncpy)
        if (n < dest_size)
        {
            dest[n] = '\0';
        }
        else
        {
            // n >= dest_size → buffer ficará sem \0 garantido → perigoso!
            printf("AVISO CRÍTICO: n >= tamanho do buffer → sem terminador nulo garantido!\n");
            dest[dest_size - 1] = '\0'; // Força \0 no último byte (perde dados)
        }
    }

    printf("Depois: \"%s\"\n\n", dest);
}

int main(int argc, char **argv)
{
    printf("--- INICIANDO TESTES DE COPIA DE STRINGS ---\n\n");

    char buffer1[20] = "Conteúdo antigo";
    char buffer2[20] = {0};
    char buffer3[10] = "Texto longo"; // pequeno → risco com strings longas
    char buffer4[15] = "";
    char buffer5[20] = "Velho";

    copy_strings("Brasil",     buffer1, sizeof(buffer1), 0,  COPY_STRCPY);
    copy_strings("Portugal",   buffer2, sizeof(buffer2), 0,  COPY_STRCPY);
    copy_strings("Abacaxi",    buffer3, sizeof(buffer3), 5,  COPY_STRNCPY); // copia "Abaca" + \0
    copy_strings("Olá mundo!", buffer4, sizeof(buffer4), 10, COPY_STRNCPY); // "Olá mundo" sem ! + \0
    copy_strings("Novo Mundo", buffer5, sizeof(buffer5), 20, COPY_STRNCPY); // copia tudo + \0

    // Exemplo perigoso (apenas para ilustrar)
    // char pequeno[5] = "oi";
    // copy_strings("12345678", pequeno, sizeof(pequeno), 8, CP_STRNCPY);
    return 0;
}
