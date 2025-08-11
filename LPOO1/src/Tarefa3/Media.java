package Tarefa3;

import java.util.Scanner;

public class Media {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        double soma = 0;
        int contador = 0;
        String opcao;

        do {
            System.out.print("Insira um número para entrar na média (ou 's' para sair): ");
            opcao = sc.next();

            if (!opcao.equalsIgnoreCase("s")) {
                try {
                    double numero = Double.parseDouble(opcao);
                    soma += numero;
                    contador++;
                } catch (Exception e) {
                    System.out.println("Entrada inválida. Digite um número ou 's'.");
                }
            }

        } while (!opcao.equalsIgnoreCase("s"));

        if (contador > 0) {
            double media = soma / contador;
            System.out.println("A média é: " + media);
        } else {
            System.out.println("Nenhum número foi informado.");
        }

        sc.close();
    }
}
