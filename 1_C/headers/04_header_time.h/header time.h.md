<!-- @format -->

# Header `<time.h>`

A header `<time.h>` fornece mecanismos para **medição, manipulação e conversão de tempo**.
Ela permite trabalhar tanto com **tempo de calendário** (data e hora reais do sistema)
quanto com **tempo de CPU** consumido por um programa.

As informações de tempo são fornecidas pelo **sistema operacional**, que utiliza
relógios e temporizadores de hardware, abstraindo esses detalhes para o programador.

Essa biblioteca é amplamente utilizada para:

- Medir desempenho
- Trabalhar com datas e horários
- Formatar informações temporais
- Calcular diferenças de tempo

---

## Tipos fundamentais

| Tipo              | Descrição                                       |
| ----------------- | ----------------------------------------------- |
| `time_t`          | Representa tempo de calendário                  |
| `clock_t`         | Representa tempo de CPU                         |
| `struct tm`       | Estrutura de data e hora                        |
| `struct timespec` | Tempo com precisão de nanossegundos (C11/POSIX) |

---

## Funções principais

### Funções de manipulação de tempo

| **Função** | **Assinatura**                           | **Descrição**                            |
| ---------- | ---------------------------------------- | ---------------------------------------- |
| `time`     | `time_t time(time_t *t);`                | Obtém o tempo atual (epoch)              |
| `difftime` | `double difftime(time_t t1, time_t t0);` | Calcula diferença entre dois tempos      |
| `clock`    | `clock_t clock(void);`                   | Retorna tempo de CPU usado pelo processo |
| `asctime`  | `char *asctime(const struct tm *tm);`    | Converte `struct tm` para string         |
| `ctime`    | `char *ctime(const time_t *t);`          | Converte `time_t` para string            |

---

### Funções de conversão de tempo

| **Função**  | **Assinatura**                                                                | **Descrição**                      |
| ----------- | ----------------------------------------------------------------------------- | ---------------------------------- |
| `localtime` | `struct tm *localtime(const time_t *t);`                                      | Converte para hora local           |
| `gmtime`    | `struct tm *gmtime(const time_t *t);`                                         | Converte para UTC                  |
| `mktime`    | `time_t mktime(struct tm *tm);`                                               | Converte `struct tm` para `time_t` |
| `strftime`  | `size_t strftime(char *s, size_t max, const char *fmt, const struct tm *tm);` | Formata data/hora                  |

---

## Exemplo simples

```c
#include <stdio.h>
#include <time.h>

int main() {
    time_t agora = time(NULL);
    struct tm *local = localtime(&agora);

    char buffer[100];
    strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", local);

    printf("Data e hora atual: %s\n", buffer);
    return 0;
}
```

---

## Tempo de calendário vs Tempo de CPU

| Tempo de calendário           | Tempo de CPU           |
| ----------------------------- | ---------------------- |
| Data e hora reais             | Tempo gasto executando |
| Depende do relógio do sistema | Independe do relógio   |
| Usa `time_t`                  | Usa `clock_t`          |
| Função `time()`               | Função `clock()`       |

---

📘 **Conclusão**

A `<time.h>` fornece uma abstração poderosa e portátil para lidar com tempo em C,
permitindo desde medições de desempenho até manipulação e formatação de datas reais.
Compreender a diferença entre tempo de calendário e tempo de CPU é essencial para seu uso correto.
