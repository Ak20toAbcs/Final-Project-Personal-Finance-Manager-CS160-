#include "create_user.h"
#include "user_data.h"
#include <iostream>
using namespace std;

int main(){
    ResetUser();
    User user;
    if (LoadUser(user) == false) {
        CreateUserPage(user);
    }
    // vao menu
    return 0;
}