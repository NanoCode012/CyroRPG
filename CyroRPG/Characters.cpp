#include "./Characters.h"

using namespace std;

void Character::SetName(string playerName)
{
    name = playerName;
}
void Character::SetClass(int index)
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
            chanceOfEvasion = 0.01;

            chanceOfDamageReduction = 0.05;
            damageReduction = 5;

            chanceOfCriticalDamage = 0.05;
            break;
        //Mage
        case 2:
            maxHp = 20;
            maxMana = 30;

            attackDamageMin = 5;
            attackDamageMax = 10;

            defense = 2;
            chanceOfEvasion = 0.01;

            chanceOfDamageReduction = 0;
            damageReduction = 5;

            chanceOfCriticalDamage = 0.04;
            break;
        //Archer
        case 3:
            maxHp = 25;
            maxMana = 5;

            attackDamageMin = 30;
            attackDamageMax = 40;

            defense = 2;
            chanceOfEvasion = 0.1;

            chanceOfDamageReduction = 0;
            damageReduction = 5;

            chanceOfCriticalDamage = 0.07;

            amountOfExtraActionAtStartTurn = 2;
            break;
    }
    
    for(int i = 1; i <= maxAmountOfSkills; i++)
    {
        Character:SetSkill((role - 1) * 3 + i);
    }
    
}

string Character::GetClassName()
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

void Character::SetTempStatsEqualToNonTemp()
{
    tempAttackDamageMin = attackDamageMin;
    tempAttackDamageMax = attackDamageMax;
    tempDefense = defense;

    tempChanceOfEvasion = chanceOfEvasion;
    tempChanceOfDamageReduction = chanceOfDamageReduction;
    tempDamageReduction = damageReduction;
    tempChanceOfCriticalDamage = chanceOfCriticalDamage;
    tempCriticalDamagePercentage = criticalDamagePercentage;
}

void Character::SetSkill(int index)
{
    switch(index)
    {
        case 1:
            skills[amountOfSkills].name = "Guard";
            skills[amountOfSkills].isActive = false;
            switch(skills[amountOfSkills].level)
            {
                case 1:
                    skills[amountOfSkills].defenseIncreasePercentage = 0.1;
                    break;
                case 2:
                    skills[amountOfSkills].defenseIncreasePercentage = 0.15;
                    break;
                case 3:
                    skills[amountOfSkills].defenseIncreasePercentage = 0.25;
                    break;
            }
            break;
        case 2:
            skills[amountOfSkills].name = "Sword Barrage";
            skills[amountOfSkills].isActive = true;
            switch(skills[amountOfSkills].level)
            {
                case 1:
                    skills[amountOfSkills].damageMultiplier = 2;
                    skills[amountOfSkills].manaCost = 5;
                    break;
                case 2:
                    skills[amountOfSkills].damageMultiplier = 3;
                    skills[amountOfSkills].manaCost = 8;
                    break;
                case 3:
                    skills[amountOfSkills].damageMultiplier = 4;
                    skills[amountOfSkills].manaCost = 12;
                    break;
            }
            break;
        case 3:
            skills[amountOfSkills].name = "Shock";
            skills[amountOfSkills].isActive = true;
            switch(level)
            {
                case 1:
                    skills[amountOfSkills].stunnedTurns = 1;
                    skills[amountOfSkills].damage = 100;
                    skills[amountOfSkills].manaCost = 10;
                    break;
                case 2:
                    skills[amountOfSkills].stunnedTurns = 1;
                    skills[amountOfSkills].damage = 300;
                    skills[amountOfSkills].manaCost = 18;
                    break;
                case 3:
                    skills[amountOfSkills].stunnedTurns = 2;
                    skills[amountOfSkills].damage = 500;
                    skills[amountOfSkills].manaCost = 25;
                    break;
            }
            break;
        case 4:
            skills[amountOfSkills].name = "Hell Fire";
            skills[amountOfSkills].isActive = true;
            switch(level)
            {
                case 1:
                    skills[amountOfSkills].damage = 150;
                    skills[amountOfSkills].damageOverTime = 25;
                    skills[amountOfSkills].amountOfTurnsDOT = 1;
                    skills[amountOfSkills].manaCost = 10;
                    break;
                case 2:
                    skills[amountOfSkills].damage = 250;
                    skills[amountOfSkills].damageOverTime = 25;
                    skills[amountOfSkills].amountOfTurnsDOT = 2;
                    skills[amountOfSkills].manaCost = 20;
                    break;
                case 3:
                    skills[amountOfSkills].damage = 350;
                    skills[amountOfSkills].damageOverTime = 35;
                    skills[amountOfSkills].amountOfTurnsDOT = 3;
                    skills[amountOfSkills].manaCost = 30;
                    break;
            }
            break;
        case 5:
            skills[amountOfSkills].name = "Frostbite";
            skills[amountOfSkills].isActive = true;
            switch(level)
            {
                case 1:
                    skills[amountOfSkills].damage = 100;
                    skills[amountOfSkills].enemyDamageReductionPercentage = 0.2;
                    skills[amountOfSkills].manaCost = 7;
                    break;
                case 2:
                    skills[amountOfSkills].damage = 150;
                    skills[amountOfSkills].enemyDamageReductionPercentage = 0.3;
                    skills[amountOfSkills].manaCost = 9;
                    break;
                case 3:
                    skills[amountOfSkills].damage = 200;
                    skills[amountOfSkills].enemyDamageReductionPercentage = 0.65;
                    skills[amountOfSkills].manaCost = 12;
                    break;
            }
            break;
        case 6:
            skills[amountOfSkills].name = "Thunder Strike";
            skills[amountOfSkills].isActive = true;
            switch(level)
            {
                case 1:
                    skills[amountOfSkills].damage = 50;
                    skills[amountOfSkills].manaCost = 5;
                    break;
                case 2:
                    skills[amountOfSkills].damage = 100;
                    skills[amountOfSkills].chanceOfDrainHP = 0.2;
                    skills[amountOfSkills].hpDrainOfMaxPercentage = 0.2;
                    skills[amountOfSkills].manaCost = 8;
                    break;
                case 3:
                    skills[amountOfSkills].damage = 150;
                    skills[amountOfSkills].chanceOfDrainHP = 0.5;
                    skills[amountOfSkills].hpDrainOfMaxPercentage = 0.35;
                    skills[amountOfSkills].manaCost = 15;
                    break;
            }
            break;
        case 7:
            skills[amountOfSkills].name = "Swift";
            skills[amountOfSkills].isActive = false;
            switch(level)
            {
                case 1:
                    skills[amountOfSkills].chanceOfEvasion = 0.1;
                    skills[amountOfSkills].chanceOfDamageReduction = 0.3;
                    skills[amountOfSkills].damageReduction = 20;
                    break;
                case 2:
                    skills[amountOfSkills].chanceOfEvasion = 0.1;
                    skills[amountOfSkills].chanceOfDamageReduction = 0.3;
                    skills[amountOfSkills].damageReduction = 30;
                    break;
                case 3:
                    skills[amountOfSkills].chanceOfEvasion = 0.1;
                    skills[amountOfSkills].chanceOfDamageReduction = 0.3;
                    skills[amountOfSkills].damageReduction = 40;
                    break;
            }
            break;
        case 8:
            skills[amountOfSkills].name = "Sharp Eye";
            skills[amountOfSkills].isActive = false;
            switch(level)
            {
                case 1:
                    skills[amountOfSkills].chanceOfCriticalDamage = 0.2;
                    skills[amountOfSkills].criticalDamagePercentage = 0.25;
                    break;
                case 2:
                    skills[amountOfSkills].chanceOfCriticalDamage = 0.3;
                    skills[amountOfSkills].criticalDamagePercentage = 0.5;
                    break;
                case 3:
                    skills[amountOfSkills].chanceOfCriticalDamage = 0.5;
                    skills[amountOfSkills].criticalDamagePercentage = 0.75;
                    break;
            }
            break;
        case 9:
            skills[amountOfSkills].name = "Burst Arrow";
            skills[amountOfSkills].isActive = true;
            switch(level)
            {
                case 1:
                    skills[amountOfSkills].damage = 150;
                    skills[amountOfSkills].chanceOfFiringAgain[0] = 0.3;
                    break;
                case 2:
                    skills[amountOfSkills].damage = 225;
                    skills[amountOfSkills].chanceOfFiringAgain[0] = 0.5;
                    break;
                case 3:
                    skills[amountOfSkills].damage = 150;
                    skills[amountOfSkills].chanceOfFiringAgain[0] = 0.75;
                    skills[amountOfSkills].chanceOfFiringAgain[1] = 0.25;
                    break;
            }
            break;
    }
    skills[amountOfSkills].id = index;
    amountOfSkills++;
}

void Character::UseSkill(int index, Monster &monster)
{
    int rand = GetRandomNumber(100);
    float damage;
    switch(skills[index].id)
    {
        //Guard Skill
        case 1:
            tempDefense = defense * (1 + skills[index].defenseIncreasePercentage);
            cout << "Your defense increased by "
                 << ConvertFromPercentageToString(skills[index].defenseIncreasePercentage, 2)
                 << " % "
                 << endl;
            break;
        //Sword Barrage
        case 2:
            cout << "Sword Barrage" << endl;
            if (rand > tempChanceOfCriticalDamage)
            {
                damage = NormalAttack() * skills[index].damageMultiplier;
                cout << "You did a Normal Attack " << skills[index].damageMultiplier << " times" << endl;
            }
            else 
            {
                damage = CriticalAttack() * skills[index].damageMultiplier;
                cout << "You did a Critical Attack " << skills[index].damageMultiplier << " times" << endl;
            }

            monster.DamageCalculation(damage);
            break;
        //Shock
        case 3:
            cout << "Shock" << endl;
            if (rand > tempChanceOfCriticalDamage)
            {
                damage = NormalAttack();
                cout << "You did a Normal Attack " << endl;
            }
            else 
            {
                damage = CriticalAttack();
                cout << "You did a Critical Attack " << endl;
            }

            monster.DamageCalculation(damage);
            break;
    }
    currentMana -= skills[index].manaCost;
}

float Character::NormalAttack()
{
    return (GetRandomNumber(tempAttackDamageMin, tempAttackDamageMax));
}

float Character::CriticalAttack()
{
    return (NormalAttack() * (1 + tempCriticalDamagePercentage));
}

bool Character::DamageCalculation(float damage)
{
    bool isDamaged = false;
    //Half of defense is how much damage is removed
    if ((tempDefense / 2) >= damage)
    {
        cout << "Your defense negated the enemy's attack" << endl;
    }
    else 
    {
        damage -= tempDefense / 2;
        
        //Player evasion/damage reduct
        int rand = GetRandomNumber(100);
        if (rand > (tempChanceOfEvasion * 100))
        {
            rand = GetRandomNumber(100);
            if (rand > (tempChanceOfDamageReduction * 100))
            {
                cout << "You took " << damage << " damage" << endl;
                currentHp -= damage;
            }
            else
            {
                if (damage > tempDamageReduction)
                {
                    cout << "You took reduced damage " << endl;
                    currentHp -= damage - tempDamageReduction;
                    cout << "You took " << damage - tempDamageReduction << " damage" << endl;
                }
                else
                {
                    cout << "You negated the enemy's attack with your damage reduction" << endl;
                }
            }

        }
        else
        {
            cout << "You evaded the enemy's attack" << endl;
        }
    }
    return isDamaged;
}

void Character::IncreaseStats()
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

bool Character::LevelUp()
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

float Character::GetExpPercentage() 
{
    return (currentExp/expToNextLevel)*100;
}

void Character::Fullheal()
{
    currentHp = maxHp;
    currentMana = maxMana;
}

bool Character::IsAlive()
{
    return (currentHp > 0);
}