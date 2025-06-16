
#include <iostream>
#include <string>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentPlayer = 'X';
int gameOver = 0; 

void drawBoard() {
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "-----------\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "-----------\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << "\n";
}

int checkWin() {
    
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }
    
   
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }
    
   
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    
   
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return 0;
            }
        }
    }
    
    return 2;
}

void playerMove() {
    int choice;
    int row, col;
    
    cout << "Player " << currentPlayer << ", enter a number (1-9): ";
    cin >> choice;
    

    row = (choice - 1) / 3;
    col = (choice - 1) % 3;
    

    if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Invalid move! Try again.\n";
        playerMove();
    } else {
        board[row][col] = currentPlayer;
        
    
        int result = checkWin();
        if (result == 1) {
            drawBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            gameOver = 1;
        } else if (result == 2) {
            drawBoard();
            cout << "It's a tie!\n";
            gameOver = 1;
        } else {
          
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
}

int main() {
    string player1, player2;
    
    cout << "Enter Player 1 name (X): ";
    getline(cin, player1);
    cout << "Enter Player 2 name (O): ";
    getline(cin, player2);
    
    cout << "\nTIC TAC TOE\n";
    cout << player1 << " (X) vs. " << player2 << " (O)\n";
    
    while (!gameOver) {
        drawBoard();
        playerMove();
    }
    
    return 0;
}
