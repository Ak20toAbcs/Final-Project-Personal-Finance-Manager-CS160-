#include "transaction.h"
#include "system.h"
#include "string"
#include "iostream"

void TransactionPage(User &user){
    bool t = true;
    while(t){
        ClearScreen();
        std::cout << borderLine << '\n';
        std::cout << "+-------------------Transaction Page-----------------------+" << '\n';
        std::cout << "[0] - Add Income                                            " << '\n';
        std::cout << "[1] - Add Expense                                           " << '\n';
        std::cout << "[2] - Back                                                  " << '\n';
        int option = InputNumber("Option: ", 2, 0);
        std::cout << '\n';
        switch (option)
        {
        case 0:{
            if (IncomePage(user)) return;
            break;
        }
        case 1:{
            if (ExpensePage(user)) return;
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

bool IncomePage(User &user){

    bool t = true;
    while(t){
        ClearScreen();
        std::cout << borderLine << '\n';
        std::cout << "+----------------------Income Page-------------------------+" << '\n';
        std::cout << "Choose Wallet:                                              " << '\n';
    
        MyVector<Wallet> displayList;
        for (int i=0; i<user.walletList.size; ++i){
            if (!user.walletList[i].isDeleted)
            displayList.push_back(user.walletList[i]);
        }
    
        // Không có Wallet nào
        if (displayList.size == 0) {
            std::cout << "There is no wallet!" << '\n';
            PauseScreen();
            return false;
        }
        // Có Wallet
        for (int i=0; i<displayList.size; ++i){
            std::cout << "[";
            std::cout << i;
            std::cout << "]";
            std::cout << " - ";
            std::cout << displayList[i].name;
            std::cout << '\n';
        }

        // Nút exit
            std::cout << "[";
            std::cout << displayList.size;
            std::cout << "]";
            std::cout << " - ";
            std::cout << "Back";
            std::cout << '\n';
        int option_wallet = InputNumber("Option: ", displayList.size, 0);
        std::cout << '\n';
        if (option_wallet == displayList.size) return false;

        std::cout << '\n';
        std::cout << "Choose category:" << '\n';
        MyVector<IncomeCategory> incomeList;
        for (int i=0; i<user.incomeList.size; ++i){
            if (!user.incomeList[i].isDeleted){
                incomeList.push_back(user.incomeList[i]);
            }
        }

        // không có Category nào
        if (incomeList.size == 0 ) {
            std::cout << "There is no category!" << '\n';
            PauseScreen();
            return false;
        }

        // Có Wallet
        for (int i=0; i<incomeList.size; ++i){
            std::cout << "[";
            std::cout << i;
            std::cout << "]";
            std::cout << " - ";
            std::cout << incomeList[i].name;
            std::cout << '\n';
        }

        // Nút exit
            std::cout << "[";
            std::cout << incomeList.size;
            std::cout << "]";
            std::cout << " - ";
            std::cout << "Back";
            std::cout << '\n';
        int option_cat = InputNumber("Option: ", incomeList.size, 0);
        std::cout << '\n';
        if (option_cat == incomeList.size) continue;

        std::cout << '\n';

        int amount = InputNumber("Choose amount: ", INT_MAX, 0);
        std::cout << '\n';
        std::cout << '\n';
        std::cout << "Write message: ";
        std::string s; 
        getline(std::cin ,s);

        Date date;
        date = GetCurrentDate();

        std::cout << '\n';
        std::cout << "Use today's date (" 
        << date.day << "/" << date.month << "/" << date.year 
        << ")? (y-YES / n-No): ";
        char option_date = InputYesNo();
        std::cout << '\n';
        if (option_date == 'n') {
            date = InputDate();
            std::cout << '\n';
        }

        AddIncome(user, displayList[option_wallet].id, incomeList[option_cat].id, amount, s, date);

        std::cout << '\n';
        std::cout << "                         Successful!                        " << '\n';
        PauseScreen();
        return true;
    }
}
bool ExpensePage(User &user){
        bool t = true;
    while(t){
        ClearScreen();
        std::cout << borderLine << '\n';
        std::cout << "+----------------------Expense Page-------------------------+" << '\n';
        std::cout << "Choose Wallet:                                              " << '\n';
    
        MyVector<Wallet> displayList;
        for (int i=0; i<user.walletList.size; ++i){
            if (!user.walletList[i].isDeleted)
            displayList.push_back(user.walletList[i]);
        }
    
        // Không có Wallet nào
        if (displayList.size == 0) {
            std::cout << "There is no wallet!" << '\n';
            PauseScreen();
            return false;
        }
        // Có Wallet
        for (int i=0; i<displayList.size; ++i){
            std::cout << "[";
            std::cout << i;
            std::cout << "]";
            std::cout << " - ";
            std::cout << displayList[i].name;
            std::cout << '\n';
        }

        // Nút exit
            std::cout << "[";
            std::cout << displayList.size;
            std::cout << "]";
            std::cout << " - ";
            std::cout << "Back";
            std::cout << '\n';
        
        int option_wallet = InputNumber("Option: ", displayList.size, 0);
        std::cout << '\n';
        if (option_wallet == displayList.size) return false;

        std::cout << '\n';
        std::cout << "Choose category:" << '\n';
        MyVector<ExpenseCategory> expenseList;
        for (int i=0; i<user.expenseList.size; ++i){
            if (!user.expenseList[i].isDeleted){
                expenseList.push_back(user.expenseList[i]);
            }
        }

        // không có Category nào
        if (expenseList.size == 0 ) {
            std::cout << "There is no category!" << '\n';
            PauseScreen();
            return false;
        }

        // Có Wallet
        for (int i=0; i<expenseList.size; ++i){
            std::cout << "[";
            std::cout << i;
            std::cout << "]";
            std::cout << " - ";
            std::cout << expenseList[i].name;
            std::cout << '\n';
        }

        // Nút exit
            std::cout << "[";
            std::cout << expenseList.size;
            std::cout << "]";
            std::cout << " - ";
            std::cout << "Back";
            std::cout << '\n';
        
        int option_cat = InputNumber("Option: ", expenseList.size, 0);
        std::cout << '\n';
        if (option_cat == expenseList.size) return false;

        std::cout << '\n';
        
        int amount = InputNumber("Choose amount: ", INT_MAX, 0);
        std::cout << '\n';
        std::cout << "Write message: ";
        std::string s; 
        getline(std::cin ,s);

        Date date;
        date = GetCurrentDate();

        std::cout << '\n';
        std::cout << "Use today's date (" 
        << date.day << "/" << date.month << "/" << date.year 
        << ")? (y-YES / n-No): ";
        char option_date = InputYesNo();
        std::cout << '\n';
        if (option_date == 'n') {
            date = InputDate();
            std::cout << '\n';
        }

        AddExpense(user, displayList[option_wallet].id, expenseList[option_cat].id, amount, s, date);

        std::cout << '\n';
        std::cout << "                         Successful!                        " << '\n';
        PauseScreen();
        return true;
    }

}

void AddIncome(User &user, int walletID, int catID, int amount, std::string s, Date date){
    int idx = SearchWalletID(user, walletID);
    if (idx == -1) return;
    else user.walletList[idx].money += amount;

    IncomeHistory newIncome;
    newIncome.date = date;
    newIncome.id = user.nextInHis_id++;
    newIncome.idCategory = catID;
    newIncome.idWallet = walletID;
    strncpy(newIncome.message, s.c_str(), sizeof(newIncome.message)-1);
    newIncome.message[sizeof(newIncome.message) - 1] = '\0';
    newIncome.money = amount;

    user.incomeHistory.push_back(newIncome);

    return;
}

void AddExpense(User &user, int walletID, int catID, int amount, std::string s, Date date){
    int idx = SearchWalletID(user, walletID);
    if (idx == -1) return;
    else user.walletList[idx].money -= amount;

    ExpenseHistory newExpense;
    newExpense.date = date;
    newExpense.id = user.nextExpense_id++;
    newExpense.idCategory = catID;
    newExpense.idWallet = walletID;
    strncpy(newExpense.message, s.c_str(), sizeof(newExpense.message)-1);
    newExpense.message[sizeof(newExpense.message) - 1] = '\0';
    newExpense.money = amount;

    user.expenseHistory.push_back(newExpense);

    return;
}