#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ocorrencias.h"

// Utilidades de leitura
static void ler_linha(const char *prompt, char *buffer, size_t tam) {
    printf("%s", prompt);
    if (fgets(buffer, tam, stdin)) {
        size_t len = strlen(buffer);
        if (len && buffer[len-1] == '\n') buffer[len-1] = '\0';
    } else {
        buffer[0] = '\0';
    }
}

static TipoOcorrencia ler_tipo() {
    char op[16];
    printf("Tipos: 1-Advertencia 2-Elogio 3-Falta > ");
    fgets(op, sizeof(op), stdin);
    int n = atoi(op);
    switch (n) {
        case 1: return TIPO_ADVERTENCIA;
        case 2: return TIPO_ELOGIO;
        case 3: return TIPO_FALTA;
        default: printf("Opcao invalida, usando Advertencia.\n"); return TIPO_ADVERTENCIA;
    }
}

static Data ler_data() {
    char linha[32];
    Data d = {0,0,0};
    while (1) {
        ler_linha("Data (DD/MM/AAAA): ", linha, sizeof(linha));
        if (parse_data(linha, &d)) break;
        printf("Data invalida.\n");
    }
    return d;
}

static void menu() {
    printf("\n==== Sistema de Registro de Ocorrencias Academicas ====\n");
    printf("1 - Cadastrar estudante\n");
    printf("2 - Registrar ocorrencia\n");
    printf("3 - Listar ocorrencias por RA (navegacao)\n");
    printf("4 - Remover ocorrencia (RA+data)\n");
    printf("5 - Filtrar ocorrencias por tipo\n");
    printf("6 - Listar estudantes\n");
    printf("0 - Sair\n");
    printf("> ");
}

int main() {
    ListaEstudantes estudantes;
    estudantes_init(&estudantes);
    char opcao[8];
    while (1) {
        menu();
        if (!fgets(opcao, sizeof(opcao), stdin)) break;
        int op = atoi(opcao);
        if (op == 0) break;
        if (op == 1) {
            char nome[100], turma[20], linha[32];
            ler_linha("RA: ", linha, sizeof(linha)); int ra = atoi(linha);
            ler_linha("Nome: ", nome, sizeof(nome));
            ler_linha("Turma: ", turma, sizeof(turma));
            if (estudantes_adicionar(&estudantes, ra, nome, turma)) printf("Estudante cadastrado.\n"); else printf("Falha: RA duplicado ou erro.\n");
        } else if (op == 2) {
            char linha[32];
            ler_linha("RA: ", linha, sizeof(linha)); int ra = atoi(linha);
            Data d = ler_data();
            TipoOcorrencia t = ler_tipo();
            char desc[256];
            ler_linha("Descricao: ", desc, sizeof(desc));
            if (registrar_ocorrencia(&estudantes, ra, d, t, desc)) printf("Ocorrencia registrada.\n"); else printf("Falha ao registrar (RA inexistente?).\n");
        } else if (op == 3) {
            char linha[32]; ler_linha("RA: ", linha, sizeof(linha)); int ra = atoi(linha);
            listar_ocorrencias_por_ra(&estudantes, ra);
        } else if (op == 4) {
            char linha[32]; ler_linha("RA: ", linha, sizeof(linha)); int ra = atoi(linha);
            Data d = ler_data();
            if (remover_ocorrencia(&estudantes, ra, d)) printf("Removida.\n"); else printf("Nao encontrada.\n");
        } else if (op == 5) {
            TipoOcorrencia t = ler_tipo();
            filtrar_por_tipo(&estudantes, t);
        } else if (op == 6) {
            estudantes_listar(&estudantes);
        } else {
            printf("Opcao invalida.\n");
        }
    }
    estudantes_destruir(&estudantes);
    printf("Encerrado.\n");
    return 0;
}
