package tarefa5.aluno;

import java.util.ArrayList;
import java.util.List;

public class Aluno {
    private String nome;
    private String matricula;
    private String curso;
    private int periodo;
    private int quantidadeMatriculasPermitidas;
    private ArrayList<String> disciplinasMatriculadas;
    private String endereco;

    // Construtor
    public Aluno(String nome, String matricula, String curso, int periodo, int quantidadeMatriculasPermitidas, String endereco) {
        this.nome = nome;
        this.matricula = matricula;
        this.curso = curso;
        this.periodo = periodo;
        this.quantidadeMatriculasPermitidas = quantidadeMatriculasPermitidas;
        this.disciplinasMatriculadas = new ArrayList<>();
        this.endereco = endereco;
    }

    // Getters e Setters
    public String getNome() { return nome; }
    public void setNome(String nome) { this.nome = nome; }

    public String getMatricula() { return matricula; }
    public void setMatricula(String matricula) { this.matricula = matricula; }

    public String getCurso() { return curso; }
    public void setCurso(String curso) { this.curso = curso; }

    public int getPeriodo() { return periodo; }
    public void setPeriodo(int periodo) { this.periodo = periodo; }

    public int getQuantidadeMatriculasPermitidas() { return quantidadeMatriculasPermitidas; }
    public void setQuantidadeMatriculasPermitidas(int quantidadeMatriculasPermitidas) { this.quantidadeMatriculasPermitidas = quantidadeMatriculasPermitidas; }

    public List<String> getDisciplinasMatriculadas() { return new ArrayList<>(disciplinasMatriculadas); }

    public String getEndereco() { return endereco; }
    public void setEndereco(String endereco) { this.endereco = endereco; }

    // Metodos da Classe
    public void fazMatricula(String disciplina) {
        if (quantidadeMatriculasPermitidas == 0) {
            System.out.println("Este aluno não pode ser matriculado em nenhuma disciplina, por favor, fale com a secretaria.");
        } else if (disciplinasMatriculadas.size() >= quantidadeMatriculasPermitidas) {
            System.out.printf("Quantidade de disciplinas excedida. O limite de disciplinas para este aluno é de %d disciplina(s).\n", quantidadeMatriculasPermitidas);
        } else {
            disciplinasMatriculadas.add(disciplina);
            System.out.printf("Matrícula na disciplina “%s” executada.\n", disciplina);
        }
    }

    public void cancelarMatricula(String disciplina) {
        if (disciplinasMatriculadas.contains(disciplina)) {
            disciplinasMatriculadas.remove(disciplina);
            System.out.printf("“Cancelamento da matrícula da disciplina %s executado com sucesso.\n",  disciplina);
        } else {
            System.out.printf("Aluno não está matriculado na disciplina %s, portanto não é possível cancelar esta matrícula.\n", disciplina);
        }
    }

    public void imprime() {
        System.out.println("-----------------------------------------------------------------");
        System.out.println("Nome do aluno: " + nome);
        System.out.println("Matricula: " + matricula);
        System.out.println("Curso: " + curso);
        System.out.println("Periodo: " + periodo);
        System.out.print("Disciplinas Matriculadas: ");
        for (int i = 0; i < disciplinasMatriculadas.size(); i++) {
            System.out.print(disciplinasMatriculadas.get(i));
            if (i < disciplinasMatriculadas.size() - 1) {
                System.out.print(", ");
            }
        }
        System.out.println();
        System.out.println("-----------------------------------------------------------------\n");
    }
}
