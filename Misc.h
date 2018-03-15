#pragma once
#include <iostream>

using namespace std;

void PrintLine(char character = '=')
{
    for (int i = 0; i < 100; i++) cout << character;
    cout << endl;
}
