#include <stdio.h>

/* Como o scanf funciona com ponteiros */

int main(int argc, char **argv)
{
    // Declaração e inicialização das variáveis
    int x = 13;          // Variável inteira x inicializada com 13
    int y = 50;          // Variável inteira y inicializada com 50
    int *pointer = NULL; // Ponteiro para inteiro, inicializado com NULL

    // Imprime os endereços de memória das variáveis e do ponteiro
    // &x: endereço de x
    // &y: endereço de y
    // pointer: endereço armazenado no ponteiro (atualmente NULL)
    // &pointer: endereço de memória onde o ponteiro 'pointer' está armazenado
    printf("ENDEREÇO DE x: %p ENDEREÇO DE y: %p ENDEREÇO QUE pointer APONTA: %p ENDEREÇO DE MEMÓRIA DE pointer: %p\n", &x, &y, pointer, &pointer);

    // Atribui o endereço de x ao ponteiro
    pointer = &x;

    // Imprime os endereços atualizados
    // &x: endereço de x (não mudou)
    // &y: endereço de y (não mudou)
    // pointer: agora aponta para o endereço de x
    // &pointer: endereço de memória onde o ponteiro 'pointer' está armazenado
    printf("\nENDEREÇO DE x: %p ENDEREÇO DE y: %p ENDEREÇO DE pointer: %p ENDEREÇO DE pointer: %p\n", &x, &y, pointer, &pointer);

    // Modifica o valor de x indiretamente através do ponteiro
    *pointer = 65; // O valor de x é alterado para 65

    // Imprime os valores das variáveis e o valor para o qual o ponteiro aponta
    // x: agora contém 65
    // y: ainda contém 50
    // *pointer: o valor de x, que o ponteiro está apontando, agora é 65
    printf("CONTEÚDO DE x: %d Conteúdo de y: %d Conteúdo de pointer: %d\n", x, y, *pointer);

    // Atribui o endereço de y ao ponteiro
    pointer = &y;
    y = 40; // Modifica o valor de y para 40

    // Imprime os endereços atualizados
    // &x: endereço de x (não mudou)
    // &y: endereço de y (não mudou)
    // pointer: agora aponta para o endereço de y
    // &pointer: endereço de memória onde o ponteiro 'pointer' está armazenado
    printf("\nENDEREÇO DE x: %p ENDEREÇO DE y: %p ENDEREÇO DE pointer: %p ENDEREÇO DE pointer: %p\n", &x, &y, pointer, &pointer);

    // Imprime os valores das variáveis e o valor para o qual o ponteiro aponta
    // x: ainda contém 65 (não foi alterado)
    // y: agora contém 40
    // *pointer: o valor de y, que o ponteiro está apontando, agora é 40
    printf("CONTEÚDO DE x: %d Conteúdo de y: %d Conteúdo de pointer: %d\n", x, y, *pointer);

    // Atualiza x com o valor do endereço para o qual o ponteiro aponta (y)
    x = *pointer; // x recebe o valor de y (40)

    // Lê um valor do teclado e armazena no endereço para o qual o ponteiro aponta (y)
    // Não precisamos usar '&pointer' aqui, pois pointer já está apontando para o endereço de y
    scanf("%d", pointer);

    // Imprime os valores finais das variáveis e o valor para o qual o ponteiro aponta
    // x: agora contém o valor lido do teclado (o mesmo que y)
    // y: contém o valor lido do teclado
    // *pointer: o valor de y, que agora é o mesmo que x
    printf("CONTEÚDO DE x: %d Conteúdo de y: %d Conteúdo de pointer: %d\n", x, y, *pointer);
    return 0;
}
