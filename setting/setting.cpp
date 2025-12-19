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
    bool t = true;
    while(t){
        ClearScreen();
        cout << borderLine << '\n';
        cout << "+------------------Edit Username Page----------------------+" << '\n';
        cout << "[1] - Edit Name                                             " << '\n';
        cout << "[2] - Back                                                  " << '\n';
        int option = InputNumber("Option: ");
        switch (option)
        {
        case 1:{
            cout << "Current username: " << user.userName << '\n';
            cout << "New Username: ";
            cin.getline(user.userName, 51);
            cout << "Create sucessful !" << '\n';
            PauseScreen();
            break;
        }
        case 2:{
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

void EditWalletPage(User& user) {
    bool t = true;
    while(t){
        ClearScreen();
        cout << borderLine << '\n';
        cout << "+-------------------Edit Wallet Page-----------------------+" << '\n';
        cout << "[1] - Show List Wallet                                      " << '\n';
        cout << "[2] - Add Wallet                                            " << '\n';
        cout << "[3] - Back                                                  " << '\n';
        int option = InputNumber("Option: ");
        switch (option)
        {
        case 1:{
            bool t1 = true;
            while(t1){
                ClearScreen();
                cout << borderLine << '\n';
                // Hiển thị danh sách các loại ví 
                cout << "+-------------------List Wallet Page-----------------------+" << '\n';
                MyVector<Wallet> displayList;
                for (int i=0; i<user.walletList.size; ++i){
                    if (!user.walletList[i].isDeleted) cout << "[ " << i + 1 << " ] - " << user.walletList[i].name << '\n';
                }
                cout << "[0] - Back                                                  " << '\n';

                cout << "Choose Wallet:                                              " << '\n';
                int option = InputNumber("Option: ");
                switch (option)
                {
                case 1:{
                    t1 = 0;
                    break;
                }
                case 2:{
                    
                }
                default:
                    cout << "Invalid input!" << '\n';
                    PauseScreen();
                    break;
                }
            }
                    break;
        }
        case 2:{
            
            break;
        }
        case 3:{
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

void EditIncomeCategory(User& user) {

}

void EditExpenseCategory(User& user) {

}
