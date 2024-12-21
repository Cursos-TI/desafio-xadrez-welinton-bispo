#include <stdio.h>
#define TAMANHO 8  // Define o tamanho do tabuleiro como 8x8

// Função recursiva para mover o bispo 5 casas na diagonal direita para cima
void moverBispo(int tabuleiro[TAMANHO][TAMANHO], int x, int y, int movimentos) {
    if (movimentos == 0 || x >= TAMANHO || y >= TAMANHO || x < 0 || y < 0) {
        return;  // Condição de término: para se os movimentos forem zero ou fora do tabuleiro
    }
    tabuleiro[x][y] = 1;  // Marca a posição atual do bispo no tabuleiro
    // Loops aninhados para mover o bispo na diagonal
    for (int i = 0; i < movimentos; i++) {
        for (int j = 0; j < movimentos; j++) {
            if (i == j) {
                tabuleiro[x + i][y + j] = 1;  // Marca a posição nas diagonais
            }
        }
    }
    moverBispo(tabuleiro, x + 1, y + 1, movimentos - 1);  // Chama recursivamente a função para mover o bispo
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);  // Imprime cada posição do tabuleiro
        }
        printf("\n");
    }
}

// Função recursiva para mover a torre 5 casas para a direita
void moverTorre(int tabuleiro[TAMANHO][TAMANHO], int x, int y, int movimentos) {
    if (movimentos == 0 || y >= TAMANHO) {
        return;  // Condição de término
    }
    tabuleiro[x][y] = 1;  // Marca a posição atual da torre no tabuleiro
    moverTorre(tabuleiro, x, y + 1, movimentos - 1);  // Chama recursivamente a função para mover a torre
}

// Função recursiva para mover a rainha 8 casas para a esquerda
void moverRainha(int tabuleiro[TAMANHO][TAMANHO], int x, int y, int movimentos) {
    if (movimentos == 0 || y < 0) {
        return;  // Condição de término
    }
    tabuleiro[x][y] = 1;  // Marca a posição atual da rainha no tabuleiro
    moverRainha(tabuleiro, x, y - 1, movimentos - 1);  // Chama recursivamente a função para mover a rainha
}

// Função para mover o cavalo 1 vez em L para cima à direita
void moverCavalo(int tabuleiro[TAMANHO][TAMANHO], int x, int y) {
    int movimentos[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
    // Itera sobre todas as possíveis movimentações do cavalo
    for (int i = 0; i < 8; i++) {
        int nx = x + movimentos[i][0];
        int ny = y + movimentos[i][1];
        if (nx >= 0 && ny >= 0 && nx < TAMANHO && ny < TAMANHO) {
            tabuleiro[nx][ny] = 1;  // Marca a posição para onde o cavalo se move
            break;  // Sai do loop após a primeira movimentação válida
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0};  // Inicializa o tabuleiro com zeros
    int x, y;

    // Coordenadas iniciais para cada peça
    printf("Digite a posição inicial do bispo (x y): ");
    scanf("%d %d", &x, &y);
    moverBispo(tabuleiro, x, y, 5);  // Move o bispo

    printf("Digite a posição inicial da torre (x y): ");
    scanf("%d %d", &x, &y);
    moverTorre(tabuleiro, x, y, 5);  // Move a torre

    printf("Digite a posição inicial da rainha (x y): ");
    scanf("%d %d", &x, &y);
    moverRainha(tabuleiro, x, y, 8);  // Move a rainha

    printf("Digite a posição inicial do cavalo (x y): ");
    scanf("%d %d", &x, &y);
    moverCavalo(tabuleiro, x, y);  // Move o cavalo

    printf("Movimentação das peças:\n");
    imprimirTabuleiro(tabuleiro);  // Imprime o tabuleiro final

    return 0;
}
