#include <stdio.h>

/**
 * AUTO: indica que uma variável é armazenada na memória stack (pilha) e sempre
 * é do escopo de local (visível apenas dentro do bloco de código onde é declarada).
 */

// auto int i; file-scope declaration of 'i' specifies 'auto'

int main(int argc, char **argv)
{
    int auto t = 4;
    printf("Valor de t: %d\n", t);

    auto float v = 555.10F;
    printf("Valor de v: %.2f\n", v);

    auto char *s = "Variável auto";
    printf("Valor de s: %s\n", s);

    // auto x = 42;
    // printf("Valor de x: %d\n", x);

    // auto y = 3.14F;
    // printf("Valor de y: %.2lf\n", y);

    /**
     * auto x = 42;
     * printf("Valor de x: %d\n", x);
     *
     * auto y = 3.14;
     * printf("Valor de y: %.2lf\n", y);
     * type defaults to 'int' in declaration of 'x' e 'y' [-Wimplicit-int] gcc <error-type> x
     *
     * Este código funcionará da mesma forma que o seu código original. No entanto,
     * a palavra-chave auto como especificador de tipo pode gerar avisos em alguns
     * compiladores C. Dificilmente utilizada em C, e mais utilizada em C++, mas se possível,
     * é recomendável evitar o uso desnecessário de auto nesse contexto.
     */
    return 0;
}
