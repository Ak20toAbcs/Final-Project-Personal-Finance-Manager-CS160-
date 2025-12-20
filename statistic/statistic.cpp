#include <iostream>
#include "statistic.h"
#include "system.h"

void StatisticPage(User &user){
    bool t = true;
    while(t){
        ClearScreen();
        cout << borderLine << '\n';
        cout << "+--------------------Statistic Page------------------------+" << '\n';
        cout << "[1] - Overall                                               " << '\n';
        cout << "[2] - Specific Wallet                                       " << '\n';
        cout << "[3] - Specific Category                                     " << '\n';
        cout << "[4] - Back                                                  " << '\n';
        int option = InputNumber("Option: ");
        switch (option)
        {
        case 1:
            //OverallPage();
            break;
        case 2:
            //WalletStat();
            break;
        case 3:
            //CatStat();
            break;
        case 4:
            // t = 0;
            break;
        default:{
            cout << "Invalid Input!" << '\n';
            break;
        }
        }
    }
}
void OverallPage(User &user){
    bool t = true;
    while (t){
        ClearScreen();
        std::cout << borderLine << '\n';
        std::cout << "+---------------------Overall Page-------------------------+" << '\n';
        int income = 0;
        int expense = 0;
        for (int i=0; i<user.incomeHistory.size; ++i){
            income += user.incomeHistory[i].money;
        }
        for (int i=0; i<user.expenseList.size; ++i){
            expense += user.expenseHistory[i].money;
        }

        std::cout << "| ";
        std::cout << std::left << std::setw(24) << "Total Balance";
        std::cout << " | ";
        std::cout << std::right << std::setw(29) << FormatMoney(sum);
        std::cout << " |" << '\n';

        int option = InputNumber("Option: ");
    }
}
void WalletStat(User& user);
void CatStat(User &user);