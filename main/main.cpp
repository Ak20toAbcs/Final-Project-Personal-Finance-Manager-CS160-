#include "create_user.h"
#include "user_data.h"
#include "dashboard.h"
#include "recurring.h"
#include <iostream>

int main(){
    //ResetUser();
    User user;
    if (LoadUser(user) == false) {
        CreateUserPage(user);
    }
    LoadRecur(user);
    DashBoard(user);
    SaveUser(user);
    return 0;
}