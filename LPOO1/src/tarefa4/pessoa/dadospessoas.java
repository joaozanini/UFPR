package tarefa4.pessoa;

public class dadospessoas {
    public static void main(String[] args) {
        pessoa p1 = new pessoa();
        p1.setNome("Joao");
        p1.setIdade(18);
        p1.setEndereco("R. Dr. Alcides Vieira Arcoverde, 1225");

        p1.imprime();

        System.out.println("João fez aniversário!");
        p1.fazAniversario();
        p1.imprime();
    }
}
