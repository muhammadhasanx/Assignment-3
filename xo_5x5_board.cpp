#include <bits/stdc++.h>
#include "BoardGame_Classes.hpp"
using namespace std;

xo_5x5_board::xo_5x5_board(){
     n_rows = n_cols = 5;
   board = new char*[n_rows];
   for (int i = 0; i < n_rows; i++) {
      board [i] = new char[n_cols];
      for (int j = 0; j < n_cols; j++)
         board[i][j] = 0;
   }
}

bool xo_5x5_board::update_board(int x, int y, char mark)
{
    if (!(x < 0 || x > 5 || y < 0 || y > 5) && (board[x][y] == 0)) {
      board[x][y] = toupper(mark);
      n_moves++;
      return true;
   }
   else
      return false;
}

void xo_5x5_board::display_board()
{
    for (int i: {0,1,2,3,4}) {
      cout << "\n| ";
      for (int j: {0,1,2,3,4}) {
         cout << "(" << i << "," << j << ")";
         cout << setw(2) << board [i][j] << " |";
      }
      cout << "\n-----------------------------";
   }
   cout << endl;
}

bool xo_5x5_board::is_winner()
{
     int O_count = 0;
     int X_count = 0;

  // Check rows
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 3; ++j) {
    int k = 0;
    int r_count=0;
      for(k;k<3;k++){
         if(board[i][j+k]=='O')
         r_count++;
      }
      if(r_count==3){
        O_count++;
      }
      else {continue;}
      

  }
  }
  // Check columns
 for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 5; ++j) {
    int k = 0;
    int c_count=0;
      for(k;k<3;k++){
         if(board[i+k][j]=='O')
         c_count++;
      }
      if(c_count==3){
        O_count++;
      }
      else {continue;}
    }
 }

 for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
    int k = 0;
    int main_diag_count=0;
      for(k;k<3;k++){
         if(board[i+k][j+k]=='O')
        main_diag_count++;
      }
      if(main_diag_count==3){
        O_count++;
      }
      else {continue;}
    }
 }
   

  for (int i = 0; i < 3; ++i) {
    for (int j = 4 ; j >=2; --j) {
    int k = 0;
    int off_diag_count=0;
      for(k;k<3;k++){
         if(board[i+k][j-k]=='O')
        off_diag_count++;
      }
      if(off_diag_count==3){
        O_count++;
      }
      else {continue;}
    }
 } 

 ////////////////////////////////////////
 // Check rows
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 3; ++j) {
    int k = 0;
    int r_count=0;
      for(k;k<3;k++){
         if(board[i][j+k]=='X')
         r_count++;
      }
      if(r_count==3){
        X_count++;
      }
      else {continue;}
      

  }
  }
  // Check columns
 for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 5; ++j) {
    int k = 0;
    int c_count=0;
      for(k;k<3;k++){
         if(board[i+k][j]=='X')
         c_count++;
      }
      if(c_count==3){
        X_count++;
      }
      else {continue;}
    }
 }

 for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
    int k = 0;
    int main_diag_count=0;
      for(k;k<3;k++){
         if(board[i+k][j+k]=='X')
        main_diag_count++;
      }
      if(main_diag_count==3){
        X_count++;
      }
      else {continue;}
    }
 }
   

  for (int i = 0; i < 3; ++i) {
    for (int j = 4 ; j >=2; --j) {
    int k = 0;
    int off_diag_count=0;
      for(k;k<3;k++){
         if(board[i+k][j-k]=='X')
        off_diag_count++;
      }
      if(off_diag_count==3){
        X_count++;
      }
      else {continue;}
    }
 } 
 // Check if 'O' or 'X' has won
    if ((O_count > X_count)&& n_moves==24) {
        cout << "O wins!\n";
        return true;
    } else if ((X_count > O_count)&& n_moves==24) {
        cout << "X wins!\n";
        return true;
    }

    return false;

}

bool xo_5x5_board::is_draw()
{
      return (n_moves == 24 && !is_winner());
}

bool xo_5x5_board::game_is_over()
{
    return n_moves >= 24;
}
