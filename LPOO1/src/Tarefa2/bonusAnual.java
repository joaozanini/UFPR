package Tarefa2;

import java.sql.SQLOutput;
import java.util.Scanner;

public class bonusAnual {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Cargo: ");
        String cargo =  sc.nextLine();

        System.out.print("Salário Atual: ");
        double salario = sc.nextDouble();

        switch (cargo) {
            case "Diretor":
                System.out.print("Quantidade de departamentos gerenciados: ");
                int departsQnt = sc.nextInt();

                double bonusDiretor = salario * 4 + 3000 * departsQnt;
                System.out.println("Bônus: " + bonusDiretor);
                break;

            case "Gerente":
                System.out.print("Quantidade de pessoas gerenciadas: ");
                int pessoasQnt = sc.nextInt();

                double bonusGerente = salario * 2 + 100 * pessoasQnt;
                System.out.println("Bônus: " + bonusGerente);
                break;

            case "Analista":
                System.out.println("Bônus: " + salario);

            case "Programador":
                System.out.println("Bônus: " + salario * 0.8);

            case "Auxiliar de Limpeza":
                System.out.println("Bônus: " + salario * 0.5);
        }

        sc.close();
    }
}
