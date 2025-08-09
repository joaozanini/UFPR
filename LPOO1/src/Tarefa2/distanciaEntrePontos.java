package Tarefa2;

import java.util.Scanner;

public class distanciaEntrePontos {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Cordanadas do primeiro ponto (x y): ");
        String input1 = sc.nextLine();

        String[] partes1 = input1.trim().split("[,\\s]+");

        int[] ponto1 = new int[2];
        ponto1[0] = Integer.parseInt(partes1[0]); // x
        ponto1[1] = Integer.parseInt(partes1[1]); // y

        System.out.print("Cordenadas do segundo ponto (x y): ");
        String input2 = sc.nextLine();

        String[] partes2 = input2.trim().split("[,\\s]+");

        int[] ponto2 = new int[2];
        ponto2[0] = Integer.parseInt(partes2[0]);
        ponto2[1] = Integer.parseInt(partes2[1]);

        int dx = ponto2[0] - ponto1[0];
        int dy = ponto2[1] - ponto1[1];

        double distancia = Math.sqrt(Math.pow(dx, 2) + Math.pow(dy, 2));

        System.out.println("Distância entre os pontos: " + distancia);
    }
}
