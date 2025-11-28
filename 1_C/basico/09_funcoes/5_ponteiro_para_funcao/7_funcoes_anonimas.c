#include <stdio.h>

/**
 * LAMBDA:
 * Lambda ou funções anônimas, ou sja, é um tipo de função que não tem um nome explícito.
 * Ela é definida no local onde é utilizada, onde pode capturar váriaveis do escopo ao redor
 * para modificar, além de ser uma forma mais concisa de expressar funções simples.
 *
 * Nativamente para a linguagem C não há suporte para se declarar explicitamente,
 * sendo possível somente com uso de macros ou ponteiros para função, sendo possível
 * em linguagens posteriores.
 * Porém em compiladores modernos com o uso da extensão "statement expression" do GCC
 * (e também do CLANG) permite criar estas funções.
 */


#define FN_NAME(counter) __lambda_##counter
#define FN(counter, return_type, args, body) \
    static return_type FN_NAME(counter)      \
    args body

#define lambda(return_type, args, body) \
    (FN(__COUNTER__, return_type, args, body), FN_NAME(__COUNTER__ - 1))

int main(void)
{
    int (*adicao)(int, int) =
        lambda(int, (int x, int y), { return x + y; });

    printf("%d\n", adicao(3, 4));
}
