#pragma once
#include <iostream>
#include "./Characters.h"
#include "./Monsters.h"
#include "./Miscellaneous/Random.h"
#include "./Items.h"
#include "./Miscellaneous/Misc.h"

void Options();

void MoveCharacter(Character &player, int opt, bool &exitStatus);

bool CheckIfMeetEnemy(Character &player);

void SetPlayerStats(Character &player, Monster &monster);

void SetEnemyStats(Monster &monster, Character &player);

void ShowPlayerStats(Character &player);
void ShowEnemyStats(Monster &monster);

void ShowBattleOptions();

void ShowActiveSkills(Character &player);
void ShowAvailableItemsInInventory(Character &player);

void CalculatePlayerAttack(Character &player, Monster &monster, int opt);

void CalculateMonsterAttack(Monster &monster, Character &player, int opt);

void OutTown(Character &player);