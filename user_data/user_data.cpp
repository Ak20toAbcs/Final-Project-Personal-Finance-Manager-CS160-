#include "user_data.h"
#include <iostream>
#include <iomanip>
#include <ctime>

    std::string FormatMoney (int money){
        if (money == 0) return "0 VND";
        int m = abs(money);
        std::string s;
        int cnt = 0; int ss = 0;
        while(m>0){
            int t = m%10;
            m /= 10;
            s.push_back(t+'0');
            ++cnt; ++ss;
            if (m>0 && cnt%3==0) {s.push_back(','); ++ss;}
        }
        if (money<0) {s.push_back('-'); ++ss;}
        std::string res;
        for (int i=0; i<ss; ++i) res.push_back(s[ss-1-i]);
        res.push_back(' ');
        res.push_back('V');
        res.push_back('N');
        res.push_back('D');
        return res;
    }

    Date GetCurrentDate() {
    time_t now = time(nullptr);
    tm* t = localtime(&now);

    return { t->tm_mday, t->tm_mon + 1, t->tm_year + 1900 };
    }

    // MyVector <Wallet> SearchWallet (User &user, const char s[]){
    //     MyVector <Wallet> result;
    //     for (int i=0; i<user.walletList.size; ++i){
    //         if (user.walletList[i].isDeleted == false && strstr(user.walletList[i].name, s)!=NULL){
    //             result.push_back(user.walletList[i]);
    //         }
    //     }
    //     return result;
    // }

    // MyVector <IncomeCategory> SearchIncome (User &user, const char s[]){
    //     MyVector <IncomeCategory> result;
    //     for (int i=0; i<user.incomeList.size; ++i){
    //         if (user.incomeList[i].isDeleted == false && strstr(user.incomeList[i].name, s)!=NULL){
    //             result.push_back(user.incomeList[i]);
    //         }
    //     }
    //     return result;
    // }

    // MyVector <ExpenseCategory> SearchExpense (User &user, const char s[]){
    //     MyVector <ExpenseCategory> result;
    //     for (int i=0; i<user.expenseList.size; ++i){
    //         if (user.expenseList[i].isDeleted == false && strstr(user.expenseList[i].name, s)!=NULL){
    //             result.push_back(user.expenseList[i]);
    //         }
    //     }
    //     return result;
    // }

    // MyVector <RecurringCategory> SearchRecur (User &user, const char s[]){
    //     MyVector <RecurringCategory> result;
    //     for (int i=0; i<user.recurList.size; ++i){
    //         if (user.recurList[i].isDeleted == false && strstr(user.recurList[i].message, s)!=NULL){
    //             result.push_back(user.recurList[i]);
    //         }
    //     }
    //     return result;
    // }

    int SearchWalletID (User &user, int id) {
        int l = 0; int r = user.walletList.size-1;
        while (l<=r) {
            if (l==r) {
                if (user.walletList[l].id == id) return l;
                else return -1;
            }
            int m = (l+r)/2;
            if (user.walletList[m].id == id) return m;
            if (user.walletList[m].id > id) {
                r = m-1;
            }
            if (user.walletList[m].id < id){
                l = m+1;
            }
        }
        return -1;
    }
    int SearchIncomeID (User &user, int id) {
        int l = 0; int r = user.incomeList.size-1;
        while (l<=r) {
            if (l==r) {
                if (user.incomeList[l].id == id) return l;
                else return -1;
            }
            int m = (l+r)/2;
            if (user.incomeList[m].id == id) return m;
            if (user.incomeList[m].id > id) {
                r = m-1;
            }
            if (user.incomeList[m].id < id){
                l = m+1;
            }
        }
        return -1;
    }

    int SearchExpenseID (User &user, int id) {
        int l = 0; int r = user.expenseList.size-1;
        while (l<=r) {
            if (l==r) {
                if (user.expenseList[l].id == id) return l;
                else return -1;
            }
            int m = (l+r)/2;
            if (user.expenseList[m].id == id) return m;
            if (user.expenseList[m].id > id) {
                r = m-1;
            }
            if (user.expenseList[m].id < id){
                l = m+1;
            }
        }
        return -1;
    }

    int SearchRecurID (User &user, int id) {
        int l = 0; int r = user.recurList.size-1;
        while (l<=r) {
            if (l==r) {
                if (user.recurList[l].id == id) return l;
                else return -1;
            }
            int m = (l+r)/2;
            if (user.recurList[m].id == id) return m;
            if (user.recurList[m].id > id) {
                r = m-1;
            }
            if (user.recurList[m].id < id){
                l = m+1;
            }
        }
        return -1;
    }

    int CompareDate(const Date&a, const Date&b){
    if (a.year < b.year) return -1;
    if (a.year > b.year) return 1;
    if (a.month < b.month) return -1;
    if (a.month > b.month) return 1;
    if (a.day < b.day) return -1;
    if (a.day > b.day) return 1;
    return 0;
    }

    void DisplayNameWithMoney (const char s[], int amount){
        std::cout << "| ";
        std::cout << std::left << std::setw(24) << s;
        std::cout << " | ";
        std::cout << std::right << std::setw(29) << FormatMoney(amount);
        std::cout << " |" << '\n';
    }

    

