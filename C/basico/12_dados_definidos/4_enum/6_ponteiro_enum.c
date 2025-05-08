#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/**
 * @enum WeaponType
 * @brief Enumeração dos tipos de armas com suas capacidades padrão de munição.
 *
 * Cada tipo de arma possui uma quantidade característica de munição máxima.
 */
typedef enum
{
    PISTOL = 12, ///< Pistola com capacidade padrão de 12 balas
    SHOTGUN = 7, ///< Espingarda com capacidade padrão de 7 cartuchos
    RIFLE = 30   ///< Fuzil com capacidade padrão de 30 balas (alterado para ser mais realista)
} WeaponType;

/**
 * @struct Weapon
 * @brief Estrutura que representa uma arma com seu tipo e estado atual de munição.
 *
 * Armazena o tipo da arma e a quantidade atual de munição, além de incluir agora
 * a capacidade máxima para permitir recarregamento.
 */
typedef struct
{
    WeaponType type;       ///< Tipo da arma
    unsigned int ammo;     ///< Munição atual
    unsigned int max_ammo; ///< Capacidade máxima de munição (adicionado)
    bool is_jammed;        ///< Estado de enguiçamento (adicionado)
} Weapon;

/**
 * @brief Obtém o nome legível do tipo de arma.
 * @param type Tipo da arma.
 * @return String com o nome da arma.
 */
const char *get_weapon_name(WeaponType type)
{
    switch (type)
    {
    case PISTOL:
        return "Pistola";

    case SHOTGUN:
        return "Espingarda";

    case RIFLE:
        return "Fuzil";

    default:
        return "Arma desconhecida";
    }
}

/**
 * @brief Cria uma nova arma do tipo especificado.
 * @param type Tipo da arma a ser criada.
 * @return Weapon inicializada.
 *
 * Nova função para criação padronizada de armas.
 */
Weapon create_weapon(WeaponType type)
{
    Weapon w = {
        .type = type,
        .ammo = type, // Começa com munição máxima
        .max_ammo = type,
        .is_jammed = false};
    return w;
}

/**
 * @brief Simula o disparo da arma.
 * @param weapon Ponteiro para a arma a ser disparada.
 * @return true se o disparo foi bem sucedido, false caso contrário.
 *
 * Versão aprimorada com verificação de enguiçamento e feedback mais detalhado.
 */
bool fire_weapon(Weapon *weapon)
{
    if (weapon->is_jammed)
    {
        printf("%s enguiçada! Não pode disparar.\n", get_weapon_name(weapon->type));
        return false;
    }

    if (weapon->ammo > 0)
    {
        weapon->ammo--;
        printf("BANG! %s disparada. %d/%d restantes.\n",
               get_weapon_name(weapon->type), weapon->ammo, weapon->max_ammo);

        // 10% de chance de enguiçar após disparo
        if (rand() % 10 == 0)
        {
            weapon->is_jammed = true;
            printf("Oh não! %s enguiçou!\n", get_weapon_name(weapon->type));
        }
        return true;
    }
    else
    {
        printf("*clic* %s sem munição!\n", get_weapon_name(weapon->type));
        return false;
    }
}

/**
 * @brief Recarrega a arma.
 * @param weapon Ponteiro para a arma a ser recarregada.
 *
 * Nova função para recarregamento.
 */
void reload_weapon(Weapon *weapon)
{
    weapon->ammo = weapon->max_ammo;
    weapon->is_jammed = false;
    printf("%s recarregada! %d/%d balas.\n",
           get_weapon_name(weapon->type), weapon->ammo, weapon->max_ammo);
}

/**
 * @brief Desenguiça a arma.
 * @param weapon Ponteiro para a arma a ser reparada.
 *
 * Nova função para resolver enguiçamentos.
 */
void clear_jam(Weapon *weapon)
{
    if (weapon->is_jammed)
    {
        weapon->is_jammed = false;
        printf("%s desenguiçada! Pronta para disparar.\n", get_weapon_name(weapon->type));
    }
    else
    {
        printf("%s não está enguiçada.\n", get_weapon_name(weapon->type));
    }
}

int main(int argc, char **argv)
{
    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Cria armas usando a função de criação padronizada
    Weapon pistol = create_weapon(PISTOL);
    Weapon shotgun = create_weapon(SHOTGUN);
    Weapon rifle = create_weapon(RIFLE);

    // Simulação de uso
    for (int i = 0; i < 3; i++)
    {
        fire_weapon(&pistol);
    }

    fire_weapon(&shotgun);
    fire_weapon(&shotgun);

    for (int i = 0; i < 5; i++)
    {
        if (!fire_weapon(&rifle))
        {
            clear_jam(&rifle); // Tenta desenguiçar se falhar
        }
    }

    reload_weapon(&pistol);
    fire_weapon(&pistol);

    return 0;
}
