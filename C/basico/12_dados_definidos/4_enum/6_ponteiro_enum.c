#include <stdio.h>

/**
 * @enum arma
 *
 * @brief Enum para diferentes tipos de armas com suas quantidades de munição. Esta enumera
 * diferentes tipos de armas com suas respectivas quantidades de munição.
 */
enum arma
{
    PISTOLA = 12, /**< Pistola com 12 balas de munição */
    SHOTGUN = 7,  /**< Espingarda com 7 balas de munição */
    RIFLE = 4     /**< Fuzil com 4 balas de munição */
};

/**
 * @struct weapon
 *
 * @brief Estrutura que representa uma arma com tipo e contagem de munição. Esta estrutura armazena
 * o tipo da arma e o número de balas disponíveis.
 */
typedef struct weapon
{
    enum arma type;    /**< Tipo da arma */
    unsigned int ammo; /**< Número de balas disponíveis */
} Weapon;

/**
 * @brief Obtém o nome da arma como uma string.
 *
 * Esta função retorna o nome da arma com base no seu tipo.
 *
 * @param type Tipo da arma.
 * @return Nome da arma.
 */
const char *equiparUmaArma(enum arma type)
{
    switch (type)
    {
    case PISTOLA:
        return "pistola";

    case SHOTGUN:
        return "espingarda";

    case RIFLE:
        return "fuzil";
    }
    
    return "arma desconhecida";
}

/**
 * @brief Dispara a arma, reduzindo a contagem de munição.
 *
 * Esta função simula o disparo da arma. Ela decrementa a contagem de munição
 * se houver munição restantes. Imprime uma mensagem indicando a munição restante ou se
 * a arma está sem munição.
 *
 * @param weapon Ponteiro para a estrutura Weapon a ser disparada.
 */
void dispararArma(Weapon *weapon)
{
    if (weapon->ammo > 0)
    {
        weapon->ammo--; /**< Decrementa a contagem de munição */
        printf("Disparando %s. Munição restante: %d\n", equiparUmaArma(weapon->type), weapon->ammo);
    }
    else
    {
        printf("Sem munição para %s.\n", equiparUmaArma(weapon->type));
    }
}

int main(int argc, char **argv)
{
    Weapon pistol = {PISTOLA, 10}; /* Inicializa a pistola com 10 balas */
    Weapon shotgun = {SHOTGUN, 5}; /* Inicializa a espingarda com 5 balas */
    Weapon rifle = {RIFLE, 3};     /* Inicializa o fuzil com 3 balas */

    dispararArma(&pistol);  /* Dispara a pistola */
    dispararArma(&pistol);  /* Dispara a pistola novamente */
    dispararArma(&shotgun); /* Dispara a espingarda */
    dispararArma(&rifle);   /* Dispara o fuzil */
    return 0;
}
