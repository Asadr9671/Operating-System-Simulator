#include <iostream>
#include <cstdlib>
#include <ctime>
#include<unistd.h>
using namespace std;

// Function to set the color of console output
void setColor(int color) {
    cout << "\033[" << color << "m";
}

int main() {
    srand(time(0)); // Seed the random number generator
    int computer_choice = rand() % 3 + 1; // Generate a random number between 1 and 3
    int player_choice;
    setColor(36); // Set color to cyan
    cout << "Rock Paper Scissors Game\n";
    cout << "1. Rock\n";
    cout << "2. Paper\n";
    cout << "3. Scissors\n";
    setColor(37); // Set color to white
    cout << "Enter your choice (1-3): ";
    cin >> player_choice;
    if (player_choice == 1) {
        setColor(35); // Set color to magenta
        cout << "You chose Rock.\n";
        if (computer_choice == 1) {
            setColor(33); // Set color to yellow
            cout << "Computer chose Rock.\n";
            cout << "It's a tie!\n";
        } else if (computer_choice == 2) {
            setColor(31); // Set color to red
            cout << "Computer chose Paper.\n";
            cout << "You lose!\n";
        } else {
            setColor(32); // Set color to green
            cout << "Computer chose Scissors.\n";
            cout << "You win!\n";
        }
    } else if (player_choice == 2) {
        setColor(35); // Set color to magenta
        cout << "You chose Paper.\n";
        if (computer_choice == 1) {
            setColor(32); // Set color to green
            cout << "Computer chose Rock.\n";
            cout << "You win!\n";
        } else if (computer_choice == 2) {
            setColor(33); // Set color to yellow
            cout << "Computer chose Paper.\n";
            cout << "It's a tie!\n";
        } else {
            setColor(31); // Set color to red
            cout << "Computer chose Scissors.\n";
            cout << "You lose!\n";
        }
    } else if (player_choice == 3) {
        setColor(35); // Set color to magenta
        cout << "You chose Scissors.\n";
        if (computer_choice == 1) {
            setColor(31); // Set color to red
            cout << "Computer chose Rock.\n";
            cout << "You lose!\n";
        } else if (computer_choice == 2) {
            setColor(32); // Set color to green
            cout << "Computer chose Paper.\n";
            cout << "You win!\n";
        } else {
            setColor(33); // Set color to yellow
            cout << "Computer chose Scissors.\n";
            cout << "It's a tie!\n";
        }
    } else {
        setColor(31); // Set color to red
        cout << "Invalid choice. Please enter a number between 1 and 3.\n";
    }
    sleep(3);
    return 0;
}

