#include <stdio.h>

#define LINHA 10
#define COLUNA 10

int main() {
    // Inicializa o tabuleiro 10x10 com valor 0 (água)
    int batalha[LINHA][COLUNA] = {0};

    // Matrizes de habilidades (criadas com loops aninhados)
    int matrizCone[5][5] = {0};
    int matrizCruz[5][5] = {0};
    int matrizOctaedro[5][5] = {0};

    // Gerando a matriz Cone
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j <= i; j++) {
            matrizCone[i][j] = 1;
        }
    }

    // Gerando a matriz Cruz
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 || j == 2) {  // Linha e coluna central
                matrizCruz[i][j] = 1;
            }
        }
    }

    // Gerando a matriz Octaedro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 || j == 2 || (i == 1 && (j == 1 || j == 3)) || (i == 3 && (j == 1 || j == 3))) {
                matrizOctaedro[i][j] = 1;
            }
        }
    }

    // Posições de origem das habilidades no tabuleiro
    int linhaCone = 2, colunaCone = 2;
    int linhaCruz = 5, colunaCruz = 5;
    int linhaOctaedro = 7, colunaOctaedro = 7;

    // Aplica a habilidade Cone
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrizCone[i][j] == 1) {
                int linha = linhaCone + i - 2;  // Ajusta o deslocamento
                int coluna = colunaCone + j - 2;  // Ajusta o deslocamento

                // Verifica se a célula está dentro dos limites do tabuleiro
                if (linha >= 0 && linha < LINHA && coluna >= 0 && coluna < COLUNA) {
                    if (batalha[linha][coluna] != 3) {  // Não afeta os navios
                        batalha[linha][coluna] = 5;  // Marca a célula como afetada pelo cone
                    }
                }
            }
        }
    }

    // Aplica a habilidade Cruz
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrizCruz[i][j] == 1) {
                int linha = linhaCruz + i - 2;  // Ajusta o deslocamento
                int coluna = colunaCruz + j - 2;  // Ajusta o deslocamento

                // Verifica se a célula está dentro dos limites do tabuleiro
                if (linha >= 0 && linha < LINHA && coluna >= 0 && coluna < COLUNA) {
                    if (batalha[linha][coluna] != 3) {  // Não afeta os navios
                        batalha[linha][coluna] = 5;  // Marca a célula como afetada pela cruz
                    }
                }
            }
        }
    }

    // Aplica a habilidade Octaedro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrizOctaedro[i][j] == 1) {
                int linha = linhaOctaedro + i - 2;  // Ajusta o deslocamento
                int coluna = colunaOctaedro + j - 2;  // Ajusta o deslocamento

                // Verifica se a célula está dentro dos limites do tabuleiro
                if (linha >= 0 && linha < LINHA && coluna >= 0 && coluna < COLUNA) {
                    if (batalha[linha][coluna] != 3) {  // Não afeta os navios
                        batalha[linha][coluna] = 5;  // Marca a célula como afetada pelo octaedro
                    }
                }
            }
        }
    }

    // Exibe o tabuleiro
    printf("    ");
    for (int i = 0; i < COLUNA; i++) {
        printf("%c ", 'A' + i); // Imprime as letras das colunas (A-J)
    }
    printf("\n");

    for (int i = 0; i < LINHA; i++) {
        printf("%2d  ", i + 1); // Imprime as linhas numeradas de 1 a 10
        for (int j = 0; j < COLUNA; j++) {
            printf("%d ", batalha[i][j]);  // Imprime o valor da célula no tabuleiro
        }
        printf("\n");  // Nova linha após imprimir uma linha do tabuleiro
    }

    return 0;
}