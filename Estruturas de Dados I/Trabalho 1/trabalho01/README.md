# Sistema de Registro de Ocorrências Acadêmicas

Projeto em C que implementa as funcionalidades mínimas exigidas no enunciado utilizando:

- Lista simples para estudantes
- Lista duplamente encadeada circular com nó sentinela para ocorrências por estudante

## Funcionalidades Implementadas
1. Cadastrar estudante (nome, RA, turma)
2. Registrar nova ocorrência (RA, tipo, data, descrição)
3. Listar todas as ocorrências por RA em ordem (mais recente → mais antiga) com navegação interativa para frente e para trás
4. Remover ocorrência específica por RA + data
5. Filtrar por tipo de ocorrência (advertência, elogio ou falta)
6. Listar estudantes cadastrados (extra para facilitar testes)

## Estruturas de Dados

```c
typedef struct OcorrenciaNode {
    struct OcorrenciaNode *prev, *next;
    Data data;
    TipoOcorrencia tipo;
    char descricao[256];
} OcorrenciaNode;
```

Lista circular com sentinela: quando vazia, `sentinela->next == sentinela`.
Inserções mantêm ordem decrescente por data (mais recente primeiro).

Estudantes:

```c
typedef struct Estudante {
    int ra; char nome[100]; char turma[20];
    ListaOcorrencias *ocorrencias;
    struct Estudante *next;
} Estudante;
```

## Compilação

```bash
gcc main.c estudantes.c ocorrencias.c lista.c -o sistema
```

## Execução

```bash
./sistema
```

## Navegação de Ocorrências
Ao escolher a opção 3 (listar por RA) é aberto um modo de navegação:
```
[n] proxima | [p] anterior | [q] sair
```

## Remoção
Remoção identifica a ocorrência pela data. Assume-se que não haverá duas ocorrências no mesmo dia para o mesmo aluno (simplificação). Se necessário diferenciar, pode-se estender a chave (ex: incluir tipo e prefixo de descrição).

## Autoria das Funções
Cada função contém um comentário de autoria com os integrantes do grupo:
- João Zanini
- Carlos Vital
- Felipe Laskos
- João Manoel
- Cayo Vinícius

### Mapa de Autoria
- Carlos Vital: `estudantes_init`, `estudantes_adicionar`, `estudantes_listar`
- João Zanini: `estudantes_buscar`, `lista_criar`, `lista_destruir`, `lista_primeiro`, `lista_ultimo`
- João Manoel: `lista_inserir_ordenado` (+ `eh_mais_recente`), `comparar_datas`
- Cayo Vinícius: `estudantes_destruir`, `lista_remover_por_data`, `lista_contar_por_tipo`
- Felipe Laskos: `registrar_ocorrencia`, `listar_ocorrencias_por_ra`, `filtrar_por_tipo`, `remover_ocorrencia`, `parse_data`, `data_to_string`
