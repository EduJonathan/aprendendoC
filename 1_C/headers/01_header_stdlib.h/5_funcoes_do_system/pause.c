#include <stdio.h>
#include <stdlib.h>

/**
 * system("pause");
 * A função system("pause") é uma chamada de sistema que executa o comando "pause"
 * do sistema operacional. Esse comando é comumente usado em sistemas Windows para
 * interromper a execução do programa e aguardar a interação do usuário.
 *
 * ultimamente não é recomendado o uso de system("pause") por questões de portabilidade
 * e segurança. Em vez disso, é preferível usar métodos mais portáteis e seguros para pausar
 * a execução do programa, como a função getchar() para aguardar a entrada do usuário.
 */

int main(int argc, char **argv)
{
    printf("\n=== Uso de system(\"pause\") ===\n");

    printf("O programa está pausado. Pressione Enter para continuar...\n");
    // Pausa a execução do programa até que o usuário pressione uma tecla
    system("pause"); // Note que isso funciona apenas em sistemas Windows

    printf("Programa continuando após a pausa.\n");
    return 0;
}