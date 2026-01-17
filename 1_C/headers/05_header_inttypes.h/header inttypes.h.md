<!-- @format -->

# Header `<inttypes.h>` e `stdint.h`

Os headers <inttypes.h> e <stdint.h> fornecem, de forma complementar, **tipos de dados inteiros com tamanhos exatos (fixos)**.
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

---

## Regras geral de uso

- Use tipos básicos para a lógica geral do programa.
- Use tipos de <`stdint.h>` / `<inttypes.h>` quando o tamanho exato for importante.
- Priorize a portabilidade e previsibilidade em código multiplataforma.
