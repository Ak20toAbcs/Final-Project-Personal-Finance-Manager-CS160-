#include <iostream>
#include "dashboard.h"
#include "system.h"
#include "transaction.h"
#include "setting.h"
#include <iomanip>
using namespace std;

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
    cout << borderLine << '\n';
    cout << "| ";
    cout << left << setw(24) << "Total Balance";
    cout << " | ";
    cout << right << setw(29) << FormatMoney(sum);
    cout << " |" << '\n';
    cout << borderLine << '\n';
    if (displayList.size == 0) {
        cout << "|                   There is no Wallet!                    |" << '\n';
    }
    for (int i=0; i<displayList.size; ++i){
        cout << "| ";
        cout << left << setw(24) << displayList[i].name;
        cout << " | ";
        cout << right << setw(29) << FormatMoney(displayList[i].money);
        cout << " |" << '\n';
    }
    cout << borderLine << '\n';
}

// Hàm dashboard
void DashBoard (User &user){
    while(true){
        ClearScreen();
        cout << "User: " << user.userName << '\n';
        DisplayMoney(user);
        MenuPage(user);
    }
}

// Hàm Menu 
void MenuPage(User &user){
        cout << "|                        MENU                              |" << '\n';
        cout << "[1] - Transaction                                           " << '\n';
        cout << "[2] - Statistic                                             " << '\n';
        cout << "[3] - Recurring                                             " << '\n';
        cout << "[4] - Setting                                               " << '\n';
        cout << "[5] - Exit                                                  " << '\n';
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
