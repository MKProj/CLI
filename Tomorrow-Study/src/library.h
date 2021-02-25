#include <iostream>
#include <string>

using namespace std;

struct Content {
    int id;
    string type;
    string name;
    string author;
    string filename;
};

struct Library {
    Content content[50];
};

