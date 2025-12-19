#pragma once
#include "user_data.h"

bool ResetUser();
bool AddUser();
bool LoadUser(User &user);
bool SaveUser(User &user);
void CreateUserPage(User &user);