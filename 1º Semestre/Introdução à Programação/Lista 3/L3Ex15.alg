algoritmo "L3Ex15"
// Fun��o :
// Autor :
// Data : 13/04/2015
// Se��o de Declara��es 
var
   num,maior,menor,i:inteiro
inicio
// Se��o de Comandos 
      escreval("Informe um n�:")
      leia (num)
      menor <- num
      maior <- num
      para i de 1 ate 131 faca
           escreval ("informe um n�:")
           leia (num)
           se (num > maior) entao
              maior <- num
           fimse
           se (num < menor) entao
              menor <- num
           fimse
      fimpara
      escreval("A diferen�a entre o maior e o menor de todos resulta em:",maior-menor)
      
      
      
      
fimalgoritmo
