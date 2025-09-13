#include <stdio.h>
#include <string.h>

#define NUM_TIMES 4 // Número de times
#define MAX_NOME 50 // Tamanho máximo para o nome do time

int main(int argc, char **argv)
{
    // Array para armazenar os nomes dos times
    char times[NUM_TIMES][MAX_NOME] = {
        "Flamengo",
        "Vasco",
        "Botafogo",
        "Fluminense"};

    // Array multidimensional para armazenar pontos, gols marcados, gols sofridos e jogos
    int tabela[NUM_TIMES][4] = {
        {30, 25, 15, 12}, // Flamengo: pontos, gols marcados, gols sofridos, jogos
        {25, 22, 18, 12}, // Vasco
        {20, 18, 22, 12}, // Botafogo
        {28, 24, 20, 12}  // Fluminense
    };

    // Usando ponteiro para acessar os dados
    int (*ptrTabela)[4] = tabela; // Ponteiro para o array de 4 inteiros (dados dos times)

    // Imprimindo os dados dos times usando ponteiros
    printf("Tabela do Campeonato:\n");
    for (int i = 0; i < NUM_TIMES; i++)
    {
        printf("Time: %-12s | Pontos: %d | Gols Marcados: %d | Gols Sofridos: %d | Jogos: %d\n",
               times[i], *(ptrTabela[i] + 0), *(ptrTabela[i] + 1), *(ptrTabela[i] + 2), *(ptrTabela[i] + 3));
    }

    // Exemplo de modificação: Incrementando pontos do Flamengo
    *(ptrTabela[0] + 0) += 3; // Flamengo ganhou uma partida e somou 3 pontos

    // Imprimindo novamente a tabela
    printf("\nTabela Atualizada (Flamengo ganhou 3 pontos):\n");
    for (int i = 0; i < NUM_TIMES; i++)
    {
        printf("Time: %-12s | Pontos: %d | Gols Marcados: %d | Gols Sofridos: %d | Jogos: %d\n",
               times[i], *(ptrTabela[i] + 0), *(ptrTabela[i] + 1), *(ptrTabela[i] + 2), *(ptrTabela[i] + 3));
    }

    return 0;
}
