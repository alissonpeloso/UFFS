- Complexidade: verificação se um problema é computacionalmente fácil ou díficil de ser resolvido.
- Computabilidade: Alguns problemas não podem ser resolvidos por computados. Classifica problemas em resolvíveis por computador ou não.
- Autômatos finitos: modelos adequados para dispositivos que têm uma pequena
quantidade de memória.
- Autômatos finitos: modelos adequados para dispositivos que têm uma pequena
quantidade de memória.

## Máquinas de Turing

- Tem memória ilimitada e irrestrita.
- Reconhecedora: aceita ou rejeita uma entrada.
- Transdutora: processa a entrada e produz uma saída.
- Se não chegar a algum estado de aceitação ou rejeição, fica processando infinitamente.

### Definição Formal

- Q: conjunto de estados.
- Sigma (Σ): Alfabeto de entrada sem o símbolo branco.
- Gama (Γ): Alfabeto da fita. onde ⊔ ∈ Γ e Σ ⊆ Γ
- Delta (δ): Q ✕ Γ →Q ✕ Γ ✕ {E, D}, função de transição.
- q0: estado inicial.
- qaceita: estado de aceitação.
- qrejeita: estado de rejeição.

### Configurações

- Coloca o estado na posição antes da posição da cabeça na fita.

### Reconhecível e Decidível

- Turing-reconhecível: se existe uma máquina de turing que reconhece.
- Turing-decidível: Sempre termina de executar/reconhece a linguagem.

### Equivalência de Máquinas de Turing

- com Parada: Pode usar estados sequentes que vão para esquerda depois pra direita ou vice-versa para manter na mesma posição.
- Múltiplas fitas: Utiliza um símbolo de separador para simular várias fitas e utiliza o símbolo com um traço no meio para representar a posição da cabeça nas múltiplas fitas.
- Não-determinísticas: Representar todos os estágios do processamento das threads possíveis usando strings. Avaliar as strings em uma certa ordem (busca em largura na árvore de todas as threads).