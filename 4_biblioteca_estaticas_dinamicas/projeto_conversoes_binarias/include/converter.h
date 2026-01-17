#ifndef CONVERTER_H
#define CONVERTER_H

// Enum para identificar as bases com clareza
typedef enum
{
    BASE_BIN = 2,
    BASE_OCT = 8,
    BASE_DEC = 10,
    BASE_HEX = 16
} BaseType;

// Struct para acoplamento dos dados da conversão
typedef struct
{
    char *output;      // String alocada dinamicamente com o resultado
    BaseType base;     // Base final
    unsigned int size; // Tamanho da string (sem '\0')
} ConversionResult;

/**
 * @brief Cria uma conversão de um número decimal para a base alvo especificada.
 *
 * @param decimal Número decimal a ser convertido.
 * @param target Base alvo para a conversão.
 *
 * @return Ponteiro para ConversionResult ou NULL em erro.
 */
ConversionResult *create_conversion(long decimal, BaseType target);

/**
 * @brief Libera a memória alocada para uma ConversionResult.
 *
 * @param res Ponteiro para a ConversionResult a ser liberada.
 */
void free_conversion(ConversionResult *res);

#endif
