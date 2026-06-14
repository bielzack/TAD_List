#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sllist.h"

#define TRUE 1 
#define FALSE 0

//estrutura da musica
typedef struct _Musica_{
    char titulo[100];
    char artista[100];
    int ano;
}Musica;

//função de comparação por título
int cmpTitulo(void *key, void *item){
    char *KeyTitulo = (char *)key;
    Musica *musica = (Musica*) item;

    if(strcasecmp(KeyTitulo, musica->titulo) == FALSE){
        return TRUE;
    }
    return FALSE;
}

//função de comparação por ano
int cmpAno(void *key, void* item){
    int *KeyAno = (int *)key;
    Musica *musica = (Musica *)item;

    if(*KeyAno == musica->ano){
        return TRUE;
    }
    return FALSE;
}

//função de comparação por artista
int cmpArtista(void *key, void *item){
    char *chaveArtista = (char *)key;
    Musica *musica = (Musica*) item;

    if(strcasecmp(chaveArtista, musica->artista) == FALSE){
        return TRUE;
    }
    return FALSE;
}

int main(){
    //criando as 3 listas
    SLList *c1 = sllCreate();
    SLList *c2 = sllCreate();
    SLList *c3 = sllCreate();
    
    void* delet;
    void* resultado;
    int flag;
    int opcao = -1;

   // Laço de repetição principal para manter o menu ativo
    while(opcao != 0){
        printf("\n----MENU PLAYLIST----\n");
        printf("\n1 - Inserir uma musica na Playlist 01");
        printf("\n2 - Inserir uma musica na Playlist 02");
        printf("\n3 - Remover uma musica da Playlist 01");
        printf("\n4 - Remover uma musica da Playlist 02");
        printf("\n5 - Listar a Playlsit 01");
        printf("\n6 - Listar a Playlist 02");
        printf("\n7 - Gerar a MixPlaylist");
        printf("\n8 - MATCH entre a  Playlist 01 e da Playlist 02");
        printf("\n0 - Sair");

        printf("\nEscolha um opcao: ");
        scanf("%d", &opcao);
        getchar();

        // Estrutura de decisão para executar a ação escolhida no menu
        switch (opcao){
            case 1:{
                if(c1 != NULL){
                    Musica* musicaC1;
                    musicaC1 = (Musica *)malloc(sizeof(Musica));
                    if(musicaC1 != NULL){
                        printf("Titulo da musica: ");
                        fgets(musicaC1->titulo, 100, stdin);
                        musicaC1->titulo[strcspn(musicaC1->titulo, "\n")] = '\0'; 

                        printf("Artista/Banda: ");
                        fgets(musicaC1->artista, 100, stdin);
                        musicaC1->artista[strcspn(musicaC1->artista, "\n")] = '\0';

                        printf("Ano de Lancamento: ");
                        scanf("%d", &musicaC1->ano);
                    
                        flag = sllInsertAsFirst(c1, (void*)musicaC1);
                        if(flag == TRUE){
                            printf("\nMusica inserida na Playlist 01 com sucesso!\n");
                        } else {
                            free(musicaC1);
                            printf("\nErro ao inserir musica na PlayList 01!\n");
                        }   
                    }
                }
            }
            break;

            // Bloco de inserção de nova música no final da Playlist 02
            case 2:{
                if(c2 != NULL){
                    Musica * musicaC2;
                    musicaC2 = (Musica*)malloc(sizeof(Musica));
                    if(musicaC2 != NULL){
                        printf("Titulo da musica: ");
                        fgets(musicaC2->titulo, 100, stdin);
                        musicaC2->titulo[strcspn(musicaC2->titulo, "\n")] = '\0';

                        printf("Artista/Banda: ");
                        fgets(musicaC2->artista, 100, stdin);
                        musicaC2->artista[strcspn(musicaC2->artista, "\n")] = '\0';

                        printf("Ano de Lancamento: ");
                        scanf("%d", &musicaC2->ano);

                        flag = sllInsertAsLast(c2, (void*)musicaC2);
                        if(flag == TRUE){
                            printf("\nMusica inserida na Playlist 02 com sucesso!\n");
                        }else{
                            free(musicaC2);
                            printf("\nErro ao inserir a musica na Playlist 02!\n");
                        }
                    }
                }
            }
            break;

            // Bloco de remoção de música da Playlist 01 por critério específico
            case 3:{
                if(c1 != NULL){
                    int OptionDelet;
                    delet = NULL;

                    printf("\nRemover musica da Playlist 01 pelo:\n 1-Titulo \n 2-Artista\n 3-Ano\n");
                    printf("Opcao: ");
                    scanf("%d", &OptionDelet);
                    getchar(); 
                    if(OptionDelet == 1){
                        char titulo[100];
                        printf("Digite o titulo da musica: ");
                        fgets(titulo, 100, stdin);
                        titulo[strcspn(titulo, "\n")] = '\0';

                        delet = sllRemoveSpec(c1, (void*)titulo, cmpTitulo);

                    }else if(OptionDelet == 2){
                        char artista[100];
                        printf("Digite o artista: ");
                        fgets(artista, 100, stdin);
                        artista[strcspn(artista, "\n")] = '\0';

                        delet = sllRemoveSpec(c1, (void*)artista, cmpArtista);

                    } else if (OptionDelet == 3){
                        int ano;
                        printf("Digite o ano de lancamento: ");
                        scanf("%d", &ano);

                        delet = sllRemoveSpec(c1, (void*)&ano, cmpAno);
                    }

                    if(delet != NULL){
                        free(delet);  
                        printf("\nMusica removida com sucesso da Playlist 01!\n");
                    } else {
                        printf("\nMusica nao encontrada na Playlist 01!\n");
                    }
                }
            }
            break;
            // Bloco de remoção de música da Playlist 02 por critério específico
            case 4:{
                if(c2 != NULL){
                    int OptionDelet;
                    delet = NULL;

                    printf("\nRemover musica da Playlist 02 por:\n 1-Titulo \n 2-Artista\n 3-Ano\n");
                    printf("Opcao: ");
                    scanf("%d", &OptionDelet);
                    getchar(); 

                    if(OptionDelet == 1){
                        char titulo[100];
                        printf("Digite o titulo da musica para remover na Playlist 02: ");
                        fgets(titulo, 100, stdin);
                        titulo[strcspn(titulo, "\n")] = '\0';

                        delet = sllRemoveSpec(c2, (void*)titulo, cmpTitulo);
                    }else if(OptionDelet == 2){
                        char artista[100];
                        printf("Digite o artista para remover da Playlist 02: ");
                        fgets(artista, 100, stdin);
                        artista[strcspn(artista, "\n")] = '\0';

                        delet = sllRemoveSpec(c2, (void*)artista, cmpArtista);
                    }else if(OptionDelet == 3){
                        int ano;
                        printf("Digite o ano de lancamento: ");
                        scanf("%d", &ano);

                        delet = sllRemoveSpec(c2, (void*)&ano, cmpAno);
                    }
                            
                    if(delet != NULL){
                        free(delet); 
                        printf("\nMusica removida de Playlist 02 com sucesso!\n");
                    }else{
                        printf("\nMusica nao encontrada na Playlist 02!\n");
                    }
                }
            }
            break;

            // percorre e imprime todos os elementos da Playlist 01
            case 5:{
                if(c1 != NULL){
                    printf("\n--- LISTANDO A PLAYLIST 01 ---\n");
                    resultado = sllGetFirst(c1);
                    if(resultado == NULL){
                        printf("Playlist 01 vazia. Adicione novas musicas.\n");
                    }

                    Musica *lista = (Musica*) resultado;
                    while(lista != NULL){
                        printf("Titulo: %s\n", lista->titulo);
                        printf("Artista: %s\n", lista->artista);
                        printf("Ano: %d\n\n", lista->ano);
                        lista = (Musica*)sllGetNext(c1);
                    }
                }
            }
            break;

            // percorre e imprime todos os elementos da Playlist 02
            case 6:{
                if(c2 != NULL){
                    printf("\n--- LISTANDO PLAYLIST 02 ---\n");
                    resultado = sllGetFirst(c2);
                    if(resultado == NULL){
                        printf("Playlist 02 vazia. Adicione novas musicas.\n");
                    }

                    Musica* lista = (Musica*)resultado;
                    while(lista != NULL){
                        printf("Titulo: %s\n", lista->titulo);
                        printf("Artista: %s\n", lista->artista);
                        printf("Ano: %d\n\n", lista->ano);
                        lista = (Musica*)sllGetNext(c2);
                    }
                }
            }
            break;
            //gera a União das duas playlists (músicas das duas sem repetições)
            case 7:{
                if(c1 != NULL && c2 != NULL){
                    printf("\n---LISTANDO a MixPlaylist---\n");
                        
                    if(c3 != NULL){
                        sllDestroy(c3);
                    }

                    c3 = sllUniao(c1, c2, cmpTitulo);

                    resultado = sllGetFirst(c3);
                    if(resultado == NULL){
                        printf("MixPlaylist Vazia.\n");
                    }

                    Musica* lista = (Musica*)resultado;
                    while(lista != NULL){
                        printf("Titulo: %s\n", lista->titulo);
                        printf("Artista: %s\n", lista->artista);
                        printf("Ano: %d\n\n", lista->ano);
                        lista = (Musica*)sllGetNext(c3);
                    }
                }
            }
            break;

            //gera a Intersecção das duas playlists (apenas músicas comuns a ambas)
            case 8:{
                if(c1 != NULL && c2 != NULL){
                    printf("\n---LISTANDO O MATCH DAS PLAYLISTS 01 E 02---\n");

                    if(c3 != NULL){
                        sllDestroy(c3);
                    }

                    c3 = sllInterseccao(c1, c2, cmpTitulo);

                    resultado = sllGetFirst(c3);
                    if(resultado == NULL){
                        printf("Nao ha musicas em comum entre as Playlists VAZIA.\n");
                    }

                    Musica* lista = (Musica*)resultado;
                    while(lista != NULL){
                        printf("Titulo: %s\n", lista->titulo);
                        printf("Artista: %s\n", lista->artista);
                        printf("Ano: %d\n\n", lista->ano);
                        lista = (Musica*)sllGetNext(c3);
                    }
                }
            }
            break;
            //encerramento do programa
            case 0:{
                if (c1 != NULL && c2 != NULL) {
                    if (sllGetFirst(c1) != NULL || sllGetFirst(c2) != NULL) {
                        printf("\nvoce precisa remover todas as musicas da Playlist 1 e Playlist 2 antes de fechar o programa!\n");
                        opcao = -1; 
                    }else{
                        printf("\nSaindo... ate a proxima!\n");
                    }
                }
            }
            break;
        }
    } 
    // Liberação final de memória após sair do menu
    if(c1 != NULL) { 
        sllDestroy(c1);
    }

    if(c2 != NULL){
        sllDestroy(c2);
    }
    
    if(c3 != NULL){
        free(c3); 
    }

    return 0;
}
