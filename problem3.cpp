/* In the game Minesweeper cells with mines are marked with the symbol "*" 
and each empty cell is marked with a number from 0 to 8 corresponding to 
the number of mines in the adjacent 8 cells to the current one. 
The program receives a list of mines on the field as input.
Build an image of the field. */

#include <iostream>

void printMines(char* mines) {
int n, m, k;
    int counter = 0;
    std::cin >> n >> m >> k;

    int** array = new int*[n];
    for (int i = 0; i < n; i++) {
        array[i] = new int[m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            array[i][j] = '0';

        }
    }

    while (counter < k) {
        int x, y;
        std::cin >> x >> y;
        array[x - 1][y - 1] = '*';
        counter++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (array[i][j] == '*') {
                if ((i - 1 >= 0) && (array[i - 1][j] != '*')) {
                    array[i - 1][j] += 1;
                }
                if ((i + 1 < n) && (array[i + 1][j] != '*')) {
                    array[i + 1][j] += 1;
                }
                if ((j - 1 >= 0) && (array[i][j - 1] != '*')) {
                    array[i][j - 1] += 1;
                }
                if ((j + 1 < m) && (array[i][j + 1] != '*')) {
                    array[i][j + 1] += 1;
                }
                
                if ((i - 1 >= 0) && (j - 1 >= 0) && (array[i - 1][j - 1] != '*')) {
                    array[i - 1][j - 1] += 1;
                }
                if ((i + 1 < n) && (j + 1 < m) && (array[i + 1][j + 1] != '*')) {
                    array[i + 1][j + 1] += 1;
                }
                if ((i - 1 >= 0) && (j + 1 < m) && (array[i - 1][j + 1] != '*')) {
                    array[i - 1][j + 1] += 1;
                }
                if ((i + 1 < n) && (j - 1 >= 0) && (array[i + 1][j - 1] != '*')) {
                    array[i + 1][j - 1] += 1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << (char) array[i][j] << ' '; 
        }
            std::cout << '\n'; 
    }
}

int main() {
    

}