#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <inttypes.h> // Para PRIu8 etc., se necessário
#include <string.h>

/**
 * Enum para identificar as funções de manipulação de memória
 */
typedef enum
{
    MEM_MEMCPY,
    MEM_MEMMOVE,
    MEM_MEMSET,
    MEM_MEMCMP
} MEMORIA_STRINGS;

/**
 * Estrutura para armazenar informações sobre uma operação de memória
 */
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
 * @brief Executa a operação de memória especificada e exibe o resultado de forma didática
 *
 * @param op Estrutura contendo os detalhes da operação de memória
 */
void executar_operacao_memoria(Operacao_Memoria op)
{
    printf("[%s] ", get_mem_name(op.type));

    switch (op.type)
    {
        case MEM_MEMCPY:
        case MEM_MEMMOVE:
        {
            const unsigned char *src_bytes = (const unsigned char *)op.src;
            printf("Copiando %zu bytes de src=[%02X %02X %02X ...] para dest\n", op.n,
                src_bytes[0], src_bytes[1], src_bytes[2] >= op.n ? 0 : src_bytes[2]);

            void *resultado = NULL;
            if (op.type == MEM_MEMCPY)
                resultado = memcpy(op.dest, op.src, op.n);
            else
                resultado = memmove(op.dest, op.src, op.n);

            unsigned char *dest_bytes = (unsigned char *)op.dest;
            printf("→ dest após operação = [%02X %02X %02X ...] (retorno: %p)\n",
                dest_bytes[0], dest_bytes[1], dest_bytes[2] >= op.n ? 0 : dest_bytes[2], resultado);
            break;
        }
        case MEM_MEMSET:
        {
            printf("Preenchendo %zu bytes de dest com valor %d (0x%02X)\n", op.n, op.fill_value, (unsigned char)op.fill_value);

            void *resultado = memset(op.dest, op.fill_value, op.n);

            unsigned char *dest_bytes = (unsigned char *)op.dest;
            printf("→ dest após operação = [%02X %02X %02X ...] (retorno: %p)\n",
                dest_bytes[0], dest_bytes[1], dest_bytes[2] >= op.n ? dest_bytes[0] : dest_bytes[2], resultado);
            break;
        }
        case MEM_MEMCMP:
        {
            const unsigned char *src_bytes = (const unsigned char *)op.src;
            const unsigned char *dest_bytes = (const unsigned char *)op.dest;

            printf("Comparando %zu bytes: dest=[%02X %02X %02X ...] vs src=[%02X %02X %02X ...]\n",
                op.n,
                dest_bytes[0], dest_bytes[1], dest_bytes[2] >= op.n ? 0 : dest_bytes[2],
                src_bytes[0], src_bytes[1], src_bytes[2] >= op.n ? 0 : src_bytes[2]);

            int resultado = memcmp(op.dest, op.src, op.n);
            printf("→ Resultado: %d (%s)\n", resultado, interpretar_memcmp(resultado));
            break;
        }
    }
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    printf("=== DEMONSTRAÇÃO DAS FUNÇÕES DE MANIPULAÇÃO DE MEMÓRIA ===\n\n");

    // Buffers para operações (grandes o suficiente para os testes)
    unsigned char buffer1[32] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF}; // inicializado com alguns valores
    unsigned char buffer2[32] = {0};
    unsigned char buffer_overlap[32] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const unsigned char fonte[] = {0x41, 0x42, 0x43, 0x44, 0x45}; // "ABCDE"

    // Testes de memcpy
    memset(buffer1, 0xFF, sizeof(buffer1)); // reset
    executar_operacao_memoria((Operacao_Memoria){
        .dest = buffer1,
        .dest_size = sizeof(buffer1),
        .src = fonte,
        .n = 5,
        .type = MEM_MEMCPY});

    // Testes de memmove (inclusive com overlap)
    executar_operacao_memoria((Operacao_Memoria){
        .dest = buffer_overlap + 2,
        .dest_size = sizeof(buffer_overlap) - 2,
        .src = buffer_overlap,
        .n = 6,
        .type = MEM_MEMMOVE}); // move 6 bytes para frente (overlap)

    // Testes de memset
    memset(buffer2, 0, sizeof(buffer2));

    executar_operacao_memoria((Operacao_Memoria){
        .dest = buffer2,
        .dest_size = sizeof(buffer2),
        .fill_value = 0x00,
        .n = 10,
        .type = MEM_MEMSET});

    executar_operacao_memoria((Operacao_Memoria){
        .dest = buffer2 + 10,
        .dest_size = sizeof(buffer2) - 10,
        .fill_value = 0xAA,
        .n = 8,
        .type = MEM_MEMSET});

    // Testes de memcmp
    unsigned char bloco1[] = {1, 2, 3, 4, 5};
    unsigned char bloco2[] = {1, 2, 3, 4, 5};
    unsigned char bloco3[] = {1, 2, 3, 0x10, 5};
    unsigned char bloco4[] = {1, 2, 0, 4, 5};

    executar_operacao_memoria((Operacao_Memoria){.dest = bloco1, .src = bloco2, .n = 5, .type = MEM_MEMCMP});
    executar_operacao_memoria((Operacao_Memoria){.dest = bloco1, .src = bloco3, .n = 5, .type = MEM_MEMCMP});
    executar_operacao_memoria((Operacao_Memoria){.dest = bloco1, .src = bloco4, .n = 5, .type = MEM_MEMCMP});

    printf("\n=== FIM DOS TESTES ===\n");
    return 0;
}
