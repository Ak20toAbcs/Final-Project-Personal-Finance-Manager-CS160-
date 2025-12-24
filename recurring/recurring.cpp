#include "recurring.h"
#include <iostream>
#include "system.h"
#include "transaction.h"

void RecurringPage(User &user) {
    bool t = true;
    while (t) {
        ClearScreen();
        std::cout << borderLine << '\n';
        std::cout << "+----------------------Recurring Page----------------------+" << '\n';
        std::cout << "[0] - Edit recurring " << '\n';
        std::cout << "[1] - Add reccuring" << '\n';
        std::cout << "[2] - Back" << '\n';
        int option = InputNumber("Option: ", 2, 0);
        switch (option)
        {
        case 0:{
            EditRecurring(user);
            break;
        }
        case 1:{
            AddRecurring(user);
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
void AddRecurring(User &user) {
    bool t = true;
    while(t){
        ClearScreen();
        std::cout << borderLine << '\n';
        std::cout << "+---------------------Add Recurring------------------------+" << '\n';
        std::cout << "Choose type of transaction" << '\n';
        std::cout << "[0] - Income" << '\n';
        std::cout << "[1] - Expense" << '\n';
        std::cout << "[2] - Back" << '\n';
        int option_type = InputNumber ("Option: ", 2, 0);
        if (option_type == 2) return;
        std::cout << '\n';

        std::cout << "Choose starting date" << '\n';
        Date st = InputDate();
        std::cout << "Choose ending date" << '\n';
        Date ed = InputDate();
        if (CompareDate(st, ed)>=0){
            std::cout << "Invalid Time Interval!" << '\n';
            PauseScreen();
            return;
        }
        std::cout << '\n';

        MyVector<Wallet> displayList;
        for (int i=0; i<user.walletList.size; ++i){
            if(!user.walletList[i].isDeleted)
            displayList.push_back(user.walletList[i]);
        }
        std::cout << "Choose wallet" << '\n';
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
        int option_wallet = InputNumber("Option: ", displayList.size, 0);
        if (option_wallet == displayList.size) return;
        std::cout << '\n';

            switch (option_type)
            {
            case 0:{
                MyVector<IncomeCategory> inList;
                for (int i=0; i<user.incomeList.size; ++i){
                    if (!user.incomeList[i].isDeleted) 
                    inList.push_back(user.incomeList[i]);
                }
                std::cout << "Choose Category" << '\n';
                for (int i=0; i<inList.size; ++i){
                    std::cout << "[";
                    std::cout << i;
                    std::cout << "]";
                    std::cout << " - ";
                    std::cout << inList[i].name << '\n';
                }
                    std::cout << "[";
                    std::cout << inList.size;
                    std::cout << "]";
                    std::cout << " - ";
                    std::cout << "Back" << '\n';
                    int option_cat = InputNumber("Option: ", inList.size, 0);
                    if (option_cat == inList.size) return;
                    
                    std::cout << '\n';
                    int amount = InputNumber("Choose amount: ", INT_MAX, 0);
    
                    std::cout << '\n';
                    RecurringCategory newRecur;
                    std::cout << "Choose message: ";
                    std::string s;
                    std::getline(std::cin, s);
                    strncpy(newRecur.message, s.c_str(), 100);
                    newRecur.message[100] = '\0';           
                    newRecur.id = user.nextRecur_id++; 
                    newRecur.isExpense = 0;
                    newRecur.inId = inList[option_cat].id;
                    newRecur.walletId = displayList[option_wallet].id;
                    newRecur.money = amount;
                    newRecur.starting = st;
                    newRecur.ending = ed;
                    newRecur.lastUpdate = {0, 0, 0};
                    user.recurList.push_back(newRecur);
                    std::cout << "Add successful!" << '\n';
                    PauseScreen();
                    return;    
                break;
            }
            case 1:{
                MyVector<ExpenseCategory> exList;
                for (int i=0; i<user.expenseList.size; ++i){
                    if (!user.expenseList[i].isDeleted) 
                    exList.push_back(user.expenseList[i]);
                }
                std::cout << "Choose Category" << '\n';
                for (int i=0; i<exList.size; ++i){
                    std::cout << "[";
                    std::cout << i;
                    std::cout << "]";
                    std::cout << " - ";
                    std::cout << exList[i].name << '\n';
                }
                    std::cout << "[";
                    std::cout << exList.size;
                    std::cout << "]";
                    std::cout << " - ";
                    std::cout << "Back" << '\n';
                    int option_cat = InputNumber("Option: ", exList.size, 0);
                    if (option_cat == exList.size) return;
                    
                    std::cout << '\n';
                    int amount = InputNumber("Choose amount: ", INT_MAX, 0);
    
                    std::cout << '\n';
                    RecurringCategory newRecur;
                    std::cout << "Choose message: ";
                    std::string s;
                    std::getline(std::cin, s);
                    strncpy(newRecur.message, s.c_str(), 100);
                    newRecur.message[100] = '\0';           
                    newRecur.id = user.nextRecur_id++;
                    newRecur.isExpense = 1;
                    newRecur.exId = exList[option_cat].id;
                    newRecur.walletId = displayList[option_wallet].id;
                    newRecur.money = amount;
                    newRecur.starting = st;
                    newRecur.ending = ed;
                    newRecur.lastUpdate = {0, 0, 0};
                    user.recurList.push_back(newRecur);
                    std::cout << "Add successful!" << '\n';
                    PauseScreen();
                    return;    
                break;
            }
            default:
                break;
            }
    }
}
void EditRecurring(User &user) {
    bool t = true;
    while (t){
        ClearScreen();
        std::cout << borderLine << '\n';
        std::cout << "+---------------------Edit Recurring-----------------------+" << '\n';
        std::cout << "Choose category to edit" << '\n';
        MyVector<RecurringCategory> displayList;
            for (int i=0; i<user.recurList.size; ++i){
                if (!user.recurList[i].isDeleted){
                    displayList.push_back(user.recurList[i]);
                }
            }

            for (int i=0; i<displayList.size; ++i){
                std::cout << "[";
                std::cout << i;
                std::cout << "]";
                std::cout << " - ";
                std::cout << displayList[i].message << '\n';
            }
                std::cout << "[";
                std::cout << displayList.size;
                std::cout << "]";
                std::cout << " - ";
                std::cout << "Back" << '\n';

            int option_cat = InputNumber("Option: ", displayList.size, 0);
            if (option_cat == displayList.size) return;
            EditCat(user, displayList[option_cat].id);
    }
}

void EditCat(User &user, int catId){
    bool t = true;
    while (t){
        ClearScreen();
        std::cout << borderLine << '\n';
        std::cout << "+---------------------Edit Recurring-----------------------+" << '\n';
        int idx = SearchRecurID(user, catId);
        if (idx==-1) return;
        
        std::cout << "State of recurring: ";
        if (user.recurList[idx].isExpense) std::cout << "Expense" << '\n';
        else std::cout << "Income" << '\n';
        std::cout << "Name: " << user.recurList[idx].message << '\n';
        std::cout << borderLine << '\n';
        std::cout << "[0] - Money" << '\n';
        std::cout << "[1] - Message" << '\n';
        std::cout << "[2] - Wallet" << '\n';
        std::cout << "[3] - Category" << '\n';
        std::cout << "[4] - Delete" << '\n';
        std::cout << "[5] - Back" << '\n';
        int option = InputNumber("Option: ", 5, 0);
        if (option == 5) return;


        switch (option)
        {
        case 0:{
            std::cout << borderLine << '\n';
            std::cout << "Current amount: " << FormatMoney(user.recurList[idx].money) << '\n';
            std::cout << "Change amount? (y - YES / n - NO): ";
            char c = InputYesNo();
            if (c == 'y') {
                int amount = InputNumber("Choose amount: ", INT_MAX, 0);
                user.recurList[idx].money = amount;
                std::cout << "Successful!" << '\n';
                PauseScreen();
            }
            break;
        }
        case 1:{
            std::cout << borderLine << '\n';
            std::cout << "Current message: " << user.recurList[idx].message << '\n';
            std::cout << "Change message? (y - YES / n - NO): ";
            char c = InputYesNo();
            if (c == 'y') {
                std::cout << "Choose message: ";
                std::string s;
                std::getline(std::cin, s);
                strncpy(user.recurList[idx].message, s.c_str(), 100);
                user.recurList[idx].message[100] = '\0';           
                std::cout << "Successful!" << '\n';
                PauseScreen();
            }
            break;
        }
        case 2:{
            std::cout << borderLine << '\n';
            std::cout << "Current wallet: " << user.walletList[SearchWalletID(user, user.recurList[idx].walletId)].name;
            std::cout << "Change wallet? (y - YES / n - NO): ";
            char c = InputYesNo();
            if (c == 'y') {
                MyVector <Wallet> displayList;
                for (int i=0; i<user.walletList.size; ++i){
                    if (!user.walletList[i].isDeleted){
                        displayList.push_back(user.walletList[i]);
                    }
                }
                for (int i=0; i<displayList.size; ++i){
                    std::cout << '[';
                    std::cout << i;
                    std::cout << ']';
                    std::cout << " - ";
                    std::cout << displayList[i].name << '\n';
                }
                std::cout << '[';
                    std::cout << displayList.size;
                    std::cout << ']';
                    std::cout << " - ";
                    std::cout << "Back" << '\n';
                int option = InputNumber("Option: ", displayList.size, 0);
                if (option == displayList.size) break;
                user.recurList[idx].walletId = displayList[option].id;
                std::cout << "Successful!" << '\n';
                PauseScreen();
            }
            break;
        }
        case 3:{
            std::cout << borderLine << '\n';
            if (user.recurList[idx].isExpense){
            std::cout << "Current category: " << user.expenseList[SearchExpenseID(user, user.recurList[idx].exId)].name;
            std::cout << "Change category? (y - YES / n - NO): ";
            char c = InputYesNo();
            if (c == 'y') {
                MyVector <ExpenseCategory> displayList;

                for (int i=0; i<user.expenseList.size; ++i){
                    if (!user.expenseList[i].isDeleted){
                        displayList.push_back(user.expenseList[i]);
                    }
                }
                
                for (int i=0; i<displayList.size; ++i){
                    std::cout << '[';
                    std::cout << i;
                    std::cout << ']';
                    std::cout << " - ";
                    std::cout << displayList[i].name << '\n';
                }
                std::cout << '[';
                    std::cout << displayList.size;
                    std::cout << ']';
                    std::cout << " - ";
                    std::cout << "Back" << '\n';
                int option = InputNumber("Option: ", displayList.size, 0);
                if (option == displayList.size) break;
                user.recurList[idx].exId = displayList[option].id;
                std::cout << "Successful!" << '\n';
                PauseScreen();
            }
            }
            else {
            std::cout << "Current category: " << user.incomeList[SearchIncomeID(user, user.recurList[idx].inId)].name;
            std::cout << "Change category? (y - YES / n - NO): ";
            char c = InputYesNo();
            if (c == 'y') {
                MyVector <IncomeCategory> displayList;

                for (int i=0; i<user.incomeList.size; ++i){
                    if (!user.incomeList[i].isDeleted){
                        displayList.push_back(user.incomeList[i]);
                    }
                }
                
                for (int i=0; i<displayList.size; ++i){
                    std::cout << '[';
                    std::cout << i;
                    std::cout << ']';
                    std::cout << " - ";
                    std::cout << displayList[i].name << '\n';
                }
                std::cout << '[';
                    std::cout << displayList.size;
                    std::cout << ']';
                    std::cout << " - ";
                    std::cout << "Back" << '\n';
                int option = InputNumber("Option: ", displayList.size, 0);
                if (option == displayList.size) break;
                int idx_cat = SearchIncomeID(user, displayList[option].id);
                user.recurList[idx].inId = displayList[option].id;
                std::cout << "Successful!" << '\n';
                PauseScreen();
            }
            }
            break;
        }
        case 4:{
            std::cout << borderLine << '\n';
            std::cout << "Are you sure to delete it (y - YES / n - NO): ";
            char c = InputYesNo();
            if (c=='y') {
                user.recurList[idx].isDeleted = true;
                std::cout << "Delete Successful!" << '\n';
                PauseScreen();
                return;
            }
        }
        default:
            break;
        }
    }
    
}

void LoadRecur(User &user){
    Date curDate = GetCurrentDate();
    for (int i=0; i<user.recurList.size; ++i){
        if (!user.recurList[i].isDeleted) {
            Date lastCheck = user.recurList[i].lastUpdate;
            if (curDate.month == lastCheck.month && curDate.year == lastCheck.year) {
                continue;
            }
            if (user.recurList[i].isExpense){
                AddExpense(user, user.recurList[i].walletId, user.recurList[i].exId, user.recurList[i].money, 
                user.recurList[i].message, curDate);
                user.recurList[i].lastUpdate = curDate;
            }
            else {
                AddIncome(user, user.recurList[i].walletId, user.recurList[i].inId, user.recurList[i].money, 
                user.recurList[i].message, curDate);
                user.recurList[i].lastUpdate = curDate;
            }
        }
    }
}