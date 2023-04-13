# hipo-simulator

<h1> Simulador de computador hipotético usando a linguagem de programação C </h1>

<h2> O que é um computador hipotético? </h2>

<p>Um computador hipotético é um modelo teórico de computador, geralmente utilizado para fins educacionais e de experimentação. Ele é composto por um conjunto de instruções básicas, que podem ser implementadas em software ou hardware, e tem como objetivo simular o funcionamento de um computador real.

<p>O desenvolvimento de algoritmos para um computador hipotético envolve a criação de um conjunto de instruções que possam ser executadas pelo modelo. Essas instruções podem incluir operações aritméticas, de entrada e saída de dados, desvio de fluxo, entre outras.

<p>Para implementar um algoritmo em C para um computador hipotético, eu defini as instruções disponíveis, bem como as regras para a execução de cada uma delas. Isso envolveu a criação de estruturas de dados para representar o estado atual do computador (como o conteúdo do acumulador, o endereço atual da instrução, etc.) e a implementação de funções para executar cada instrução.

<p>Além disso, é importante ter em mente que um computador hipotético não possui todas as funcionalidades de um computador real, como por exemplo um sistema operacional ou uma interface gráfica. Por isso, os programas desenvolvidos para esse tipo de computador costumam ser bastante simplificados e focados em demonstrar conceitos específicos de programação.

<p>Eu deixei comentado no código cada instrução, mas pra quem tem interesse em ver mais sobre, pode acessar esse link: https://www.ime.usp.br/~jstern/miscellanea/MaterialDidatico/hipo.htm

### Pré-requisitos

Antes de começar, você vai precisar ter instalado em sua máquina as seguintes ferramentas:
[Git](https://git-scm.com), [C](https://www.cprogramming.com/). 
Além disto é bom ter um editor para trabalhar com o código como [VSCode](https://code.visualstudio.com/)

### 🎲 Executando o algoritmo

```bash
# Clone este repositório
$ git clone <https://github.com/lucasmunizz/hipo-simulator>

# Acesse a pasta do projeto no terminal/cmd
$ cd hipo-simulator

# Compile a aplicação
$ gcc hipo_simulator.c -o hipo_simulator.exe

# Execute a aplicação
$ ./hipo_simulator.exe hipo.txt
