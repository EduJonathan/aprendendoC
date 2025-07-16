#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

#ifndef SETSTRING_H
#define SETSTRING_H

typedef struct set
{
    char dados[MAX_SIZE][100];
    size_t tamanho;
} Set;

#endif

/**
 * @brief Verifica se um elemento está presente no set
 *
 * Função para verificar se o conjunto contém um valor
 *
 * @param s Ponteiro para o conjunto
 * @param valor Elemento a ser verificado
 * @return Retorna verdadeiro se o elemento estiver presente no conjunto
 */
bool contem(Set *s, const char *valor)
{
    for (size_t i = 0ull; i < s->tamanho; i++)
    {
        if (strcmp(s->dados[i], valor) == 0)
        {
            return true; // Encontrou duplicata
        }
    }
    return false;
}

/**
 * @brief Adiciona um elemento ao set
 *
 * Função para adicionar um elemento ao conjunto
 *
 * @param s Ponteiro para o conjunto
 * @param valor Elemento a ser adicionado
 */
void adicionar(Set *s, const char *valor)
{
    if (!contem(s, valor) && s->tamanho < MAX_SIZE)
    {
        strcpy(s->dados[s->tamanho], valor);
        s->tamanho++;
    }
}

/**
 * @brief Imprime os elementos do set
 *
 * Função para imprimir o conjunto
 *
 * @param s Ponteiro para o conjunto
 */
void print(Set *s)
{
    for (size_t i = 0ull; i < s->tamanho; i++)
    {
        printf("%s\n", s->dados[i]);
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    Set setx = {{"Verde", "Azul"}, 2};   // Inicializando os conjuntos com 2 elementos
    Set sety = {{"Azul", "Amarelo"}, 2}; // Inicializando os conjuntos com 2 elementos
    Set setz = {{"", ""}, 0};            // Conjunto vazio para armazenar a união

    for (size_t i = 0ull; i < setx.tamanho; i++)
    {
        adicionar(&setz, setx.dados[i]);
    }

    for (size_t i = 0ull; i < sety.tamanho; i++)
    {
        adicionar(&setz, sety.dados[i]);
    }

    print(&setz);
    return 0;
}
