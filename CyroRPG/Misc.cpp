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

int ConvertFromStringToInt(string input)
{
    int num = 0;
    int length = input.length();
    for (int i = 0; i < length; i++)
    {
        num += (input[i] - '0') * (int)pow(10, length - i - 1);
    }
    return num;
}

float ConvertFromStringToPercentage(string input)
{
    float num = 0;
    int i = 0;
    while(input[i] && input[i++] != '.');
    int positionOfDot = i - 1;
    while(input[i])
    {
        num += (input[i] - '0') * (float)pow(10, positionOfDot - i);
        i++;
    }
    return num;
}