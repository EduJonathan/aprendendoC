#include <stdio.h>

/**
 * VARIÁVEIS DE BLOCO:
 * São variáveis declaradas dentro de um par de chaves `{ }`, seja dentro de uma função
 * ou dentro de um bloco interno (como em if, while, for ou blocos anônimos).
 *
 * Elas possuem escopo restrito ao bloco onde foram declaradas: só podem ser acessadas
 * dentro desse conjunto de chaves. Quando o bloco termina, essas variáveis deixam de
 * existir.
 *
 * Caso uma variável dentro de um bloco tenha o mesmo nome de uma variável local ou global,
 * ocorre "sombreamento" (shadowing): a variável mais interna esconde a externa dentro
 * daquele escopo, mas a variável original continua existindo fora do bloco.
 */

int main(int argc, char **argv)
{
    // Variáveis locais da função main
    int a = 8;
    int p = 5;

    // Bloco interno
    {
        int b = 12;    // variável de bloco
        int r = a + b; // variável de bloco
        int p = 3;     // esta 'p' SOMBREIA a 'p' local acima

        printf("a + b: %d\n", r);
        printf("p dentro do bloco: %d\n", p); // imprime 3
    }

    // Erro se tentar usar 'b' ou 'r' aqui: elas existem somente dentro do bloco acima
    // printf("%d\n", b);  // inválido
    // printf("%d\n", r);  // inválido

    // Aqui volta a valer o 'p' da função main (que é 5)
    printf("p fora do bloco: %d\n", p);

    return 0;
}
