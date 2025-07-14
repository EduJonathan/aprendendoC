#include <stdio.h>
#include <inttypes.h>

// Neste código eu exibo as formatações de entradas(scanf) e saída(printf) de dados,
// de cada tipo pertencente a biblioteca inttypes.h ou stdint.h

/**
 * @brief Procedimento que realiza a leitura e impressão de variáveis do tipo int_t
 */
void inputAndOutputInt_t(void)
{
    int8_t formatterParaInt8 = 0;
    int16_t formatterParaInt16 = 0;
    int32_t formatterParaInt32 = 0;
    int64_t formatterParaInt64 = 0;

    printf("INSIRA UM VALOR PARA formatterParaInt8: ");
    scanf("%" SCNd8, &formatterParaInt8);
    printf("O VALOR DE formatterParaInt8: %" PRId8 "\n", formatterParaInt8);

    printf("\nINSIRA UM VALOR PARA formatterParaInt16: ");
    scanf("%" SCNd16, &formatterParaInt16);
    printf("O VALOR DE formatterParaInt16: %" PRId16 "\n", formatterParaInt16);

    printf("\nINSIRA UM VALOR PARA formatterParaInt32: ");
    scanf("%" SCNd32, &formatterParaInt32);
    printf("O VALOR DE formatterParaInt32: %" PRId32 "\n", formatterParaInt32);

    printf("\nINSIRA UM VALOR PARA formatterParaInt64: ");
    scanf("%" SCNd64, &formatterParaInt64);
    printf("O VALOR DE formatterParaInt64: %" PRId64 "\n", formatterParaInt64);
}

/**
 * @brief Procedimento que realiza a leitura e impressão de variáveis do tipo uint_t
 */
void inputAndOutputUint_t(void)
{
    uint8_t formatterParaUInt8 = 0;
    uint16_t formatterParaUInt16 = 0;
    uint32_t formatterParaUInt32 = 0;
    uint64_t formatterParaUInt64 = 0;

    printf("\nINSIRA UM VALOR PARA formatterParaUInt8: ");
    scanf("%" SCNu8, &formatterParaUInt8);
    printf("O VALOR DE formatterParaUInt8: %" PRIu8 "\n", formatterParaUInt8);

    printf("\nINSIRA UM VALOR PARA formatterParaUInt16: ");
    scanf("%" SCNu16, &formatterParaUInt16);
    printf("O VALOR DE formatterParaUInt16: %" PRIu16 "\n", formatterParaUInt16);

    printf("\nINSIRA UM VALOR PARA formatterParaUInt32: ");
    scanf("%" SCNu32, &formatterParaUInt32);
    printf("O VALOR DE formatterParaUInt32: %" PRIu32 "\n", formatterParaUInt32);

    printf("\nINSIRA UM VALOR PARA formatterParaUInt64: ");
    scanf("%" SCNu64, &formatterParaUInt64);
    printf("O VALOR DE formatterParaUInt64: %" PRIu64 "\n", formatterParaUInt64);
}

/**
 * @brief Procedimento que realiza a leitura e impressão de variáveis do tipo int_least_t
 */
void inputAndOutputInt_least_t(void)
{
    int_least8_t formatterParaIL8 = 0;
    int_least16_t formatterParaIL16 = 0;
    int_least32_t formatterParaIL32 = 0;
    int_least64_t formatterParaIL64 = 0;

    printf("\nINSIRA UM VALOR PARA formatterParaIL8: ");
    scanf("%" SCNdLEAST8, &formatterParaIL8);
    printf("O VALOR DE formatterParaIL8: %" PRIdLEAST8 "\n", formatterParaIL8);

    printf("\nINSIRA UM VALOR PARA formatterParaIL16: ");
    scanf("%" SCNdLEAST16, &formatterParaIL16);
    printf("O VALOR DE formatterParaIL16: %" PRIdLEAST16 "\n", formatterParaIL16);

    printf("\nINSIRA UM VALOR PARA formatterParaIL32: ");
    scanf("%" SCNdLEAST32, &formatterParaIL32);
    printf("O VALOR DE formatterParaIL32: %" PRIdLEAST32 "\n", formatterParaIL32);

    printf("\nINSIRA UM VALOR PARA formatterParaIL64: ");
    scanf("%" SCNdLEAST64, &formatterParaIL64);
    printf("O VALOR DE formatterParaIL64: %" PRIdLEAST64 "\n", formatterParaIL64);
}

/**
 * @brief Procedimento que realiza a leitura e impressão de variáveis do tipo uint_least_t
 */
void inputAndOutputUint_least_t(void)
{
    uint_least8_t formatterParaUIL8 = 0;
    uint_least16_t formatterParaUIL16 = 0;
    uint_least32_t formatterParaUIL32 = 0;
    uint_least64_t formatterParaUIL64 = 0;

    printf("\nINSIRA UM VALOR PARA formatterParaUIL8: ");
    scanf("%" SCNuLEAST8, &formatterParaUIL8);
    printf("O VALOR DE formatterParaUIL8: %" PRIuLEAST8 "\n", formatterParaUIL8);

    printf("\nINSIRA UM VALOR PARA formatterParaUIL16: ");
    scanf("%" SCNuLEAST16, &formatterParaUIL16);
    printf("O VALOR DE formatterParaUIL16: %" PRIuLEAST16 "\n", formatterParaUIL16);

    printf("\nINSIRA UM VALOR PARA formatterParaUIL32: ");
    scanf("%" SCNuLEAST32, &formatterParaUIL32);
    printf("O VALOR DE formatterParaUIL32: %" PRIuLEAST32 "\n", formatterParaUIL32);

    printf("\nINSIRA UM VALOR PARA formatterParaUIL64: ");
    scanf("%" SCNuLEAST64, &formatterParaUIL64);
    printf("O VALOR DE formatterParaUIL64: %" PRIuLEAST64 "\n", formatterParaUIL64);
}

/**
 * @brief Procedimento que realiza a leitura e impressão de variáveis do tipo int_fast_t
 */
void inputAndOutputInt_fast_t(void)
{
    int_fast8_t formatterParaIF8 = 0;
    int_fast16_t formatterParaIF16 = 0;
    int_fast32_t formatterParaIF32 = 0;
    int_fast64_t formatterParaIF64 = 0;

    printf("\nINSIRA UM VALOR PARA formatterParaIF8: ");
    scanf("%" SCNdFAST8, &formatterParaIF8);
    printf("O VALOR DE formatterParaIF8: %" PRIdFAST8 "\n", formatterParaIF8);

    printf("\nINSIRA UM VALOR PARA formatterParaIF16: ");
    scanf("%" SCNdFAST16, &formatterParaIF16);
    printf("O VALOR DE formatterParaIF16: %" PRIdFAST16 "\n", formatterParaIF16);

    printf("\nINSIRA UM VALOR PARA formatterParaIF32: ");
    scanf("%" SCNdFAST32, &formatterParaIF32);
    printf("O VALOR DE formatterParaIF32: %" PRIdFAST32 "\n", formatterParaIF32);

    printf("\nINSIRA UM VALOR PARA formatterParaIF64: ");
    scanf("%" SCNdFAST64, &formatterParaIF64);
    printf("O VALOR DE formatterParaIF64: %" PRIdFAST64 "\n", formatterParaIF64);
}

/**
 * @brief Procedimento que realiza a leitura e impressão de variáveis do tipo uint_fast_t
 */
void inputAndOutputUInt_fast_t(void)
{
    uint_fast8_t formatterParaUIF8 = 0;
    uint_fast16_t formatterParaUIF16 = 0;
    uint_fast32_t formatterParaUIF32 = 0;
    uint_fast64_t formatterParaUIF64 = 0;

    printf("\nINSIRA UM VALOR PARA formatterParaUIF8: ");
    scanf("%" SCNuFAST8, &formatterParaUIF8);
    printf("O VALOR DE formatterParaUIF8: %" PRIuFAST8 "\n", formatterParaUIF8);

    printf("\nINSIRA UM VALOR PARA formatterParaUIF16: ");
    scanf("%" SCNuFAST16, &formatterParaUIF16);
    printf("O VALOR DE formatterParaUIF16: %" PRIuFAST16 "\n", formatterParaUIF16);

    printf("\nINSIRA UM VALOR PARA formatterParaUIF32: ");
    scanf("%" SCNuFAST32, &formatterParaUIF32);
    printf("O VALOR DE formatterParaUIF32: %" PRIuFAST32 "\n", formatterParaUIF32);

    printf("\nINSIRA UM VALOR PARA formatterParaUIF64: ");
    scanf("%" SCNuFAST64, &formatterParaUIF64);
    printf("O VALOR DE formatterParaUIF64: %" PRIuFAST64 "\n", formatterParaUIF64);
}

int main(int argc, char **argv)
{
    printf("\n==========================================\n");
    printf("\n\t\t>>INT_T<<\n");

    inputAndOutputInt_t();

    printf("\n==========================================\n");
    printf("\n\t\t>>UINT_T<<\n");

    inputAndOutputUint_t();

    printf("\n==========================================\n");
    printf("\n\t\t>>INT_LEAST_T<<\n");

    inputAndOutputInt_least_t();

    printf("\n==========================================\n");
    printf("\n\t\t>>UINT_LEAST_T<<\n");

    inputAndOutputUint_least_t();

    printf("\n==========================================\n");
    printf("\n\t\t>>INT_FAST_T<<\n");

    inputAndOutputInt_fast_t();

    printf("\n==========================================\n");
    printf("\n\t\t>>UINT_FAST_T<<\n");

    inputAndOutputUInt_fast_t();
    return 0;
}
