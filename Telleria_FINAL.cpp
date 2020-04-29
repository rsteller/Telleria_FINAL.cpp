/* Connect Four 
   Final Term Project
   Raisa Telleria
   04/23/2020
*/

#include <iostream>
using namespace std;

// label the board, give name, label players, label empty spots
 
const int ROWS = 6, COLS= 7;
 
const string PROG_NAME = "Connect Four!";
 
// Blue marker = B  and Red marker = R 
const char BLUE = 'B', RED = 'R', EMPTY= '*';
 
void gameBoard (char board [][COLS], int numRows);
void playersTurn (char board[][COLS], char player, int numRows);
bool showTheWinner (char board[][COLS], char player, int numRows);
bool BoardFull (char board[][COLS], int numRows);

int main()
{
    cout << "Welcome to " << PROG_NAME << endl;
// show the layout of the game
    char BOARD[ROWS][COLS]=
    {
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    };
// determine the winner for the game
    char thePlayer = RED;
    gameBoard (BOARD, ROWS);
    do
    {
        playersTurn (BOARD, thePlayer, ROWS);
        gameBoard(BOARD, ROWS);
 
        if (showTheWinner (BOARD, thePlayer, ROWS))
        {
            cout << "Congrats Player " << thePlayer << endl;
            break;
        }
        if (thePlayer == BLUE)
        {
            thePlayer = RED;
        } else {
            thePlayer = BLUE;
        }
    } while (! BoardFull (BOARD, ROWS));
 
    cout << "Thank you for using " << PROG_NAME << endl;
    return 0;
}
 
    void gameBoard(char board[][COLS], int numRows)
    {
        for ( int TheRows =0; TheRows < numRows; TheRows++)
        {
            for (int TheCols =0; TheCols < COLS; TheCols++)
            {
                cout << board[TheRows][TheCols];
            }
            cout << endl;
        }
    }
// make the player choose a slot 
    void playersTurn (char board[][COLS], char player, int numRows)
    {
        int Slot1, Slot2;
 
        cout << "Enter a row:";
        cin >> Slot1;
        cout << "Enter a column:";
        cin >> Slot2;
        board[Slot1-1][Slot2-1]=player;
    }
 
// the winner is determined by someone getting four in a row first whether 
// horizontal, vertical, or diagonal
bool showTheWinner(char board[][COLS], char player, int numRows)
{
    int column, row;
    for (column=0; column < COLS; column++)

// Show all possible wins for four in a row across and vertical
    {
        if (board[0][column==player] && board[1][column]==player && board[2][column]==player && board[3][column]==player)
        {
            cout << "Player has won by filling column #" << column + 1 << "! " << endl;
            return true;
        }
    }
    for (column=0; column < COLS; column++)
    {
        if (board[1][column==player] && board[2][column]==player && board[3][column]==player && board[4][column]==player)
        {
            cout << "Player has won by filling column #" << column + 1 << "! " << endl;
            return true;
        }
    }
    for (column=0; column < COLS; column++)
    {
        if (board[2][column==player] && board[3][column]==player && board[4][column]==player && board[5][column]==player)
        {
            cout << "Player has won by filling column #" << column + 1 << "! " << endl;
            return true;
        }
    }
    for (column=0; column < COLS; column++)
    {
        if (board[3][column==player] && board[4][column]==player && board[5][column]==player && board[6][column]==player)
        {
            cout << "Player has won by filling column #" << column + 1 << "! " << endl;
            return true;
        }
    }

    for (row = 0; row < numRows; row++)
    {
        if (board[row][0]== player && board[row][1]== player && board [row][2]==player && board[row][3]==player)
        {
            cout << "Player has won by filling row #" << row + 1 << "! " << endl;
            return true;
        }
    }
    for (row = 0; row < numRows; row++)
    {
        if (board[row][1]== player && board[row][2]== player && board [row][3]==player && board[row][4]==player)
        {
            cout << "Player has won by filling row #" << row + 1 << "! " << endl;
            return true;
        }
    }
    for (row = 0; row < numRows; row++)
    {
        if (board[row][2]== player && board[row][3]== player && board [row][4]==player && board[row][5]==player)
        {
            cout << "Player has won by filling row #" << row + 1 << "! " << endl;
            return true;
        }
    }

    bool diagWin = true;
    for (int spot=0; spot < COLS; spot++)
    {
        if (board[spot][spot]==player)
        diagWin=true;
        else 
        {
            diagWin=false;
            break;
        }
    }

// put all possible outcomes of diagonal winning left to right and right to left
    if (diagWin)
    {
        cout << "Congrats!" << endl;
        return true;
    }
    if (board [0][3]==player && board [1][2]==player && board [2][1]==player && board[3][0]== player)
    {
        cout << "Player has won by filling the diagonal way" << endl;
        return true;
    }
    if (board [0][4]==player && board [1][3]==player && board [2][2]==player && board[3][1]== player)
    {
        cout << "Player has won by filling the diagonal way" << endl;
        return true;
    }
    if (board [0][5]==player && board [1][4]==player && board [2][3]==player && board[3][2]== player)
    {
        cout << "Player has won by filling the diagonal way" << endl;
        return true;
    }
    if (board [1][5]==player && board [2][4]==player && board [3][3]==player && board[4][2]== player)
    {
        cout << "Player has won by filling the diagonal way" << endl;
        return true;
    }
    if (board [2][5]==player && board [3][4]==player && board [4][3]==player && board[5][2]== player)
    {
        cout << "Player has won by filling the diagonal way" << endl;
        return true;
    }
    if (board [3][5]==player && board [4][4]==player && board [5][3]==player && board[6][2]== player)
    {
        cout << "Player has won by filling the diagonal way" << endl;
        return true;
    }

    if (board [3][5]==player && board [2][4]==player && board [1][3]==player && board[0][2]== player)
    {
        cout << "Player has won by filling the diagonal way" << endl;
        return true;
    }
    if (board [4][5]==player && board [3][4]==player && board [2][3]==player && board[1][2]== player)
    {
        cout << "Player has won by filling the diagonal way" << endl;
        return true;
    }
    if (board [5][5]==player && board [4][4]==player && board [3][3]==player && board[2][2]== player)
    {
        cout << "Player has won by filling the diagonal way" << endl;
        return true;
    }
    if (board [6][5]==player && board [5][4]==player && board [4][3]==player && board[3][2]== player)
    {
        cout << "Player has won by filling the diagonal way" << endl;
        return true;
    }
    if (board [6][4]==player && board [5][3]==player && board [4][2]==player && board[3][1]== player)
    {
        cout << "Player has won by filling the diagonal way" << endl;
        return true;
    }

    if (board [1][3]==player && board [2][2]==player && board [3][1]==player && board[4][0]== player)
    {
        cout << "Player has won by filling the diagonal way" << endl;
        return true;
    }
    if (board [1][4]==player && board [2][3]==player && board [3][2]==player && board[4][1]== player)
    {
        cout << "Player has won by filling the diagonal way" << endl;
        return true;
    }
    if (board [2][4]==player && board [3][3]==player && board [4][2]==player && board[4][2]== player)
    {
        cout << "Player has won by filling the diagonal way" << endl;
        return true;
    }
    if (board [3][4]==player && board [4][3]==player && board [5][2]==player && board[6][1]== player)
    {
        cout << "Player has won by filling the diagonal way" << endl;
        return true;
    }
    if (board [2][3]==player && board [3][2]==player && board [4][1]==player && board[5][0]== player)
    {
        cout << "Player has won by filling the diagonal way" << endl;
        return true;
    }
    if (board [3][3]==player && board [4][2]==player && board [5][1]==player && board[6][0]== player)
    {
        cout << "Player has won by filling the diagonal way" << endl;
        return true;
    }

    if (board [6][3]==player && board [5][2]==player && board [4][1]==player && board[3][0]== player)
    {
        cout << "Player has won by filling the diagonal way" << endl;
        return true;
    }
    if (board [5][3]==player && board [4][2]==player && board [3][1]==player && board[2][0]== player)
    {
        cout << "Player has won by filling the diagonal way" << endl;
        return true;
    }
    if (board [5][4]==player && board [4][3]==player && board [3][2]==player && board[2][1]== player)
    {
        cout << "Player has won by filling the diagonal way" << endl;
        return true;
    }
    if (board [4][3]==player && board [3][2]==player && board [2][1]==player && board[1][0]== player)
    {
        cout << "Player has won by filling the diagonal way" << endl;
        return true;
    }
    if (board [4][4]==player && board [3][3]==player && board [2][2]==player && board[1][1]== player)
    {
        cout << "Player has won by filling the diagonal way" << endl;
        return true;
    }
    if (board [3][3]==player && board [2][2]==player && board [1][1]==player && board[0][0]== player)
    {
        cout << "Player has won by filling the diagonal way" << endl;
        return true;
    }
    if (board [3][4]==player && board [2][3]==player && board [1][2]==player && board[0][1]== player)
    {
        cout << "Player has won by filling the diagonal way" << endl;
        return true;
    }


    else if (board [0][1]==player && board [1][1]==player && board[2][2]==player && board[3][3]==player)
    {
        cout << "Player has won by filling column 2!";
        return true;
    }
    return false;
}
 bool BoardFull(char board[][COLS], int numRows)
 {
 
    return true;
}