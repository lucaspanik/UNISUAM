#include <stdio.h>

main(){
	int dia;
	
	printf("Digite um numero entre 1 e 7: ");
	scanf("%d", &dia);
	
	switch(dia){
		case 1:
			printf("Domingo");
			break;
		case 2: 
			printf("Segunda");
			break;
		case 3:
			printf("Terca-feira");
			break;
		case 4:
			printf("Quarta-feira");
			break;
		case 5:
			printf("Quinta-feira");
			break;
		case 6:
			printf("Sexta-feira");
			break;
		case 7:
			printf("Sabado");
			break;
		default:
			printf("Dia invalido!");
			break;		
	}
}
