#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

/**
 * A biblioteca stddef, com os tipos de dados off32_t, off64_t e off_t,
 * define tipos de dados para representar deslocamentos (offsets) em arquivos.
 * Esses tipos são usados para manipular posições em arquivos de forma portátil,
 * independentemente do sistema operacional.
 */

/**
 * @struct Usuario
 * @brief Estrutura que representa um usuário com nome, idade, saldo e sexo.
 *
 * Utilizada para demonstrar análise de padding e offsets em memória.
 */
struct Usuario
{
    char nome[50]; ///< Nome do usuário (50 bytes)
    int idade;     ///< Idade do usuário (4 bytes)
    float saldo;   ///< Saldo na conta do usuário (4 bytes)
    char sexo;     ///< Sexo do usuário (1 byte)
    // Padding esperado aqui, dependendo do alinhamento do compilador.
};

/**
 * @brief Exibe os offsets dos campos da struct `Usuario` e calcula o padding total.
 */
void mostrar_offsets()
{
    printf("=== Análise de offsets e padding ===\n");
    printf("Tamanho da struct Usuario: %zu bytes\n", sizeof(struct Usuario));
    printf("Offset de nome : %zu\n", offsetof(struct Usuario, nome));
    printf("Offset de idade: %zu\n", offsetof(struct Usuario, idade));
    printf("Offset de saldo: %zu\n", offsetof(struct Usuario, saldo));
    printf("Offset de sexo : %zu\n", offsetof(struct Usuario, sexo));
    printf("\n");

    size_t soma_campos = sizeof(char) * 50 + sizeof(int) + sizeof(float) + sizeof(char);
    printf("Soma dos tamanhos dos campos (sem padding): %zu bytes\n", soma_campos);
    printf("Padding total: %zu bytes\n", sizeof(struct Usuario) - soma_campos);
    printf("=====================================\n\n");
}

/**
 * @brief Salva os dados de um usuário no arquivo binário "dados.bin".
 *
 * @param u Ponteiro para a estrutura do usuário a ser salva.
 */
void salvar_binario(struct Usuario *u)
{
    FILE *f = fopen("dados.bin", "ab");
    if (!f)
    {
        perror("Erro ao abrir arquivo");
        return;
    }
    fwrite(u, sizeof(struct Usuario), 1, f);
    fclose(f);
}

/**
 * @brief Lê e exibe os dados armazenados no arquivo binário "dados.bin".
 */
void ler_binario()
{
    FILE *f = fopen("dados.bin", "rb");
    if (!f)
    {
        perror("Erro ao abrir arquivo");
        return;
    }
    struct Usuario u;
    printf("\n=== Dados lidos do arquivo ===\n");
    while (fread(&u, sizeof(struct Usuario), 1, f))
    {
        printf("Nome : %s\n", u.nome);
        printf("Idade: %d\n", u.idade);
        printf("Saldo: %.2f\n", u.saldo);
        printf("Sexo : %c\n", u.sexo);
        printf("------------------------------\n");
    }
    fclose(f);
}

int main(int argc, char **argv)
{
    // Definido como int, representando um offset de 32 bits
    // geralmente usado em sistemas de 32 bits.
    off32_t offset32;

    // off64_t é geralmente definido como long long ou __int64,
    // representando um offset de 64 bits, usado em sistemas de 64 bits.
    off64_t offset64;

    // off_t é um tipo genérico que pode ser definido como int, long ou long long,
    // dependendo do sistema e da implementação.
    off_t offset;

    // Exemplo de uso dos tipos off32_t, off64_t e off_t
    offset32 = 12345678;            // Exemplo de offset de 32 bits
    offset64 = 1234567890123456789; // Exemplo de offset de 64 bits
    offset = 123456789;             // Exemplo de offset genérico

    printf("Exemplo de offsets:\n");
    printf("Offset 32 bits : %ld\n", (long)offset32);
    printf("Offset 64 bits : %lld\n", (long long)offset64);
    printf("Offset genérico : %ld\n", (long)offset);

    printf("-------------------------------------\n");

    mostrar_offsets();

    struct Usuario u;
    printf("Digite nome: ");
    fgets(u.nome, sizeof(u.nome), stdin);
    u.nome[strcspn(u.nome, "\n")] = 0; // Remover \n

    printf("Digite idade: ");
    scanf("%d", &u.idade);

    printf("Digite saldo: ");
    scanf("%f", &u.saldo);

    printf("Digite sexo (M/F): ");
    scanf(" %c", &u.sexo);

    salvar_binario(&u);
    ler_binario();

    return 0;
}
