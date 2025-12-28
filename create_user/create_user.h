#pragma once
#include "user_data.h"

bool ResetUser();
bool AddUser();
void AddDefault(User &user);
bool LoadUser(User &user);
bool SaveUser(User &user);
void CreateUserPage(User &user);