package Tarefa1;

import java.util.Scanner;

public class Calculadora {
    public static void main(String[] args) {
        System.out.println("<número 1> <número 2> <operação>");
        Scanner sc = new Scanner(System.in);

        double resultado;
        String input =  sc.nextLine();

        String[] op = input.split(" ");
        double num1 = Double.parseDouble(op[0]);
        double num2 = Double.parseDouble(op[1]);
        String operacao = op[2];

        switch (operacao) {
            case "+":
                resultado = num1 + num2;
                break;
            case "-":
                resultado = num1 - num2;
                break;
            case "*":
                resultado = num1 * num2;
                break;
            case "/":
                if (num2 == 0) {
                    System.out.println("Erro: divisão por zero!");
                    return;
                }
                resultado = num1 / num2;
                break;
            default:
                System.out.println("Operação inválida! Use +, -, * ou /");
                return;
        }

        System.out.println(resultado);
    }
}
