package tarefa5.aluno;

public class usaAluno {
    public static void main(String[] args) {
        Aluno aluno1 = new Aluno("João Zanini", "GRR20242373", "TADS", 3, 3, "Rua Genérica");

        // Fazendo algumas matrículas
        aluno1.fazMatricula("LPOO");
        aluno1.fazMatricula("Humanidades");
        aluno1.fazMatricula("Banco de Dados II");

        // Testando exceder as matriculas
        aluno1.fazMatricula("Redes");

        // Cancelando uma matrícula
        aluno1.cancelarMatricula("Humanidades");

        // Refazendo matricula em Redes
        aluno1.fazMatricula("Redes");

        // Imprimindo informações
        aluno1.imprime();
    }
}
