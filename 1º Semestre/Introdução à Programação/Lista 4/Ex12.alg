algoritmo "ex12"
// Fun��o :
// Autor :
// Data : 7/6/2015
// Se��o de Declara��es 
var
   op, filhos:inteiro
   sal, sal_media, sal_maior, sal_minimo, sal_menor, filhos_media:real
   sair:caracter
inicio
      sal_maior <- -1
      enquanto (op <= 5000000) e (sair <> "s") faca
            op <- op + 1
            escreva("Digite o sal�rio do ",op,"� habitante         : ")
            leia(sal)
            escreva("Digite o n�mero de filhos do ",op,"� habitante: ")
            leia(filhos)
            
            sal_media <- sal_media + sal
            filhos_media <- filhos_media + filhos
            
            se (sal > sal_maior) entao
                sal_maior <- sal
            fimse
            
            se (sal < 788) entao
                sal_menor <- sal_menor + 1
            fimse
            
            repita
                escreva("Deseja sair? (S/N): ")
                leia(sair)
            ate (sair = "s") ou (sair = "n")
      fimenquanto
      
      escreval("M�dia de sal�rio da popula��o                               : R$", sal_media / op)
      escreval("M�dia do n�mero de filhos                                   : ", filhos_media / op, " filho(s)/habitante")
      escreval("Maior sal�rio dos habitantes                                : R$", sal_maior)
      escreval("Percentual de pessoas com sal�rio menor que o sal�rio m�nimo: ", (sal_menor * 100)/op)
fimalgoritmo
