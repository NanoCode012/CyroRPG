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
            evasion = 0.01;
            chanceOfDamageReduction = 0.05;
            damageReduction = 5;
            chanceOfCritical = 0.05;

            Character::SetSkill(0);
            Character::SetSkill(1);
            Character::SetSkill(2);
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

void Character::SetSkill(int index)
{
    switch(index)
    {
        //Guard skill
        case 0:
            skills[amountOfSkills].name = "Guard";
            skills[amountOfSkills].isActive = false;
            skills[amountOfSkills].manaCost = 0;
            switch(skills[amountOfSkills].level)
            {
                case 1:
                    skills[amountOfSkills].defense = 0.1;
                    break;
                case 2:
                    skills[amountOfSkills].defense = 0.15;
                    break;
                case 3:
                    skills[amountOfSkills].defense = 0.25;
                    break;
            }
            tempDefense = defense * (1 + defense);

            skills[amountOfSkills].index = index;
            amountOfSkills++;
            break;
        //Sword Dance
        case 1:
            skills[amountOfSkills].name = "Sword Dance";
            skills[amountOfSkills].isActive = true;
            switch(skills[amountOfSkills].level)
            {
                case 1:
                    skills[amountOfSkills].manaCost = 5;
                    break;
                case 2:
                    skills[amountOfSkills].manaCost = 8;
                    break;
                case 3:
                    skills[amountOfSkills].manaCost = 12;
                    break;
            }

            skills[amountOfSkills].index = index;
            amountOfSkills++;
            break;
        //Shock Stun
        case 2:
            skills[amountOfSkills].name = "Shock Stun";
            skills[amountOfSkills].isActive = true;
            switch(level)
            {
                case 1:
                    skills[amountOfSkills].manaCost = 5;
                    break;
                case 2:
                    skills[amountOfSkills].manaCost = 8;
                    break;
                case 3:
                    skills[amountOfSkills].manaCost = 12;
                    break;
            }

            skills[amountOfSkills].index = index;
            amountOfSkills++;
            break;
    }
}

void Character::UseSkill(int index)
{

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