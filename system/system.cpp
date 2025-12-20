#include "system.h"
#include <cstdlib>

// dùng để xóa màn hình
void ClearScreen(){
    system("cls");
}
void PauseScreen(){
    system("pause");
}
int InputNumber(const std::string &prompt, int maxIn, int minIn){
    int value;
    std::cout << prompt;
    while (!(std::cin >> value) || value < minIn || value > maxIn) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "\033[1A" << "\033[2K"; // Xóa dòng lỗi
        std::cout << "Invalid input! " << prompt; // In lại prompt
    }
    std::cin.ignore(); // Xóa bộ nhớ đệm sau khi nhập xong
    return value;
}

Date InputDate(){
    Date result;
    std::string prompt = "Year: ";
    std::cout << prompt;
    while (!(std::cin >> result.year) || result.year <= 0) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "\033[1A" << "\033[2K"; // Xóa dòng lỗi
        std::cout << "Invalid input! " << prompt; // In lại prompt
    }
    std::cin.ignore(); // Xóa bộ nhớ đệm sau khi nhập xong

    int dayinMonth [13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (result.year%400 == 0 || (result.year%4==0 && result.year %100 !=0)) dayinMonth[2] = 29;

    prompt = "Month: ";
    std::cout << prompt;
    while (!(std::cin >> result.month) || result.month <= 0 || result.month > 12) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "\033[1A" << "\033[2K"; // Xóa dòng lỗi
        std::cout << "Invalid input! " << prompt; // In lại prompt
    }
    std::cin.ignore(); // Xóa bộ nhớ đệm sau khi nhập xong

    prompt = "Day: ";
    std::cout << prompt;
    while (!(std::cin >> result.day) || result.day <= 0 || result.day > dayinMonth[result.month]) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "\033[1A" << "\033[2K"; // Xóa dòng lỗi
        std::cout << "Invalid input! " << prompt; // In lại prompt
    }
    std::cin.ignore(); // Xóa bộ nhớ đệm sau khi nhập xong
    return result;
}

char InputYesNo(){
    std::string prompt = "(y - YES / n - NO): ";
    char option;
    while (!(std::cin >> option) || (option!='n' && option!='y')){
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "\033[1A" << "\033[2K"; // Xóa dòng lỗi
        std::cout << "Invalid input! " << prompt; // In lại prompt
    }
    std::cin.ignore(); // Xóa bộ đệm khi dùng xong
    return option;
}
std::string borderLine = "+----------------------------------------------------------+";




