algoritmo "L�NumImprimeTodosInteirosde1AteNumCasoMultiplosde3ou5"
var
 n,i:inteiro
inicio
   Escreval("Digite um n�mero")
   Leia(n)
   para i de 1 ate n passo 1 faca
     se (i%3=0)  entao
        Escreval(i, " atende ao crit�rio, pois � m�ltiplo de 3")
     fimse
     se (i%5=0)  entao
        Escreval(i, " atende ao crit�rio, pois � m�ltiplo de 5")
     fimse
   fimpara
fimalgoritmo
