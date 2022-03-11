# Pontos para Revisar:

## Aplicação

- FDMA (Frequency Division Multiple Access): divisão por frequência 
- TDMA (Time Division Multiple Access): divisão por tempo
- TDMA + FDMA: junção dos dois, realizando a divisão da banda por frequência e por tempo.
Multiplica número de usuários atendidos ao mesmo tempo.
- Comutação de pacotes: datagrama e circuitos virtuais
- ISP: provedor -> níveis de ISP (1,2,3)
- Atraso de pacotes: 
  1. Processamento nos nós
  2. Enfileiramento
  3. atraso de transmissão
  4. atraso de propagação
- Arquitetura P2P, cliente-servidor e hibrida
- TCP e UDP
- RTT: tempo para enviar um pequeno pacote que vai do cliente para o servidor e
retorna.
- HTTP persistente e não persistente
- Cookies
- Web caches (proxy server)
- FTP: transferência de arquivos. Usa uma porta para controle e outra pra dados. port 21 e 20
- SMTP: correio eletrônico. porta 25. POP, IMAP, HTTP tbm 
  - MIME: multimedia mail extension conteúdos binários convertidos. base64
- POP3: download do e-mail, remove do servidor não salva estado
- IMAP: salva os estados usando sessões. Mensagens salvas no servidor
- DNS: traduz domínio para IP
  - consulta recursiva e encadeada
- P2P: Napster, Gnutella, KaZaA

## Transporte
- Multiplexação/demultiplexação: permite ter múltiplas instâncias conversando com diversos processos.
- checksum
- ACKs e NACKs -> timeout
- ARQ (Automatic Repeat Request): sender initiated and receiver initiated
- ARQ SWP (stop-and-wait): usa só um bit de controle, até não receber a confirmação (ack com o bit esperado).
- ARQ SRP (repetição seletiva): usa janela e nSeqs. sizeOf(window) <= count(n)/2. Tem variantes: assumir ACK com confirmação do pacote recebido e NextPacket. Se window.len = 4 e o NP=3, significa que os pacotes 0, 1 e 2 foram confirmados automaticamente. confirmação cumulativa
  - TCP não tem NP, apenas usa ACK com valor do NP.
- ARQ GBN (Go Back-N): receptor tem janela de tamanho 1 e sender com janela normal. só recebe pacotes na ordem correta para entregar para a aplicação
- SRP com NACK: envia NACK com o valor que não chegou e uma sequência de bits que identifica os posteriores que chegaram (1) ou não (0). 3 -> 3 (101) -> 5 (111)
  - adianta o reenvio se recebe o NACK antes do TO.
- Temporização TCP
  - RTT
  - SampleRTT
  - EstimatedRTT
    - EstimatedRTT = (1-alfa) * EstimatedRTT + alfa * SampleRTT (alfa = 0,125)
    - DevRTT = (1-beta)*DevRTT + beta*|SampleRTT-EstimatedRTT| (beta = 0,25))
  - TimeoutInterval = EstimatedRTT + 4*DevRTT
- Retransmissão rápida: Se o transmissor recebe 3 ACKs para o mesmo dado, supões que o segmento com confirmações
duplicadas foi perdido. Reenvia antes do temporizador expirar. ACK == NP
- Controle de Fluxo: espaço disponível no buffer = RcvWindow = RcvBuffer-[LastByteRcvd - LastByteRead]
  - 500 - [400 - 300] = 500 - 100 = 400
- Estabelecimento de conexão: 
  - Manda pacote de solicitação com o flag SYN = 1
  - Pode aceitar ou recusar.
  - Se aceitar retorna SYN = 1 e ACK = 1
  - então o solicitante manda outro pacote com ACK = 1
- Encerramento de conexão:
  - Manda pacote com FIN = 1
  - O receptor manda um ACK e depois solicita também um fechamento com o FIN = 1
  - O solicitante então recebe um ACK = 1 e espera um tempo antes de fechar para receber eventuais pacotes e descartá-los sem gerar mensagens de erro.
- Controle de congestionamento:
  - fim-a-fim
  - assistido pela rede
- limite transmisão:  LastByteSent-LastByteAcked <= CongWin
  - 500; 400 - 300 = 100 não foram confirmados
- rate = (CongWin/RTT) Bytes/s -> vazão = win/RTT
- TCP AIMD: Additive Increase Multiplicative Decrease
  - gráfico dente de serra. Divide congWin pela metade no evento de perda e aumenta 1 na ausência de eventos de perda.
- TCP: Partida lenda
  - começa com congWin = 1 
  - Dobra a cada RTT, a cada ACK recebido.
  - Threshold: ao chegar no limiar, aumenta de 1 em 1 linear.
  - Se der perda:
    - TCP Tahoe série 1: reduz janela pra 1 e divide Threshold para metade da janela no momento da perda.
    - TCP Reno série 2 (com retransmissão rápida): 
      - Na perda por confirmação duplicada. Threshold e janela recebem a metade da janela no momento da perda.
        - 14 -> TH = 7, W = 7
      - Na perda por TO, congWin é ajustado para 1 MMS
        - 14 -> TH = 7, W = 1