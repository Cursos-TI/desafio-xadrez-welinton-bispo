#include <stdio.h>
#define TAMANHO 8

void moverBispo(int tabuleiro[TAMANHO][TAMANHO], int x, int y, int movimentos) {
    if (movimentos == 0 || x >= TAMANHO || y >= TAMANHO || x < 0 || y < 0) {
        return;
    }
    tabuleiro[x][y] = 1;
    for (int i = 0; i < movimentos; i++) {
        for (int j = 0; j < movimentos; j++) {
            if (i == j) {
                tabuleiro[x + i][y + j] = 1;
            }
        }
    }
    moverBispo(tabuleiro, x + 1, y + 1, movimentos - 1);
}

void imprimirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void moverTorre(int tabuleiro[TAMANHO][TAMANHO], int x, int y, int movimentos) {
    if (movimentos == 0 || y >= TAMANHO) {
        return;
    }
    tabuleiro[x][y] = 1;
    moverTorre(tabuleiro, x, y + 1, movimentos - 1);
}

void moverRainha(int tabuleiro[TAMANHO][TAMANHO], int x, int y, int movimentos) {
    if (movimentos == 0 || y < 0) {
        return;
    }
    tabuleiro[x][y] = 1;
    moverRainha(tabuleiro, x, y - 1, movimentos - 1);
}

void moverCavalo(int tabuleiro[TAMANHO][TAMANHO], int x, int y) {
    int movimentos[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
    for (int i = 0; i < 8; i++) {
        int nx = x + movimentos[i][0];
        int ny = y + movimentos[i][1];
        if (nx >= 0 && ny >= 0 && nx < TAMANHO && ny < TAMANHO) {
            tabuleiro[nx][ny] = 1;
            break;
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0};
    int x, y;

    // Coordenadas iniciais para cada peça
    printf("Digite a posição inicial do bispo (x y): ");
    scanf("%d %d", &x, &y);
    moverBispo(tabuleiro, x, y, 5);

    printf("Digite a posição inicial da torre (x y): ");
    scanf("%d %d", &x, &y);
    moverTorre(tabuleiro, x, y, 5);

    printf("Digite a posição inicial da rainha (x y): ");
    scanf("%d %d", &x, &y);
    moverRainha(tabuleiro, x, y, 8);

    printf("Digite a posição inicial do cavalo (x y): ");
    scanf("%d %d", &x, &y);
    moverCavalo(tabuleiro, x, y);

    printf("Movimentação das peças:\n");
    imprimirTabuleiro(tabuleiro);

    return 0;
}
