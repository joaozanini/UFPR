import java.util.Scanner;

public class brincadeira {
    public static void main(String[] args) {
        //Scanner sc = new Scanner(System.in);
        //String texto = sc.nextLine();

        String texto = "Ela é um morango do amor-não ta no menu-ela é fofinha e bravinha-tipo um labubu";

        String[] textoSeparado = texto.split("");

        for(String letra : textoSeparado) {
            if(letra.equals("-")) {
                System.out.println();
            } else {
                try {
                    System.out.print(letra);
                    Thread.sleep(25);
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
            }
        }
    }
}
