#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
int main() {
	string objName[16];
	string filepath;
    objName[0] = "calculator";
	objName[1] = "calender";
	objName[2] = "clock";
    objName[3] = "copyFile";
	objName[4] = "createFile";
	objName[5] = "deletefile";
	objName[6] = "Fileproperties";
	objName[7] = "moveFile";
	objName[8] = "notepad";
	objName[9] = "rename";
	objName[10] = "song";
	objName[11] = "tictactoe";
    objName[12] = "towerOfHonoi";
	objName[13] = "video";
	objName[14] = "rock_sissor";
    objName[15] = "main";
    
	for (int i=0;i<15;i++)
    {
        filepath = "/home/siu/Downloads/os/os/"+ objName[i] + ".cpp";
        string command ="g++ -o "+ objName[i] + " "+ filepath;
        int result = system(command.c_str());
        if (result == 0) {
            cout << "Command for "<<objName[i]<<" executed successfully." << endl;
        } 
        else 
        {
            cerr << "Error executing command for "<<objName[i]<< endl;
        }
    }
    ///////////////For Main use thread
    filepath = "/home/siu/Downloads/os/os/"+ objName[15] + ".cpp";
        string command ="g++ -pthread -o "+ objName[15] + " "+ filepath;
        int result = system(command.c_str());
        if (result == 0) {
            cout << "Command for "<<objName[15]<<" executed successfully." << endl;
        } 
        else 
        {
            cerr << "Error executing command for "<<objName[14]<< endl;
        }
	
    return 0;
}




