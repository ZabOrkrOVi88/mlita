/*1.8. Шашки 2 (7)
На шахматном поле расположены N черных шашек и одна белая дамка. 
Требуется написать программу, которая по заданному расположению шашек определяет, какое максимальное количество шашек может взять белая дамка за один ход. 
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

const char EMPTY = '0';
const char BLACK = '1';
const char WHITE = '2';
const char BEATEN = 'X';
const int DR[] = { -1, -1, 1, 1 };
const int DC[] = { -1, 1, -1, 1 };

int max_k = 0;
std::vector<std::pair<int, int>> best_path;
std::vector<std::string> board(8);

void Glub(int row, int columnn, std::vector<std::pair<int, int>>& path, bool rule_flag)
{
    bool land_flag = false;

    for (int i = 0; i < 4; ++i)
    {
        int try_row = row + DR[i];
        int try_column = columnn + DC[i];
        int found_row = -1;
        int found_column = -1;
        bool found_flag = false;

        while (try_row >= 0 && try_row < 8 && try_column >= 0 && try_column < 8)
        {
            if (board[try_row][try_column] == BLACK)
            {
                found_flag = true;
                found_row = try_row;
                found_column = try_column;
                break;
            }
            else if (board[try_row][try_column] != EMPTY) { break; }

            try_row += DR[i];
            try_column += DC[i];
        }

        if (found_flag)
        {
            try_row += DR[i];
            try_column += DC[i];

            while (try_row >= 0 && try_row < 8 && try_column >= 0 && try_column < 8)
            {
                if (board[try_row][try_column] == EMPTY)
                {
                    land_flag = true;
                    if (rule_flag)
                    {
                        board[found_row][found_column] = BEATEN;
                    }
                    else
                    {
                        board[found_row][found_column] = EMPTY;
                    }
                    path.push_back({ try_row + 1, try_column + 1 });

                    Glub(try_row, try_column, path, rule_flag);

                    path.pop_back();
                    board[found_row][found_column] = BLACK;
                }
                else { break; }

                try_row += DR[i];
                try_column += DC[i];
            }
        }
    }
    if (!land_flag)
    {
        int k = (path.size() - 1);
        if (k > max_k)
        {
            max_k = k;
            best_path = path;
        }
    }
}

int main()
{
    std::ifstream in("INPUT.TXT");
    std::ofstream out("OUTPUT.TXT");

    if (!in.is_open()) { return 0; }

    std::vector<std::pair<int, int>> path;
    int start_row = -1;
    int start_column = -1;
    
    for (int i = 0; i < 8; ++i)
    {
        in >> board[i];
        for (int j = 0; j < 8; ++j)
        {
            if (board[i][j] == WHITE) 
            {
                board[i][j] = EMPTY;
                start_row = i;
                start_column = j;
                path.push_back({ i + 1, j + 1});
                best_path = path;
            }
        }
    }

    Glub(start_row, start_column, path, true);

    out << max_k << "\n";
    for (int i = 0; i < best_path.size(); i++)
    {
        out << best_path[i].first << " " << best_path[i].second << "\n";
    }

    max_k = 0;
    path.clear();
    path.push_back({ start_row + 1, start_column + 1 });
    best_path.clear();
    best_path = path;

    Glub(start_row, start_column, path, false);

    out  << "\n" << max_k << "\n";
    for (int i = 0; i < best_path.size(); i++)
    {
        out << best_path[i].first << " " << best_path[i].second << "\n";
    }
    return 0;
}
