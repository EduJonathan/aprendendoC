#ifndef PRINTLN_H
#define PRINTLN_H

/**
 * @brief Imprime uma string no stdout com quebra de linha automática.
 * Implementação 100% Assembly usando syscall write (Linux x86_64).
 *
 * O diferencial dessa função será sua implementação que em vez de utilizar escopo de função, ou seja:
 *
 * `int _println(const char *fmt, ...) { // implementação }`,
 *
 * o controle dessa função será realizado 100% pela linguagem assembly, linkada através da biblioteca estática.
 * No momento o código não possue implementação para outros formatores `(%d, %s, %c, etc)`.
 * Futuramente será implementado suporte para esses formatos.
 *
 * @param fmt A string de formato que pode conter especificadores de formato.
 * @param ... Argumentos adicionais para formatação, se necessário.
 * @return Retorna o número de caracteres impressos, excluindo o caractere nulo final.
 */
int _println(const char *str);

#endif // PRINTLN_H
