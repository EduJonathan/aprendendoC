#include "../include/permissoes_lib.h"
#include <sys/stat.h>
#include <string.h>

void modo_para_string(mode_t modo, char str[11])
{
    memset(str, 0, 11);

    if (S_ISDIR(modo)) // Tipo de arquivo
        str[0] = 'd';
    else if (S_ISLNK(modo)) // Link simbólico
        str[0] = 'l';
    else
        str[0] = '-';

    // Dono
    str[1] = (modo & S_IRUSR) ? 'r' : '-';
    str[2] = (modo & S_IWUSR) ? 'w' : '-';
    str[3] = (modo & S_IXUSR) ? 'x' : '-';

    // Grupo
    str[4] = (modo & S_IRGRP) ? 'r' : '-';
    str[5] = (modo & S_IWGRP) ? 'w' : '-';
    str[6] = (modo & S_IXGRP) ? 'x' : '-';

    // Outros
    str[7] = (modo & S_IROTH) ? 'r' : '-';
    str[8] = (modo & S_IWOTH) ? 'w' : '-';
    str[9] = (modo & S_IXOTH) ? 'x' : '-';

    str[10] = '\0';
}
