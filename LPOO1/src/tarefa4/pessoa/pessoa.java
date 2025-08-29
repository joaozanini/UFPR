package tarefa4.pessoa;

public class pessoa {
    private String nome;
    private int idade;
    private String endereco;

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public String getEndereco() {
        return endereco;
    }

    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }

    public void fazAniversario() {
        this.idade++;
    }

    public void imprime() {
        System.out.println("Nome: " + this.nome + "| Idade: " + this.idade + "| Endereco: " + this.endereco );
    }
}
