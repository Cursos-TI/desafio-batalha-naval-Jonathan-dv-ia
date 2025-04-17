#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3
#define HABILIDADE_TAMANHO 5 // Tamanho das matrizes de habilidade

// Função para criar a matriz de habilidade em cone
void criarCone(int habilidade[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO]) {
    int centro = HABILIDADE_TAMANHO / 2;
    for (int i = 0; i < HABILIDADE_TAMANHO; i++) {
        for (int j = 0; j < HABILIDADE_TAMANHO; j++) {
            if (i >= centro && j >= centro - i + centro && j <= centro + i - centro) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Função para criar a matriz de habilidade em cruz
void criarCruz(int habilidade[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO]) {
    int centro = HABILIDADE_TAMANHO / 2;
    for (int i = 0; i < HABILIDADE_TAMANHO; i++) {
        for (int j = 0; j < HABILIDADE_TAMANHO; j++) {
            if (i == centro || j == centro) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Função para criar a matriz de habilidade em octaedro (losango) SEM usar abs
void criarOctaedroSemAbs(int habilidade[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO]) {
    int centro = HABILIDADE_TAMANHO / 2;
    for (int i = 0; i < HABILIDADE_TAMANHO; i++) {
        for (int j = 0; j < HABILIDADE_TAMANHO; j++) {
            int distanciaLinha = (i > centro) ? (i - centro) : (centro - i);
            int distanciaColuna = (j > centro) ? (j - centro) : (centro - j);
            if (distanciaLinha + distanciaColuna <= centro) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

int main() {
    char linhas[TAMANHO] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[TAMANHO][TAMANHO] = {0};

    // Posiciona navios (mantendo o exemplo)
    

    // Cria as matrizes de habilidade
    int cone[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO] = {0};
    int cruz[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO] = {0};
    int octaedro[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO] = {0};

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedroSemAbs(octaedro); // Usando a função sem abs

    // Define os pontos de origem das habilidades no tabuleiro
    int origemConeLinha = 1;
    int origemConeColuna = 4;
    int origemCruzLinha = 6;
    int origemCruzColuna = 5;
    int origemOctaedroLinha = 8;
    int origemOctaedroColuna = 2;

    // Aplica a habilidade de cone ao tabuleiro
    int centroHabilidade = HABILIDADE_TAMANHO / 2;
    for (int i = 0; i < HABILIDADE_TAMANHO; i++) {
        for (int j = 0; j < HABILIDADE_TAMANHO; j++) {
            int tabuleiroLinha = origemConeLinha + i - centroHabilidade;
            int tabuleiroColuna = origemConeColuna + j - centroHabilidade;
            if (tabuleiroLinha >= 0 && tabuleiroLinha < TAMANHO && tabuleiroColuna >= 0 && tabuleiroColuna < TAMANHO && cone[i][j] == 1) {
                if (tabuleiro[tabuleiroLinha][tabuleiroColuna] != 3) { // Não sobrescreve navios
                    tabuleiro[tabuleiroLinha][tabuleiroColuna] = 5;
                }
            }
        }
    }

    // Aplica a habilidade de cruz ao tabuleiro
    for (int i = 0; i < HABILIDADE_TAMANHO; i++) {
        for (int j = 0; j < HABILIDADE_TAMANHO; j++) {
            int tabuleiroLinha = origemCruzLinha + i - centroHabilidade;
            int tabuleiroColuna = origemCruzColuna + j - centroHabilidade;
            if (tabuleiroLinha >= 0 && tabuleiroLinha < TAMANHO && tabuleiroColuna >= 0 && tabuleiroColuna < TAMANHO && cruz[i][j] == 1) {
                if (tabuleiro[tabuleiroLinha][tabuleiroColuna] != 3) {
                    tabuleiro[tabuleiroLinha][tabuleiroColuna] = 5;
                }
            }
        }
    }

    // Aplica a habilidade de octaedro ao tabuleiro
    for (int i = 0; i < HABILIDADE_TAMANHO; i++) {
        for (int j = 0; j < HABILIDADE_TAMANHO; j++) {
            int tabuleiroLinha = origemOctaedroLinha + i - centroHabilidade;
            int tabuleiroColuna = origemOctaedroColuna + j - centroHabilidade;
            if (tabuleiroLinha >= 0 && tabuleiroLinha < TAMANHO && tabuleiroColuna >= 0 && tabuleiroColuna < TAMANHO && octaedro[i][j] == 1) {
                if (tabuleiro[tabuleiroLinha][tabuleiroColuna] != 3) {
                    tabuleiro[tabuleiroLinha][tabuleiroColuna] = 5;
                }
            }
        }
    }

    // Exibe o tabuleiro com as habilidades
    printf("  ");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%c ", linhas[i]);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
