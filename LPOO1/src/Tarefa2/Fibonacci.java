package Tarefa2;

import java.util.Scanner;

public class Fibonacci {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int value;
        do {
            System.out.println("Digite um número inteiro positivo: ");
            value = sc.nextInt();
        } while (value < 0);

        int a = 0, b = 1;

        System.out.println("Série de Fibonacci até " + value + ":");

        while (a <= value) {
            System.out.print(a + " ");
            int proximo = a + b;
            a = b;
            b = proximo;
        }
    }
}
