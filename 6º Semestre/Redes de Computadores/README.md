###### Rio, 14/08/2017

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
***
###### Rio, 21/08/2017

Aplicações em tempo real permitem perda de pacotes.

TCP -> Não tolera perda de pacotes

UDP -> Tolera perda de pacotes

HTTP não persistente -> Abre e fecha uma conexao pra cada objeto (Imagem, js, css) necessário para carregar uma página.

HTTP Persistente -> Abre e Fecha a conexão apenas uma única vez independente da quantidade de objetos necessários para abrir uma página.

RTT-> É o tempo que dura para o pacote trafegar do cliente ao servidor.

**Problemas do HTTP (Não Persistente):**
- Requer sempre 2 RTT por objeto
- Overhead do SO para cada conexão TCP
- Nevagadores geralmente abrem conexões TCP paralelas  para buscar objetos referenciados.
 
**HTTP Persistente:**
- servidor deixa conexão aberta depois de enviar a resposta
- mensagem HTTP seguintes entre cliente/servidor são enviadas pela conexão aberta
- cliente envia requisições assim  que encontra o objeto referenciado
- no mínimo um RTT para todos os objetos referenciados.