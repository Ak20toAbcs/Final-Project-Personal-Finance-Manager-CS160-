#include "system.h"
#include <cstdlib>

// dùng để xóa màn hình
void ClearScreen(){
    system("cls");
}
void PauseScreen(){
    system("pause");
}
int InputNumber(const std::string &prompt){
    int value;
    std::cout << prompt;
    while (!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "\033[1A" << "\033[2K"; // Xóa dòng lỗi
        std::cout << "Invalid input! " << prompt; // In lại prompt
    }
    std::cin.ignore(); // Xóa bộ nhớ đệm sau khi nhập xong
    return value;
}
std::string borderLine = "+----------------------------------------------------------+";




