algoritmo "Ex05"
// Fun��o :
// Autor :
// Data : 29/05/2015
// Se��o de Declara��es
var
   soma: NUMERICO
   entrada: CARACTER
inicio
   // Se��o de Comandos
   soma <- 0
   ESCREVAl("Escreva SAIR para finalizar o programada ou")
   ESCREVA("digite um n�mero para continuar: ")
   LEIA(entrada)
   ENQUANTO (entrada <> "sair") FACA
      // caracpnum() serve para converter tipo caracter
      // em real ou inteiro possibilitando a soma
      soma <- soma +  caracpnum(entrada)
      ESCREVAl("Escreva SAIR para finalizar o programada ou")
      ESCREVA("digite um n�mero para continuar: ")
      LEIA(entrada)
   FIMENQUANTO
   ESCREVAL("Soma dos n�meros digitados:", soma)
fimalgoritmo
