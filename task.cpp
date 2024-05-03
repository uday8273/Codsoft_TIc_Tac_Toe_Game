#include <iostream>
#include <vector>

class TicTacToe {
private:
    std::vector<std::vector<char>> board{{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    char currentPlayer = 'X';
    bool gameOver = false;

public:
    // Function to display the board
    void displayBoard() {
        std::cout << "Player 1 (X) - Player 2 (O)\n\n";
        for (const auto& row : board) {
            for (char cell : row) {
                std::cout << cell << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    // Function to handle player's move
    void makeMove(int choice) {
        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;
        if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
            std::cout << "Invalid move! Please choose another.\n";
            return;
        }
        board[row][col] = currentPlayer;
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        if (checkGameOver()) {
            displayBoard();
            char winner = checkWinner();
            if (winner == 'X' || winner == 'O') {
                std::cout << "Player " << winner << " wins!\n";
            } else {
                std::cout << "It's a draw!\n";
            }
        }
    }

    // Function to check if the game is over
    bool checkGameOver() {
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                gameOver = true;
                return true;
            }
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                gameOver = true;
                return true;
            }
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            gameOver = true;
            return true;
        }
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            gameOver = true;
            return true;
        }
        gameOver = true;
        for (const auto& row : board) {
            for (char cell : row) {
                if (cell != 'X' && cell != 'O') {
                    gameOver = false;
                    return false;
                }
            }
        }
        return true;
    }

    // Function to check winner
    char checkWinner() {
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                return board[i][0];
            }
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                return board[0][i];
            }
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            return board[0][0];
        }
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            return board[0][2];
        }
        return ' ';
    }

    // Function to get the current player
    char getCurrentPlayer() const {
        return currentPlayer;
    }
};

int main() {
    TicTacToe game;
    int choice;
    std::cout << "Tic Tac Toe Game\n";

    while (!game.checkGameOver()) {
        game.displayBoard();
        std::cout << "Player " << game.getCurrentPlayer() << ", enter your move (1-9): ";
        std::cin >> choice;
        game.makeMove(choice);
    }

    return 0;
}