#pragma once
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "./Characters.h"
#include "./Items.h"
#include "./Home.h"
#include "./Random.h"
#include "./DataController.h"
#include "./Misc.h"

void OptionsInTown();

void Inn(Character &player, bool isDead = false);

void GenerateItem(Item *items, int index, int playerLevel);
void ItemShop(Character &player);

void InTown(Character &player);

