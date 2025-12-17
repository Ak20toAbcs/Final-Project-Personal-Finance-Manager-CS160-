#include "create_user.h"
#include "user_data.h"
#include "dashboard.h"
#include <iostream>
using namespace std;

int main(){
    ResetUser();
    User user;
    IncomeCategory a;
    strncpy(a.name, "Moi", sizeof(a.name)-1);
    IncomeCategory b;
    strncpy(b.name, "Moi1", sizeof(b.name)-1);
    IncomeCategory c;
    strncpy(c.name, "Moi2", sizeof(c.name)-1);

    Wallet x;
    strncpy(x.name, "Moi", sizeof(x.name)-1);
    Wallet y;
    strncpy(y.name, "Moi1", sizeof(y.name)-1);
    Wallet z;
    strncpy(z.name, "Moi2", sizeof(z.name)-1);

    user.walletList.push_back(x);
    user.walletList.push_back(y);
    user.walletList.push_back(z);
    user.incomeList.push_back(a);
    user.incomeList.push_back(b);
    user.incomeList.push_back(c);
    if (LoadUser(user) == false) {
        CreateUserPage(user);
    }
    DashBoard(user);
    return 0;
}