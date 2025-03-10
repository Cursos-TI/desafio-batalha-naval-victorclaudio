#include <stdio.h>

int main () {


 
    int batalha [10][10]= {0}; //tabuleiro com agua

    // Definir as coordenadas de início e o tamanho dos navios
    int linhaH = 3, colunaH = 4; // Navio horizontal - Linha 3, Coluna 4
    int linhaV = 5, colunaV = 5; // Navio vertical - Linha 5, Coluna 5
    int NavioTamanho = 3;

    // Posiciona o navio horizontal no tabuleiro
   if (colunaH + NavioTamanho <= 10) {
        for(int i = 0; i < NavioTamanho; i++) {
            batalha[linhaH][colunaH + i] = 3; // Coloca o navio (representado por 3)
    }
   } else {
    printf( " ***ERROR*** \n");
   }

  
   // Posiciona o navio vertical no tabuleiro
   if (linhaV + NavioTamanho <= 10) {
        for(int i = 0; i < NavioTamanho; i++) {
            batalha[linhaV + i][colunaV] = 3; // Coloca o navio (representado por 3)
        }
   } else {
    printf( " ***ERROR*** \n");
   }
   
    // Exibe o tabuleiro
    printf("Tabuleiro:\n");
    printf("\n");


    printf("    "); // Adiciona um espaço de indentação para alinhar as colunas
    for (int i = 0; i < 10; i++) {
        printf("%c ", 'A' + i); // Imprime as letras das colunas (A-J)
    }
    printf("\n");
    printf("\n");
    
    
    for (int i = 0; i < 10; i++) {
        printf("%2d  ", i + 1); // Imprime as linhas numeradas de 1 a 10
        for (int j = 0; j < 10; j++) {
            printf("%d ", batalha[i][j]); // Exibe o valor da posição (0 ou 3)
        }
        printf("\n"); // Nova linha após imprimir uma linha do tabuleiro
    }

    return 0; // Fim do programa
}