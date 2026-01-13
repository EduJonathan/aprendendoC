<!-- @format -->

# 📌 STREAMS

## ❓ O que é uma Stream?

Antes de entender arquivos, precisamos compreender o conceito de stream.
Uma stream (ou fluxo) é um conceito fundamental em programação e representa uma sequência de dados que flui de uma origem para um destino.

> Podemos entender uma stream como uma via de mão única, pela qual os dados `entram` ou `saem` do programa.

---

🔁 Resumindo:

Uma stream é uma abstração que representa a transferência de dados entre o programa e o mundo exterior, como:

- teclado
- tela
- arquivos
- rede

---

## ❓ Diferença entre Arquivo e Stream

📁 Arquivo (File)

Um arquivo é um objeto físico ou lógico de armazenamento gerenciado pelo sistema operacional.
Representa dados armazenados de forma persistente em disco.

Exemplos:

- `.txt`
- `.jpg`
- `.mp3`
- `.c`
- `.py`

---

## 🌊 Stream

Uma stream é uma abstração de fluxo de dados, utilizada pelo programa para ler ou escrever dados.
Ela não representa o dado em si, mas sim o caminho por onde o dado flui.

Uma stream pode representar:

- Entrada: stdin (teclado), arquivos, sockets, etc.
- Saída: stdout (tela), arquivos, impressoras, sockets, etc.

---

## 📊 Comparação: Arquivo × Stream

| Conceito     | Arquivo                       | Stream                                    |
| ------------ | ----------------------------- | ----------------------------------------- |
| O que é?     | Objeto de armazenamento       | Canal/fluxo de comunicação de dados       |
| Armazena?    | Sim, dados persistem em disco | Não, apenas trafega dados temporariamente |
| Onde existe? | Sistema de arquivos (HD/SSD)  | Tempo de execução (memória)               |
| Exemplo      | `dados.txt`                   | `FILE *fp = fopen("dados.txt", "r");`     |

---

## 📁 Arquivos Em C

> Em C, há duas formas principais de trabalhar com arquivos, dependendo do formato dos dados que você deseja manipular:

---

## 📝 1. Arquivos de Texto (.txt)

Armazenam dados em formato legível para humanos. Os dados são gravados exatamente como seriam exibidos em um editor de texto.

Exemplos:

- números
- palavras
- frases

---

## 💾 2. Arquivos Binários (.bin)

Armazenam dados em formato binário, exatamente como estão representados na memória. São mais compactos e rápidos,
porém não legíveis diretamente.

Usados para:

- Armazenar estruturas (struct)
- Manipular grandes volumes de dados com melhor desempenho
- Evitar conversões entre texto e binário

---

## 🔓 Modos de abertura de arquivos

- r: Permissão de abertura somente para leitura. É necessário que o arquivo já esteja presente no disco.

- w: Permissão de abertura para escrita (gravação). Este código cria o arquivo caso
  ele não exista, e caso o mesmo exista ele recria o arquivo novamente fazendo com que
  o conteúdo seja perdido. Portanto devemos tomar muito cuidado ao usar esse tipo de abertura.

- a: Permissão para abrir um arquivo texto para escrita(gravação), permite acrescentar
  novos dados ao final do arquivo. Caso não exista, ele será criado.

---

## 📝 Modo de abertura de Arquivos de Texto

| Modo | Descrição                                                                  |
| ---- | -------------------------------------------------------------------------- |
| `r`  | Leitura. Arquivo deve existir, não apaga o conteúdo.                       |
| `w`  | Escrita. Cria arquivo se não existir, **apaga o conteúdo**.                |
| `a`  | Escrita em modo _append_. Cria arquivo se não existir, não apaga conteúdo. |
| `r+` | Leitura e escrita. Arquivo deve existir, não apaga conteúdo.               |
| `w+` | Leitura e escrita. Cria arquivo se não existir, **apaga conteúdo**.        |
| `a+` | Leitura e escrita (escreve no final). Cria arquivo se não existir.         |

---

## 💾 Modo de abertura de Arquivos Binários

| Modo  | Descrição                                          |
| ----- | -------------------------------------------------- |
| `rb`  | Leitura binária. Arquivo deve existir.             |
| `wb`  | Escrita binária. Cria ou apaga conteúdo existente. |
| `ab`  | Escrita binária em modo _append_.                  |
| `rb+` | Leitura e escrita binária. Arquivo deve existir.   |
| `wb+` | Leitura e escrita binária. Cria ou apaga conteúdo. |
| `ab+` | Leitura e escrita binária (escreve no final).      |

---

## 💭 Curiosidade

> É possível criar arquivos como .docx, .xlsx, .json e outros formatos complexos utilizando C.

⚠️ Porém:

A linguagem C não oferece suporte nativo para manipular diretamente esses formatos.
Esses arquivos são estruturados, geralmente compostos por ZIP + XML.
Diferentemente de linguagens como Python, C depende de bibliotecas externas(de terceiros instalado por fora).

📚 Exemplos de bibliotecas em C:

- libxml2 – Manipulação de XML
- libzip – Manipulação de arquivos compactados
- libxlsxwriter – Geração de arquivos Excel (.xlsx)
- cJSON – Manipulação de arquivos JSON

---

## 📎 Referência

[Stack Overflow (PT-BR)](https://pt.stackoverflow.com/questions/227339/o-que-%c3%a9-stream)
