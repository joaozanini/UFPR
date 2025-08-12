package Tarefa3;

import java.util.InputMismatchException;
import java.util.Scanner;

public class MediaSalarial {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        double somaSalarios = 0;
        int numFuncionarios;
        
        while (true) {
            try {
                System.out.print("Número de funcionários da empresa: ");
                numFuncionarios = sc.nextInt();
                sc.nextLine();
                if (numFuncionarios > 0) break;
                System.out.println("O número de funcionários deve ser maior que zero!");
            } catch (InputMismatchException e) {
                System.out.println("Digite apenas números inteiros válidos!");
                sc.nextLine();
            }
        }

        String[] nomes = new String[numFuncionarios];
        double[] salarios = new double[numFuncionarios];

        for (int i = 0; i < numFuncionarios; i++) {
            while (true) {
                System.out.print("Nome: ");
                nomes[i] = sc.nextLine().trim();
                if (nomes[i].length() >= 3) break;
                System.out.println("O nome não pode conter menos de 3 caracteres!");
            }

            while (true) {
                try {
                    System.out.print("Salário: ");
                    salarios[i] = sc.nextDouble();
                    sc.nextLine();
                    if (salarios[i] >= 0) break;
                    System.out.println("O salário não pode ser negativo!");
                } catch (InputMismatchException e) {
                    System.out.println("Digite um valor numérico válido!");
                    sc.nextLine();
                }
            }

            somaSalarios += salarios[i];
        }

        double media = somaSalarios / numFuncionarios;
        System.out.printf("\nMédia salarial: R$ %.2f%n", media);

        System.out.println("\nFuncionários com salário acima da média:");
        for (int i = 0; i < salarios.length; i++) {
            if (salarios[i] > media) {
                System.out.printf("%s | R$ %.2f%n", nomes[i], salarios[i]);
            }
        }

        sc.close();
    }
}
