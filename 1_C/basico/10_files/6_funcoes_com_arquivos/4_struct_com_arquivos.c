#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // Para mkstemp()

#define MAX_NOME 100

struct funcionario
{
    int id;
    char *nome;
};

/**
 * @brief Cria um novo funcionário e o grava no arquivo.
 *
 * @param fp Ponteiro para o arquivo.
 * @param funcionario Ponteiro para o struct funcionario.
 *
 * @note Este método não fecha o arquivo.
 */
void criarFuncionario(FILE *fp, struct funcionario *funcionario)
{
    funcionario->nome = (char *)malloc(MAX_NOME * sizeof(char));
    if (!funcionario->nome)
    {
        perror("Erro ao alocar memória");
        return;
    }

    printf("Digite o ID do funcionario: ");
    if (scanf("%d", &funcionario->id) != 1)
    {
        printf("Erro ao ler ID.\n");
        free(funcionario->nome);
        return;
    }

    getchar(); // Limpa o '\n' do buffer

    printf("Digite o nome do funcionario: ");
    if (!fgets(funcionario->nome, MAX_NOME, stdin))
    {
        printf("Erro ao ler nome.\n");
        free(funcionario->nome);
        return;
    }

    // Remove o '\n' e calcula o tamanho real
    size_t len = strlen(funcionario->nome);
    if (len > 0 && funcionario->nome[len - 1] == '\n')
    {
        funcionario->nome[len - 1] = '\0';
        len--;
    }

    // Grava ID e nome (com '\0')
    if (fwrite(&funcionario->id, sizeof(funcionario->id), 1, fp) != 1 ||
        fwrite(funcionario->nome, len + 1, 1, fp) != 1)
    {
        perror("Erro ao gravar no arquivo");
    }

    free(funcionario->nome); // Libera a memória após uso
}

/**
 * @brief Atualiza o nome de um funcionário no arquivo.
 *
 * @param fp Ponteiro para o arquivo.
 * @param funcionario Ponteiro para o struct funcionario.
 */
void atualizar(FILE *fp, struct funcionario *funcionario)
{
    int id, encontrado = 0;
    char temp_filename[] = "/tmp/funcionarios_temp_XXXXXX";
    FILE *temp_fp = NULL;
    int fd = -1;

    printf("Digite o ID do funcionario a ser atualizado: ");
    if (scanf("%d", &id) != 1)
    {
        printf("Erro ao ler ID.\n");
        return;
    }

    // Cria arquivo temporário seguro, usando mkstemp para evitar colisões de nomes
    // e o fdopen é para associar o descritor de arquivo a um ponteiro FILE.
    if ((fd = mkstemp(temp_filename)) == -1 || (temp_fp = fdopen(fd, "wb")) == NULL)
    {
        perror("Erro ao criar arquivo temporário");
        if (fd != -1)
            close(fd);
        return;
    }

    rewind(fp); // Volta ao início do arquivo

    while (fread(&funcionario->id, sizeof(funcionario->id), 1, fp) == 1)
    {
        // Lê nome até encontrar '\0'
        funcionario->nome = (char *)malloc(MAX_NOME);
        if (!funcionario->nome)
        {
            perror("Erro ao alocar memória");
            fclose(temp_fp);
            remove(temp_filename);
            return;
        }

        int i = 0;
        do
        {
            if (fread(&funcionario->nome[i], 1, 1, fp) != 1)
            {
                free(funcionario->nome);
                fclose(temp_fp);
                remove(temp_filename);
                perror("Erro ao ler nome");
                return;
            }
        } while (funcionario->nome[i++] != '\0' && i < MAX_NOME);

        if (funcionario->id == id)
        {
            encontrado = 1;
            printf("Funcionario encontrado. Nome atual: %s\n", funcionario->nome);
            printf("Digite o novo nome: ");

            getchar(); // Limpa buffer
            if (!fgets(funcionario->nome, MAX_NOME, stdin))
            {
                printf("Erro ao ler novo nome.\n");
                free(funcionario->nome);
                continue;
            }

            // Remove '\n' e recalcula tamanho
            size_t len = strlen(funcionario->nome);
            if (len > 0 && funcionario->nome[len - 1] == '\n')
            {
                funcionario->nome[len - 1] = '\0';
                len--;
            }

            printf("Novo nome: %s\n", funcionario->nome);
        }

        // Grava no arquivo temporário (ID + nome com '\0')
        if (fwrite(&funcionario->id, sizeof(funcionario->id), 1, temp_fp) != 1 ||
            fwrite(funcionario->nome, strlen(funcionario->nome) + 1, 1, temp_fp) != 1)
        {
            perror("Erro ao gravar no arquivo temporário");
            free(funcionario->nome);
            fclose(temp_fp);
            remove(temp_filename);
            return;
        }

        free(funcionario->nome);
    }

    fclose(fp);
    fclose(temp_fp);

    if (!encontrado)
    {
        printf("Funcionario com ID %d não encontrado.\n", id);
        remove(temp_filename);
    }
    else
    {
        // Substitui arquivo original
        remove("funcionarios.dat");
        if (rename(temp_filename, "funcionarios.dat") != 0)
        {
            perror("Erro ao renomear arquivo");
            remove(temp_filename);
        }
        else
        {
            printf("Atualização concluída com sucesso.\n");
        }
    }
}

/**
 * @brief Exibe todos os funcionários do arquivo.
 *
 * @param fp Ponteiro para o arquivo.
 * @param funcionario Ponteiro para o struct funcionario.
 */
void exibir(FILE *fp, struct funcionario *funcionario)
{
    rewind(fp);

    printf("\n--- Funcionários Cadastrados ---\n");
    while (fread(&funcionario->id, sizeof(funcionario->id), 1, fp) == 1)
    {
        funcionario->nome = (char *)malloc(MAX_NOME);
        if (!funcionario->nome)
        {
            perror("Erro ao alocar memória");
            continue;
        }

        // Lê até '\0'
        int i = 0;
        do
        {
            if (fread(&funcionario->nome[i], 1, 1, fp) != 1)
            {
                free(funcionario->nome);
                perror("Erro ao ler nome");
                break;
            }
        } while (funcionario->nome[i++] != '\0' && i < MAX_NOME);

        printf("ID: %d, Nome: %s\n", funcionario->id, funcionario->nome);
        free(funcionario->nome);
    }
    printf("-------------------------------\n");
    fclose(fp);
}

int main(int argc, char **argv)
{
    FILE *fp = NULL;
    struct funcionario func = {0};
    int opcao = 0;

    do
    {
        printf("\nMenu:\n");
        printf("1. Criar funcionario\n");
        printf("2. Exibir funcionarios\n");
        printf("3. Atualizar funcionario\n");
        printf("4. Sair\n");
        printf("Opcao: ");

        if (scanf("%d", &opcao) != 1)
        {
            printf("Entrada inválida.\n");
            while (getchar() != '\n'); // Limpa buffer
            continue;
        }

        switch (opcao)
        {
        case 1:
            fp = fopen("funcionarios.dat", "ab");
            if (!fp)
            {
                perror("Erro ao abrir arquivo");
                break;
            }
            criarFuncionario(fp, &func);
            fclose(fp);
            break;

        case 2:
            fp = fopen("funcionarios.dat", "rb");
            if (!fp)
            {
                perror("Erro ao abrir arquivo");
                break;
            }
            exibir(fp, &func);
            break;

        case 3:
            fp = fopen("funcionarios.dat", "rb+");
            if (!fp)
            {
                perror("Erro ao abrir arquivo");
                break;
            }
            atualizar(fp, &func);
            break;

        case 4:
            printf("Saindo...\n");
            break;

        default:
            printf("Opção inválida.\n");
        }
    } while (opcao != 4);

    return 0;
}
