#pragma once
#include <fstream>
#include "./Character.h"

bool CanReadData();

void SaveData(Character &player);
void LoadData(Character &player);

void SeparateAndSetData(std::string input, float &first, float &second, char separator = '/', char endSign = ' ');
void SeparateAndSetData(std::string input, int &first, int &second, char separator = '/', char endSign = ' ');
void SeparateAndSetBossData(std::string input, bool *arr, int size, char separator = '/', char endSign = ' ');
void SeparateAndSetMissionData(string input, Mission &mission);
void SeparateAndSetItemData(string input, Item &item);