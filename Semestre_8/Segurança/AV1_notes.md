# Anotações para Avaliação 1 - Segurança

## 5 pilares da segurança da informação
- **Disponibilidade:** precisa estar disponível quando necessário.
- **Confidencialidade:** deve estar acessível apenas para quem tem permissão.
- **Integridade:** Informação se mantém fiel ao conteúdo de criação.
- **Autenticidade:** A autoria de um dado pode ser verificada/garantida.
- **Não-repúdio ou Irretratabilidade:** O autor de uma informação não pode negar a sua autoria.

## Criptografia
Criptografia é o processo de codificação de mensagens para que somente pessoas autorizadas possam lê-las. A criptografia é uma técnica de segurança que permite a transmissão de dados de forma segura, ou seja, que somente as pessoas autorizadas possam ter acesso a esses dados.
- Cripto: segredo/esconder
- Grafia: escrita
Precisa ser eficiente computacionalmente e dificil de ser quebrada.

### Tipos de criptografia

#### Simétrica:
- usa a mesma chave para criptografar e descriptografar.

##### Transposição: 
Não substitui os caracteres na etapa de criptografia, apenas os embaralha através de uma chave.

- Colunas/Linhas: cria uma tabela com o número de colunas de acordo com a chave. Ex: chave = Colunas 5. A mensagem é escrita na tabela em 5 colunas e os espaços que sobrarem são preenchidos com caracteres aleatórios, usando um X, por exemplo. Depois é lido da tabela linha por linha. Pra descriptografar é só fazer o processo inverso, dividindo a mensagem por 5, onde cada grupo da divisão é uma coluna da tabela.
  - Variação usando números que representam a ordem das colunas. Ex: chave = 3 1 4 2 5. A mensagem é escrita na tabela em 5 colunas, onde a primeira coluna é a 3, a segunda a 1, a terceira a 4, a quarta a 2 e a quinta a 5.
- Espiral: mesma ideia da coluna, porém formando uma espiral. Mais dificil de descriptografar.

##### Substituição: 
Ideia de substituir os caracteres de entrada por novos caracteres para a criptografia. (Cifra de Cesar)

- Cifra de César: (monoalfabética) utiliza uma chave de deslocamento no alfabeto, exemplo 2 direita. Então o novo simbolo é o simbolo da direita 2 vezes. (A -> C)
- Cifra de Playfair: (monoalfabética) inicia com chave e completa o alfabeto com os valores faltantes.
- Monoalfabeto: substitui cada letra do alfabeto por outra letra do alfabeto.
- Polialfabeto: muda as chaves nas iterações.
- Análise de Frequência: utiliza as letras mais comuns da língua para fazer a substituição. Usado pra quebrar monoalfabéticas.
- Cifra de Vigenere: (polialfabética) transforma mensagem e palavra-chave em números e faz a soma entre os números. Mensagem + chave, repetindo a chave até completar a mensagem. A palavra-chave não deve ser muito pequena e não deve ser maior que a mensagem.

##### Esteganografia: 
Esconder dados em locais onde não se esperaria que esses dados sejam encontrados, em imagens, áudios, vídeos, etc. (ocultar, mensagem subliminar) 
- usando último bit de cada pixel de uma imagem, por exemplo.

#### Assimétrica:
usa chaves diferentes para criptografar e descriptografar. Chave pública e privada.

--- 

## Criptografia Moderna (a partir de 1970)

- AES: Advanced Encryption Standard
  - Símétrica
  - Desvantagem: forma de transmissão da chave
  - Vantagem: eficiência computacional
  - chave de 128, 256, 512 bits. Padrão é 256 bits.

- RSA: Rivest, Shamir, Adleman
  - Assimétrica
  - Chave pública e privada
  - Vantagem: não precisa trocar chaves
  - Desvantagem: eficiência computacional
  - Usado no HTTPS, Certificado e Assinatura Digital
  

---

## Certificado Digital

- Certificado Digital é um documento eletrônico que contém informações sobre a identidade de uma pessoa ou empresa, e que serve para comprovar a autenticidade de uma transação eletrônica. 
- ICP-Brasil: Instituto de Certificação de Pessoas Jurídicas e Físicas. (2001);
- Usa par de chaves assimétricas (RSA), para garantir a autenticidade da identidade do usuário.
- Para assinar o documento:
  - Utiliza a chave privada para criptografar o hash do documento.
  - Para confirmar a autenticidade do documento, utiliza a chave pública para descriptografar o hash do documento, e verificar se o hash do documento descriptografado é igual ao hash do documento original.
- Alguém pode se passar por mim emitindo uma chave pública falsa, então usa-se das autoridades certificadoras para garantir a autenticidade da chave pública.

---

## Protocolos de Rede

- Normas e regras para comunicação entre computadores (padronização).
  - TLS: Transport Layer Security
    - Substitui o SSL
    - Permite comunicação entre servidor e navegador.
    - RSA e AES para compor a chave de sessão.
    - Envia chave simétrica por conexão assimétrica para compor a chave de sessão.
  - SSH: Secure Shell
    - Substitui o Telnet
    - Permite comunicação segura entre dispositivos em rede não segura.
    - criptografia hibrida: usa chaves assimétricas para trocar chaves simétricas.
  - HTTPS (Hypertext Transfer Protocol Secure) e SFTP (Secure File Transfer Protocol)
    - HTTPS é a junção de HTTP e TLS.
    - SFTP é a junção de FTP e SSH, para transmissão de arquivos.
- WEP, WPA e WPA2: transmissão sem fio
  - WEP (Wired Equivalent Privacy): 1997, usa criptografia RC4 (tem falhas de segurança).
  - WPA (Wi-Fi Protected Access): 2003, gambiarra usando TKIP (Temporal Key Integrity Protocol) e RC4.
  - WPA2 (Wi-Fi Protected Access II): 2004, usa AES.
    - PSK: Pre-Shared Key, usa uma senha para gerar a chave de sessão, mesma senha para todos os usuários.
    - Enterprise: usa um servidor para gerar a chave de sessão, cada usuário tem uma senha diferente.

--- 

## Função Hash

- Função que gera um resumo de um arquivo, para verificar se o arquivo foi alterado. A saída da função hash é um valor de tamanho fixo, que é gerado a partir de um arquivo de tamanho variável.
- saída igual para a mesma entrada.
- geralmente, não reversível, pois se perde informação ao gerar o hash.
- Utilizado para integridade: verificar se o arquivo foi alterado em uma transmissão.
  - Nesse caso, é enviado um arquivo junto com a chave hash (usando uma assinatura digital para garantir a autenticidade), assim é possível passar o arquivo no mesmo algoritmo de hash pra gerar um hash e podemos comparar os hashs pra verificar se o arquivo não foi modificado.
    - **Resistência à pré-imagem:** reversão da função deve ser inviável computacionalmente.
    - **Resistência à segunda pré-imagem:** dado uma entrada, ser muito difícil encontrar uma entrada diferente que gere a mesma saída.
    - **Resistência à colisão:** deve ser muito difícil encontrar dois dados de entrada que produzam a mesma saída na função.
- São resistentes, mas não infalíveis.
- Utilização:
  - Verificação de integridade.
  - Gerar assinatura digital.
  - Armazenar senhas.
  - gerar identificadores únicos.
  - números pseudo-aleatórios.
  - proof-of-work, para minerar bitcoins. (prova de trabalho)
- exemplos que utilizam essa ideia: BLAKE, GOST, HAVAL, **MD**, RIPEMD, **SHA**, Tiger e Whirlpool;
    - MD (MD5): tem problemas na resistência a colisão, então para segurança se usa mais o **SHA**.
  
---

## Senhas e Salt
- Armazenar informações confidenciais de forma segura.
- gerenciador de senhas.
- Salt: adicionar um valor aleatório a senha, para dificultar a quebra de senha.
  - Usado para complicar as senhas padrões. Existe um banco com a Hash de todas as senhas padrões mais utilizadas no mundo, por isso, o salt é usado para dificultar a quebra de senha.
  - Para cada usuário é gerado um código aleatório (o Salt), pra ser utilizado para combinar com a entrada do hash. Assim não há como identificar se as senhas são as mesmas a partir do hash.

--- 

## Atividades

1. Cite os cinco principais pilares da segurança da informação e explique
resumidamente o que cada um deles representa.
- **Disponibilidade:** precisa estar disponível quando necessário.
- **Confidencialidade:** deve estar acessível apenas para quem tem permissão.
- **Integridade:** Informação se mantém fiel ao conteúdo de criação.
- **Autenticidade:** A autoria de um dado pode ser verificada/garantida.
- **Irretratabilidade:** O autor de uma informação não pode negar a sua autoria.

2. Explique a estratégia utilizada por cada um dos tipos de criptografia a seguir:
transposição, substituição e esteganografia.
- **Transposição:** Não substitui os caracteres na etapa de criptografia, apenas os embaralha através de uma chave.
- **Substituição:** Ideia de substituir os caracteres de entrada por novos caracteres para a criptografia. (Cifra de Cesar)
- **Esteganografia:** Esconder dados em locais onde não se esperaria que esses dados sejam encontrados, em imagens, áudios, vídeos, etc. (ocultar, mensagem subliminar)

3. Indique corretamente as características da criptografia (A) assimétrica, (B)
simétrica ou (C) para características que são de ambas.
- B B A C A A B A B A (Cerificado digital pode usar os dois)

4. Cite as principais características desejadas para um algoritmo de Hash
criptográfico. 
- Precisa ser eficiente coputacionalmente e ter as seguintes características:
    - **Resistência à pré-imagem:** reversão da função deve ser inviável computacionalmente.
    - **Resistência à segunda pré-imagem:** dado uma entrada, ser muito difícil encontrar uma entrada diferente que gere a mesma saída.
    - **Resistência à colisão:** deve ser muito difícil encontrar dois dados de entrada que produzam a mesma saída na função.
    - Tamanho fixo de saída

5. Explique o que é um certificado digital e dê exemplos de onde podemos utilizá-lo.
- É uma forma de autenticidade para identificar pessoas físicas e júridicas. Pode ser usado, por exemplo, para uma assinatura digital para comprovar que um documento foi assinado digitalmente, Notas Fiscais Eletrônicas, dentro do HTTPS, eCPF, eCNPJ.

6. Assinale (F) para as afirmações falsas e (V) para as verdadeiras

- **(V)** MD5 e SHA são funções de resumo de mensagem (funções hash). Esses algoritmos têm
a finalidade de garantir a integridade de mensagens de tamanho arbitrário
- **(V)** No padrão RSA, a assinatura digital é um código de verificação concatenado a uma
mensagem que é o hash da mensagem cifrada com a chave privada de quem emite a
mensagem
- **(F)** Considerando-se os algoritmos de criptografia tradicionais (RSA, por exemplo), tem-se
a garantia que é impossível determinar a chave privada a partir do conhecimento da chave
pública
- **(F)** O resultado e o tamanho do método criptográfico hash variam de acordo com o tamanho da informação à qual ele seja aplicado
- **(F)** O desenvolvimento de software seguro é uma funcionalidade presente em todas as
ferramentas e padrões existentes no mercado. Assim, o programador precisa focar apenas na
criatividade e no atendimento aos requisitos do cliente, pois segurança, hoje, é uma questão
secundária
- **(V)** A autoridade certificadora é uma entidade responsável por validar a identidade de um
usuário em uma infraestrutura de chaves públicas ICP
- **(V)** O uso de senhas ou a adoção de identificação física, como biometrias, são formas de
autenticação para fins de identificação única e exclusiva de usuários
- **(V)** Apesar de a criptografia moderna estar presente no cotidiano dos usuários, a implantação
de mecanismos criptográficos requer diversos cuidados, como a utilização de algoritmos e
protocolos conhecidos e extensivamente analisados e o uso de primitivas criptográficas
adequadas para cada situação


- Resposta = V V F F F V V V
   - ICP: Infraestrutura de Chaves Públicas 

---

## Criptomoedas e NFTs:
- **Criptomoedas:** são moedas digitais que utilizam criptografia para controlar a criação de unidades monetárias e verificar a transferência de fundos, operando de forma descentralizada. Ideia de moeda de troca rápida, porém, ficou muito valorizada e custosa para realizar as transações.
- **NFTs:** são ativos digitais únicos e não substituíveis, que podem ser criados, armazenados e negociados na blockchain. São usados para representar ativos físicos, como obras de arte, colecionáveis, ingressos, etc.

### Criptomoedas:
- criptografia garante que não seja possível falsificar moedas, mantém saldo sempre válido. Operações com segurança, confiança e validade.
- Descentralizadas. Governo e países não afetam a moeda com inflação ou criação de novas moedas.
- Computação distribuída e paralela.
- Ideia do proof of work (POW) ou proof of stake (POS);
  - POW: disperdício de energia, mineradores competem para resolver um problema matemático, que é a validação da transação. Quem resolver primeiro, ganha a recompensa.
  - POS: mineradores são os donos das moedas, que validam as transações e recebem recompensas. Quanto mais moedas, maior a chance de ganhar a recompensa. Ideia da recompensa por investir na moeda.

- **Vantagens:** 
    - Transações rápidas e baratas. (perdeu isso com o aumento de valor)
    - Imunes, em teoria, do controle estatal. Existe excessões, como a China que proibiu. Geralmente é tratado como ativo financeiro e não uma moeda de troca.
    - Desassociadas a economia local de países. Mas são sucetíveis a economia global.
    - Mais robustas quanto a falhas localizadas por ser decentralizada.
    - Investimento de alto rico, mas pode trazer grandes lucros em pouco tempo.
- **Desvantagens:**
    - Alta volatilidade
    - Elevado consumo de energia
    - Uso para atividades criminosas: lavagem de dinheiro e comércio ilegal.
    - Legalidade ainda em estudo/discussão em diversos países.
    - distribuição e trabalho de mineração concentrada em poucos "usuários".
    - Carteira e acesso podem ser vulneráveis a ataques. Se perder acesso, não tem suporte nem a quem recorrer.

#### Bitcoin:
- Criado em 2009 por Satoshi Nakamoto.
- primeiro blockchain eficiente.
- Jamais existirá mais de 21 milhões de bitcoins. Em 2140, não haverá mais mineração de bitcoins.
- **prova de trabalho:** usuário da rede disponibiliza máquina pra processar as transações. Prova de trabalho é feita por mineradores, que resolvem um problema com Hash. Primeiros a resolver realizam o processamento da transação e recebem uma recompensa em bitcoin.
  - Se passar, recebe 1 bloco de transações para computar. É necessário que vários computadores façam essa computação, para segurança. 
  - A dificuldade do processamento (entrada) vai depender da quantidade de transações na fila.
  - Uma transação só é computada se a maioria validar. 
  - Disperdício de energia para computação para a prova.
- **prova de participação:** mineradores são os donos das moedas, que validam as transações e recebem recompensas. Quanto mais moedas, maior a chance de ganhar a recompensa. Ideia da recompensa por investir na moeda.
- **Blockchain:**
  - estrutura de dados dividindo todas as transações em blocos lineares.
  - todos os usuários da rede tem uma cópia dos dados da blockchain.
  - informações criptografadas, pessoas identificadas com certificado digital, não é possível saber quem é. Só se tem essa informação durante o processamento da transação para quem faz parte da transação.
  - lista encadeada indentificada por hash. Blocos tem hash do bloco anterior, para garantir a integridade da informação. Qualquer alteração em algum dos blocos invalida todos os blocos seguintes, pois o hash altera. Rede só permite que seja adicionado blocos, não é possível alterar ou remover blocos.

### NFTs:
- **NFT:** Non-Fungible Token
- É um token que representa um ativo digital único, está ligado a uma blockchain. (geralmente Ethereum)
- Não tem valor definido e não pode ser trocado por algo equivalente.
- cada objeto digital tem hash criptografico único.
- É possível ter réplicas, mas é definido o número de réplicas existentes e há um hash específico para cada réplica.
- Tudo que é NFT é armazenado em uma blockchain.
- Possibilidade de validar que alguém é o dono do NFT.
- Só pode comercializar quem é dono do NFT.
- O criador no NFT é imutável, mas o dono pode mudar.
- Criador do NFT pode cobrar royalties por revendas.

---

## LGPD e Legislação
Regulamentação sobre segurança de sisemas no Brasil.

### Política Nacional de Segurança das Informações
- 2000 - Decreto 3505:
  - Confidencialidade, integridade e autenticidade dados sencíveis. 
  - Eliminar dependência externa.
  - capacitação e qualidifcação de pessoal e tecnologia relacionados a segurança.
  - promover produtos e serviços de segurança.
- 2001 - Medida provisória 2200-2:
  - Instituição do ICP-Brasil (Infraestrutura de Chaves Públicas Brasileira) e Instituto Nacional de Tecnologia da Informação (ITI).
- **LGPD:** implementada em 2018 e que foi adiada por conta da adaptação dos sistemas até 2021, possui uma abrangência mais geral, incluindo todos os sistemas. Antes desta lei existir os crimes que aconteciam na internet eram julgados através de leis existentes na constituição, e muitas vezes não existia uma tradução direta, então dessa forma os autores dos crimes não recebiam penalidade alguma.
    - Prevê penalidades que vão desde advertência até multa de até 2% do faturamento anual da empresa (limitado a R$ 50 milhões).

### e-Direito
- direito se condutas criminosas "virtuais" só podem ser julgadas se houver uma lei específica para isso.
- Delegacias especializadas em crimes virtuais.
Sobre a aplicação das leis/penalidades descritas nos slides:
  - No início se teve muito medo, pois todos os sistemas teriam que se adaptar rapidamente e etc, com medo de que fosse fiscalizado. Mas na realidade a cobrança destas leis se aplicam através de denúncias, sem a fiscalização ativa dos órgãos responsáveis.

## Auditoria de Sistemas
- **Auditoria de Sistemas:** é um processo sistemático de avaliação e verificação de informações, documentos, processos, sistemas e pessoas, com o objetivo de emitir um parecer sobre a conformidade com normas, procedimentos, políticas, leis e regulamentos, com foco em sistemas de informação.
- Foco nos pilares de segurança: integridade, disponibilidade confidencialidade, não-repúdio e autenticidade. além de satisfação dos usuários, regras interntas, tratamento de dados, eficiência, usabilidade.
- documentar e propor melhorias.
- resolução de riscos, problemas e falhas.

### Interna: 
Equipe interna da própria empresa, ideal que seja uma equipe diferente da de desenvolvimento e manutenção.
### Externa:
Contratação de equipe externa. Verificar conformidades.
Ocorre quando empresas estão em processos legais talvez para investigar um crime ou algo do tipo.

- Analisar os sistemas com o fim de verificar se está seguro, se tem uma usabilidade boa.
- Em geral é fazer uma vistoria para ver se tudo está de acordo com as leis que se aplicam, e também para encontrar fatores de risco para o sistema, falhas e etc.
- Deveria ser realizado em todas as etapas de desenvolvimento, implementação e etc.
- Pode ser feito de maneira interna, uma equipe que valida estas coisas(QA/quality ?assurance?), ou externa, um terceiro que valida seu sistema, uma outra visão.
- acredite , as ISO são pagas, sobre segurança e auditoria é a faixa 27000