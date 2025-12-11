# Interfaces Gráficas (GUI)

Uma GUI (Graphical User Interface) é toda interface visual utilizada por um programa para interação com o usuário.
Diferente de aplicações em modo texto (como consoles), a GUI depende de elementos visuais como:

- janelas
- botões
- menus
- ícones
- caixas de diálogo
- entradas de texto
- seletores (checkbox, dropdown etc.)

Esses componentes permitem que o usuário execute ações de forma intuitiva, utilizando
principalmente o mouse, o teclado e, em sistemas modernos, até toque.

---

## 🎮 Programação orientada a eventos

GUIs funcionam através de eventos. Ao invés de seguir um fluxo linear de cima para baixo, o programa:

1. fica escutando eventos gerados pelo usuário ou pelo sistema.
2. processa esses eventos quando acontecem.
3. atualiza a interface conforme necessário.

Eventos comuns incluem:

- cliques do mouse
- teclas pressionadas
- movimentação do cursor
- arrastar/soltar arquivos
- redimensionamento da janela
- foco/desfoque de elementos
- eventos internos do sistema operacional
- Isso cria uma aplicação sempre reativa.

---

## ✅ Vantagens de usar GUI

**Experiência intuitiva:**: Interfaces gráficas são mais fáceis de usar, especialmente para usuários iniciantes.
**Interatividade rica:**: É possível combinar vários tipos de entrada (mouse, teclado, toque).
**Layouts complexos:**: Permitem organizar muitos elementos em telas visuais elaboradas.
**Padrões estabelecidos:**: Bibliotecas como Qt, GTK, wxWidgets, ImGui, SDL2, SFML etc. já oferecem componentes prontos.
**Escalabilidade visual:**: Com esforços relativamente pequenos, é possível criar interfaces avançadas com menus, painéis e animações.

---

## ❌ Desvantagens de usar GUI

- **Complexidade maior:** A arquitetura orientada a eventos pode ser confusa para iniciantes, pois a execução não é linear.
- **Maior consumo de recursos:** GUIs exigem processamento e memória comparados a programas em modo texto.
- **Dependência de bibliotecas:** Cada plataforma pode exigir adaptações diferentes.
- **Depuração mais difícil:** Bugs podem surgir de interações complexas entre eventos.
- **Requer mais cálculos:** Mesmo com bibliotecas prontas, muitos aspectos dependem de lógica própria:
  - álgebra para posicionamento
  - cálculos de hitbox
  - manipulação de coordenadas
  - detecção de colisão entre elementos
  - gerenciamento de estados

> Interfaces gráficas tornam aplicativos mais amigáveis e modernos, porém exigem:
> cuidados com cálculos matemáticos,
> organização de estados,
> algoritmos bem estruturados,
> e atenção ao fluxo de eventos.
> Elas não seguem uma sequência linear tradicional — o programa reage ao usuário e ao sistema a todo momento.

---

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

### Casos de uso ideais da OpenGL

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

### Casos de uso da SDL

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

---

## SFML

A SFML `(Simple and Fast Multimedia Library)` é uma biblioteca multimídia moderna focada em simplicidade e produtividade.
Foi projetada principalmente para C++, mas também possui bindings para outras linguagens.

### Vantagens da SFML

- Sintaxe simples e amigável para iniciantes.
- Estrutura bem organizada em módulos: Graphics, Window, Audio, Network e System.
- Excelente para jogos 2D, animações e aplicações multimídia.
- Faz o gerenciamento de janelas, eventos e renderização de forma intuitiva.
- Biblioteca leve, fácil de compilar e usar em projetos pequenos e médios.

### Limitações da SFML

- Não possui renderização 3D nativa (pode ser integrada ao OpenGL, mas requer código adicional).
- Menos popular que SDL para projetos profissionais muito grandes.
- Comunidade menor que Qt e SDL, embora bastante ativa.

### Casos de uso ideais da SFML

- Jogos 2D de pequeno e médio porte.
- Prototipagem de mecânicas.
- Aplicações gráficas simples.
- Ferramentas visuais leves.
- Interfaces customizadas (não possui widgets como botões, então é tudo desenhado manualmente).

📘 SFML — Documentação Oficial

- **Site Oficial:**
  [Site Oficial](https://www.sfml-dev.org)

- **Reference Documentation:**
  [Reference Documentation](https://www.sfml-dev.org/documentation)

---

## Qt

O Qt é um dos frameworks de GUI mais poderosos e completos do mundo. É usado amplamente na indústria para
criar desde pequenas ferramentas até softwares complexos e multiplataforma, também projetada para C++ também.

### Vantagens do Qt

- Muito rico em widgets: botões, abas, menus, listas, tabelas, janelas, diálogos, formulários etc.
- Ferramentas visuais como o Qt Designer permitem criar interfaces arrastando e soltando.
- Sistema de signals/slots, que facilita a programação orientada a eventos.
- Suporte nativo a renderização 2D e 3D, áudio, rede, arquivos, bancos de dados e mais.
- Multiplataforma: Windows, Linux, macOS, Android, iOS e embarcados.
- Muito robusto para aplicações profissionais.

### Limitações do Qt

- Curva de aprendizado maior para iniciantes.
- Pesado comparado a SFML e SDL (por ser mais completo).
- Licenciamento pode ser complexo para empresas (GPL/LGPL/Comercial).
- Não é ideal para jogos — embora seja possível fazer, não é seu foco principal.

### Casos de uso ideais

Aplicações desktop profissionais (IDE, players de mídia, ferramentas administrativas).

- Softwares com GUI complexa.
- Aplicações multiplataforma com grande número de recursos.
- Ferramentas que exigem tabelas, formulários e navegação avançada.
- Aplicações industriais e de automação.

📗 Qt — Documentação Oficial

- **Site Oficial:**
  [SDL – Site Oficial](https://www.qt.io)

- **Qt Documentation:**
  [SDL Wiki – Documentação Oficial](https://doc.qt.io)

> As wiki contém tutoriais, referência completa das funções, exemplos e guias de configuração para todas as plataformas suportadas.
