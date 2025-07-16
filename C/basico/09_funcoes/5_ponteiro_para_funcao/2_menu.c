#include <stdio.h>

/**
 * @brief Função que simula a operação de cortar.
 *
 * @param cortar Valor inteiro representando a escolha do usuário.
 */
void cut(int cortar)
{
    printf("Você selecionou %d.\n", cortar);
    printf("Item cortar ativado.\n");
}

/**
 * @brief Função que simula a operação de copiar.
 *
 * @param copiar Valor inteiro representando a escolha do usuário.
 */
void copy(int copiar)
{
    printf("Você selecionou %d.\n", copiar);
    printf("Item copiar ativado.\n");
}

/**
 * @brief Função que simula a operação de colar.
 *
 * @param colar Valor inteiro representando a escolha do usuário.
 */
void paste(int colar)
{
    printf("Você selecionou %d.\n", colar);
    printf("Item colar ativado.\n");
}

/**
 * @brief Função que simula a operação de deletar.
 *
 * @param deletar Valor inteiro representando a escolha do usuário.
 */
void delete(int deletar)
{
    printf("Você selecionou %d.\n", deletar);
    printf("Item deletar ativado.\n");
}

int main(int argc, char **argv)
{
    void (*menu[4])(int) = {cut, copy, paste, delete};
    int escolha = 0;

    printf("Escolha um valor (1-para cortar, 2-para copiar, 3-para colar, 4-deletar): ");
    scanf("%d", &escolha);

    // Verifica se a escolha está dentro do intervalo válido
    if (escolha < 1 || escolha > 4)
    {
        printf("Escolha valores de intervalos entre 1 e 4\n");
        return 1; // Encerra o programa com código de erro
    }

    // Ajusta o índice para começar em 0
    (*menu[escolha - 1])(escolha);

    return 0;
}
