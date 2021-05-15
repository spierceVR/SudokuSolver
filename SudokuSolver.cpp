// SudokuSolver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "main.h"

int main()
{
    std::vector<std::vector<int>> myGrid = getGrid("puzzle.txt");

    printGrid(myGrid);
    std::pair<int, int> coord = findEmptySquare(myGrid);
    std::cout << "x:"<< coord.first << " y:" << coord.second << "\n";

    solve(myGrid);
/*solve:
    int guessNum = 1;
    std::pair<int, int> pos;
    while (findEmptySquare(myGrid).first != -1){
        pos = findEmptySquare(myGrid);
        if (isValidGuess(myGrid, guessNum, pos)) {
            myGrid[pos.second][pos.first] = guessNum;
            std::cout << "Guessing " << guessNum << " in (" << pos.first << "," << pos.second << ")\n";
            guessNum = 1;
            std::cout << "reset guessNum to 1\n\n";
        }
        else if (guessNum < 9) {
            std::cout << "Incrementing guessNum "<< guessNum << " because it was invalid\n";
            guessNum++;
        }
        else {
            std::cout << "All guesses failed in (" << pos.first << "," << pos.second << ")\n";
            break;
        }
        printGrid(myGrid);
        std::cout << "\n\n\n";
    }
    */

}