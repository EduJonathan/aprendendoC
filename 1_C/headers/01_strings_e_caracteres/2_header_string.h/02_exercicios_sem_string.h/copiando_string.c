#include <stdio.h>

/**
 * @brief Copia uma string com limite de tamanho para segurança.
 *
 * @param origem String fonte.
 * @param destino Buffer que receberá a cópia.
 * @param limite Tamanho máximo que o destino suporta.
 */
void copiarStringSegura(const char *origem, char *destino, size_t limite)
{
    int i = 0;

    // Copia enquanto houver caracteres E enquanto houver espaço no destino
    // Deixamos um espaço (limite - 1) para o '\0' final
    while (origem[i] != '\0' && i < (limite - 1))
    {
        destino[i] = origem[i];
        i++;
    }

    // Finaliza a string de destino obrigatoriamente
    destino[i] = '\0';
}

int main(int argc, char **argv)
{
    char string1[] = "Hello World com frase muito longa";
    char string2[17] = {0};

    // Passamos sizeof(string2) para a função saber onde parar
    copiarStringSegura(string1, string2, sizeof(string2));

    printf("String 1: %s\n", string1);
    printf("String 2 (truncada no limite): %s\n", string2);

    return 0;
}
