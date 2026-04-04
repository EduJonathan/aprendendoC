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
} GradeInfo;

// Tabela de lookup para status de notas (acesso O(1))
static const GradeInfo GRADE_TABLE[] = {
    {0.0f,  false, "Reprovado - Insuficiente"},
    {1.0f,  false, "Reprovado - Insuficiente"},
    {2.0f,  false, "Reprovado - Insuficiente"},
    {3.0f,  false, "Reprovado - Insuficiente"},
    {4.0f,  false, "Reprovado - Insuficiente"},
    {5.0f,  false, "Reprovado - Recuperação"},
    {6.0f,  true,  "Aprovado  - Satisfatório"},
    {7.0f,  true,  "Aprovado  - Bom"},
    {8.0f,  true,  "Aprovado  - Muito Bom"},
    {9.0f,  true,  "Aprovado  - Excelente"},
    {10.0f, true,  "Aprovado  - Perfeito"}
};

const int TOTAL_NOTAS = sizeof(GRADE_TABLE) / sizeof(GRADE_TABLE[0]);

const char *obter_status_nota(float nota)
{
    if (nota < 0.0f || nota > 10.0f)
        return "Nota inválida";

    int indice = (int)nota;
    return GRADE_TABLE[indice].status;
}

const char *aluno_aprovado_simples(bool aprovado)
{
    return aprovado ? "Aprovado" : "Reprovado";
}

const char *verificar_situacao_aluno(float nota, int frequencia)
{
    bool nota_ok = nota >= 6.0f;
    bool freq_ok = frequencia >= 75;

    if (nota_ok && freq_ok)
        return "Aprovado";

    if (!nota_ok && !freq_ok)
        return "Reprovado por nota e frequência";

    return nota_ok ? "Reprovado por frequência" : "Reprovado por nota";
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

// Tabela lookup que será utilizada para armazenar a classificação de cada caractere ASCII, permitindo acesso O(1) para classificação
static CharCategory charLookup[128];

// Função para inicializar a tabela de lookup com as classificações de caracteres
void initCharLookup(void)
{
    // Inicializa tudo como caractere especial
    for (int i = 0; i < 128; i++)
    {
        charLookup[i] = SPECIAL;
    }

    // Dígitos
    for (int i = '0'; i <= '9'; i++)
    {
        charLookup[i] = DIGIT;
    }

    // Espaço
    charLookup[' '] = SPACE;

    // Vogais
    const char *vowels = "aeiouAEIOU";
    for (int i = 0; vowels[i]; i++)
    {
        charLookup[(unsigned char)vowels[i]] = VOWEL;
    }

    // Consoantes (letras que não são vogais)
    for (int i = 'a'; i <= 'z'; i++)
    {
        if (strchr(vowels, i) == NULL)
            charLookup[i] = CONSONANT;
    }

    for (int i = 'A'; i <= 'Z'; i++)
    {
        if (strchr(vowels, i) == NULL)
            charLookup[i] = CONSONANT;
    }
}

// Função para classificar um caractere usando a tabela de lookup
CharCategory classifyChar(char c)
{
    return (c >= 0 && c < 128) ? charLookup[(unsigned char)c] : SPECIAL;
}

// Função para contar categorias de caracteres em uma string
void analisar_string(const char *str)
{
    if (!str)
        return;

    int counts[CATEGORY_COUNT] = {0};

    for (int i = 0; str[i] != '\0'; i++)
    {
        counts[classifyChar(str[i])]++;
    }

    printf("Análise da string: \"%s\"\n", str);
    printf("   Vogais:          %d\n",     counts[VOWEL]);
    printf("   Consoantes:      %d\n",     counts[CONSONANT]);
    printf("   Espaços:         %d\n",     counts[SPACE]);
    printf("   Dígitos:         %d\n",     counts[DIGIT]);
    printf("   Especiais:       %d\n",     counts[SPECIAL]);
    printf("   Total caracteres: %zu\n\n", strlen(str));
}

// 3. Exemplo 3: Utilizando ponteiro para função
typedef int (*operation_func)(int);

int add(int x) { return x + 1; }
int subtract(int x) { return x - 1; }
int multiply(int x) { return x * 2; }
int divide(int x) { return x / 2; }

// Tabela de operações (substitui múltiplos if/else)
static operation_func operations[] = {
    add,
    subtract,
    multiply,
    divide
};

const char *operation_names[] = {
    "Incrementar",
    "Decrementar",
    "Duplicar",
    "Dividir por 2"
};

int process_operation(int op_type, int data)
{
    // Em vez de:

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

    // Utilize apenas
    if (op_type >= 0 && op_type < 4)
    {
        return operations[op_type](data);
    }
    return 0;
}

int main(int argc, char **argv)
{
    initCharLookup();

    printf("=== BOAS PRÁTICAS COM CONTROLE DE FLUXO ===\n\n");

    /* --- Teste 1: Notas de Aluno --- */
    printf("1. Análise de Notas do Aluno\n");
    printf("----------------------------\n");

    float notas[]     = {7.0f, 5.0f, 9.5f, 3.0f, 10.0f, 11.0f};
    int frequencias[] = {80, 70, 85, 90, 60, 75};

    for (int i = 0; i < 6; i++)
    {
        float nota = notas[i];
        int freq = frequencias[i];

        printf("Nota: %.1f | Frequência: %d%%\n", nota, freq);
        printf("   → Status: %s\n", obter_status_nota(nota));
        printf("   → Simples: %s\n", aluno_aprovado_simples(nota >= 6.0f));
        printf("   → Completo: %s\n\n", verificar_situacao_aluno(nota, freq));
    }

    /* --- Teste 2: Análise de String --- */
    printf("2. Análise de String com Tabela de Lookup\n");
    printf("----------------------------------------\n");
    analisar_string("Hello, World! 123 @#$ ABC123");

    /* --- Teste 3: Operações com Ponteiro para Função --- */
    printf("3. Operações usando Tabela de Ponteiros para Função\n");
    printf("--------------------------------------------------\n");

    int valor = 10;
    for (int i = 0; i < 4; i++)
    {
        int resultado = process_operation(i, valor);
        printf("%s(%d) = %d\n", operation_names[i], valor, resultado);
    }

    return 0;
}
