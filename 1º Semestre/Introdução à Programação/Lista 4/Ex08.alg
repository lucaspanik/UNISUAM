algoritmo "ex08"
// Fun��o :
// Autor :
// Data : 7/6/2015
// Se��o de Declara��es 
var
   fimloop:caracter
   num,par,impar:inteiro
inicio
      enquanto (fimloop <> "sair") faca
           escreva("Digite um n�mero: ")
           leia(num)
           
           se (num % 2 = 0) entao
               par <- par + 1
           senao
               impar <- impar + 1
           fimse
           

           escreval(" --- PARA SAIR DIGITE sair PARA A VARI�EL fimloop  ---")
           escreva("fimloop <- ")
           leia(fimloop)
      fimenquanto
      
      escreval("Percentual de n�meros pares inseridos : ", (100*par)/(par+impar),"%")
      escreval("Percentual de n�eros �mpares inseridos: ", (100*impar)/(par+impar), "%")
fimalgoritmo
