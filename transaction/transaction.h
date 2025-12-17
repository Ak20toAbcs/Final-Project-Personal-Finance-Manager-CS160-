#pragma once 
#include "user_data.h"

void TransactionPage(User &user);
bool IncomePage(User &user);
bool ExpensePage(User &user);
bool AddIncome(User &user, int walletID, int catID, int amount, string s, Date date);
bool AddExpense(User &user, int walletID, int catID, int amount, string s, Date date);