Este projeto foi desenvolvido na linguagem C com a finalidade de implementar uma Lista Encadeada Simples, explorando conceitos fundamentais como ponteiros, alocação dinâmica de memória e manipulação de estruturas de dados. Para demonstrar o funcionamento dessa estrutura de forma prática, foi criada uma aplicação de gerenciamento de músicas. Por meio dela, o usuário pode adicionar músicas em duas playlists diferentes (Playlist 01 e Playlist 02), excluir músicas com base em critérios específicos, realizar operações de união e interseção entre as playlists e gerar uma terceira lista contendo os resultados dessas operações, tudo através de um menu interativo executado no terminal.



Se os seus arquivos estiverem dentro de uma subpasta chamada `scr`, entre nela primeiro:
```bash
cd scr
```

E execute:

**Ambiente Windows:**
```cmd
gcc scr/main.c scr/sllist.c -o programa.exe
gcc main.c sllist.c -o programa.exe
.\programa.exe
```

**Ambiente Linux:**
```cmd
gcc scr/main.c scr/sllist.c -o programa
```bash
gcc main.c sllist.c -o programa
./programa
```

# 3. Funcionalidades Implementadas
O sistema dispõe de um menu interativo com as seguintes operações:
---

## 3. Funcionalidades Implementadas

1 - Inserir música na Playlist 01: Aloca dinamicamente uma música e a insere no início da lista.
Inserir na Playlist 01: Permite cadastrar uma nova música na Playlist 01, adicionando-a no início da lista encadeada.

2 - Inserir música na Playlist 02: Aloca dinamicamente uma música e a insere no final da lista.
Inserir na Playlist 02: Permite cadastrar uma nova música na Playlist 02, adicionando-a no final da lista encadeada.

3 - Remover música da Playlist 01: Remove uma música específica baseada em uma busca por Título, Artista ou Ano.
Remover da Playlist 01: Permite remover uma música armazenada na Playlist 01. A busca do registro pode ser realizada pelo título, artista ou ano de lançamento.

4 - Remover música da Playlist 02: Remove uma música específica da segunda playlist usando os mesmos critérios.
Remover da Playlist 02: Permite remover uma música armazenada na Playlist 02. A busca do registro pode ser realizada pelo título, artista ou ano de lançamento.

5 - Listar a Playlist 01: Percorre e exibe na tela todas as músicas salvas na primeira lista.
Listar Playlist 01: Exibe todas as músicas cadastradas na Playlist 01.

6 - Listar a Playlist 02: Percorre e exibe na tela todas as músicas salvas na segunda lista.
Listar Playlist 02: Exibe todas as músicas cadastradas na Playlist 02.

7 - Gerar a MixPlaylist (União): Cria e exibe uma nova playlist contendo todas as músicas da Playlist 01 e da Playlist 02, sem duplicar faixas que tenham o mesmo título.
Listar Playlist 03 (União): Cria e exibe uma terceira playlist contendo todas as músicas presentes na Playlist 01 e Playlist 02, sem duplicação de registros.

8 - MATCH entre Playlists (Intersecção): Cria e exibe uma nova lista contendo apenas as músicas que estão presentes simultaneamente em ambas as playlists.
Listar Playlist 03 (Interseção): Cria e exibe uma terceira playlist contendo apenas as músicas presentes simultaneamente na Playlist 01 e Playlist 02.

0 - Sair (Encerramento Seguro): Libera toda a memória alocada dinamicamente. Possui uma trava de segurança que impede o fechamento do programa caso o usuário ainda não tenha esvaziado as listas originais.
Sair: Fecha o programa após liberar a memória alocada, contando com uma trava de segurança que exige que as playlists originais estejam vazias para evitar vazamentos de memória.

---

## Identificação


Disciplina: Estruturas de Dados I
Aluno:Gabriel Serra Bastos.

Aluno: Gabriel Serra Bastos



