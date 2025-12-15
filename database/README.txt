File này dùng để lưu dữ liệu quan trọng liên quan đến User

Cấu trúc của file database.bin

    char userName[51]; -> 51 bytes;
    MyVector<Wallet> walletList;
    MyVector<IncomeCategory> incomeList;
    MyVector<ExpenseCategory> expenseList;
    MyVector<RecurringCategory> recurList;
    MyVector<IncomeHistory> incomeHistory;
    MyVector<ExpenseHistory> expenseHistory;
    MyVector<RecurringHistory> recurHistory;