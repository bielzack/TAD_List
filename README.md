# Trabalho de Implementação 02 - TAD Lista Encadeada

## Descrição do Projeto
Este projeto foi desenvolvido na linguagem C com a finalidade de implementar uma Lista Encadeada Simples, explorando conceitos fundamentais como ponteiros, alocação dinâmica de memória e manipulação de estruturas de dados. Para demonstrar o funcionamento dessa estrutura de forma prática, foi criada uma aplicação de gerenciamento de músicas. Por meio dela, o usuário pode adicionar músicas em duas playlists diferentes (Playlist 01 e Playlist 02), excluir músicas com base em critérios específicos, realizar operações de união e interseção entre as playlists e gerar uma terceira lista contendo os resultados dessas operações, tudo através de um menu interativo executado no terminal.

Estrutura das musicas:
* `char titulo[100]`: Título da música.
* `char artista[100]`: Nome do artista ou banda.
* `int ano`: Ano de lançamento da música.

---

## 1. Ambiente de Desenvolvimento
* **Sistemas Operacionais:** Windows / Linux Ubuntu / macOS.
* **Compilador:** GCC (MinGW no Windows).
* **Bibliotecas:** Bibliotecas padrão da linguagem C (`stdio.h`, `stdlib.h`, `string.h`) e a biblioteca customizada `"sllist.h"`.

---

## 2. Compilação e Execução
Se os seus arquivos estiverem dentro de uma subpasta chamada `scr`, entre nela primeiro:
```bash
cd scr
```

E execute:

**Ambiente Windows:**
```cmd
gcc main.c sllist.c -o programa.exe
.\programa.exe
```

**Ambiente Linux:**
```bash
gcc main.c sllist.c -o programa
./programa
```

---

## 3. Funcionalidades Implementadas

Inserir na Playlist 01: Permite cadastrar uma nova música na Playlist 01, adicionando-a no início da lista encadeada.

Inserir na Playlist 02: Permite cadastrar uma nova música na Playlist 02, adicionando-a no final da lista encadeada.

Remover da Playlist 01: Permite remover uma música armazenada na Playlist 01. A busca do registro pode ser realizada pelo título, artista ou ano de lançamento.

Remover da Playlist 02: Permite remover uma música armazenada na Playlist 02. A busca do registro pode ser realizada pelo título, artista ou ano de lançamento.

Listar Playlist 01: Exibe todas as músicas cadastradas na Playlist 01.

Listar Playlist 02: Exibe todas as músicas cadastradas na Playlist 02.

Listar Playlist 03 (União): Cria e exibe uma terceira playlist contendo todas as músicas presentes na Playlist 01 e Playlist 02, sem duplicação de registros.

Listar Playlist 03 (Interseção): Cria e exibe uma terceira playlist contendo apenas as músicas presentes simultaneamente na Playlist 01 e Playlist 02.

Sair: Fecha o programa após liberar a memória alocada, contando com uma trava de segurança que exige que as playlists originais estejam vazias para evitar vazamentos de memória.

---

## Identificação

Disciplina: Estruturas de Dados I

Aluno: Gabriel Serra Bastos


