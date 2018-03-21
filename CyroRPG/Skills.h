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

    float chanceOfStun;
    int stunnedTurns;

    int damageMultiplier;

    float enemyDamageReductionPercentage;

    float chanceOfDrainHP;
    float hpDrainOfMaxPercentage;

    float chanceOfFiringAgain[2];

    //Passive
    float defenseIncreasePercentage;

    float chanceOfEvasion;

    float chanceOfDamageReduction;
    int damageReduction;

    float chanceOfCriticalDamage;
    float criticalDamagePercentage;
};