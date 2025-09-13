#include <stdio.h>

/**
 * @brief Estrutura com campos de bits para validação de largura e altura.
 *
 * Esta estrutura utiliza campos de bits para armazenar informações de validação
 * de largura e altura.
 */
typedef struct campo1
{
    unsigned int widthValidated : 1;  /**< Indica se a largura foi validada */
    unsigned int heightValidated : 1; /**< Indica se a altura foi validada */
} status1;

/**
 * @brief Estrutura com campos de bits para validação de largura e altura.
 *
 * Esta estrutura tem a mesma definição que `status1`. Utiliza campos de bits
 * para armazenar informações de validação de largura e altura.
 */
typedef struct campo2
{
    unsigned int widthValidated : 1;  /**< Indica se a largura foi validada */
    unsigned int heightValidated : 1; /**< Indica se a altura foi validada */
} status2;

/**
 * @brief Estrutura com um campo de bits para armazenar a idade.
 *
 * Esta estrutura usa um campo de bits de 3 bits para armazenar um valor
 * numérico que pode variar de 0 a 7.
 */
typedef struct campo3
{
    unsigned int idade : 3; /**< Idade armazenada em 3 bits (0 a 7) */
} age;

int main(int argc, char **argv)
{
    // Exibe o tamanho da estrutura com campos de bits para validação
    printf("Memória ocupada por status1 : %zu bytes\n", sizeof(status1));
    printf("Memória ocupada por status2 : %zu bytes\n", sizeof(status2));

    // Cria uma instância da estrutura com campo de bits para idade
    age Idade = {0};

    // Atribui e exibe a idade dentro do intervalo permitido
    Idade.idade = 4;
    printf("Sizeof(Idade) : %zu bytes\n", sizeof(Idade));
    printf("Idade.idade : %d\n", Idade.idade);

    // Atribui um valor máximo permitido
    Idade.idade = 7;
    printf("Idade.idade : %d\n", Idade.idade);

    // Atribui um valor fora do intervalo permitido
    // 8 em binário é 1000; somente os 3 bits menos significativos são armazenados
    Idade.idade = 8;
    printf("Idade.idade : %d\n", Idade.idade); // Será 0
    return 0;
}
