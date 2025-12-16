#include "../include/permissoes_lib.h"
#include <stdio.h>
#include <sys/stat.h> // Para a estrutura stat e a função stat
#include <unistd.h>   // Para a função stat
#include <pwd.h>      // Para obter nome de usuário e ID do usuário, através de getpwuid
#include <grp.h>      // Para obter nome de grupo e ID do grupo, através de getgrgid

/**
 * Para Compilar este programa siga estes passos estando na pasta raiz do projeto "projeto_permissoes_de_arquivos":
 *
 * 1. Compile a biblioteca estática ou dinâmica primeiro (conforme instruções na respectiva pasta).
 *
 * # Recompila a biblioteca (importante recompilar depois de adicionar _GNU_SOURCE)
 * gcc -fPIC -shared -o lib/libpermissoes.so src/permissoes_lib.c -I./include
 *
 * 2. Compile este programa com o comando:
 * gcc -o main src/main.c -L./lib -lpermissoes -Wl,-rpath,'$ORIGIN/lib' -I./include
 *
 * 3. Teste(aqui é um caso onde você deve ter um arquivo chamado "arquivo.txt" no mesmo diretório):
 * caso não tenha, crie um arquivo de teste com o comando dentro do diretório raiz do projeto:
 * catch > arquivo.txt
 * mas por curiosidade, você pode testar com qualquer arquivo que tenha em seu sistema basta pecorrer o caminho correto.
 *
 * 4. Execute o programa:
 * ./main arquivo.txt
 *
 * 5. Executando com outro arquivo:
 * ./main ~/Documentos/aprendendoC/4_biblioteca_estaticas_dinamicas/projeto_permissoes_de_arquivos/lib/libpermissoes.so
 */

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Uso: %s <nome_do_arquivo>\n", argv[0]);
        return 1;
    }

    struct stat file_stat;
    char permissions_str[11];
    struct passwd *pw = NULL;
    struct group *gr = NULL;

    if (stat(argv[1], &file_stat) == -1)
    {
        perror("Erro ao obter estatísticas do arquivo");
        return 2;
    }

    modo_para_string(file_stat.st_mode, permissions_str);

    pw = getpwuid(file_stat.st_uid);
    gr = getgrgid(file_stat.st_gid);

    printf("--- Permissões e Detalhes do Arquivo: %s ---\n", argv[1]);
    printf("Formato Simbólico: %s\n", permissions_str);
    printf("Formato Octal:     %o\n", file_stat.st_mode & 0777);

    printf("Proprietário: %s (UID: %d)\n", pw ? pw->pw_name : "Desconhecido", file_stat.st_uid);
    printf("Grupo: %s (GID: %d)\n", gr ? gr->gr_name : "Desconhecido", file_stat.st_gid);
    printf("Tamanho (bytes):   %lld\n", (long long)file_stat.st_size);

    /**
     * Para compilar no windows, siga estes passos:
     *
     * Windows (MinGW):
     * > gcc -DBUILDING_PERMISSOES_LIB -shared -o lib/permissoes.dll src/permissoes_lib.c ^c -Wl,--out-implib,lib/libpermissoes.a
     *
     * > Compilar o main.c
     * gcc -o main.exe src/main.c -L./lib -lpermissoes
     *
     * > Executar
     * main.exe arquivo.txt
     *
     * > Executar com outro arquivo
     * main.exe C:\caminho\para\seu\arquivo.txt
     */
    return 0;
}
