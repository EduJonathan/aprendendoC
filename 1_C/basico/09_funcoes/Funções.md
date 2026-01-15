<!-- @format -->

# Funções

Funções têm o propósito de **evitar código monolítico**, separando a lógica do programa
em **blocos reutilizáveis e independentes**, onde cada função executa uma tarefa específica.

Uma função pode:

- **Alterar o estado** do programa (por meio de ponteiros)
- **Retornar um valor** ao chamador

> O uso de funções melhora a organização, a legibilidade, a manutenção e promove o reuso de código.

---

## Exemplo de código monolítico

```c
#include <stdio.h>

int main() {
    int inputInteiro = 0;
    char inputCaractere = '\0';

    printf("Insira um valor inteiro: ");
    scanf("%d", &inputInteiro);

    printf("Insira um caractere: ");
    scanf(" %c", &inputCaractere); // espaço ignora o '\n'

    return 0;
}
```

---

## Exemplo utilizando funções

```c
#include <stdio.h>

// Lê um valor inteiro
void inputInteiro(const char *msg, int *valorLido) {
    printf("%s", msg);
    scanf("%d", valorLido);
}

// Lê um caractere
void inputCaractere(const char *msg, char *valorLido) {
    printf("%s", msg);
    scanf(" %c", valorLido); // ignora caracteres em branco
}

int main() {
    int numero = 0;
    char letra = '\0';

    inputInteiro("Insira um valor inteiro: ", &numero);
    inputCaractere("Insira um caractere: ", &letra);

    return 0;
}
```

---

## Destacando os principais pontos sobre funções

### Passagem por valor vs Passagem por referência

#### Passagem por valor

Na passagem por valor, a função recebe uma cópia do valor original.
Qualquer modificação feita dentro da função não afeta a variável no escopo chamador.

```c
void incrementa(int x) {
    x++;
}

int main() {
    int a = 10;
    incrementa(a);
    // a continua valendo 10
}
```

#### Passagem por referência (via ponteiros)

Em C, a passagem por referência é simulada com ponteiros. A função recebe o endereço da variável, podendo modificá-la diretamente.

```c
void incrementa(int *x) {
    // Sempre verifique parâmetros e ponteiros
    if(x == NULL)
        return;
    (*x)++;
}

int main() {
    int a = 10;
    incrementa(&a);
    // a agora vale 11
}
```

> É como ligar diretamente no motor em vez de girar apenas a chave.

---

### Recursividade

**Recursividade** é uma técnica de programação na qual uma função chama a si mesma para resolver um problema,
dividindo-o em subproblemas menores até alcançar uma condição de parada. Toda função recursiva possui dois elementos fundamentais:

- Caso base: condição que encerra as chamadas recursivas.
- Caso recursivo: chamada da própria função para resolver uma parte menor do problema.

```c
int fatorial(int n) {
    if (n == 0 || n == 1)
        return 1; // Caso base
    return n * fatorial(n-1); // Caso recursivo
}
```

> Cuidados ao usar recursão

- Sempre defina um caso base e garanta que a função eventualmente o alcance; caso contrário, ocorrerá um estouro de pilha (stack overflow).
- Tenha atenção à lógica do caso recursivo, certificando-se de que o problema está sendo reduzido a cada chamada.
- Evite recursão desnecessária em problemas simples, pois chamadas recursivas possuem custo maior de memória e processamento.

---

### Pilha de Chamadas (Call Stack) vs Profundidade da Recursão

> Esse é um dos conceitos mais importantes (e invisíveis) quando se trabalha com funções, especialmente recursivas.

#### O que é a Pilha de Chamadas (Call Stack)?

Sempre que uma função é chamada (inclusive a `main`), o sistema operacional reserva um bloco de memória chamado
**frame de ativação (ou activation record)** e o coloca no topo da pilha de chamadas. Cada frame contém:

- Endereço de retorno (para onde voltar depois que a função terminar)
- Parâmetros passados
- Variáveis locais da função
- Outros dados de controle (como registradores salvos)

> Exemplo simplificado de pilha durante recursão fatorial(4):

```text
        TOPO DA PILHA
    ┌────────────────────┐
    │ fatorial(1)        │  ← caso base (retorna 1)
    ├────────────────────┤
    │ fatorial(2)        │  ← espera retorno * 2
    ├────────────────────┤
    │ fatorial(3)        │  ← espera retorno * 3
    ├────────────────────┤
    │ fatorial(4)        │  ← chamada inicial
    ├────────────────────┤
    │ main()             │
    └────────────────────┘
        BASE DA PILHA
```

> A cada novo fram `(push)` Quando uma função termina `(return)`, seu frame é removido `(pop)` do topo da pilha, e o controle retorna para o frame anterior.

---

#### Profundidade da Pilha

A profundidade da pilha representa a **quantidade de frames** (registros de ativação) que estão empilhados
simultaneamente durante a execução de uma função, seja por chamadas da mesma função ou por uma cadeia de chamadas diferentes.

```c
int fibonacci(int n) {
    if (n <= 1)
        return n;              // Caso base
    return fibonacci(n - 1) + fibonacci(n - 2); // Caso recursivo
}
```

> Exemplo:

- fibonacci(5) → profundidade máxima ≈ 6 (cadeia mais profunda: main → fib(5) → fib(4) → fib(3) → fib(2) → fib(1))

> ⚠️ Apesar de a profundidade máxima ser linear (O(n)), o número total de chamadas cresce exponencialmente (O(2ⁿ)),
> tornando essa abordagem ineficiente para valores grandes de `n`.

- Árvore binária balanceada → profundidade ≈ log₂(n)
- Lista encadeada longa → profundidade ≈ n (pode explodir rápido!)

---

### Ponteiros para Funções, Funções Callback e Funções Anônimas(lambdas)

Tenha em mente que funções também **possuem endereço na memória**. A partir disso, surgem três conceitos relacionados, mas distintos.

#### 1. Ponteiros para Função (O "Endereço")

Um ponteiro para função é uma variável que armazena o endereço de uma função já definida.

- **Onde vive:** Comum em C e C++.
- **Limitação:** Ele aponta para um bloco de código estático. Ele não consegue "carregar" dados extras com ele (não tem estado).
- **Exemplo:** Imagine que você passa o endereço da "receita de bolo" para alguém.

```c
#include <stdio.h>

// Definindo um tipo para o ponteiro de função
typedef int (*Operacao)(int, int);

// Função que aceita um callback
void processar(int a, int b, Operacao callback) {
    int resultado = callback(a, b);
    printf("Resultado da operacao: %d\n", resultado);
}

int soma(int x, int y) {
    return x + y;
}

int main() {
    // Passando o endereço da função soma como callback
    processar(5, 3, soma);
    return 0;
}
```

#### 2. Callbacks (O "Papel/Função")

Um callback é um padrão de projeto onde uma função é passada como argumento para outra, para ser executada em um momento específico.

```c
#include <stdio.h>

void processoLongo(void (*callback)(int)) {
    printf("Processando...\n");
    int resultado = 42;
    callback(resultado);
}

void quandoTerminar(int valor) {
    printf("Processo terminou! Resultado = %d\n", valor);
}

int main() {
    processoLongo(quandoTerminar);

    // ⚠️ Exemplo didático:
    // printf é usado aqui apenas porque a assinatura é compatível.
    // Isso NÃO é uma prática recomendada em código real.
    processoLongo(printf);
    return 0;
}
```

> O ponteiro para função é a ferramenta; o callback é o uso que você faz dela.

#### 3. Lambdas (A "Função Anônima e Inteligente")

Lambdas não são nativas de C, tendo que implementar 'manualmente', que é um desafio por si só.
Linguagens como C++, Java e Python oferecem suporte direto. Em C, é possível simular closures
combinando ponteiros de função com um contexto de dados.

- **Estado:** Diferente de um ponteiro de função puro, uma Lambda pode `capturar` variáveis do ambiente ao seu redor.
- **Exemplo:** Se você tem uma variável taxa = 0.1 fora da função, a Lambda consegue `ler` essa taxa e usá-la no cálculo interno,
  enquanto um ponteiro de função comum precisaria que você passasse esse valor explicitamente como parâmetro.

```c
#include <stdio.h>

typedef int (*CallbackComEstado)(int, void*);

void executar(int x, CallbackComEstado funcao, void* contexto) {
    int res = funcao(x, contexto);
    printf("Resultado com contexto: %d\n", res);
}

int somar_com_base(int x, void* contexto) {
    int valor_base = *(int*)contexto;
    return x + valor_base;
}

int main() {
    int base = 10;
    executar(5, somar_com_base, &base);
    return 0;
}
```

---

### Quando usar cada abordagem?

- **Funções simples:** organizar e reutilizar lógica
- **Ponteiros:** permitir que funções modifiquem dados do chamador
- **Recursão:** problemas naturalmente hierárquicos (com cuidado)
- **Callbacks:** comportamento customizável e desacoplado
- **`Closures` em C:** quando é necessário combinar estado + callback
- **Pilha de chamadas** é mais recomendado para entender recursão

---

📘 **Conclusão**

O uso correto de funções transforma programas grandes e confusos em
códigos organizados, reutilizáveis e fáceis de manter. Entender a diferença
entre **retornar valores** e **alterar dados via ponteiros** é essencial
para programar corretamente em C.
