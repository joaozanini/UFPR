package Tarefa3;

import java.util.Scanner;

public class Palindromo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Digite uma frase: ");
        String fraseOriginal = sc.nextLine();

        String fraseTratada = fraseOriginal.toLowerCase()
                .replaceAll("[^a-z0-9]", "");

        String fraseInvertida = new StringBuilder(fraseTratada).reverse().toString();

        if (fraseTratada.equals(fraseInvertida)) {
            System.out.println("É um palíndromo!");
        } else {
            System.out.println("Não é um palíndromo.");
        }

        sc.close();
    }
}
