#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

void exibirMenu();
void exibirTelaDeJogo(int, char [],char [] , int, char[]);
int verificarLetra(char, char [], char [] );
int verificarPalavra(char [], char []);
int usadoLetra(char , char []);


int main()
{
    #define RED      "\033[1;31m"
    #define RESET    "\033[0m"
    #define  GREEN   "\033[1;32m"
    #define GREY     "\033[1;30m"



    char palavra[47], letraPalavra[47];
    char alfabeto [26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char usadoalfabeto[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int opcaoMenu = 0,QatLetras = 0, vida = 8;

    exibirMenu();
    scanf(" %d", &opcaoMenu);

    if(opcaoMenu == 1){
        printf("Iniciando o jogo...\n");
        printf("Digite a palavra secreta: ");
        scanf(" %46s", palavra);
        _strupr(palavra);
        QatLetras = strlen(palavra);

        /*for ( int c = 0 ; c < QatLetras ; c++)
            letraPalavra[c] = 'a';
        letraPalavra[QatLetras] = '\0'; */
         memset(letraPalavra, 0, 47);

        while (vida > 0)
        {
            char letra;
            
            exibirTelaDeJogo(QatLetras , alfabeto,letraPalavra, vida, usadoalfabeto);
            if(verificarPalavra(palavra, letraPalavra)){
                printf("vocer galhor\n");
                break;
            }

            printf("Digite uma letra: ");
            scanf(" %c", &letra);
            letra = toupper(letra);
 
            if(usadoLetra(letra, usadoalfabeto) == 1){
                if(verificarLetra(letra, palavra, letraPalavra)){
                    printf(GREEN"Letra correta!\n" RESET);
                }else{
                    printf(RED "Letra incorreta!\n" RESET );
                    vida--;
                }
             }else
                  printf(RED "ja foi usado!\n" RESET );
        }
        


    }else if(opcaoMenu == 2){
        printf("Iniciando o jogo automaticamente...\n");

    }else if(opcaoMenu == 3){
        printf("Saindo do jogo...\n");
        return 0;
    }

    printf(" \n");
}

void exibirMenu()
{
    for (int i = 0; i < 25; i++)
        printf("=");
    printf("\nBem Vindo a jogo da Forca\n");
    for (int i = 0; i < 25; i++)
        printf("=");
    printf("\n");
    printf("1 - Jogar\n");
    printf("2 - Automaticamente   \n");
    printf("3 - Sair\n");
}

void exibirTelaDeJogo(int QatLetras, char alfabeto[], char letraPalavra[] , int vida, char usadoalfabeto[]){
    printf("\n\njogo da Forca\n\n");
    printf(" _______\n");
    printf(" |     |\n");   
    printf(" |     ");  
    if(vida < 8) printf("o");
    printf("\n");

    printf(" |    ");
    if(vida == 6) printf(" | ");
    if(vida == 5) printf("/|");
    if(vida <= 4) printf("/|\\");
    printf("\n");

    printf(" |   ");
     if(vida == 3) printf(" /");
     if(vida == 2) printf(" / \\");
     if(vida == 1) printf("_/ \\");
     if(vida == 0) printf("_/ \\_");
    printf("\n");

    printf(" |\n");     
    printf("_|_  ");

    int i = 0;
    for(i = 0; i < QatLetras; i++)
        printf("[%c] " , letraPalavra[i]);

    printf("\n\n");
    printf("Letras disponiveis:");
    for(int t = 0 ; t < strlen(alfabeto) - 1; t++ ){
        if(alfabeto[t] == usadoalfabeto[t] ){
            printf(" %c ", alfabeto[t] );
        }else
            printf( GREY " %c " RESET, alfabeto[t]);
    }

        printf("\n\n");

}

int verificarLetra(char lestra, char palavra[],char letraPalavra[] ){
    int res = 0;
    for(int i = 0; i < strlen(palavra); i++){
        if(lestra == palavra[i]){
            letraPalavra[i] = lestra;
            res =  1;
        }
    } 
    return res;
}

int verificarPalavra(char palavra[], char letraPalavra[]){

    if (strcmp(palavra, letraPalavra) == 0) 
       return 1;
    return 0;
}

int usadoLetra(char lestra, char usadoalfabeto[]){
    for(int i = 0; i < strlen(usadoalfabeto); i++){
        if( lestra == usadoalfabeto[i]){
            usadoalfabeto[i] = tolower(lestra);
            return 1;
        }
    }
    return 0;
}
