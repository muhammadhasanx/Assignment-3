
#include <iostream>
#include <iomanip>
#include "BoardGame_Classes.hpp"

using namespace std;

void pyramid_board::display_board()
{
    for (int i : {0, 1, 2})
    {
        cout << "\n";
        switch (i)
        {
        case 0:
            cout << setw(19) << "|";
            cout << "(" << i << "," << 1 << ")";
            cout << setw(2) << board[i][1] << " |";
            cout << "\n\t\t   ----------";
            break;
        case 1:
            cout << setw(10) << "|";
            for (int j : {0, 1, 2})
            {
                cout << "(" << i << "," << j << ")";
                cout << setw(2) << board[i][j] << " |";
            }
            cout << "\n\t  ----------------------------";
            break;
        case 2:
            cout << "|(" << 0 << "," << 0 << ")";
            cout << setw(2) << board[0][0] << " |";
            for (int j : {0, 1, 2})
            {
                cout << "(" << i << "," << j << ")";
                cout << setw(2) << board[i][j] << " |";
            }
            cout << "(" << 0 << "," << 2 << ")";
            cout << setw(2) << board[0][2] << " |";
            cout << "\n ----------------------------------------------";
            break;
        default:
            break;
        }
    }
    cout << endl;
}

bool pyramid_board::is_winner()
{
    if (((board[0][1] == board[1][0] && board[1][0] == board[0][0]) ||
         (board[0][1] == board[1][1] && board[1][1] == board[2][1]) ||
         (board[0][1] == board[1][2] && board[1][2] == board[0][2])) &&
        (board[0][1] != 0))
    {
        return true;
    }
    if (((board[0][0] == board[2][0] && board[0][0] == board[2][1]) ||
         (board[2][0] == board[2][1] && board[2][1] == board[2][2]) ||
         (board[2][1] == board[2][2] && board[2][2] == board[0][2])) &&
        (board[2][1] != 0))
    {
        return true;
    }
    if ((board[1][1] == board[1][0] && board[1][0] == board[1][2]) && board[1][0] != 0)
    {
        return true;
    }
    else
        return false;
}
