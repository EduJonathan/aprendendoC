#include <stdio.h>

/**
 * STATIC:
 * A palavra-chave `static` em C indica que uma variável mantém seu valor entre
 * chamadas consecutivas da função ou do bloco onde foi declarada.
 *
 * - Variáveis locais comuns são criadas e destruídas a cada chamada da função;
 *   já variáveis `static` preservam seu valor entre as chamadas.
 *
 * - Variáveis `static` declaradas fora de qualquer função têm escopo de arquivo,
 *   ou seja, só são visíveis dentro do arquivo em que foram declaradas.
 *
 * USOS:
 * - Manter estado interno de uma função sem expor variáveis globalmente.
 * - Criar contadores ou caches persistentes.
 *
 * ATENÇÃO:
 * - Uso excessivo pode causar efeitos colaterais difíceis de depurar.
 * - Variáveis `static` não podem ser membros de `struct`.
 */

/**
 * @brief Incrementa uma variável estática e uma variável local em cada chamada.
 *
 * Variável `a` é estática: preserva seu valor entre chamadas.
 * Variável `b` é local: reinicializa a cada chamada.
 */
void teste_static_global(void)
{
    static int a = 0; // mantém o valor entre chamadas
    int b = 0;        // reinicia a cada chamada
    a += 5;           // incrementa 5 a cada chamada
    b++;              // incrementa 1 a cada chamada, mas reinicia sempre

    printf("STATIC a: %d\tINT b: %d\n", a, b);
}

/**
 * @brief Incrementa uma variável estática de função a cada chamada.
 *
 * Demonstra persistência do valor de uma variável `static`.
 */
void estatico(void)
{
    static int a = 5; // primeira chamada = 5

    printf("Valor de a: %d\n", a);
    a++; // mantém incremento entre chamadas
}

int main(int argc, char **argv)
{
    // Demonstração do escopo de função e persistência de variáveis estáticas
    estatico(); // OUTPUT: 5
    estatico(); // OUTPUT: 6

    printf("\n===================\n");

    teste_static_global(); // OUTPUT: STATIC a: 5    INT b: 1
    teste_static_global(); // OUTPUT: STATIC a: 10   INT b: 1

    return 0;
}
