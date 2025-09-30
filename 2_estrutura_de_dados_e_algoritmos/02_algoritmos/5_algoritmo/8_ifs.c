#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

/**
 * If é um controle de fluxo que altera o caminho que o código irá pecorrer,
 * devido a esse controle é importante ressaltar que a lógica deve ser aplicada
 * corretamente e logicamente quando realmente convém.
 *
 * Cuidado com if's aninhados
 * Use switch para 3+ condições do mesmo valor
 * Prefira tabelas/arrays para mapeamentos valor→ação
 * Use early returns para validações
 * Combine condições relacionadas com &&, ||, !
 * Aplique ternário para atribuições simples
 * Considere máquinas de estados para comportamentos complexos
 * Use guard clauses para reduzir aninhamento
 *
 * Tenha estas considerações pelo if para ser mais legível e mais limpo ao implementar
 * Ressaltando também que o controle de loops(while, do-while, for) é válido sua implementação
 * na lógica. Para o código mais entendível e propenso a menos erros de lógica
 */

// Exemplo 1: Utilizar ternário em comparações simples
typedef struct
{
    float nota;
    bool aprovado;
    const char *status;
} NotaDoAluno;

// Lookup table com acesso O(1)
static const NotaDoAluno GRADE_NOTAS[] = {
    {0.0, false, "Reprovado - Insuficiente"},
    {1.0, false, "Reprovado - Insuficiente"},
    {2.0, false, "Reprovado - Insuficiente"},
    {3.0, false, "Reprovado - Insuficiente"},
    {4.0, false, "Reprovado - Insuficiente"},
    {5.0, false, "Reprovado - Recuperação"},
    {6.0, true, "Aprovado - Satisfatório"},
    {7.0, true, "Aprovado - Bom"},
    {8.0, true, "Aprovado - Muito Bom"},
    {9.0, true, "Aprovado - Excelente"},
    {10.0, true, "Aprovado - Perfeito"}};

const int TOTAL_NOTAS = sizeof(GRADE_NOTAS) / sizeof(GRADE_NOTAS[0]);

const char *obter_status_aprovacao(float nota)
{
    int indice = (int)nota;
    return (indice >= 0 && indice < TOTAL_NOTAS) ? GRADE_NOTAS[indice].status : "Nota inválida";
}

const char *aluno_aprovado_simples(bool aprovado)
{
    return aprovado ? "Aprovado" : "Reprovado";
}

const char *verificar_situacao_completa(float nota, int frequencia)
{
    bool nota_aprovada = nota >= 6.0;
    bool frequencia_aprovada = frequencia >= 75;
    return (nota_aprovada && frequencia_aprovada)     ? "Aprovado"
           : (!nota_aprovada && !frequencia_aprovada) ? "Reprovado por nota e frequência"
           : (!nota_aprovada)                         ? "Reprovado por nota"
                                                      : "Reprovado por frequência";
}

// Exemplo 2: Evitando if's com tabela de lookup para classificação de caracteres
typedef enum
{
    VOWEL,
    CONSONANT,
    SPACE,
    DIGIT,
    SPECIAL,
    CATEGORY_COUNT
} CharCategory;

static CharCategory charLookup[128];

void initCharLookup(void)
{
    for (int i = 0; i < 128; i++)
    {
        charLookup[i] = SPECIAL;
    }

    // Digits
    for (int i = '0'; i <= '9'; i++)
    {
        charLookup[i] = DIGIT;
    }

    // Space
    charLookup[' '] = SPACE;

    // Vowels
    const char *vowels = "aeiouAEIOU";
    for (int i = 0; vowels[i]; i++)
    {
        charLookup[(unsigned char)vowels[i]] = VOWEL;
    }

    // Consonants
    for (int i = 'a'; i <= 'z'; i++)
    {
        if (strchr(vowels, i) == NULL)
        {
            charLookup[i] = CONSONANT;
        }
    }
    for (int i = 'A'; i <= 'Z'; i++)
    {
        if (strchr(vowels, i) == NULL)
        {
            charLookup[i] = CONSONANT;
        }
    }
}

CharCategory classifyChar(char c)
{
    return (c < 128) ? charLookup[(unsigned char)c] : SPECIAL;
}

void checaString(const char *string)
{
    int counts[CATEGORY_COUNT] = {0};
    for (int i = 0; string[i] != '\0'; i++)
    {
        counts[classifyChar(string[i])]++;
    }
    printf("Vogais: %d\n", counts[VOWEL]);
    printf("Consoantes: %d\n", counts[CONSONANT]);
    printf("Espaços: %d\n", counts[SPACE]);
    printf("Caracteres especiais: %d\n", counts[SPECIAL]);
    printf("Dígitos: %d\n", counts[DIGIT]);
}

// 3. Exemplo 3: Utilizando ponteiro para função
typedef int (*operation_func)(int);

int add(int x) { return x + 1; }
int subtract(int x) { return x - 1; }
int multiply(int x) { return x * 2; }
int divide(int x) { return x / 2; }

// Tabela de funções
static operation_func operations[] = {add, subtract, multiply, divide};

int process_operation(int op_type, int data)
{
    /*if (op_type == ADD)
    {
        return add(data);
    }
    else if (op_type == SUBTRACT)
    {
        return subtract(data);
    }
    else if (op_type == MULTIPLY)
    {
        return multiply(data);
    }
    else if (op_type == DIVIDE)
    {
        return divide(data);
    }*/

    if (op_type >= 0 && op_type < 4)
    {
        return operations[op_type](data);
    }
    return 0;
}

int main(int argc, char **argv)
{
    initCharLookup();

    printf("Teste de Notas:\n");

    float test_notas[] = {7.0, 5.0, 11.0, 7.5};
    int test_frequencias[] = {80, 70, 75, 80};

    for (int i = 0; i < 4; i++)
    {
        float nota = test_notas[i];
        int freq = test_frequencias[i];
        printf("Nota: %.1f, Frequência: %d%%\n", nota, freq);
        printf("  Status: %s\n", obter_status_aprovacao(nota));
        printf("  Simples: %s\n", aluno_aprovado_simples(nota >= 6.0));
        printf("  Completo: %s\n\n", verificar_situacao_completa(nota, freq));
    }

    printf("Teste de String:\n");

    const char *str = "Hello, World! 123 @#$";
    printf("String: %s\n", str);
    checaString(str);

    printf("\nTeste de Operações:\n");

    int data = 10;
    const char *op_names[] = {"Adição", "Subtração", "Multiplicação", "Divisão"};
    for (int i = 0; i < 4; i++)
    {
        printf("Operação %s sobre %d -> Resultado: %d\n", op_names[i], data, process_operation(i, data));
    }

    return 0;
}
