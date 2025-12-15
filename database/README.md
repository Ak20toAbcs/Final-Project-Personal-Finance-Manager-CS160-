File này dùng để lưu dữ liệu quan trọng liên quan đến User

Cấu trúc của file database.bin

    char userName[51]; 
    -> 51 bytes

    MyVector<Wallet> walletList; 
    -> n (size của Vector) : 4 bytes
    n cái Wallet: mỗi cái sizeof(Wallet)

    MyVector<IncomeCategory> incomeList;
    -> n (size của Vector) : 4 bytes
    n cái Category: mỗi cái sizeof(IncomeCategory)

    MyVector<ExpenseCategory> expenseList;
    -> n (size của Vector) : 4 bytes
    n cái Category: mỗi cái sizeof(ExpenseCategory)

    MyVector<RecurringCategory> recurList;
    -> n (size của Vector) : 4 bytes
    n cái Category: mỗi cái sizeof(RecurringCategory)

    MyVector<IncomeHistory> incomeHistory;
    -> n (size của Vector) : 4 bytes
    n cái History: mỗi cái sizeof(IncomeHistory)

    MyVector<ExpenseHistory> expenseHistory;
    -> n (size của Vector) : 4 bytes
    n cái History: mỗi cái sizeof(ExpenseHistory)

    MyVector<RecurringHistory> recurHistory;
    -> n (size của Vector) : 4 bytes
    n cái History: mỗi cái sizeof(RecurringHistory)