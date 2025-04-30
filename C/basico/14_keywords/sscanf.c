#include <stdio.h>
#include <stdbool.h>

/**
 * SSCANF: A função `sscanf` é parte da biblioteca padrão de C e permite ler e interpretar
 * dados de uma string, funcionando de maneira semelhante ao `scanf`, mas em vez de ler
 * da entrada padrão (como o teclado), ela processa uma cadeia de caracteres que é passada
 * como argumento. Essa abordagem é útil para processar strings formatadas, como logs,
 * configurações, mensagens e outras fontes de dados em formato específico.
 *
 * Sintaxe: int sscanf(const char *str, const char *format, ...);
 *
 * Parâmetros:
 * - `str`: A string que contém os dados a serem lidos.
 * - `format`: A string de formato, que especifica como os dados devem ser interpretados.
 * - Os parâmetros adicionais (`...`) são as variáveis onde os dados lidos serão armazenados.
 *
 * Retorno:
 * A função retorna o número de itens lidos e atribuídos com sucesso de acordo com o formato.
 * Se ocorrer um erro, ela retorna `EOF`.
 *
 * Utilização:
 * `sscanf` é muito útil quando você precisa processar entradas em formato específico a partir
 * de strings, como parsing de dados configuracionais, logs ou qualquer outro tipo de entrada
 * formatada que já tenha sido lida em memória.
 */

/**
 * @brief Valida se a data fornecida é válida.
 *
 * Essa função verifica se o dia, mês e ano fornecidos formam uma data válida.
 * Ela considera os meses do ano, o número de dias de cada mês e verifica
 * se o ano é bissexto para o mês de fevereiro.
 *
 * @param dia O dia da data a ser validada.
 * @param mes O mês da data a ser validada.
 * @param ano O ano da data a ser validada.
 *
 * @return Retorna `true` se a data for válida, `false` caso contrário.
 */
bool validar_data(int dia, int mes, int ano)
{
    // Verifica se o mês é válido (1-12)
    if (mes < 1 || mes > 12)
    {
        return false;
    }

    // Verifica os dias de cada mês
    int dias_no_mes;
    switch (mes)
    {
    case 2: // Fevereiro
        // Verificação simplificada para ano bissexto
        dias_no_mes = ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) ? 29 : 28;
        break;
    case 4:
    case 6:
    case 9:
    case 11: // Abril, Junho, Setembro, Novembro
        dias_no_mes = 30;
        break;
    default: // Outros meses
        dias_no_mes = 31;
        break;
    }

    return (dia >= 1 && dia <= dias_no_mes);
}

int main(int argc, char **argv)
{
    char entrada[] = "42 3.14 exemplo";
    int numero;
    float decimal;
    char palavra[20];

    // Interpretando valores da string
    sscanf(entrada, "%d %f %s", &numero, &decimal, palavra);

    printf("Número inteiro: %d\n", numero);
    printf("Número decimal: %.2f\n", decimal);
    printf("Palavra: %s\n", palavra);

    printf("\n-------------------------------------\n");

    char input[50];
    int dia, mes, ano;

    printf("Digite uma data no formato dd/mm/aaaa: ");
    fgets(input, sizeof(input), stdin);

    // Usando sscanf para extrair os valores
    int itens_lidos = sscanf(input, "%d/%d/%d", &dia, &mes, &ano);

    if (itens_lidos != 3)
    {
        printf("Formato inválido! Use dd/mm/aaaa.\n");
        return 1;
    }

    if (validar_data(dia, mes, ano))
    {
        printf("Data válida: %02d/%02d/%04d\n", dia, mes, ano);
    }
    else
    {
        printf("Data inválida!\n");
    }
    return 0;
}
