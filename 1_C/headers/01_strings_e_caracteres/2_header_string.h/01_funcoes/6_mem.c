#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <inttypes.h> // Para PRIu8 etc., se necessário
#include <string.h>


// Enum para identificar as funções de manipulação de memória
typedef enum
{
    MEM_MEMCPY,
    MEM_MEMMOVE,
    MEM_MEMSET,
    MEM_MEMCMP
} MEMORIA_STRINGS;


// Estrutura para armazenar informações sobre uma operação de memória
typedef struct
{
    const void *dest_orig; // Ponteiro original do destino (para exibição)
    void *dest;            // Buffer de destino modificável
    size_t dest_size;      // Tamanho do buffer de destino
    const void *src;       // Fonte (para memcpy/memmove/memcmp)
    int fill_value;        // Valor de preenchimento (para memset)
    size_t n;              // Número de bytes a operar
    MEMORIA_STRINGS type;  // Tipo da função
} Operacao_Memoria;

/**
 * @brief Retorna o nome da função de memória como string
 * 
 * @param type O tipo de função de memória
 * @return const char* Nome da função
 */
const char *get_mem_name(MEMORIA_STRINGS type)
{
    switch (type)
    {
    case MEM_MEMCPY:
        return "memcpy";

    case MEM_MEMMOVE:
        return "memmove";

    case MEM_MEMSET:
        return "memset";

    case MEM_MEMCMP:
        return "memcmp";

    default:
        return "Função Desconhecida";
    }
}

/**
 * @brief Interpreta o resultado de memcmp
 *
 * @param res Resultado retornado por memcmp
 * @return Descrição didática do resultado
 */
const char *interpretar_memcmp(int res)
{
    if (res == 0)
        return "BLOCOS IGUAIS";

    if (res < 0)
        return "PRIMEIRO BLOCO VEM ANTES (MENOR)";

    return "PRIMEIRO BLOCO VEM DEPOIS (MAIOR)";
}

/**
 * @brief Executa a operação de memória e imprime os resultados
 *
 * @param op Estrutura contendo os parâmetros da operação
 * @param len Número de bytes a operar
 * @param max_mostrar Número máximo de bytes a mostrar na saída
 */
static void print_primeiros_bytes(const void *ptr, size_t len, size_t max_mostrar)
{
    const unsigned char *p = (const unsigned char *)ptr;
    size_t mostrar = len < max_mostrar ? len : max_mostrar;

    printf("[");
    
    for (size_t i = 0; i < mostrar; i++)
    {
        printf("%02X", p[i]);
        if (i < mostrar - 1)
            printf(" ");
    }

    if (len > max_mostrar)
        printf(" ...");
    printf("]");
}

/**
 * @brief Imprime os primeiros bytes de um bloco de memória em formato hexadecimal
 *
 * @param dest Ponteiro para o bloco de memória
 * @param dest_size Número máximo de bytes a imprimir
 * @param src Nome do bloco (para exibição)
 * @param n Número de bytes a imprimir
 * @param fill_value Valor de preenchimento (para memset)
 * @param type Tipo da função de memória
 */
void demonstrar_memoria(void *dest, size_t dest_size, const void *src, size_t n, int fill_value, MEMORIA_STRINGS type)
{
    if (n > dest_size && (type == MEM_MEMCPY || type == MEM_MEMMOVE || type == MEM_MEMSET))
    {
        printf("[ERRO] Tentativa de escrever %zu bytes em buffer de %zu bytes → operação abortada\n\n", n, dest_size);
        return;
    }

    printf("[%s]  ", get_mem_name(type));

    switch (type)
    {
    case MEM_MEMCPY:
    case MEM_MEMMOVE:
    {
        printf("copiando %zu bytes  ", n);
        print_primeiros_bytes(src, n, 5);
        printf(" → ");

        void *ret = (type == MEM_MEMCPY) ? memcpy(dest, src, n) : memmove(dest, src, n);
        print_primeiros_bytes(dest, n, 5);
        printf("  (retorno = %p)\n\n", (void *)ret);
        break;
    }

    case MEM_MEMSET:
    {
        printf("preenchendo %zu bytes com 0x%02X  →  ", n, (unsigned char)fill_value);
        void *ret = memset(dest, fill_value, n);
        print_primeiros_bytes(dest, n, 5);
        printf("  (retorno = %p)\n\n", (void *)ret);
        break;
    }

    case MEM_MEMCMP:
    {
        printf("comparando %zu bytes:  ", n);
        print_primeiros_bytes(dest, n, 5);
        printf(" vs ");
        print_primeiros_bytes(src, n, 5);
        printf("  →  ");

        int res = memcmp(dest, src, n);
        printf("%d  (%s)\n\n", res, interpretar_memcmp(res));
        break;
    }
    }
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");

    printf("=== DEMONSTRAÇÃO: memcpy / memmove / memset / memcmp ===\n\n");

    // Buffers de teste
    unsigned char buf_a[32];
    unsigned char buf_b[32];
    unsigned char buf_overlap[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16}; // Para teste de overlap
    const unsigned char fonte[] = {0x41, 0x42, 0x43, 0x44, 0x45, 0x46};                      // ABCDEF

    printf("1. memcpy e memmove\n");
    printf("-------------------------------\n");

    memset(buf_a, 0xFF, sizeof(buf_a)); // limpa com valor chamativo

    demonstrar_memoria(buf_a, sizeof(buf_a), fonte, 6, 0, MEM_MEMCPY);

    // Exemplo clássico de overlap (só memmove é seguro)
    printf("   → teste de sobreposição (shift left 3 posições):\n");
    print_primeiros_bytes(buf_overlap, sizeof(buf_overlap), 12);
    printf("  →  ");
    demonstrar_memoria(buf_overlap + 3, sizeof(buf_overlap) - 3, buf_overlap, 10, 0, MEM_MEMMOVE);
    // Note: memcpy aqui causaria comportamento indefinido

    printf("2. memset\n");
    printf("-------------------------------\n");

    demonstrar_memoria(buf_b, sizeof(buf_b), NULL, 12, 0x00, MEM_MEMSET);
    demonstrar_memoria(buf_b + 12, sizeof(buf_b) - 12, NULL, 8, 0xAA, MEM_MEMSET);

    printf("3. memcmp\n");
    printf("-------------------------------\n");

    unsigned char a[] = {1, 2, 3, 4, 5};
    unsigned char b[] = {1, 2, 3, 4, 5};
    unsigned char c[] = {1, 2, 3, 0x10, 5};
    unsigned char d[] = {1, 2, 0x00, 4, 5};
    unsigned char e[] = {1, 2, 3, 4};

    demonstrar_memoria(a, sizeof(a), b, 5, 0, MEM_MEMCMP); // igual
    demonstrar_memoria(a, sizeof(a), c, 5, 0, MEM_MEMCMP); // a < c
    demonstrar_memoria(a, sizeof(a), d, 5, 0, MEM_MEMCMP); // a > d
    demonstrar_memoria(a, sizeof(a), e, 4, 0, MEM_MEMCMP); // prefixo igual

    printf("\nObservações importantes:\n");
    printf("• memcpy  → não garante comportamento correto com regiões sobrepostas\n");
    printf("• memmove → seguro para regiões sobrepostas (cópia temporária interna)\n");
    printf("• memset  → preenche bytes (não valores multi-byte)\n");
    printf("• memcmp  → compara bytes crus (ordem lexicográfica de bytes)\n");
    printf("• Sempre verifique que n ≤ tamanho do buffer destino!\n");
}
