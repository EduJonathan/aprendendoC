#include <stdio.h>
#include <string.h>

/**
 * A função `strcat()` adiciona o conteúdo da string `src` ao final da string `dest`,
 * sobrescrevendo o caractere nulo (`'\0'`) de `dest` e adicionando um novo no final.
 *
 * @param dest Ponteiro para a string de destino, que deve conter espaço suficiente
 *             para armazenar a string resultante.
 * @param src  Ponteiro para a string de origem que será adicionada ao final de `dest`.
 *
 * @return Retorna um ponteiro para `dest`.
 *
 * @note A função não verifica o tamanho de `dest`. Use com cuidado para evitar
 *       *buffer overflows*. Prefira `strncat()` para limitar a concatenação.
 */

/**
 * concatenandoStringsComStrcat(): Função de concatenação (juntar duas strings em uma),
 * onde a primeira string deve ter espaço suficiente para a concatenação.
 *
 * @param string1 Ponteiro para a string que receberá a concatenação.
 * @param string2 Ponteiro para a string que será concatenada.
 */
void concatenandoStringsComStrcat(char *string1, const char *string2) { strcat(string1, string2); }

int main(int argc, char **argv)
{
    /**
     * Se tentar passar apenas um caracter.
     * ERRO:
     * char Char1 = 'a';
     * char Char2 = 'b';
     * strcat(Char1, Char2);
     * printf("%s\n", Char1);
     */

    /*Concatenando as strings "Latino" e " Americano". */
    char str1[10] = "Latino";
    char str2[13] = " Americano";

    concatenandoStringsComStrcat(str1, str2);
    printf("%s\n", str1);

    printf("\n-----------------------------\n");

    /*Concatenando as strings "Brasi" e "leiro". */
    char str3[10] = "Brasi";
    concatenandoStringsComStrcat(str3, "leiro");
    printf("%s\n", str3);
    return 0;
}
