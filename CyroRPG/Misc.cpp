#include "./Misc.h"
using namespace std;

void PrintLine(char character)
{
    for (int i = 0; i < 100; i++) cout << character;
    cout << endl;
}

void CleanExit()
{
    atexit(CleanUp);
    exit(0);
}

void CleanUp(void)
{
    
}
