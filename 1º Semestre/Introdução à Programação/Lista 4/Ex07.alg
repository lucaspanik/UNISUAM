algoritmo "ex07"
// Fun��o :
// Autor :
// Data : 7/6/2015
// Se��o de Declara��es 
var
   op, idade:inteiro
   sair, sexo:caracter
inicio
      op <- 1
      enquanto (op <= 200) e (sair <> "s") faca
           repita
               escreva("Digite a idade do",op,"� entrevistado: ")
               leia(idade)
           ate (idade > 0) e (idade < 150)
           
           repita
               escreva("Digite o sexo do",op,"� entrevistado : ")
               leia(sexo)
           ate (sexo = "M") ou (sexo = "F")
           
           se (sexo = "M") entao
               se (idade >= 18) entao
                   escreval("MAIOR DE IDADE!")
               senao
                   escreval("MENOR DE IDADE!")
               fimse
           senao
               se (idade >= 21) entao
                   escreval("MAIOR DE IDADE!")
               senao
                   escreval("MENOR DE IDADE!")
               fimse
           fimse
           
           repita
               escreva("Deseja sair? (S/N): ")
               leia(sair)
           ate (sair = "s") ou (sair = "n")
           
           op <- op + 1
      fimenquanto
fimalgoritmo
