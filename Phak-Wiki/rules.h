#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>

/*
Will contain all information related to rules 
- Format 
- Card Types
- Terms 
- Game Mechanics 
- Creation Piles
*/

using namespace std;

void Format()
{
    ofstream file;
    file.open("Phaktionz/format.md");

    string header = "# Formats \n";

    struct format
    {
        string name;
        string version;
        string desc; //description
    };

    struct format standard = {
        "Standard", "V1.\\*.\\*",
        "* This format is the most commonly played format and considered the default\n* A Deck must contain 50 cards\n* A Deck must only contain Summons from one Faction"};

    //Standard first then any other format will have it's own block
    file << header << "## " << standard.name << "(" << standard.version << ")\n"
         << standard.desc; // standard block
    /*
    Other Blocks
    */
    file.close();
    cout << "Check Phaktionz/format.md !" << endl;
}

void Types()
{
    ofstream file;
    struct Type
    {
        string name;
        string desc;
    };

    struct Card
    {
        string name;
        struct Type type[8]; //8 Just because it is a high enough number to not need to change for a while
    };

    /*
    Start off with Summon Types and Summon
    */
    struct Type Striker = {
        "Striker",
        "Can Battle any Opponent's Summons, but not directly"};
    struct Type Tech = {
        "Tech",
        "Can only Battle in the same column, and directly"};

    struct Card Summon = {
        "Summons",
        {Striker, Tech}};
    ////////////////////////
    /*
Now Invocation Types and Invocation
*/
    struct Type Regular = {
        "Regular",
        "This type of invocation may only be cast on your turn"};

    struct Type Counter = {
        "Counter",
        "This type of invocation may be cast on any turn"};

    struct Type Realm = {
        "Realm",
        "This type of invocation remains on the battlefield, with continuous abilities"};

    struct Type Weapon = {
        "Weapon",
        "This type of invocation attaches itself to a Summon on the Battlefield"};
    struct Card Invocation = {
        "Invocations",
        {Regular, Counter, Realm, Weapon}};
    //////////
    cout << "Do you want to save this? [Y/N]: ";
    char save; 
    cin >> save;
    save = tolower(save);
    //
    if(save == 'y'){
    cout << "Saving...\n";
    file.open("Phaktionz/Types.md"); 

    file << "# " << Summon.name << ":\n\t* " << Summon.type[0].name << ": " << Summon.type[0].desc << "\n\t";
    file << "* "  << Summon.type[1].name << ": " << Summon.type[1].desc << "\n";

    file << "# " << Invocation.name << ":\n\t* " << Invocation.type[0].name << ": " << Invocation.type[0].desc << "\n\t";
    file << "* " << Invocation.type[1].name << ": " << Invocation.type[1].desc << "\n\t";
    file << "* " << Invocation.type[2].name << ": " << Invocation.type[2].desc << "\n\t";
    file << "* " << Invocation.type[3].name << ": " << Invocation.type[3].desc << "\n";
    // Summons
    cout << Summon.name << ":\n\t" << Summon.type[0].name << ": " << Summon.type[0].desc << "\n\t";
    cout << Summon.type[1].name << ": " << Summon.type[1].desc << "\n";
    
    // Invocation
    cout << Invocation.name << ":\n\t" << Invocation.type[0].name << ": " << Invocation.type[0].desc << "\n\t";
    cout << Invocation.type[1].name << ": " << Invocation.type[1].desc << "\n\t";
    cout << Invocation.type[2].name << ": " << Invocation.type[2].desc << "\n\t";
    cout << Invocation.type[3].name << ": " << Invocation.type[3].desc << "\n";
    } else {
    // Summons
    cout << Summon.name << ":\n\t" << Summon.type[0].name << ": " << Summon.type[0].desc << "\n\t";
    cout << Summon.type[1].name << ": " << Summon.type[1].desc << "\n";
    // Invocation
    cout << Invocation.name << ":\n\t" << Invocation.type[0].name << ": " << Invocation.type[0].desc << "\n\t";
    cout << Invocation.type[1].name << ": " << Invocation.type[1].desc << "\n\t";
    cout << Invocation.type[2].name << ": " << Invocation.type[2].desc << "\n\t";
    cout << Invocation.type[3].name << ": " << Invocation.type[3].desc << "\n";
    }
}

void Terms(){
    ofstream file;
    cout << "Do you want to save this? [Y/N]: ";
    char save;
    cin >> save;
    save = tolower(save);

    string terms[11] = {
        "Summons: Units that battle in the battlefield", 
        "Invocations: Sorcery that may be cast to gain benefit",
        "Abled: The position in which a unit may battle", 
        "Disabled: The position in which a unit is unable to battle (This is done with your Summon being sideways)", 
        "Demote: To have a summon leave the battlefield", 
        "Exile: To remove from play a summon", 
        "Tiers: Represents the rank of a summon, Tier 1 being the lowest and 3 the highest", 
        "DMG: The amount of cards a summon can deal an opponent to lose", 
        "Fizzle: To stop an opponent's play", 
        "L/x: Limit x per turn", 
        "Lx: Limit x per match"
    };

    if(save == 'y'){
        cout << "Saving...\n";
        file.open("Phaktionz/Terms.md");
        file << "# Keywords/Conditions:\n";
        for (int i = 0; i < 11; i++){
           file << "* " << terms[i] << "\n";     
        }
        cout << "Keywords/Conditions:\n"; 
        for (int i = 0; i < 11; i++){
           cout << terms[i] << "\n";     
        }
    file.close();    
    } else{
        cout << "Keywords/Conditions:\n"; 
        
        for (int i = 0; i < 11; i++){
           cout << terms[i] << "\n";     
        }
    }

}

void Game(){
    ofstream file;
    cout << "Do you want to save this? [Y/N]: ";
    char save;
    cin >> save;
    save = tolower(save);

    string Mechanics[5] = {
    "• When a Summon battles it becomes disabled (turned sideways)",
    "• To place a Tier 2 or higher summon, you must demote Tiers total to the Summon’s Tier.\n\t– For example, a Tier 2 may be placed by demoting a Tier 2 or 2 Tier 1s.",
    "\b• At the start of the game, after the turn order is chosen, both players may mulligan any cards in their hand once.",
    "• If a card’s ability were to break one of these rules, the card’s ability takes precedence.",
    "• When battling, a Player takes DMG equal to the difference between the Summons.\n\t– If a Summon that battles has less DMG than the opposing, no DMG is dealt.\n\t– If a Summon that battles has more DMG than the opposing, the Opponent takes the difference, and the Summon is demoted, except if it’s Tier 3+."
    };
    
    if(save == 'y'){
        file.open("Phaktionz/Game_Mechanics.md");
        cout << "Saving...\n";

        file << "# Game Mechanics\n";
        for (int i=0; i < 5 ; i ++){
            file << Mechanics[i] << "\n";
        }

        cout << "Game Mechanics: \n";
        for (int i=0; i < 5 ; i ++){
            cout << Mechanics[i] << "\n";
        }
    } else {
        cout << "Game Mechanics: \n";
        for (int i=0; i < 5 ; i ++){
            cout << Mechanics[i] << "\n";
        }
    }
}

void CP(){
    ofstream file;
    cout << "Do you want to save this? [Y/N]: ";
    char save;
    cin >> save;
    save = tolower(save);

    string CP[4] = {
        "• A CP Card may be added to your hand if it satisfies the Card’s Create condition.",
        "• Limit: 10 (In Format V1 & V2)",
        "• Abilities that include ’CP’ refer to Creation Pile",
        "• CP Cards are identified with CP in the top left along where Tier or Invocation type is located."
    };

    if(save == 'y'){
        file.open("Phaktionz/CP.md");
        cout << "Saving...\n";
        file << "# Creation Pile\n";
        for(int i=0; i < 4; i++){
            file << CP[i] << "\n";
        }

        cout << "Creation Pile:\n";
        for(int i=0; i < 4; i++){
            cout << CP[i] << "\n";
        }
        file.close();
    }else{
        cout << "Creation Pile:\n";
        for(int i=0; i < 4; i++){
            cout << CP[i] << "\n";
        }
    }
}





void rules()
{
    string cmd;
    cout << "Available Commands: \n"
            << "\t Format: Rules on the Formats\n"
            << "\t Types: Lists out the different type of Summons/Invocations\n"
            << "\t Terms: Lists out the common terms\n"
            << "\t Game: Explain game mechanics\n"
            << "\t CP: Explain Creation Pile\n";
    do {
        cout << "Rules >> ";
    
        cin >> cmd;
        if (cmd == "Format")
        {
            Format();
        } else if (cmd == "Types")
        {
            Types();
        } else if (cmd == "Terms")
        {
            Terms();
        } else if (cmd == "Game")
        {
            Game();
        } else if (cmd == "CP")
        {
            CP();
        }




        else if (cmd == "clear"){
        system("clear");
        }
    }while (cmd != "exit");
}
