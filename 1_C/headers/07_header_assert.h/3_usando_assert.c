#include <stdio.h>
#include <assert.h>
#include <math.h>

int main(int argc, char **argv)
{
    // Variáveis para armazenar os números de entrada e o resultado intermediário.
    double x = 0.0, y = 0.0, z = 0.0;

    // Solicita ao usuário que insira pares de números (0 0 para sair).
    puts("Digite um par de dois números (0 0 para encerrar): ");

    // Loop para continuar pedindo pares de números até que 0 0 seja inserido.
    while (scanf("%lf %lf", &x, &y) == 2.0 && (x != 0.0 || y != 0.0))
    {
        // Cálculo da diferença dos quadrados (x^2 - y^2).
        // z = x * x - y * y; /* deveria ser '+' */
        z = x * x + y * y; // Corrigido para adição (+) ao invés de subtração (-).

        // Verifica se a diferença dos quadrados é não-negativa.
        assert(z >= 0);

        // Imprime a raiz quadrada da diferença dos quadrados.
        printf("A resposta é %f\n", sqrt(z));

        // Solicita o próximo par de números.
        puts("Próximo par de números: ");
    }

    // Mensagem indicando que o programa foi concluído.
    puts("Concluído");
    return 0;
}
