algoritmo "Ex02"
// Fun��o :
// Autor :
// Data : 28/05/2015
// Se��o de Declara��es 
var
   // N�o pode ser NUMERICO pois n�o poder�
   // fazer o MOD(%) para verificar se � divis�vel
   n,num : INTEIRO
inicio
   // Se��o de Comandos
   n <- 1
   ENQUANTO (n <= 155) FACA
      ESCREVA("Digite um n�mero: ")
      LEIA(num)
      SE ((num MOD 4) = 0) ENTAO
         ESCREVAL(num, " � divis�vel por 4")
      FIMSE
      n <- n + 1
   FIMENQUANTO
fimalgoritmo
