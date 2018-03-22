#pragma once
#include <iostream>
#include <stdlib.h>
#include "./Characters.h"
#include "./Monsters.h"

void PrintLine(char character = '=');

void CleanExit();
void CleanUp();

void ShowPlayerStats(Character &player);
void ShowEnemyStats(Monster &monster);