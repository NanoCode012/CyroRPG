#pragma once
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "./Characters.h"
#include "./Random.h"
#include "./Misc.h"

void OptionsInTown();
void Inn(Character &player, bool isDead = false);

void ShowPlayerStatsFull(Character &player);

void SaveData(Character &player);
void LoadData(Character &player);

void SeparateAndSetData(string input, float &first, float &second, char separator = '/', char endSign = ' ');
void SeparateAndSetData(string input, int &first, int &second, char separator = '/', char endSign = ' ');
void SeparateAndSetData(string input, bool *arr, int size, char separator = '/', char endSign = ' ');

void InTown(Character &player);

