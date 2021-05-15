#include "main.h"


std::vector<std::vector<int>> getGrid(std::string path) {

    std::vector<std::vector<int>> grid;
    std::ifstream input(path);
    std::string line;

    if (input.is_open()) {
        while (getline(input, line))
        {
            std::vector<int> gridLine;
            char c;
            std::istringstream stream(line);
            while (stream >> c)
            {
                gridLine.push_back(c - '0');
            }
            grid.push_back(gridLine);
        }
        input.close();
    }
    else {
        std::cout << "file is not open" << "\n";
    }
    return grid;
}

void printGrid(std::vector<std::vector<int>> aGrid) {
    for (int row = 0; row <= 8; row++) {
        for (int col = 0; col <= 8; col++) {
            std::cout << " " << aGrid[row][col] << " ";
            if ((col + 1) % 3 == 0 && col != 0) std::cout << "|";
        }
        std::cout << "\n";
        if ((row + 1) % 3 == 0 && row != 0) std::cout << "- - - - - - - - - - - - - -\n";
    }
}