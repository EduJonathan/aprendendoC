#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    // Alocação do nome do funcionário
    funcionario->nome = (char *)malloc(100 * sizeof(char));

    // Leitura dos dados do funcionário
    printf("Digite o ID do funcionario: ");
    scanf("%d", &funcionario->id);

    // Consumindo o caractere de nova linha deixado pelo scanf
    getchar(); // Limpa o '\n' do buffer

    printf("Digite o nome do funcionario: ");
    fgets(funcionario->nome, 100, stdin);

    // Remover o caractere de nova linha '\n' que fgets pode deixar
    size_t len = strlen(funcionario->nome);
    if (len > 0 && funcionario->nome[len - 1] == '\n')
    {
        funcionario->nome[len - 1] = '\0';
    }

    // Escreve o ID e o nome no arquivo
    fwrite(&funcionario->id, sizeof(funcionario->id), 1, fp);
    fwrite(funcionario->nome, strlen(funcionario->nome) + 1, 1, fp); // Inclui o '\0' no nome
}

/**
 * @brief Atualiza o nome de um funcionário no arquivo com base no seu ID.
 *
 * @param fp Ponteiro para o arquivo que contém os dados dos funcionários.
 * @param funcionario Ponteiro para o struct funcionario que será utilizado para leitura dos dados.
 *
 * @note Este método fecha o arquivo após a atualização. Se o ID não for encontrado,
 * uma mensagem informando que o funcionário não foi encontrado será exibida.
 */
void atualizar(FILE *fp, struct funcionario *funcionario)
{
    int id, flag = 0;
    char nome[100];
    FILE *temp_fp;

    if (fp == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return;
    }

    // Cria um arquivo temporário para armazenar os dados atualizados
    temp_fp = fopen("temp.dat", "wb");
    if (temp_fp == NULL)
    {
        perror("Erro ao criar o arquivo temporário");
        return;
    }

    printf("Digite o ID do funcionario a ser atualizado: ");
    scanf("%d", &id);

    fseek(fp, 0, SEEK_SET); // Vai para o início do arquivo

    // Percorrer o arquivo original para encontrar o funcionário
    while (fread(&funcionario->id, sizeof(funcionario->id), 1, fp))
    {
        funcionario->nome = (char *)malloc(100 * sizeof(char));
        fread(funcionario->nome, 100, 1, fp); // Lê o nome do funcionário

        if (id == funcionario->id)
        {
            printf("Funcionario encontrado. Digite o novo nome: ");
            getchar(); // Limpa o '\n' deixado pelo scanf
            fgets(nome, 100, stdin);
            nome[strcspn(nome, "\n")] = '\0'; // Remove o '\n' se presente

            // Escreve os dados atualizados no arquivo temporário
            fwrite(&funcionario->id, sizeof(funcionario->id), 1, temp_fp);
            fwrite(nome, strlen(nome) + 1, 1, temp_fp); // Inclui o '\0' no nome

            flag = 1;
        }
        else
        {
            // Escreve o dado original no arquivo temporário, se não for o funcionário a ser atualizado
            fwrite(&funcionario->id, sizeof(funcionario->id), 1, temp_fp);
            fwrite(funcionario->nome, strlen(funcionario->nome) + 1, 1, temp_fp); // Inclui o '\0' no nome
        }

        free(funcionario->nome); // Libera a memória alocada para o nome
    }

    if (flag == 0)
    {
        printf("Funcionario com o ID %d nao encontrado.\n", id);
    }

    // Fecha os arquivos
    fclose(fp);
    fclose(temp_fp);

    // Substitui o arquivo original pelo temporário
    remove("funcionarios.dat");
    rename("temp.dat", "funcionarios.dat");

    printf("Funcionario atualizado com sucesso.\n");
}

/**
 * @brief Exibe todos os funcionarios armazenados no arquivo.
 *
 * @param fp Ponteiro para o arquivo.
 * @param funcionario Ponteiro para o struct funcionario.
 *
 * @note Este metodo fecha o arquivo.
 */
void exibir(FILE *fp, struct funcionario *funcionario)
{
    if (fp == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return;
    }

    fseek(fp, 0, SEEK_SET); // Vai para o início do arquivo

    // Loop para ler todos os funcionários armazenados no arquivo
    while (fread(&funcionario->id, sizeof(funcionario->id), 1, fp))
    {
        // Aloca memória para o nome de cada funcionário
        funcionario->nome = (char *)malloc(100 * sizeof(char));

        // Lê o nome do funcionário. A quantidade lida deve ser o tamanho máximo de 100
        fread(funcionario->nome, 100, 1, fp);

        printf("ID: %d\n", funcionario->id);
        printf("Nome: %s\n", funcionario->nome);

        // Libera a memória alocada para o nome
        free(funcionario->nome);
    }

    fclose(fp);
}

int main(int argc, char **argv)
{
    FILE *fp;
    struct funcionario funcionario;
    int opcao;

    do
    {
        printf("\nEscolha uma opcao:\n");
        printf("1. Criar funcionario\n");
        printf("2. Exibir funcionarios\n");
        printf("3. Atualizar funcionario\n");
        printf("4. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            fp = fopen("funcionarios.dat", "ab+"); // Abrir o arquivo para adicionar novos dados
            if (fp == NULL)
            {
                printf("Erro ao abrir o arquivo.\n");
                return 1;
            }
            criarFuncionario(fp, &funcionario);
            fclose(fp);
            break;

        case 2:
            fp = fopen("funcionarios.dat", "rb"); // Abrir o arquivo para leitura
            if (fp == NULL)
            {
                printf("Erro ao abrir o arquivo.\n");
                return 1;
            }
            exibir(fp, &funcionario);
            fclose(fp);
            break;

        case 3:
            fp = fopen("funcionarios.dat", "rb+"); // Abrir o arquivo para leitura e escrita
            if (fp == NULL)
            {
                printf("Erro ao abrir o arquivo.\n");
                return 1;
            }
            atualizar(fp, &funcionario);
            break;

        case 4:
            printf("Saindo...\n");
            break;

        default:
            printf("Opcao invalida! Tente novamente.\n");
            break;
        }

    } while (opcao != 4);

    return 0;
}
