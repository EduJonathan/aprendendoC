#include <stdio.h>

/**
 * AUTO:
 * - `auto` é o modificador de armazenamento padrão para variáveis locais em C e C++.
 * - Indica que a variável tem escopo local (só é visível dentro do bloco em que foi declarada)
 *   e é armazenada na memória stack (pilha).
 * - Em C moderno, a palavra-chave `auto` é **opcional**, pois todas as variáveis locais já
 *   são tratadas como auto por padrão.
 *
 * Características:
 * - Escopo local ao bloco.
 * - Vida útil limitada à execução do bloco.
 * - Pode ser usada com qualquer tipo de dado.
 *
 * Uso típico:
 *   auto int i;   // variável local do tipo int
 *
 * Observação:
 * - Em C++ moderno (C++11+), `auto` também permite inferência de tipo, mas em C isso não existe.
 * - O uso explícito de `auto` em C é raríssimo e desnecessário, sendo mais utilizado em C++.
 */

int main(int argc, char **argv)
{
    // Variáveis auto explícitas (opcional, comportamento padrão)
    auto int t = 4;
    printf("Valor de t: %d\n", t);

    auto float v = 555.10F;
    printf("Valor de v: %.2f\n", v);

    auto char *s = "Variável auto";
    printf("Valor de s: %s\n", s);

    /**
     * Observações importantes:
     * - O uso de 'auto' como especificador de tipo é redundante em C.
     * - Alguns compiladores antigos podem gerar avisos se 'auto' for usado
     *   sem tipo explícito:
     *
     *     auto x = 42;   // C90/C99: type defaults to 'int' [-Wimplicit-int]
     *     auto y = 3.14; // mesmo aviso
     *
     * - Em C moderno, é melhor declarar diretamente:
     *     int x = 42;
     *     float y = 3.14F;
     */
    return 0;
}
