#include <iostream>
#include "fiveXfive_manager.cpp"
#include "Four_Board.cpp"
#include "GameManager.cpp"
#include "Player.cpp"
#include "pyramid_board.cpp"
#include "RandomPlayer.cpp"
#include "X_O_Board.cpp"
#include "xo_5x5_board.cpp"
using namespace std;

int main()
{
     int choice;
        Player *players[2];
        players[0] = new Player(1, 'x');
 
    int n;
    cout << "welcom to x_o games: \n";
    cout << "enter the number of the game you want to play: \n";
    cout << "1-for normal X O game: \n";
    cout << "2-for pyramid X-O game: \n";
    cout << "3-for four in row game: \n";
    cout << "4-for 5x5 tic tac toe game: \n";
    cin>>n;

    switch (n)
    {
    case 1:
     {  

        cout << "Welcome to FCAI X-O Game. :)\n";
        cout << "Press 1 if you want to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player(2, 'o');
        else
            // Player pointer points to child
            players[1] = new RandomPlayer('o', 3);

        GameManager x_o_game(new X_O_Board(), players);
        x_o_game.run();
        system("pause");
        break;
     }
    case 2:
     {  

        cout << "Welcome to FCAI X-O Game. :)\n";
        cout << "Press 1 if you want to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player(2, 'o');
        else
            // Player pointer points to child
            players[1] = new RandomPlayer('o', 3);

        GameManager pyramid_X_O(new pyramid_board(), players);
        pyramid_X_O.run();
        system("pause");
        break;
     }
    case 3:
      { 

        cout << "Welcome to FCAI X-O Game. :)\n";
        cout << "Press 1 if you want to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player(2, 'o');
        else
            // Player pointer points to child
            players[1] = new RandomPlayer('o', 3);

        GameManager four_in_row(new Four_Board(), players);
        four_in_row.run();
        system("pause");
        break;
      }
    case 4:
       {

        cout << "Welcome to FCAI X-O Game. :)\n";
        cout << "Press 1 if you want to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player(2, 'o');
        else
            // Player pointer points to child
            players[1] = new RandomPlayer('o', 5);

        fiveXfive_manager XO_5x5(new xo_5x5_board, players);
        XO_5x5.run();
        system("pause");
        break;
       }
    default:
        cout << "invlid";
        break;
    }

    return 0;
}