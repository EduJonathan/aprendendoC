#include <stdio.h>

int main(int argc, char **arv)
{
    char string[10] = {0}; /* Vetor de 10 posições para armazenar o nome do usuário */

    // Solicita o nome do usuário
    printf("Digite seu nome: ");
    gets(string); // ⚠️ Função insegura: veja explicação abaixo.

    // Exibe o nome lido
    printf("%s\n", string);

    /**
     * ### Por que `gets()` é insegura
     *
     * `gets()` lê caracteres da entrada padrão até encontrar um `\n` (Enter),
     * mas **não tem limite de leitura**. Isso permite que o usuário digite mais
     * caracteres do que o vetor comporta, sobrescrevendo áreas de memória e
     * causando *buffer overflow* (comportamento indefinido).
     *
     * Exemplo: vetor de 10 bytes (`char string[10]`):
     *
     * Digitação: "eduardo jonathan"
     *
     * Posições reais escritas:
     * ['e']['d']['u']['a']['r']['d']['o'][' ']['j']['o']['\0']
     *   0    1    2    3    4    5    6    7    8    9   10  ← já fora do limite
     *
     * O compilador costuma emitir aviso: **"warning: the 'gets' function is dangerous
     * and should not be used"**.
     *
     * ### Alternativa segura: `fgets()`
     *
     * `fgets()` permite limitar a quantidade de caracteres lidos e mantém o `\n`
     * final (que pode ser removido se necessário):
     *
     * ```c
     * if (fgets(string, sizeof(string), stdin)) {
     *     string[strcspn(string, "\n")] = '\0'; // remove o '\n' se existir
     * }
     * ```
     *
     * Assim, evita-se escrever além do tamanho do vetor.
     *
     * **Importante**: Strings em C **sempre terminam com `'\0'`**.
     */

    printf("\n-----------------------------------------------------\n");

    /* Mostra índice, conteúdo e endereço de cada caractere da string lida */
    for (int i = 0; string[i] != '\0'; i++)
    {
        printf("Índice: %d\tConteúdo: %c\tEndereço: %p\n", i, string[i], (void *)&string[i]);
    }

    return 0;
}
