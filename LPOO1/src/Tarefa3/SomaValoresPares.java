package Tarefa3;

import java.util.Scanner;

public class SomaValoresPares {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        double soma = 0;
        int contador = 0;

        while(contador < 20) {
            System.out.printf("Digite o %dº número: ", contador + 1);
            try {
                double valor = sc.nextDouble();
                if (valor % 2 == 0) {
                    soma += valor;
                }
                contador++;
            } catch (Exception e) {
                System.out.println("Entrada inválida. Digite apenas números.");
                sc.nextLine();
            }
        }

        System.out.println("Soma dos números pares: " + soma);
        sc.close();
    }
}
