#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <ctime>

using namespace std;

int main() {
    while (true) {
        system("clear");  // Clears the terminal

        // Get current system time
        time_t now = time(0);
        tm *ltm = localtime(&now);

        // Print formatted time
        cout << "\n\n\t\t⏰ Current Time: ";
        cout << setw(2) << setfill('0') << ltm->tm_hour << ":"
             << setw(2) << setfill('0') << ltm->tm_min << ":"
             << setw(2) << setfill('0') << ltm->tm_sec << endl;

        this_thread::sleep_for(chrono::seconds(1));  // Wait 1 second
    }

    return 0;
}

