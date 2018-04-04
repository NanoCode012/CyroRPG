#pragma once
#include <iostream>
#include "./Characters.h"
#include "./Monsters.h"
#include "./Miscellaneous/Random.h"
#include "./Items.h"
#include "./Home.h"
#include "./Miscellaneous/Misc.h"

void Options();

void UseItemInBattle(Character &player);

void MoveCharacter(Character &player, int opt, bool &exitStatus);

bool CheckIfMeetEnemy(Character &player);

void SetPlayerStats(Character &player, Monster &monster);

void SetEnemyStats(Monster &monster, Character &player);

void ShowPlayerTempStats(Character &player);
void ShowEnemyTempStats(Monster &monster);

void ShowBattleOptions();

void ShowActiveSkills(Character &player);
void ShowAvailableItemsInInventory(Character &player);

void CalculatePlayerAttack(Character &player, Monster &monster, int opt);

void CalculateMonsterAttack(Monster &monster, Character &player, int opt);

void CheckIfMonsterDead(Monster &monster, Character &player);

void OutTown(Character &player);