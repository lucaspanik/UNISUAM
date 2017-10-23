##### Rio, 14/08/2017

Provas escritas:
>- A1 - 09/10
>- A2 - 04/12
>- A3 - 18/12
>- Feriado - 20/11

***
#### Matéria

**Rede**
> Para se denominar uma rede podemos definir que existem dois ou mais computadores que utilizam um sistema básico de comunicação que envolva: Transmissor, Meio de Transmissão, Mensagem Trasmitida e o Receptor.

**Multiplexação:**
> Em um único canal é possível utilizar mais de um protocolo de transferência em rede.

**Internet:** 
> É uma interconexão de redes locais

**Camadas**
> Dados/mensagens da camada da **Aplicação** para a camada **Física** sofrem encapsulamento, já da **Física** para a **Aplicação** sofrem o desencapsulamento.


***


##### Rio, 21/08/2017

Aplicações em tempo real permitem perda de pacotes.

TCP -> Não tolera perda de pacotes

UDP -> Tolera perda de pacotes

HTTP não persistente -> Abre e fecha uma conexao pra cada objeto (Imagem, js, css) necessário para carregar uma página.

HTTP Persistente -> Abre e Fecha a conexão apenas uma única vez independente da quantidade de objetos necessários para abrir uma página.

RTT-> É o tempo que dura para o pacote trafegar do cliente ao servidor.

**Problemas do HTTP (Não Persistente):**
- Requer sempre **2 RTT** por objeto
- Overhead do SO para cada conexão TCP
- Nevegadores geralmente abrem conexões TCP paralelas  para buscar objetos referenciados.
 
**HTTP Persistente:**
- servidor deixa conexão aberta depois de enviar a resposta
- mensagem HTTP seguintes entre cliente/servidor são enviadas pela conexão aberta
- cliente envia requisições assim  que encontra o objeto referenciado
- no mínimo um **RTT** para todos os objetos referenciados.



***


##### Rio, 28/08/2017

### Camada de Aplicação

FTP (TCP) (21 e 20)
> Os dados são transportados via "Plain Text" onde não há criptografia, o que acaba não sendo muito utilizado. A porta 21 é usada para navegação e controle entre as pastas, já a porta 20 é utilizada exclusivamente para transferência de arquivos entre o cliente/servidor.


**Correio Eletrônico**

SMTP (TCP) (25) 
> Protocolo de envio e recebimento de e-mails. Utiliza a organização de Fila, primeiro e-mail que chegar será o primeiro a ser transferido. Nessa transferência ocore em 3 fases:
    1) HandShaking (Saudação) onde é validado se ambos os servidores estão funcionando e apto a transferirem mensagens
    2) Transferência dos arquivos
    3) Fechamento da conexão

DNS (53)
> Converte um nome em um IP, podendo dar nomes/apelidos a servidores que tem IP ou nomes canônicos difíceis de se lembrar por exemplo. Usado também para distribuição de carga em servidores Web.

Telnet(23)


***


##### Rio, 04/09/2017

### Camada de Transporte (TCP e UDP)
A camada de transporte é responsável por preparar as informações da camada de aplicação para a camada de rede.

TCP(20 Bytes) e UDP(8 Bytes) são os protocolos da camada de transporte.
- **Estabelecimento de uma Sessão** faz uma verificação se o caminho de transporte esta funcionando e pronta para receber os dados.
- **Entrega na Mesma Ordem** garante que os dados sejam entregues sequencialmente como foram enviados mesmo que recebidos aleatoriamente.
- **Entrega Confiável** reenviando os pacotes perdidos.
- **Controle de fluxo** gerencia a entrega de dados se há congestionamento no host. (como se fosse um guarda de trânsito mandando ir e vir)


***


##### Rio, 11/09/2017

### Processos TCP
Protocolo que estabelece conexão para envio e recebimento das informações. Dados que chegam em ordem erradas são organizados no servidor de destino. Os dados perdidos são reenviados.

#### IPT
> Diferença entre o UDP e TCP. Para que serve cada um. Porque um cabeçalho é maior que o outro.

#### Handshake Triplo
> Faz uma verificação entre origem e destino para verificar se esta online e pronta para estabelecer uma conexão. 

**Abrindo e estabelecimento a conexão**
> O PC de origem envia um pacote  SYN para destino e o destino se online retorna um pacote SYN e um pacote ACK, sendo ACK uma confirmação de recebimento do pacote SYN, por fim o origem envia um ACK para o destino para estabelecer uma conexão.

**Fechando e encerrando a conexão**
> O PC de origem envia um pacote FIN para destino e o destino retorna um pacote ACK, sendo ACK uma confirmação de recebimento do pacote FIN. O destino envia um FIN para o origem e por fim o origem envia um ACK para o destino como confirmação de recebimento do pacote FIN para encerrar uma conexão.


**MTU - Max Trasnfer Unit (Ethernet)**
> Controle de fluxo onde há um reconhecimento de Segmento TCP e Tamanho da Janela, caso haja perda de pacote, a janela é reduzida pro mínimo (1500).



### Processos UDP
Protocolo que não estabelece uma conexão para envio de dados, como o envio de SYN, ACK, FIN. Os Dados chegam fora de ordem e NÃO são organizados no servidor de origem. Os dados perdidos são efetivamente perdidos.



***


##### Rio, 18/09/2017

### Camada de Rede
> A camada de rede é sem conexão, ou seja, nenhuma conexão é estabelecida antes do envio dos pacotes de dados. (Ao contrário do TCP que tem conexão). O pacote (cabeçalho IP e Segmento) são sempre os mesmos independente do meio físico que o transporta (fio, cabo ethernet, coaxial, fibra ótica, wi-fi, etc)
Os endereços de IP de origem e destino se mantem sempre os mesmos ao percorrer por toda a rede até chegar no destino.

### Tipos de Endereço

##### Endereço de Rede
É sempre o primeiro endereço ip PAR disponível naquela sub rede. (Exemplo: 192.168.0.0)

##### Endereço Broadcast
É sempre o último ip IMPAR disponível de cada sub rede. (Exemplo: 192.168.0.127)

##### Endereço de Host
São os endereços IP entre o endereço de rede e o endereço de broadcast.
(Exemplo: 192.168.0.1 - 192.168.0.1.126)




Qual é o endereço de rede e boadcast do IP 192.168.0.157/30?
Fórmula:
Máscara em binário COM AND LÓGICO COM o ultimo octeto do IP
(and LÓGICA (O QUE É 1 É 1 SE TIVER ZERO EH ZERO).
```
   11111100 (30 Decimal)
   10011101 (157 Decimal)
 --------------------------
   10011100 (156 Decimal) (Rede)
   
   Broadcast: Rede + quantidade de IP - 1
   Broadcast: 156 + 4 - 1
   Broadcast: 159
   Intervalo de ip: 157 à 158
 ```


***


##### Rio, 23/10/2017

### Tecnologias 

CIDR
> Roteamento sem uso de classes- permite um melhor aproveitamento dos endereços disponíveis

RFC 1918
> Endereços privados - permite o uso de endereços não válidos na internet nas redes corporativas

NAT
> Tradução de endereços - permite que um endereço válido na internet apenas, toda uma rede de computadores usando endereços privados seja conectada, mas com várias restrições. ***Ou Seja converte um IP inválido (da rede interna) para um IP válido pra rede externa (internet)***.

DHCP
> Alocação dinâmica de endreços IP - permite que provedores reutilizem endereços internet para conexões não permanentes (ainda é usada como solução paliaiva, ajudando até agora, dando-nos tempo para desenvolver o ***IPv6*** mas também colaborando para a demora em sua adoção)


IPv4
> 32 bits

IPv6
> 128 bits

### Endereços
Uma mesma interface de rede tem város endereços, com funções diversas:

Loopback
> Válido para host

Link Local
> Válido para rede local, assinalado automaticamente com base no MAC Address.

Global
> Válido na internet

### Mudanças
o IPv6 não é uma atualização do IPv4, o 6 é um protocolo completamente novo. De ponto de vista dos equipamentos é um protocolo **diferente**. Para implantar o 6, serão necessárias mudanças de roteadores, switches, farewalls entre outras coisas como programas legados, sistemas operacionais antigos com as características antigas.

##### Como fazer a implantação? IPv4 e IPv6 odem conviver?

#### Pilha dupla (dual stack)
> - Os equipamentos usam simultamente IPv4 e IPv6 
> - Quanto à conectividade à internet, pode ser: Só IPv4, Só IPv6, ou ambos.

### Túneis (conectando pilhas de IPv6 entre si)
> - O IPv6 pode ser encapsulado dentro de conexão IPv4.
> - Os pacotes IPv6 podem ser transmitidos dentro do pacote IPv4.
> - IPv6-over-IPv4 / Tunnel Broker / 6to4 / ISATAP / Teredo.

### Tradução de pacotes (redes IPv4 conversando com redes IPv6)
> Reescrevendo os cabeçalhos dos pacotes IP
> Reescrevendo os cabeçalhos dos pacotes TCP

### Tradução de Aplicações















