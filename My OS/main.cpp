#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <dirent.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <iomanip>
#include <limits>

using namespace std;

double ram = 0, storage = 0;
mutex mtx;

// === Utility Functions ===
void* calculator(void* p)       { system("gnome-terminal -- bash -c './calculator; exec bash'"); return NULL; }
void* calendar(void* p)         { system("gnome-terminal -- bash -c './calendar; exec bash'"); return NULL; }
void* clock(void* p)            { system("gnome-terminal -- bash -c './clock; exec bash'"); return NULL; }
void* copyFile(void* p)         { system("gnome-terminal -- bash -c './copyFile; exec bash'"); return NULL; }
void* createFile(void* p)       { system("gnome-terminal -- bash -c './createFile; exec bash'"); return NULL; }
void* deletefile(void* p)       { system("gnome-terminal -- bash -c './deletefile; exec bash'"); return NULL; }
void* Fileproperties(void* p)   { system("gnome-terminal -- bash -c './Fileproperties; exec bash'"); return NULL; }
void* moveFile(void* p)         { system("gnome-terminal -- bash -c './moveFile; exec bash'"); return NULL; }
void* notepad(void* p)          { system("gnome-terminal -- bash -c './notepad; exec bash'"); return NULL; }
void* rock_sissor(void* p)      { system("gnome-terminal -- bash -c './rock_sissor; exec bash'"); return NULL; }
void* renamefile(void* p)       { system("gnome-terminal -- bash -c './rename; exec bash'"); return NULL; }
void* song(void* p)             { system("gnome-terminal -- bash -c './song; exec bash'"); return NULL; }
void* tictactoe(void* p)        { system("gnome-terminal -- bash -c './tictactoe; exec bash'"); return NULL; }
void* towerOfHonoi(void* p)     { system("gnome-terminal -- bash -c './towerOfHonoi; exec bash'"); return NULL; }
void* video(void* p)            { system("gnome-terminal -- bash -c './video; exec bash'"); return NULL; }

void dis() {
    DIR* dir = opendir("/proc");
    if (!dir) {
        cerr << "Failed to open directory /proc.\n";
        return;
    }

    struct dirent* ent;
    vector<pid_t> pids;
    while ((ent = readdir(dir)) != nullptr) {
        if (ent->d_type != DT_DIR) continue;
        const string pid_str = ent->d_name;
        if (pid_str.find_first_not_of("0123456789") != string::npos) continue;
        const pid_t pid = stoi(pid_str);
        char cmdline_path[64];
        sprintf(cmdline_path, "/proc/%d/cmdline", pid);
        FILE* cmdline_file = fopen(cmdline_path, "r");
        if (!cmdline_file) continue;
        char cmdline[1024];
        size_t len = fread(cmdline, 1, sizeof(cmdline), cmdline_file);
        fclose(cmdline_file);
        if (len == 0) continue;
        cmdline[len] = '\0';
        if (strstr(cmdline, "./") == cmdline) {
            pids.push_back(pid);
            cout << pid << " " << cmdline << endl;
        }
    }
    closedir(dir);

    if (pids.empty()) {
        cout << "No processes found.\n";
        return;
    }

    int pid;
    cout << "Enter the PID of the process you want to terminate: ";
    cin >> pid;
    int ret = kill(pid, SIGKILL);
    if (ret == -1) perror("Failed to kill process");
    else cout << "Process terminated successfully.\n";
}

void startup() {
    system("clear");
    ifstream infile("start.txt");
    if (!infile) {
        cerr << "\033[1;31mError: Could not open start.txt\n\033[0m";
        return;
    }

    string line;
    while (getline(infile, line)) {
        if (!line.empty()) {
            cout << "\033[1;32m" << line << "\033[0m\n";
            usleep(200000); // 0.2 sec
        }
    }
}

void display_res() {
    int count = 0;
    DIR* dir = opendir("/proc");
    if (!dir) {
        cerr << "Failed to open /proc.\n";
        return;
    }

    struct dirent* ent;
    while ((ent = readdir(dir)) != nullptr) {
        if (ent->d_type != DT_DIR) continue;
        const string pid_str = ent->d_name;
        if (pid_str.find_first_not_of("0123456789") != string::npos) continue;
        char cmdline_path[64];
        sprintf(cmdline_path, "/proc/%s/cmdline", pid_str.c_str());
        FILE* cmdline_file = fopen(cmdline_path, "r");
        if (!cmdline_file) continue;
        char cmdline[1024];
        size_t len = fread(cmdline, 1, sizeof(cmdline), cmdline_file);
        fclose(cmdline_file);
        if (len == 0) continue;
        cmdline[len] = '\0';
        if (strstr(cmdline, "./") == cmdline) {
            count++;
        }
    }

    closedir(dir);
    cout << "Available RAM: " << ram - 0.5 * count << " GB\n";
    cout << "Available Storage: " << storage - 0.1 * count << " GB\n";
}

// === Main Function ===
int main() {
    startup();
    sleep(2);
    system("clear");

    cout << "Enter total RAM (GB): ";
    cin >> ram;
    cout << "Enter total Storage (GB): ";
    cin >> storage;

    pthread_t threads[20];
    int choice;

    while (true) {
        system("clear");

        // Menu Header
        cout << "\033[1;36m" << string(60, '=') << "\n";
        cout << "🌟 Welcome to Smart Utility Shell 🌟\n";
        cout << string(60, '=') << "\033[0m\n\n";

        // Menu Options
        cout << "\033[1;33mChoose an option:\033[0m\n";
        cout << "\033[1;32m";
        cout << "1. Calculator 🧮\n2. Calendar 📅\n3. Clock ⏰\n4. Copy File 📂\n5. Create File ✍️\n";
        cout << "6. Delete File 🗑️\n7. File Properties 📄\n8. Move File 🚚\n9. Notepad 📝\n10. Rename File ✏️\n";
        cout << "11. Play Song 🎵\n12. Play Video 🎬\n13. Tic Tac Toe ❌⭕\n14. Tower of Honoi 🗼\n";
        cout << "15. Rock Paper Scissor ✊✋✌️\n16. Dis Function 🔍\n";
        cout << "\033[1;31m-1. Exit ❌\033[0m\n\n";

        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        pid_t pid = fork();
        if (pid == 0) {
            switch (choice) {
                case 1: pthread_create(&threads[1], NULL, calculator, NULL); pthread_join(threads[1], NULL); break;
                case 2: pthread_create(&threads[2], NULL, calender, NULL); pthread_join(threads[2], NULL); break;
                case 3: pthread_create(&threads[3], NULL, clock, NULL); pthread_join(threads[3], NULL); break;
                case 4: pthread_create(&threads[4], NULL, copyFile, NULL); pthread_join(threads[4], NULL); break;
                case 5: pthread_create(&threads[5], NULL, createFile, NULL); pthread_join(threads[5], NULL); break;
                case 6: pthread_create(&threads[6], NULL, deletefile, NULL); pthread_join(threads[6], NULL); break;
                case 7: pthread_create(&threads[7], NULL, Fileproperties, NULL); pthread_join(threads[7], NULL); break;
                case 8: pthread_create(&threads[8], NULL, moveFile, NULL); pthread_join(threads[8], NULL); break;
                case 9: pthread_create(&threads[9], NULL, notepad, NULL); pthread_join(threads[9], NULL); break;
                case 10: pthread_create(&threads[10], NULL, renamefile, NULL); pthread_join(threads[10], NULL); break;
                case 11: pthread_create(&threads[11], NULL, song, NULL); pthread_join(threads[11], NULL); break;
                case 12: pthread_create(&threads[12], NULL, video, NULL); pthread_join(threads[12], NULL); break;
                case 13: pthread_create(&threads[13], NULL, tictactoe, NULL); pthread_join(threads[13], NULL); break;
                case 14: pthread_create(&threads[14], NULL, towerOfHonoi, NULL); pthread_join(threads[14], NULL); break;
                case 15: pthread_create(&threads[15], NULL, rock_sissor, NULL); pthread_join(threads[15], NULL); break;
                case 16: dis(); break;
                case -1: exit(0);
                default: cout << "Invalid option!\n"; sleep(2); exit(0);
            }
            exit(0);
        } else if (pid > 0) {
            wait(NULL);
            display_res();
        } else {
            cerr << "Failed to fork.\n";
        }
    }

    return 0;
}

