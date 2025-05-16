#include <iostream>
#include<unistd.h>
using namespace std;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char player = 'X';

// Function to set the color of console output
void setColor(int color) {
    cout << "\033[" << color << "m";
}

void display_board() {
    setColor(36); // Set color to cyan
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " \n";
    cout << "---|---|---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " \n";
    cout << "---|---|---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " \n";
    setColor(37); // Set color to white
}

void player_turn() {
    int row, col;
    cout << "Player " << player << " turn \n(Enter row): ";
    cin >> row;
    row--;
    cout<<"(Enter column): ";
    cin>>col;
    col--;
    if (board[row][col] == ' ') {
        board[row][col] = player;
    } else {
        setColor(31); // Set color to red
        cout << "This cell is already occupied! Try again.\n";
        setColor(37); // Set color to white
        player_turn();
    }
}

void change_player() {
    if (player == 'X') {
        player = 'O';
    } else {
        player = 'X';
    }
}

bool check_game_over() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return true;
        }
    }
    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
            return true;
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return true;
    }
    // Check for tie
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != ' ') {
                count++;
            }
        }
    }
    if (count == 9) {
        setColor(33); // Set color to yellow
        cout << "The game is a tie!\n";
        setColor(37); // Set color to white
        return true;
    }
    return false;
}

int main() {
    setColor(36); // Set color to cyan
    cout << "Tic Tac Toe Game\n";
    display_board();
    while (!check_game_over()) {
        player_turn();
        display_board();
        if (check_game_over()) {
            setColor(32); // Set color to green
            cout << "Player " << player << " wins!\n";
            setColor(37); // Set color to white
        }
        change_player();
    }
    sleep(2);
    return 0;
}

