#include <stdio.h>

int main(int argc, char **argv)
{
    // Variáveis para armazenar os dados do cadastro
    char primeiro_nome[50] = {0};
    char segundo_nome[50] = {0};
    char sexo = '\0';
    char nome_completo[100] = {0}; // Espaço maior para nome completo

    int c = 0; // variável para limpeza de buffer

    printf("\n\t=== SISTEMA DE CADASTRO DE USUÁRIO ===\n\n");

    printf(">> Digite seu primeiro nome: ");
    if (scanf("%49s", primeiro_nome) != 1)
    {
        fprintf(stderr, "Erro ao ler o primeiro nome.\n");
        return 1;
    }
    while ((c = getchar()) != '\n' && c != EOF);

    printf(">> Digite seu sobrenome: ");
    if (scanf("%49s", segundo_nome) != 1)
    {
        fprintf(stderr, "Erro ao ler o sobrenome.\n");
        return 1;
    }
    while ((c = getchar()) != '\n' && c != EOF);

    printf("------------------------------------------------\n");

    printf(">> Digite seu sexo (M - Masculino / F - Feminino): ");
    if (scanf(" %c", &sexo) != 1) // note o espaço antes de %c para ignorar '\n' pendente
    {
        fprintf(stderr, "Erro ao ler o sexo.\n");
        return 1;
    }
    while ((c = getchar()) != '\n' && c != EOF);
    
    printf("------------------------------------------------\n");
    
    printf("\n>> Digite seu nome completo (primeiro e segundo nome): ");
    if (scanf(" %99[^\n]", nome_completo) != 1)
    {
        fprintf(stderr, "Erro ao ler o nome completo.\n");
        return 1;
    }
    while ((c = getchar()) != '\n' && c != EOF);
    
    printf("------------------------------------------------\n");
    
    printf("\n================== DADOS CADASTRAIS ==================\n");
    printf("Primeiro nome : %s\n", primeiro_nome);
    printf("Sobrenome     : %s\n", segundo_nome);
    printf("Sexo          : %c\n", sexo);
    printf("Nome completo : %s\n", nome_completo);
    printf("======================================================\n");

    /* Impressão dos índices e endereços para fins didáticos */
    printf("\n--- Detalhes de memória (primeiro nome) ---\n");
    for (int i = 0; primeiro_nome[i] != '\0'; i++)
    {
        printf("Índice: %d\tConteúdo: %c\tEndereço: %p\n",
               i, primeiro_nome[i], (void *)&primeiro_nome[i]);
    }

    printf("\n--- Detalhes de memória (sobrenome) ---\n");
    for (int i = 0; segundo_nome[i] != '\0'; i++)
    {
        printf("Índice: %d\tConteúdo: %c\tEndereço: %p\n",
               i, segundo_nome[i], (void *)&segundo_nome[i]);
    }

    return 0;
}
