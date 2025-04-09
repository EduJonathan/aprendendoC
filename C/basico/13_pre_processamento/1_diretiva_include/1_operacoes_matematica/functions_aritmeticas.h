#ifndef FUNCTIONS_ARITMETICAS_H
// Testa se o identificador FUNCTIONS_ARITMETICAS_H não está definido. Se não estiver
// definido, o bloco de código seguinte será incluído; caso contrário, será ignorado.
#define FUNCTIONS_ARITMETICAS_H
// Define o identificador FUNCTIONS_ARITMETICAS_H, indicando que o bloco de código seguinte
// até #endif deve ser incluído.

// Protótipo de função para adição de dois números
float add(float a, float b);

// Protótipo de função para subtração de dois números
float subtract(float a, float b);

// Protótipo de função para multiplicação de dois números
float multiply(float a, float b);

// Protótipo de função para divisão de dois números
float divide(float a, float b);

#endif
// Encerra o bloco condicional iniciado por #ifndef. Tudo entre #ifndef e #endif será
// incluído apenas se o identificador FUNCTIONS_ARITMETICAS_H não estiver definido.

/**
 * A diretiva #ifndef protege contra a inclusão repetida do conteúdo do arquivo de cabeçalho.
 * Se FUNCTIONS_ARITMETICAS_H já estiver definido (ou seja, já foi incluído), as próximas
 * inclusões serão ignoradas. Esse padrão é conhecido como "guarda de inclusão" (include guard).
 * @note Tecnicamente, o nome que você for nomear o conteúdo do arquivo NÃO precisa ser exatamente
 * O nome do arquivo.
 */