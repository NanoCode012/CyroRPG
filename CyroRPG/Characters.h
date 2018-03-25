#pragma once
#include <string>
#include <iostream>
#include "./Skills.h"
#include "./Monsters.h"
#include "./Misc.h"

using namespace std;

struct Character
{
    string name;

    int role;

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
    float chanceOfCriticalDamage;
    float criticalDamagePercentage = 0.25;

    float tempChanceOfEvasion;
    float tempChanceOfDamageReduction;
    float tempDamageReduction;
    float tempChanceOfCriticalDamage;
    float tempCriticalDamagePercentage;

    int level = 1;
    float currentExp = 0;
    float expToNextLevel = 5;

    bool turn = true;
    int amountOfExtraActionAtStartTurn = 0;
    int amountOfExtraTurns = 0;

    int gold = 0;

    bool hasSword;
    bool hasArmor;
    bool hasShield;
    bool hasStaff;
    bool hasNecklace;
    bool hasBow;

    int maxAmountOfSkills = 3;
    int amountOfSkills = 0;
    Skill *skills = new Skill[maxAmountOfSkills];

    int position;

    bool killedBoss[3];

    void SetName(string playerName);
    void SetClass(int index);

    string GetClassName();

    void SetTempStatsEqualToNonTemp();
    void SetSkill(int index);
    void UseSkill(int index, Monster &monster);

    float NormalAttack();
    float CriticalAttack();

    bool DamageCalculation(float damage);

    void IncreaseStats();
    
    bool LevelUp();

    float GetExpPercentage();

    void Fullheal();

    bool IsAlive();
};