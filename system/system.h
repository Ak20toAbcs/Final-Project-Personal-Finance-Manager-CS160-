#pragma once
#include <iostream>
#include <string>

void ClearScreen();
void PauseScreen();
int InputNumber(const std::string& prompt);
// dùng để ngăn cách các trang
 extern std::string borderLine;