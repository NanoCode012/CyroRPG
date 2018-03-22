#pragma once
#include <string>
#include "./Skills.h"
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
    
    float evasion;
    float chanceOfDamageReduction;
    float damageReduction;
    float chanceOfCritical;

    float tempEvasion;
    float tempChanceOfDamageReduction;
    float tempDamageReduction;
    float tempChanceOfCritical;

    int level = 1;
    float currentExp = 0;
    float expToNextLevel = 5;

    bool turn = true;
    int amountOfExtraActionAtStartTurn;
    int amountOfExtraActionAtNextTurn;

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

    void SetName(string playerName);
    void SetClass(int index);

    string GetClassName();

    void SetTempStatsEqualToNonTemp();
    void SetSkill(int index);
    void UseSkill(int index);

    void IncreaseStats();
    
    bool LevelUp();

    float GetExpPercentage();

    void Fullheal();

    bool IsAlive();
};