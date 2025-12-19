#include "transaction.h"
#include "system.h"
#include "string"
#include "iostream"
using namespace std;

void TransactionPage(User &user){
    bool t = true;
    while(t){
        ClearScreen();
        cout << borderLine << '\n';
        cout << "+-------------------Transaction Page-----------------------+" << '\n';
        cout << "[1] - Add Income                                            " << '\n';
        cout << "[2] - Add Expense                                           " << '\n';
        cout << "[3] - Back                                                  " << '\n';
        int option = InputNumber("Option: ");
        switch (option)
        {
        case 1:{
            if (IncomePage(user)) t = 0;
            break;
        }
        case 2:{
            if (ExpensePage(user)) t = 0;
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

bool IncomePage(User &user){

    bool t = true;
    while(t){
        ClearScreen();
        cout << borderLine << '\n';
        cout << "+----------------------Income Page-------------------------+" << '\n';
        cout << "Choose Wallet:                                              " << '\n';
    
        MyVector<Wallet> displayList;
        for (int i=0; i<user.walletList.size; ++i){
            if (!user.walletList[i].isDeleted)
            displayList.push_back(user.walletList[i]);
        }
    
        // Không có Wallet nào
        if (displayList.size == 0) {
            cout << "There is no wallet!" << '\n';
            PauseScreen();
            return false;
        }
        // Có Wallet
        for (int i=0; i<displayList.size; ++i){
            cout << "[";
            cout << i;
            cout << "]";
            cout << " - ";
            cout << displayList[i].name;
            cout << '\n';
        }

        // Nút exit
        cout << "[";
            cout << displayList.size;
            cout << "]";
            cout << " - ";
            cout << "Back";
            cout << '\n';
        
        int option_wallet = InputNumber("Option: ");

        if (option_wallet == displayList.size) return false;

        if (option_wallet > displayList.size) {
            cout << "Invalid input!" << '\n';
            PauseScreen();
            return false;
        }

        cout << '\n';
        cout << "Choose category:" << '\n';
        MyVector<IncomeCategory> incomeList;
        for (int i=0; i<user.incomeList.size; ++i){
            if (!user.incomeList[i].isDeleted){
                incomeList.push_back(user.incomeList[i]);
            }
        }

        // không có Category nào
        if (incomeList.size == 0 ) {
            cout << "There is no category!" << '\n';
            PauseScreen();
            return false;
        }

        // Có Wallet
        for (int i=0; i<incomeList.size; ++i){
            cout << "[";
            cout << i;
            cout << "]";
            cout << " - ";
            cout << incomeList[i].name;
            cout << '\n';
        }

        // Nút exit
            cout << "[";
            cout << incomeList.size;
            cout << "]";
            cout << " - ";
            cout << "Back";
            cout << '\n';
        
        int option_cat = InputNumber("Option: ");

        if (option_cat == incomeList.size) return false;
        
        if (option_cat > incomeList.size) {
            cout << "Invalid Input!" << '\n';
            PauseScreen();
            return false;
        }

        cout << '\n';
        int amount = InputNumber("Choose amount: ");

        if (amount<=0) {
            cout << "Invalid income!";
            PauseScreen();
            return false;
        }
        
        cout << '\n';
        cout << "Write message: ";
        string s; 
        getline(cin ,s);

        Date date;
        date = GetCurrentDate();

        cout << '\n';
        cout << "Use today's date (" 
        << date.day << "/" << date.month << "/" << date.year 
        << ")? (y/n): ";

        char option_date;
        while(!(cin >> option_date)) { 
            // 1. Xử lý lỗi như bình thường
            cin.clear(); 
            cin.ignore(1000, '\n'); 

            // 2. Xử lý giao diện:
            // \033[1A: Di chuyển con trỏ lên 1 dòng (lên dòng chứa chữ "abc" vừa nhập sai)
            // \033[2K: Xóa toàn bộ nội dung của dòng hiện tại
            cout << "\033[1A" << "\033[2K"; 
            
            // 3. In lại dòng nhắc lệnh để nhập lại
            cout << "Invalid input!" << "Use today's date (" 
            << date.day << "/" << date.month << "/" << date.year 
            << ")? (y/n): ";
            }

            cin.ignore();

        if (option_date == 'n') {
            date.day = InputNumber("Day: ");

            date.month = InputNumber("Month: ");

            date.year = InputNumber("Year: ");
        }

        AddIncome(user, displayList[option_wallet].id, incomeList[option_cat].id, amount, s, date);

        cout << '\n';
        cout << "Successful!" << '\n';
        PauseScreen();
        return true;
    }
}
bool ExpensePage(User &user){
        bool t = true;
    while(t){
        ClearScreen();
        cout << borderLine << '\n';
        cout << "+----------------------Expense Page-------------------------+" << '\n';
        cout << "Choose Wallet:                                              " << '\n';
    
        MyVector<Wallet> displayList;
        for (int i=0; i<user.walletList.size; ++i){
            if (!user.walletList[i].isDeleted)
            displayList.push_back(user.walletList[i]);
        }
    
        // Không có Wallet nào
        if (displayList.size == 0) {
            cout << "There is no wallet!" << '\n';
            PauseScreen();
            return false;
        }
        // Có Wallet
        for (int i=0; i<displayList.size; ++i){
            cout << "[";
            cout << i;
            cout << "]";
            cout << " - ";
            cout << displayList[i].name;
            cout << '\n';
        }

        // Nút exit
        cout << "[";
            cout << displayList.size;
            cout << "]";
            cout << " - ";
            cout << "Back";
            cout << '\n';
        
        int option_wallet = InputNumber("Option: ");

        if (option_wallet == displayList.size) return false;

        if (option_wallet > displayList.size) {
            cout << "Invalid input!" << '\n';
            PauseScreen();
            return false;
        }

        cout << '\n';
        cout << "Choose category:" << '\n';
        MyVector<ExpenseCategory> expenseList;
        for (int i=0; i<user.expenseList.size; ++i){
            if (!user.expenseList[i].isDeleted){
                expenseList.push_back(user.expenseList[i]);
            }
        }

        // không có Category nào
        if (expenseList.size == 0 ) {
            cout << "There is no category!" << '\n';
            PauseScreen();
            return false;
        }

        // Có Wallet
        for (int i=0; i<expenseList.size; ++i){
            cout << "[";
            cout << i;
            cout << "]";
            cout << " - ";
            cout << expenseList[i].name;
            cout << '\n';
        }

        // Nút exit
            cout << "[";
            cout << expenseList.size;
            cout << "]";
            cout << " - ";
            cout << "Back";
            cout << '\n';
        
        int option_cat = InputNumber("Option: ");

        if (option_cat == expenseList.size) return false;
        
        if (option_cat > expenseList.size) {
            cout << "Invalid Input!" << '\n';
            PauseScreen();
            return false;
        }

        cout << '\n';
        int amount = InputNumber("Choose amount: ");

        if (amount<=0) {
            cout << "Invalid expense!";
            PauseScreen();
            return false;
        }
        
        cout << '\n';
        cout << "Write message: ";
        string s; 
        getline(cin ,s);

        Date date;
        date = GetCurrentDate();

        cout << '\n';
        cout << "Use today's date (" 
        << date.day << "/" << date.month << "/" << date.year 
        << ")? (y/n): ";

        char option_date;
        while(!(cin >> option_date)) { 
            // 1. Xử lý lỗi như bình thường
            cin.clear(); 
            cin.ignore(1000, '\n'); 

            // 2. Xử lý giao diện:
            // \033[1A: Di chuyển con trỏ lên 1 dòng (lên dòng chứa chữ "abc" vừa nhập sai)
            // \033[2K: Xóa toàn bộ nội dung của dòng hiện tại
            cout << "\033[1A" << "\033[2K"; 
            
            // 3. In lại dòng nhắc lệnh để nhập lại
            cout << "Invalid input!" << "Use today's date (" 
            << date.day << "/" << date.month << "/" << date.year 
            << ")? (y/n): ";
            }

            cin.ignore();

        if (option_date == 'n') {
            date.day = InputNumber("Day: ");

            date.month = InputNumber("Month: ");

            date.year = InputNumber("Year: ");
        }

        AddExpense(user, displayList[option_wallet].id, expenseList[option_cat].id, amount, s, date);

        cout << '\n';
        cout << "Successful!" << '\n';
        PauseScreen();
        return true;
    }

}

bool AddIncome(User &user, int walletID, int catID, int amount, string s, Date date){
    bool foundWallet = false;

    for (int i=0; i<user.walletList.size; ++i){
        if (user.walletList[i].id == walletID){
            user.walletList[i].money += amount;
            foundWallet = true;
            break;
        }
    }
    if (!foundWallet) {
        return false;
    }
    IncomeHistory newIncome;
    newIncome.date = date;
    newIncome.id = user.incomeHistory.size;
    newIncome.idCategory = catID;
    newIncome.idWallet = walletID;
    strncpy(newIncome.message, s.c_str(), sizeof(newIncome.message)-1);
    newIncome.money = amount;

    user.incomeHistory.push_back(newIncome);

    return true;

}

bool AddExpense(User &user, int walletID, int catID, int amount, string s, Date date){
        bool foundWallet = false;

    for (int i=0; i<user.walletList.size; ++i){
        if (user.walletList[i].id == walletID){
            user.walletList[i].money -= amount;
            foundWallet = true;
            break;
        }
    }
    if (!foundWallet) {
        return false;
    }
    ExpenseHistory newExpense;
    newExpense.date = date;
    newExpense.id = user.expenseHistory.size;
    newExpense.idCategory = catID;
    newExpense.idWallet = walletID;
    strncpy(newExpense.message, s.c_str(), sizeof(newExpense.message)-1);
    newExpense.money = amount;

    user.expenseHistory.push_back(newExpense);

    return true;
}