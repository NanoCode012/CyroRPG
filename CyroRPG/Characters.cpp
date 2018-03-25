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
                    skills[amountOfSkills].damageReductionPercentage = 0.2;
                    skills[amountOfSkills].manaCost = 7;
                    break;
                case 2:
                    skills[amountOfSkills].damage = 150;
                    skills[amountOfSkills].damageReductionPercentage = 0.3;
                    skills[amountOfSkills].manaCost = 9;
                    break;
                case 3:
                    skills[amountOfSkills].damage = 200;
                    skills[amountOfSkills].damageReductionPercentage = 0.65;
                    skills[amountOfSkills].manaCost = 12;
                    break;
            }
            break;
        case 6:
            skills[amountOfSkills].name = "Thunder Strike";
            skills[amountOfSkills].isActive = true;
            skills[amountOfSkills].stunnedTurns = 1;
            switch(level)
            {
                case 1:
                    skills[amountOfSkills].damage = 50;
                    skills[amountOfSkills].chanceOfStun = 0.2;
                    skills[amountOfSkills].manaCost = 5;
                    break;
                case 2:
                    skills[amountOfSkills].damage = 100;
                    skills[amountOfSkills].chanceOfStun = 0.35;
                    skills[amountOfSkills].chanceOfDrainHP = 0.2;
                    skills[amountOfSkills].hpDrainOfMaxPercentage = 0.2;
                    skills[amountOfSkills].manaCost = 8;
                    break;
                case 3:
                    skills[amountOfSkills].damage = 150;
                    skills[amountOfSkills].chanceOfStun = 0.5;
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
                    skills[amountOfSkills].chanceOfEvasion = 0.2;
                    skills[amountOfSkills].chanceOfDamageReduction = 0.3;
                    skills[amountOfSkills].damageReduction = 30;
                    break;
                case 3:
                    skills[amountOfSkills].chanceOfEvasion = 0.3;
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
            skills[amountOfSkills].name = "Arrow Burst";
            skills[amountOfSkills].isActive = true;
            skills[amountOfSkills].chanceOfFiringAgain[0] = 0;
            skills[amountOfSkills].chanceOfFiringAgain[1] = 0;
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
                damage = skills[index].damage;
                cout << "You did a Normal Attack" << endl;
            }
            else 
            {
                damage = skills[index].damage * (1 + tempCriticalDamagePercentage);
                cout << "You did a Critical Attack" << endl;
            }

            //Stun does not stack, only refreshes previous stack
            if (monster.DamageCalculation(damage))
            {
                cout << "Enemy has been stunned for " << skills[index].stunnedTurns << " turns" << endl;
                monster.stunnedTurns = skills[index].stunnedTurns;
            }
            break;
        //Hell Fire
        case 4:
            cout << "Hell Fire" << endl;
            if (rand > tempChanceOfCriticalDamage)
            {
                damage = skills[index].damage;
                cout << "You did a Normal Attack" << endl;
            }
            else 
            {
                damage = skills[index].damage * (1 + tempCriticalDamagePercentage);
                cout << "You did a Critical Attack" << endl;
            }

            if (monster.DamageCalculation(damage))
            {
                monster.damagedOverTime = skills[index].damageOverTime;
                monster.amountOfTurnsDOT = skills[index].amountOfTurnsDOT;
            }
            break;
        //Frostbite
        case 5:
            cout << "Frostbite" << endl;
            if (rand > tempChanceOfCriticalDamage)
            {
                damage = skills[index].damage;
                cout << "You did a Normal Attack" << endl;
            }
            else 
            {
                damage = skills[index].damage * (1 + tempCriticalDamagePercentage);
                cout << "You did a Critical Attack" << endl;
            }

            if (monster.DamageCalculation(damage))
            {
                monster.damageReductionPercentage = skills[index].damageReductionPercentage;
                monster.amountOfTurnsDamageReductionPercentage = 1;
            }
            break;
        //Thunder Strike
        case 6:
            cout << "Thunder Strike" << endl;
            if (rand > tempChanceOfCriticalDamage)
            {
                damage = skills[index].damage;
                cout << "You did a Normal Attack" << endl;
            }
            else 
            {
                damage = skills[index].damage * (1 + tempCriticalDamagePercentage);
                cout << "You did a Critical Attack" << endl;
            }

            if (monster.DamageCalculation(damage))
            {
                rand = GetRandomNumber(100);
                if (rand <= skills[index].chanceOfStun)
                {
                    monster.stunnedTurns = skills[index].stunnedTurns;
                }
                rand = GetRandomNumber(100);
                if (rand <= skills[index].chanceOfDrainHP)
                {
                    //Player take half of hp drained
                    currentHp += (monster.maxHp * (1 + skills[index].hpDrainOfMaxPercentage))/2;
                    monster.currentHp -= monster.maxHp * (1 + skills[index].hpDrainOfMaxPercentage);
                }
            }
            break;
        //Swift
        case 7:
            cout << "Swift" << endl;
            tempChanceOfEvasion += skills[index].chanceOfEvasion;
            tempChanceOfDamageReduction += skills[index].chanceOfDamageReduction;
            tempDamageReduction += skills[index].damageReduction;
            cout << "Your evasion chance increased by " << skills[index].chanceOfEvasion << endl;
            if (skills[index].chanceOfDamageReduction > 0)
            {
                cout << "Your damage reduction chance increased by " 
                     << skills[index].chanceOfDamageReduction 
                     << " against " 
                     << skills[index].damageReduction
                     << " damage"
                     << endl; 
            }
            break;
        //Sharp Eye
        case 8:
            cout << "Sharp Eye" << endl;
            tempChanceOfCriticalDamage += skills[index].chanceOfCriticalDamage;
            tempCriticalDamagePercentage += skills[index].criticalDamagePercentage;
            cout << "Your critical chance increased by " << skills[index].chanceOfCriticalDamage << endl;
            cout << "Your critical damage is " << 1 + tempChanceOfCriticalDamage << "x of your normal attack" << endl;
            break;
        //Arrow Burst
        case 9:
            cout << "Arrow Burst" << endl;
            if (rand > tempChanceOfCriticalDamage)
            {
                damage = skills[index].damage;
                cout << "You did a Normal Attack" << endl;
            }
            else 
            {
                damage = skills[index].damage * (1 + tempCriticalDamagePercentage);
                cout << "You did a Critical Attack" << endl;
            }

            if (monster.DamageCalculation(damage))
            {
                rand = GetRandomNumber(100);
                if (rand <= skills[index].chanceOfFiringAgain[0])
                {
                    amountOfExtraTurns++;
                    rand = GetRandomNumber(100);
                    if (rand <= skills[index].chanceOfFiringAgain[1])
                    {
                        amountOfExtraTurns++;
                    }
                    cout << "Enemy is pushed back. You get " << amountOfExtraTurns << " extra turn(s)." << endl;
                }
            }
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
        currentExp -= expToNextLevel;
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