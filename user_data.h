#pragma once

#include <string>
using namespace std;

template <typename T>
struct MyVector {
    T* data; // con trỏ quản lý mảng động
    int size; // size hiện tại của vector
    int capacity; // capacity hiện tại của vector 
    
    // Constructor khởi tạo
    MyVector() {
        size = 0;
        capacity = 10;  // sức chưa mặc định
        data = new T[capacity]; // Cấp phát bộ nhớ động cho kiểu T
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

struct Wallet {
    char name[50]; // tên của ví
    int id; // id của ví
    int money; // số tiền trong ví
    bool isDeleted; // xem coi ví đã bị xóa chưa
    Wallet() {
        name[0] = '\0';
        money = 0;
        isDeleted = false;
        id = 0;
    }

    void set_name (string s) {
        // copy sang array
        int ss = s.size();
        int cap = (ss<49)? ss : 49;
        for (int i=0; i<cap; ++i){
            name[i] = s[i];
        }
        name[cap] = '\0';
    }
};

    extern bool hasUsed;
    extern char userName[51];
    extern MyVector<Wallet> walletList;


