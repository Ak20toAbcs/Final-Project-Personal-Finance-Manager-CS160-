#include "user_data.h"
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

    MyVector <Wallet> SearchWallet (User &user, char s[]){
        MyVector <Wallet> result;
        for (int i=0; i<user.walletList.size; ++i){
            if (user.walletList[i].isDeleted == false && strstr(user.walletList[i].name, s)!=NULL){
                result.push_back(user.walletList[i]);
            }
        }
        return result;
    }

    MyVector <IncomeCategory> SearchIncome (User &user, char s[]){
        MyVector <IncomeCategory> result;
        for (int i=0; i<user.incomeList.size; ++i){
            if (user.incomeList[i].isDeleted == false && strstr(user.incomeList[i].name, s)!=NULL){
                result.push_back(user.incomeList[i]);
            }
        }
        return result;
    }

    MyVector <ExpenseCategory> SearchExpense (User &user, char s[]){
        MyVector <ExpenseCategory> result;
        for (int i=0; i<user.expenseList.size; ++i){
            if (user.expenseList[i].isDeleted == false && strstr(user.expenseList[i].name, s)!=NULL){
                result.push_back(user.expenseList[i]);
            }
        }
        return result;
    }

    MyVector <RecurringCategory> SearchRecur (User &user, char s[]){
        MyVector <RecurringCategory> result;
        for (int i=0; i<user.recurList.size; ++i){
            if (user.recurList[i].isDeleted == false && strstr(user.recurList[i].name, s)!=NULL){
                result.push_back(user.recurList[i]);
            }
        }
        return result;
    }

    

