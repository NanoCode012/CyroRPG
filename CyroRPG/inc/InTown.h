#pragma once
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "./Character.h"
#include "./Item.h"
#include "./Home.h"
#include "./Random.h"
#include "./DataController.h"
#include "./Misc.h"

void OptionsInTown();

void Inn(Character &player, bool isDead = false);

void GenerateItem(Item *items, int index, int playerLevel);

Item GenerateItem(int playerLevel);
void ItemShop(Character &player);

void Quit();

void InTown(Character &player);

