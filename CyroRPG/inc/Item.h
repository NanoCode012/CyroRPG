#pragma once
#include <string>
#include <iostream>
#include "./Random.h"

using namespace std;

struct Item
{
    string name = "";
    int id = -1;

    bool isNull = true;
    bool isEquippable = false;

    int level = -1;//0->5 from lowest to highest level
    
    int cost = 0;

    float defense = 0;

    float chanceOfEvasion = 0;

    float chanceOfDamageReduction = 0;
    float damageReduction = 0;

    float chanceOfCriticalDamage = 0;
    
    float criticalDamagePercentage = 0;

    float hp = 0;
    float mana = 0;

    void SetType(int type, int rarity, bool wearable);

    void ShowInfo(bool showName = true);
};