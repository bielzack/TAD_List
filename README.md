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
E execute:

**Ambiente Windows:**
```cmd
gcc scr/main.c scr/sllist.c -o programa.exe
.\programa.exe

**Ambiente Linux:**
```cmd
gcc scr/main.c scr/sllist.c -o programa
./programa

# 3. Funcionalidades Implementadas
O sistema dispõe de um menu interativo com as seguintes operações:

1 - Inserir música na Playlist 01: Aloca dinamicamente uma música e a insere no início da lista.

2 - Inserir música na Playlist 02: Aloca dinamicamente uma música e a insere no final da lista.

3 - Remover música da Playlist 01: Remove uma música específica baseada em uma busca por Título, Artista ou Ano.

4 - Remover música da Playlist 02: Remove uma música específica da segunda playlist usando os mesmos critérios.

5 - Listar a Playlist 01: Percorre e exibe na tela todas as músicas salvas na primeira lista.

6 - Listar a Playlist 02: Percorre e exibe na tela todas as músicas salvas na segunda lista.

7 - Gerar a MixPlaylist (União): Cria e exibe uma nova playlist contendo todas as músicas da Playlist 01 e da Playlist 02, sem duplicar faixas que tenham o mesmo título.

8 - MATCH entre Playlists (Intersecção): Cria e exibe uma nova lista contendo apenas as músicas que estão presentes simultaneamente em ambas as playlists.

0 - Sair (Encerramento Seguro): Libera toda a memória alocada dinamicamente. Possui uma trava de segurança que impede o fechamento do programa caso o usuário ainda não tenha esvaziado as listas originais.

##Identificação
Disciplina: Estruturas de Dados I
Aluno:Gabriel Serra Bastos.
