#include "library.h"
#include "fs.cpp"
int main(){
   /*
    All different type of content and libraries will be kept in their respective category
    Ex. Formula sheets: fs.cpp
    We will have the following order: 

    0 : FS
    1 : B (Basics)
    2 : N (Notes)
   */

    string cmd;
    do{
        cout << "MKProjects >> ";
        cin >> cmd;

        // List out the commands 
        // 

        if(cmd == "get"){
            cout << "Enter ID: ";
            int ID; 
            cin >> ID;
            if(fs.c->id == ID){
              get(fs.c[0]);      
            }
        }

    }while(cmd != "exit");



    return 0;
}