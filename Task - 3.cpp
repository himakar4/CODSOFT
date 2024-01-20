//TIC-TAC-TOE GAME

#include <iostream>
#include <vector>

using namespace std;

void printBoard(const vector<vector<char> >& board) 
{
    cout << "Tic-Tac-Toe Board:" << endl;
    for (vector<vector<char> >::const_iterator it = board.begin(); it != board.end(); ++it) 
    {
        for (vector<char>::const_iterator j = it->begin(); j != it->end(); ++j) 
        {
            cout << *j << " ";
        }
        cout << endl;
    }
}

bool checkWin(const vector<vector<char> >& board, char player) 
{
    for (int i = 0; i < 3; ++i) 
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) 
        {
            return true;
        }
    }

    return (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
           (board[0][2] == player && board[1][1] == player && board[2][0] == player);
}

bool checkTie(const vector<vector<char> >& board) 
{
    for (vector<vector<char> >::const_iterator it = board.begin(); it != board.end(); ++it) 
    {
        for (vector<char>::const_iterator cell = it->begin(); cell != it->end(); ++cell) 
        {
            if (*cell == '-') 
            {
                return false;
            }
        }
    }
    return true;
}

int main() 
{
	int n=1;
	while(n!=0)
	{
	    vector<vector<char> > board(3, vector<char>(3, '-')); 
	    char currentPlayer = 'X';
		while (true) 
	    {
	        printBoard(board);
	
	        int row, col;
	        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
	        cin >> row >> col;
	
	        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != '-') 
	        {
	            cout << "Invalid move. Try again." << endl;
	            continue;
	        }
	
	        board[row][col] = currentPlayer;
	
	        if (checkWin(board, currentPlayer)) 
	        {
	            printBoard(board);
	            cout << "Player " << currentPlayer << " wins!" << endl;
	            break;
	        }
	
	        if (checkTie(board)) 
	        {
	            printBoard(board);
	            cout << "It's a tie!" << endl;
	            break;
	        }
	
	        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
	    }
		cout<<"If you want to play another game press 1 or press 0 :";
		cin>>n;
	}
    
    return 0;
}

