import java.util.Scanner;

public class Nome {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String nome_completo = sc.nextLine();

        String[] nomes = nome_completo.split(" ");

        for (int i = nomes.length - 1; i >= 0; i--) {
            System.out.println(nomes[i]);
        }
    }
}