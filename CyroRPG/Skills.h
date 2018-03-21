#pragma once
#include <string>
#include "./Random.h"
using namespace std;

struct Skill
{
    int id;
    string name;

    bool isActive;
    int level = 1;
    
    int manaCost;

    //Active
    int damage;
    int damageOverTime;
    int amountOfTurns;
    int stunnedTurns;
    int damageMultiplier;
    float damageReductionPercentage;

    //Passive
    float defenseIncreasePercentage;
    float evasion;
    float chanceOfDamageReduction;
    float chanceOfCritical;
};