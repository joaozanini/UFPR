package Tarefa3;

import java.util.Scanner;

public class indicePluviometrico {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        double soma = 0;
        int contador = 0;

        double maxIndice = Double.MIN_VALUE;
        int diaMax = -1;

        double minIndice = Double.MAX_VALUE;
        int diaMin = -1;

        for (int i = 0; i < 7; ) {
            try {
                System.out.printf("Índice do dia %d: ", i + 1);
                double value = sc.nextDouble();

                soma += value;
                contador++;


                if (value > maxIndice) {
                    maxIndice = value;
                    diaMax = i + 1;
                }

                if (value < minIndice) {
                    minIndice = value;
                    diaMin = i + 1;
                }

                i++;

            } catch (Exception e) {
                System.out.println("Digite apenas números válidos!");
                sc.nextLine();
            }
        }

        double media = soma / contador;

        System.out.printf("\nMédia semanal: %.2f\n", media);
        System.out.printf("Maior índice: %.2f (Dia %d)\n", maxIndice, diaMax);
        System.out.printf("Menor índice: %.2f (Dia %d)\n", minIndice, diaMin);

        sc.close();
    }
}
