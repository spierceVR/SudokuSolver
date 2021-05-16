#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

//io.cpp
std::vector<std::vector<int>> getGrid(std::string name);

void printGrid(std::vector<std::vector<int>> aGrid);



//solving.cpp
bool isValidGuess(std::vector<std::vector<int>> grid, int guess, std::pair<int, int> pos);

std::pair<int, int> findEmptySquare(std::vector<std::vector<int>> grid);

bool solve(std::vector<std::vector<int>> &grid);

