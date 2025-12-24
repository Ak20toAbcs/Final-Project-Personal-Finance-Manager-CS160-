#pragma once 
#include "user_data.h"

void TransactionPage(User &user);
bool IncomePage(User &user);
bool ExpensePage(User &user);
void AddIncome(User &user, int walletID, int catID, int amount, std::string s, Date date);
void AddExpense(User &user, int walletID, int catID, int amount, std::string s, Date date);