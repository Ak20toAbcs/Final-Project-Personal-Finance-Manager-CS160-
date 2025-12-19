#pragma once
#include "user_data.h"

void SettingPage(User& user);
void EditUsernamePage(User& user);
void EditWalletPage(User& user);
void EditIncomeCategory(User& user);
void EditExpenseCategory(User& user);
void EditListWallet(User &user);
bool EditWallet(User &user, int walletId);
void AddWallet(User &user);

