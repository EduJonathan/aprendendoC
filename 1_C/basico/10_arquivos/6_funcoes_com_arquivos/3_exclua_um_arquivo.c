#include <stdio.h>
#include <string.h>

/**
 * @brief Função para substituir espaços por underscores
 * Substitui os espaços em um nome de arquivo por underscores.
 *
 * @param nomeArquivo O nome do arquivo.
 */
void substituirEspacosPorUnderscore(char *nomeArquivo)
{
    for (int i = 0; nomeArquivo[i] != '\0'; i++)
    {
        if (nomeArquivo[i] == ' ')
        {
            nomeArquivo[i] = '_';
        }
    }
}

int main(int argc, char **argv)
{
    // Criação de 3 arquivos com nomes diferentes
    const char *arquivo1 = "Arquivo_1.txt";
    const char *arquivo2 = "Documento_2.txt";
    const char *arquivo3 = "Relatorio_3.txt";

    // Criando os arquivos
    FILE *file1 = fopen(arquivo1, "w");
    FILE *file2 = fopen(arquivo2, "w");
    FILE *file3 = fopen(arquivo3, "w");

    // Fechando os arquivos
    fclose(file1);
    fclose(file2);
    fclose(file3);

    char nomeEscolhido[100] = {0}; // Array para armazenar o nome do arquivo escolhido
    char resposta = '\0';          // Variável para controlar o loop

    do
    {
        // Exibe os arquivos disponíveis
        printf("\nArquivos disponíveis para remoção:\n");
        printf("1. %s\n", arquivo1);
        printf("2. %s\n", arquivo2);
        printf("3. %s\n", arquivo3);

        printf("\nDigite o nome do arquivo (completo ou com espaço) que deseja remover: ");
        fgets(nomeEscolhido, sizeof(nomeEscolhido), stdin);

        // Remove a nova linha que fgets pode adicionar
        nomeEscolhido[strcspn(nomeEscolhido, "\n")] = '\0';

        // Substitui espaços por underscores
        substituirEspacosPorUnderscore(nomeEscolhido);

        // Tenta remover o arquivo escolhido
        if (remove(nomeEscolhido) == 0)
        {
            printf("\nArquivo '%s' removido com sucesso.\n", nomeEscolhido);
        }
        else
        {
            printf("\nErro ao remover o arquivo '%s'. Verifique se o nome foi digitado corretamente.\n", nomeEscolhido);
        }

        // Pergunta ao usuário se deseja continuar
        printf("\nDeseja remover outro arquivo? (s/n): ");
        scanf(" %c", &resposta);
        // O espaço antes de %c é para limpar qualquer caractere de nova linha pendente.

        // Limpa o buffer de entrada para a próxima iteração
        while (getchar() != '\n');

    } while (resposta == 's' || resposta == 'S'); // Continuar se a resposta for 's' ou 'S'

    printf("\nPrograma encerrado.\n");
    return 0;
}
