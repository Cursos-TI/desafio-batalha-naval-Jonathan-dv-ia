#include <stdio.h>




#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída

#define TAMANHO 10 // Define o tamanho do tabuleiro como 10x10
#define NAVIO 3 // Define o tamanho dos navios como 3 posições

int main() {
    char linhas[TAMANHO] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; // Array com as letras das colunas
    int tabuleiro[TAMANHO][TAMANHO] = {0}; // Matriz 10x10 para o tabuleiro, inicializada com 0 (água)

    // Posiciona navios (exemplo simples)
    for (int i = 0; i < NAVIO; i++) { // Loop para posicionar o navio horizontalmente
        tabuleiro[2][3 + i] = 3; // Marca as posições do navio horizontalmente com 3
        tabuleiro[5 + i][1] = 3; // Marca as posições do navio verticalmente com 3
    }

    // Exibe o tabuleiro
    printf("  "); // Imprime espaços para alinhar as letras das colunas
    for (int i = 0; i < TAMANHO; i++) { // Loop para imprimir as letras das colunas
        printf("%c ", linhas[i]); // Imprime cada letra da coluna seguida de um espaço
    }
    printf("\n"); // Imprime uma nova linha

    for (int i = 0; i < TAMANHO; i++) { // Loop para percorrer as linhas do tabuleiro
        printf("%2d ", i); // Imprime o número da linha (com 2 espaços para alinhamento)
        for (int j = 0; j < TAMANHO; j++) { // Loop para percorrer as colunas do tabuleiro
            printf("%d ", tabuleiro[i][j]); // Imprime o valor da posição do tabuleiro seguido de um espaço
        }
        printf("\n"); // Imprime uma nova linha após cada linha do tabuleiro
    }

    return 0; // Indica que o programa terminou com sucesso
}