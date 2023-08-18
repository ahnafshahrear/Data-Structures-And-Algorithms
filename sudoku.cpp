#include <bits/stdc++.h>

using namespace std;

bool solvable(vector<vector<char>> &board, int r, int c, char value)
{
    for (int k = 0; k < 9; k++)
    {
        if (board[r][k] == value) return false;
        else if (board[k][c] == value) return false;
    }

    int row = r - r % 3, column = c - c % 3; //... Starting index of the 3x3 sub-grid

    for (int i = row; i < row + 3; i++)
    {
        for (int j = column; j < column + 3; j++)
        {
            if (board[i][j] == value) 
            {
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(vector<vector<char>> &sudoku)
{
    int size = sudoku.size();

    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            if (sudoku[r][c] == '.')
            {
                for (char n = '1'; n <= '9'; n++)
                {
                    if (solvable(sudoku, r, c, n) == true)
                    {
                        sudoku[r][c] = n;
                        if (solveSudoku(sudoku) == true) return true;
                        sudoku[r][c] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
//... Time Complexity = O[9^(n*n)]

int main()
{
    vector<vector<char>> sudoku;

    //... This solveSudoku works for 9x9 sudoku 
    solveSudoku(sudoku);

    return 0;
}