#include <stdio.h>
#include <time.h>

// Estrutura para armazenar os dados dos candidatos para entrevista
typedef struct entrevista
{
    char nome[100];
    char email[100];
    char profissao[50];
    char local[100];
    time_t horario_entrevista;
} Candidatos;

// Função para enviar e-mail (simulação)
void enviarEmail(Candidatos candidato)
{
    char dataHora[50];
    // Converte o horário da entrevista para o formato de data e hora
    strftime(dataHora, 50, "%d/%m/%Y às %H:%M", localtime(&candidato.horario_entrevista));

    // Exibe o conteúdo do e-mail
    printf("Email enviado para: %s\n", candidato.email);
    printf("Assunto: Confirmação de entrevista\n");
    printf("Corpo:\n");
    printf("Olá, %s\n", candidato.nome);
    printf("Sua entrevista para %s está agendada\n", candidato.profissao);
    printf("Local: %s\n", candidato.local);
    printf("Horário: %s\n", dataHora);
    printf("---------------------------------\n");
}

int main(int argc, char **argv)
{
    // Dados dos candidatos
    Candidatos candidatos[] = {
        {"Eduardo Jonathan", "edujonathan@gmail.com", "Desenvolvedor C", "Sala 102, Torre A", time(NULL) + 86400}, // Amanhã
        {"Ana", "Ana@gmail.com", "Analista de dados", "Sala 205, Torre B", time(NULL) + 172800},                   // 2 dias
        {"John", "john@gmail.com", "Engenheiro de Software", "Auditório Principal", time(NULL) + 259200}};         // 3 dias

    // Calcula o número de candidatos
    size_t numero_de_candidatos = sizeof(candidatos) / sizeof(candidatos[0]);

    // Envia o e-mail para cada candidato
    for (size_t i = 0; i < numero_de_candidatos; i++)
    {
        enviarEmail(candidatos[i]);
    }

    return 0;
}
