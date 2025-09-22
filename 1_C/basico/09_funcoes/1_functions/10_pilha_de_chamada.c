#include <stdio.h>
#include <time.h>

/**
 * @brief Conceito de Pilha de Chamada (Call Stack).
 *
 * **O que é**
 * - A *pilha de chamada* é uma área de memória usada pelo sistema para controlar
 *   a execução de funções.
 * - Sempre que uma função é invocada, o compilador/tempo de execução cria um
 *   *quadro de ativação* (*stack frame*), que é empilhado no topo da pilha.
 *
 * **O que o quadro de ativação contém**
 * - Endereço de retorno: indica para onde o programa deve voltar após a
 *   conclusão da função.
 * - Parâmetros da função: valores passados na chamada.
 * - Variáveis locais: variáveis declaradas dentro da função.
 *
 * **Funcionamento**
 * - Quando a função termina, seu quadro é removido (*desempilhado*), e o
 *   controle retorna para a função chamadora, utilizando o endereço de retorno
 *   armazenado.
 *
 * **Por que é importante entender**
 * - Ajuda a evitar problemas de desempenho e uso excessivo de memória.
 * - Em funções recursivas, profundidade excessiva pode causar *stack overflow*
 *   (estouro da pilha).
 * - Conhecimento da pilha permite aplicar técnicas como *tail call optimization*,
 *   que podem reduzir o consumo de memória eliminando quadros desnecessários
 *   em chamadas recursivas de cauda.
 */

/**
 * @brief Exibe a profundidade atual da pilha com o nome da função.
 *
 * @param profundidade Nível atual da pilha.
 * @param nome_funcao Nome da função para contexto.
 */
void exibirProfundidade(int profundidade, const char *nome_funcao)
{
    // %*s funciona como indentação dinâmica baseada no valor passado antes da string.
    // profundidade * 2 define a largura mínima (número de caracteres) a ser impressa.
    // "" → é a string a ser impressa, aqui uma string vazia.
    // O efeito prático: imprime espaços em branco até completar a largura,
    // criando um recuo proporcional à profundidade.
    printf("%*s> %s (Profundidade: %d)\n", profundidade * 2, "", nome_funcao, profundidade);
}

/**
 * @brief Função de nível 3 (folha da chamada).
 *
 * @param profundidade Nível atual da pilha.
 * @return Novo valor da profundidade após a execução.
 */
int chamada3(int profundidade)
{
    profundidade++;
    exibirProfundidade(profundidade, "chamada3");
    return profundidade - 1;
}

/**
 * @brief Função de nível 2, chama chamada3.
 *
 * @param profundidade Nível atual da pilha.
 * @return Novo valor da profundidade após a execução.
 */
int chamada2(int profundidade)
{
    profundidade++;
    exibirProfundidade(profundidade, "chamada2");
    profundidade = chamada3(profundidade);
    return profundidade - 1;
}

/**
 * @brief Função de nível 1, chama chamada2.
 *
 * @param profundidade Nível atual da pilha.
 * @return Novo valor da profundidade após a execução.
 */
int chamada1(int profundidade)
{
    profundidade++;
    exibirProfundidade(profundidade, "chamada1");
    profundidade = chamada2(profundidade);
    return profundidade - 1;
}

/**
 * @brief Lê o ano de nascimento do usuário com validação.
 *
 * @return Ano de nascimento válido ou -1 em caso de erro.
 */
int lerAno(void)
{
    int ano = 0;
    printf("\nDigite o ano de nascimento (1900-%d): ", (int)(time(NULL) / 31556926) + 1970);
    if (scanf("%d", &ano) != 1 || ano < 1900 || ano > (int)(time(NULL) / 31556926) + 1970)
    {
        fprintf(stderr, "Ano inválido\n");
        while (getchar() != '\n'); // Limpa o buffer
        return -1;
    }
    while (getchar() != '\n'); // Limpa o buffer
    return ano;
}

/**
 * @brief Calcula a idade com base no ano de nascimento e no ano atual.
 *
 * @param ano Ano de nascimento.
 * @return Idade ou -1 se inválido.
 */
int calcularIdade(int ano)
{
    if (ano < 0)
        return -1;

    time_t t = time(NULL);
    struct tm *dataAtual = localtime(&t);

    if (dataAtual == NULL)
    {
        fprintf(stderr, "Erro ao obter data atual\n");
        return -1;
    }
    int anoAtual = dataAtual->tm_year + 1900;
    int idade = anoAtual - ano;
    if (idade < 0 || idade > 150)
        return -1; // Validação de idade
    return idade;
}

/**
 * @brief Exibe a idade calculada.
 *
 * @param idade Idade do usuário.
 * @return 0 se exibido com sucesso, -1 se inválido.
 */
int exibirIdade(int idade)
{
    if (idade < 0)
    {
        fprintf(stderr, "Idade inválida\n");
        return -1;
    }
    printf("Você tem %d anos\n", idade);
    return 0;
}

/**
 * @brief Calcula o fatorial de n usando recursão e exibe a profundidade da pilha.
 *
 * @param n Número para calcular o fatorial.
 * @param profundidade Nível atual da pilha.
 * @return Fatorial de n.
 */
unsigned long long fatorial(int n, int profundidade)
{
    exibirProfundidade(profundidade, "fatorial");
    if (n <= 1)
        return 1;
    return n * fatorial(n - 1, profundidade + 1);
}

int main(int argc, char **argv)
{
    // Demonstração da pilha de chamada
    chamada1(0);

    /**
     * Ordem das chamadas de função
     * main()
     * |--------chamada1()
     *          |--------chamada2()
     *                  |--------chamada3()
     */

    // Demonstração da pilha de chamada (recursiva)
    printf("\nDemonstração da pilha de chamada (recursiva - fatorial de 5):\n");
    unsigned long long resultado = fatorial(5, 1);
    printf("Fatorial de 5 = %llu\n", resultado);

    /**
     * Ordem das chamadas de função (recursiva)
     * main()
     * |--------fatorial(5)
     *          |--------fatorial(4)
     *                  |--------fatorial(3)
     *                          |--------fatorial(2)
     *                                  |--------fatorial(1)
     */

    // Cálculo e exibição da idade
    int ano = lerAno(); // A função só irá sair após o valor de entrada
    int idade = calcularIdade(ano);
    exibirIdade(idade);
    return 0;
}
