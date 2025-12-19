# 🌐 REDES

Chegando a um dos tópicos mais avançados e complexos tecnicamente em praticamente todas as linguagens de programação.
Redes têm como objetivo estabelecer `comunicação` e `conexões` entre dois ou mais dispositivos, processos ou aplicações.

> De forma simples: **Rede** é troca de dados.

---

## 🌐📲 O que é comunicação em redes?

Comunicação em redes é o processo de:

- Enviar dados
- Receber dados
- Garantir que esses dados cheguem íntegros, na ordem correta e no tempo esperado

Esses dados podem ser:

- Texto
- Números
- Arquivos
- Pacotes de jogo (posição do jogador, ações, cartas, turnos etc.)

---

## ⚠️ Por que redes são difíceis?

Sim, é um dos tópicos mais desafiadores porque:

- **Não determinístico**: Latência varia, pacotes podem chegar fora de ordem ou se perder.
- **Concorrência real**: Threads, async, race conditions com eventos de rede.
- **Debugging**: Use `Wireshark` para capturar pacotes, logs detalhados, ferramentas como `ngrok` para testar localhost na internet, pois debugar torna-se um desafio intenso.
- **NAT/Firewalls**: A maioria dos jogadores está atrás de roteador (NAT), exigindo técnicas como hole punching para P2P.
- **Escalabilidade**: 2 jogadores é razoávelmente fácil; 100+ exige servidores dedicados, matchmaking, sharding.
