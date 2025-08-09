package Tarefa2;

import java.util.Scanner;

/**
 * Classe executável que calcula o faturamento anual e ganhos com multas
 * de uma vídeo locadora, dado o número de DVDs disponíveis e o valor
 * do aluguel por DVD.
 *
 * <p>Regras:</p>
 * <ul>
 *     <li>1/3 dos DVDs são alugados por mês.</li>
 *     <li>Multa de 10% do valor do aluguel para DVDs atrasados.</li>
 *     <li>1/10 dos DVDs alugados no mês são devolvidos com atraso.</li>
 * </ul>
 *
 * @author João Vitor Zanini Pedro GRR20242373
 * @version 1.0
 */
public class Locadora {

    /**
     * Método principal que executa o programa.
     *
     * @param args argumentos da linha de comando (não utilizados).
     */

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Quantidade total de DVDs: ");
        int quantidadeDVD = sc.nextInt();

        System.out.print("Valor do aluguel por DVD (R$): ");
        double valorAluguel = sc.nextDouble();

        double alugadosMes = quantidadeDVD / 3.0;
        double faturamentoAnual = alugadosMes * valorAluguel * 12;
        System.out.printf("Faturamento Anual: R$ %.2f%n", faturamentoAnual);

        double valorMulta = valorAluguel * 0.10;
        double qntAtrasados = alugadosMes * 0.10;
        double ganhoMultasMes = valorMulta * qntAtrasados;

        System.out.printf("Ganho com multas por mês: R$ %.2f%n", ganhoMultasMes);
        System.out.printf("Ganho com multas por ano: R$ %.2f%n", ganhoMultasMes * 12);

        sc.close();
    }
}
