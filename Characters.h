#pragma once
#include <string>

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
    int amountOfActionAtNextTurn = 0;

    int gold = 0;

    void SetName(string playerName)
    {
        name = playerName;
    }
    void SetClass(int index)
    {
        role = index;
        switch(role)
        {
            //Warriors
            case 1:
                maxHp = 50;
                maxMana = 10;
                attackDamageMin = 20;
                attackDamageMax = 25;
                defense = 10;
                evasion = 0.01;
                chanceOfDamageReduction = 0.05;
                damageReduction = 5;
                chanceOfCritical = 0.05;
                break;
            //Mage
            case 2:
                maxHp = 20;
                maxMana = 30;
                attackDamageMin = 5;
                attackDamageMax = 10;
                defense = 2;
                evasion = 0.01;
                chanceOfDamageReduction = 0;
                damageReduction = 5;
                chanceOfCritical = 0.04;
                break;
            //Archer
            case 3:
                maxHp = 25;
                maxMana = 5;
                attackDamageMin = 30;
                attackDamageMax = 40;
                defense = 2;
                evasion = 0.1;
                chanceOfDamageReduction = 0;
                damageReduction = 5;
                chanceOfCritical = 0.07;
                break;
        }
    }

    string GetClassName()
    {
        switch(role)
        {
            case 1:
                return "Warrior";
            case 2:
                return "Mage";
            case 3:
                return "Archer";
        }
        return "null";
    }

    void IncreaseStats()
    {
        switch(role)
        {
            case 1:
                maxHp += 10+level*7;
                maxMana += 1.25*level;
                attackDamageMin += 2*level;
                attackDamageMax += 2*level;
                break;
            case 2:
                maxHp += 5+level*2.5;
                maxMana += 3*level;
                attackDamageMin += 0.75*level;
                attackDamageMax += 0.75*level;
                break;
            case 3:
                maxHp += 5+level*3;
                maxMana += 1.5*level;
                attackDamageMin += 3*level;
                attackDamageMax += 3*level;
                break;
        }
    }
    
    bool LevelUp()
    {
        if (level >= 100) return false;
        if (expToNextLevel - currentExp <= 0.01 || currentExp >= expToNextLevel) 
        {
            level++;
            currentExp = 0;
            for (int i = 1; i < 25; i++)
            {
                if (i*5 > level) 
                {
                    expToNextLevel += i*5;
                    break;
                }
            }
            IncreaseStats();
            return true;
        }
        return false;
    }

    float GetExpPercentage() 
    {
        return (currentExp/expToNextLevel)*100;
    }

    void Fullheal()
    {
        currentHp = maxHp;
        currentMana = maxMana;
    }
};

#pragma once