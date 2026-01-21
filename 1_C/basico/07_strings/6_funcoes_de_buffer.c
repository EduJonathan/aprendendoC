#include <stdio.h>

/**
 * FUNÇÕES E TÉCNICAS PARA LIDAR COM BUFFER DE ENTRADA (stdin) EM C
 *
 * A entrada de dados, principalmente de caracteres (`char`), é uma fonte comum de erros em C,
 * pois o buffer de entrada (stdin) pode conter caracteres residuais, como '\n'.
 * Diferentemente de linguagens de alto nível, C exige que o programador trate esse problema
 * explicitamente.
 *
 * A seguir estão algumas abordagens comuns, com observações importantes:
 *
 * 1. fflush(stdin);
 * - Comportamento indefinido segundo o padrão ISO C.
 * - Funciona apenas em alguns compiladores (ex.: MSVC).
 * - NÃO É PORTÁVEL e não deve ser usado em código confiável.
 *
 * 2. setbuf(stdin, NULL);
 * - Desativa o buffer do stdin a partir da chamada.
 * - NÃO limpa dados já existentes no buffer.
 * - Pode impactar o desempenho.
 *
 * 3. setvbuf(stdin, NULL, _IONBF, 0);
 * - Similar ao setbuf, porém com mais controle.
 * - Também não remove dados já presentes no buffer.
 *
 * 4. Limpeza manual do buffer (FORMA CORRETA E PORTÁVEL):
 * - Lê e descarta caracteres até encontrar '\n' ou EOF.
 *
 *   int c;
 *   while ((c = getchar()) != '\n' && c != EOF);
 *
 * - Atenção: chamar getchar() mais de uma vez na condição do while é um erro,
 *   pois causa a leitura e descarte indevido de caracteres.
 *
 * 5. scanf(" %c", &var);
 * - O espaço antes de %c faz o scanf ignorar caracteres em branco
 *   (espaços, tabs e quebras de linha).
 * - É a forma recomendada para ler um caractere isolado.
 *
 * 6. getchar();
 * - Pode ser usado para consumir um único '\n' residual,
 *   mas apenas quando se tem certeza de que há exatamente um caractere pendente.
 * - NÃO é uma solução geral.
 *
 * 7. fpurge(stdin);
 * - Função não padronizada (BSD / macOS).
 * - Não disponível em todos os sistemas.
 * - Não recomendada para código portátil.
 *
 * BOA PRÁTICA GERAL:
 * - Prefira usar fgets() para leitura de entrada
 *   e depois processe os dados com sscanf(), strtol(), etc.
 *
 *   char buffer[100];
 *   fgets(buffer, sizeof(buffer), stdin);
 *
 * CUIDADOS:
 * - Sempre verifique os retornos de funções de entrada.
 * - Evite suposições sobre o estado do buffer de entrada.
 * - Teste seu código em diferentes ambientes e compiladores.
 * - Evite buffer overflows, pois são uma fonte comum de vulnerabilidades.
 */

int main(int argc, char **argv)
{
    printf("Exemplo de leitura segura de string em C\n");

    char letra[100];

    /* Leitura correta de string usando scanf */
    printf("Digite uma palavra: ");
    scanf("%99s", letra); // limita para evitar buffer overflow
    printf("Você digitou: %s\n\n", letra);

    printf("--------------------------------\n\n");

    printf("Exemplo com fflush(stdin) (NÃO RECOMENDADO)\n");
    printf("A chamada abaixo possui comportamento indefinido segundo o padrão C\n");

    /* COMPORTAMENTO INDEFINIDO — apenas para fins educacionais */
    fflush(stdin);

    printf("Digite outra palavra: ");
    scanf("%99s", letra);
    printf("Você digitou: %s\n", letra);

    printf("--------------------------------\n\n");
    printf("Exemplo de limpeza manual do buffer (RECOMENDADO)\n");

    /* Limpeza manual do buffer (forma portável) */
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Digite mais uma palavra: ");
    scanf("%99s", letra);
    printf("Você digitou: %s\n", letra);

    printf("--------------------------------\n\n");
    printf("Exemplo utilizando setvbuf (NÃO RECOMENDADO)\n");

    /* Desativa o buffer do stdin (não limpa dados já existentes) */
    setvbuf(stdin, NULL, _IONBF, 0);
    printf("Digite uma última palavra: ");
    scanf("%99s", letra);
    printf("Você digitou: %s\n", letra);

    printf("--------------------------------\n\n");
    printf("Exemplo utilizando setbuf (NÃO RECOMENDADO)\n");

    /* Desativa o buffer do stdin (não limpa dados já existentes) */
    setbuf(stdin, NULL);
    printf("Digite uma palavra final: ");
    scanf("%99s", letra);
    printf("Você digitou: %s\n", letra);

    printf("--------------------------------\n\n");
    printf("Utilizando fgets e sscanf (MELHOR PRÁTICA)\n");

    /* Limpa o buffer antes do fgets */
    while ((c = getchar()) != '\n' && c != EOF);

    char buffer[100];
    printf("Digite uma palavra final: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%99s", letra);
    printf("Você digitou: %s\n", letra);

    return 0;
}
