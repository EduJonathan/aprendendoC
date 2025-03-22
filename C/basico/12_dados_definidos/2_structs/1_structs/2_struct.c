#include <stdio.h>
#include <string.h>

/**
 * @brief Struct que define os seguintes dados do usuario, com os seguintes campos determinantes
 */
struct usuario
{
	unsigned short int idade_do_usuario; /**< Campo para armazenar idade do usuario */
	float peso_do_usuario;				 /**< Campo para armazenar peso do usuario */
	char nome_do_usuario[100];			 /**< Campo para armazenar nome do usuario */
};

int main(int argc, char **argv)
{
	printf("\n\t\t>>STRUCTS<<\n");

	// Atribuindo valores para cada campos da
	// struct {idade_do_usuario, peso_do_usuario, "nome_do_usuario"}
	struct usuario dados_do_usuario = {1U, 96.5F, "Eduardo Jonathan Oliveira de Moraes Silva"};

	printf("\n\tACESSANDO OS VALORES INSERINDO DO CAMPOS DA STRUCT 'struct usuario dados_do_usuario'\n");

	printf(" dados_do_usuario.idade : %hu\n", dados_do_usuario.idade_do_usuario);
	printf(" dados_do_usuario.peso  : %.2f\n", dados_do_usuario.peso_do_usuario);
	printf(" dados_do_usuario.nome  : %s\n", dados_do_usuario.nome_do_usuario);

	printf("\n====================================================\n");

	printf("\n\tACESSANDO OS VALORES INSERINDO DO CAMPOS DA STRUCT 'struct usuario dados_do_usuario1'\n");

	// Outra maneira de definir dados dos campos de uma struct
	struct usuario dados_do_usuario1 = {
		.idade_do_usuario = 78U,
		.peso_do_usuario = 56.45F,
		.nome_do_usuario = "João da Silva"};

	printf(" dados_do_usuario1.idade : %hu\n", dados_do_usuario1.idade_do_usuario);
	printf(" dados_do_usuario1.peso  : %.2f\n", dados_do_usuario1.peso_do_usuario);
	printf(" dados_do_usuario1.nome  : %s\n", dados_do_usuario1.nome_do_usuario);

	printf("\n\tALTERANDO OS VALORES INSERINDO DO CAMPOS DA STRUCT CAMPO POR CAMPO\n");

	dados_do_usuario.idade_do_usuario = -23U;
	dados_do_usuario.peso_do_usuario = 86.45F;
	// dados_do_usuario.nome_do_usuario = "Jonathan";
	// Alterações de strings não se pode com o '=', teremos de usar o strcpy,
	// que estaremos atribuindo um valor ao campo de char `nome_do_usuario`,
	// da struct `dados_do_usuario`
	strcpy(dados_do_usuario.nome_do_usuario, "Jonathan");

	printf(" dados_do_usuario.idade : %hu\n", dados_do_usuario.idade_do_usuario);
	printf(" dados_do_usuario.peso  : %.2f\n", dados_do_usuario.peso_do_usuario);
	printf(" dados_do_usuario.nome  : %s\n", dados_do_usuario.nome_do_usuario);

	printf("\n=========================================================\n");
	printf("\n\tVALORES DA STRUCT ATRAVÉS DO SCANF()\n");

	printf(" INSIRA A IDADE DO USUARIO: ");
	scanf("%hu", &dados_do_usuario.idade_do_usuario);

	printf(" INSIRA O PESO DO USUARIO: ");
	scanf("%f", &dados_do_usuario.peso_do_usuario);

	printf(" INSIRA O NOME DO USUARIO: ");
	scanf("%99[^\n]", &dados_do_usuario.nome_do_usuario);
	setbuf(stdin, NULL);

	printf("\n dados_do_usuario.idade : %hu\n", dados_do_usuario.idade_do_usuario);
	printf(" dados_do_usuario.peso    : %.2f\n", dados_do_usuario.peso_do_usuario);
	printf(" dados_do_usuario.nome    : %s\n", dados_do_usuario.nome_do_usuario);
	return 0;
}
