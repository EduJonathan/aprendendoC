#include "roleta.h"

int main(int argc, char **argv)
{
    // Exemplo de uso:
    RoletaDeArmas roleta;
    const char *armas_disponiveis[] = {"Pistola", "Espingarda", "Rifle", "Granada"};
    int num_armas = sizeof(armas_disponiveis) / sizeof(armas_disponiveis[0]);

    // Inicializa a roleta com as armas disponíveis
    inicializar_roleta(&roleta, armas_disponiveis, num_armas);

    // Exibe o menu interativo
    exibir_menu(&roleta);

    return 0;
}
