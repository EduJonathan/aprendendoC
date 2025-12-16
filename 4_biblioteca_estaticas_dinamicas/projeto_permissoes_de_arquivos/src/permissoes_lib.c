#define _GNU_SOURCE // <--- ESSA LINHA É ESSENCIAL para S_ISUID, S_ISGID, S_ISVTX

#include "../include/permissoes_lib.h"
#include <sys/stat.h>
#include <string.h>

PERMISSOES_API void modo_para_string(mode_t modo, char str[11])
{
    memset(str, '-', 10);
    str[10] = '\0';

    // Tipo de arquivo usando switch
    switch (modo & S_IFMT)
    {
    case S_IFREG:
        str[0] = '-';
        break;

    case S_IFDIR:
        str[0] = 'd';
        break;

    case S_IFLNK:
        str[0] = 'l';
        break;

    case S_IFCHR:
        str[0] = 'c';
        break;

    case S_IFBLK:
        str[0] = 'b';
        break;

    case S_IFIFO:
        str[0] = 'p';
        break;

    case S_IFSOCK:
        str[0] = 's';
        break;

    default:
        str[0] = '?';
        break;
    }

    // Permissões do dono
    if (modo & S_IRUSR)
        str[1] = 'r';
    if (modo & S_IWUSR)
        str[2] = 'w';
    if (modo & S_IXUSR)
        str[3] = 'x';

    // Grupo
    if (modo & S_IRGRP)
        str[4] = 'r';
    if (modo & S_IWGRP)
        str[5] = 'w';
    if (modo & S_IXGRP)
        str[6] = 'x';

    // Outros
    if (modo & S_IROTH)
        str[7] = 'r';
    if (modo & S_IWOTH)
        str[8] = 'w';
    if (modo & S_IXOTH)
        str[9] = 'x';

    // Bits especiais (setuid, setgid, sticky)
    if (modo & S_ISUID)
        str[3] = (modo & S_IXUSR) ? 's' : 'S';
    if (modo & S_ISGID)
        str[6] = (modo & S_IXGRP) ? 's' : 'S';
    if (modo & S_ISVTX)
        str[9] = (modo & S_IXOTH) ? 't' : 'T';
}
