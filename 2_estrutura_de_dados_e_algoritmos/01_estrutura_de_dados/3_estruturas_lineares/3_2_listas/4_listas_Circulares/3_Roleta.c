#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WEAPON_NAME 20

/**
 * @brief Estrutura que representa um nó da lista circular.
 *
 * Cada nó contém o nome de uma arma e um ponteiro para o próximo nó.
 */
typedef struct node
{
    char weapon[MAX_WEAPON_NAME]; /**< Nome da arma */
    struct node *next;            /**< Ponteiro para o próximo nó */
} Node;

/**
 * @brief Estrutura que representa a roleta de armas.
 *
 * A roleta é uma lista circular onde cada nó contém o nome de uma arma.
 * O ponteiro atual indica a arma selecionada.
 */
typedef struct WeaponRoulette
{
    Node *current; /**< Ponteiro para o nó atual (arma selecionada) */
} WeaponRoulette;

/**
 * @brief Cria um novo nó contendo o nome de uma arma.
 *
 * Aloca memória dinamicamente para um nó e inicializa com o nome da arma.
 *
 * @param weapon Nome da arma a ser armazenado no nó.
 * @return Ponteiro para o nó recém-criado, ou NULL em caso de falha.
 */
Node *node_create(const char *weapon)
{
    Node *new_node = malloc(sizeof(Node));
    if (!new_node)
    {
        fprintf(stderr, "Erro ao alocar memória!\n");
        exit(EXIT_FAILURE);
    }

    strncpy(new_node->weapon, weapon, MAX_WEAPON_NAME - 1);
    new_node->weapon[MAX_WEAPON_NAME - 1] = '\0';
    new_node->next = NULL;
    return new_node;
}

/**
 * @brief Inicializa a roleta de armas com uma lista circular.
 *
 * Cria uma lista circular com os nomes das armas fornecidas no array.
 *
 * @param roulette Ponteiro para a estrutura WeaponRoulette a ser inicializada.
 * @param weapons Array de strings com os nomes das armas.
 * @param num_weapons Número de armas a serem adicionadas na roleta.
 */
void roulette_init(WeaponRoulette *roulette, const char *weapons[], int num_weapons)
{
    if (!roulette || num_weapons <= 0)
    {
        roulette->current = NULL;
        return;
    }

    Node *first_node  = node_create(weapons[0]);
    roulette->current = first_node;
    Node *last_node   = first_node;

    for (int i = 1; i < num_weapons; i++)
    {
        Node *new_node  = node_create(weapons[i]);
        last_node->next = new_node;
        last_node       = new_node;
    }
    last_node->next = first_node;
}

/**
 * @brief Move a roleta para a esquerda (próximo nó).
 *
 * Atualiza o ponteiro atual para o próximo nó na lista circular.
 *
 * @param roulette Ponteiro para a estrutura WeaponRoulette.
 */
void roulette_move_left(WeaponRoulette *roulette)
{
    if (!roulette || !roulette->current)
    {
        return;
    }
    roulette->current = roulette->current->next;
}

/**
 * @brief Move a roleta para a direita (nó anterior).
 *
 * Atualiza o ponteiro atual para o nó anterior na lista circular.
 *
 * @param roulette Ponteiro para a estrutura WeaponRoulette.
 */
void roulette_move_right(WeaponRoulette *roulette)
{
    if (!roulette || !roulette->current)
    {
        return;
    }

    Node *current = roulette->current;
    Node *temp = current;

    do
    {
        temp = temp->next;
        if (temp->next == current)
        {
            roulette->current = temp;
            break;
        }
    } while (temp != current);
}

/**
 * @brief Exibe o conteúdo da roleta de armas.
 *
 * Exibe todos os nomes das armas na roleta, destacando a arma atualmente selecionada.
 *
 * @param roulette Ponteiro para a estrutura WeaponRoulette.
 */
void roulette_print(const WeaponRoulette *roulette)
{
    if (!roulette || !roulette->current)
    {
        printf("A roleta está vazia!\n");
        return;
    }

    Node *current = roulette->current;
    do
    {
        if (current == roulette->current)
        {
            printf("[%s] <-- Selecionada\n", current->weapon);
        }
        else
        {
            printf("%s\n", current->weapon);
        }
        current = current->next;
    } while (current != roulette->current);
}

/**
 * @brief Libera a memória alocada para a roleta de armas.
 *
 * Percorre todos os nós da lista circular e libera a memória de cada um.
 *
 * @param roulette Ponteiro para a estrutura WeaponRoulette a ser liberada.
 */
void roulette_free(WeaponRoulette *roulette)
{
    if (!roulette || !roulette->current)
    {
        return;
    }

    Node *current = roulette->current;
    Node *first   = current;
    do
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    } while (current != first);

    roulette->current = NULL;
}

int main(int argc, char **argv)
{
    const char *weapons[] = {"Pistola", "Rifle", "Espingarda", "Metralhadora", "Granada"};
    size_t num_weapons    = sizeof(weapons) / sizeof(weapons[0]);
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

    return 0;
}
