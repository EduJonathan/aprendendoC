<!-- @format -->

# Header `<inttypes.h>` e `<stdint.h>`

Os headers `<inttypes.h>` e `<stdint.h>` fornecem, de forma complementar, **tipos de dados inteiros com tamanhos exatos (fixos)**.
Eles são essenciais para escrever **código portátil e previsível**, especialmente em cenários como:

- Protocolos de rede/comunicação
- Formatos de arquivos binários
- Hardware e sistemas embarcados (registradores específicos)
- Cálculos que exigem precisão de bits
- Código que deve se comportar da mesma forma em arquiteturas 32/64 bits
- Criptografia e algoritmos dependentes de tamanho exato

---

O tipos são:

```c
int8_t, int16_t, int32_t, int64_t      // Com sinal
uint8_t, uint16_t, uint32_t, uint64_t // Sem sinal
```

> Esses tipos garantem exatamente o número de bits indicado no nome, se a plataforma os suportar.

---

```c
int_least8_t, int_least64_t  // Pelo menos X bits
int_fast8_t, int_fast64_t    // Mais rápido com pelo menos X bits
```

> **leastX_t:** garante no mínimo `X` bits.
> **fastX_t:** prioriza desempenho, mantendo ao menos `X` bits.

---

## Substituem os tipos inteiros

**NÃO**,

```c
// Tipo básico - compilador escolhe tamanho otimizado
for (int i = 0; i < 100; i++)  // 'int' é geralmente mais eficiente

// Tipo fixo - pode ser menos eficiente em algumas arquiteturas
for (int32_t i = 0; i < 100; i++)
```

Os tipos básicos (`int`, `long`, etc.) costumam ser melhores em:

- Laços de contagem simples.
- Retornos de funções padrão.
- Código onde o tamanho exato não é crítico.
- Situações em que se deseja máxima otimização automática do compilador.

---

## Observação importante

Sempre que usar esses tipos em `printf/scanf`, prefira os **macros de formatação** de `<inttypes.h>`
(como _PRId32_, _PRIu64_), garantindo portabilidade total.

| **Tipo**         | **printf()**  | **scanf()**   |
| ---------------- | ------------- | ------------- |
| `int8_t`         | `PRId8`       | `SCNd8`       |
| `int16_t`        | `PRId16`      | `SCNd16`      |
| `int32_t`        | `PRId32`      | `SCNd32`      |
| `int64_t`        | `PRId64`      | `SCNd64`      |
| `uint8_t`        | `PRIu8`       | `SCNu8`       |
| `uint16_t`       | `PRIu16`      | `SCNu16`      |
| `uint32_t`       | `PRIu32`      | `SCNu32`      |
| `uint64_t`       | `PRIu64`      | `SCNu64`      |
| `int_least8_t`   | `PRIdLEAST8`  | `SCNdLEAST8`  |
| `int_least16_t`  | `PRIdLEAST16` | `SCNdLEAST16` |
| `int_least32_t`  | `PRIdLEAST32` | `SCNdLEAST32` |
| `int_least64_t`  | `PRIdLEAST64` | `SCNdLEAST64` |
| `uint_least8_t`  | `PRIuLEAST8`  | `SCNuLEAST8`  |
| `uint_least16_t` | `PRIuLEAST16` | `SCNuLEAST16` |
| `uint_least32_t` | `PRIuLEAST32` | `SCNuLEAST32` |
| `uint_least64_t` | `PRIuLEAST64` | `SCNuLEAST64` |
| `int_fast8_t`    | `PRIdFAST8`   | `SCNdFAST8`   |
| `int_fast16_t`   | `PRIdFAST16`  | `SCNdFAST16`  |
| `int_fast32_t`   | `PRIdFAST32`  | `SCNdFAST32`  |
| `int_fast64_t`   | `PRIdFAST64`  | `SCNdFAST64`  |
| `uint_fast8_t`   | `PRIuFAST8`   | `SCNuFAST8`   |
| `uint_fast16_t`  | `PRIuFAST16`  | `SCNuFAST16`  |
| `uint_fast32_t`  | `PRIuFAST32`  | `SCNuFAST32`  |
| `uint_fast64_t`  | `PRIuFAST64`  | `SCNuFAST64`  |

---

```c
// Exemplo de uso
#include <stdio.h>
#include <inttypes.h>

int32_t x;
scanf("%" SCNd32, &x);
printf("%" PRId32 "\n", x);
```

---

## Regras geral de uso

- Use tipos básicos para a lógica geral do programa.
- Use tipos de `<stdint.h>` / `<inttypes.h>` quando o tamanho exato for importante.
- Priorize a portabilidade e previsibilidade em código multiplataforma.
