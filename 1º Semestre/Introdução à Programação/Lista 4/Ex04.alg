algoritmo "Ex04"
// Fun��o :
// Autor :
// Data : 28/05/2015
// Se��o de Declara��es 
var
   n,num,maior,menor:NUMERICO
inicio
   // Se��o de Comandos
   n <- 1
   ENQUANTO (n <= 254) FACA
      ESCREVA("Digite um n�mero:")
      LEIA(num)
      SE (n = 1) ENTAO
         maior <- num
         menor <- num
      SENAO
         SE (num > maior) ENTAO
            maior <- num
         FIMSE
         SE (num < menor) ENTAO
            menor <- num
         FIMSE
      FIMSE
      n <- n + 1
   FIMENQUANTO
   ESCREVAL("A diferen�a entre ", menor," e o ", maior, " � ", (maior-menor))
fimalgoritmo
