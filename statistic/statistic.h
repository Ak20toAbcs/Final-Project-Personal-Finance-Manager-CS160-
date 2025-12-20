#pragma once
#include "user_data.h"

void StatisticPage(User &user);
void OverallPage(User &user, Date &bd, Date &kt);
void IncomeBreakdown(User &user, Date &bd, Date &kt);
void ExpenseBreakdown(User &user, Date &bd, Date &kt);
void WalletStat(User &user, Date &bd, Date &kt, int id);
void HistoryStat(User& user, Date &bd, Date &kt, int state);
void AnnualAnalysis(User &user, MyVector<Date> &listYear);
void NetAnnual(User &user, MyVector<Date> &listyear);
void IncomeAnnual(User &user, MyVector<Date> &listYear);
void ExpenseAnnual(User& user, MyVector<Date> &listYear);
void showIncomeHistory(User &user, Date &bd, Date &kt);
void showExpenseHistory(User &user, Date &bd, Date &kt);
