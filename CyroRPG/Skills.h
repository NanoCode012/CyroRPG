#pragma once
#include <string>
#include "./Miscellaneous/Random.h"
using namespace std;

struct Skill
{
    int id;
    string name;

    bool isActive = false;
    int level = 1;
    
    int manaCost = 0;

    //Active
    int damage = 0;
    int damageOverTime = 0;
    int amountOfTurnsDOT = 0;

    float chanceOfStun = 0;
    int stunnedTurns = 0;

    int damageMultiplier = 0;

    float damageReductionPercentage = 0;
    int amountOfTurnsDamageReductionPercentage = 0;

    float chanceOfDrainHP = 0;
    float hpDrainOfMaxPercentage = 0;

    float chanceOfFiringAgain[2];

    //Passive
    float defenseIncreasePercentage = 0;

    float chanceOfEvasion = 0;

    float chanceOfDamageReduction = 0;
    int damageReduction = 0;

    float chanceOfCriticalDamage = 0;
    float criticalDamagePercentage = 0;
};