cmake_minimum_required(VERSION 3.10)

# Đặt tên dự án của bạn
project(MyApplication)

# 1. Cấu hình C++ chuẩn (ví dụ C++ 17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 2. Gom tất cả các file mã nguồn (.cpp)
# Lệnh này quét các folder để tìm file .cpp và lưu vào biến SOURCES
file(GLOB_RECURSE SOURCES 
    "main/*.cpp"
    "user_data/*.cpp"
    "database/*.cpp"
    "create_user/*.cpp"
    "system/*.cpp"
    "dashboard/*.cpp"
    "transaction/*.cpp"
)

# 3. Thêm đường dẫn folder chứa file Header (.h)
# Dòng này giúp bạn #include "user_data.h" thoải mái mà không cần ../
include_directories(
    ${CMAKE_SOURCE_DIR}/create_user
    ${CMAKE_SOURCE_DIR}/system
    ${CMAKE_SOURCE_DIR}/user_data    
    # Bạn nên thêm cả database và dashboard vào đây nếu các folder đó có file .h cần include
    ${CMAKE_SOURCE_DIR}/database
    ${CMAKE_SOURCE_DIR}/dashboard
    ${CMAKE_SOURCE_DIR}/transaction
)

# 4. Tạo file chạy (Executable) từ danh sách file SOURCES vừa tìm được ở mục 2
add_executable(MyApp ${SOURCES})