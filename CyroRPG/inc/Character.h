#pragma once
#include <string>
#include <iostream>
#include "./Skill.h"
#include "./Monster.h"
#include "./Item.h"
#include "./Random.h"
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
    float criticalDamagePercentage = 0.1;

    float tempChanceOfEvasion;
    float tempChanceOfDamageReduction;
    float tempDamageReduction;
    float tempChanceOfCriticalDamage;
    float tempCriticalDamagePercentage;

    int level = 1;
    int currentExp = 0;
    int expToNextLevel = 5;

    bool turn = true;
    int amountOfExtraActionAtStartTurn = 0;
    int amountOfExtraTurns = 0;

    int gold = 0;

    bool hasSword = false;
    bool hasArmor = false;
    bool hasShield = false;
    bool hasStaff = false;
    bool hasNecklace = false;
    bool hasBow = false;

    int maxAmountOfItems = 10;
    int amountOfItems = 0;
    Item *inventory = new Item[maxAmountOfItems];
    Item *equipped = new Item[5];

    int maxAmountOfSkills = 3;
    int amountOfSkills = 0;
    Skill *skills = new Skill[maxAmountOfSkills];

    int position = 0;

    bool killedBoss[3];

    void SetName(string playerName);
    void SetClass(int index);

    string GetClassName();

    void SetTempStatsEqualToNonTemp();

    void Insert(Item &item);
    void ApplyItemEffect(int index, bool isEquipped, bool addEffect = true);
    void Swap(int index, bool swapFromInventoryToEquipped, bool swapOnlyInInventory = false);
    void Equip(int indexInInventory);
    void Unequip(int indexInEquipped);
    void UseItem(int indexInInventory);
    
    void SetSkillForClass(int index);
    void SetSkill(int skillID, int index = -1);
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