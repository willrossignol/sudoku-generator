#include <iostream>
#include <chrono>
#include <random>
#include "generator.hpp"
#include "board.hpp"

int main()
{
    // Create vector of numbers
    std::vector<int> numbers = std::vector<int>();
    for (int i = 0; i < 9; i++)
    {
        numbers.emplace_back(i + 1);
    }

    // Create seed for random num generator
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distributionInteger(0, 10000);
    int random = distributionInteger(generator);

    // Transform random number into index for numbers vector
    int index = random % numbers.size();
    if (index >= numbers.size())
    {
        std::cout << "An error occurred" << std::endl;
        return EXIT_FAILURE;
    }

    // Create board object
    auto sudokuBoard = board();

    // Fill board with numbers to test layout
    int count = 0;
    for (int i = 0; i < sudokuBoard.squares.size(); i++)
    {
        for (int j = 0; j < sudokuBoard.squares[i].numbers.size(); j++)
        {
            for (int k = 0; k < sudokuBoard.squares[i].numbers[j].size(); k++)
            {
                sudokuBoard.squares[i].numbers[j][k] = count;
                count++;
            }
        }
    }

    // Print board in terminal
    sudokuBoard.print();

    return EXIT_SUCCESS;
}