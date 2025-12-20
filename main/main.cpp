#include "create_user.h"
#include "user_data.h"
#include "dashboard.h"
#include <iostream>

int main(){
    ResetUser();
    User user;
    IncomeCategory a; a.id = 0;
    strncpy(a.name, "Default", sizeof(a.name)-1);
    IncomeCategory b; b.id = 1;
    strncpy(b.name, "Salary", sizeof(b.name)-1);
    IncomeCategory c; c.id = 2;
    strncpy(c.name, "Onlyfans", sizeof(c.name)-1);
    ExpenseCategory q; q.id = 0;
    strncpy(q.name, "Default", sizeof(a.name)-1);
    ExpenseCategory p; p.id = 1;
    strncpy(p.name, "Shopping", sizeof(b.name)-1);
    ExpenseCategory w; w.id = 2;
    strncpy(w.name, "Groceries", sizeof(c.name)-1);
    Wallet x; x.id = 0;
    strncpy(x.name, "Cash", sizeof(x.name)-1);
    Wallet y; y.id = 1;
    strncpy(y.name, "Bank", sizeof(y.name)-1);
    Wallet z; z.id = 2;
    strncpy(z.name, "BIDV", sizeof(z.name)-1);

    user.walletList.push_back(x);
    user.walletList.push_back(y);
    user.walletList.push_back(z);
    user.incomeList.push_back(a);
    user.incomeList.push_back(b);
    user.incomeList.push_back(c);
    user.expenseList.push_back(q);
    user.expenseList.push_back(p);
    user.expenseList.push_back(w);
    if (LoadUser(user) == false) {
        CreateUserPage(user);
    }
    DashBoard(user);
    return 0;
}