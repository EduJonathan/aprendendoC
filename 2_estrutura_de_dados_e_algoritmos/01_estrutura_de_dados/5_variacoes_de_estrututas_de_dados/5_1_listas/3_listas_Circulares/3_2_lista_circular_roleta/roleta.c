#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "roleta.h"

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

void roulette_init(WeaponRoulette *roulette, const char *weapons[], int num_weapons)
{
    if (!roulette || num_weapons <= 0)
    {
        roulette->current = NULL;
        return;
    }

    Node *first_node = node_create(weapons[0]);
    roulette->current = first_node;
    Node *last_node = first_node;

    for (int i = 1; i < num_weapons; i++)
    {
        Node *new_node = node_create(weapons[i]);
        last_node->next = new_node;
        last_node = new_node;
    }

    last_node->next = first_node;
}

void roulette_move_left(WeaponRoulette *roulette)
{
    if (!roulette || !roulette->current)
    {
        return;
    }
    roulette->current = roulette->current->next;
}

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

void roulette_free(WeaponRoulette *roulette)
{
    if (!roulette || !roulette->current)
    {
        return;
    }

    Node *current = roulette->current;
    Node *first = current;
    do
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    } while (current != first);

    roulette->current = NULL;
}
