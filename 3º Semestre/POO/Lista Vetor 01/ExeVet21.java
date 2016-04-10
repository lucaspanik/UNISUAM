import java.util.Scanner;

class ExeVet21 {
    public static void main(String args[]) {
        Scanner s new Scanner(System.in);
        double temp[] = new double[121];
        int i, numeroDeDias;
        double menorTemp, maiorTemp, tempMedia,somaTemp;
        
        somaTemp = 0.0;
        for(i = 0; i < temp.length; i++){
            System.out.print("Digite uma temperatura: ");
            temp[i] = s.nextDouble();
            // Menor e Maior
            if (i == 0){
              menorTemp = temp[i];
              maiorTemp = temp[i];               
            }else{
               if(temp[i] < menorTemp)
                   menorTemp = temp[i];
               if(temp[i] > maiorTemp)
                   maiorTemp = temp[i];   
            }
            // Soma da Temperatura
            somaTemp = somaTemp + temp[i];
        }

        tempMedia = somaTemp / temp.length;
        numeroDeDias = 0;
        
         for(i = 0; i < temp.length; i++){
            if(temp[i] < tempMedia)
                numeroDeDias++;
        }
        System.out.println("Menor temperatura: " + menorTemp);
        System.out.println("Maior temperatura: " + maiorTemp);
        System.out.println("Temperatura m?ia: " + tempMedia);
        System.out.println("Número de dias: " + numeroDeDias);
    }
}
