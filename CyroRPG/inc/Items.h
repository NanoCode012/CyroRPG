#pragma once
#include <string>
#include "./Random.h"

using namespace std;

struct Item
{
    string name;
    bool isNull = true;
    bool isEquippable;
    int type;
    int level;//0->5 from lowest to highest level
    int cost = 0;

    float defense = 0;
    float chanceOfEvasion = 0;
    float chanceOfDamageReduction = 0;
    float damageReduction = 0;
    float chanceOfCriticalDamage = 0;
    float criticalDamagePercentage = 0;

    float hp = 0;
    float mana = 0;

    void SetType(int index, int rarity, bool wearable);
};