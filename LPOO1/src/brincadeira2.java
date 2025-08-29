public class brincadeira2 {
    public static void main(String[] args) {
        String frase = "felipao é massa demais";
        String alfabeto = " abcdeéfghijklmnopqrstuvwxyz0123456789";

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
