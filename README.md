# Trabalho de Implementação 02 - TAD Lista Encadeada

## Descrição do Projeto
Este projeto foi desenvolvido em linguagem C com o objetivo de implementar uma Lista Encadeada Simples e aplicar conceitos relacionados ao uso de ponteiros, alocação dinâmica de memória e manipulação de estruturas de dados. Para mostrar como a estrutura funciona na prática, foi desenvolvida uma aplicação simples de gerenciamento de músicas. Nela, o usuário pode cadastrar músicas em duas playlists distintas (Playlist 01 e Playlist 02), remover registros por critérios específicos, realizar operações de união e interseção entre as listas e gerar uma terceira lista com os resultados, tudo por meio de um menu interativo no terminal.

Cada música possui as seguintes informações:
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
Para compilar o código-fonte e gerar o executável, certifique-se de estar na pasta raiz do projeto (`TAD_Lista`) e utilize os comandos abaixo conforme o seu sistema:

**Ambiente Windows:**
```cmd
gcc scr/main.c scr/sllist.c -o programa.exe
.\programa.exe

**Ambiente Linux:**
```cmd
gcc scr/main.c scr/sllist.c -o programa
./programa

## 3. 
