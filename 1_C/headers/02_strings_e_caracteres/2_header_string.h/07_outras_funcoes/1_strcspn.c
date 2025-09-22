#include <stdio.h>
#include <string.h>

/**
 * A função `strcspn()` encontra a posição do primeiro caractere na string `_Str` que
 * corresponde a qualquer caractere presente em `_Control`. Ela retorna o número de
 * caracteres desde o início de `_Str` até o primeiro caractere que está presente em `_Control`.
 *
 * Se nenhum caractere de `_Str` for encontrado em `_Control`, a função retorna o comprimento
 * total de `_Str`.
 *
 * @param _Str Ponteiro para a string a ser analisada.
 * @param _Control Ponteiro para a string de controle, contendo os caracteres a serem evitados em `_Str`.
 *
 * @return O número de caracteres iniciais de `_Str` que não estão presentes em `_Control`.
 * Se nenhum caractere de `_Str` for encontrado em `_Control`, a função retorna o comprimento total de `_Str`.
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
    char nome[10] = {0};      /**< String para armazenar o nome */
    char sobreNome[10] = {0}; /**< String para armazenar o sobrenome */

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
