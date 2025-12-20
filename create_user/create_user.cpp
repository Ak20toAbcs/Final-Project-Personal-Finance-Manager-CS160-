#include "system.h"
#include "user_data.h"
#include "create_user.h"
#include <iostream>
#include <fstream>


// Hàm để reset lại HasUsed = 0
bool ResetUser (){
    std::ofstream fout;
    fout.open("config/app_config.bin", std::ios::binary);
    if (fout.is_open() == false) return false;

    bool temp = false;
    fout.write((char*)&temp, 1);
    fout.close();
    return true;
}
// Hàm để thay hasUser thành true
bool AddUser (){
    std::ofstream fout;
    fout.open("config/app_config.bin", std::ios::binary);
    if (fout.is_open() == false) return false;

    bool temp = true;
    fout.write((char*)&temp, 1);
    fout.close();
    return true;
}
// Hàm để load data cho user
bool LoadUser(User &user){
    std::ifstream fin;
    fin.open("config/app_config.bin", std::ios::binary);
    if (fin.is_open() == false) return false;

    bool hasUsed;
    fin.read((char*)&hasUsed, sizeof(bool));
    fin.close();
    
    if (hasUsed == false) return false;

    // --- BƯỚC QUAN TRỌNG: Xóa dữ liệu cũ để tránh bị trùng lặp ---
    user.walletList.size = 0;
    user.incomeList.size = 0;
    user.expenseList.size = 0;
    user.recurList.size = 0;
    user.incomeHistory.size = 0;
    user.expenseHistory.size = 0;
    user.recurHistory.size = 0;
        fin.open("database/database.bin", std::ios::binary);
        if (fin.is_open() == false) return false;

        // đọc userName
        fin.read((char*)&user.userName, sizeof(user.userName));
        
        int tempSize = 0;
        
        // đọc WalletList
        fin.read((char*)&tempSize, sizeof(int));
        for (int i=0; i<tempSize; ++i){
            Wallet x;
            fin.read((char*)&x, sizeof(Wallet));
            user.walletList.push_back(x);
        }

        // đọc IncomeCategory
        fin.read((char*)&tempSize, sizeof(int));
        for (int i=0; i<tempSize; ++i){
            IncomeCategory x;
            fin.read((char*)&x, sizeof(IncomeCategory));
            user.incomeList.push_back(x);
        }

        // đọc ExpenseCategory
        fin.read((char*)&tempSize, sizeof(int));
        for (int i=0; i<tempSize; ++i){
            ExpenseCategory x;
            fin.read((char*)&x, sizeof(ExpenseCategory));
            user.expenseList.push_back(x);
        }

        // đọc RecurringCategory
        fin.read((char*)&tempSize, sizeof(int));
        for (int i=0; i<tempSize; ++i){
            RecurringCategory x;
            fin.read((char*)&x, sizeof(RecurringCategory));
            user.recurList.push_back(x);
        }

        // đọc IncomeHistory
        fin.read((char*)&tempSize, sizeof(int));
        for (int i=0; i<tempSize; ++i){
            IncomeHistory x;
            fin.read((char*)&x, sizeof(IncomeHistory));
            user.incomeHistory.push_back(x);
        }

        // đọc ExpenseHistory
        fin.read((char*)&tempSize, sizeof(int));
        for (int i=0; i<tempSize; ++i){
            ExpenseHistory x;
            fin.read((char*)&x, sizeof(ExpenseHistory));
            user.expenseHistory.push_back(x);
        }

        // đọc RecurringHistory
        fin.read((char*)&tempSize, sizeof(int));
        for (int i=0; i<tempSize; ++i){
            RecurringHistory x;
            fin.read((char*)&x, sizeof(RecurringHistory));
            user.recurHistory.push_back(x);
        }
        
        fin.close();
        return true;
}
// Hàm để save data cho user
bool SaveUser(User &user){
        std::ofstream fout;
        // ghi has Used
        fout.open("config/app_config.bin", std::ios::binary);
        bool hasUsed = true;
        fout.write((char*)&hasUsed, sizeof(bool));
        fout.close();

        // ghi DATA
        fout.open("database/database.bin", std::ios::binary);
        if (fout.is_open()==false) return false;
        // save userName 
        fout.write((char*)&user.userName, sizeof(user.userName));

        // save WalletList
        fout.write((char*)&user.walletList.size, sizeof(int));
        for (int i=0; i<user.walletList.size; ++i)
        fout.write((char*)&user.walletList[i], sizeof(Wallet));

        // save IncomeCategory
        fout.write((char*)&user.incomeList.size, sizeof(int));
        for (int i=0; i<user.incomeList.size; ++i)
        fout.write((char*)&user.incomeList[i], sizeof(IncomeCategory));

        // save ExpenseCategory
        fout.write((char*)&user.expenseList.size, sizeof(int));
        for (int i=0; i<user.expenseList.size; ++i)
        fout.write((char*)&user.expenseList[i], sizeof(ExpenseCategory));

        // save RecurringCategory
        fout.write((char*)&user.recurList.size, sizeof(int));
        for (int i=0; i<user.recurList.size; ++i)
        fout.write((char*)&user.recurList[i], sizeof(RecurringCategory));

        // save IncomeHistory
        fout.write((char*)&user.incomeHistory.size, sizeof(int));
        for (int i=0; i<user.incomeHistory.size; ++i)
        fout.write((char*)&user.incomeHistory[i], sizeof(IncomeHistory));

        // save ExpenseHistory
        fout.write((char*)&user.expenseHistory.size, sizeof(int));
        for (int i=0; i<user.expenseHistory.size; ++i)
        fout.write((char*)&user.expenseHistory[i], sizeof(ExpenseHistory));

        // save RecurringHistory
        fout.write((char*)&user.recurHistory.size, sizeof(int));
        for (int i=0; i<user.recurHistory.size; ++i)
        fout.write((char*)&user.recurHistory[i], sizeof(RecurringHistory));

        fout.close();
        return true;

}
// Trang khi mở app lần đầu
void CreateUserPage(User &user) {
    ClearScreen();
    std::cout << borderLine << '\n';
    std::cout << "                Welcome to Expense Manager!                 " << '\n';
    std::cout << "Please create your username: ";
    std::cin.getline(user.userName, 51);
    std::cout << '\n';
    std::cout << "                Create Successful!                          " << '\n';
    PauseScreen();
    return;
}



