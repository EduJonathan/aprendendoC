#define _GNU_SOURCE // <--- ESSA LINHA É ESSENCIAL para S_ISUID, S_ISGID, S_ISVTX

#include "../include/permissoes_lib.h"
#include <sys/stat.h>
#include <string.h>

PERMISSOES_API void modo_para_string(mode_t modo, char str[11])
{
    // Preenche com hífens nas posições de permissão (índices 1 a 9)
    memset(str, '-', 10);
    str[10] = '\0';

    // Tipo de arquivo
    if (S_ISREG(modo))
        str[0] = '-';
    else if (S_ISDIR(modo))
        str[0] = 'd';
    else if (S_ISLNK(modo))
        str[0] = 'l';
    else if (S_ISCHR(modo))
        str[0] = 'c';
    else if (S_ISBLK(modo))
        str[0] = 'b';
    else if (S_ISFIFO(modo))
        str[0] = 'p';
    else if (S_ISSOCK(modo))
        str[0] = 's';
    else
        str[0] = '?';

    // Permissões básicas
    if (modo & S_IRUSR)
        str[1] = 'r';
    if (modo & S_IWUSR)
        str[2] = 'w';
    if (modo & S_IXUSR)
        str[3] = 'x';

    if (modo & S_IRGRP)
        str[4] = 'r';
    if (modo & S_IWGRP)
        str[5] = 'w';
    if (modo & S_IXGRP)
        str[6] = 'x';

    if (modo & S_IROTH)
        str[7] = 'r';
    if (modo & S_IWOTH)
        str[8] = 'w';
    if (modo & S_IXOTH)
        str[9] = 'x';

    // Bits especiais: setuid, setgid, sticky bit
    if (modo & S_ISUID)
    {
        if (modo & S_IXUSR)
            str[3] = 's';
        else
            str[3] = 'S';
    }
    if (modo & S_ISGID)
    {
        if (modo & S_IXGRP)
            str[6] = 's';
        else
            str[6] = 'S';
    }
    if (modo & S_ISVTX)
    {
        if (modo & S_IXOTH)
            str[9] = 't';
        else
            str[9] = 'T';
    }
}
