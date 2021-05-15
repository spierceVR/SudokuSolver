#include "main.h"

//loop through array and find first available coordinate
std::pair<int, int> findEmptySquare(const std::vector<std::vector<int>> grid) {
	int gridLen = grid.size();
	for (int y = 0; y < gridLen; y++) {
		for (int x = 0; x < gridLen; x++) {
			if (grid[y][x] == 0) {
				return std::make_pair(x, y);
			}
		}
	}
	return std::make_pair(-1, 0);
}

//is this number allowed in this position
bool isValidGuess(const std::vector<std::vector<int>> grid, const int guess, const std::pair<int,int> pos) {
	//check for duplicate number in column
	int yPos = pos.second;
	int xPos = pos.first;
	for (int y = 0; y < grid.size(); y++)
	{
		if (grid[y][xPos] == guess) {
			return false;
		}

	}
	//check for duplicate number in row
	for (int x = 0; x < grid.size(); x++)
	{
		if (grid[yPos][x] == guess) {
			return false;
		}
	}
//check for duplicate number in 3x3 square

	//determine beginning of for loop through 3x3 subgrid
	int box_col = xPos / 3; // 0, 1, or 2
	int box_row = yPos / 3;
	// determine limit of for loop through 3x3
	int box_right_edge = box_col * 3 + 2; //0, 1, or 2; * 3 + 2 gives us index 2, 5, or 8 of our row/column array
	int box_bot_edge = box_row * 3 + 2;

	for (int col = box_col*3; col <= box_right_edge; col++) {
		for (int row = box_row*3; row <= box_bot_edge; row++) {
			if (guess == grid[row][col]) {
				return false;
			}
		}
	}
	return true;
}

bool solve(std::vector<std::vector<int>> grid){
	if (findEmptySquare(grid) == std::make_pair(-1, 0)) {
		printGrid(grid);
		return true;
	}
	else {
		for(int g = 1; g < 10; g++){
			std::pair<int, int> pos = findEmptySquare(grid);
			if (isValidGuess(grid, g, pos)) {
				grid[pos.second][pos.first] = g;

				if (solve(grid)) {
					return true;
				}
				grid[pos.second][pos.first] = 0;
			}
		}
	}
}