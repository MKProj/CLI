#include <string>
#include <iostream>
#include <fstream>
#include <sys/stat.h> 
#include <sys/types.h> 
#include <bits/stdc++.h> 

using namespace std;

struct content
{
    int id;
    string name;
    string author;
    string version; 
    string url;
};

const int libsize = 25;
struct library
{
   content c[libsize];
};

void init (){
    system("mkdir Tomorrow-Study-Material");
}


void details (struct content c){
    cout << "ID: " << c.id << "\n";
    cout << "Name: " << c.name << "\n";
    cout << "Author: " << c.author << "\n";
    cout << "Version: " << c.version << "\n";
    cout << "Url: " << c.url << "\n";
}

void libdetails (struct library l[libsize]){
    for(int i=0; i<libsize; i++){
        details(l->c[i]);
    }
}
string wget = "wget ";

void get (struct content c){
    ofstream shfile; 
    shfile.open("get.sh");
    shfile << wget + c.url << endl;
    shfile.close();
    system("chmod +x get.sh");
    system("./get.sh"); 
}