#include <stdio.h>

/* Este programa apresenta 2 funções que tratam apenas caracteres putchar() e getchar() */

int main(int argc, char **argv)
{
    /* Declarando uma variável char. */
    char caracter;
    printf("Digite um caractere: ");

    // getchar(): Com getchar guardada na variável char podemos ter uma entrada para um caractere.
    caracter = getchar();

    /* Limpa o buffer de entrada (caso o usuário tenha inserido mais de um caractere). */
    while (getchar() != '\n');

    printf("\nCaractere inserido: ");

    // putchar(insere caractere): Permite podemos inserir um caractere APENAS, seja char ou de escape.     
    putchar(caracter);
    putchar('\n');

    /**
     * ERRO: Não permite pegar um array de string, o compilador indicará conflito caso tentar.
     * 
     * char caracteres[10];
     * caracteres = getchar();
     */
    return 0;
}
