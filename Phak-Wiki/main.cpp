#include <iostream>
#include <string>
#include <sys/stat.h> 
#include <sys/types.h> 
#include <bits/stdc++.h> 
#include "rules.h"
using namespace std;

int main(){
    string cmd;
     cout << "Phaktionz-Wiki CLI \nMKProjects Version 1.0.0 \n";
do {
    cout << "Phaktionz >> ";
    cin >> cmd;
    if (cmd == "Init"){
          // Creating a directory 
        if (mkdir("Phaktionz", 0777) == -1) {
            cerr << "Error :  " << strerror(errno) << endl; 
        }else{
                cout << "Initialize Complete \n"; 
            }
    }
    /// Rules Commands Begin ///
    /*
    Base Rules Function 
    Format 
    Type
    Terms
    Game
    CP
    */

    else if (cmd == "Rules" || cmd == "R"){
       rules();
    }
    else if (cmd == "Rules:Types" || cmd == "R:Types"){
        Types();
    }
    else if (cmd == "Rules:Terms" || cmd == "R:Terms"){
        Terms();
    }
    else if (cmd == "Rules:Game" || cmd == "R:Game"){
        Game();
    }
    else if (cmd == "Rules:CP" || cmd == "R:CP"){
        CP();
    }

    /// Rules Commands Ends ///


    /// General Commands Begins ///
    else if (cmd == "help"){
        cout << "Init: To initialize Phaktionz Directory\n" 
        << "Rules, R: Will Offer Help in Rules\n" 
        << "Profile, P: Will give the Profile of a certain Character\n" 
        << "Ability. A: Will give the details of a certain Ability\n"
        << endl;
    }

    else if (cmd == "clear"){
        system("clear");
    }


    else {
        if (cmd != "exit"){
        cout << "Command does not exist, try \"help\" for a list of commands" << endl; // Error handler of incorrect commands
        }
    }
  /// General Commands Ends ///  
} while (cmd != "exit");
    if(cmd == "exit"){
        cout << "Bye!" << endl; //Final Goodbye when exited 
    }
}