#include <stdio.h>
#include <setjmp.h>

/**
 * <setjmp.h>: Presentes funções e tipos e constantes que são capazes de manipular
 * o fluxo de execução de um programa. Portanto, trata-se de um cabeçalho do qual seus
 * recursos devem ser utilizados apenas em situações nas quais estes são a única opção,
 * caso o código escrito esteja seguindo o paradigma de programação estruturada,
 * uma vez que os efeitos das funções presentes neste cabeçalho assemelham-se ao
 * uso de goto's no código.
 *
 * SETJMP: Salva o contexto de execução (ou seja, o estado atual do programa, como a pilha,
 * os registradores, etc.). Quando chamada, setjmp() retorna 0.
 *
 * LONGJMP: Faz o programa "voltar" para o ponto onde setjmp() foi chamada, mas com um
 * valor diferente. Se longjmp() for chamada, a execução "salta" para o ponto em que setjmp()
 * foi chamado, mas retorna um valor diferente de 0.
 */

int main(int argc, char **argv)
{
    jmp_buf env;   // Declara um buffer de salto
    int value = 0; // Variável para armazenar o valor de retorno

    // setjmp salva o contexto atual na variável env
    // e retorna 0 na primeira chamada.
    int jump_value = setjmp(env);

    if (jump_value != 0)
    {
        // Se setjmp retornar um valor diferente de 0, significa que longjmp foi chamado
        if (jump_value == 1)
        {
            printf("Retornando de longjmp com valor: %d\n", value);
        }
        else if (jump_value == 2)
        {
            // Aqui o fluxo vem da chamada de example_function
            printf("Retornando de example_function com valor: %d\n", value);
        }
    }
    else
    {
        // Se setjmp retornar 0, significa que é a primeira chamada
        printf("Primeira chamada de setjmp\n");
        longjmp(env, 1); // Chama longjmp para voltar para o ponto de setjmp
    }

    // Aqui o programa continua após o longjmp
    printf("Programa continua após longjmp\n");

    return 0;
}
