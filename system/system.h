#pragma once
#include <iostream>
#include <string>

using namespace std;

void ClearScreen();
void PauseScreen();
int InputNumber(const string& prompt);
// dùng để ngăn cách các trang
 extern string borderLine;