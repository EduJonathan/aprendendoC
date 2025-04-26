#include "pragma_once.h"

/**
 * O #pragma: É uma diretiva de pré-processador usada para evitar múltiplas inclusões de
 * um mesmo arquivo de cabeçalho durante a compilação. Ele é uma alternativa mais simples
 * ao uso tradicional de include guards (#ifndef, #define, #endif ) e garante que o compilador
 * inclua o arquivo apenas uma vez, independentemente de quantas vezes ele seja referenciado.
 * Não é oficialmente padronizado na linguagem C/C++.
 * Para compatibilidade máxima, alguns desenvolvedores ainda preferem os include guards.
 * Use #pragma once em arquivos de cabeçalho (.h). Caso você esteja criando um arquivo
 * de cabeçalho separado para declarar funções e incluir esse cabeçalho em outros arquivos.
 * 
 * A melhor flag para o pragma once seria as de verificações
 * gcc pragma_once_main.c -E
 */

void minhaFuncao()
{
    printf("Executando minhaFuncao!\n");
}

int main(int argc, char **argv)
{
    minhaFuncao();
    return 0;
}
