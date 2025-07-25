#include <stdio.h>

/**
 * STRUCT: ou estrutura é um recurso da linguagem C (e de outras linguagens também) que
 * permite agrupar diferentes tipos de dados em um único conjunto. Imagine que você quer
 * guardar informações sobre uma pessoa, como nome (texto), idade (número) e altura
 * (número decimal). Com a struct, você pode criar uma "caixinha" que guarda tudo isso junto,
 * como se fosse um modelo personalizado.
 *
 * Assim, ao invés de ter várias variáveis separadas para cada informação, você cria uma
 * estrutura que representa uma pessoa, e pode criar quantas "pessoas" quiser a partir dela.
 * Isso torna o código mais organizado, reutilizável e fácil de entender.
 */

/**
 * @brief Armazena dois campos que definem o IMC de uma pessoa, com os campos
 */
struct IMC
{
    float altura; /**< Campo para altura da pessoa */
    float peso;   /**< Campo para peso da pessoa */
};

/* 'GLOBAL_IMC' Aqui criarmos uma instância do tipo global */
struct IMC GLOBAL_IMC = {0}; // Inicializando com zero

int main(int argc, char **argv)
{
    printf("\n\t==>IMC_GLOBAL<==\n");

    /* '.' Acessa de dentro da struct os campos através da instância global, para inserir valores. */
    GLOBAL_IMC.altura = 1.76F;
    GLOBAL_IMC.peso = 84.6F;

    /* '.' e podemos acessar para obter os valores de cada campo para utilizar em uma expressão. */
    float IMC_GLOBAL = GLOBAL_IMC.peso / (GLOBAL_IMC.altura * GLOBAL_IMC.altura);
    printf(" O RESULTADO DE IMC_GLOBAL E : %.2f\n", IMC_GLOBAL);

    printf("\n==============================================================\n");
    printf("\n\t==>IMC_LOCAL<==\n");

    /* 'LOCAL_IMC' Aqui criarmos uma instância do tipo local. */
    struct IMC LOCAL_IMC = {0}; // Inicializando com zero

    /* O mesmo para a instância global, atribuindo valor para altura e peso. */
    LOCAL_IMC.altura = 1.54F;
    LOCAL_IMC.peso = 50.4F;

    /* Obtendo os valores para calcular uma expressão de IMC e imprimindo o valor. */
    float IMC_LOCAL = LOCAL_IMC.peso / (LOCAL_IMC.altura * LOCAL_IMC.altura);
    printf(" O RESULTADO DE IMC_LOCAL E : %.2f\n", IMC_LOCAL);
    return 0;
}
