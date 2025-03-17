#include <stdio.h>

// Marca a função insegura 'gets' como "envenenada/perigosa ao programa"
#pragma poison gets

int main(int argc, char **argv)
{
    char buffer[100];

    // Tentativa de usar 'gets' resultará em um erro ou aviso
    gets(buffer); // Deve gerar um aviso ou erro de compilação
    return 0;
}
