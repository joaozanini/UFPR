import java.util.Scanner;

public class brincadeira2 {
    public static void main(String[] args) {
        //String frase = "ela é um morango do amor, não ta no menu ela é fofinha e bravinha tipo um labubu";
        Scanner sc = new Scanner(System.in);
        String frase = sc.nextLine();

        String alfabeto = " abcdefghijklmnopqrstuvwxyzáãéõ";

        String ram = "";

        for (char letra : frase.toCharArray()) {
            for (char letraAlfabeto : alfabeto.toCharArray()) {
                System.out.print(ram);
                System.out.print(letraAlfabeto + "\n");
                if (letraAlfabeto == letra) {
                    ram = ram + letra;
                    break;
                }
                try {
                    Thread.sleep(250);
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
            }
        }

        for (char letra : frase.toCharArray()) {
            System.out.print(letra);
            try {
                Thread.sleep(250);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
