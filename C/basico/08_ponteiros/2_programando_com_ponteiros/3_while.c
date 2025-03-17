#include <stdio.h>

int main(int argc, char **argv)
{
    // Valor inicial 'A'
    char valor = 'A';

    // Ponteiro para o valor 'A'
    char *ptr = &valor;

    // Imprime o alfabeto de 'A' a 'Z'
    while (*ptr <= 'Z')
    {
        printf("%c ", *ptr); // Imprime o caractere apontado por 'ptr'
        (*ptr)++;            // Incrementa o valor apontado por 'ptr'
    }

    printf("\n=======================================\n");

    // Pedindo ao usuário um caractere
    char alfa;
    printf("Insira uma letra para encontramos? ");
    scanf("%c", &alfa);
    setbuf(stdin, NULL);

    // Guarde o caractere em um ponteiro
    char *ponteiro = &alfa;

    // Verifica o conteúdo do ponteiro que enquanto o conteúdo não for encontrado
    // com a verificação na tabela
    while (*ponteiro)
    {
        // Verifica se o caractere está entre 'A' e 'Z'
        if (*ponteiro >= 65 && *ponteiro <= 90)
        {
            // Imprime a mensagem indicando que o caractere foi encontrado
            printf("O caractere %c está entre 'A' e 'Z' na tabela ASCII.\n", *ponteiro);
            break; // Encerra o loop quando o caractere for encontrado
        }
        else
        {
            // Lendo outro caractere para continuar
            printf("Insira outra letra ou presione: ");
            scanf("%c", &alfa);
            setbuf(stdin, NULL);
            ponteiro = &alfa; // Atualiza o ponteiro para apontar para o novo caractere inserido
        }
    }
    return 0;
}
