#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include <math.h>

void PrintLine(char character = '=');

void CleanExit(std::string message = "Quit Game");
void CleanUp();

std::string ConvertFromIntToString(int a);
std::string ConvertFromPercentageToString(float a, int decimalPlaces);
int ConvertFromStringToInt(std::string input);
float ConvertFromStringToFloat(std::string input);