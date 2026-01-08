#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>

/**
 * Tipos para funções de cópia de strings definidas em <string.h>
 */
typedef enum
{
    CP_STRCPY,
    CP_STRNCPY
} COPIE_STRINGS;

/**
 * Estrutura para armazenar o resultado de uma operação de cópia de strings
 */
typedef struct
{
    const char *src;           // string fonte (original)
    char *dest;                // buffer destino (modificado)
    size_t dest_size;          // tamanho total do buffer destino (para segurança)
    size_t n;                  // número máximo de caracteres a copiar (usado apenas por strncpy)
    COPIE_STRINGS type; // tipo de cópia realizada
    char dest_before[64];      // conteúdo do destino ANTES da cópia (para demonstração)
} Resultado_Copia_String;

/**
 * @brief Retorna o nome da função de cópia correspondente ao tipo
 */
const char *get_copy_name(COPIE_STRINGS type)
{
    switch (type)
    {
    case CP_STRCPY:
        return "strcpy";

    case CP_STRNCPY:
        return "strncpy";

    default:
        return "Função Desconhecida";
    }
}

/**
 * @brief Realiza a cópia de uma string usando a função especificada e exibe o processo
 *
 * @param src String fonte
 * @param dest Buffer destino (deve ter espaço suficiente)
 * @param dest_size Tamanho total do buffer destino (incluindo o '\0')
 * @param n Número máximo de caracteres a copiar (usado apenas por strncpy)
 * @param type Tipo de função de cópia
 * @return Resultado_Copia_String Estrutura com informações da operação
 */
Resultado_Copia_String copy_strings(const char *src, char *dest, size_t dest_size, size_t n, COPIE_STRINGS type)
{
    Resultado_Copia_String res;

    res.src = src;
    res.dest = dest;
    res.dest_size = dest_size;
    res.n = n;
    res.type = type;

    // Salva o estado ANTES da cópia (máximo 63 caracteres + '\0' para exibição segura)
    strncpy(res.dest_before, dest, 63);
    res.dest_before[63] = '\0';

    printf("[%s] Copiando \"%s\" → buffer destino (tamanho %zu)\n", get_copy_name(type), src, dest_size);
    printf("Antes : \"%s\"\n", res.dest_before);

    // Executa a cópia conforme o tipo
    if (type == CP_STRCPY)
    {
        strcpy(dest, src); // Copia toda a string + '\0'
    }
    else if (type == CP_STRNCPY)
    {
        strncpy(dest, src, n);
        
        // Importante: strncpy NÃO garante o terminador nulo se n >= tamanho da fonte!
        if (n < dest_size && strlen(src) >= n)
        {
            dest[n] = '\0'; // Força o terminador nulo se necessário (boa prática)
        }
    }

    printf("Depois: \"%s\"\n\n", dest);

    return res;
}

int main(int argc, char **argv)
{
    printf("--- INICIANDO TESTES DE COPIA DE STRINGS ---\n\n");

    char buffer1[20] = "Conteúdo antigo";
    char buffer2[20] = {0};           // buffer zerado
    char buffer3[10] = "Texto longo"; // buffer pequeno
    char buffer4[15] = "";

    // 1. strcpy - cópia completa
    copy_strings("Brasil", buffer1, sizeof(buffer1), 0, CP_STRCPY);

    // 2. strcpy em buffer zerado
    copy_strings("Portugal", buffer2, sizeof(buffer2), 0, CP_STRCPY);

    // 3. strncpy - cópia limitada (copia apenas parte)
    copy_strings("Abacaxi", buffer3, sizeof(buffer3), 5, CP_STRNCPY);

    // 4. strncpy - cópia com n maior que a fonte (comportamento seguro)
    copy_strings("Olá", buffer4, sizeof(buffer4), 10, CP_STRNCPY);

    // 5. strncpy - cópia completa (n suficiente)
    char buffer5[20] = "Velho";
    copy_strings("Novo Mundo", buffer5, sizeof(buffer5), 20, CP_STRNCPY);

    return 0;
}
