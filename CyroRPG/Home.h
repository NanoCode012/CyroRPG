#pragma once
#include <iostream>
#include "./Characters.h"
#include "./Items.h"
#include "./Miscellaneous/DataController.h"
#include "./Miscellaneous/Misc.h"

void OptionsHome();

void ShowItemStats(Item item, bool showName = true);

void ShowPlayerStats(Character &player);
void ShowPlayerSkills(Character &player);
void ShowPlayerEquippedGear(Character &player, bool showWithNumbering = false);
void ShowPlayerInventory(Character &player);
void ShowAllPlayerInfo(Character &player);

void ShowPlayerEquippableGear(Character &player);
void EquipItem(Character &player, int indexInInventory);

void Home(Character &player);