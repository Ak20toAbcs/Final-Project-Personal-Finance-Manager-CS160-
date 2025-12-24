#pragma once
#include "user_data.h"

void SettingPage(User& user);
void EditUsernamePage(User& user);
void EditWalletPage(User& user);
void EditListWallet(User &user);
void EditWallet(User &user, int walletId);
void AddWallet(User &user);
void EditCategoryPage(User &user);
void EditIncomeCategory(User& user);
void EditExpenseCategory(User& user);
void AddIncomeCat(User &user);
void AddExpenseCat(User &user);
void ShowInCat (User &user);
void EditIn(User &user, int idCat);
void ShowExCat (User &user);
void EditEx(User &user, int idCat);