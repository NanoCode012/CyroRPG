#include "./Misc.h"
using namespace std;

void PrintLine(char character)
{
    for (int i = 0; i < 100; i++) cout << character;
    cout << endl;
}

void CleanExit(string message)
{
    cout << "Exiting.. Reason : " << message << endl;
    atexit(CleanUp);
    exit(0);
}

void CleanUp(void)
{
    
}

string ConvertFromIntToString(int a)
{
    string temp = "";
    while(a > 0)
    {
        temp += (char)((a % 10) + '0');
        a /= 10;
    }

    string result = "";
    for (int i = temp.length() - 1; i >= 0; i--)
    {
        result += temp[i];
    }
    return result;
}

string ConvertFromPercentageToString(float a, int decimalPlaces)
{
    string temp;
    for (int i = 0; i < decimalPlaces; i++) a *= 10;
    for(int i = 0; i < decimalPlaces; i++)
    {
        temp += (char)((fmod(a, 10)) + '0');
        a /= 10;
    }

    string result = "";
    for (int i = temp.length() - 1; i >= 0; i--)
    {
        result += temp[i];
    }
    return result;
}