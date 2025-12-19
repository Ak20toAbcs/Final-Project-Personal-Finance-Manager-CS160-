#pragma once

#include <string>
#include <cstring>
using namespace std;

// KHÔNG ĐƯỢC SỬA CÁI NÀY !!!
template <typename T>
struct MyVector {
    private:
    T* data; // con trỏ quản lý mảng động
    int capacity; // capacity hiện tại của vector 
    
    public:
    int size; // size hiện tại của vector
    // Constructor khởi tạo
    MyVector() {
        size = 0;
        capacity = 10;  // sức chưa mặc định
        data = new T[capacity]; // Cấp phát bộ nhớ động cho kiểu T
    }
    ~MyVector(){
        if (data!=nullptr){
            delete[] data;
            data = nullptr;
        }
    }

    // hàm thêm phần tử vào cuối
    void push_back(T value) {
        if (size==capacity) {
            capacity *= 2;
            T* newData = new T[capacity]; // tạo mảng mới để copy qua
            for (int i=0; i<size; ++i) {
                newData[i] = data[i];
            }
            delete[] data; // xóa mảng cũ
            data = newData;
        }
        data[size] = value;
        ++size;
    }

    // hàm để lấy phần tử thứ index
    T& operator[](int index){
        return data[index];
    }

    // hàm để xóa phần tử ở vị trí thứ index
    void erase_at(int index){
        // 1. Kiểm tra vị trí xóa có hợp lệ không
        if (index < 0 || index >= size) {
            return; // Hoặc ném lỗi, hoặc in thông báo
        }

        // 2. Dời các phần tử phía sau lên trước 1 nấc
        // Chạy từ vị trí cần xóa đến áp chót
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }

        // 3. Giảm kích thước logic của mảng
        size--; 
    }
};

struct Date {
    int day;
    int month;
    int year;
};

Date GetCurrentDate();

struct Wallet {
    char name[50]; // tên của ví
    int id; // id của ví
    int money{0}; // số tiền trong ví
    bool isDeleted{0}; // xem coi ví đã bị xóa chưa
};

struct IncomeCategory { 
    int id;
    char name[50];
    bool isDeleted{0};
};

struct ExpenseCategory {
    int id;
    char name[50];
    bool isDeleted{0};
};

struct RecurringCategory {
    int id;
    int money{0};
    bool isIncome{0};
    char name[50];
    bool isDeleted{0};
};

struct IncomeHistory {
    int id;
    int idCategory;
    int idWallet;
    int money{0};
    Date date;
    char message[100];
    bool isDeleted{0};
};

struct ExpenseHistory {
    int id;
    int idCategory;
    int idWallet;
    int money{0};
    Date date;
    char message[100];
    bool isDeleted{0};
};

struct RecurringHistory {
    int id;
    int idCategory;
    int idWallet;
    Date date;    
    bool isDeleted{0};
};


struct User {
    char userName[51];
    MyVector<Wallet> walletList;
    MyVector<IncomeCategory> incomeList;
    MyVector<ExpenseCategory> expenseList;
    MyVector<RecurringCategory> recurList;
    MyVector<IncomeHistory> incomeHistory;
    MyVector<ExpenseHistory> expenseHistory;
    MyVector<RecurringHistory> recurHistory;
};

// Hàm để chuyển từ tiền thành string
string FormatMoney (int money);

MyVector <Wallet> SearchWallet (User &user, char s[]);
MyVector <IncomeCategory> SearchIncome (User &user, char s[]);
MyVector <ExpenseCategory> SearchExpense (User &user, char s[]);
MyVector <RecurringCategory> SearchRecur (User &user, char s[]);
