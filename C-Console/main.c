#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// Definição de cores para o terminal usando códigos ANSI
#define RED "\033[1;31m"      // Vermelho para mensagens de erro
#define RESET "\033[0m"        // Reseta a cor para o padrão
#define GREEN "\033[1;32m"     // Verde para mensagens de sucesso
#define GREY "\033[1;30m"      // Cinza para letras já usadas

// Protótipos das funções - declaração antecipada
void exibirMenu();
void exibirTelaDeJogo(int, char[]);
void exibirForca(int);
void exibirLetrasDisponiveis(char[], char[]);
int verificarLetra(char, char[], char[]);
int verificarPalavraCompleta(char[], char[]);
int marcarLetraUsada(char, char[]);
void limparQuebraDeLinha(char *);
void sortearPalavra(char *);

int main()
{
    // Inicializa o gerador de números aleatórios com base no tempo atual
    srand(time(NULL));

    // Loop principal do jogo - permite jogar múltiplas partidas
    do
    {
        // Declaração de variáveis para a partida
        char palavraSecreta[47];           // Armazena a palavra que deve ser adivinhada
        char letrasReveladas[47];          // Armazena as letras já descobertas pelo jogador
        char alfabeto[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";           // Alfabeto completo
        char alfabetoDisponivel[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // Letras ainda disponíveis
        int opcaoMenu = 0;                 // Opção escolhida pelo usuário no menu
        int quantidadeLetras = 0;          // Número de letras na palavra secreta
        int vidas = 8;                     // Número de tentativas erradas permitidas

        // Exibe o menu e captura a escolha do usuário
        exibirMenu();
        scanf(" %d", &opcaoMenu);

        // Se o usuário não escolheu sair (opção 3)
        if (opcaoMenu != 3)
        {
            printf("Iniciando o jogo...\n");

            // Modo 1: Usuário digita a palavra secreta
            if (opcaoMenu == 1)
            {
                printf("Digite a palavra secreta: ");
                scanf(" %46s", palavraSecreta);
            }
            // Modo 2: Palavra é sorteada automaticamente do arquivo
            else
            {
                printf("Iniciando o jogo automaticamente...\n");
                sortearPalavra(palavraSecreta);
            }
            
            // Converte a palavra para maiúsculas para padronização
            _strupr(palavraSecreta);
            
            // Conta quantas letras tem a palavra
            quantidadeLetras = strlen(palavraSecreta);
            
            // Inicializa o array de letras reveladas com zeros (vazio)
            memset(letrasReveladas, 0, 47);

            // Loop principal do jogo - continua enquanto houver vidas
            while (vidas > 0)
            {
                char letra;
                printf("\n\nJogo da Forca\n\n");

                // Exibe os elementos visuais do jogo
                exibirForca(vidas);                                        // Desenho da forca
                exibirTelaDeJogo(quantidadeLetras, letrasReveladas);       // Palavra com _ e letras reveladas
                exibirLetrasDisponiveis(alfabeto, alfabetoDisponivel);     // Letras disponíveis

                // Verifica se o jogador completou a palavra
                if (verificarPalavraCompleta(palavraSecreta, letrasReveladas))
                {
                    printf(GREEN "\nParabens! Voce ganhou!\n" RESET);
                    break; // Sai do loop, termina a partida
                }

                // Solicita uma letra ao jogador
                printf("Digite uma letra: ");
                scanf(" %c", &letra);
                letra = toupper(letra); // Converte para maiúscula

                // Verifica se a letra ainda não foi usada
                if (marcarLetraUsada(letra, alfabetoDisponivel) == 1)
                {
                    // Verifica se a letra está na palavra
                    if (verificarLetra(letra, palavraSecreta, letrasReveladas))
                    {
                        printf(GREEN "Letra correta!\n" RESET);
                    }
                    else
                    {
                        // Letra incorreta - perde uma vida
                        printf(RED "Letra incorreta!\n" RESET);
                        vidas--;
                    }
                }
                else
                {
                    // Letra já foi usada anteriormente
                    printf(RED "Essa letra ja foi usada!\n" RESET);
                }
            }
            
            // Se acabaram as vidas, o jogador perdeu
            if (vidas == 0)
            {
                exibirForca(vidas);
                printf(RED "\nVoce perdeu! A palavra era: %s\n" RESET, palavraSecreta);
            }
        }
        // Opção 3: Sair do jogo
        else if (opcaoMenu == 3)
        {
            printf("Saindo do jogo...\n");
            return 0;
        }

        // Mensagem ao final de cada partida
        printf("\n\nFim de jogo! Deseja continuar ou mudar de modo?\n\n");

    } while (1); // Loop infinito - só sai com a opção 3
}


/**
 Exibe o menu principal do jogo com as opções disponíveis
 */
void exibirMenu()
{
    // Linha superior decorativa
    for (int i = 0; i < 25; i++)
        printf("=");
    
    printf("\nBem-vindo ao Jogo da Forca\n");
    
    // Linha inferior decorativa
    for (int i = 0; i < 25; i++)
        printf("=");
    
    printf("\n");
    
    // Opções do menu
    printf("1 - Jogar (definir palavra)\n");
    printf("2 - Jogar (palavra automatica)\n");
    printf("3 - Sair\n");
}

/**
 * Exibe a palavra sendo adivinhada com as letras reveladas
 * @param quantidadeLetras: número total de letras na palavra
 * @param letrasReveladas: array com as letras já descobertas
 */
void exibirTelaDeJogo(int quantidadeLetras, char letrasReveladas[])
{
    int i = 0;
    // Para cada letra da palavra
    for (i = 0; i < quantidadeLetras; i++)
        // Se a letra foi revelada, mostra ela; senão, mostra underscore
        printf("[%c] ", letrasReveladas[i] ? letrasReveladas[i] : '_');

    printf("\n\n");
}

/**
 * Desenha a forca com o boneco de acordo com o número de vidas restantes
 * @param vidas: número de vidas restantes (8 = sem erros, 0 = enforcado)
 */
void exibirForca(int vidas)
{
    // Estrutura da forca
    printf(" _______\n");
    printf(" |     |\n");
    
    // Cabeça (aparece quando vidas < 8)
    printf(" |     ");
    if (vidas < 8)
        printf("O");
    printf("\n");

    // Tronco e braços
    printf(" |    ");
    if (vidas == 6)
        printf(" | ");      // Só o tronco
    if (vidas == 5)
        printf("/|");       // Tronco + braço esquerdo
    if (vidas <= 4)
        printf("/|\\");     // Tronco + ambos os braços
    printf("\n");

    // Pernas
    printf(" |   ");
    if (vidas == 3)
        printf(" /");       // Perna esquerda
    if (vidas == 2)
        printf(" / \\");    // Ambas as pernas
    if (vidas == 1)
        printf("_/ \\");    // Pernas com pé esquerdo
    if (vidas == 0)
        printf("_/ \\_");   // Pernas com ambos os pés (enforcado)
    printf("\n");

    // Base da forca
    printf(" |\n");
    printf("_|_  ");
}

/**
 * Exibe as letras do alfabeto, destacando quais já foram usadas
 * @param alfabeto: alfabeto completo em maiúsculas
 * @param alfabetoDisponivel: alfabeto com letras usadas em minúsculas
 */
void exibirLetrasDisponiveis(char alfabeto[], char alfabetoDisponivel[])
{
    printf("\nLetras disponiveis:");
    
    // Percorre todo o alfabeto
    for (int t = 0; t < strlen(alfabeto); t++)
    {
        // Se a letra ainda está disponível (maiúscula)
        if (alfabeto[t] == alfabetoDisponivel[t])
        {
            printf(" %c ", alfabeto[t]);
        }
        // Se a letra já foi usada (convertida para minúscula)
        else
        {
            printf(GREY " %c " RESET, alfabeto[t]); // Mostra em cinza
        }
    }
    printf("\n");
}

/**
 * Verifica se uma letra está na palavra secreta e revela todas as ocorrências
 * @param letra: letra digitada pelo jogador
 * @param palavraSecreta: palavra que está sendo adivinhada
 * @param letrasReveladas: array que armazena as letras já descobertas
 * @return 1 se a letra foi encontrada, 0 caso contrário
 */
int verificarLetra(char letra, char palavraSecreta[], char letrasReveladas[])
{
    int acertou = 0; // Flag para indicar se a letra foi encontrada
    
    // Percorre toda a palavra secreta
    for (int i = 0; i < strlen(palavraSecreta); i++)
    {
        // Se a letra corresponde à posição atual
        if (letra == palavraSecreta[i])
        {
            letrasReveladas[i] = letra; // Revela a letra nesta posição
            acertou = 1; // Marca que acertou
        }
    }
    return acertou;
}

/**
 * Verifica se a palavra foi completamente adivinhada
 * @param palavraSecreta: palavra original
 * @param letrasReveladas: letras descobertas pelo jogador
 * @return 1 se a palavra está completa, 0 caso contrário
 */
int verificarPalavraCompleta(char palavraSecreta[], char letrasReveladas[])
{
    // Compara as duas strings - se forem iguais, palavra está completa
    if (strcmp(palavraSecreta, letrasReveladas) == 0)
        return 1;
    return 0;
}

/**
 * Marca uma letra como usada no alfabeto disponível
 * @param letra: letra a ser marcada
 * @param alfabetoDisponivel: alfabeto com as letras ainda disponíveis
 * @return 1 se a letra estava disponível, 0 se já tinha sido usada
 */
int marcarLetraUsada(char letra, char alfabetoDisponivel[])
{
    // Procura a letra no alfabeto disponível
    for (int i = 0; i < strlen(alfabetoDisponivel); i++)
    {
        // Se encontrou a letra em maiúscula (ainda não usada)
        if (letra == alfabetoDisponivel[i])
        {
            // Converte para minúscula para marcar como usada
            alfabetoDisponivel[i] = tolower(letra);
            return 1; // Letra estava disponível
        }
    }
    return 0; // Letra já tinha sido usada
}

/**
 * Remove caracteres de quebra de linha do final de uma string
 * @param str: string a ser limpa
 */
void limparQuebraDeLinha(char *str)
{
    int tamanho = strlen(str);
    
    // Se a string não está vazia e termina com \n ou \r
    if (tamanho > 0 && (str[tamanho - 1] == '\n' || str[tamanho - 1] == '\r'))
    {
        str[tamanho - 1] = '\0'; // Remove o caractere substituindo por fim de string
    }
}

/**
 * Sorteia uma palavra aleatória do arquivo palavras.txt
 * Usa o algoritmo Reservoir Sampling para selecionar de forma eficiente
 * @param palavraDestino: ponteiro para onde a palavra será armazenada
 */
void sortearPalavra(char *palavraDestino)
{
    // Tenta abrir o arquivo de palavras
    FILE *arquivo = fopen("palavras.txt", "r");

    // Se o arquivo não existe ou não pode ser aberto
    if (arquivo == NULL)
    {
        printf("Erro: Nao foi possivel abrir 'palavras.txt'.\n");
        strcpy(palavraDestino, "DESCONHECIDA"); // Usa palavra padrão
        return;
    }

    char linha[100];        // Buffer para ler cada linha
    int totalPalavras = 0;  // Contador de palavras lidas

    // Reservoir Sampling: escolhe uma palavra aleatória em uma única passada pelo arquivo
    // Isso é mais eficiente que ler o arquivo duas vezes
    while (fgets(linha, sizeof(linha), arquivo))
    {
        // Remove quebra de linha do final
        limparQuebraDeLinha(linha);

        // Ignora linhas vazias
        if (strlen(linha) == 0)
            continue;

        totalPalavras++; // Incrementa contador
        
        // Algoritmo Reservoir Sampling: cada palavra tem probabilidade 1/totalPalavras de ser escolhida
        // Isso garante distribuição uniforme sem precisar saber quantas palavras existem
        if ((rand() % totalPalavras) == 0)
        {
            strcpy(palavraDestino, linha); // Atualiza a palavra escolhida
        }
    }

    fclose(arquivo); // Fecha o arquivo
}