#include <stdio.h>
#include <math.h>
#include <string.h>


void exibirMenu();
void exibirTelaDeJogo(int, char [],char [] );
int verificarLetra(char, char [], char [] );
int verificarPalavra(char [], char []);


int main()
{
    #define RED     "\033[1;31m"
    #define RESET   "\033[0m"
    #define  GREEN   "\033[1;32m"

    char palavra[47], letraPalavra[47];
    char alfabeto [51] = "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
    char usadoalfabeto[27];
    int opcaoMenu = 0,QatLetras = 0;

    exibirMenu();
    scanf(" %d", &opcaoMenu);

    if(opcaoMenu == 1){
        printf("Iniciando o jogo...\n");
        printf("Digite a palavra secreta: ");
        scanf(" %46s", palavra);
        QatLetras = strlen(palavra);

        /*for ( int c = 0 ; c < QatLetras ; c++)
            letraPalavra[c] = 'a';
        letraPalavra[QatLetras] = '\0'; */
         memset(letraPalavra, 0, 47);

        for (int vida = 6;vida >0 ;vida--){
            char letra;
            
            exibirTelaDeJogo(QatLetras , alfabeto,letraPalavra);
            if(verificarPalavra(palavra, letraPalavra)){
                break;
            }

            printf("Digite uma letra: ");
            scanf(" %c", &letra);

           // verificarLetra(letra,alfabeto,usadoalfabeto )

            if(verificarLetra(letra, palavra, letraPalavra)){
                printf(GREEN"Letra correta!\n" RESET);
            }else{
                printf(RED "Letra incorreta!\n"RESET );
            }
        }
        printf("vocer galhor\n");


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

void exibirTelaDeJogo(int QatLetras, char alfabeto[], char letraPalavra[] ){
    printf("\n\njogo da Forca\n\n");
    printf(" _______\n");
    printf(" |     |\n");   
    printf(" |     O\n");
    printf(" |    /|\\  \n");
    printf(" |   _/ \\_ \n");
    printf(" |\n");     
    printf("_|_  ");

    int i = 0;
    for(i = 0; i < QatLetras; i++)
        printf("[%c] " , letraPalavra[i]);

    printf("\n\n");
    printf("Letras disponiveis: %s\n", alfabeto);
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
