#include <stdio.h>
#include <string.h>

/**
 * strcat(string concat): Função de concatenção (juntar duas strings em uma), recebendo as
 * strings como parâmetros, onde sempre o primeiro parâmetro a qual a função irá receber, será
 * a que terá acesso sempre ao segundo parâmetros.
 *
 * SINTAXE: char *strcat(char *__restrict__ _Dest, const char *__restrict__ _Source);
 *
 * @param _Dest: Ponteiro para a string de destino onde a string de origem será concatenada.
 * Esta string deve ter espaço suficiente para acomodar a concatenação.
 * @param _Source Ponteiro para a string de origem que será adicionada ao final da string de destino.
 * @return Um ponteiro para a string de destino (dest).
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
