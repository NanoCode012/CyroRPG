#include "../inc/Monster.h"

using namespace std;

void Monster::SetType(int index, int playerPosition)
{
    //Get value of 0-4, to be used later for increasing stats in each zone
    int tempPlayerPosition = playerPosition;
    tempPlayerPosition--;
    for (int i = 0; i < index - 1; i++)
    {
        tempPlayerPosition -= 5;
    }

    int randHp = GetRandomNumber(10 * index);
    int atk = tempPlayerPosition * index;
    int def = atk;

    chanceOfCriticalDamage = 0.05 + playerPosition * 0.04;
    chanceOfSpecialAttack = 0.05 + playerPosition * 0.01;
    level = playerPosition;

    gold = GetRandomNumber(20*index + playerPosition * 3);
    exp = GetRandomNumber(15*index + playerPosition * 3);
    switch(index)
    {
        //Boss - Uses PlayerPosition for higher stats
        //Lore - Boss of Each Zone
        case 0:
            //Set name
            switch(playerPosition)
            {
                case 5:
                    name = "Giant Rat";
                    break;
                case 10:
                    name = "Vicious Wolf";
                    break;
                case 15:
                    name = "Angered Orge";
                    break;
            }

            maxHp = 150 * ((playerPosition)/5) + GetRandomNumber(playerPosition * 5);
            maxMana = 15 * ((playerPosition)/5) + GetRandomNumber(playerPosition * 3);

            attackDamageMin = 15 * ((playerPosition)/5) + GetRandomNumber(playerPosition * 1);
            attackDamageMax = 20 * ((playerPosition)/5) + GetRandomNumber(playerPosition * 1);

            if (attackDamageMin >= attackDamageMax) attackDamageMax = attackDamageMin + 5;

            defense = 15 * ((playerPosition)/5) + GetRandomNumber(playerPosition * 4);
            chanceOfEvasion = 0.1 * ((playerPosition)/5) + (GetRandomNumber(playerPosition * 3)/100);

            chanceOfDamageReduction = 0.2 * ((playerPosition)/5) + (GetRandomNumber(playerPosition * 4)/100);
            damageReduction = 15 * ((playerPosition)/5) + GetRandomNumber(playerPosition * 6);

            gold += playerPosition * 5;
            exp += playerPosition * playerPosition;
            break;
        //Position 0-4
        case 1:
            name = "Rat";
            maxHp = 100 + tempPlayerPosition * 20 + randHp;
            maxMana = 10;

            attackDamageMin = 10 + atk;
            attackDamageMax = 15 + atk;

            defense = 15 + def;
            chanceOfEvasion = 0;

            chanceOfDamageReduction = 0;
            damageReduction = 0;
            break;
        //Position 6-9
        case 2:
            name = "Wolf";
            maxHp = 200 + tempPlayerPosition * 20 + randHp;
            maxMana = 20;

            attackDamageMin = 20 + atk;
            attackDamageMax = 25 + atk;

            defense = 25 + def;
            chanceOfEvasion = 0.01 + tempPlayerPosition * 0.01;

            chanceOfDamageReduction = 0.05 + tempPlayerPosition * 0.05;
            damageReduction = 5 + tempPlayerPosition * 5;
            break;
        //Position 11-14
        case 3:
            name = "Ogre";
            maxHp = 300 + tempPlayerPosition * 30 + randHp;
            maxMana = 30;

            attackDamageMin = 35 + atk;
            attackDamageMax = 40 + atk;

            defense = 40 + def;
            chanceOfEvasion = 0.05 + tempPlayerPosition * 0.05;

            chanceOfDamageReduction = 0.1 + tempPlayerPosition * 0.1;
            damageReduction = 10 + tempPlayerPosition * 10;
            break;
    }
    
}

void Monster::SetTempStatsEqualToNonTemp()
{
    currentHp = maxHp;
    currentMana = maxMana;
    
    tempAttackDamageMin = attackDamageMin;
    tempAttackDamageMax = attackDamageMax;
    tempDefense = defense;

    tempChanceOfEvasion = chanceOfEvasion;
    tempChanceOfDamageReduction = chanceOfDamageReduction;
    tempDamageReduction = damageReduction;
    tempChanceOfCriticalDamage = chanceOfCriticalDamage;
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

bool Monster::DamageCalculation(float damage)
{
    bool isDamaged = false;
    //Half of defense is how much damage is removed
    if ((tempDefense / 2) >= damage)
    {
        cout << "Enemy's defense negated your attack" << endl;
        isDamaged = false;
    }
    else
    {
        damage -= tempDefense / 2;
            
        //Enemy evasion/damage reduct
        int rand = GetRandomNumber(100);
        if (rand > (tempChanceOfEvasion * 100))
        {
            rand = GetRandomNumber(100);
            if (rand > (tempChanceOfDamageReduction * 100))
            {
                cout << "Enemy took " << damage << " damage" << endl;
                currentHp -= damage;
                isDamaged = true;
            }
            else
            {
                if (damage > tempDamageReduction)
                {
                    cout << "Enemy took reduced damage" << endl;
                    currentHp -= damage - tempDamageReduction;
                    cout << "Enemy took " << damage - tempDamageReduction << " damage" << endl;
                    isDamaged = true;
                }
                else
                {
                    cout << "Enemy negated your attack with its damage reduction" << endl;
                    isDamaged = false;
                }
            }
        }
        else
        {
            cout << "Enemy evaded your attack" << endl;
            isDamaged = false;
        }
    }
    return isDamaged;
}

bool Monster::IsAlive()
{
    return (currentHp > 0);
}