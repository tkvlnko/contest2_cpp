/* In the game Minesweeper cells with mines are marked with the symbol "*" 
and each empty cell is marked with a number from 0 to 8 corresponding to 
the number of mines in the adjacent 8 cells to the current one. 
The program receives a list of mines on the field as input.
Build an image of the field. */

#include <iostream>


// void updateIndeces(int array[n][m]) {

// }

int main() {
    int n, m, k;
    int counter = 0;
    std::cin >> n >> m >> k;

    int** array = new int*[n];
    for (int i = 0; i < n; i++) {
        array[i] = new int[m];
    }

    // for (int i = 0; i < k; i++)

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
            std::cout << (char) array[i][j] << ' '; 
        }
            std::cout << '\n'; 
    }

}