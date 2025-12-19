#ifndef PERMISSOES_LIB_H
#define PERMISSOES_LIB_H

#include <sys/types.h> // mode_t, mode_t é usado para representar o modo do arquivo

#if defined(_WIN32) || defined(__CYGWIN__)
#ifdef BUILDING_PERMISSOES_LIB
    #define PERMISSOES_API __declspec(dllexport)
#else
    #define PERMISSOES_API __declspec(dllimport)
#endif
#else
    #define PERMISSOES_API
#endif

/**
 * @brief Converte o modo do arquivo para string simbólica (ex: -rwxr-xr-x)
 * O buffer str deve ter no mínimo 11 bytes (10 caracteres + '\0')
 *
 * @param modo O modo do arquivo (st_mode da struct stat)
 * @param str Buffer para armazenar a string resultante
 */
PERMISSOES_API void modo_para_string(mode_t modo, char str[11]);

#endif // PERMISSOES_LIB_H
