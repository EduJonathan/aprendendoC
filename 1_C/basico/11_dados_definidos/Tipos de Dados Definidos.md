<!-- @format -->

# Tipos Definidos de Dados

Antes de avançarmos, é importante compreender o conceito de **Tipos Definidos de Dados**, também conhecidos como
**Tipos Definidos pelo Usuário** (_User Defined Types – UDTs_).

De acordo com a documentação da IBM, um **Tipo de Dado Definido pelo Usuário (UDT)** é um tipo de dado criado pelo
programador a partir de tipos já existentes na linguagem. Esses tipos permitem estender os tipos primitivos oferecidos
pelo sistema, possibilitando a criação de estruturas de dados mais organizadas, legíveis e adequadas às necessidades do programa.

Em vez de trabalhar apenas com tipos básicos como `int`, `float` ou `char`, os UDTs permitem agrupar
informações relacionadas ou representar conceitos do mundo real de forma mais clara dentro do código.

[site da IBM](https://www.ibm.com/docs/pt-br/db2/11.1.0?topic=list-user-defined-types)

> E na linguagem C, possuímos 4 tipos, sendo as principais:

---

## struct (estrutura)

> Usada para agrupar diferentes tipos de dados.

```c
struct Pessoa {
    char nome[50];
    int idade;
    float altura;
};
```

---

## typedef

> Permite criar apelidos para tipos existentes, tornando o código mais legível.

```c
typedef unsigned int uint;
uint contador;
```

> Com struct e os demais logo abaixo `enums` e `unions`, o uso de typedef é muito comum:

```c
typedef struct {
    char nome[50];
    int idade;
} Pessoa;

Pessoa p1;
```

---

## enum (enumeração)

> Define um conjunto de valores constantes nomeados.

```c
typedef enum {
    SEGUNDA,
    TERCA,
    QUARTA,
    QUINTA,
    SEXTA
} DiaSemana;
```

---

## union

> Permite que diferentes tipos compartilhem o mesmo espaço de memória.

```c
union Dado {
    int inteiro;
    float real;
    char caractere;
};
```

---

## Destacando pontos principais dos Tipos Definidos de Dados

### Tamanho, Alinhamento dos tipos, Padding

#### **Tamanho**

A soma dos tamanhos dos membros de uma **struct** nem sempre corresponde ao valor retornado por **sizeof**.
Isso ocorre porque a CPU acessa a memória de forma mais eficiente quando os dados estão **alinhados em blocos**
(normalmente de 4 ou 8 bytes). Para garantir esse alinhamento, o compilador pode inserir bytes extras,
chamados de **padding**.

```c
struct exemplo {
  int a;    // 4 bytes
  float b;  // 4 bytes
  char c;   // 1 byte
  // + 3 bytes de padding aqui para alinhar ao próximo bloco de 4
}; // Total: 12 bytes (em vez de 9)
```

> A ordem dos membros dentro de uma `struct` pode impactar diretamente a quantidade de _padding_.

```c
#include <stdio.h>

struct ExemploRuim {
    char a;
    int b;
    char c;
}; // Tamanho total: 12 bytes

struct ExemploBom {
    int b;
    char a;
    char c;
}; // Tamanho total: 8 bytes

int main(void) {
    printf("Ruim: %zu bytes\n", sizeof(struct ExemploRuim));
    printf("Bom : %zu bytes\n", sizeof(struct ExemploBom));
    return 0;
}
```

---

### Bit-fiels (Campos de bits)

Os campos de bits permitem que você especifique exatamente quantos bits cada membro de uma struct deve ocupar.
Isso é essencial em programação de baixo nível (como drivers ou sistemas embarcados)
para economizar memória ou mapear registradores de hardware.

São muito utilizados em:

- sistemas embarcados
- drivers
- mapeamento de registradores de hardware

```c
struct Status {
    unsigned int ligado : 1;      // Usa apenas 1 bit (0 ou 1)
    unsigned int modo : 2;        // Usa 2 bits (pode representar 0, 1, 2 ou 3)
    unsigned int prioridade : 4;  // Usa 4 bits
};
```

---

### Union e seu compartilhamento "estranho" de memória

A union é diferente da struct, apesar dela fazer as mesmas coisas, ela não soma os tamanhos.
Ela reserva apenas o espaço do maior membro. Todos os membros começam no mesmo endereço de memória.

> Regra de ouro: Você pode armazenar vários tipos, mas só pode ler um por vez (o último que foi gravado).

```c
union Dado {
    int i;      // 4 bytes
    char c;     // 1 byte
    double d;   // 8 bytes
};

// sizeof(union Dado) será 8 bytes (o tamanho do double).
```

Mas gera uma dúvida **E SE**

```c
union Dado {
    int i;    // 4 bytes
    char c;   // 1 byte
    float d; // 4 bytes
};

// Qual o tamanho dessa union, sendo que ela possui de maior tanto **int** e **float** possuem os mesmos 4 bytes, mas são tipos diferentes?
```

---

- 📏 Regra formal do C

> O tamanho de uma union é igual ao tamanho do maior membro, arredondado para atender aos  
> requisitos de alinhamento do membro mais exigente. Ou seja: O compilador analisa todos os membros  
> O maior tamanho é 4 bytes.  
> O maior alinhamento exigido é 4 bytes.

Descobrindo o seguinte:

- qual é o maior tamanho
- qual exige o maior alinhamento
- Aloca memória suficiente para ambos os requisitos

> ⚠️ Importante: tipo ≠ tamanho: Mesmo int e float sendo tipos diferentes, isso não importa para o tamanho da union.

---

### Sobre Enums

Com enums não há padding interno e não há alinhamento interno, O enum é tratado como um único valor inteiro.

---

### 📏 Qual o tamanho de um enum?

- Depende da implementação (isso é importante!).

Na prática: Em muitos compiladores (GCC, Clang, MSVC): `sizeof(enum) == sizeof(int)` (normalmente 4 bytes),
Mas o padrão C diz: Um enum deve ser capaz de representar todos os seus valores. Ou seja, O compilador pode escolher
o menor tipo inteiro capaz de armazenar os valores do enum.

---

### Considerações Importante

- Existe uma diretiva de **pré-processamento** chamada `pragma pack(1)` Ele

  - Remove alinhamento automático.
  - Pode causar acessos lentos ou undefined behavior
  - Deve ser usado apenas em casos muito específicos (protocolos, leitura de arquivos binários, estruturas externas)

---

- Atenção ao usar `-fshort-enums`
  - Não é portável
  - Pode quebrar ABI
  - Pode causar incompatibilidade entre módulos

Não recomendável para:

- bibliotecas
- código compartilhado
- interfaces públicas

```c
enum Pequeno {
    A,
    B,
    C
};

// Configuração  sizeof(enum)
// Padrão        4 bytes
// -fshort-enums 1 byte
```

> Resumo: `-fshort-enums` troca segurança e portabilidade por economia de memória.
