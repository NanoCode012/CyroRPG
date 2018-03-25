#include "./Monsters.h"

using namespace std;

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
            chanceOfEvasion = 0;

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
            chanceOfEvasion = 0;

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
            chanceOfEvasion = 0.01 + tempPlayerPosition * 0.01;

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
            chanceOfEvasion = 0.05 + tempPlayerPosition * 0.05;

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

    tempChanceOfEvasion = chanceOfEvasion;
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