#include <stdio.h>
#include <assert.h>

// assert(expression): macro principal da biblioteca. Se a expressão passada
// como argumento for falsa (avaliada como zero), a macro assert gera uma mensagem de erro,
// geralmente indicando a expressão que falhou, e encerra o programa.

int main(int argc, char **argv)
{
    int x = -1;
    assert(x >= 0);
    printf("x = %d\n", x);

    /**
     * ASSERT: a função assert é usada para testar uma expressão e, caso a expressão seja
     * falsa, ela interrompe o programa e imprime uma mensagem de erro. no código, a
     * expressão dentro do assert é x >= 0. Portanto, se x for menor que zero, o assert
     * falhará, interrompendo o programa e exibindo uma mensagem de erro.
     *
     * Vale mencionar que a utilização de assert é geralmente destinada para testes
     * durante o desenvolvimento e depuração do código. Quando você compila o programa com
     * a flag -DNDEBUG (por exemplo, usando gcc -DNDEBUG -o <nome do arquivo> arquivo.c).
     * As declarações assert são removidas do código compilado. Isso significa que em versões
     * de produção, as verificações assert não terão efeito. Portanto, se você está usando
     * assert para garantir que uma condição seja  verdadeira, talvez seja mais apropriado
     * usar instruções condicionais e mensagens de erro explícitas para garantir que o
     * programa não falhe em situações inesperadas. 
     * O uso de assert é mais adequado para testes temporários e depuração.
     */
    return 0;
}
