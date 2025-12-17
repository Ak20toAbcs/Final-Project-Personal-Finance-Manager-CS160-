#include "system.h"
#include <cstdlib>

using namespace std;

// dùng để xóa màn hình
void ClearScreen(){
    system("cls");
}
void PauseScreen(){
    system("pause");
}
int InputNumber(const string &prompt){
    int value;
    cout << prompt;
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\033[1A" << "\033[2K"; // Xóa dòng lỗi
        cout << "Invalid input! " << prompt; // In lại prompt
    }
    cin.ignore(); // Xóa bộ nhớ đệm sau khi nhập xong
    return value;
}
string borderLine = "+----------------------------------------------------------+";




