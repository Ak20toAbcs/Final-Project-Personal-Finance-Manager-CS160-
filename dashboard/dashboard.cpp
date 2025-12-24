#include <iostream>
#include "dashboard.h"
#include "system.h"
#include "transaction.h"
#include "statistic.h"
#include "setting.h"
#include "recurring.h"
#include <iomanip>


// Hàm hiển thị Total 
void DisplayMoney (User &user){
    long long sum = 0;
    
    // tạo cái Display List
    MyVector<Wallet> displayList;
    for (int i=0; i<user.walletList.size; ++i){
        if (!user.walletList[i].isDeleted){
           displayList.push_back(user.walletList[i]); 
           sum+=user.walletList[i].money;
        }
        
    }
    // Hiển thị cái Display List
    std::cout << borderLine << '\n';
    DisplayNameWithMoney("Total Balance", sum);
    std::cout << borderLine << '\n';
    if (displayList.size == 0) {
        std::cout << "|                   There is no Wallet!                    |" << '\n';
    }
    for (int i=0; i<displayList.size; ++i){
        DisplayNameWithMoney(displayList[i].name, displayList[i].money);
    }
    std::cout << borderLine << '\n';
}

// Hàm dashboard
void DashBoard (User &user){
    while(true){
        ClearScreen();
        std::cout << "User: " << user.userName << '\n';
        DisplayMoney(user);
        if (MenuPage(user)) return;
    }
}

// Hàm Menu 
bool MenuPage(User &user){
        std::cout << "|                        MENU                              |" << '\n';
        std::cout << "[1] - Transaction                                           " << '\n';
        std::cout << "[2] - Statistic                                             " << '\n';
        std::cout << "[3] - Recurring                                             " << '\n';
        std::cout << "[4] - Setting                                               " << '\n';
        std::cout << "[5] - Exit                                                  " << '\n';
        int option = InputNumber("Option: ", 5, 1);
        switch(option){
            case 1:{
                TransactionPage(user);
                break;
            }
            case 2:{
                StatisticPage(user);
                break;
            }
            case 3:{
                RecurringPage(user);
                break;
            }
            case 4:{
                SettingPage(user);
                break;
            }
            case 5:{
                return true;
                break;
            }
            default:{
                break;
            }
        }
        return false;
}
