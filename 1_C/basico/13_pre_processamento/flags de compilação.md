# ⚙️ Flags de Compilação

Flags de compilação são **parâmetros passados ao compilador** para alterar o comportamento da compilação. Elas permitem:

- Ativar ou desativar recursos específicos.
- Controlar verificações e análises.
- Definir o tipo de saída (executável, objeto, biblioteca).
- Otimizar o código para desempenho ou tamanho.

Essas flags tornam o processo de compilação mais flexível e ajudam a personalizar como o código é construído.

---

## 📶 FLAGS DE EXIBIÇÃO

```bash
gcc arquivo.c -E

# Exibe o código depois do pré-processamento (expansão de macros, inclusão de cabeçalhos, etc.),
# mas não compila o código.
```

```bash
gcc arquivo.c -S

# Gera o código Assembly. É útil se você deseja estudar como o compilador
# traduziu seu código-fonte em código de baixo nível.
```

```bash
gcc -c arquivo.c

# Gera apenas o código objeto (.o), sem gerar um executável. Isso é útil se você
# está fazendo compilação modular, onde os arquivos objeto são linkados posteriormente.
```

```bash
gcc arquivo.c -o

# Define o nome do arquivo de saída. A flag -o é usada para especificar
# o nome do arquivo gerado, seja um executável ou outro tipo de arquivo.
```

```bash
gcc -E file -o output_processed_file.i

# Cria um arquivo .i contendo o código-fonte após o pré-processamento.
# Isso pode ser útil para estudar a forma como o pré-processamento foi realizado.
```

```bash
gcc -E -P main.c -o main.i

# Aqui, o código ainda é pré-processado, mas sem as diretivas de inclusão (como include),
# o que pode ser útil quando você quer ver como as macros são expandidas sem se preocupar
# com as dependências de cabeçalhos externos.
```

```bash
gcc arquivo.c -g ou -ggdb

# Adiciona informações de depuração ao seu programa. O -g inclui informações básicas
# de depuração, enquanto o -ggdb adiciona mais informações específicas para o GDB.
```

```bash
gcc -static main.cpp -o build

# Compila o programa com bibliotecas estáticas (em vez de dinâmicas).
# O executável resultante não depende de bibliotecas externas e pode ser mais "portátil".
```

---

## 🚀 FLAGS DE OTIMIZAÇÃO

As otimizações controlam a performance e tamanho do binário. As opções mais comuns são:

- `-O0`: Desativa todas as otimizações. Útil para depuração, pois o código gerado é mais próximo
  do código-fonte original.
- `-O1`: Ativa otimizações básicas para melhorar a performance sem aumentar muito o tempo de compilação.
- `-O2`: Ativa otimizações mais agressivas para melhorar a performance. É uma escolha padrão para
  a maioria dos programas em produção.
- `-O3`: Aplica as otimizações do -O2 e adiciona otimizações agressivas (como vetorização e
  unrolling de loops). Ideal para código de alto desempenho, mas pode aumentar o tamanho do código.
- `-Os`: Otimiza para reduzir o tamanho do binário gerado. Útil para sistemas embarcados ou
  para quando você precisa de um arquivo executável menor.

```bash
# Sem otimização (ideal para depuração)
gcc -O0 arquivo.c -o programa

# Otimização básica
gcc -O1 arquivo.c -o programa

# Otimização padrão para produção
gcc -O2 arquivo.c -o programa

# Otimização agressiva (alto desempenho)
gcc -O3 arquivo.c -o programa

# Otimização para tamanho (sistemas embarcados)
gcc -Os arquivo.c -o programa
```

### 📩 Nota

Algumas flags, como `-O0` e `-O3`, são mutuamente exclusivas, pois definem
níveis de otimização diferentes. Sempre verifique a documentação do compilador
para combinações específicas, o que acompanha no começo é o caractere `O`.

---

## ⚠️ Flags de Aviso

Essas flags ajudam a identificar potenciais problemas no código, como falhas de lógica,
inconsistências e más práticas.

- `Wall`: Ativa a maioria dos avisos importantes, mas não todos. É uma boa prática usar,
  pois ajuda a detectar problemas comuns no código.
- `Wextra`: Ativa avisos adicionais além dos ativados por -Wall. Pode incluir avisos sobre
  construções do código que não são necessariamente erros, mas que podem ser problemáticas.
- `Wshadow`: Emite um aviso quando uma variável local "sombra" (ou oculta) outra variável com
  o mesmo nome em um escopo diferente. Esse tipo de erro pode ser difícil de detectar.
- `Wconversion`: Avisa quando há conversões de tipos implícitas que podem resultar em perda
  de dados ou comportamento inesperado (por exemplo, conversão de float para int).
- `Wpedantic`: Garante conformidade rigorosa com o padrão da linguagem C (ISO/IEC).
  Emite avisos sobre qualquer violação do padrão.
- `fopenmp`: Habilita o suporte ao OpenMP, que é uma API para programação paralela. Usado
  quando você deseja dividir seu código para ser executado em múltiplos núcleos de processadores.

```bash
# Variáveis sombreadas
gcc -Wshadow arquivo.c -o programa

# Conversões implícitas perigosas
gcc -Wconversion arquivo.c -o programa

# Variáveis não inicializadas
gcc -Wuninitialized arquivo.c -o programa

# Possível uso não inicializado
gcc -Wmaybe-uninitialized arquivo.c -o programa

# Auto-inicialização
gcc -Winit-self arquivo.c -o programa

# Habilitar OpenMP
gcc -fopenmp arquivo.c -o programa
```

```bash
#include <omp.h>
#include <stdio.h>

int main()
{
  #pragma omp parallel
  printf("Thread %d\n", omp_get_thread_num());
  return 0;
}

gcc -fopenmp paralelo.c -o paralelo
```

---

## 📜 Flags de Padrão (STDC)

Essas flags forçam o compilador a seguir versões específicas da linguagem.
Garantindo que o código seja compatível com uma versão específica da linguagem C.

- `-std=c89` ou `-std=c90`: Segue o padrão ANSI C de 1989/1990. É útil quando se precisa garantir a
  compatibilidade com versões muito antigas do compilador.
- `-std=c99`: Utiliza o padrão C99, que introduziu novos recursos como variáveis declaradas em qualquer lugar
  (não só no início da função), novos tipos de dados (como long long), entre outras melhorias.
- `-std=c11`: Utiliza o padrão C11, que trouxe melhorias como suporte nativo a threads (programação concorrente),
  além de novos recursos de otimização.
- `-std=c17` ou `-std=c18`: Versões mais recentes do C11, com algumas correções de bugs e pequenas melhorias.

```bash
# Padrão ANSI C 1989/1990
gcc -std=c89 arquivo.c -o programa
gcc -std=c90 arquivo.c -o programa

# Padrão C99
gcc -std=c99 arquivo.c -o programa

# Padrão C11
gcc -std=c11 arquivo.c -o programa

# Padrões recentes
gcc -std=c17 arquivo.c -o programa
gcc -std=c18 arquivo.c -o programa
```

---

## 🧩 Warnings Avançados (GCC Diagnostic)

Essas flags permitem uma verificação mais aprofundada do seu código e podem ajudar a identificar
comportamentos errôneos ou potencialmente perigosos:

- `Wuninitialized`: Avisa quando uma variável pode ser usada sem ter sido inicializada. É útil para detectar
  bugs que podem ser difíceis de encontrar.
- `Wmaybe-uninitialized`: Avisa quando o compilador não pode garantir que uma variável foi inicializada
  corretamente, especialmente em fluxos de controle complexos.
- `Winit-self`: Avisa quando uma variável é inicializada com ela mesma, o que é geralmente um erro de programação.

```bash
# Variáveis não inicializadas
gcc -Wuninitialized arquivo.c -o programa

# Possível uso não inicializado
gcc -Wmaybe-uninitialized arquivo.c -o programa

# Auto-inicialização
gcc -Winit-self arquivo.c -o programa
```

---

## 🚫 Flags para Ignorar/Suprimir Avisos Específicos

- `Wno-unused-parameter`: Parâmetros não usados callbacks, implementações parciais.
- `Wno-unused-variable`: Variáveis não usadas variáveis para debug futuro.
- `Wno-unused-function`: Funções não usadas funções de biblioteca não chamadas.
- `Wno-uninitialized`: Variáveis não inicializadas código legado com inicialização complexa.
- `Wno-maybe-uninitialized`: Inicialização incerta fluxos condicionais complexos.
- `Wno-init-self`: Auto-inicialização código que precisa ser compatível.

```bash
# Suprime aviso de parâmetros não usados (callbacks, implementações parciais)
gcc -Wno-unused-parameter arquivo.c -o programa

# Suprime aviso de variáveis não usadas (variáveis para debug futuro)
gcc -Wno-unused-variable arquivo.c -o programa

# Suprime aviso de funções não usadas (funções de biblioteca não chamadas)
gcc -Wno-unused-function arquivo.c -o programa

# Suprime aviso de variáveis não inicializadas (código legado com inicialização complexa)
gcc -Wno-uninitialized arquivo.c -o programa

# Suprime aviso de inicialização incerta (fluxos condicionais complexos)
gcc -Wno-maybe-uninitialized arquivo.c -o programa

# Suprime aviso de auto-inicialização (código que precisa ser compatível)
gcc -Wno-init-self arquivo.c -o programa
```

---

## 👨🏻‍💻 Exemplos Práticos de Combinações de Flags

As flags podem ser usadas **isoladamente** ou **combinadas** conforme a necessidade para criar conjuntos.
que otimizam a compilação, melhoram a depuração e garantem a qualidade do código de forma consistente.

### 👨🏻‍💻 Pode-se construir flags para desenvolvimento

```bash
# Querer ver todos os avisos e erros do código e facilitar a depuração
gcc arquivo.c -Wall -Wextra -g -o programa

# Quando já não precisa tanto de avisos e quer gerar um executável otimizado
gcc arquivo.c -O2 -o programa

# Para garantir a conformidade com um padrão mais antigo
gcc arquivo.c -std=c99 -Wall -o programa
```

---

### 👨🏻‍💻 Criação de Conjuntos de Flags

```bash
# Conjunto para desenvolvimento e depuração: Este conjunto ativa todos os avisos importantes
# e adiciona informações de depuração, facilitando a identificação de problemas.
gcc arquivo.c -Wall -Wextra -Wshadow -Wconversion -Wpedantic -g -o programa

# Conjunto para produção e otimização: Foca em otimizar o código para performance e trata todos os avisos como erros, garantindo maior rigor.
gcc arquivo.c -O2 -Werror -std=c11 -o programa

# Conjunto para garantir padrões e qualidade: Esse conjunto foca em garantir que o código seja escrito
# conforme os padrões e que não haja problemas de inicialização de variáveis,
# com flags para fazer o código aderir estritamente ao padrão C11.
gcc arquivo.c -std=c11 -Wuninitialized -Wmaybe-uninitialized -Wpedantic -Wshadow -Wconversion -o programa

# Primeiro: veja todos os warnings
gcc -Wall -Wextra arquivo.c -o programa

# Depois: suprima apenas os problemáticos
gcc -Wall -Wextra -Wno-unused-parameter -Wno-unused-variable -o programa arquivo.c

# Exemplo de fluxo completo
gcc -Wall -Wextra -g -O0 -o programa_dev arquivo.c    # Desenvolvimento
gcc -Wall -Wextra -O2 -o programa_test arquivo.c      # Testes
gcc -O2 -o programa_final arquivo.c                   # Produção

# Durante desenvolvimento - todos os avisos ativos
gcc -Wall -Wextra -Wshadow -Wconversion -Wuninitialized arquivo.c -o programa

# Para produção - suprime avisos menos críticos
gcc -Wall -Wno-unused-parameter -Wno-unused-variable arquivo.c -o programa

# Código legado com muitos falsos positivos
gcc -Wall -Wno-uninitialized -Wno-maybe-uninitialized arquivo.c -o programa
```

## ⚠️ Cuidados Importantes

- Use `-Wall` `-Wextra` primeiro: Veja todos os avisos antes de suprimir qualquer um suprima seletivamente:
  Não use -w (que suprime TODOS os avisos). Documente o motivo: Comente por que cada aviso está sendo suprimido
  Tenha preferência na correção do código

```bash
# // Em vez de suprimir -Wunused-parameter:

void callback(int param)
{
  (void)param;  # // Solução no código - melhor prática
}
```

```bash
# 1. Primeiro compile com todos os avisos
gcc -Wall -Wextra -Wshadow -Wconversion arquivo.c -o programa

# 2. Analise cada aviso e decida: corrigir ou suprimir?
# 3. Se necessário, suprima avisos específicos
gcc -Wall -Wextra -Wno-unused-parameter -Wno-unused-variable arquivo.c -o programa

# 4. Para produção, considere -Werror para tratar warnings como errors
gcc -Wall -Wextra -Werror arquivo.c -o programa
```

---

## 🛠️ Automação com Scripts e Makefiles

- Um `script` é basicamente um arquivo de texto que guarda comandos que você normalmente
  digitaria no terminal. Ele guarda o comando gcc para compilar o programa.

- Um `Makefile` é um arquivo especial usado pelo comando make para automatizar a compilação
  de projetos maiores. Ele entende dependências entre arquivos e só recompila o que mudou.

---

| **Método** | **Quando Usar**                                | **Vantagens**                                                         |
| ---------- | ---------------------------------------------- | --------------------------------------------------------------------- |
| Script     | Projetos pequenos ou rápidos                   | Simples e rápido de criar e usar                                      |
| Makefile   | Projetos médios ou grandes com muitos arquivos | Organiza dependências e recompila apenas o necessário                 |
| CMake      | Projetos multiplataforma ou complexos          | Gera Makefiles ou projetos para diferentes compiladores e plataformas |

---

## CONCLUSÃO

Há várias flags que você poderá captar ao decorrer de seu ensino, aqui eu citei apenas para
os mais conhecidos e para se ter uma base. Além de flags que não foram citadas. Exemplo:

- `-lm`: Vincula a biblioteca matemática (necessária para funções como `sin`, `cos`, etc.).
- `-L caminho`: Especifica um diretório para buscar bibliotecas externas.
- `-D NOME=VALOR`: Define uma macro diretamente no comando de compilação.
- `DNDEBUG`: Desativa asserções para builds de produção, reduzindo verificações de depuração.
- `save-temps`: Preserva arquivos intermediários (pré-processado, assembly, objeto) para análise ou aprendizado.

> `gcc -D DEBUG=1 arquivo.c -o programa` define a macro `DEBUG` com valor 1.  
> `gcc -save-temps arquivo.c -o programa`  
> `gcc -DNDEBUG -save-temps -Wall arquivo.c -o programa`

Esse é o poder da compilação em C/C++: você praticamente conversa diretamente com a máquina,
dizendo o que ela deve fazer e como deve fazer.

---

## REFERÊNCIA

- [GCC Option Summary](https://gcc.gnu.org/onlinedocs/gcc/Option-Summary.html)
