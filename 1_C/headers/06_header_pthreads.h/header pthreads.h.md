<!-- @format -->

# Header `<pthreads.h>`

Antes de tudo, é importante destacar que este _header_ possui um significado muito mais amplo do que apenas uma
biblioteca específica da linguagem C. Ele está diretamente relacionado a um dos conceitos mais importantes da
computação moderna, independentemente da linguagem utilizada: a **programação concorrente**.

A programação concorrente permite que múltiplas tarefas sejam executadas de forma simultânea ou intercalada,
explorando melhor os recursos do sistema, como múltiplos núcleos de processamento.
Com isso, o programador deixa de focar apenas **em como escrever o código de forma sequencial** e passa a
**pensar em como as tarefas serão divididas, sincronizadas e executadas em paralelo**, Como por exemplo.

- Como dividir o trabalho
- Como sincronizar as tarefas
- Como evitar condições de corrida
- Como prevenir deadlocks

Com a programação concorrente, torna-se possível o gerenciamento eficiente de uma vasta gama de recursos, como:

- Melhor aproveitamento de recursos do processador
- Maior responsividade em aplicações
- Processamento paralelo eficiente
- Gerenciamento de múltiplas conexões (redes, servidores)
- Jogos mais fluidos
- Processamento de grandes volumes de dados

O arquivo de cabeçalho `<pthreads.h>` faz parte do padrão **POSIX Threads (Pthreads)** e fornece mecanismos
para criação e gerenciamento de _threads_, além de ferramentas de sincronização como _mutexes_, _semaphores_ e
_variáveis de condição_, tornando possível o desenvolvimento de aplicações concorrentes eficientes e seguras.

---

## Headers e mecanismos para programação concorrente

A biblioteca Pthreads disponibiliza uma variedade de headers e mecanismos que permitem trabalhar com
concorrência, sincronização e controle de recursos compartilhados.

📌 <pthread.h>

- Funções para criação e controle de threads

| Função                                                                                                     | Descrição                                       |
| ---------------------------------------------------------------------------------------------------------- | ----------------------------------------------- |
| `pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg)` | Cria uma nova thread.                           |
| `pthread_join(pthread_t thread, void **retval)`                                                            | Aguarda a finalização de uma thread específica. |
| `pthread_exit(void *retval)`                                                                               | Finaliza a execução da thread atual.            |

---

- Funções de mutex (exclusão mútua), Garante que apenas uma thread por vez acesse uma região crítica.

| Função                                                                        | Descrição                                                             |
| ----------------------------------------------------------------------------- | --------------------------------------------------------------------- |
| `pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr)` | Inicializa um mutex.                                                  |
| `pthread_mutex_destroy(pthread_mutex_t *mutex)`                               | Destrói o mutex e libera seus recursos.                               |
| `pthread_mutex_lock(pthread_mutex_t *mutex)`                                  | Bloqueia o mutex até que esteja disponível.                           |
| `pthread_mutex_unlock(pthread_mutex_t *mutex)`                                | Libera o mutex para outras threads.                                   |
| `pthread_mutex_trylock(pthread_mutex_t *mutex)`                               | Tenta bloquear o mutex sem bloquear a thread caso ele esteja ocupado. |

---

📌 <semaphore.h>

- Funções de semáforos, Semáforos são úteis para controle de acesso a um número limitado de recursos.

| Função                                                  | Descrição                                                                 |
| ------------------------------------------------------- | ------------------------------------------------------------------------- |
| `sem_init(sem_t *sem, int pshared, unsigned int value)` | Inicializa um semáforo com um valor inicial.                              |
| `sem_wait(sem_t *sem)`                                  | Bloqueia a thread até que o semáforo esteja disponível (valor > 0).       |
| `sem_post(sem_t *sem)`                                  | Incrementa o valor do semáforo e libera uma thread bloqueada, se existir. |
| `sem_destroy(sem_t *sem)`                               | Destrói o semáforo e libera seus recursos.                                |

---

📌 <stdatomic.h>

- Operações atômicas (C11), oferece operações indivisíveis (sem necessidade de mutex em muitos casos simples).

| Recurso                           | Descrição                                           |
| --------------------------------- | --------------------------------------------------- |
| `atomic_int`, `atomic_bool`, etc. | Tipos atômicos que garantem operações indivisíveis. |
| `atomic_load()`                   | Lê um valor atômico com segurança.                  |
| `atomic_store()`                  | Escreve um valor atômico com segurança.             |
| `atomic_fetch_add()`              | Incrementa um valor atômico de forma segura.        |
| `atomic_fetch_sub()`              | Decrementa um valor atômico de forma segura.        |
