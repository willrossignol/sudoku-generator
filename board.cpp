#include "board.hpp"

#include <iostream>

/**
 * @brief This is a 3x3 square that contains 9 integers
 */
square::square()
{
    numbers = std::vector<std::vector<int>>(3);
    numbers.resize(3);
    for (auto &row : numbers)
    {
        row.resize(3);
    }
}

/**
 * @brief Check if a number is in the nTh coloumn of the square
 *
 * @param n The number of the column where to check for the number
 * @param x The number we are checking fore
 *
 * @return True if x is in nTh column, false if it is not
 */
bool square::checkInCol(int n, int x)
{
    if (numbers[0][n] == x)
        return true;
    if (numbers[1][n] == x)
        return true;
    if (numbers[2][n] == x)
        return true;

    return false;
}

/**
 * @brief Check if a number is in the nTh row of the square
 *
 * @param n The number of the row where to check for the number
 * @param x The number we are checking fore
 *
 * @return True if x is in nTh row, false if it is not
 */
bool square::checkInRow(int n, int x)
{
    if (numbers[n][0] == x)
        return true;
    if (numbers[n][1] == x)
        return true;
    if (numbers[n][2] == x)
        return true;

    return false;
}

/**
 * @brief Prints the nTh row of the square
 */
void square::printRow(int n)
{
    std::cout << "|\t" << numbers[n][0] << "\t" << numbers[n][1] << "\t" << numbers[n][2] << "\t";
}

/**
 * @brief Represents a Sudoku board wich contains 9 3x3 squares
 */
board::board()
{
    squares = std::vector<square>(9);
}

/**
 * @brief Prints the whole sudoku board with all 9 squares, formatted clearly
 */
void board::print()
{
    std::cout << "-------------------------------------------------------------------------------------------------" << std::endl;
    for (int k = 0; k < 3; k++)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                squares[j + (k * 3)].printRow(i);
            }
            std::cout << "|" << std::endl;
        }
        std::cout << "-------------------------------------------------------------------------------------------------" << std::endl;
    }
}