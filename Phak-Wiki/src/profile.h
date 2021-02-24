#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h> 
#include <sys/types.h> 
using namespace std;
ofstream file;

struct Characters{
    string Name;
    int Age;
    string Gender;
    string Faction[3];
    string Decks[5];
    string Role;
    string Desc; 
};

struct Profile{
    Characters characters[20];
};

struct Characters Zane = {
    "Zane Fulmore", 
    17, 
    "Male",
    {"Warriors", "Sorcerers", "Dragons"},
    {"Warriors – Basic",
    "Warriors - The Warrior’s Path",
    "Sorcerers - Prestige’s Will",
    "Dragons - Dragonic Reign", 
    "Warriors/Sorcerers/Dragons - Z-Fulthrottle Synthesis"
    }, 
    "Main Character", 
    "Zane is the energetic character that is always determined,and pushing himself to do better.\n\
    \tIn Season 1 we see him starting outwith some success in Phaktionz and as he progresses becomes the best play.\n\
    \tHe later becomes full of himself to it, until he sees what greedreally becomes of someone."
};

struct Characters Lulo = {
    "Lulo Tsuzaki",
    17,
    "Male",
    {"Mythicals"},
    {
    "Mythicals-United",
    "Mythicals-Lin’s Forbidden Army",
    "Mythicals-Helio’s Will"
    },
    "MC’s Bestfriend",
    "Lulo is the calm and mysterious one in the group.\n\
    \tWith him living with Finn not being the weirdest part, he later goes evil in Season 2 after being manipulated by Lyla.\n\
    \tBut he still stays to be with Zane when he needs him most, as well as this he’s usually the Character who doesn’t lose, and if he does something is wrong."
};

struct Characters Khloe = {
    "Khloe Bright",
    18,
    "Female",
    {"Kingdom"},
    {"Kingdom - Insects",
    "Kingdom - King’s Will"
    },
    "Female MC Bestfriend",
    "Khloe is like the Mom of the gang, she’s usually the one to try and get people back together, or knows the problem of them.\n\
    \tShe is used to the craziness of the guys, but cares much about them.\n\
    \tAs well as that, she works at a daycare, and is a few months older than Zane and Lulo."
};


struct Characters Percy = {
    "Percy Thomson",
    18,
    "Male",
    {
        "Mythicals",
        "Alchemists"
    },
    {
        "Mythicals - Elf Reinforcement",
        "Alchemists - Chryso Alchemy"
    },
    "Comical Friend in the Gang",
    "Percy is the comedian in the group, who always tries to make the others laugh.\n\ 
    \tHe tends to get into arguments with Lulo as their ideals polar, but he also is one of the teammates who is the most effective in encouraging them."
};

struct Characters Finn = {
    "Finn",
    40,
    "Male"    
    {"Sorcerers"},
    {"Sorcerers - Astral Perils"},
    "Coach / Father Figure",
    "Finn is the shop owner of the FFF shop.",
    "He is also the father of Lyla Preston, and guardian of Lulo.\n\
     \tHe is as well as Prestige’s right hand man, but after leaving his mission for love, he had lost his way, until he lost everything he decided it was time to go back."
};




void Profile(){
    string cmd;
    do{
        cout << "Profile >> ";
        cin >> cmd;
        if(cmd == "list"){
            //List of Characters
        }

        //Individual Characters
        else if (cmd == "Zane"){
            cout << "Do you want to save this? [Y/N]: ";
            char save;
            cin >> save;    
            save = tolower(save);
            if(save == 'y'){
                cout << "Saving...\n";
                file.open("Phaktionz/Zane.md");

                file << "# " << Zane.Name << "\n";
                file << "* Age: " << Zane.Age << "\n";
                file << "* Gender: " << Zane.Gender << "\n";
                file << "* Factions: " << "\n\t";   
                for(int i=0; i < 3; i++){
                    file << i + 1 << ". " << Zane.Faction[i] <<"\n\t";
                }   
                file << "\b* Decks: \n\t";
                for(int i=0; i < 5; i++){
                    file << i + 1 << ". " << Zane.Decks[i] << "\n\t";
                }
                file << "\b* Description: \n" << Zane.Desc << endl;

                ///  
                
                cout << "Fullname: " << Zane.Name << "\n";
                cout << "Age: " << Zane.Age << "\n";
                cout << "Gender: " << Zane.Gender << "\n";
                cout << "Factions: " << "\n\t";   
                for(int i=0; i < 3; i++){
                    cout << i + 1 << ". " << Zane.Faction[i] <<"\n\t";
                }   
                cout << "\bDecks: \n\t";
                for(int i=0; i < 5; i++){
                    cout << i + 1 << ". " << Zane.Decks[i] << "\n\t";
                }
                cout << "\bDescription: \n" << "\t" << Zane.Desc << endl;
            }
        }
        else if (cmd == "Lulo"){
        cout << "Do you want to save this? [Y/N]: ";
        char save;
        cin >> save;    
        save = tolower(save);
        if(save == 'y'){
            cout << "Saving...\n";
            file.open("Phaktionz/Lulo.md");

            file << "# " << Lulo.Name << "\n";
            file << "* Age: " << Lulo.Age << "\n";
            file << "* Gender: " << Lulo.Gender << "\n";
            file << "* Factions: " << "\n\t";   
            for(int i=0; i < 3; i++){
                file << i + 1 << ". " << Lulo.Faction[i] <<"\n\t";
            }   
            file << "\b* Decks: \n\t";
            for(int i=0; i < 5; i++){
                file << i + 1 << ". " << Lulo.Decks[i] << "\n\t";
            }
            file << "\b* Description: \n" << Lulo.Desc << endl;

            ///  
        
            cout << "Fullname: " << Lulo.Name << "\n";
            cout << "Age: " << Lulo.Age << "\n";
            cout << "Gender: " << Lulo.Gender << "\n";
            cout << "Factions: " << "\n\t";   
            for(int i=0; i < 3; i++){
                cout << i + 1 << ". " << Lulo.Faction[i] <<"\n\t";
            }   
            cout << "\bDecks: \n\t";
            for(int i=0; i < 5; i++){
            cout << i + 1 << ". " << Lulo.Decks[i] << "\n\t";
        }
            cout << "\bDescription: \n" << "\t" << Lulo.Desc << endl;
        }

    }
    else if (cmd == "Khloe"){
        cout << "Do you want to save this? [Y/N]: ";
        char save;
        cin >> save;    
        save = tolower(save);
        if(save == 'y'){
            cout << "Saving...\n";
            file.open("Phaktionz/Khloe.md");

            file << "# " << Khloe.Name << "\n";
            file << "* Age: " << Khloe.Age << "\n";
            file << "* Gender: " << Khloe.Gender << "\n";
            file << "* Factions: " << "\n\t";   
            for(int i=0; i < 1; i++){
                file << i + 1 << ". " << Khloe.Faction[i] <<"\n\t";
            }   
            file << "\b* Decks: \n\t";
            for(int i=0; i < 2; i++){
                file << i + 1 << ". " << Khloe.Decks[i] << "\n\t";
            }
            file << "\b* Description: \n" << Khloe.Desc << endl;

            ///  
        
            cout << "Fullname: " << Khloe.Name << "\n";
            cout << "Age: " << Khloe.Age << "\n";
            cout << "Gender: " << Khloe.Gender << "\n";
            cout << "Factions: " << "\n\t";   
            for(int i=0; i < 1; i++){
                cout << i + 1 << ". " << Khloe.Faction[i] <<"\n\t";
            }   
            cout << "\bDecks: \n\t";
            for(int i=0; i < 2; i++){
            cout << i + 1 << ". " << Khloe.Decks[i] << "\n\t";
        }
            cout << "\bDescription: \n" << "\t" << Khloe.Desc << endl;
        }

    }
    


    }while(cmd != "exit");
}