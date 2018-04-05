#pragma once
#include <fstream>
#include "./Characters.h"

void SaveData(Character &player);
void LoadData(Character &player);

void SeparateAndSetData(std::string input, float &first, float &second, char separator = '/', char endSign = ' ');
void SeparateAndSetData(std::string input, int &first, int &second, char separator = '/', char endSign = ' ');
void SeparateAndSetData(std::string input, bool *arr, int size, char separator = '/', char endSign = ' ');