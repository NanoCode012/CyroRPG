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
    char result[10];
    snprintf(result, 10, "%d", a);
    return result;
}

string ConvertFromFloatToString(float a)
{
    char result[10];
    snprintf(result, 10, "%f", a);
    return result;
}