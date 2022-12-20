- VPN é uma rede privada virtual, que permite que você se conecte a uma rede privada de forma segura através da internet. Ela é uma alternativa para conexões dedicadas que podem ser muito custosas dependendo da distância necessária entre os pontos de conexão.
- Incialmente buscamos separar os termos da VPN pra formarmos uma definição mais clara do que é uma VPN.
  - Network: Visão de rede de comunicação, onde os dados são enviados e recebidos entre os nós da rede. É basicamente uma troca de informações entre entidades.
  - Private: está relacionado com a virtualização e se refere a uma comunicação secreta entre disposítivos, onde apenas o grupo restrito que faz parte da rede de comunicação pode acessar os dados.
  - Virtual: Algo simulado, que não existe fisicamente, desempenha funções que não estão na realidade.

---

Aqui temos a definição de Ferguson e Huston (1998): [LER A DEFINIÇÃO]

---

- Os tipos de VPN podem ser dividos em 2 grandes grupos, seguindo o artigo de Ferguson e Huston. Aqui, vamos apenas citar esse tipos e não se aprofundar, até porque o assunto é mais relacionado a redes de computadores.
  - Camada de Enlace:
    - ATM (Asynchronous Transfer Mode)/Frame Relay: ATM busca o envio eficiente de dados como texto, vıdeo e  ́audio. Ela se baseia na comutaçao de celulas e utiliza a criaçao de circuitos virtuais para transferir os dados. E o Frame Relay transmite os dados dividindo eles em quadros de tamanho variavel, e verifica os erros apenas nas extremidades da rede.
    - MPLS (Multiprotocol Label Switching): usa o chaveamento e priorizacao do fluxo de pacotes dentro de uma rede compartilhada atraves do uso de rotulos (labels). Rótulos indicam o caminho a ser seguido, permitindo um envio mais eficiente de dados.
    - MPOA (Multiprotocol Over ATM): Busca aproveitar ao máximo a capacidade de uma rede ATM, ur sa canais virtuais comutados para a transferencia de dados.

  - Camada de Rede:
    - Controlled Route Leaking: Usa privacidade de obscuridade, controla propagação para que redes só recebam informações que estão nos seus limites de interesse.
    - Tunneling: Envio de tráfego de rede encapsulado dados e apenas os desencapsulando quando chegam ao destino. Vamos ver mais sobre adiante.
    - Virtual Private Dial Networks: oferece recursos para serviço de discagem de redes privadas. Usa tunelamento da camada 2, como L2F e L2TP.

---

