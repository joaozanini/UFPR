package Tarefa3;

import java.util.Scanner;

public class SomaDiagonais {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("dimensão da matriz quadrada: ");
        int n = sc.nextInt();

        int[][] matriz = new int[n][n];

        System.out.println("Digite os valores da matriz (" + n + "x" + n + "):");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print("Elemento [" + i + "][" + j + "]: ");
                matriz[i][j] = sc.nextInt();
            }
        }

        int soma = 0;
        for (int i = 0; i < n; i++) {
            soma += matriz[i][i];           // diagonal principal
            soma += matriz[i][n - 1 - i];  // diagonal secundária
        }

        if (n % 2 == 1) {
            soma -= matriz[n / 2][n / 2];
        }

        System.out.println("A soma das diagonais é: " + soma);

        sc.close();
    }

}

