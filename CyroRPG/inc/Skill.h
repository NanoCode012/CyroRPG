#pragma once
#include <string>
#include <iostream>
#include "./Random.h"
using namespace std;

struct Skill
{
    int id = -1;
    string name = "";

    bool isActive = false;
    int level = 1;
    
    int manaCost = 0;

    int learnCost = 0;
    int upgradeCost = 0;

    //Active
    int damage = 0;
    int damageOverTime = 0;
    int amountOfTurnsDOT = 0;

    float chanceOfStun = -1;
    int stunnedTurns = 0;

    int damageMultiplier = 0;

    float damageReductionPercentage = 0;
    int amountOfTurnsDamageReductionPercentage = 0;

    float chanceOfDrainHP = -1;
    float hpDrainOfMaxPercentage = 0;

    int maxTimesOfFiringAgain = 2;
    float *chanceOfFiringAgain = new float[maxTimesOfFiringAgain];

    //Passive
    float defenseIncreasePercentage = 0;

    float chanceOfEvasion = -1;

    float chanceOfDamageReduction = -1;
    int damageReduction = 0;

    float chanceOfCriticalDamage = -1;
    float criticalDamagePercentage = 0;


    void SetType(int skillID, int lvl = 1);

    void ShowInfo(bool showName = true);
};