# Camada de Aplicação

## O que é internet?
- milhões de elementos de computação interligados.
- Roteadores: encaminham pacotes para destinos finais
- Protocolos: regras que controlam o envio e recepção de mensagens
- Internet: rede de redes. Internets and intranets
- RFC: request for comments -> aonde possuí 

## Protocolo

### Partes de um protocolo
- serviço oferecido
- hipóteses sobre o ambiente onde executa e os serviços utilizados
- Vocabulário de mensagens
- Formato das mensagens
- Algoritmos garantindo a consitência

- Borda da Rede: Aplicações e hospedeiros
- Núcleo da rede: roteadores e redes de redes
- redes de acesso, meio físico: enlaces de comunicação

#### Borda da rede
- cliente/servidor: requests, pedidos e respostas
- Peer-to-peer: uso mínimo de servidores dedicados

#### Serviço orientado à conexão
- Handshaking: Tipo "alô" humano. Usa para estabelecer conexão antes de transmitir dados.
- TCP: Transmission Control Protocol
  - transferencia de dados confiavel e sequencial, controle de fluxo e controle de congestão.
  - ex: HTTP(web), FTP (transferência de arquivo), Telnet (login remoto), SMTP (e-mail).
  
#### Serviço sem conexão
- UDP: User Datagram Protocol
  - Sem conexão na camada de Transporte da internet.
    - Transferencia não confiavel, sem controle de fluxo e sem controle de congestão.
    - ex: Streaming media, teleconferência, DNS, telefonia IP


#### Núcleo da rede

- Malha de roteadores interconectados

- **Comutação de circuitos:** Usa canal dedicado para cada conexão. Ex: rede telefônica
  - recursos fim-a-fim são reservados por "chamada"
  - não há compartilhamento
  - exige estabelecimento de conexão
  - recursos da rede divididos em "pedaços". Pedaços alocados às chamadas e pedaço desperdiçado se não for usado pela chamada
    - Divisão em frequência (FDM);
    - Divisão temporal (TDM);
  - Tem número máximo de usuários que podem alternar durante o tempo.

- **Comutação de pacotes:** dados são enviados em blocos discretos
  - fluxo é dividido em pacotes
  - cada pacote usa toda a banda disponível para transmissão
  - recursos usados sob demanda
  - **Contenção**: a demanda pode exceder a capacidade
  - **Congestão**: filas de pacotes
  - Pacotes de movem um salto por vez (store-and-forward)
  - Nó recebe pacote completo antes de encaminhar
  - Melhor compartilhamento de recursos
  - Não precisa de chamda
  - Mas pode ocorrer congestionamento, necessário protocolo para o controle e transferência confiável
  - Cálculo de comutação:
    - L/R -> pacote de L bits, para o enlace de R bps. Ou seja: Tam_Pacote/Largura_Enlace
    - Tempo Total: tempo de propagação + tempo de atraso (armazena e reenvia)

##### Redes de comutação de pacotes: roteamento
- **Redes de datagrama:** 
  - Endereço destino determina o próximo salto
  - Rotas podem mudar durante a sessão
  - Analogia: dirigir perguntando o caminho
- **Rede de circuitos virtuais:**
  - cada pacote tem um ID, o id determina o próximo salto
  - Caminho fixo e determinado no instante do estabelecimento da conexão
  
##### Acesso residencial: redes ponto-a-ponto
 - Modem discado:
   - ADSL: AsymmetricDigital Subscriber Line -> até 3.5 Mbps de upstream e até 24 Mbps de downstream
 - FDM: 
   - 50 kHz -> 1 MHz para downstream
   - 4 kHz -> 50 kHz para upstream
   - 0 kHz -> 4 kHz para telefonia comum

##### Acesso residencial: cable modems
- HFC: hibrído (fibra e coaxial)
  - até 30 Mbps upstream, 2 Mbps downstream
- Rede de cabo e fbra liga residências ao roteador do ISP (fornecedor)

##### Acesso institucional: redes de área local
- Arede local(LAN) da companhia/univ conecta sistemas fnais ao roteador de acesso
- Ethernet:
  - Cabo compartilhado ou dedicado conecta sistemas fnais e o roteador
    - 10 Mbs, 100 Mbps, Gigabit Ethernet

---

#### Redes de acesso sem fio

- conecta sistemas finais ao roteador
- LANs sem fio:
  - 802.11b (WiFi): 11 Mbps
- Wide-area de acesso sem fio:
  - 3G, 4G, etc

#### Redes residenciais
- Componentes típicos de uma rede residencial:
  - ADSL ou cable modem
  - Roteador/firewall
  - Ethernet
  - Ponto de acesso sem fio

#### Meios físicos
- **Bit:** propaga-se entre os pares transmissor/ receptor
- **Enlace físico:** meio que fica entre o transmissor e o receptor
  - Guiados: meios sólidos com caminhos fixos: cobre, fibra ótica
    - **Twisted Pair:** par de fios trançados de cobre isolados (entrelaçado para que o campo magnético não altere os dados);
  - Não guiados: Propagação livre: rádio

---

### Estrutura da Internet: rede de redes
- Grosseiramente hierárquica
- No centro, ISPs de zona 1: cobertura internacional
  - NAP: Network acess point -> compartilhamento de enlaces entre os ISPs de zona 1 (troca de favores).
- ISPs de zona 2: menores (regionais geralmente)
  - Conectam-se a um ou mais ISPs de zona-1 e talvez outros ISPs de zona 2.
- ISPs de zona 3 e ISPs locais:
  - última rede de acesso (hop) mais próxima de sistemas finais

---

### Como perdas e atrasos ocorrem?

- Filas de pacotes: taxa de chegada de pacotes ultarpassa a capacidade de saída
  - pacote sendo transmitido (atraso)
  - enfileiramento de pacotes (atraso)
  - pacotes descartados (perda)

#### Quatro fontes de atraso de pacotes
1. Processamento nos nós: 
   - Verifica erros de bit
   - Determina link de saída
2. Enfileiramento:
   - Tempo de espera no link de saída para transmissão
   - Depende do nível de congestionamento do roteador
3. Atraso de transmissão:
   - R= largura de banda do link (bps)
   - L= tamanho do pacote (bits)
   - Tempo para enviar bits ao link = L/R
4. Atraso de propagação:
   - d = comprimento do link físico
   - s = velocidade de propagação no meio (~2x10^8 m/s)
   - Atraso de propagação = d/s

- s e R são medidas **muito diferentes**

#### Atraso de filas
- R = largura de banda do link (bps)
- L = tamanho do pacote (bits)
- a = taxa média de chegada de pacotes
- **Intensidade de tráfego = La/R**
  - La/R ~ 0: atraso médio de fla pequeno
  - La/R -> 1: atraso se torna grande
  - La/R > 1: mais trabalho chega do que a capacidade de transmissão. O atraso médio cresce indefnidamente!

### Perda de pacotes
- A fila no buffer possuí capacidade finita, se pacote chega em fila cheia, é descartado
- Pacote perdido pode ou não ser retransmitido.

### Pilha de protocolos da Internet
- Aplicação: suporta as aplicações de rede FTP, SMTP, HTTP
- Transporte: transferência de dados hospedeiro-hospedeiro (fm-a-fm)
  - TCP, UDP
- Rede: roteamento de  datagramas da origem ao destino
  - IP, protocolos de roteamento
- Enlace: transferência de dados entre elementos vizinhos da rede 
  - PPP, Ethernet
- Física: transmissão física dos bits nos canais

#### Encapsulamento
 - Aplicação -> Mensagem
 - Segmento -> Transporte
 - Datagrama -> Rede
 - Quadro -> Enlace

---