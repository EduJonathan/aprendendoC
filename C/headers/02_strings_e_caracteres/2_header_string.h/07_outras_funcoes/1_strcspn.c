#include <stdio.h>
#include <string.h>

/**
 * strcspn(): Função encontra a posição do caractere de '\n' e substitui por '\0' (terminador nulo).
 *
 * SINTAXE: size_t strcspn(const char *_Str, const char *_Control);
 *
 * @param _Str Ponteiro para char informada
 * @param _Control Subtituição do caractere de controle '\n' por '\0'.
 * @return Retorna um ponteiro para a primeira ocorrência de um caractere da string de busca
 * na string fornecida ou NULL se nenhuma ocorrência for encontrada.
 */

/**
 * @brief Remove o caractere de nova linha de uma string, se presente.
 *
 * Esta função procura um caractere de nova linha na string e o substitui
 * pelo terminador nulo para tratar corretamente a entrada do usuário.
 *
 * @param str Ponteiro para a string da qual remover o caractere de nova linha.
 */
void removeNewline(char *str)
{
    str[strcspn(str, "\n")] = '\0';
}

/**
 * @brief Lê uma linha de entrada do usuário para um buffer.
 *
 * Esta função solicita a entrada do usuário e armazena o resultado no buffer fornecido.
 * Utilizando fgets para ler a entrada de forma segura e depois remove qualquer caractere de
 * nova linha.
 *
 * @param buffer Ponteiro para o buffer onde a entrada será armazenada.
 * @param size Tamanho do buffer.
 */
void leituraDaString(char *buffer, size_t size)
{
    printf("Digite o nome: ");
    fgets(buffer, size, stdin);
    removeNewline(buffer);
}

/**
 * @brief Imprime o conteúdo de uma string com seus índices e endereços.
 *
 * Esta função itera pelos caracteres da string, imprimindo cada caractere,
 * seu índice e seu endereço de memória.
 *
 * @param str Ponteiro para a string a ser impressa.
 */
void imprimeDetalhesDaString(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        printf("Índice: %d\tConteúdo: %c\tEndereço: %p\n", i, str[i], (void *)&str[i]);
    }
}

int main(int argc, char **argv)
{
    char nome[10];
    char sobreNome[10];

    // Lê e processa o primeiro nome
    leituraDaString(nome, sizeof(nome));
    imprimeDetalhesDaString(nome);

    // Lê e processa o sobrenome
    leituraDaString(sobreNome, sizeof(sobreNome));
    imprimeDetalhesDaString(sobreNome);

    // Imprime o nome completo
    printf("%s %s\n", nome, sobreNome);
    return 0;
}
