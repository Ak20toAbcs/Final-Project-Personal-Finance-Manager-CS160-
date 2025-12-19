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
            std::cin.getline(user.userName, 51);
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
            AddWallet(user);
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
                    std::cout << "There is no wallet !" << '\n';
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
                std::cout << "Invalid input!" << '\n';
                PauseScreen();
                return;
            }

            if (EditWallet(user, displayList[option_wallet].id)) {
                return;
            }
            else continue;
            }
}

bool EditWallet(User &user, int walletId) {
    int idx = -1;
    for(int i = 0; i < user.walletList.size; ++i) {
        if(user.walletList[i].id == walletId) {
            idx = i;
            break;
        }
    }

    if(idx == -1){
        return false;
    }

    bool t = true;
    while(t){
        ClearScreen();
        std::cout << borderLine << '\n';
        std::cout << "Wallet " << user.walletList[idx].name << '\n';
        std::cout << "[1] - Edit name                                             " << '\n';
        std::cout << "[2] - Delete Wallet                                         " << '\n';
        std::cout << "[3] - Back                                                  " << '\n';
        int option = InputNumber("Option: ");
        switch (option)
        {
        case 1:{
            std::cout << "Create new name for wallet: ";
            std::cin.ignore(1000, '\n');
            std::cin.getline(user.walletList[idx].name, sizeof(user.walletList[idx].name));
            std::cout << "Sucessful !" << '\n';
            PauseScreen();
            break;
        }
        case 2:{
            std::cout << "Are you sure ? ([1]: Yes / [2]: No)" << '\n';
            int confirm = InputNumber("Option: ");
            if (confirm == 1) {
                user.walletList[idx].isDeleted = true;
                std::cout << "Sucessful !" << '\n';
                PauseScreen();
                return true;
            }
            break;
        }
        case 3:{
            return true;
            break;
        }
        default:
            std::cout << "Invalid input!" << '\n';
            PauseScreen();
            break;
        }
    }
    return true;
}

void AddWallet(User &user) {
    std::cout << "+----------------------Add Wallet-------------------------+" << '\n';

    Wallet newWallet;
    char tempName[100];
    
    std::cout << "Name of Wallet is: ";
    std::cin.getline(tempName, 51);
    strncpy(newWallet.name, tempName, sizeof(newWallet.name)-1);
    newWallet.name[sizeof(newWallet.name) - 1] = '\0';

    int maxId = 0;
    for(int i = 0; i < user.walletList.size; ++i) {
        if(user.walletList[i].id > maxId) maxId = user.walletList[i].id;
    }
    newWallet.id = maxId + 1;
    newWallet.isDeleted = false;

    user.walletList.push_back(newWallet);

    std::cout << "Add Wallet sucessful !" << '\n';
    PauseScreen();
}

void EditIncomeCategory(User& user) {
    ClearScreen();
    std::cout << borderLine << '\n';
    std::cout << "Feature: Edit Income Category is under development." << '\n';
    PauseScreen();
}

void EditExpenseCategory(User& user) {
    ClearScreen();
    std::cout << borderLine << '\n';
    std::cout << "Feature: Edit Expense Category is under development." << '\n';
    PauseScreen();
}
