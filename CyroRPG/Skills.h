#pragma once
#include "./Characters.h"
#include "./Random.h"
struct Skill
{
    bool isActive;
    int level = 1;
    int index;
    
    int manaCost;

    //Active
    int damage;
    int damageOverTime;
    int amountOfTurns;

    //Passive
    float defense;
    float evasion;
    float chanceOfDamageReduction;
    float chanceOfCritical;

    void Set(Character &player);

    void Use(Character &player);
};