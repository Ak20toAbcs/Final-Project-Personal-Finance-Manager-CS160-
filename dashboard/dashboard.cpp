#include <iostream>
#include "dashboard.h"
#include "system.h"
#include "transaction.h"
#include "setting.h"
#include <iomanip>


// Hàm hiển thị Total 
void DisplayMoney (User &user){
    long long sum = 0;
    
    // tạo cái Display List
    MyVector<Wallet> displayList;
    for (int i=0; i<user.walletList.size; ++i){
        if (!user.walletList[i].isDeleted){
           displayList.push_back(user.walletList[i]); 
           sum+=displayList[i].money;
        }
        
    }
    // Hiển thị cái Display List
    std::cout << borderLine << '\n';
    std::cout << "| ";
    std::cout << std::left << std::setw(24) << "Total Balance";
    std::cout << " | ";
    std::cout << std::right << std::setw(29) << FormatMoney(sum);
    std::cout << " |" << '\n';
    std::cout << borderLine << '\n';
    if (displayList.size == 0) {
        std::cout << "|                   There is no Wallet!                    |" << '\n';
    }
    for (int i=0; i<displayList.size; ++i){
        std::cout << "| ";
        std::cout << std::left << std::setw(24) << displayList[i].name;
        std::cout << " | ";
        std::cout << std::right << std::setw(29) << FormatMoney(displayList[i].money);
        std::cout << " |" << '\n';
    }
    std::cout << borderLine << '\n';
}

// Hàm dashboard
void DashBoard (User &user){
    while(true){
        ClearScreen();
        std::cout << "User: " << user.userName << '\n';
        DisplayMoney(user);
        MenuPage(user);
    }
}

// Hàm Menu 
void MenuPage(User &user){
        std::cout << "|                        MENU                              |" << '\n';
        std::cout << "[1] - Transaction                                           " << '\n';
        std::cout << "[2] - Statistic                                             " << '\n';
        std::cout << "[3] - Recurring                                             " << '\n';
        std::cout << "[4] - Setting                                               " << '\n';
        std::cout << "[5] - Exit                                                  " << '\n';
        int option = InputNumber("Option: ");
        switch(option){
            case 1:{
                TransactionPage(user);
                break;
            }
            case 2:{
                // StatisticPage();
                break;
            }
            case 3:{
                // RecurringPage();
                break;
            }
            case 4:{
                SettingPage(user);
                break;
            }
            case 5:{
                //t = 0;
                break;
            }
            default:{
                break;
            }
    }
       

}
