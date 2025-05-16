#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <limits>
#include <unistd.h>

using namespace std;

void printHeader() {
    cout << "=====================================\n";
    cout << "|| Welcome to the Awesome Calculator! ||\n";
    cout << "=====================================\n";
}

void printFooter() {
    cout << "=====================================\n";
    cout << "|| Thank you for using our calculator! ||\n";
    cout << "=====================================\n";
}

int main() {
    double num1, num2, result;
    char op;

    printHeader();

    while (true) {
        // Display the prompt and get user input
         cout << "Enter an operation (+, -, *, /, ^, %, q to quit): ";
        cin >> op;

        if (op == 'q') {
            break;
        }
        cout << "\nEnter first number: ";
        cin >> num1;
       

        if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^' || op == '%') {
            cout << "Enter second number: ";
            cin >> num2;

            // Check for division or modulus by zero
            if ((op == '/' || op == '%') && num2 == 0) {
                cerr << "Error: Division by zero is undefined." << endl;
                continue;
            }

            // Perform the requested operation
            switch (op) {
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    break;
                case '/':
                    result = num1 / num2;
                    break;
                case '^':
                    result = pow(num1, num2);
                    break;
                case '%':
                    result = fmod(num1, num2);
                    break;
                default:
                    cerr << "Invalid operation." << endl;
                    continue;
            }

            // Print the result
            cout << "\nResult: " << result << endl;
        } else {
            cerr << "Invalid operation." << endl;
        }
    }

    printFooter();

    // Sleep for 3 seconds
    sleep(3);

    return 0;
}

