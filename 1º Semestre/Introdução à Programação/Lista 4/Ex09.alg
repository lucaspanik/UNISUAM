algoritmo "ex09"
// Fun��o :
// Autor :
// Data : 7/6/2015
// Se��o de Declara��es 
var
   dilma,aecio,voto:inteiro
   sair:caracter
inicio
      enquanto (sair <> "s") faca
           escreval("(13) Dilma     ---    (45) A�cio")
           repita
                escreva("Voto: ")
                leia(voto)
           ate (voto = 13) ou (voto = 45)
           
           se (voto = 13) entao
               dilma <- dilma + 1
           senao
               aecio <- aecio + 1
           fimse
           
           repita
                escreva("Deseja sair? (S/N): ")
                leia(sair)
           ate (sair = "s") ou (sair = "n")
      fimenquanto
      
      escreval("(13) Dilma: ", (100*dilma)/(dilma+aecio),"% dos votos com ",dilma," votos.")
      escreval("(45) A�cio: ", (100*aecio)/(dilma+aecio),"% dos votos com ",aecio," votos.")
fimalgoritmo
