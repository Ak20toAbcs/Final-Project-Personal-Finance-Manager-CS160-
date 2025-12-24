#include "setting.h"
#include "system.h"
#include <string>
#include <cstring>
#include <iostream>

void SettingPage(User& user) {
    bool t = true;
    while(t){
        ClearScreen();
        std::cout << borderLine << '\n';
        std::cout << "+---------------------Setting Page-------------------------+" << '\n';
        std::cout << "[0] - Edit username                                         " << '\n';
        std::cout << "[1] - Edit Wallet                                           " << '\n';
        std::cout << "[2] - Edit Income Category                                  " << '\n';
        std::cout << "[3] - Edit Expense Category                                 " << '\n';
        std::cout << "[4] - Back                                                  " << '\n';
        int option = InputNumber("Option: ", 4, 0);
        switch (option)
        {
        case 0:{
            EditUsernamePage(user);
            break;
        }
        case 1:{
            EditWalletPage(user);
            break;
        }
        case 2:{
            EditIncomeCategory(user);
            break;
        }
        case 3:{
            EditExpenseCategory(user);
            break;
        }
        case 4:{
            return;
            break;
        }
        default:
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
        std::cout << "[0] - Edit Name                                             " << '\n';
        std::cout << "[1] - Back                                                  " << '\n';
        int option = InputNumber("Option: ", 1, 0);
        switch (option)
        {
        case 0:{
            std::cout << "Current username: " << user.userName << '\n';
            std::cout << "New Username: ";
            std::string s; 
            std::getline(std::cin, s);
            strncpy(user.userName, s.c_str(), 50);
            user.userName[50] = '\0';
            std::cout << "Create sucessful !" << '\n';
            PauseScreen();
            break;
        }
        case 1:{
            return;
            break;
        }
        default:
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
        std::cout << "[0] - Edit Wallet                                      " << '\n';
        std::cout << "[1] - Add Wallet                                            " << '\n';
        std::cout << "[2] - Back                                                  " << '\n';
        int option = InputNumber("Option: ", 2, 0);
        switch (option)
        {
        case 0:{
            EditListWallet(user);
            break;
        }
        case 1:{
            AddWallet(user);
            break;
        }
        case 2:{
            return;
            break;
        }
        default:
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

                std::cout << "Choose wallet to edit" << '\n';

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
            int option_wallet = InputNumber("Option: ", displayList.size, 0);

            if (option_wallet == displayList.size) {
                return;
            }

            EditWallet(user, displayList[option_wallet].id);
            }
}

void EditWallet(User &user, int walletId) {
    int idx = SearchWalletID(user, walletId);

    if(idx == -1){
        return;
    }

    bool t = true;
    while(t){
        ClearScreen();
        std::cout << borderLine << '\n';
        std::cout << "Wallet " << user.walletList[idx].name << '\n';
        std::cout << "[0] - Edit name                                             " << '\n';
        std::cout << "[1] - Delete Wallet                                         " << '\n';
        std::cout << "[2] - Back                                                  " << '\n';
        int option = InputNumber("Option: ", 2, 0);
        switch (option)
        {
        case 0:{
            std::cout << "Create new name for wallet: ";
            std::string s; 
            std::getline(std::cin, s);
            strncpy(user.walletList[idx].name, s.c_str(), 50);
            user.walletList[idx].name[50] = '\0';
            std::cout << "Sucessful !" << '\n';
            PauseScreen();
            break;
        }
        case 1:{
            std::cout << "Are you sure ? (y - Yes / n -  No): ";
            char confirm = InputYesNo();
            if (confirm == 'y') {
                user.walletList[idx].isDeleted = true;
                std::cout << "Sucessful !" << '\n';
                PauseScreen();
                return;
            }
            break;
        }
        case 2:{
            return;
            break;
        }
        default:
            break;
        }
    }
    return;
}

void AddWallet(User &user) {
    std::cout << "+----------------------Add Wallet-------------------------+" << '\n';

    Wallet newWallet;

    std::cout << "Name of Wallet is: ";
    std::string s; 
    std::getline(std::cin, s);
    strncpy(newWallet.name, s.c_str(), 50);
    newWallet.name[50] = '\0';

    newWallet.id = user.nextWallet_id++;
    newWallet.isDeleted = false;

    user.walletList.push_back(newWallet);

    std::cout << '\n';
    std::cout << "Add Wallet sucessful !" << '\n';
    PauseScreen();
}


void EditCategoryPage(User &user){
    bool t = true;
    while (t){
        ClearScreen();
    std::cout << borderLine << '\n';
    std::cout << "+---------------------Category Page------------------------+" << '\n';
    std::cout << "[0] - Edit Income Category" << '\n';
    std::cout << "[1] - Edit Expense Category" << '\n';
    std::cout << "[2] - Back" << '\n';

    int option = InputNumber("Option: ", 2, 0);
    switch (option)
    {
    case 0:{
        EditIncomeCategory(user);
        break;
    }
    case 1:{
        EditExpenseCategory(user);
        break;
    }
    case 2:{
        return;
        break;
    }
    default:
        break;
    }
    }
}

void EditIncomeCategory(User& user) {
    bool t = true;
    while (t){
        ClearScreen();
        std::cout << borderLine << '\n';
        std::cout << "+------------------Income Category Page--------------------+" << '\n';
        std::cout << "[0] - Edit/Delete Income category" << '\n';
        std::cout << "[1] - Add Income category" << '\n';
        std::cout << "[2] - Back" << '\n';
        int option = InputNumber("Option: ", 2, 0);
        switch (option)
        {
        case 0:{
            ShowInCat(user);
            break;
        }
        case 1:{
            AddIncomeCat(user);
            break;
        }
        case 2:{
            return;
            break;
        }
        default:
            break;
        }
    }
}

void EditExpenseCategory(User& user) {
    bool t = true;
    while (t){
        ClearScreen();
        std::cout << borderLine << '\n';
        std::cout << "+------------------Expense Category Page-------------------+" << '\n';
        std::cout << "[0] - Edit/Delete Expense category" << '\n';
        std::cout << "[1] - Add Expense category" << '\n';
        std::cout << "[2] - Back" << '\n';
        int option = InputNumber("Option: ", 2, 0);
        switch (option)
        {
        case 0:{
            ShowExCat(user);
            break;
        }
        case 1:{
            AddExpenseCat(user);
            break;
        }
        case 2:{
            return;
            break;
        }
        default:
            break;
        }
    }
}

void AddIncomeCat(User &user) {
    std::cout << "+------------------Add Income Category---------------------+" << '\n';

    IncomeCategory newCat;
    
    std::cout << "Name of Category is: ";
    std::string s; 
    std::getline(std::cin, s);
    strncpy(newCat.name, s.c_str(), 50);
    newCat.name[50] = '\0';

    newCat.id = user.nextIncome_id++;

    user.incomeList.push_back(newCat);

    std::cout << "Add Category sucessful !" << '\n';
    PauseScreen();
}

void AddExpenseCat(User &user) {
    std::cout << "+------------------Add Expense Category--------------------+" << '\n';

    ExpenseCategory newCat;
    
    std::cout << "Name of Category is: ";
    std::string s; 
    std::getline(std::cin, s);
    strncpy(newCat.name, s.c_str(), 50);
    newCat.name[50] = '\0';

    newCat.id = user.nextExpense_id++;

    user.expenseList.push_back(newCat);

    std::cout << "Add Category sucessful !" << '\n';
    PauseScreen();
}

void ShowInCat (User &user) {
    bool t = true;
    while (t){
        ClearScreen();
        std::cout << borderLine << '\n';
        std::cout << "+------------------Income Category Page--------------------+" << '\n';
        std::cout << "Choose category" << '\n';

        MyVector<IncomeCategory> displayList;
        for (int i=0; i<user.incomeList.size; ++i){
            if (!user.incomeList[i].isDeleted){
                displayList.push_back(user.incomeList[i]);
            }
        }

        if (displayList.size == 0) {
            std::cout << "There is no category" << '\n';
        }

        for (int i=0; i<displayList.size; ++i){
            std::cout << "[";
            std::cout << i;
            std::cout << "]";
            std::cout << " - ";
            std::cout << displayList[i].name << '\n';
        }
        std::cout << "[";
        std::cout << displayList.size;
        std::cout << "]";
        std::cout << " - ";
        std::cout << "Back" << '\n';

        int option = InputNumber("Option: ", displayList.size, 0);

        if (option == displayList.size) return;
        EditIn(user, displayList[option].id);
    }
}

void EditIn(User &user, int idCat) {
    bool t = true;
    while (t){
        ClearScreen();
        std::cout << borderLine << '\n';
        std::cout << "+------------------Income Category Page--------------------+" << '\n';
        int idx = SearchIncomeID(user, idCat);

        if (idx == -1) return;
        std::cout << "Category: " << user.incomeList[idx].name << '\n';
        std::cout << "[0] - Edit name" << '\n';
        std::cout << "[1] - Delete category" << '\n';
        std::cout << "[2] - Back" << '\n';
        int option = InputNumber("Option: ", 2, 0);
        switch (option)
        {
        case 0:{
            std::cout << "Create new name for category: ";
            std::string s; 
            std::getline(std::cin, s);
            strncpy(user.incomeList[idx].name, s.c_str(), 50);
            user.incomeList[idx].name[50] = '\0';

            std::cout << "Sucessful !" << '\n';
            PauseScreen();
            break;
        }
        case 1:{
            std::cout << "Are you sure ? (y - Yes / n -  No): ";
            char confirm = InputYesNo();
            if (confirm == 'y') {
                user.incomeList[idx].isDeleted = true;
                std::cout << "Sucessful !" << '\n';
                PauseScreen();
                return;
            }
            break;
        }
        case 2:{
            return;
            break;
        }
        default:
            break;
        } 
    }
}

void ShowExCat (User &user) {
    bool t = true;
    while (t){
        ClearScreen();
        std::cout << borderLine << '\n';
        std::cout << "+------------------Expense Category Page-------------------+" << '\n';
        std::cout << "Choose category" << '\n';

        MyVector<ExpenseCategory> displayList;
        for (int i=0; i<user.expenseList.size; ++i){
            if (!user.expenseList[i].isDeleted){
                displayList.push_back(user.expenseList[i]);
            }
        }

        if (displayList.size == 0) {
            std::cout << "There is no category" << '\n';
        }

        for (int i=0; i<displayList.size; ++i){
            std::cout << "[";
            std::cout << i;
            std::cout << "]";
            std::cout << " - ";
            std::cout << displayList[i].name << '\n';
        }
        std::cout << "[";
        std::cout << displayList.size;
        std::cout << "]";
        std::cout << " - ";
        std::cout << "Back" << '\n';

        int option = InputNumber("Option: ", displayList.size, 0);

        if (option == displayList.size) return;
        EditEx(user, displayList[option].id);
    }
}

void EditEx(User &user, int idCat) {
    bool t = true;
    while (t){
        ClearScreen();
        std::cout << borderLine << '\n';
        std::cout << "+------------------Expense Category Page-------------------+" << '\n';
        int idx = SearchExpenseID(user, idCat);

        if (idx == -1) return;
        std::cout << "Category: " << user.expenseList[idx].name << '\n';
        std::cout << "[0] - Edit name" << '\n';
        std::cout << "[1] - Delete category" << '\n';
        std::cout << "[2] - Back" << '\n';
        int option = InputNumber("Option: ", 2, 0);
        switch (option)
        {
        case 0:{
            std::cout << "Create new name for category: ";
            std::string s; 
            std::getline(std::cin, s);
            strncpy(user.expenseList[idx].name, s.c_str(), 50);
            user.expenseList[idx].name[50] = '\0';
            std::cout << "Sucessful !" << '\n';
            PauseScreen();
            break;
        }
        case 1:{
            std::cout << "Are you sure ? (y - Yes / n -  No): ";
            char confirm = InputYesNo();
            if (confirm == 'y') {
                user.expenseList[idx].isDeleted = true;
                std::cout << "Sucessful !" << '\n';
                PauseScreen();
                return;
            }
            break;
        }
        case 2:{
            return;
            break;
        }
        default:
            break;
        } 
    }
}