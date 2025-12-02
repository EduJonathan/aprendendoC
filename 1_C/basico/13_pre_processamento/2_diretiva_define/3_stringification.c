#include <stdio.h>

/**
 * O operador '#' em macros (também chamado de *stringification*) converte o argumento
 * passado para o parâmetro da macro em uma *string literal*. Isso ocorre antes da
 * compilação, durante a etapa de pré-processamento.
 *
 * No exemplo abaixo, `#a` e `#b` transformam exatamente o texto fornecido nos argumentos
 * da macro em strings. Assim, independentemente de `a` ou `b` serem números, identificadores
 * ou valores já escritos como strings, o pré-processador converte seus tokens literais
 * em sequências de caracteres entre aspas.
 *
 * O resultado final é então concatenado com outras *string literals* no `printf`,
 * permitindo montar mensagens em tempo de pré-processamento.
 */

#define STRINGIFICATION(a, b) \
    printf(#a " e " #b ": Nós te amamos!\n")

int main(int argc, char **argv)
{
    STRINGIFICATION("Carol", "Debora");
    return 0;
}
