- interpretation overhead: O interpretador precisa analisar cada declaração no programa cada vez que ele é executado e então realizar a ação desejada.
- coroutines: Pausar uma sub-rotina e poder continuar de onde estava -> basicamente funções assíncronas
- tail calls: Chamada de funções no retorno de outra função (utilizada para chamadas recursivas)
- Ahead-of-time: O código é todo compilado antes de atingir as plataformas que a executam.
- Just-in-time: Consiste em transformar o código em código de máquina ou traduzido para outros formatos e então executado. É uma mistura de AOT com a interpretação. Combina a velocidade do código compilado com a flexibilidade da interpretação.
- Lua:
  - Lua é uma linguagem de programação poderosa, eficiente e leve, projetada para estender aplicações. Ela permite programação procedural, programação orientada a objetos, programação funcional, programação orientada a dados e descrição de dados.
  - Lua combina sintaxe procedural simples com poderosas construções para descrição de dados baseadas em tabelas associativas e semântica extensível. Lua é tipada dinamicamente, é executada via interpretação de bytecodes para uma máquina virtual baseada em registradores, e tem gerenciamento automático de memória com coleta de lixo incremental. Essas características fazem de Lua uma linguagem ideal para configuração, automação (scripting) e prototipagem rápida.
- Pallene language: Igual a Lua só que tipado e focado em performance.
- constant propagation: Uma otimização que substitui o valor de uma variável por uma constante em uma equação
- dead code elimination: remover código que não afeta os resultados do programa.
- bytecodes: Código intermediário que será executado em uma máquina virtual.
- Computed-goto GCC extension: utilização de goto para uma label, assim como o Jump do Assembly.
- dispatching overheads: Problema de uma linguagem orientada a objetos, onde vários objetos podem conter uma função de mesmo nome.
- Futamura Projection: é uma técnica para vários tipos diferentes de otimização de programa por especialização. A aplicação mais simples é produzir novos programas que rodem mais rápido do que os originais, mas com a garantia de se comportar da mesma maneira.
- low-hanging fruit: fácil de conseguir, obter. Fruta mais abaixo no pé
- dispatch tables: é uma tabela de ponteiros ou endereços de memória para funções ou métodos. O uso de tal tabela é uma técnica comum ao implementar a vinculação tardia na programação orientada a objetos.
- garbage collector: gerenciamento de memória responsável por alocar e liberar a memória.
- AST-based interpreter: um interpretador baseado em árvore de sintaxe abstrata.

---

# Síntese

## Resumo

- A maioria das linguagens dinamicamente tipadas são implementadas usando interpretadores;
- Desvantagem, pois a linguagem pode crescer demais (excesso de interpretação);
- Apresentação da LuaAOT, que é uma linguagem ahead-of-time derivada do interpretador Lua.
- Utiliza uma ideia antiga, que usa uma "avaliação parcial" para gerar um compilador baseado em um interpretador existente.
- Contribuição: Aplicar essa ideia em uma linguagem de programação bem estabelecida.

## Introdução

- Interpretadores e sua utilização para linguagens dinamicamente tipadas;
- Interpretadores são geralmente mais lentos que os compiladores por causa do interpretation overhead;
- Vantagem dos compiladores just-in-time para os ahead-of-time relacionados a linguagens de programação dinâmica.
  - ahead-of-time precisa de um conhecimento prévio das tipagens para realizar determinadas otimizações.
- Motivação: Trabalho anterior usando Pallene (tipo a Lua, porém tipado), que permitia fazer otimizações por não ter tipos especulativos.
- LuaAOT não possui otimizações baseadas na tipagem.
- Utilizaram uma ideia antiga "desenrolando" e especializando o núcleo de loop do interpretador.
- LuaAOT permite a utilização de co-rotinas (funções, pelo que entendi) e chamadas de cauda (chamada de função e o retorno ao local apropriado);
- Uma parte das otimizações da LuaAOT é passada para o C, incluindo a propagação de constantes e eliminação de código morto.
- A LuaAOT não pode competir com um compilador JIT, porém a questão é que com um baixo custo, foi conseguida uma performance respeitável em uma linguagem não tipada a partir do método aplicado.

## Máquinas Virtuais e avaliação parcial

- Uma forma para implementar um interpretador para linguagens dinamicamente tipadas é a máquina virtual.
  - É utilizada uma linguagem intermediária (bytecodes).
  - Usar a imagem 1 do documento.
- Mostrar a figura 2, o funcionamento de um código intermediário de máquina virtual (tipo assembly), usando um PC (program counter) para o fluxo de controle e rodando instrução por instrução como em uma CPU.
  - É baseado em registradores.
- interpretation overhead está relacionado diretamente com a decodificação e o "despachamento":
  - A decodificação está relacionada a busca da próxima instrução da memória e a processar os valores;
  - O despachamento excessivo está relacionado a forma que o interpretador transfere o controle para o manipulador de instruções apropriado.
    - Forma mais básica: while-switch loop.
  - O interpretador Lua pode ser configurado para usar tanto o while-switch loop ou uma tabela de despachamento usando o Goto do GCC.
  - LuaAOT usa uma versão modificada do inner interpreter loop, especializada em rodar uma função dada.
    - Mostrar a figura 3: pode ser vista como uma avaliação parcial da função de execução.
    - Método de produzir um compilador de um interpretador às vezes é chamado de Futamura Projection.
  - Essa simples abordagem, não otimiza todas as coisas possíveis que podem ser otimizadas para o interpretador Lua.
    - Não há tentativa de salvar variáveis nos registradores da CPU, interpretador Lua e a LuaAOT salva as variáveis na Pilha da Lua.

## O Compilador da LuaAOT

- O código desenvolvido no formato Lua é transformado em uma saída em C como saída.
  - Esse código em C pode ser compilado dentro do módulo de extensão da Lua.
  - O módulo resultante pode ser carregado por um interpretador Lua customizado, que foi modificado para conseguir rodar funções compiladas.
  - Programas completamente compilados não são comuns, geralmente só as partes críticas do código são compiladas.

## O interpretador

- O interpretador Lua utilizado possui algumas alterações que são necessárias para conseguir rodar tanto as partes compiladas quanto às partes interpretadas do código, por isso, o interpretador desempenha um papel central em nosso sistema.
  - Outro motivo é que o interpretador utiliza a Lua runtime e o coletor de lixo, que são utilizados na parte do código compilado e não compilado.
- O interpretador possui algumas pequenas modificações como:
  - um campo adicional na estrutura de dados que representa as funções Lua. Esse campo aponta para a função compilada, se houver uma versão compilada.
  - A extensão de módulos do C inclui a inicialização do código que associa as funções Lua com as versões compiladas em C.
- No início da execução da subrotina, o interpretador verifica se há uma versão compilada da função para execução.
- Foram necessárias modificações para as chamadas de função (call, tail call, and return).
- O interpretador Lua 5.4 não possui otimização na execução de função. O interpretador Lua realiza essas chamadas alterando o counter, o mesmo que um loop natural de interpretador roda a função chamada.
  - Incompatível com a implementação realizada nesse artigo, cada função de execução é especializada para uma função específica. Então essa otimização foi desabilitada.

## O gerador de Código

- Recebe um módulo de Lua e converte para C.
  - É chamado inicialmente o compilador bytecode e depois o bytecode é passado para c.
  - Para cada função é criado um header de função adequado e tem como saída um bloco de C para cada instrução.
  - Na maioria dos casos, os blocos de C são literalmente copiados, porém alguns bytecodes precisam ser adaptados.
    - Principais casos que exigem adaptação: bytecodes que alteram o PC, bytecodes usando C gotos e bytecodes relacionados a chamada de funções.
  - No LuaAOT, cada um dos jumps gerados no bytecodes são alterados para um C goto.
  - Para operações binárias, cada operação é seguida por uma instrução especial (mmbin) que trata o overloading.Quando os operadores tem os tipos esperados, a operação binária apenas incrementa o PC para pular a instrução.
  - "This means that all binary operations contain an implicit jump, which our compiler must also replace by a goto."

## Compilação alternativa sem Gotos

- Se a Lua fosse implementada baseada em outra linguagem, o uso de gotos talvez fosse muito mais difícil usar os Gotos na avaliação parcial. Porém, como é baseada em C, isso permite utilizar essa otimização sem muito problema.
- Foi implementada então, uma versão usando trampoline pattern ao invés de gotos. Mostrar figura 4.
- Aqui, o despache é baseado no PC e não na tag de instrução. Para instruções sem jump, o manipulador cai para manipular a próxima instrução, para as que modificam o PC, o manipulador termina com uma instância de break que retorna para o início do trampolim.
- Essa abordagem é tão simples quanto utilizar gotos, a desvantagem é que ela mantém alguns overheads relacionados ao despachamento do interpretador.

## Corrotinas

- As corrotinas da Lua são um mecanismo de controle de fluxo muito poderoso.
- úteis para programação assíncrona.
- Lua mantém uma pilha de chamada para cada corrotina, quando a corrotina cede, o interpretador salva o PC e volta para o loop do interpretador. Quando a corrotina é retomada, o interpretador deve continuar o loop de execução de onde ele saiu.
- Para o compilador ser compatível com as corrotinas, foi necessário achar um meio de reiniciar a execução do ponto em que a corrotina foi interrompida.
- Como: Foi inserido um switch-case que pula para o local indicado pelo PC. Esse switch-case é usado apenas uma vez no início da função, depois disso os outros jumps ocorrem com gotos. Mostrar figura 5

## Avaliação

- A performance foi estudada junto a complexidade da implementação.
- Também foi feita uma análise quantitativa para saber o que é necessário para um interpretador aceitar um compilador no estilo do LuaAOT.
- Benchmarks disponíveis online.

### Performance

- Foi feita comparação de tempo de execução entre o interpretador, o LuaAOT e o LuaJIT (um compilador JIT avançado para Lua).
- Utilizaram programas que garantiam que o tempo de execução mínima fosse pelo menos um segundo, rodando 20 vezes. Foi feito média e desvio padrão dos valores encontrados. Mostrar Tabela 1 e Figura 6.
- Em todos os testes o LuaAOT foi mais rápido que o interpretador normal. Redução de 20% a 60%.
- A versão usando trampolim, ficou entre o interpretador e a LuaAOT usando gotos. LuaJIT foi a mais rápida em todos os casos.
- Foi verificado se a diferença de tempo ocorreu não só apenas pela diferença de números de instrução. Rodaram usando perf. Mostrar a tabela 2.
- Para aquela máquina, a maior diferença realmente foi causada pelo menor número de instruções para a CPU.
- O código binário gerado pelo LuaAOT é muito maior que o bytecode correspondente. Medidas na Tabela 3.

### Complexidade da Implementação

- Para medir a complexidade foram contadas as linhas de código do gerador de código.
- Das 1600 linhas do gerador de código, 450 podem ser atribuídas às subrotinas do compilador bytecode.
- Os modelos de código derivados do loop do interpretador conta para mais da metade do código gerador, cerca de 850 linhas.
- O resto do código, que foi escrito do zero, foi menos de 500 linhas.
- Para comparação:
  - O interpretador Lua tem 28k de linhas em C e o LuaJIT tem 80k de linhas de C e 35k em assembly.

### Aplicabilidade da Técnica

- Simples o suficiente para ser aplicado em outros interpretadores de linguagens dinâmicas.
- A técnica não funcionará facilmente para um interpretador baseado em AST.
  - Mais complicado que bytecodee pela presença de recursão.
- Usando avaliação parcial, a linguagem na qual o interpretador foi criado é importante. C possui o goto, otimizações de compilador e um pré processador de macros.
- Otimizações: Propagação de constantes do C para instruções bytecode: luxo de emitir um código quase idêntico ao código usado pelo interpretador original.

## Trabalhos Relacionados

- O trabalho não é um sistema de avaliação parcial.
- LuaAOT é no formato ad-hoc em um interpretador existente.
- Exemplo de avaliação parcial para interpretador é o Truffle framework: permite criar um JIT compiler baseado em um interpretador AST. Tuffle precisa que o interpretador seja escrito em Java, usando o Truffle framework.
- Interpretation Overhead:
  - Barany’s pylibjit: implementa um JIT compiler para python usando GNU LibJIT: também trabalha no nível de instruções bytecode, convertendo cada instrução de bytecode para um código de sequência de máquina. Permite desabilitar e habilitar diversas otimizações. Isso é útil para comparação com o tempo de execução do interpretador.
- Foco do artigo foi estudar o interpretation overhead.

## Conclusão

- Apresentação da LuaAOT que usando menos de 500 novas linhas de código de um total de 1600 linhas, foi possível cobrir todas as funções da Luan incluindo corrotinas e chamadas de cauda.
- Redução no tempo de execução entre 20% e 60%. Mesmo não competindo com um bom JIT compiler, houve uma melhora de performance relativa ao interpretador e isso pode ser útil para estudos sobre interpretation overheads.
- A forma como a LuaAOT foi implementada pode ser de interesse para outras linguagens de programação. No geral, as ideias do trabalho podem ser aplicadas para interpretadores que usam uma máquina virtual baseada em bytecode escrita em C.
