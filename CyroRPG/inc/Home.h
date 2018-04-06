#pragma once
#include <iostream>
#include "./Character.h"
#include "./Item.h"
#include "./DataController.h"
#include "./Misc.h"

void OptionsHome();

void ShowItemStats(Item item, bool showName = true);

void ShowPlayerStats(Character &player);
void ShowPlayerSkills(Character &player);
void ShowPlayerEquippedGear(Character &player, bool showWithNumbering = false);
void ShowPlayerInventory(Character &player);
void ShowAllPlayerInfo(Character &player);

void ShowPlayerEquippableGear(Character &player);
void EquipItem(Character &player, int indexInInventory);
void UnequipItem(Character &player, int indexInEquipped);

void Home(Character &player);