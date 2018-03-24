#pragma once
#include <string>
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

    int stunnedTurns;

    int level = 1;

    int gold = 0;

    void SetType(int index, int playerPosition);
    void SetTempStatsEqualToNonTemp();

    float NormalAttack();
    float CriticalAttack();
    float SpecialAttack();

    bool IsAlive();
};