#pragma once
#include <string>
#include <iostream>
#include "./Random.h"

struct Monster
{
    std::string name;

    int type;

    float maxHp;
    float maxMana;

    float currentHp;
    float currentMana;

    float attackDamageMin;
    float attackDamageMax;
    float defense;

    float tempAttackDamageMin;
    float tempAttackDamageMax;
    float tempDefense;
    
    float chanceOfEvasion;
    float chanceOfDamageReduction;
    float damageReduction;
    float chanceOfCritical;
    float chanceOfSpecialAttack;

    float tempChanceOfEvasion;
    float tempChanceOfDamageReduction;
    float tempDamageReduction;
    float tempChanceOfCritical;
    float tempChanceOfSpecialAttack;

    float damagedOverTime = 0;
    int amountOfTurnsDOT = 0;

    float damageReductionPercentage = 0;
    int amountOfTurnsDamageReductionPercentage = 0;

    int stunnedTurns = 0;

    int level = 1;

    int gold = 0;

    void SetType(int index, int playerPosition);
    void SetTempStatsEqualToNonTemp();

    float NormalAttack();
    float CriticalAttack();
    float SpecialAttack();

    bool DamageCalculation(float damage);

    bool IsAlive();
};