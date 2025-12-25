#include <stdlib.h>
#include "../includes/utils.h"

/**
 * @brief Limpa o console de comandos de forma portável.
 *
 * Detecta o sistema operacional em tempo de compilação e executa
 * o comando 'cls' (Windows) ou 'clear' (Unix/Linux/macOS).
 */
void clear_screen(void)
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
