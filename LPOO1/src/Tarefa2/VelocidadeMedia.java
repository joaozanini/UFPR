package Tarefa2;

import java.util.Scanner;

public class VelocidadeMedia {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Distância percorrida em km: ");
        double distancia = sc.nextDouble();

        System.out.print("Tempo gasto em minutos: ");
        double tempo = sc.nextDouble();

        System.out.printf("\nVelocidade Média: %.2f km/m", distancia / tempo);
    }
}
