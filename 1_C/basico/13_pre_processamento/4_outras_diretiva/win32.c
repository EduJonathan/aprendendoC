#include <stdio.h>

int main(int argc, char **argv)
{
#ifdef _WIN32 // macro é definida automaticamente quando o código está sendo compilado no Windows
    printf("Seu Sistema é o Windows\n");
#elif defined(__APPLE__) // Macro é definida quando o código está sendo compilado no macOS (Apple).
    printf("Seu Sistema é o macOS\n");
#elif defined(__linux__) // Macro Definido para compilações no Linux.
    printf("Seu Sistema é o Linux\n");
#else
    printf("Sistema não identificado\n");
#endif
    return 0;
}
