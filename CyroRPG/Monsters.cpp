#include "./Monsters.h"

void Monster::SetType(int index, int playerPosition)
{
    int tempPlayerPosition = playerPosition;
    tempPlayerPosition--;
    for (int i = 0; i < index - 1; i++)
    {
        tempPlayerPosition -= 5;
    }
    switch(index)
    {
        //Boss - Uses PlayerPosition for higher stats
        case 0:
            maxHp = 100 + playerPosition * 20;
            maxMana = 10;

            attackDamageMin = 10;
            attackDamageMax = 15;

            defense = 15;
            evasion = 0;

            chanceOfDamageReduction = 0.05;
            damageReduction = 5;

            chanceOfCritical = 0.05;
            break;
        //Position 0-4
        case 1:
            maxHp = 100 + tempPlayerPosition * 20;
            maxMana = 10;

            attackDamageMin = 10 + tempPlayerPosition * 1;
            attackDamageMax = 15 + tempPlayerPosition * 1;

            defense = 15 + tempPlayerPosition * 1;
            evasion = 0;

            chanceOfDamageReduction = 0;
            damageReduction = 0;
            break;
        //Position 6-9
        case 2:
            maxHp = 200 + tempPlayerPosition * 20;
            maxMana = 20;

            attackDamageMin = 20 + tempPlayerPosition * 2;
            attackDamageMax = 25 + tempPlayerPosition * 2;

            defense = 25 + tempPlayerPosition * 2;
            evasion = 0.01 + tempPlayerPosition * 0.01;

            chanceOfDamageReduction = 0.05 + tempPlayerPosition * 0.05;
            damageReduction = 5 + tempPlayerPosition * 5;
            break;
        //Position 11-14
        case 3:
            maxHp = 300 + tempPlayerPosition * 30;
            maxMana = 30;

            attackDamageMin = 35 + tempPlayerPosition * 3;
            attackDamageMax = 40 + tempPlayerPosition * 3;

            defense = 40 + tempPlayerPosition * 3;
            evasion = 0.05 + tempPlayerPosition * 0.05;

            chanceOfDamageReduction = 0.1 + tempPlayerPosition * 0.1;
            damageReduction = 10 + tempPlayerPosition * 10;
            break;
    }
    chanceOfCritical = 0.05 + playerPosition * 0.04;
    chanceOfSpecialAttack = 0.05 + playerPosition * 0.01;
}

void Monster::SetTempStatsEqualToNonTemp()
{
    currentHp = maxHp;
    currentMana = maxMana;
    
    tempAttackDamageMin = attackDamageMin;
    tempAttackDamageMax = attackDamageMax;
    tempDefense = defense;

    tempEvasion = evasion;
    tempChanceOfDamageReduction = chanceOfDamageReduction;
    tempDamageReduction = damageReduction;
    tempChanceOfCritical = chanceOfCritical;
    tempChanceOfSpecialAttack = chanceOfSpecialAttack;
}

float Monster::NormalAttack()
{
    return (GetRandomNumber(tempAttackDamageMin, tempAttackDamageMax));
}

float Monster::CriticalAttack()
{
    return (NormalAttack() * 1.25);
}

float Monster::SpecialAttack()
{
    return (NormalAttack() * 5);
}

bool Monster::IsAlive()
{
    return (currentHp > 0);
}