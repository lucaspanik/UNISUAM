algoritmo "Ex03"
// Fun��o :
// Autor :
// Data : 28/05/2015
// Se��o de Declara��es 
var
   num: INTEIRO
inicio
   // Iniciei com ESCREVA e LEIA antes do ENQUANTO para ter o controle do -1,
   // caso o usuario ja digite de primeira vez o -1 j� ir� bloquear.
   // Coisa que se tivesse no inicio do ENQUANTO seria executado ao menos uma
   // vez mesmo digitando -1, sendo um programa incorreto na l�gica
   ESCREVA("Digite um n�mero inteiro (-1 para sair):")
   LEIA(num)
   ENQUANTO (num <> -1)FACA
      SE (num <> 0) ENTAO
         SE ((NUM MOD 2) = 0) ENTAO
            ESCREVAL(num, " � par")
         SENAO
            ESCREVAL(num, " � �mpar")
         FIMSE
      FIMSE
      ESCREVA("Digite um n�mero inteiro (-1 para sair):")
      LEIA(num)
   FIMENQUANTO
fimalgoritmo
