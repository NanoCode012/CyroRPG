#pragma once
#include <string>
#include "./Random.h"
using namespace std;

struct Skill
{
    int index;
    string name;

    bool isActive;
    int level = 1;
    
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
};