# CMake: Sistema de Construção para Projetos C/C++

## O que é o CMake?

CMake é uma ferramenta de código aberto usada para gerenciar o processo de construção (build)
de projetos de software, principalmente em linguagens como C/C++. Ele é um
**sistema de construção multiplataforma** que automatiza a configuração, compilação e instalação
de projetos, eliminando a necessidade de **configurar manualmente** arquivos de build para diferentes
sistemas operacionais (Windows, Linux, macOS) ou compiladores (GCC, Clang, MSVC, etc.).

Diferentemente de ferramentas como o `make`, que dependem de Makefiles específicos para
cada plataforma, o CMake gera arquivos de build nativos (como Makefiles no Linux ou soluções
Visual Studio no Windows) a partir de um conjunto de scripts de configuração escritos em sua
própria linguagem. Esses scripts são definidos em arquivos chamados `CMakeLists.txt`.

O CMake é amplamente utilizado em projetos de grande escala, como bibliotecas (Boost, OpenCV)
e softwares (KDE, MySQL), devido à sua flexibilidade e capacidade de lidar com dependências complexas.

## Como o CMake se compara a outras ferramentas?

Embora o CMake seja frequentemente associado a C/C++, ele pode ser comparado a ferramentas
de gerenciamento de construção e configuração em outras linguagens de programação.
Abaixo, apresentamos uma comparação com ferramentas equivalentes:

---

| Linguagem      | Ferramenta             | Função Principal                                                           |
| -------------- | ---------------------- | -------------------------------------------------------------------------- |
| **C/C++**      | **CMake**              | Gera arquivos de build para compilar projetos em diferentes plataformas.   |
| **Python**     | **venv / pip**         | Cria ambientes virtuais para isolar dependências e gerenciar pacotes.      |
| **Java**       | **Maven / Gradle**     | Gerencia dependências, compila e empacota projetos Java.                   |
| **C#**         | **MSBuild / .NET CLI** | Automatiza a construção e gerenciamento de projetos .NET.                  |
| **JavaScript** | **npm / Yarn**         | Gerencia pacotes, scripts e dependências para projetos JavaScript/Node.js. |

Enquanto ferramentas como `venv` (Python) ou `npm` (JavaScript) focam no gerenciamento
de dependências e ambientes, o CMake é mais voltado para a **compilação** e
**configuração de builds**, lidando com aspectos como:

- Localização de bibliotecas externas.
- Configuração de compiladores e flags de compilação.
- Geração de arquivos de build para múltiplas plataformas.
- Suporte a testes automatizados e instalação de projetos.

---

## Por que usar o CMake?

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

## Boas Práticas no CMake

- Use `target_include_directories` em vez de `include_directories`.
- Prefira `PUBLIC`, `PRIVATE` e `INTERFACE` para controle de visibilidade.
- Estruture o projeto em subdiretórios claros: `include/`, `src/`, `tests/`.

---

## Recursos Adicionais

- [CMake Tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)
- [Fórum Discourse do CMake](https://discourse.cmake.org/)
- **CPack**: Gere instaladores com `cpack -G DEB`.

---

## Integração com IDEs

O CMake se integra bem com IDEs populares:

- **Visual Studio**: Gere uma solução com `cmake -G "Visual Studio 17 2022" ..` e abra o arquivo `.sln` gerado.
- **CLion**: Abra a pasta do projeto; o CLion detecta automaticamente o `CMakeLists.txt`.
- **VS Code**: Use a extensão "CMake Tools" para configurar e compilar projetos diretamente.

---

## Exemplo Básico de Uso

### Suponha que tenhas este diretório

MeuProjeto/
├── CMakeLists.txt
├── src/
│ └── main.cpp
└── include/
└── meu_header.hpp

> O caminho do diretório no terminal estará algo como: `C:\Users\NomeUsuario\Documents\MeuProjeto\`

---

### Conteúdo do CMakeLists.txt

Para o diretório descrito (`C:\Users\NomeUsuario\Documents\MeuProjeto`),
o arquivo `CMakeLists.txt` pode ser configurado assim:

```cmake
cmake_minimum_required(VERSION 3.10)
project(MeuProjeto VERSION 1.0 LANGUAGES CXX)

# Define o padrão C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Adiciona o diretório de includes
target_include_directories(meu_programa PRIVATE include)

# Adiciona o executável
add_executable(meu_programa src/main.cpp)
```

---

### 1. Navegue até a pasta do projeto

C:\Users\NomeUsuario\Documents> cd MeuProjeto  
C:\Users\NomeUsuario\Documents\MeuProjeto> dir  
Volume in drive C has no label.  
Directory of C:\Users\NomeUsuario\Documents\MeuProjeto

CMakeLists.txt  
src  
include

### 2. Crie um diretório separado para a build

C:\Users\NomeUsuario\Documents\MeuProjeto> mkdir build (Aqui você irá criar a build em MeuProjeto)
C:\Users\NomeUsuario\Documents\MeuProjeto> cd build (Vá para a pasta build)

### 3. Gere os arquivos de build com CMake

`C:\Users\NomeUsuario\Documents\MeuProjeto\build> cmake ..`

`-- The C compiler identification is MSVC 19.35.32215.0`  
`-- The CXX compiler identification is MSVC 19.35.32215.0`  
`-- Detecting C compiler ABI info`  
`-- Detecting C compiler ABI info - done`  
`-- Configuring done`  
`-- Generating done`  
`-- Build files have been written to: C:/Users/NomeUsuario/Documents/MeuProjeto/build`

### 4. (Opcional) Para gerar projeto Visual Studio no Windows

C:\Users\NomeUsuario\Documents\MeuProjeto\build> `cmake -G "Visual Studio 17 2022" ..`

## 5. Compile o projeto

C:\Users\NomeUsuario\Documents\MeuProjeto\build> `cmake --build .` ou `ninja` se for o caso

`[ 50%] Building CXX object CMakeFiles\meu_programa.dir\src\main.cpp.obj`  
`[100%] Linking CXX executable meu_programa.exe`  
`[100%] Built target meu_programa`

### 6. Execute o programa

C:\Users\NomeUsuario\Documents\MeuProjeto\build> `.\meu_programa.exe`  
**Olá, mundo! Meu programa C++ compilou com CMake!**

### 7. Limpar a build (opcional)

C:\Users\NomeUsuario\Documents\MeuProjeto\build> `rmdir /s /q \*`

---

### 🔍 Observação: Recompilando Após Alterações

Após realizar alterações em arquivos `.hpp` ou `.cpp`, é necessário recompilar o projeto
para que as mudanças sejam aplicadas. Para isso, execute novamente o comando de compilação
na pasta `build`:

```bash
cmake --build .
```
