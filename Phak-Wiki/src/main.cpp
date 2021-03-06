#include <iostream>
#include <string>
#include <sys/stat.h> 
#include <sys/types.h> 
#include <bits/stdc++.h> 
#include "rules.h"
#include "profile.h"
using namespace std;
string Version = "Version 1.1.1";
int main(){
    string cmd;
     cout << "Phaktionz-Wiki CLI \nMKProjects " << Version << "\n";
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

    /// Profile Commands Begin ///
    else if (cmd == "Profile" || cmd == "P"){
        Profile();
    }

    /// Profile Commands Ends ///

    /// Ability Commands Begin ///
    else if (cmd == "Ability" || cmd == "A"){
        cout << "Coming Soon!!!";
    }
    /// Ability Commands End ///

    /// General Commands Begins ///
    else if (cmd == "help"){
        cout << "Init: To initialize Phaktionz Directory\n" 
        << "Rules, R: Will Offer Help in Rules\n" 
        << "Profile, P: Will give the Profile of a certain Character\n" 
        << "Ability. A: Will give the details of a certain Ability\n"
        << "Install, I: This will install the gui Phaktionz-Wiki\n"
        << endl;
    }

    else if (cmd == "Install" || cmd == "I"){
        cout << "Phaktionz-Wiki is currently only available on Debian x86_64 systems!\n" 
        << "Would you like to continue? [Y/N]: ";
        char answer;
        cin >> answer;
        answer = tolower(answer);
        if(answer == 'y'){
            //First update 
            //Make sure wget is installed 
            //Get the package and install 
            //Get missing packages 
            //Install again 
            const char *commands[6] = {
                "sudo apt-get update",
                "sudo apt-get install wget",
                "wget http://download1648.mediafire.com/qnlcvn4bmkqg/mx3zrw8ntttx7jk/phaktionz-wiki_1.0.1_amd64.deb", 
                "sudo dpkg -i phaktionz-wiki_1.0.1_amd64.deb", 
                "sudo apt-get install -f", 
                "sudo dpkg -i phaktionz-wiki_1.0.1_amd64.deb"
            };
            for(int i=0; i < 6; i++){
                system(commands[i]);
            }
        } else {
            cout << "Installation exited";
        }
    }





    else if (cmd == "version" || cmd == "Version"){
        cout << Version << endl;
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