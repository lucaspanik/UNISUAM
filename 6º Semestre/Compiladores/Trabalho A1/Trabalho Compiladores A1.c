#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// header for functions
void displayHeader();
void automato();
int nextState(char letter);

// declared here to make it global
// will be used on automato() method.
int cid = 0;
int current_state = 0;
int final_states[2] = { 4, 7 };

int main(int argc, char *argv[]) {

	char word[100];
	displayHeader();
	printf("\n Informe a palavra para o automato: ");

	scanf("%[^\n]", word);

	printf("\n Palavra informada: %s\n", word);
	printf(" Processamento do automato: \n\n");
	automato(word);

	//system("pause");
	return 0;
}

void displayHeader(){
	system("cls");
	printf("--------------------------------------------------------------------------------\n");
	printf(" Automato Finito Deterministico (AFD)                                           \n");
	printf(" Por: Renan Medina (15101455) && Lucas Moraes (15100471)                        \n");
	printf(" Alfabeto aceito: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, +, -, ., E}                    \n");
	printf(" Estado inicial: Q0                                                             \n");
	printf(" Estado final: {Q4, Q7}                                                         \n");
	printf("--------------------------------------------------------------------------------\n");
}

void automato(char w[100]){
  int i = 0;
  char read_c = 'x';
  while(i < strlen(w) && read_c != '\0'){
  	read_c = w[i];
  	// check for digits
  	printf("\n Lendo caracter %c (Q%d)", read_c, current_state);
  	current_state = nextState(read_c);
  	if (current_state == -1){
        read_c = '\0';
        printf(" : Caracter NAO pertence ao alfabeno.");
    }else{
        printf(" -> Q%d", current_state);
        i++;
    }
  }

  printf("\n\n Resultado: \n");
  printf("\n ******************************************************************\n");
  if(current_state != final_states[0] && current_state != final_states[1])
  	printf(" * \n * PALAVRA NAO ACEITA! (%s) \n * \n", w);
  else
  	printf(" * \n * PALAVRA ACEITA !!!! (%s) \n * \n", w);

  printf("\n ******************************************************************\n");
  system("pause");
}



int nextState(char letter){
	// reading 0 || 1 || 2 || 3 || 4 || 5 || 6 || 7 || 8 || 9
	if((int) letter > 47 && (int) letter < 58){
	  switch(current_state){
	  	case 0:
	  	case 1:
	  		return 2;
	  		break;
	  	case 3:
	  		return 4;
	  		break;
	  	case 5:
	  	case 6:
	  		return 7;
	  		break;
	  	default: // state == 2, 4, 7
	  		return current_state;
	  		break;
	  }
	}
	// reading + || -
	else if(letter == '+' || letter == '-'){
		switch(current_state){
			case 0:
		  		return 1;
		  		break;
		  	case 5:
		  		return 6;
		  		break;
		  	default:
		  		return current_state;
		  		break;
		}
	}
	// reading .
	else if(letter == '.'){
		switch(current_state){
			case 0:
			case 1:
		  		return 3;
		  		break;
		  	case 2:
		  		return 4;
		  		break;
		  	default:
		  		return current_state;
		  		break;
		}
	}
	// reading " " (white-space)
	else if(letter == 'e' || letter == 'E'){
		switch(current_state){
			case 2:
				return 5;
				break;
			case 4:
		  		return 5;
		  		break;
		  	default:
		  		return current_state;
		  		break;
		}
	}
	// character not accepted
	else {
		return -1;
	}
}


