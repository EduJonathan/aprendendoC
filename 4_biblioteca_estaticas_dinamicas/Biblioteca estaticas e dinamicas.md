# 📚 Biblioteca estáticas e dinâmicas

**Site Referência para explicação sobre bibliotecas**
![Site terminal root](https://terminalroot.com.br/2024/09/diferenca-entre-bibliotecas-estatica-e-dinamica.html#google_vignette)

## Bibliotecas(lib)

São coleções de funções e recursos usados para desenvolver software. Elas ajudam a evitar a repetição de código,
facilitam a manutenção e permitem a reutilização de código em diferentes programas.

Existem dois tipos principais de bibliotecas:

- Bibliotecas estáticas;
- Bibliotecas dinâmicas (ou compartilhada).

---

## Biblioteca Estática

Uma biblioteca estática é um arquivo que contém código objeto, que é vinculado (linkado) ao programa no momento da compilação.

### Características

- **Extensão do Arquivo**: Em sistemas Unix-like, as bibliotecas estáticas normalmente têm a extensão `.a`(archive),
  enquanto no Windows, a extensão é `.lib`.

- **Linkagem**: O código da biblioteca é copiado para o executável final durante o processo de linkagem.
  Isso resulta em um executável maior, pois contém todo o código da biblioteca necessário.

- **Performance**: Como todo o código necessário já está presente no executável, a execução tende a ser mais rápida.
  No entanto, isso também significa que qualquer atualização na biblioteca requer a recompilação do programa.

- **Portabilidade**: O executável é auto-suficiente, não depende da presença de arquivos de biblioteca
  no sistema onde será executado.

---

### Vantagens

- Não há dependência externa em tempo de execução.
- Pode ser mais rápida devido à ausência de overhead de ligação dinâmica.

---

### Desvantagens

- Maior tamanho do executável.
- Dificuldade em atualizar bibliotecas, pois requer recompilação e redistribuição do executável.

---

## Biblioteca Dinâmica (compartilhada)

Uma biblioteca dinâmica é um arquivo que contém código objeto que é carregado em tempo de execução,
permitindo que múltiplos programas usem a mesma biblioteca.

### Qualidades

- **Extensão do Arquivo:** Em sistemas Unix-like, as bibliotecas dinâmicas normalmente têm a extensão `.so`(shared object),
  enquanto no Windows, a extensão é `.dll` (dynamic-link library).

- **Linkagem:** O código da biblioteca é vinculado ao programa em tempo de execução, não durante a compilação.
  Isso resulta em um executável menor, pois o código da biblioteca não está incluído.

- **Performance:** Pode haver uma leve sobrecarga na execução devido à necessidade de carregar e ligar
  a biblioteca em tempo de execução.

- **Portabilidade:** O executável depende da presença da biblioteca compartilhada no sistema onde será executado.
  Se a biblioteca não estiver presente, o programa não funcionará.

### Aplicabilidade

- Menor tamanho do executável.
- Facilidade de atualização das bibliotecas sem recompilar o executável.
- Redução de uso de memória, já que a mesma biblioteca pode ser compartilhada entre múltiplos processos.

### Malefícios

- Dependência da biblioteca estar disponível em tempo de execução.
- Possíveis conflitos de versão (problema de `DLL Hell`).
