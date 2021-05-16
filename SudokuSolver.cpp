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
    printGrid(myGrid);
}