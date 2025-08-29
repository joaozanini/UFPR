package tarefa4.circunferencia;

public class circunferencia {
    private double raio;

    public double getRaio() {
        return raio;
    }

    public void setRaio(double raio) {
        this.raio = raio;
    }

    public double getAreaCircunferencia() {
        return Math.PI * this.raio * this.raio;
    }
}
