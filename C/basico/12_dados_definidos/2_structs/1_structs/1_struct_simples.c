#include <stdio.h>

/**
 * STRUCT: Estrutura que nos permite agrupar vários tipos de dados conhecidos como
 * campos, que podem personalizar informações relacionadas de maneira organizada,
 * instanciando-a para o uso desses dados.
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
struct IMC GLOBAL_IMC;

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
    struct IMC LOCAL_IMC;

    /* O mesmo para a instância global, atribuindo valor para altura e peso. */
    LOCAL_IMC.altura = 1.54L;
    LOCAL_IMC.peso = 50.4L;

    /* Obtendo os valores para calcular uma expressão de IMC e imprimindo o valor. */
    double IMC_LOCAL = LOCAL_IMC.peso / (LOCAL_IMC.altura * LOCAL_IMC.altura);
    printf(" O RESULTADO DE IMC_LOCAL E : %.2f\n", IMC_LOCAL);
    return 0;
}
