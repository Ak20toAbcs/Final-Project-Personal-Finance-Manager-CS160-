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
        std::cout << "[1] - Overall                                               " << '\n';
        std::cout << "[2] - Specific Wallet                                       " << '\n';
        std::cout << "[3] - Specific Category                                     " << '\n';
        std::cout << "[4] - Back                                                  " << '\n';
        int option = InputNumber("Option: ", 4, 1);
        switch (option)
        {
        case 1:{
            Date bd = {0,0,0};
            Date kt = {INT_MAX, INT_MAX, INT_MAX};
            OverallPage(user, bd, kt);
            break;
        }
        case 2:{
            //WalletStat();
            break;
        }
        case 3:{
            //CatStat();
            break;
        }
        case 4:{
            t = 0;
            break;
        }
        default:{
            break;
        }
        }
    }
}
void OverallPage(User &user, const Date &bd, const Date &kt){
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
            Date temp = user.incomeHistory[i].date;
            if (CompareDate(temp, bd) >= 0 && CompareDate(temp, kt) <= 0)
            income += user.incomeHistory[i].money;
        }
        for (int i=0; i<user.expenseList.size; ++i){
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

void WalletStat(User& user);
void CatStat(User &user);