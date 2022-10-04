#pragma once

#include <vector>

class square
{
public:
    explicit square();

    void printRow(int n);
    bool checkInCol(int n, int x);
    bool checkInRow(int n, int x);
    std::vector<std::vector<int>> numbers;

private:
};
class board
{
public:
    explicit board();
    void print();

    std::vector<square> squares;
};