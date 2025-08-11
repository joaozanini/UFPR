package Tarefa2;

import java.util.Scanner;

import java.util.Scanner;

public class EqSegundoGrau {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("coeficiente a: ");
        double a = sc.nextDouble();

        System.out.print("coeficiente b: ");
        double b = sc.nextDouble();

        System.out.print("coeficiente c: ");
        double c = sc.nextDouble();

        double delta = Math.pow(b, 2) - 4 * a * c;

        double x1 = (-b + Math.sqrt(delta)) / (2 * a);
        double x2 = (-b - Math.sqrt(delta)) / (2 * a);

        System.out.printf("x1 = %.2f x2 = %.2f", x1, x2);

        sc.close();
    }
}

