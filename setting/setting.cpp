#include "setting.h"
#include "system.h"
#include "string"
#include <iostream>


void SettingPage(User& user) {
    bool t = true;
    while(t){
        ClearScreen();
        std::cout << borderLine << '\n';
        std::cout << "+---------------------Setting Page-------------------------+" << '\n';
        std::cout << "[1] - Edit username                                         " << '\n';
        std::cout << "[2] - Edit Wallet                                           " << '\n';
        std::cout << "[3] - Edit Income Category                                  " << '\n';
        std::cout << "[4] - Edit Expense Category                                 " << '\n';
        std::cout << "[5] - Back                                                  " << '\n';
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
            std::cout << "Invalid input!" << '\n';
            PauseScreen();
            break;
        }
    }
}

void EditUsernamePage(User& user) {
    bool t = true;
    while(t){
        ClearScreen();
        std::cout << borderLine << '\n';
        std::cout << "+------------------Edit Username Page----------------------+" << '\n';
        std::cout << "[1] - Edit Name                                             " << '\n';
        std::cout << "[2] - Back                                                  " << '\n';
        int option = InputNumber("Option: ");
        switch (option)
        {
        case 1:{
            std::cout << "Current username: " << user.userName << '\n';
            std::cout << "New Username: ";
            cin.getline(user.userName, 51);
            std::cout << "Create sucessful !" << '\n';
            PauseScreen();
            break;
        }
        case 2:{
            t = 0;
            break;
        }
        default:
            std::cout << "Invalid input!" << '\n';
            PauseScreen();
            break;
        }
    }
}

void EditWalletPage(User& user) {
    bool t = true;
    while(t){
        ClearScreen();
        std::cout << borderLine << '\n';
        std::cout << "+-------------------Edit Wallet Page-----------------------+" << '\n';
        std::cout << "[1] - Show List Wallet                                      " << '\n';
        std::cout << "[2] - Add Wallet                                            " << '\n';
        std::cout << "[3] - Back                                                  " << '\n';
        int option = InputNumber("Option: ");
        switch (option)
        {
        case 1:{
            EditListWallet(user);
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
            std::cout << "Invalid input!" << '\n';
            PauseScreen();
            break;
        }
    }
}

void EditIncomeCategory(User& user) {

}

void EditExpenseCategory(User& user) {

}

void EditListWallet(User &user) {
    bool t = true;
            while(t){
                ClearScreen();
                std::cout << borderLine << '\n';
                // Hiển thị danh sách các loại ví 
                std::cout << "+-------------------List Wallet Page-----------------------+" << '\n';
                MyVector<Wallet> displayList;

                for(int i = 0; i < user.walletList.size; ++i) {
                    if(!user.walletList[i].isDeleted) {
                        displayList.push_back(user.walletList[i]);
                    }
                }

                // Trường hợp không có wallet
                if (displayList.size == 0) {
                    cout << "There is no wallet !" << '\n';
                    PauseScreen();
                    return;
                }

                // Trường hợp có Wallet
                for (int i=0; i<displayList.size; ++i){
                    std::cout << "[";
                    std::cout << i;
                    std::cout << "]";
                    std::cout << " - ";
                    std::cout << displayList[i].name;
                    std::cout << '\n';
                }

                std::cout << "[";
                std::cout << displayList.size;
                std::cout << "]";
                std::cout << " - ";
                std::cout << "Back";
                std::cout << '\n';
            int option_wallet = InputNumber("Option: ");

            if (option_wallet == displayList.size) {
                return;
            }

            if (option_wallet > displayList.size) {
                cout << "Invalid input!" << '\n';
                PauseScreen();
                return;
            }


            cout << '\n';
            }
}