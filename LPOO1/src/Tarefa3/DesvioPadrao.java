package Tarefa3;

import java.util.Scanner;

public class DesvioPadrao {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("número de amostras: ");
        int n = sc.nextInt();

        double[] amostras = new double[n];

        for (int i = 0; i < n; i++) {
            System.out.printf("Amostra %d: ", i + 1);
            amostras[i] = sc.nextDouble();
        }

        double soma = 0;
        for (double valor : amostras) {
            soma += valor;
        }
        double media = soma / n;

        double somaQuadrados = 0;
        for (double valor : amostras) {
            somaQuadrados += Math.pow(valor - media, 2);
        }

        double desvioPadrao = Math.sqrt(somaQuadrados / (n - 1));

        System.out.printf("Média das amostras = %.4f\n", media);
        System.out.printf("Desvio padrão amostral = %.4f\n", desvioPadrao);

        sc.close();
    }
}
