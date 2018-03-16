#pragma once
#include <iostream>
#include "./Characters.h"
#include "./Random.h"
#include "./Misc.h"

void OptionsInTown();
void Inn(Character &player, bool isDead = false);
void ShowStats(Character &player);
void InTown(Character &player);