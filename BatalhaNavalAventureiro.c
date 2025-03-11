#include <stdio.h>

int main () {

    // Inicializa o tabuleiro 10x10 com valor 0 (água)
    int batalha[10][10] = {0}; 

    // Definir as coordenadas de início e o tamanho dos navios
    int linhaH1 = 3, colunaH1 = 4; // Primeiro navio horizontal - Linha 3, Coluna 4
    int linhaH2 = 6, colunaH2 = 1; // Segundo navio horizontal - Linha 6, Coluna 1
    int linhaV1 = 5, colunaV1 = 5; // Primeiro navio vertical - Linha 5, Coluna 5
    int linhaV2 = 1, colunaV2 = 8; // Segundo navio vertical - Linha 1, Coluna 8
    int linhaD1 = 0, colunaD1 = 0; // Primeiro navio diagonal - Linha 0, Coluna 0
    int linhaD2 = 7, colunaD2 = 2; // Segundo navio diagonal - Linha 7, Coluna 2
    int NavioTamanho = 3;

    // Posiciona o primeiro navio horizontal no tabuleiro
    if (colunaH1 + NavioTamanho <= 10) {
        for (int i = 0; i < NavioTamanho; i++) {
            batalha[linhaH1][colunaH1 + i] = 3; // Coloca o navio (representado por 3)
        }
    } else {
        printf("***ERROR***: Não cabe o navio horizontal 1.\n");
    }

    // Posiciona o segundo navio horizontal no tabuleiro
    if (colunaH2 + NavioTamanho <= 10) {
        for (int i = 0; i < NavioTamanho; i++) {
            batalha[linhaH2][colunaH2 + i] = 3; // Coloca o navio (representado por 3)
        }
    } else {
        printf("***ERROR***: Não cabe o navio horizontal 2.\n");
    }

    // Posiciona o primeiro navio vertical no tabuleiro
    if (linhaV1 + NavioTamanho <= 10) {
        for (int i = 0; i < NavioTamanho; i++) {
            batalha[linhaV1 + i][colunaV1] = 3; // Coloca o navio (representado por 3)
        }
    } else {
        printf("***ERROR***: Não cabe o navio vertical 1.\n");
    }

    // Posiciona o segundo navio vertical no tabuleiro
    if (linhaV2 + NavioTamanho <= 10) {
        for (int i = 0; i < NavioTamanho; i++) {
            batalha[linhaV2 + i][colunaV2] = 3; // Coloca o navio (representado por 3)
        }
    } else {
        printf("***ERROR***: Não cabe o navio vertical 2.\n");
    }

    // Posiciona o primeiro navio diagonal (da esquerda para a direita)
    if (linhaD1 + NavioTamanho <= 10 && colunaD1 + NavioTamanho <= 10) {
        for (int i = 0; i < NavioTamanho; i++) {
            batalha[linhaD1 + i][colunaD1 + i] = 3; // Coloca o navio (representado por 3)
        }
    } else {
        printf("***ERROR***: Não cabe o navio diagonal 1.\n");
    }

    // Posiciona o segundo navio diagonal (da direita para a esquerda)
    if (linhaD2 + NavioTamanho <= 10 && colunaD2 - NavioTamanho + 1 >= 0) {
        for (int i = 0; i < NavioTamanho; i++) {
            batalha[linhaD2 + i][colunaD2 - i] = 3; // Coloca o navio (representado por 3)
        }
    } else {
        printf("***ERROR***: Não cabe o navio diagonal 2.\n");
    }

    // Exibe o tabuleiro
    printf("Tabuleiro:\n");
    printf("\n");

    // Imprime as letras das colunas
    printf("    ");
    for (int i = 0; i < 10; i++) {
        printf("%c ", 'A' + i); // Imprime as letras das colunas (A-J)
    }
    printf("\n");
    printf("\n");

    // Imprime as linhas numeradas e os valores do tabuleiro
    for (int i = 0; i < 10; i++) {
        printf("%2d  ", i + 1); // Imprime as linhas numeradas de 1 a 10
        for (int j = 0; j < 10; j++) {
            printf("%d ", batalha[i][j]); // Exibe o valor da posição (0 ou 3)
        }
        printf("\n"); // Nova linha após imprimir uma linha do tabuleiro
    }

    return 0; // Fim do programa
}