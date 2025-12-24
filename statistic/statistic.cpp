#include <iostream>
#include <iomanip>
#include "statistic.h"
#include "system.h"
#include "user_data.h"

void StatisticPage(User &user){
    bool t = true;
    while(t){
        ClearScreen();
        std::cout << borderLine << '\n';
        std::cout << "+--------------------Statistic Page------------------------+" << '\n';
        std::cout << "[0] - Overall                                               " << '\n';
        std::cout << "[1] - Income Breakdown                                      " << '\n';
        std::cout << "[2] - Expense Breakdown                                     " << '\n';
        std::cout << "[3] - Wallet                                                " << '\n';
        std::cout << "[4] - History                                               " << '\n';
        std::cout << "[5] - Annual Analysis                                       " << '\n';
        std::cout << "[6] - Back                                                  " << '\n';
        int option = InputNumber("Option: ", 6, 0);
        Date bd = {0,0,0};
        Date kt = {INT_MAX, INT_MAX, INT_MAX};
        switch (option)
        {
        case 0:{
            OverallPage(user, bd, kt);
            break;
        }
        case 1:{
            IncomeBreakdown(user, bd, kt);
            break;
        }
        case 2:{
            ExpenseBreakdown(user, bd, kt);
            break;
        }
        case 3:{
            WalletStat(user, bd, kt, -1);
            break;
        }
        case 4:{
            HistoryStat(user, bd, kt, -1);
            break;
        }
        case 5:{
            MyVector<Date> temp;
            AnnualAnalysis(user, temp);
            break;
        }
        case 6:{
            return;
            break;
        }
        default:{
            break;
        }
        }
    }
}
void OverallPage(User &user, Date &bd, Date &kt){
    Date default_bd = {0,0,0}; 
    Date default_kt = {INT_MAX, INT_MAX, INT_MAX};
    bool t = true; 
    while (t){
        ClearScreen();
        std::cout << borderLine << '\n';
        std::cout << "+---------------------Overall Page-------------------------+" << '\n';
        if (CompareDate(bd, default_bd) == 0) {
            std::cout << "Date: All time" << '\n'; 
        }
        else {
            std::cout << "From: " << bd.day << '/' << bd.month << '/' << bd.year << '\n';
            std::cout << "To:   " << kt.day << '/' << kt.month << '/' << kt.year << '\n';
        }
        int income = 0;
        int expense = 0;
        for (int i=0; i<user.incomeHistory.size; ++i){
            if (user.incomeHistory[i].isDeleted) continue;
            Date temp = user.incomeHistory[i].date;
            if (CompareDate(temp, bd) >= 0 && CompareDate(temp, kt) <= 0)
            income += user.incomeHistory[i].money;
        }
        for (int i=0; i<user.expenseHistory.size; ++i){
            if (user.expenseHistory[i].isDeleted) continue;
            Date temp = user.expenseHistory[i].date;
            if (CompareDate(temp, bd) >= 0 && CompareDate(temp, kt) <= 0)
            expense += user.expenseHistory[i].money;
        }

        DisplayNameWithMoney("Net Balance", income-expense);
        DisplayNameWithMoney("Total Income", income);
        DisplayNameWithMoney("Total Expense", expense);
        std::cout << borderLine << '\n';
        std::cout << "[0] - Choose specific time" << '\n';
        std::cout << "[1] - Back" << '\n';
        int option = InputNumber("Option: ", 1, 0);
        switch (option)
        {
        case 0:{
            std::cout << "Input starting date..." << '\n';
            Date bg = InputDate();
            std::cout << "Input ending date..." << '\n';
            Date ed = InputDate();
            if (CompareDate(bg, ed) >= 0) {
                std::cout << "Invalid Time Interval!" << '\n';
                PauseScreen();
                return;
            }
            OverallPage(user, bg, ed);
            return;
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

void IncomeBreakdown (User &user, Date &bd, Date &kt){
    Date default_bd = {0,0,0}; 
    Date default_kt = {INT_MAX, INT_MAX, INT_MAX};
    bool t = true; 
    while (t){
        ClearScreen();
        std::cout << borderLine << '\n';
        std::cout << "+-------------------Income Breakdown-----------------------+" << '\n';
        if (CompareDate(bd, default_bd) == 0) {
            std::cout << "Date: All time" << '\n'; 
        }
        else {
            std::cout << "From: " << bd.day << '/' << bd.month << '/' << bd.year << '\n';
            std::cout << "To:   " << kt.day << '/' << kt.month << '/' << kt.year << '\n';
        }

        int* cntInCat = new int [user.incomeList.size]();
        int total = 0;
        for (int i=0; i<user.incomeHistory.size; ++i){
            if (!user.incomeHistory[i].isDeleted){
                Date temp = user.incomeHistory[i].date;
                if (CompareDate(temp, bd)>=0 && CompareDate(temp, kt)<=0){
                    cntInCat[user.incomeHistory[i].idCategory] += user.incomeHistory[i].money;
                    total += user.incomeHistory[i].money;
                }
            }
        }

        std::cout << borderLine << '\n';
        DisplayNameWithMoney("Total Income", total);
        for (int i=0; i<user.incomeList.size; ++i){
            if (!user.incomeList[i].isDeleted) {
                DisplayNameWithMoney(user.incomeList[i].name, cntInCat[user.incomeList[i].id]);
            }
        }

        std::cout << borderLine << '\n';
        delete[] cntInCat;

        std::cout << "[0] - Choose specific time" << '\n';
        std::cout << "[1] - Back                " << '\n';
        int option = InputNumber("Option: ", 1, 0);
        switch (option)
        {
        case 0:{
            std::cout << "Input starting date..." << '\n';
            Date bg = InputDate();
            std::cout << "Input ending date..." << '\n';
            Date ed = InputDate();
            if (CompareDate(bg, ed) >=0) {
                std::cout << "Invalid Time Interval!" << '\n';
                PauseScreen();
                return;
            }
            IncomeBreakdown(user, bg, ed);
            return;
            break;
        }
        case 1:{
            return;
            break;
        }
        default:
            break;
        }

        return;
    }
}

void ExpenseBreakdown (User &user, Date &bd, Date &kt){
    Date default_bd = {0,0,0}; 
    Date default_kt = {INT_MAX, INT_MAX, INT_MAX};
    bool t = true; 
    while (t){
        ClearScreen();
        std::cout << borderLine << '\n';
        std::cout << "+-------------------Expense Breakdown----------------------+" << '\n';
        if (CompareDate(bd, default_bd) == 0) {
            std::cout << "Date: All time" << '\n'; 
        }
        else {
            std::cout << "From: " << bd.day << '/' << bd.month << '/' << bd.year << '\n';
            std::cout << "To:   " << kt.day << '/' << kt.month << '/' << kt.year << '\n';
        }

        int* cntExCat = new int [user.expenseList.size]();
        int total = 0;
        for (int i=0; i<user.expenseHistory.size; ++i){
            if (!user.expenseHistory[i].isDeleted){
                Date temp = user.expenseHistory[i].date;
                if (CompareDate(temp, bd)>=0 && CompareDate(temp, kt)<=0){
                    cntExCat[user.expenseHistory[i].idCategory] += user.expenseHistory[i].money;
                    total += user.expenseHistory[i].money;
                }
            }
        }

        std::cout << borderLine << '\n';
        DisplayNameWithMoney("Total Expense", total);
        for (int i=0; i<user.expenseList.size; ++i){
            if (!user.expenseList[i].isDeleted) {
                DisplayNameWithMoney(user.expenseList[i].name, cntExCat[user.expenseList[i].id]);
            }
        }

        std::cout << borderLine << '\n';
        delete[] cntExCat;

        std::cout << "[0] - Choose specific time" << '\n';
        std::cout << "[1] - Back                " << '\n';
        int option = InputNumber("Option: ", 1, 0);
        switch (option)
        {
        case 0:{
            std::cout << "Input starting date..." << '\n';
            Date bg = InputDate();
            std::cout << "Input ending date..." << '\n';
            Date ed = InputDate();
            if (CompareDate(bg, ed) >=0){
                std::cout << "Invalid Time Interval!" << '\n';
                PauseScreen();
                return;
            }
            ExpenseBreakdown(user, bg, ed);
            return;
            break;
        }
        case 1:{
            return;
            break;
        }
        default:
            break;
        }

        return;
    }
}

void WalletStat(User& user, Date &bd, Date &kt, int id){
    Date default_bd = {0,0,0}; 
    Date default_kt = {INT_MAX, INT_MAX, INT_MAX};
    bool t = true; 
    while (t){
        ClearScreen();
        std::cout << borderLine << '\n';
        std::cout << "+--------------------Wallet Breakdown----------------------+" << '\n';
        if (CompareDate(bd, default_bd) == 0) {
            std::cout << "Date: All time" << '\n'; 
        }
        else {
            std::cout << "From: " << bd.day << '/' << bd.month << '/' << bd.year << '\n';
            std::cout << "To:   " << kt.day << '/' << kt.month << '/' << kt.year << '\n';
        }
        
        std::cout << borderLine << '\n';
        if (id == -1) {
            MyVector <Wallet> displayList;
            for (int i=0; i<user.walletList.size; ++i){
                if (!user.walletList[i].isDeleted){
                    displayList.push_back(user.walletList[i]);
                }
            }
            if (displayList.size == 0) std::cout << "There is no wallet!" << '\n';
            else std::cout << "Choose wallet" << '\n';
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
            std::cout << "Back" << "\n";

            int option = InputNumber("Option: ", displayList.size, 0);

            if (option  == displayList.size) return;
            else {
                WalletStat(user, bd, kt, displayList[option].id);
            }
        }
        else {
            Wallet displayWallet;
            int idx = SearchWalletID(user, id);
            displayWallet = user.walletList[idx];
            
            int income = 0;
            for (int i=0; i<user.incomeHistory.size; ++i){
                if (user.incomeHistory[i].isDeleted == false && user.incomeHistory[i].idWallet == id){
                    Date temp = user.incomeHistory[i].date;
                    if (CompareDate(temp, bd)>=0 && CompareDate(temp, kt)<=0)
                    income += user.incomeHistory[i].money;
                }
            }
            int expense = 0;
            for (int i=0; i<user.expenseHistory.size; ++i){
                if (user.expenseHistory[i].isDeleted == false && user.expenseHistory[i].idWallet == id){
                    Date temp = user.expenseHistory[i].date;
                    if (CompareDate(temp, bd)>=0 && CompareDate(temp, kt)<=0)
                    expense += user.expenseHistory[i].money;
                }
            }
            std::cout << "Wallet: " << displayWallet.name << '\n';
            DisplayNameWithMoney("Income", income);
            DisplayNameWithMoney("Expense", expense);
            DisplayNameWithMoney("Net Balance", income - expense);

            std::cout << "[0] - Choose specific time" << '\n';
            std::cout << "[1] - Back" << '\n';
            int option = InputNumber("Option: ", 1, 0);
            switch (option)
            {
            case 0:{
                std::cout << "Input starting date..." << '\n';
                Date bg = InputDate();
                std::cout << "Input ending date..." << '\n';
                Date ed = InputDate();
                if (CompareDate(bg, ed)>=0){
                    std::cout << "Invalid Time Interval!" << '\n';
                    PauseScreen();
                    return;
                }
                WalletStat(user, bg, ed, id);
                return;
                break;
            }
            case 1:{
                return;
            }
            default:
                break;
            }
        }

    }
}

void HistoryStat(User& user, Date &bd, Date &kt, int state) {
    Date default_bd = {0,0,0}; 
    Date default_kt = {INT_MAX, INT_MAX, INT_MAX};   
    bool t = true; 
    while (t){
        ClearScreen();
        std::cout << borderLine << '\n';
        std::cout << "+-------------------------History--------------------------+" << '\n';
        if (CompareDate(bd, default_bd) == 0) {
            std::cout << "Date: All time" << '\n'; 
        }
        else {
            std::cout << "From: " << bd.day << '/' << bd.month << '/' << bd.year << '\n';
            std::cout << "To:   " << kt.day << '/' << kt.month << '/' << kt.year << '\n';
        }
        
        std::cout << borderLine << '\n';
        if (state == -1) {
            std::cout << "[0] - All History" << '\n';
            std::cout << "[1] - Income History" << '\n';
            std::cout << "[2] - Expense History" << '\n';
            std::cout << "[3] - Back" << '\n';
            int option = InputNumber("Option: ", 3, 0);
            switch (option)
            {
            case 0: {
                HistoryStat(user, bd, kt, 0);
                break;
            }
            case 1: {
                HistoryStat(user, bd, kt, 1);
                break;
            }
            case 2: {
                HistoryStat(user, bd, kt, 2);
                break;
            }
            case 3: {
                return;
                break;
            }
            default:
                break;
            }
        }
        if (state == 0){
            showIncomeHistory(user, bd, kt);
            showExpenseHistory(user, bd, kt);
            std::cout << "[0] - Back" << '\n';
            int option = InputNumber("Option: ", 0, 0);
            return;
        }
        if (state == 1){
            showIncomeHistory(user, bd, kt);
            std::cout << "[0] - Back" << '\n';
            int option = InputNumber("Option: ", 0, 0);
            return;
        }
        if (state == 2){
            showExpenseHistory(user, bd, kt);
            std::cout << "[0] - Back" << '\n';
            int option = InputNumber("Option: ", 0, 0);
            return;
        }
    } 
    
}

void AnnualAnalysis(User &user, MyVector<Date> &listYear){
    bool t = true;
    while (t){
        ClearScreen();
        std::cout << borderLine << '\n';
        std::cout << "+--------------------Annual Analysis-----------------------+" << '\n';
            std::cout << "[0] - Net Balance" << '\n';
            std::cout << "[1] - Income" << '\n';
            std::cout << "[2] - Expense" << '\n';
            std::cout << "[3] - Back" << '\n';
            int option = InputNumber("Option: ", 3, 0);
            switch (option)
            {
            case 0:{
                NetAnnual(user, listYear);
                break;
            }
            case 1:{
                IncomeAnnual(user, listYear);
                break;
            }
            case 2:{
                ExpenseAnnual(user, listYear);
                break;
            }
            case 3:{
                return;
                break;
            }
            default:
                break;
            }
        }
}

void NetAnnual(User &user, MyVector<Date> &listYear) {
    bool t = true;
    while(t){
        ClearScreen();
        std::cout << borderLine << '\n';
        std::cout << "+------------------Net Balance Analysis--------------------+" << '\n';
        if (listYear.size == 0) {

            std::cout << "[0] - Choose years to analyze" << '\n';
            std::cout << "[1] - Back" << '\n';
            int option = InputNumber("Option: ", 1, 0);
            if (option == 1) return;
            MyVector<Date> inputYear;
            int n = InputNumber("Choose the number of years to analyze (max - 1000): ", 1000, 1);
            for (int i=1; i<=n; ++i){
                std::cout << "Enter year " << i << '\n';
                int year = InputNumber("Year: ", INT_MAX, 1);
                inputYear.push_back({0, 0, year});
            } 
            NetAnnual(user, inputYear);
        }
        else {
            for (int i=0; i<listYear.size; ++i) {
                int year = listYear[i].year;
                int income = 0;
                int expense = 0;
                for (int j=0; j<user.incomeHistory.size; ++j){
                    if (user.incomeHistory[j].isDeleted == false && user.incomeHistory[j].date.year == year)
                    income+= user.incomeHistory[j].money;
                }
                for (int j=0; j<user.expenseHistory.size; ++j){
                    if (user.expenseHistory[j].isDeleted == false && user.expenseHistory[j].date.year == year)
                    expense+= user.expenseHistory[j].money;
                }
                std::cout << "Year: " << year << '\n';
                DisplayNameWithMoney("Income", income);
                DisplayNameWithMoney("Expense", expense);
                DisplayNameWithMoney("Net Balance", income - expense);
                std::cout << borderLine << '\n';

            }
            std::cout << "[0] - Back" <<'\n';
            int option = InputNumber("Option: ", 0, 0);
            if (option == 0) return;
        } 
    }
}

void IncomeAnnual(User &user, MyVector<Date> &listYear){
    bool t = true;
    while(t){
        ClearScreen();
        std::cout << borderLine << '\n';
        std::cout << "+-----------------Income Annual Analysis-------------------+" << '\n';
        if (listYear.size == 0) {

            std::cout << "[0] - Choose years to analyze" << '\n';
            std::cout << "[1] - Back" << '\n';
            int option = InputNumber("Option: ", 1, 0);
            if (option == 1) return;
            MyVector<Date> inputYear;
            int n = InputNumber("Choose the number of years to analyze (max - 1000): ", 1000, 1);
            for (int i=1; i<=n; ++i){
                std::cout << "Enter year " << i << '\n';
                int year = InputNumber("Year: ", INT_MAX, 1);
                inputYear.push_back({0, 0, year});
            } 
            IncomeAnnual(user, inputYear);
        }
        else {
            for (int t=0; t<listYear.size; ++t) {
                int year = listYear[t].year;
                int income = 0;

                int* cntInCat = new int [user.incomeList.size]();

                for (int i=0; i<user.incomeList.size; ++i){
                    if (!user.incomeList[i].isDeleted){
                        int inCat = user.incomeList[i].id;
                        for (int j=0; j<user.incomeHistory.size; ++j){
                            IncomeHistory check = user.incomeHistory[j];
                            if (check.isDeleted == false && check.date.year == year && check.idCategory == inCat){
                                income += check.money;
                                cntInCat[inCat] += check.money;
                            }
                        }
                    }
                }

                std::cout << "Year: " << year << '\n';
                std::cout << "Income: " << FormatMoney(income) << '\n';
                for (int i=0; i<user.incomeList.size; ++i){
                    IncomeCategory show = user.incomeList[i];
                    if (!show.isDeleted){
                        DisplayNameWithMoney(show.name, cntInCat[show.id]);
                    }
                }
                std::cout << borderLine << '\n';
                delete[] cntInCat;
            }
            std::cout << "[0] - Back" <<'\n';
            int option = InputNumber("Option: ", 0, 0);
            if (option == 0) return;
        } 
    }
}

void ExpenseAnnual(User& user, MyVector<Date> &listYear){
    bool t = true;
    while(t){
        ClearScreen();
        std::cout << borderLine << '\n';
        std::cout << "+-----------------Expense Annual Analysis------------------+" << '\n';
        if (listYear.size == 0) {

            std::cout << "[0] - Choose years to analyze" << '\n';
            std::cout << "[1] - Back" << '\n';
            int option = InputNumber("Option: ", 1, 0);
            if (option == 1) return;
            MyVector<Date> inputYear;
            int n = InputNumber("Choose the number of years to analyze (max - 1000): ", 1000, 1);
            for (int i=1; i<=n; ++i){
                std::cout << "Enter year " << i << '\n';
                int year = InputNumber("Year: ", INT_MAX, 1);
                inputYear.push_back({0, 0, year});
            } 
            ExpenseAnnual(user, inputYear);
        }
        else {
            for (int t=0; t<listYear.size; ++t) {
                int year = listYear[t].year;
                int expense = 0;

                int* cntExCat = new int [user.expenseList.size]();

                for (int i=0; i<user.expenseList.size; ++i){
                    if (!user.expenseList[i].isDeleted){
                        int exCat = user.expenseList[i].id;
                        for (int j=0; j<user.expenseHistory.size; ++j){
                            ExpenseHistory check = user.expenseHistory[j];
                            if (check.isDeleted == false && check.date.year == year && check.idCategory == exCat){
                                expense += check.money;
                                cntExCat[exCat] += check.money;
                            }
                        }
                    }
                }

                std::cout << "Year: " << year << '\n';
                std::cout << "Expense: " << FormatMoney(expense) << '\n';
                for (int i=0; i<user.expenseList.size; ++i){
                    ExpenseCategory show = user.expenseList[i];
                    if (!show.isDeleted){
                        DisplayNameWithMoney(show.name, cntExCat[show.id]);
                    }
                }
                std::cout << borderLine << '\n';
                delete[] cntExCat;
            }
            std::cout << "[0] - Back" <<'\n';
            int option = InputNumber("Option: ", 0, 0);
            if (option == 0) return;
        } 
    }
}

void showIncomeHistory (User &user, Date &bd, Date &kt) {
        std::cout << "+------Income History: " << '\n';
        for (int i=0; i<user.incomeHistory.size; ++i){
            Date temp = user.incomeHistory[i].date;
            if (CompareDate(temp, bd) <0 || CompareDate(temp, kt) >0) continue;
            if (user.incomeHistory[i].isDeleted == false){

                IncomeHistory show = user.incomeHistory[i];
                std::cout << "Date: " << show.date.day << "/"
                << show.date.month << "/" << show.date.year << '\n';
                std::cout << "Message: " << show.message << '\n';
                
                Wallet wallet; 
                int idx = SearchWalletID(user, show.idWallet);
                wallet = user.walletList[idx];

                std::cout << "Wallet: " << wallet.name << '\n';

                IncomeCategory inCat;
                idx = SearchIncomeID(user, show.idCategory);
                inCat = user.incomeList[idx];

                std::cout << "Category: " << inCat.name << '\n';

                std::cout << "Amount: " << FormatMoney(show.money) << '\n';

                std::cout << '\n';             
            }
        }
}

void showExpenseHistory (User &user, Date &bd, Date &kt) {
        std::cout << "+------Expense History: " << '\n';
        for (int i=0; i<user.expenseHistory.size; ++i){
            Date temp = user.expenseHistory[i].date;
            if (CompareDate(temp, bd) <0 || CompareDate(temp, kt) >0) continue;
            if (!user.expenseHistory[i].isDeleted){
                ExpenseHistory show = user.expenseHistory[i];
                std::cout << "Date: " << show.date.day << "/"
                << show.date.month << "/" << show.date.year << '\n';
                std::cout << "Message: " << show.message << '\n';
                
                Wallet wallet; 
                int idx = SearchWalletID(user, show.idWallet);
                wallet = user.walletList[idx];

                std::cout << "Wallet: " << wallet.name << '\n';

                ExpenseCategory exCat;
                idx = SearchExpenseID(user, show.idCategory);
                exCat = user.expenseList[idx];
                
                std::cout << "Category: " << exCat.name << '\n';

                std::cout << "Amount: " << FormatMoney(show.money) << '\n';

                std::cout << '\n';             
            }
        }
}