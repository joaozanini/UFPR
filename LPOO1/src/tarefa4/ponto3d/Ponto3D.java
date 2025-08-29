package tarefa4.ponto3d;

public class Ponto3D {
    private double x, y, z;
    private String cor;
    private double intensidade;

    public double getX() {
        return x;
    }

    public void setX(double x) {
        this.x = x;
    }

    public double getY() {
        return y;
    }

    public void setY(double y) {
        this.y = y;
    }

    public double getZ() {
        return z;
    }

    public void setZ(double z) {
        this.z = z;
    }

    public String getCor() {
        return cor;
    }

    public void setCor(String cor) {
        this.cor = cor;
    }

    public double getIntensidade() {
        return intensidade;
    }

    public void setIntensidade(double intensidade) {
        this.intensidade = intensidade;
    }

    public double calculaDistancia(Ponto3D p) {
        return Math.sqrt(
                Math.pow(this.x - p.x, 2) +
                        Math.pow(this.y - p.y, 2) +
                        Math.pow(this.z - p.z, 2)
        );
    }
}
