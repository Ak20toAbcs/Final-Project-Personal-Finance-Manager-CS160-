#pragma once
#include "user_data.h"
using namespace std;

bool ResetUser();
bool AddUser();
bool LoadUser(User &user);
bool SaveUser(User &user);
void CreateUserPage(User &user);