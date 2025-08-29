package tarefa5.Bicicleta;

public class Bicicleta {
    private int marchaAtual;
    private int velocidade;
    private int numeroMaximoMarchas;

    public Bicicleta() {
        this.numeroMaximoMarchas = 18;
        this.marchaAtual = 0;
        this.velocidade = 0;
    }

    public Bicicleta(int numeroMaximoMarchas) {
        this.numeroMaximoMarchas = numeroMaximoMarchas;
        this.marchaAtual = 0;
        this.velocidade = 0;
    }

    // Getters e Setters
    public int getMarchaAtual() {
        return marchaAtual;
    }

    public int getVelocidade() {
        return velocidade;
    }

    public int getNumeroMaximoMarchas() {
        return numeroMaximoMarchas;
    }

    // Metodos para mudar a marcha
    public void subirMarcha() {
        if (marchaAtual < numeroMaximoMarchas) {
            marchaAtual++;
        } else {
            System.out.println("Marcha máxima alcançada!");
        }
    }

    public void descerMarcha() {
        if (marchaAtual > 0) {
            marchaAtual--;
        } else {
            System.out.println("Marcha mínima já alcançada!");
        }
    }

    // Metodo para acelerar a bicicleta
    public void acelerar(int incremento) {
        if (incremento > 0) {
            velocidade += incremento;
        }
    }

    // Metodo para frear a bicicleta
    public void frear(int decremento) {
        if (decremento > 0) {
            velocidade -= decremento;
            if (velocidade < 0) {
                velocidade = 0;
            }
        }
    }
}
