# 🔨 CMake: Sistema de Construção para Projetos C/C++

## O que é o CMake?

CMake é uma ferramenta de código aberto usada para gerenciar o processo de construção (build)
de projetos de software, principalmente em linguagens como C/C++.

Ele é um **sistema de construção multiplataforma** que automatiza a _configuração_, _compilação_
e instalação de projetos, eliminando a necessidade de **configurar manualmente** arquivos de build
para diferentes sistemas operacionais `(Windows, Linux, macOS)` ou compiladores `(GCC, Clang, MSVC, etc.)`.

> Esses scripts são definidos em arquivos chamados `CMakeLists.txt`.

O CMake é amplamente utilizado em projetos de grande escala, como bibliotecas (Boost, OpenCV)
e softwares (KDE, MySQL), devido à sua flexibilidade e capacidade de lidar com dependências complexas.

---

## Como o CMake se compara a outras ferramentas?

Embora o CMake seja frequentemente associado a C/C++, ele pode ser comparado a ferramentas de gerenciamento de construção
e configuração em outras linguagens de programação.

> Abaixo, apresentamos uma comparação com ferramentas equivalentes:

| Linguagem      | Ferramenta             | Função Principal                                                           |
| -------------- | ---------------------- | -------------------------------------------------------------------------- |
| **C/C++**      | **CMake**              | Gera arquivos de build para compilar projetos em diferentes plataformas.   |
| **Python**     | **venv / pip**         | Cria ambientes virtuais para isolar dependências e gerenciar pacotes.      |
| **Java**       | **Maven / Gradle**     | Gerencia dependências, compila e empacota projetos Java.                   |
| **C#**         | **MSBuild / .NET CLI** | Automatiza a construção e gerenciamento de projetos .NET.                  |
| **JavaScript** | **npm / Yarn**         | Gerencia pacotes, scripts e dependências para projetos JavaScript/Node.js. |

Enquanto ferramentas como `venv` (em Python) ou `npm` (em JavaScript) focam no gerenciamento de dependências e ambientes,
o CMake é mais voltado para a **compilação** e **configuração de builds**, lidando com aspectos como:

- Localização de bibliotecas externas.
- Configuração de compiladores e flags de compilação.
- Geração de arquivos de build para múltiplas plataformas.
- Suporte a testes automatizados e instalação de projetos.

---

## ⁉️ Por que usar o CMake?

O CMake oferece várias vantagens para desenvolvedores de C/C++:

1. **Portabilidade**: Funciona em diferentes sistemas operacionais e compiladores, garantindo que o mesmo script `CMakeLists.txt` possa ser usado em múltiplas plataformas.
2. **Automação**: Reduz a necessidade de configurar manualmente compiladores, caminhos de bibliotecas e dependências.
3. **Flexibilidade**: Suporta projetos complexos com múltiplos módulos, bibliotecas e executáveis.
4. **Integração**: Compatível com ferramentas de teste (como CTest) e empacotamento (como CPack).
5. **Comunidade**: Amplamente adotado, com vasta documentação e suporte em projetos de código aberto.

---

## CMake vs. Make vs. Ninja

- **Make**: Usa Makefiles, mas requer configuração manual para cada plataforma.
- **Ninja**: Mais rápido que o Make, mas depende de geradores como o CMake.
- **CMake**: Gera arquivos para Make ou Ninja, oferecendo portabilidade.

---

## Exemplo Básico de Uso

### 🗂️ Suponha que tenhas este hierarquia de diretório

MeuProjeto/ `# <- diretório pastas raiz`  
├── CMakeLists.txt `# <- CMakeLists.txt escreva dessa maneira`  
├── src/ `# <- Diretório que fica todas as implementações de código fonte(funções e main)`  
│ └── main.c  
└── include/ `# <- Diretório que fica todas as declarações do código(protótipos de funções, structs)`  
 └── meu_header.h

> Exemplo de caminho no terminal (Windows): `C:\Users\NomeUsuario\Documents\MeuProjeto\`  
> Exemplo de caminho no terminal (Linux): `~/home/eduardo/Documentos/aprendendoC/3_CMake/MeuProjeto`

---

## 🏗️ Como criar um Cmake

Ao trabalhar com CMake, sempre esteja no diretório raiz do projeto, ou seja, onde está localizado o arquivo `CMakeLists.txt`.
criado por antes mesmo da build, este diretório é o ponto de referência para:

- caminhos relativos
- arquivos de código-fonte
- diretórios de include
- criação da pasta `build/`

Tendo este conceito em mente, estando em seu projeto `~/home/eduardo/Documentos/aprendendoC/3_CMake/MeuProjeto`
e já tendo configurado seu arquivo `CMakeLists.txt`, com a seguinte configuração

---

```cmake
cmake_minimum_required(VERSION 3.10)

# Nome do projeto
project(MeuProjeto C)

# Define o padrão da linguagem C
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Diretório dos headers
include_directories(include)

# Cria o executável
add_executable(meu_programa
    src/main.c
)

target_include_directories(meu_programa
    PRIVATE include
)
```

---

Logo após a configuração do cmake, começarmos criação da build, estando novamente como dito dentro de seu projeto raiz

```bash
# 🐧 Linux
eduardo@jonathan:~/Documentos/aprendendoC/3_CMake/MeuProjeto

mkdir build       # Cria a pasta build
cd build          # Altera seu posicionamento atual de MeuProjeto -> MeuProjeto/build
cmake ..          # Configura o projeto usando o CMakeLists.txt da raiz
cmake -G Ninja .. # Usando o gerador Ninja (opcional), e se você tiver instalado

# -----

# 🪟 Windows (PowerShell)
PS C:\\Users\\NomeUsuario\\Documents\\MeuProjeto\\

mkdir build # Cria a pasta build
cd build    # Altera seu posicionamento atual de MeuProjeto -> MeuProjeto/build
cmake ..    # Configura o projeto usando o CMakeLists.txt da raiz
```

> O comando cmake .. diz: "Use o `CMakeLists.txt` que está um nível acima (diretório raiz)"  
> Nunca execute cmake fora da pasta build. Isso evita arquivos de build espalhados pelo projeto.
> Use apenas **um** gerador por diretório build. Não execute `cmake ..` e depois `cmake -G Ninja ..` no mesmo build

---

## 🔨 Compilando

Após a configuração:

```bash
    cmake --build . # Irá gerar o executável
    Ninja           # Caso Você tenha utilizado cmake -G Ninja ..

```

- `Linux/macOs`: meu_programa
- `Windows`: meu_programa.exe

---

MeuProjeto/  
├── CMakeLists.txt  
├── src/  
│ └── main.c  
├── include/  
│ └── meu_header.h  
└── build/  
├── CMakeCache.txt  
├── Makefile / build files  
└── meu_programa

> Lembre-se de realizar todos estes passos no terminal de seu sistema operacional

---

## ⚠️ CUIDADOS

Tenha SEMPRE atenção aos nomes de **arquivos** e **diretórios(pastas)**. Alterações fora do código,
como renomear pastas ou arquivos, podem quebrar o projeto, pois os caminhos passam a não existir.

Exemplo de problema

Suponha que você renomeie os seguintes:

- MeuProjeto → Projeto (Nome do diretório do exemplo acima)
- meu_header.h → header.h (Nome do arquivo do exemplo acima)

Toda essa alteração, já causa um _efeito colateral_ muito forte

❗ Efeito colateral

Renomear arquivos ou diretórios exige:

- Atualizar os caminhos e referências de arquivos no `CMakeLists.txt`
- Atualizar tanto os caminhos no `CMakeLists.txt`, igualmente os caminhos `CMakeLists.txt` dentro do pasta `build/`
- Caso não funcionar possivelmente apagar e recriar a pasta `build/` e recompilar

> Se algo estranho acontecer com o CMake, apague a pasta build/ e gere novamente.

---

## Recursos Adicionais

- [CMake Tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)
- [Fórum Discourse do CMake](https://discourse.cmake.org/)
- **CPack**: Gere instaladores com `cpack -G DEB`.

---

### 🛠️ Tipos De Construção

Atualmente, contamos com 3 formas de construir (buildar) o projeto, cada uma indicada
para um nível diferente de complexidade e crescimento do código.

---

> **Scripts Shell (.sh)**: Automatizam os comandos do compilador. Exemplo:`./scripts/build.s`

| Característica/Aspecto         | Descrição                                                                                                             |
| ------------------------------ | --------------------------------------------------------------------------------------------------------------------- |
| **Objetivo Central**           | Centraliza o comando `gcc` (ou outros comandos de build).                                                             |
| **Vantagens**                  | Simples, fácil de modificar, ideal para aprendizado.                                                                  |
| **Otimização de Processo**     | Evita repetição de comandos complexos e longos.                                                                       |
| **Facilidade de Uso**          | Facilita a compilação, execução e limpeza do projeto.                                                                 |
| **Arquivos Comuns (Exemplos)** | `build.sh` (para compilar o projeto), `run.sh` (para executar o binário), `clean.sh` (para remover arquivos gerados). |
| **Quando Usar (Cenário)**      | Projetos pequenos a médios, ambientes Linux, organização inicial de projeto.                                          |
| **Desvantagens**               | Não resolve dependências automaticamente, pouca portabilidade entre sistemas (principalmente fora do Unix-like).      |

---

> **Makefile (make)**: Sistema clássico de automação de builds em C/C++.

| Categoria                      | Aspecto                       | Detalhe                                                                                                    |
| ------------------------------ | ----------------------------- | ---------------------------------------------------------------------------------------------------------- |
| **Funcionalidade Principal**   | Regras de Compilação          | Define regras explícitas (targets, prerequisites e commands) para o processo de build.                     |
| **Otimização do Processo**     | Compilação Seletiva           | **Compila apenas arquivos modificados** (baseado no timestamp), economizando tempo.                        |
|                                | Gerenciamento de Dependências | **Gerencia dependências automaticamente** (se um arquivo `header` mudar, recompila os `.c` que o incluem). |
| **Casos de Uso (Quando Usar)** | Tamanho do Projeto            | Ideal para **projetos médios**.                                                                            |
|                                | Complexidade                  | Recomendado para projetos com **vários arquivos .c e .h**.                                                 |
|                                | Contexto                      | Usado em um **desenvolvimento mais profissional** e estruturado.                                           |
| **Vantagens**                  | Velocidade                    | O processo de compilação é **rápido** devido à compilação seletiva.                                        |
|                                | Padrão Industrial             | **Muito usado na indústria** (padrão em projetos Unix/Linux).                                              |
|                                | Controle                      | Permite um **controle fino** e detalhado sobre o processo de build.                                        |
| **Desvantagens**               | Sintaxe                       | Possui uma **sintaxe sensível** e rígida (o caractere **TAB** é **obrigatório** para indentar comandos).   |
|                                | Escalabilidade                | Pode se tornar **complexo** e difícil de manter em **projetos muito grandes**.                             |

---

> **CMake**: Ferramenta moderna de geração de build, não compila diretamente.

| Categoria                      | Aspecto                   | Detalhe                                                                                                                                                            |
| ------------------------------ | ------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| **Funcionalidade Principal**   | Sistema de Metaconstrução | **Gera Makefiles** (no Linux/macOS), arquivos de projeto para Visual Studio (no Windows), ou outros sistemas de build.                                             |
| **Portabilidade**              | Build Multiplataforma     | Facilita a criação de builds **multiplataforma** a partir de um único conjunto de arquivos de configuração (`CMakeLists.txt`).                                     |
| **Gerenciamento**              | Bibliotecas Externas      | Possui ferramentas avançadas para **gerenciar e encontrar bibliotecas externas** (como SDL2, SFML, etc.).                                                          |
| **Casos de Uso (Quando Usar)** | Tamanho do Projeto        | Ideal para **projetos grandes** e complexos.                                                                                                                       |
|                                | Ambiente                  | Essencial para projetos que precisam ser compilados em **múltiplas plataformas** (Linux, Windows, macOS, etc.).                                                    |
|                                | Dependências              | Quando há **uso significativo de bibliotecas externas** de terceiros.                                                                                              |
| **Vantagens**                  | Escalabilidade            | É **altamente escalável**, suportando a complexidade de grandes bases de código.                                                                                   |
|                                | Padrão Industrial         | Considerado o **padrão moderno** para o gerenciamento de builds em projetos C/C++.                                                                                 |
|                                | Aplicações                | Ideal para projetos como **motores de jogos**, bibliotecas complexas e aplicações de nível empresarial.                                                            |
| **Desvantagens**               | Curva de Aprendizado      | Possui uma **curva de aprendizado maior** devido à sua própria linguagem de script e ecossistema.                                                                  |
|                                | Complexidade no Setup     | Envolve **mais arquivos e etapas** de configuração (primeiro o CMake é executado para gerar os arquivos de build, e depois o sistema de build gerado é executado). |
