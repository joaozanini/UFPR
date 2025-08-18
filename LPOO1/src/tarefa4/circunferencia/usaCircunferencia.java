package tarefa4.circunferencia;

public class usaCircunferencia {
    public static void main(String[] args) {
        circunferencia c1 = new circunferencia();

        c1.setRaio(5);
        System.out.printf("Área da circunferência: %.2f", c1.getAreaCircunferencia());
    }
}
