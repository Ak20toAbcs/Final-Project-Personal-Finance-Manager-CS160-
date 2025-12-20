#pragma once
#include <iostream>
#include <string>
#include "user_data.h"

void ClearScreen();
void PauseScreen();
int InputNumber(const std::string& prompt, int maxIn, int minIn);
Date InputDate();
char InputYesNo();
// dùng để ngăn cách các trang
 extern std::string borderLine;