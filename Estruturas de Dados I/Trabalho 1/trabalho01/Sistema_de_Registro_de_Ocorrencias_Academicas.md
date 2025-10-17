# Sistema de Registro de Ocorrências Acadêmicas

## Trabalho Prático I – Estrutura de Dados Linear com Interface de Aplicação

### Objetivo Geral
Desenvolver, em grupos, uma aplicação em linguagem C que utilize listas lineares (estáticas, dinâmicas, encadeadas, circulares, duplas ou com cabeçalho) de forma funcional, com foco no armazenamento, manipulação e exibição de dados relacionados a um contexto real, integrando teoria e prática.

### Cenário-Problema
A coordenação pedagógica precisa de um sistema para registrar ocorrências acadêmicas dos estudantes, como advertências, elogios e faltas. Cada ocorrência está ligada a um aluno e possui uma descrição, tipo e data. A equipe pedagógica precisa consultar rapidamente todas as ocorrências por aluno e navegar por elas de forma sequencial, tanto para frente quanto para trás (ex: da mais recente à mais antiga e vice-versa).

### Regras e Restrições Didáticas
Cada grupo deverá entregar um diário de bordo com relatos semanais do processo de desenvolvimento, contendo:
- Quem fez o quê (responsabilidade individual)  
- Dificuldades encontradas e como foram resolvidas  
- Trechos de código explicados em suas palavras  

Cada membro do grupo apresentará oralmente ao professor (ou banca) uma das funções implementadas, explicando:
- A lógica por trás da função  
- Como a lista foi usada ali  
- Por que aquela estrutura foi a mais adequada  

O código deve conter um comentário de autoria no topo de cada função, explicando sua função e quem a desenvolveu.

### Funcionalidades mínimas obrigatórias
- Cadastrar estudante (nome, RA, turma)  
- Registrar nova ocorrência (RA, tipo, data, descrição)  
- Listar todas as ocorrências por RA (ordem mais recente → mais antiga)  
- Permitir navegação em ambas direções (lista dupla encadeada)  
- Remover ocorrência específica por RA + data  
- Filtrar por tipo de ocorrência (advertência, elogio ou falta)  

### Entrega e Itens Avaliados
**Prazo:** 2 semanas a partir da data de publicação do trabalho  
**Entrega:** via repositório GitHub + apresentação oral + diário de bordo (PDF)  

Arquivos esperados:
- `main.c`: menu principal  
- `estudantes.c` / `estudantes.h`: cadastro de estudantes  
- `ocorrencias.c` / `ocorrencias.h`: gerenciamento das ocorrências  
- `lista.c` / `lista.h`: lista duplamente encadeada  
- `README.md`: orientações, autoria e explicações  
- `diario_de_bordo.pdf`: processo de desenvolvimento e responsabilidades  
