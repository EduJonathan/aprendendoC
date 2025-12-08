# Interfaces Gráficas (GUI)

`GUI` _(Graphical User Interface)_ é todo tipo de interface gráfica utilizada por um programa
para interação com o usuário. Diferente de aplicações em modo texto, uma GUI depende de elementos
visuais como `janelas`, `botões`, `menus`, `ícones` e `caixas de diálogo`.

GUI também está diretamente ligada à **programação orientada a eventos**, onde a aplicação reage a ações do usuário, como:

- cliques do mouse.
- pressionamento de teclas.
- movimentação do cursor.
- redimensionamento de janelas.
- eventos do sistema operacional.

Ou seja, uma `GUI` não segue uma sequência linear tradicional de código, mas responde continuamente aos eventos disparados.

## Tempos Passados

No início da computação pessoal, em sistemas operacionais como `DOS`, a criação de interfaces gráficas
era bastante limitada. Desenvolvedores recorriam a ferramentas como a `Turbo BGI (Borland Graphics Interface)`,
que permitia desenhar elementos simples como linhas, círculos e textos em modo gráfico.

Além disso, versões mais antigas de `C` utilizavam implementações iniciais de `GL (Graphics Library)`,
precursoras do que mais tarde se tornaria o `OpenGL`. Embora já possibilitassem renderizações mais complexas,
ainda estavam distantes das capacidades gráficas modernas.

---

## OpenGL

O `OpenGL (Open Graphics Library)` é uma API multiplataforma projetada para renderização
`2D` e principalmente `3D`, oferecendo acesso direto aos recursos da GPU.

### Vantagens do OpenGL

- Alto desempenho graças ao uso intensivo da GPU.
- Extremamente flexível para gráficos complexos.
- Multiplataforma e suportado por vários dispositivos.
- Permite renderização moderna usando shaders, buffers e pipeline programável.

### Limitações do OpenGL

- Curva de aprendizado elevada, especialmente para iniciantes.
- Muitas tarefas simples exigem muito código e gerenciamento manual.
- Precisa ser combinado com outras bibliotecas para lidar com janelas, entrada, áudio etc.

### Casos de uso ideais

- Jogos 3D.
- Simuladores.
- Softwares de CAD.
- Engines gráficas personalizadas.
- Animações de alta performance.

### 📗 OpenGL — Documentação Oficial

- **Página Oficial (Khronos Group):**  
  [OpenGL – Khronos Group](https://www.khronos.org/opengl/)

- **Reference Pages (Documentação Oficial das Funções):**  
  [OpenGL Reference Pages](https://www.khronos.org/registry/OpenGL-Refpages/)

---

## SDL

A `SDL (Simple DirectMedia Layer)` é uma biblioteca multiplataforma de nível mais alto,
criada para facilitar o desenvolvimento de aplicações multimídia e jogos.

### Vantagens da SDL

- Fácil de aprender e usar comparada ao OpenGL.
- Oferece gerenciamento completo de janelas, entrada, áudio, arquivos e timers.
- Excelente para jogos 2D.
- Permite usar OpenGL junto com ela (SDL cria a janela e o contexto gráfico).
- Código simples e direto.

### Limitações da SDL

- Renderização 2D limitada se comparada ao OpenGL.
- Não é focada em gráficos 3D (embora possa ser usada como base para `OpenGL/Vulkan`).
- Para projetos muito grandes, pode exigir construção de sistemas adicionais manualmente.

### Casos de uso

- Jogos 2D.
- Emuladores.
- Aplicações multimídia simples.
- Protótipos rápidos.
- Ferramentas com interface gráfica leve.

### 📘 SDL – Documentação Oficial

- **Site Oficial:**  
  [SDL – Site Oficial](https://www.libsdl.org)

- **Documentação (Wiki):**  
  [SDL Wiki – Documentação Oficial](https://wiki.libsdl.org)

> As wiki contém tutoriais, referência completa das funções, exemplos e guias de configuração para todas as plataformas suportadas.
