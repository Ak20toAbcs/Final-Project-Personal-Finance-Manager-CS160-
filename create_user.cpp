#include "system.h"
#include "user_data.h"
#include "create_user.h"
#include <iostream>
#include <fstream>


using namespace std;

void CreateUserPage() {
    ClearScreen();
    hasUsed = true;

    cout << borderLine << '\n';
    cout << "Welcome to Our Project!" << '\n';

    // nhập - lưu Username
    cout << "Please create your username - max 50 characters (Enter - confirm)" << '\n';
    cin.getline(userName, 51);

    ofstream fout;
    fout.open("D:/appdev/lab_project/Final-Project-Personal-Finance-Manager-CS160-/data/user_name.bin", ios::binary);
   
    if (fout.is_open()) {
    fout.write(userName, 51);
    fout.close();
    cout << "Username saved successfully!" << endl;
    } else {
        cout << "Error: Could not save username!" << endl;
    }

    return;
}



