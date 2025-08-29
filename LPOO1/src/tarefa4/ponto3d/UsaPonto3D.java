package tarefa4.ponto3d;

public class UsaPonto3D {
    public static void main(String[] args) {
        Ponto3D p1 = new Ponto3D();
        p1.setX(1);
        p1.setY(2);
        p1.setZ(3);

        Ponto3D p2 = new Ponto3D();
        p2.setX(4);
        p2.setY(6);
        p2.setZ(8);

        double distancia = p1.calculaDistancia(p2);
        System.out.printf("A distância entre p1 e p2 é: %.2f", distancia);
    }
}
