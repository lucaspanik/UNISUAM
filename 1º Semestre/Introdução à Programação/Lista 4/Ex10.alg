algoritmo "ex10"
// Fun��o :
// Autor :
// Data : 7/6/2015
// Se��o de Declara��es 
var
   conceito,media,maior_media:real
   sair, nome, maior_nome:caracter
inicio
      maior_media <- -1
      enquanto (sair <> "s") faca
           media <- 0
           
           escreva("Digite o nome do biba loka : ")
           leia(nome)
           
           repita
                escreva("Cavalheiro            : ")
                leia(conceito)
           ate (conceito >= 0) e (conceito <= 10)
           media <- media + conceito
           
           repita
                escreva("Gosta de dar presentes: ")
                leia(conceito)
           ate (conceito >= 0) e (conceito <= 10)
           media <- media + conceito
           
           repita
                escreva("Elogiar               : ")
                leia(conceito)
           ate (conceito >= 0) e (conceito <= 10)
           media <- media + conceito
           
           repita
                escreva("Beijo bom             : ")
                leia(conceito)
           ate (conceito >= 0) e (conceito <= 10)
           media <- media + conceito
           
           repita
                escreva("Endinheirado          : ")
                leia(conceito)
           ate (conceito >= 0) e (conceito <= 10)
           media <- media + conceito
           
           repita
                escreva("Pegada boa            : ")
                leia(conceito)
           ate (conceito >= 0) e (conceito <= 10)
           media <- media + conceito
           
           media <- media / 6
           
           se (media > maior_media) entao
               maior_nome <- nome
               maior_media <- media
           fimse
           
           repita
               escreva("Deseja sair? (S/N): ")
               leia(sair)
           ate (sair = "s") ou (sair = "n")
      fimenquanto
      
      escreval("Melhor cachorr�o at� agora: ", nome)
      escreval("M�dia do melhor cachorr�o : ", maior_media)
fimalgoritmo
