#include "setting.h"
#include "system.h"
#include "string"
#include "iostream"
using namespace std;

void SettingPage(User& user) {
    bool t = true;
    while(t){
        ClearScreen();
        cout << borderLine << '\n';
        cout << "+---------------------Setting Page-------------------------+" << '\n';
        cout << "[1] - Edit username                                         " << '\n';
        cout << "[2] - Edit Wallet                                           " << '\n';
        cout << "[3] - Edit Income Category                                  " << '\n';
        cout << "[4] - Edit Expense Category                                 " << '\n';
        cout << "[5] - Back                                                  " << '\n';
        int option = InputNumber("Option: ");
        switch (option)
        {
        case 1:{
            EditUsernamePage(user);
            break;
        }
        case 2:{
            EditWalletPage(user);
            break;
        }
        case 3:{
            EditIncomeCategory(user);
            break;
        }
        case 4:{
            EditExpenseCategory(user);
            break;
        }
        case 5:{
            t = 0;
            break;
        }
        default:
            cout << "Invalid input!" << '\n';
            PauseScreen();
            break;
        }
    }
}

void EditUsernamePage(User& user) {
    
}

void EditWalletPage(User& user) {

}

void EditIncomeCategory(User& user) {

}

void EditExpenseCategory(User& user) {

}
