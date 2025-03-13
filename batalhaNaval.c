#include <stdio.h>

#define TAMANHO 10
#define TAM_NAVIO 3

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para posicionar navios de forma segura (horizontal, vertical, diagonal)
void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (direcao == 0) tabuleiro[linha][coluna + i] = 3;        // Horizontal
        else if (direcao == 1) tabuleiro[linha + i][coluna] = 3;   // Vertical
        else if (direcao == 2) tabuleiro[linha + i][coluna + i] = 3; // Diagonal Principal
        else if (direcao == 3) tabuleiro[linha + i][coluna - i] = 3; // Diagonal Secundária
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para aplicar habilidades especiais no tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tipo) {
    if (tipo == 0) { // Cone
        if (linha + 2 < TAMANHO) {
            tabuleiro[linha + 2][coluna] = 1;
            if (coluna > 0) tabuleiro[linha + 1][coluna - 1] = 1;
            tabuleiro[linha + 1][coluna] = 1;
            if (coluna + 1 < TAMANHO) tabuleiro[linha + 1][coluna + 1] = 1;
        }
    } 
    else if (tipo == 1) { // Octaedro
        if (linha > 0) tabuleiro[linha - 1][coluna] = 1;
        if (linha + 1 < TAMANHO) tabuleiro[linha + 1][coluna] = 1;
        if (coluna > 0) tabuleiro[linha][coluna - 1] = 1;
        if (coluna + 1 < TAMANHO) tabuleiro[linha][coluna + 1] = 1;
    } 
    else if (tipo == 2) { // Cruz
        for (int i = -2; i <= 2; i++) {
            if (linha + i >= 0 && linha + i < TAMANHO) tabuleiro[linha + i][coluna] = 1;
            if (coluna + i >= 0 && coluna + i < TAMANHO) tabuleiro[linha][coluna + i] = 1;
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];

    // Inicializa o tabuleiro com água (0)
    inicializarTabuleiro(tabuleiro);

    // Posiciona os navios (horizontal, vertical, diagonal)
    posicionarNavio(tabuleiro, 2, 3, 0); // Horizontal
    posicionarNavio(tabuleiro, 5, 7, 1); // Vertical
    posicionarNavio(tabuleiro, 1, 1, 2); // Diagonal principal
    posicionarNavio(tabuleiro, 6, 8, 3); // Diagonal secundária

    // Aplica habilidades especiais
    aplicarHabilidade(tabuleiro, 4, 4, 0); // Cone
    aplicarHabilidade(tabuleiro, 7, 7, 1); // Octaedro
    aplicarHabilidade(tabuleiro, 3, 3, 2); // Cruz

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
