##### Rio, 05/03/2018

Sistemas distribuídos tem como proósito de "descentralizar" informações e processamento.

o SD tem que dar transparência pro usuário acima de tudo.

**Obs.:** Nao existe rede confiável, e sim comunicação confiável.

**DataCenters**
> O grande problema dos datacenters é justamente a temperatura (refrigeração), onde faz com que as empresas busquem soluções diferentes, 
como colocar datacenters no fundo do mar, que aproveitam a energia gerada com as ondas, e temperaturas mais baixas dos oceanos.

**Mobilidade**
> O termo mobilidade pode ser usada como uma das características do sistema distribuído, pois possibilita o acesso das informações independente do local de acesso.

#### O que é Sistemas distribuídos?
> Um SD é um conjunto de computadores independentes que se apresenta a seus usuários como um sistema único e coerente.

> Os componentes são chamados de **autônomos**.

#### Metas (questão de prova)
- Acesso de recurso
- Transparência na distribuição
- Abertura de sistema 
- Escalabalidade

#### Tolerância a falha
> Consiste em manter o serviço funcionando mesmo com falha de máquinas.


## Sistema X (pegar nome)
#### Computação em Cluster
> Tem como premissa onde todas as máquinas e sistemas operacionais são idênticos.

#### Computação em Grade
> São várias máquinas heterogênica onde os hardwares e sistemas são distintos



## Sistema Y (pegar nome)
#### Sistema de processamento de transações
> PEGAR DEFINIÇÃO

#### Sistemas Pervasivos
> PEGAR DEFINIÇÃO




## Sistema Z (pegar nome)
#### Sistemas Embutidos
> Feitos para hardwares próprios como Tvs digitais, Tablet, etc...



##### Rio, 12/03/2018

### Arquiteturas (Questão da Prova):
> Classificações abstratas com base em caracterrísticas da arquitetura.

**Camadas**
> Cada camada tem sua responsabilidade e funções, muito igual o modelo OZI em redes, realizando suas ações e passando para camada abaixo no fluxo de requisição e para cima no fluxo de resposta.

**Objetos**
> Tem como características em orientação a objetos, cada objeto corresponde a um componente sendo conectados por chamadas remotas de quaisquer ponto da infraestrutura designada. 

**Centrada em Dados**
> Se comunicam por meio de um repositório comum, tem ideia de compartilhar via rede, como se fosse uma única base de dados compartilhada entre os usuários. Como se fosse um Clound com dados e arquivos guardados.

**Eventos**
> Tem como ideia do barramento, onde é disparado um evento no barramento e quem tiver 'ouvindo' o evento irá realizar alguma tarefa.


### Arquiteturas Centralizadas:
Inicialmente tinha a base de Cliente X Servidor, embora tenham sido criadas com 2 camadas, hoje são definas como no mínimo três níveis:
- Nível de Interface com Usuários
- Nível de Processamento
- Nível de Dados

### Arquiteturas Descentralizadas:
No centralização tem como distribuição vertical, já a descentralizada tem distribuição horizontal. Cada componente é completo do ponto de vista funcional e colabora com seus peers (pares).


### Mediador (Middleware)
Forma de abstrair os sistemas operacionais na camada abaixo para trabalhar de forma mediar as informações pro usuário da camada acima, foco em abstração pro usuário.

# -----------------


##### Rio, 19/03/2018

## Processos e Threads


# -----------------


##### Rio, 26/03/2018

- Comunicação de Processos
- Nomeação
- Sincronização

## Comunicação de Processos (RPC)
> É um protocolo que abstrai para o desenvolvedor as regras de envio de dados na rede, 

## Nomeação
> 

## Sincronização
> Uma das formas cruciais de sincronismo num S.D é o relógio, e nele é usado o protocolo NTP (Network Time Protocol) que pode ser usado pra troca de informações de sincronização. Em redes sem fio, esse método é substituído por RBS (Reference Broadcast Synchronism).

> Num S.D tem questões fundamentais que é a concorrência e colaboração. Isso, muitas vezes, significa a exclusão mútua a recursos compartilhados. Em S.D, podemos dividir as estratégias de exclusão mútua em 2 tipos: 
> - Baseados em ficha (Só faz quem ta com a permissão de ser feito no momento)
> - Baseados em permissão (O Access Poinnt controla quem pode transmitir)
