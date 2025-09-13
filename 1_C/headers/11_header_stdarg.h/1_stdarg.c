#include <stdio.h>
#include <stdarg.h>

/**
 * stdarg.h: Biblioteca que fornece um mecanismo para criar funções que
 * aceitam um número variável de argumentos.
 */

/**
 * @brief Função que aceita um número variável de argumentos inteiros e retorna a soma.
 *
 * @note O operador "..." é descrito como operador de propagação(em inglês, spread operator)
 * Na linguagem C introduzido para que indique uma lista de parâmetros de uma função, recebendo
 * um números variável de argumentos, cada linguagem, como JavaScript e Python, tem seu uso
 * próprio para esta operação
 *
 * @param count O número total de argumentos inteiros a serem somados.
 * @param ... Lista de argumentos inteiros a serem somados.
 * @return A soma dos argumentos inteiros.
 */
int Var_args(int count, ...)
{
    // Variável para armazenar o resultado
    int result = 0;

    // Declara uma lista de argumentos variáveis
    va_list args;
    /*
     * va_list(): Tipo de dado usado para declarar um objeto que mantém informações
     * sobre a lista de argumentos variáveis.
     */

    // Inicializa a lista de argumentos
    va_start(args, count);
    /*
     * va_start(): macro que inicializa uma lista de argumentos variáveis. É preciso
     * passar o nome do último parâmetro fixo da função como argumento para va_start,
     * assim como o número de parâmetros fixos antes dos parâmetros variáveis.
     */

    // Itera sobre os argumentos e os adiciona à soma
    for (int i = 0; i < count; i++)
    {
        // Adiciona o argumento ao resultado
        result += va_arg(args, int);
        /*
         * va_arg(): macro usada para acessar o próximo argumento na lista.
         * Ela recebe a va_list e o tipo do próximo argumento na lista.
         */
    }

    va_end(args);
    /*
     * va_end(): macro que deve ser chamada para finalizar o uso da lista de
     * argumentos variáveis. Ela recebe a va_list e realiza as operações necessárias
     * para encerrar o uso seguro da lista.
     */
    return result;
}

int Var_copy(int count, ...)
{
    int result = 0;

    // Inicializa a lista de argumentos
    va_list args;
    va_start(args, count);

    // Cria uma cópia da lista de argumentos
    va_list args_copy;

    /*
     * va_copy(): É usado para criar uma cópia da lista de argumentos args. A cópia
     * é usada para iterar sobre os argumentos e realizar a soma, enquanto a lista
     * original permanece inalterada. pode ser útil em situações em que você precisa
     * reutilizar a lista original de argumentos após ter feito uma cópia dela.
     */
    va_copy(args_copy, args);

    // Itera sobre os argumentos da cópia e os adiciona à soma
    for (int i = 0; i < count; i++)
    {
        result += va_arg(args_copy, int);
    }

    // Finaliza a cópia da lista de argumentos
    va_end(args_copy);

    // Finaliza a lista de argumentos original
    va_end(args);

    return result;
}

int main(int argc, char **argv)
{
    printf("Soma: %d\n", Var_args(4, 25, 25, 50, 50));
    printf("Soma: %d\n", Var_copy(4, 25, 25, 50, 50));
    return 0;
}
