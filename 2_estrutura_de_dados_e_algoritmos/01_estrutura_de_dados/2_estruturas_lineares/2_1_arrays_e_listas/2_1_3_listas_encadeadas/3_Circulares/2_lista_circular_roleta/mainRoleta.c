#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "roleta.h"

int main(int argc, char **argv)
{
    const char *weapons[] = {"Pistola", "Rifle", "Espingarda", "Metralhadora", "Granada"};
    int num_weapons = sizeof(weapons) / sizeof(weapons[0]);

    WeaponRoulette roulette;
    roulette_init(&roulette, weapons, num_weapons);

    int choice = 0;
    while (true)
    {
        printf("\n--- ROLETA DE ARMAS ABERTA ---\n");
        printf("1. Mover para a esquerda\n");
        printf("2. Mover para a direita\n");
        printf("3. Exibir roleta\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");

        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n');
            printf("Entrada inválida! Tente novamente.\n");
            continue;
        }

        switch (choice)
        {
        case 1:
            roulette_move_left(&roulette);
            roulette_print(&roulette);
            break;

        case 2:
            roulette_move_right(&roulette);
            roulette_print(&roulette);
            break;

        case 3:
            roulette_print(&roulette);
            break;

        case 0:
            printf("Saindo...\n");
            roulette_free(&roulette);
            return 0;

        default:
            printf("Opção inválida! Tente novamente.\n");
        }
        while (getchar() != '\n'); // Limpa buffer
    }


    /**
     * Compile e execute com:
     * gcc -std=c17 -o roleta mainRoleta.c roleta.c
     * .\roleta.exe
     */
    return 0;
}
