#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "BoardGame_Classes.hpp"
using namespace std;

Four_Board::Four_Board () {
   n_rows = 6;
   n_cols = 7;
   n_moves=0;
   board = new char*[n_rows];
   for (int i = 0; i < n_rows; i++) {
      board [i] = new char[n_cols];
      for (int j = 0; j < n_cols; j++)
         board[i][j] = 0;
   }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool Four_Board::update_board (int x, int y, char mark)
{
   // Only update if move is valid
   if (x >= 0 && x <= 5 && y >= 0 && y <= 6)
   {
      for(int i = 5;i >=0;i--)
      {
         if(!board[i][y])
         {
            board[i][y] = toupper(mark);
            n_moves++;
            return true;
         }
      
      }
   }
   return false;
}
// Display the board and the pieces on it
void Four_Board::display_board() {
   for (int i=0; i<n_rows; i++) {
      cout << "\n| ";
      for (int j=0; j<n_cols; j++) {
         cout << "(" << i << "," << j << ")";
         cout << setw(2) << board [i][j] << " |";
      }
      cout << "\n----------------------------------------------------------";
   }
   cout << endl;
}

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool Four_Board::is_winner(){
   for(int i=0; i<=3; i++)
   {
      for(int j=0; j<7; j++)
      {
         if((board[i][j]=='X' && board[i+1][j]== 'X' && board[i+2][j]=='X' && board[i+3][j]=='X' ))
            return true;
      }
   }


   for(int i=0; i<6; i++)
   {
      for(int j=0; j<=3; j++)
      {
         if((board[i][j]
         =='X' && board[i][j+1]== 'X' && board[i][j+2]=='X' && board[i][j+3]=='X' ))
            return true;
      }
   }



   for(int i=0; i<=2; i++)
   {
      for(int j=0; j<4; j++)
      {
         if(board[i][j] == 'X' && board[i+1][j+1] == 'X' && board[i+2][j+2]== 'X' && board[i+3][j+3]=='X')
            return true;
      }
   }

   

   for(int i=5; i>=3; i--)
   {
      for(int j=0; j<=3; j++)
      {
         if(board[i][j] == 'X' && board[i-1][j+1] == 'X' && board[i-2][j+2] == 'X' && board[i-3][j+3] == 'X')
            return true;
      }
   }

   for(int i=0; i<=3; i++)
   {
      for(int j=0; j<7; j++)
      {
         if((board[i][j]=='O' && board[i+1][j]== 'O' && board[i+2][j]=='O' && board[i+3][j]=='O' ))
            return true;
      }
   }


   for(int i=0; i<6; i++)
   {
      for(int j=0; j<=3; j++)
      {
         if((board[i][j]=='O' && board[i][j+1]== 'O' && board[i][j+2]=='O' && board[i][j+3]=='O' ))
            return true;
      }
   }


   for(int i=0; i<2; i++)
   {
      for(int j=0; j<4; j++)
      {
         if(board[i][j] == 'O' && board[i+1][j+1] == 'O' && board[i+2][j+2]== 'O' && board[i+3][j+3] == 'O')
            return true;
      }
   }


   for(int i=5; i>=3; i--)
   {
      for(int j=0; j<=3; j++)
      {
         if(board[i][j] == 'O' && board[i-1][j+1] == 'O' && board[i-2][j+2] == 'O' && board[i-3][j+3] == 'O')
            return true;
      }
   }



    return false;
}





bool Four_Board::is_draw() {
    return (n_moves == 42 && !is_winner());
}

bool Four_Board ::game_is_over () {
    return n_moves >= 42;
}